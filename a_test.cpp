#include    "stdio.h"

#include    <refractor_math.h>
#include    <chrono>    /* for timing! */
#include    <cstdlib>
#include    <ctime>
#include    <iostream>  /* just for cin.get and chrono print lmao */
#include    <string>    /* pov you gave up on c string handling */
#include    <thread>    /* threading */

/* Ripped the random float stuff from Stack Overflow.
 * It'll work for the purposes of this test program, but that's about it. */
#define     LO -64.f
#define     HI  64.f

/* Some of this math is def going to throw some exceptions, but I hardly care right now . */

/* number of vectors to test, all 4-value double-precision*/
#define     RFR_TEST_VECTOR_COUNT       32

/* how many times to loop the operations, no idea
 * what kind of hell this will raise but def a floating-point exception or two :))))) */
#define     RFR_TEST_VECTOR_LOOP_COUNT  8

/* whether to use multiple threads for test
 * single-threaded is way faster here bc avx execution time
 * greatly outperforms spinning up several threads, but with a
 * job system with already-running threads this may not be an issue,
 * so keep that in mind */
#define     RFR_TEST_VECTOR_MULTITHREAD 0

static double rfr_test_generate_random_f64()
{
    /* Ripped from SO because it's a test program and I don't really care right now */
    return LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
}

static void rfr_test_vec4d_sprintf(RfrVec4d* inVector, const char* inPrefix, std::string& outStream)
{
    /* Really nooby and slopped-together for some debugging.
     * Do not use in shipping. */
    double* locAsDbl = (double*)inVector;
    char locAppend[256];
    sprintf(locAppend, "%s Vec4d - X=%.2f, Y=%.2f, Z=%.2f, W=%.2f \n", inPrefix, locAsDbl[0], locAsDbl[1], locAsDbl[2], locAsDbl[3]);
    outStream.append(locAppend);
}

static void rfr_test_vec4d_math(RfrVec4d* inOutputs, RfrVec4d* inLefts, RfrVec4d* inRights, unsigned j)
{
    inOutputs[j] = rfr_math_vec4d_add(inLefts[j], inRights[j]);
    inOutputs[j] = rfr_math_vec4d_sub(inRights[j], inLefts[j]);
    inOutputs[j] = rfr_math_vec4d_mul(inLefts[j], inRights[j]);
    inOutputs[j] = rfr_math_vec4d_div(inRights[j], inLefts[j]);
}

