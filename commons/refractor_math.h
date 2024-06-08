#ifndef     REFRACTOR_MATH_INCLUDE
#define     REFRACTOR_MATH_INCLUDE

#ifdef      __cplusplus
extern "C" {
#endif

/*    Refractor Commons: Math    */
/* ----------------------------- */

/* ------ Vector Register Types ------
 * Refractor math is based around vector math operations.
 * We directly interface with instruction intrinsics for maximum performance. */

#if defined(__ARM_NEON)
    #define RFR_MATH_ARCH_NEON
    #include "arm_neon.h"
#elif defined(__x86_64__)
    #define RFR_MATH_ARCH_AVX
    #include "immintrin.h"
    typedef __m128i     RfrVec4i;
    typedef __m128      RfrVec4f;
    typedef __m128d     RfrVec2d;
    typedef __m256i     RfrVec8i;
    typedef __m256      RfrVec8f;
    typedef __m256d     RfrVec4d;
#else
    #error "REFRACTOR MATH: Unsupported SIMD architecture."
#endif

/* ------ Vector Load/Store ------ */

RfrVec4i rfr_math_vec4i_load(int* const inInts);       /* load 4 32-bit integers into dst */
RfrVec4f rfr_math_vec4f_load(float* const inFloats);   /* load 4 32-bit floats into dst */
RfrVec2d rfr_math_vec2d_load(double* const inDoubles); /* load 2 64-bit floats into dst */
RfrVec8i rfr_math_vec8i_load(int* const inInts);       /* load 8 32-bit integers into dst */
RfrVec8f rfr_math_vec8f_load(float* const inFloats);   /* load 8 32-bit floats into dst */
RfrVec4d rfr_math_vec4d_load(double* const inDoubles); /* load 4 64-bit floats into dst */

void rfr_math_vec4i_store(int* outDst, RfrVec4i inV);    /* store 4 32-bit integers from inV into outDst */
void rfr_math_vec4f_store(float* outDst, RfrVec4f inV);  /* store 4 32-bit floats from inV into outDst */
void rfr_math_vec2d_store(double* outDst, RfrVec2d inV); /* store 2 64-bit doubles from inV into outDst */
void rfr_math_vec8i_store(int* outDst, RfrVec8i inV);    /* store 8 32-bit integers from inV into outDst */
void rfr_math_vec8f_store(float* outDst, RfrVec8f inV);  /* store 8 32-bit floats from inV into outDst */
void rfr_math_vec4d_store(double* outDst, RfrVec4d inV); /* store 4 64-bit doubles from inV into outDst */

/* ------ Vector Add ------ */

RfrVec4i rfr_math_vec4i_add(RfrVec4i inLHS, RfrVec4i inRHS); /* add 8 32-bit integers and store in dst */
RfrVec4f rfr_math_vec4f_add(RfrVec4f inLHS, RfrVec4f inRHS); /* add 8 32-bit floats and store in dst */
RfrVec2d rfr_math_vec2d_add(RfrVec2d inLHS, RfrVec2d inRHS); /* add 4 64-bit doubles and store in dst */
RfrVec8i rfr_math_vec8i_add(RfrVec8i inLHS, RfrVec8i inRHS); /* add 16 32-bit integers and store in dst */
RfrVec8f rfr_math_vec8f_add(RfrVec8f inLHS, RfrVec8f inRHS); /* add 16 32-bit floats and store in dst */
RfrVec4d rfr_math_vec4d_add(RfrVec4d inLHS, RfrVec4d inRHS); /* add 8 64-bit doubles and store in dst */

/* ------ Vector Subtract ------ */

RfrVec4i rfr_math_vec4i_sub(RfrVec4i inLHS, RfrVec4i inRHS); /* subtract 8 32-bit integers and store in dst */
RfrVec4f rfr_math_vec4f_sub(RfrVec4f inLHS, RfrVec4f inRHS); /* subtract 8 32-bit floats and store in dst */
RfrVec2d rfr_math_vec2d_sub(RfrVec2d inLHS, RfrVec2d inRHS); /* subtract 4 64-bit doubles and store in dst */
RfrVec8i rfr_math_vec8i_sub(RfrVec8i inLHS, RfrVec8i inRHS); /* subtract 16 32-bit integers and store in dst */
RfrVec8f rfr_math_vec8f_sub(RfrVec8f inLHS, RfrVec8f inRHS); /* subtract 16 32-bit floats and store in dst */
RfrVec4d rfr_math_vec4d_sub(RfrVec4d inLHS, RfrVec4d inRHS); /* subtract 8 64-bit doubles and store in dst */

/* ------ Vector Multiply ------ */

RfrVec4i rfr_math_vec4i_mul(RfrVec4i inLHS, RfrVec4i inRHS); /* multiply 8 32-bit integers and store in dst */
RfrVec4f rfr_math_vec4f_mul(RfrVec4f inLHS, RfrVec4f inRHS); /* multiply 8 32-bit floats and store in dst */
RfrVec2d rfr_math_vec2d_mul(RfrVec2d inLHS, RfrVec2d inRHS); /* multiply 4 64-bit doubles and store in dst */
RfrVec8i rfr_math_vec8i_mul(RfrVec8i inLHS, RfrVec8i inRHS); /* multiply 16 32-bit integers and store in dst */
RfrVec8f rfr_math_vec8f_mul(RfrVec8f inLHS, RfrVec8f inRHS); /* multiply 16 32-bit floats and store in dst */
RfrVec4d rfr_math_vec4d_mul(RfrVec4d inLHS, RfrVec4d inRHS); /* multiply 8 64-bit doubles and store in dst */

/* ------ Vector Divide ------ */

RfrVec4i rfr_math_vec4i_div(RfrVec4i inLHS, RfrVec4i inRHS); /* divide 8 32-bit integers and store in dst */
RfrVec4f rfr_math_vec4f_div(RfrVec4f inLHS, RfrVec4f inRHS); /* divide 8 32-bit floats and store in dst */
RfrVec2d rfr_math_vec2d_div(RfrVec2d inLHS, RfrVec2d inRHS); /* divide 4 64-bit doubles and store in dst */
RfrVec8i rfr_math_vec8i_div(RfrVec8i inLHS, RfrVec8i inRHS); /* divide 16 32-bit integers and store in dst */
RfrVec8f rfr_math_vec8f_div(RfrVec8f inLHS, RfrVec8f inRHS); /* divide 16 32-bit floats and store in dst */
RfrVec4d rfr_math_vec4d_div(RfrVec4d inLHS, RfrVec4d inRHS); /* divide 8 64-bit doubles and store in dst */

#ifdef      __cplusplus
}
#endif

#endif  /*  REFRACTOR_MATH_INCLUDE  */
