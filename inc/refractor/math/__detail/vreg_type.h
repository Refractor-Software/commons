#ifndef     REFRACTOR_MATH_DETAIL_VREG_TYPE_H
#define     REFRACTOR_MATH_DETAIL_VREG_TYPE_H

#include    "refractor/core/core.h"
#include    "vreg_def.h"

#if defined(R_ARCH_USE_SSE2) || defined(R_ARCH_USE_AVX)
    #if defined(R_COMPILER_CL)
        #include "intrin.h"
    #elif defined(R_COMPILER_GCC) || defined(R_COMPILER_CLANG)
        #include "immintrin.h"
    #endif
#elif defined(R_ARCH_USE_NEON)
    #include "arm_neon.h"
#endif

R_EXTERN_C_BEGIN

/* RV64 *************************************************************/

typedef struct RV64f {
    union {
        RF32        f32[2];

        #if defined(R_ARCH_USE_SSE2)
        __m64       m64;
        #elif defined(R_ARCH_USE_NEON)        
        float32x2_t f32x2;
        #endif
    } u;
} RV64f;

typedef struct RV64i {
    union {
        RU8         u8[8];
        RS8         s8[8];

        RU16        u16[4];
        RS16        s16[4];

        RU32        u32[2];
        RS32        s32[2];

        #if defined(R_ARCH_USE_NEON)
        int8x8_t    i8x8;
        uint8x8_t   u8x8;
        
        int16x4_t   i64x4;
        uint16x4_t  u64x4;
        
        int32x2_t   i32x2;
        uint32x2_t  u32x2;
        #endif
    } u;
} RV64i;

/* RV128 ************************************************************/

typedef struct RV128f {
    union {
        RF32        f32[4];

        RV64f       v64[2];

        #if defined(R_ARCH_USE_SSE2)
        __m128      m128;
        #elif defined(R_ARCH_USE_NEON)
        float32x4_t f32x4;
        #endif
    } u;
} RV128f;

typedef struct RV128d {
    union {
        RF64        f64[2];

        #if defined(R_ARCH_USE_SSE2)
        __m128d     m128d;
        #elif defined(R_ARCH_USE_NEON)
        float64x2_t f64x2;
        #endif
    } u;
} RV128d;

typedef struct RV128i {
    union {
        RU8         u8[16];
        RS8         s8[16];

        RU16        u16[8];
        RS16        s16[8];

        RU32        u32[4];
        RS32        s32[4];

        RU64        u64[2];
        RS64        s64[2];
        
        RV64i       v64[2];

        #if defined(R_ARCH_USE_SSE2)
        __m128i     m128i;
        #elif defined(R_ARCH_USE_NEON)
        int64x2_t   i64x2;
        uint64x2_t  u64x2;
        
        int32x4_t   i32x4;
        uint32x4_t  u32x4;
        
        int16x8_t   i16x8;
        uint16x8_t  u16x8;
        
        int8x16_t   i8x16;
        uint8x16_t  u8x16;
        #endif
    } u;
} RV128i;

/* RV256 ************************************************************/

typedef struct RV256f {
    union {
        RF32        f32[8];

        RV64f       v64[4];
        RV128f      v128[2];

        #if defined(R_ARCH_USE_AVX)
        __m256      m256;
        #elif defined(R_ARCH_USE_SSE2)
        __m128      m128[2];
        #elif defined(R_ARCH_USE_NEON)
        float32x4_t f32x4[2];
        #endif
    } u;
} RV256f;

typedef struct RV256d {
    union {
        RF64        f64[4];

        RV128d      v128[2];

        #if defined(R_ARCH_USE_AVX)
        __m256d     m256d;
        #elif defined(R_ARCH_USE_SSE2)
        __m128d     m128d[2];
        #elif defined(R_ARCH_USE_NEON)        
        float64x2_t f64x2[2];
        #endif
    } u;
} RV256d;

typedef struct RV256i {
    union {
        RU8         u8[32];
        RS8         s8[32];

        RU16        u16[16];
        RS16        s16[16];

        RU32        u32[8];
        RS32        s32[8];

        RU64        u64[4];
        RS64        s64[4];

        RV64i       v64[4];
        RV128i      v128[2];

        #if defined(R_ARCH_USE_AVX)
        __m256i     m256i;
        #elif defined(R_ARCH_USE_SSE2)
        __m128i     m128i[2];
        #elif defined(R_ARCH_USE_NEON)
        int64x2_t   i64x2[2];
        uint64x2_t  u64x2[2];
        
        int32x4_t   i32x4[2];
        uint32x4_t  u32x4[2];
        
        int16x8_t   i16x8[2];
        uint16x8_t  u16x8[2];
        
        int8x16_t   i8x16[2];
        uint8x16_t  u8x16[2];
        #endif
    } u;
} RV256i;

/* RV512 ************************************************************/

typedef struct RV512f {
    union {
        RF32    f32[16];

        RV64f   v64[8];
        RV128f  v128[4];
        RV256f  v256[2];

        #if defined(R_ARCH_USE_AVX)
        __m256  m256[2];
        #elif defined(R_ARCH_USE_SSE2)
        __m128  m128[4];
        #elif defined(R_ARCH_USE_NEON)
        float32x4_t f32x4[4];
        #endif
    } u;
} RV512f;

typedef struct RV512d {
    union {
        RF64    f64[8];

        RV128d  v128[4];
        RV256d  v256[2];

        #if defined(R_ARCH_USE_AVX)
        __m256d m256d[2];
        #elif defined(R_ARCH_USE_SSE2)
        __m128d m128d[4];
        #elif defined(R_ARCH_USE_NEON)        
        float64x2_t f64x2[4];
        #endif
    } u;
} RV512d;

typedef struct RV512i {
    union {
        RU8     u8[64];
        RS8     s8[64];

        RU16    u16[32];
        RS16    s16[32];

        RU32    u32[16];
        RS32    s32[16];

        RU64    u64[8];
        RS64    s64[8];

        RV64i   v64[8];
        RV128i  v128[4];
        RV256i  v256[2];

        #if defined(R_ARCH_USE_AVX)
        __m256i m256i[2];
        #elif defined(R_ARCH_USE_SSE2)
        __m128i m128i[4];
        #elif defined(R_ARCH_USE_NEON)
        int64x2_t   i64x2[4];
        uint64x2_t  u64x2[4];

        int32x4_t   i32x4[4];
        uint32x4_t  u32x4[4];

        int16x8_t   i16x8[4];
        uint16x8_t  u16x8[4];

        int8x16_t   i8x16[4];
        uint8x16_t  u8x16[4];
        #endif
    } u;
} RV512i;

R_EXTERN_C_END

#endif  /*  REFRACTOR_MATH_DETAIL_VREG_TYPE_H  */