/* this shi def gon blue screen XDDDD */
int main()
{
    /* make some output buffers */
    std::string locPretestOutputStream;
    std::string locPosttestOutputStream;

    /* Seed random number generator */
    srand(time(0));
    
    /* Slam the CPU with a bunch of 256-bit vectors, why not?
     * We are testing AVX after all... */
    RfrVec4d  locVectors[RFR_TEST_VECTOR_COUNT];
    
    /* for arithmetic operations */
    RfrVec4d  locLeftHands[RFR_TEST_VECTOR_COUNT];
    RfrVec4d  locRightHands[RFR_TEST_VECTOR_COUNT];
    
    /* For each vector... */
    for (RfrVec4d& iterVec : locVectors)
    {
        double locLoaded[4];
        for (double& iterF64 : locLoaded)
        {
            iterF64 = rfr_test_generate_random_f64();
        }
        iterVec = rfr_math_vec4d_load(locLoaded);
    }
    for (RfrVec4d& iterVec : locLeftHands)
    {
        double locLoaded[4];
        for (double& iterF64 : locLoaded)
        {
            iterF64 = rfr_test_generate_random_f64();
        }
        iterVec = rfr_math_vec4d_load(locLoaded);
    }
    for (RfrVec4d& iterVec : locRightHands)
    {
        double locLoaded[4];
        for (double& iterF64 : locLoaded)
        {
            iterF64 = rfr_test_generate_random_f64();
        }
        iterVec = rfr_math_vec4d_load(locLoaded);
    }
    
    /* Write all of that to our output stream
     * there probably is prod code worse than this... */
    locPretestOutputStream.append("\nOUT:\n");
    for (int i = 0; i < RFR_TEST_VECTOR_COUNT; ++i) {
        rfr_test_vec4d_sprintf(&locVectors[i], "BEFORE: [OUT] ", locPretestOutputStream);
    }
    locPretestOutputStream.append("\nLHS:\n");
    for (int i = 0; i < RFR_TEST_VECTOR_COUNT; ++i) {
        rfr_test_vec4d_sprintf(&locLeftHands[i], "BEFORE: [LHS] ", locPretestOutputStream);
    }
    locPretestOutputStream.append("\nRHS:\n");
    for (int i = 0; i < RFR_TEST_VECTOR_COUNT; ++i) {
        rfr_test_vec4d_sprintf(&locRightHands[i], "BEFORE: [RHS] ", locPretestOutputStream);
    }

    std::cout << locPretestOutputStream << "\n";
    puts("Running some really shitty tests...\n");

    auto locStart = std::chrono::system_clock::now();

    /* run those silly little tests */
    for (int i = 0; i < RFR_TEST_VECTOR_LOOP_COUNT; ++i) {

        #if !RFR_TEST_VECTOR_MULTITHREAD

        for (int j = 0; j < RFR_TEST_VECTOR_COUNT; ++j) {
            rfr_test_vec4d_math(locVectors, locLeftHands, locRightHands, j);
        }

        /* rattle the left and right just to fuck with the system */
        for (int j = 0; j < RFR_TEST_VECTOR_COUNT; ++j) {
            rfr_test_vec4d_math(locLeftHands, locVectors, locRightHands, j);
        }
        for (int j = 0; j < RFR_TEST_VECTOR_COUNT; ++j) {
            rfr_test_vec4d_math(locRightHands, locLeftHands, locVectors, j);
        }

        #else

        /* if we are multithreaded we need a different strat
         * for now i'll just test with 2 threads, and see how it goes
         * using two variables instead of one because i can't be assed to do the math to
         * avoid off-by-one ahead of time, would rather not spend time fixing a segfault
         * 
         * also for future references, maybe create these threads in a loop, that way it's
         * not such a pain in the ass to make new ones */
        for (int j = 0; j < RFR_TEST_VECTOR_COUNT; j += 8) {
            std::thread locThread1(rfr_test_vec4d_math, locVectors, locLeftHands, locRightHands, j);
            std::thread locThread2(rfr_test_vec4d_math, locVectors, locLeftHands, locRightHands, j + 1);
            std::thread locThread3(rfr_test_vec4d_math, locVectors, locLeftHands, locRightHands, j + 2);
            std::thread locThread4(rfr_test_vec4d_math, locVectors, locLeftHands, locRightHands, j + 3);
            std::thread locThread5(rfr_test_vec4d_math, locVectors, locLeftHands, locRightHands, j + 4);
            std::thread locThread6(rfr_test_vec4d_math, locVectors, locLeftHands, locRightHands, j + 5);
            std::thread locThread7(rfr_test_vec4d_math, locVectors, locLeftHands, locRightHands, j + 6);
            std::thread locThread8(rfr_test_vec4d_math, locVectors, locLeftHands, locRightHands, j + 7);
            locThread1.join();
            locThread2.join();
            locThread3.join();
            locThread4.join();
            locThread5.join();
            locThread6.join();
            locThread7.join();
            locThread8.join();
        }
        for (int j = 0; j < RFR_TEST_VECTOR_COUNT; j += 8) {
            std::thread locThread1(rfr_test_vec4d_math, locLeftHands, locVectors, locRightHands, j);
            std::thread locThread2(rfr_test_vec4d_math, locLeftHands, locVectors, locRightHands, j + 1);
            std::thread locThread3(rfr_test_vec4d_math, locLeftHands, locVectors, locRightHands, j + 2);
            std::thread locThread4(rfr_test_vec4d_math, locLeftHands, locVectors, locRightHands, j + 3);
            std::thread locThread5(rfr_test_vec4d_math, locLeftHands, locVectors, locRightHands, j + 4);
            std::thread locThread6(rfr_test_vec4d_math, locLeftHands, locVectors, locRightHands, j + 5);
            std::thread locThread7(rfr_test_vec4d_math, locLeftHands, locVectors, locRightHands, j + 6);
            std::thread locThread8(rfr_test_vec4d_math, locLeftHands, locVectors, locRightHands, j + 7);
            locThread1.join();
            locThread2.join();
            locThread3.join();
            locThread4.join();
            locThread5.join();
            locThread6.join();
            locThread7.join();
            locThread8.join();
        }
        for (int j = 0; j < RFR_TEST_VECTOR_COUNT; j += 8) {
            std::thread locThread1(rfr_test_vec4d_math, locRightHands, locLeftHands, locVectors, j);
            std::thread locThread2(rfr_test_vec4d_math, locRightHands, locLeftHands, locVectors, j + 1);
            std::thread locThread3(rfr_test_vec4d_math, locRightHands, locLeftHands, locVectors, j + 2);
            std::thread locThread4(rfr_test_vec4d_math, locRightHands, locLeftHands, locVectors, j + 3);
            std::thread locThread5(rfr_test_vec4d_math, locRightHands, locLeftHands, locVectors, j + 4);
            std::thread locThread6(rfr_test_vec4d_math, locRightHands, locLeftHands, locVectors, j + 5);
            std::thread locThread7(rfr_test_vec4d_math, locRightHands, locLeftHands, locVectors, j + 6);
            std::thread locThread8(rfr_test_vec4d_math, locRightHands, locLeftHands, locVectors, j + 7);
            locThread1.join();
            locThread2.join();
            locThread3.join();
            locThread4.join();
            locThread5.join();
            locThread6.join();
            locThread7.join();
            locThread8.join();
        }

        #endif
    }
    
    /* log elapsed time */
    auto locEnd = std::chrono::system_clock::now();
    auto locElapsed = locEnd - locStart;

    /* re-print */
    locPosttestOutputStream.append("\nOUT:\n");
    for (int i = 0; i < RFR_TEST_VECTOR_COUNT; ++i) {
        rfr_test_vec4d_sprintf(&locVectors[i], "AFTER: [OUT] ", locPosttestOutputStream);
    }
    locPosttestOutputStream.append("\nLHS:\n");
    for (int i = 0; i < RFR_TEST_VECTOR_COUNT; ++i) {
        rfr_test_vec4d_sprintf(&locLeftHands[i], "AFTER: [LHS] ", locPosttestOutputStream);
    }
    locPosttestOutputStream.append("\nRHS:\n");
    for (int i = 0; i < RFR_TEST_VECTOR_COUNT; ++i) {
        rfr_test_vec4d_sprintf(&locRightHands[i], "AFTER: [RHS] ", locPosttestOutputStream);
    }

    std::cout << locPosttestOutputStream << "\n";
    std::cout << "Execution time was " << std::chrono::duration_cast<std::chrono::microseconds>(locElapsed)
              << "(" << std::chrono::duration_cast<std::chrono::milliseconds>(locElapsed) << ")\n\n\n";
    puts("Press any key to continue...");
    
    /* stall the main thread, so I can read how awful this went */
    std::cin.get();
    
    /* implicit return 0; */
}
