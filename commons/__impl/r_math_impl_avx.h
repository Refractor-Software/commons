#ifndef     REFRACTOR_MATH_IMPL_AVX_H
#define     REFRACTOR_MATH_IMPL_AVX_H

#ifndef REFRACTOR_MATH_INCLUDE
#include    "../refractor_math.h"
#endif

#ifdef      __cplusplus
extern "C" {
#endif

/* --------------------------------------------------------
 * VECTOR LOAD
 */

RfrVec4i rfr_math_vec4i_load(int* const inInts)
{
#if defined(RFR_MATH_ARCH_AVX)
    return _mm_load_si128((__m128i*)inInts);
#elif defined(RFR_MATH_ARCH_NEON)

#endif
}

RfrVec4f rfr_math_vec4f_load(float* const inFloats)
{
#if defined(RFR_MATH_ARCH_AVX)
    return _mm_load_ps(inFloats);
#elif defined(RFR_MATH_ARCH_NEON)

#endif
}

RfrVec2d rfr_math_vec2d_load(double* const inDoubles)
{
#if defined(RFR_MATH_ARCH_AVX)
    return _mm_load_pd(inDoubles);
#elif defined(RFR_MATH_ARCH_NEON)

#endif
}

RfrVec8i rfr_math_vec8i_load(int* const inInts)
{
#if defined(RFR_MATH_ARCH_AVX)
    return _mm256_load_si256((__m256i*)inInts);
#elif defined(RFR_MATH_ARCH_NEON)
    
#endif
}

RfrVec8f rfr_math_vec8f_load(float* const inFloats)
{
#if defined(RFR_MATH_ARCH_AVX)
    return _mm256_load_ps(inFloats);
#elif defined(RFR_MATH_ARCH_NEON)

#endif
}

RfrVec4d rfr_math_vec4d_load(double* const inDoubles)
{
#if defined(RFR_MATH_ARCH_AVX)
    return _mm256_load_pd(inDoubles);
#elif defined(RFR_MATH_ARCH_NEON)

#endif
}

/* --------------------------------------------------------
 * VECTOR STORE
 */

void        rfr_math_vec4i_store(int* outDst, RfrVec4i inV)
{
#if defined(RFR_MATH_ARCH_AVX)
    _mm_store_si128((__m128i*)outDst, inV);
#elif defined(RFR_MATH_ARCH_NEON)

#endif
}

void        rfr_math_vec4f_store(float* outDst, RfrVec4f inV)
{
#if defined(RFR_MATH_ARCH_AVX)
    _mm_store_ps(outDst, inV);
#elif defined(RFR_MATH_ARCH_NEON)

#endif
}

void        rfr_math_vec2d_store(double* outDst, RfrVec2d inV)
{
#if defined(RFR_MATH_ARCH_AVX)
    _mm_store_pd(outDst, inV);
#elif defined(RFR_MATH_ARCH_NEON)

#endif
}

void        rfr_math_vec8i_store(int* outDst, RfrVec8i inV)
{
#if defined(RFR_MATH_ARCH_AVX)
    _mm256_store_si256((__m256i*)outDst, inV);
#elif defined(RFR_MATH_ARCH_NEON)

#endif
}

void        rfr_math_vec8f_store(float* outDst, RfrVec8f inV)
{
#if defined(RFR_MATH_ARCH_AVX)
    _mm256_store_ps(outDst, inV);
#elif defined(RFR_MATH_ARCH_NEON)

#endif
}

void        rfr_math_vec4d_store(double* outDst, RfrVec4d inV)
{
#if defined(RFR_MATH_ARCH_AVX)
    _mm256_store_pd(outDst, inV);
#elif defined(RFR_MATH_ARCH_NEON)

#endif
}

/* --------------------------------------------------------
 * VECTOR ADD
 */

RfrVec4i rfr_math_vec4i_add(RfrVec4i inLHS, RfrVec4i inRHS)
{
#if defined(RFR_MATH_ARCH_AVX)
    return _mm_add_epi32(inLHS, inRHS);
#elif defined(RFR_MATH_ARCH_NEON)

#endif
}

RfrVec4f rfr_math_vec4f_add(RfrVec4f inLHS, RfrVec4f inRHS)
{
#if defined(RFR_MATH_ARCH_AVX)
    return _mm_add_ps(inLHS, inRHS);
#elif defined(RFR_MATH_ARCH_NEON)

#endif
}

RfrVec2d rfr_math_vec2d_add(RfrVec2d inLHS, RfrVec2d inRHS)
{
#if defined(RFR_MATH_ARCH_AVX)
    return _mm_add_pd(inLHS, inRHS);
#elif defined(RFR_MATH_ARCH_NEON)

#endif
}

RfrVec8i rfr_math_vec8i_add(RfrVec8i inLHS, RfrVec8i inRHS)
{
#if defined(RFR_MATH_ARCH_AVX)
    /* we don't get 256-bit integer instructions until AVX-2 so just split the registers for now */
    RfrVec4i locReg1, locReg2, locReg3, locReg4;
    _mm256_storeu2_m128i(&locReg1, &locReg2, inLHS);
    _mm256_storeu2_m128i(&locReg3, &locReg4, inRHS);
    RfrVec4i locResult1 = _mm_add_epi32(locReg1, locReg3);
    RfrVec4i locResult2 = _mm_add_epi32(locReg2, locReg4);
    return _mm256_loadu2_m128i(&locResult1, &locResult2);
#elif defined(RFR_MATH_ARCH_NEON)

#endif
}

RfrVec8f rfr_math_vec8f_add(RfrVec8f inLHS, RfrVec8f inRHS)
{
#if defined(RFR_MATH_ARCH_AVX)
    return _mm256_add_ps(inLHS, inRHS);
#elif defined(RFR_MATH_ARCH_NEON)

#endif
}

RfrVec4d rfr_math_vec4d_add(RfrVec4d inLHS, RfrVec4d inRHS)
{
#if defined(RFR_MATH_ARCH_AVX)
    return _mm256_add_pd(inLHS, inRHS);
#elif defined(RFR_MATH_ARCH_NEON)

#endif
}

/* --------------------------------------------------------
 * VECTOR SUBTRACT
 */

RfrVec4i rfr_math_vec4i_sub(RfrVec4i inLHS, RfrVec4i inRHS)
{
#if defined(RFR_MATH_ARCH_AVX)
    return _mm_sub_epi32(inLHS, inRHS);
#elif defined(RFR_MATH_ARCH_NEON)

#endif
}

RfrVec4f rfr_math_vec4f_sub(RfrVec4f inLHS, RfrVec4f inRHS)
{
#if defined(RFR_MATH_ARCH_AVX)
    return _mm_sub_ps(inLHS, inRHS);
#elif defined(RFR_MATH_ARCH_NEON)

#endif
}

RfrVec2d rfr_math_vec2d_sub(RfrVec2d inLHS, RfrVec2d inRHS)
{
#if defined(RFR_MATH_ARCH_AVX)
    return _mm_sub_pd(inLHS, inRHS);
#elif defined(RFR_MATH_ARCH_NEON)

#endif
}

RfrVec8i rfr_math_vec8i_sub(RfrVec8i inLHS, RfrVec8i inRHS)
{
#if defined(RFR_MATH_ARCH_AVX)
    /* we don't get 256-bit integer instructions until AVX-2 so just split the registers for now */
    RfrVec4i locReg1, locReg2, locReg3, locReg4;
    _mm256_storeu2_m128i(&locReg1, &locReg2, inLHS);
    _mm256_storeu2_m128i(&locReg3, &locReg4, inRHS);
    RfrVec4i locResult1 = _mm_sub_epi32(locReg1, locReg3);
    RfrVec4i locResult2 = _mm_sub_epi32(locReg2, locReg4);
    return _mm256_loadu2_m128i(&locResult1, &locResult2);
#elif defined(RFR_MATH_ARCH_NEON)

#endif
}

RfrVec8f rfr_math_vec8f_sub(RfrVec8f inLHS, RfrVec8f inRHS)
{
#if defined(RFR_MATH_ARCH_AVX)
    return _mm256_sub_ps(inLHS, inRHS);
#elif defined(RFR_MATH_ARCH_NEON)

#endif
}

RfrVec4d rfr_math_vec4d_sub(RfrVec4d inLHS, RfrVec4d inRHS)
{
#if defined(RFR_MATH_ARCH_AVX)
    return _mm256_sub_pd(inLHS, inRHS);
#elif defined(RFR_MATH_ARCH_NEON)

#endif
}

/* --------------------------------------------------------
 * VECTOR MULTIPLY
 */

RfrVec4i rfr_math_vec4i_mul(RfrVec4i inLHS, RfrVec4i inRHS)
{
#if defined(RFR_MATH_ARCH_AVX)
    return _mm_mul_epi32(inLHS, inRHS);
#elif defined(RFR_MATH_ARCH_NEON)

#endif
}

RfrVec4f rfr_math_vec4f_mul(RfrVec4f inLHS, RfrVec4f inRHS)
{
#if defined(RFR_MATH_ARCH_AVX)
    return _mm_mul_ps(inLHS, inRHS);
#elif defined(RFR_MATH_ARCH_NEON)

#endif
}

RfrVec2d rfr_math_vec2d_mul(RfrVec2d inLHS, RfrVec2d inRHS)
{
#if defined(RFR_MATH_ARCH_AVX)
    return _mm_mul_pd(inLHS, inRHS);
#elif defined(RFR_MATH_ARCH_NEON)

#endif
}

RfrVec8i rfr_math_vec8i_mul(RfrVec8i inLHS, RfrVec8i inRHS)
{
#if defined(RFR_MATH_ARCH_AVX)
    /* we don't get 256-bit integer instructions until AVX-2 so just split the registers for now */
    RfrVec4i locReg1, locReg2, locReg3, locReg4;
    _mm256_storeu2_m128i(&locReg1, &locReg2, inLHS);
    _mm256_storeu2_m128i(&locReg3, &locReg4, inRHS);
    RfrVec4i locResult1 = _mm_mul_epi32(locReg1, locReg3);
    RfrVec4i locResult2 = _mm_mul_epi32(locReg2, locReg4);
    return _mm256_loadu2_m128i(&locResult1, &locResult2);
#elif defined(RFR_MATH_ARCH_NEON)

#endif
}

RfrVec8f rfr_math_vec8f_mul(RfrVec8f inLHS, RfrVec8f inRHS)
{
#if defined(RFR_MATH_ARCH_AVX)
    return _mm256_mul_ps(inLHS, inRHS);
#elif defined(RFR_MATH_ARCH_NEON)

#endif
}

RfrVec4d rfr_math_vec4d_mul(RfrVec4d inLHS, RfrVec4d inRHS)
{
#if defined(RFR_MATH_ARCH_AVX)
    return _mm256_mul_pd(inLHS, inRHS);
#elif defined(RFR_MATH_ARCH_NEON)

#endif
}

/* --------------------------------------------------------
 * VECTOR DIVIDE
 */

RfrVec4i rfr_math_vec4i_div(RfrVec4i inLHS, RfrVec4i inRHS)
{
#if defined(RFR_MATH_ARCH_AVX)
    /* this is awful but it should work for now */
    return _mm_cvtps_epi32(_mm_div_ps(_mm_cvtepi32_ps(inLHS), _mm_cvtepi32_ps(inRHS)));
#elif defined(RFR_MATH_ARCH_NEON)

#endif
}

RfrVec4f rfr_math_vec4f_div(RfrVec4f inLHS, RfrVec4f inRHS)
{
#if defined(RFR_MATH_ARCH_AVX)
    return _mm_div_ps(inLHS, inRHS);
#elif defined(RFR_MATH_ARCH_NEON)

#endif
}

RfrVec2d rfr_math_vec2d_div(RfrVec2d inLHS, RfrVec2d inRHS)
{
#if defined(RFR_MATH_ARCH_AVX)
    return _mm_div_pd(inLHS, inRHS);
#elif defined(RFR_MATH_ARCH_NEON)

#endif
}

RfrVec8i rfr_math_vec8i_div(RfrVec8i inLHS, RfrVec8i inRHS)
{
#if defined(RFR_MATH_ARCH_AVX)
    /* we don't get 256-bit integer instructions until AVX-2 so just split the registers for now */
    RfrVec4i locReg1, locReg2, locReg3, locReg4;
    _mm256_storeu2_m128i(&locReg1, &locReg2, inLHS);
    _mm256_storeu2_m128i(&locReg3, &locReg4, inRHS);
    /* again this is awful but it should work for now */
    RfrVec4i locResult1 = _mm_cvtps_epi32(_mm_div_ps(_mm_cvtepi32_ps(locReg1), _mm_cvtepi32_ps(locReg3)));
    RfrVec4i locResult2 = _mm_cvtps_epi32(_mm_div_ps(_mm_cvtepi32_ps(locReg2), _mm_cvtepi32_ps(locReg4)));
    return _mm256_loadu2_m128i(&locResult1, &locResult2);
#elif defined(RFR_MATH_ARCH_NEON)

#endif
}

RfrVec8f rfr_math_vec8f_div(RfrVec8f inLHS, RfrVec8f inRHS)
{
#if defined(RFR_MATH_ARCH_AVX)
    return _mm256_div_ps(inLHS, inRHS);
#elif defined(RFR_MATH_ARCH_NEON)

#endif
}

RfrVec4d rfr_math_vec4d_div(RfrVec4d inLHS, RfrVec4d inRHS)
{
#if defined(RFR_MATH_ARCH_AVX)
    return _mm256_div_pd(inLHS, inRHS);
#elif defined(RFR_MATH_ARCH_NEON)

#endif
}

#ifdef      __cplusplus
} /* extern "C" */
#endif

#endif  /*  REFRACTOR_MATH_IMPL_AVX_H  */