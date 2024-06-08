#ifndef     REFRACTOR_MATH_DETAIL_VREG_DEF_H
#define     REFRACTOR_MATH_DETAIL_VREG_DEF_H

/* preprocessor tokens for vector register features */

#if !defined(R_ARCH_USE_SSE2)
    #if defined(R_ARCH_ALWAYS_SSE2)
        #define R_ARCH_USE_SSE2
    #endif
#endif

#if !defined(R_ARCH_USE_AVX)
    #if defined(R_ARCH_ALWAYS_AVX)
        #define R_ARCH_USE_SSE2   /* use SSE4.2 as well */
        #define R_ARCH_USE_AVX
    #endif
#endif

#if !defined(R_ARCH_USE_NEON)
    #if defined(R_ARCH_ALWAYS_NEON)
        #define R_ARCH_USE_NEON
    #endif
#endif

#define R_MATH_FLOAT_ALIGN 16

#if defined(R_ARCH_USE_AVX)
    #define R_MATH_DOUBLE_ALIGN 32
#else
    #define R_MATH_DOUBLE_ALIGN 16
#endif

#endif  /*  REFRACTOR_MATH_DETAIL_VREG_DEF_H  */
