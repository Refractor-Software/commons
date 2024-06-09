#ifndef     REFRACTOR_MATH_INCLUDE
#define     REFRACTOR_MATH_INCLUDE

#ifdef      __cplusplus
extern "C" {
#endif

/*    Refractor Commons: Math    */
/* ----------------------------- */

/* ------ Vector Register Types ------
 * Refractor math is based around vector math operations.
 * We directly interface with intrinsics for maximum performance.
 *
 * Our own data types are simply typedef's for the architecture's native
 * types, so they ought to not introduce much coupling. */

#if defined(__ARM_NEON)
    #define RFR_MATH_ARCH_NEON
    #include "arm_neon.h"
#elif defined(__x86_64__) /* AMD64 requires AVX support */
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

enum {
    RFR_MATH_VECTOR_FLOAT_ALIGN = 16,
    RFR_MATH_VECTOR_DOUBLE_ALIGN =
    #if defined(RFR_MATH_ARCH_AVX)
        32
    #elif defined(RFR_MATH_ARCH_NEON) || defined(RFR_MATH_ARCH_SSSE3) /* SSE w/o AVX is not yet implemented */
        16
    #endif
};

/* ------ Vector Load ------------------------------------------------------- */

/**
 * Load four 32-bit integer values into the returned register.
 * @param inInts Four values to be loaded, in XYZW order.
 * @return Register with the four values loaded.
 * @warning Loaded data must rest on an aligned boundary of width
 * RFR_MATH_VECTOR_FLOAT_ALIGN.
 */
RfrVec4i rfr_math_vec4i_load(int* const inInts);

/**
 * Load four 32-bit floating-point values into the returned register.
 * @param inFloats Four values to be loaded, in XYZW order.
 * @return Register with the four values loaded.
 * @warning Loaded data must rest on an aligned boundary of width
 * RFR_MATH_VECTOR_FLOAT_ALIGN.
 */
RfrVec4f rfr_math_vec4f_load(float* const inFloats);

/**
 * Load two 64-bit floating-point values into the returned register.
 * @param inDoubles Two values to be loaded, in XY order.
 * @return Register with the two values loaded.
 * @warning Loaded data must rest on an aligned boundary of width
 * RFR_MATH_VECTOR_DOUBLE_ALIGN.
 */
RfrVec2d rfr_math_vec2d_load(double* const inDoubles);

/**
 * Load eight 32-bit integer values into the returned register.
 * @param inInts Eight values to be loaded, in XYZW-ABCD order.
 * @return Register with the eight values loaded.
 * @warning Loaded data must rest on an aligned boundary of width
 * RFR_MATH_VECTOR_DOUBLE_ALIGN. (Not a typo, this is a 256-bit register.)
 */
RfrVec8i rfr_math_vec8i_load(int* const inInts);

/**
 * Load eight 32-bit floating-point values into the returned register.
 * @param inInts Eight values to be loaded, in XYZW-ABCD order.
 * @return Register with the eight values loaded.
 * @warning Loaded data must rest on an aligned boundary of width
 * RFR_MATH_VECTOR_DOUBLE_ALIGN. (Not a typo, this is a 256-bit register.)
 */
RfrVec8f rfr_math_vec8f_load(float* const inFloats);

/**
 * Load four 64-bit floating-point values into the returned register.
 * @param inFloats Four values to be loaded, in XYZW order.
 * @return Register with the four values loaded.
 * @warning Loaded data must rest on an aligned boundary of width
 * RFR_MATH_VECTOR_DOUBLE_ALIGN.
 */
RfrVec4d rfr_math_vec4d_load(double* const inDoubles);

/* ------ Vector Store ------------------------------------------------------ */

/**
 * Store four 32-bit integer values from inV to outDst.
 * @param outDst Destination for the stored values.
 * @param inV Values to store in outDst.
 * @warning Stored data must rest on an aligned boundary of width
 * RFR_MATH_VECTOR_FLOAT_ALIGN.
 */
void rfr_math_vec4i_store(int* outDst, RfrVec4i inV);

/**
 * Store four 32-bit floating-point values from inV to outDst.
 * @param outDst Destination for the stored values.
 * @param inV Values to store in outDst.
 * @warning Loaded data must rest on an aligned boundary of width
 * RFR_MATH_VECTOR_FLOAT_ALIGN.
 */
void rfr_math_vec4f_store(float* outDst, RfrVec4f inV);

/**
 * Store two 64-bit floating-point values from inV to outDst.
 * @param outDst Destination for the stored values.
 * @param inV Values to store in outDst.
 * @warning Loaded data must rest on an aligned boundary of width
 * RFR_MATH_VECTOR_DOUBLE_ALIGN.
 */
void rfr_math_vec2d_store(double* outDst, RfrVec2d inV);

/**
 * Store eight 32-bit integer values from inV to outDst.
 * @param outDst Destination for the stored values.
 * @param inV Values to store in outDst.
 * @warning Loaded data must rest on an aligned boundary of width
 * RFR_MATH_VECTOR_DOUBLE_ALIGN. (Not a typo, this is a 256-bit register.)
 */
void rfr_math_vec8i_store(int* outDst, RfrVec8i inV);

/**
 * Store eight 32-bit floating-point values from inV into outDst.
 * @param outDst Destination for the stored values.
 * @param inV Values to store in outDst.
 * @warning Loaded data must rest on an aligned boundary of width
 * RFR_MATH_VECTOR_DOUBLE_ALIGN. (Not a typo, this is a 256-bit register.)
 */
void rfr_math_vec8f_store(float* outDst, RfrVec8f inV);

/**
 * Store four 64-bit floating-point values from inV into outDst.
 * @param outDst Destination for the stored values.
 * @param inV Values to store in outDst.
 * @warning Loaded data must rest on an aligned boundary of width
 * RFR_MATH_VECTOR_DOUBLE_ALIGN.
 */
void rfr_math_vec4d_store(double* outDst, RfrVec4d inV);

/* ------ Vector Add -------------------------------------------------------- */

/**
 * Add eight (two sets of four) 32-bit integer values and return the result.
 * @param inLHS Left four values.
 * @param inRHS Right four values.
 * @return Resulting four values.
 */
RfrVec4i rfr_math_vec4i_add(RfrVec4i inLHS, RfrVec4i inRHS);

/**
 * Add eight (two sets of four) 32-bit floating-point values and return the result.
 * @param inLHS Left four values.
 * @param inRHS Right four values.
 * @return Resulting four values.
 */
RfrVec4f rfr_math_vec4f_add(RfrVec4f inLHS, RfrVec4f inRHS);

/**
 * Add four (two sets of two) 64-bit floating-point values and return the result.
 * @param inLHS Left two values.
 * @param inRHS Right two values.
 * @return Resulting two values.
 */
RfrVec2d rfr_math_vec2d_add(RfrVec2d inLHS, RfrVec2d inRHS);

/**
 * Add sixteen (two sets of eight) 32-bit integer values and return the result.
 * @param inLHS Left eight values.
 * @param inRHS Right eight values.
 * @return Resulting eight values.
 */
RfrVec8i rfr_math_vec8i_add(RfrVec8i inLHS, RfrVec8i inRHS);

/**
 * Add sixteen (two sets of eight) 32-bit integer values and return the result.
 * @param inLHS Left eight values.
 * @param inRHS Right eight values.
 * @return Resulting eight values.
 */
RfrVec8f rfr_math_vec8f_add(RfrVec8f inLHS, RfrVec8f inRHS);

/**
 * Add eight (two sets of four) 64-bit floating-point values and return the result.
 * @param inLHS Left four values.
 * @param inRHS Right four values.
 * @return Resulting four values.
 */
RfrVec4d rfr_math_vec4d_add(RfrVec4d inLHS, RfrVec4d inRHS);

/* ------ Vector Subtract --------------------------------------------------- */

/**
 * Subtract eight (two sets of four) 32-bit integer values and return the result.
 * @param inLHS Left four values.
 * @param inRHS Right four values.
 * @return Resulting four values.
 */
RfrVec4i rfr_math_vec4i_sub(RfrVec4i inLHS, RfrVec4i inRHS);

/**
 * Subtract eight (two sets of four) 32-bit floating-point values and return the result.
 * @param inLHS Left four values.
 * @param inRHS Right four values.
 * @return Resulting four values.
 */
RfrVec4f rfr_math_vec4f_sub(RfrVec4f inLHS, RfrVec4f inRHS);

/**
 * Subtract four (two sets of two) 64-bit floating-point values and return the result.
 * @param inLHS Left two values.
 * @param inRHS Right two values.
 * @return Resulting two values.
 */
RfrVec2d rfr_math_vec2d_sub(RfrVec2d inLHS, RfrVec2d inRHS);

/**
 * Subtract sixteen (two sets of eight) 32-bit integer values and return the result.
 * @param inLHS Left eight values.
 * @param inRHS Right eight values.
 * @return Resulting eight values.
 */
RfrVec8i rfr_math_vec8i_sub(RfrVec8i inLHS, RfrVec8i inRHS);

/**
 * Subtract sixteen (two sets of eight) 32-bit integer values and return the result.
 * @param inLHS Left eight values.
 * @param inRHS Right eight values.
 * @return Resulting eight values.
 */
RfrVec8f rfr_math_vec8f_sub(RfrVec8f inLHS, RfrVec8f inRHS);

/**
 * Subtract eight (two sets of four) 64-bit floating-point values and return the result.
 * @param inLHS Left four values.
 * @param inRHS Right four values.
 * @return Resulting four values.
 */
RfrVec4d rfr_math_vec4d_sub(RfrVec4d inLHS, RfrVec4d inRHS);

/* ------ Vector Multiply ------ */

/**
 * Multiply eight (two sets of four) 32-bit integer values and return the result.
 * @param inLHS Left four values.
 * @param inRHS Right four values.
 * @return Resulting four values.
 */
RfrVec4i rfr_math_vec4i_mul(RfrVec4i inLHS, RfrVec4i inRHS);

/**
 * Multiply eight (two sets of four) 32-bit floating-point values and return the result.
 * @param inLHS Left four values.
 * @param inRHS Right four values.
 * @return Resulting four values.
 */
RfrVec4f rfr_math_vec4f_mul(RfrVec4f inLHS, RfrVec4f inRHS);

/**
 * Multiply four (two sets of two) 64-bit floating-point values and return the result.
 * @param inLHS Left two values.
 * @param inRHS Right two values.
 * @return Resulting two values.
 */
RfrVec2d rfr_math_vec2d_mul(RfrVec2d inLHS, RfrVec2d inRHS);

/**
 * Multiply sixteen (two sets of eight) 32-bit integer values and return the result.
 * @param inLHS Left eight values.
 * @param inRHS Right eight values.
 * @return Resulting eight values.
 */
RfrVec8i rfr_math_vec8i_mul(RfrVec8i inLHS, RfrVec8i inRHS);

/**
 * Multiply sixteen (two sets of eight) 32-bit integer values and return the result.
 * @param inLHS Left eight values.
 * @param inRHS Right eight values.
 * @return Resulting eight values.
 */
RfrVec8f rfr_math_vec8f_mul(RfrVec8f inLHS, RfrVec8f inRHS);

/**
 * Multiply eight (two sets of four) 64-bit floating-point values and return the result.
 * @param inLHS Left four values.
 * @param inRHS Right four values.
 * @return Resulting four values.
 */
RfrVec4d rfr_math_vec4d_mul(RfrVec4d inLHS, RfrVec4d inRHS);

/* ------ Vector Divide ------ */

/**
 * Divide eight (two sets of four) 32-bit integer values and return the result.
 * @param inLHS Left four values.
 * @param inRHS Right four values.
 * @return Resulting four values.
 * @warning Due to a lack of native integer division as of AVX, this operation is
 * more expensive than other arithmetic.
 */
RfrVec4i rfr_math_vec4i_div(RfrVec4i inLHS, RfrVec4i inRHS);

/**
 * Divide eight (two sets of four) 32-bit floating-point values and return the result.
 * @param inLHS Left four values.
 * @param inRHS Right four values.
 * @return Resulting four values.
 */
RfrVec4f rfr_math_vec4f_div(RfrVec4f inLHS, RfrVec4f inRHS);

/**
 * Divide four (two sets of two) 64-bit floating-point values and return the result.
 * @param inLHS Left two values.
 * @param inRHS Right two values.
 * @return Resulting two values.
 */
RfrVec2d rfr_math_vec2d_div(RfrVec2d inLHS, RfrVec2d inRHS);

/**
 * Divide sixteen (two sets of eight) 32-bit integer values and return the result.
 * @param inLHS Left eight values.
 * @param inRHS Right eight values.
 * @return Resulting eight values.
 * @warning Due to a lack of native integer division as of AVX, this operation is
 * more expensive than other arithmetic.
 */
RfrVec8i rfr_math_vec8i_div(RfrVec8i inLHS, RfrVec8i inRHS);

/**
 * Divide sixteen (two sets of eight) 32-bit integer values and return the result.
 * @param inLHS Left eight values.
 * @param inRHS Right eight values.
 * @return Resulting eight values.
 */
RfrVec8f rfr_math_vec8f_div(RfrVec8f inLHS, RfrVec8f inRHS);

/**
 * Divide eight (two sets of four) 64-bit floating-point values and return the result.
 * @param inLHS Left four values.
 * @param inRHS Right four values.
 * @return Resulting four values.
 */
RfrVec4d rfr_math_vec4d_div(RfrVec4d inLHS, RfrVec4d inRHS);

#ifdef      __cplusplus
} /* extern "C" */
#endif

#include "__impl/r_math_impl_avx.h"

#endif  /*  REFRACTOR_MATH_INCLUDE  */
