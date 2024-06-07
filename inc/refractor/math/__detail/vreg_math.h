#ifndef     REFRACTOR_MATH_DETAIL_VREG_MATH_H
#define     REFRACTOR_MATH_DETAIL_VREG_MATH_H

/* debugging */
#define R_ARCH_ALWAYS_SSE2
#define R_ARCH_ALWAYS_AVX

/* @TODO: NEON implementation for ARM and Apple Silicon */
/* @TODO: SVE for ARM and Apple Silicon (if I can be bothered) */
/* @TODO: Arithmetic, comparisons, etc. */

#include    "refractor/core/core.h"
#include    "refractor/math/vreg.h" /* fwd declarations of functions */
#include    "vreg_type.h"
#include    "string.h" /* memcpy, etc. */

/* internals */

RV64i _rV64iCopyPointer(void* InCopy)
{
    RV64i   LocOut;
    memcpy  (&LocOut, InCopy, sizeof(LocOut));
    return  LocOut;
}
RV64f _rV64fCopyPointer(void* InCopy)
{
    RV64f   LocOut;
    memcpy  (&LocOut, InCopy, sizeof(LocOut));
    return  LocOut;
}



RV128i _rV128iCopyPointer(void* InCopy)
{
    RV128i  LocOut;
    memcpy  (&LocOut, InCopy, sizeof(LocOut));
    return  LocOut;
}
RV128f _rV128fCopyPointer(void* InCopy)
{
    RV128f  LocOut;
    memcpy  (&LocOut, InCopy, sizeof(LocOut));
    return  LocOut;
}
RV128d _rV128dCopyPointer(void* InCopy)
{
    RV128d  LocOut;
    memcpy  (&LocOut, InCopy, sizeof(LocOut));
    return  LocOut;
}



RV256i _rV256iCopyPointer(void* InCopy)
{
    RV256i  LocOut;
    memcpy  (&LocOut, InCopy, sizeof(LocOut));
    return  LocOut;
}
RV256f _rV256fCopyPointer(void* InCopy)
{
    RV256f  LocOut;
    memcpy  (&LocOut, InCopy, sizeof(LocOut));
    return  LocOut;
}
RV256d _rV256dCopyPointer(void* InCopy)
{
    RV256d  LocOut;
    memcpy  (&LocOut, InCopy, sizeof(LocOut));
    return  LocOut;
}



RV512i _rV512iCopyPointer(void* InCopy)
{
    RV512i  LocOut;
    memcpy  (&LocOut, InCopy, sizeof(LocOut));
    return  LocOut;
}
RV512f _rV512fCopyPointer(void* InCopy)
{
    RV512f  LocOut;
    memcpy  (&LocOut, InCopy, sizeof(LocOut));
    return  LocOut;
}
RV512d _rV512dCopyPointer(void* InCopy)
{
    RV512d  LocOut;
    memcpy  (&LocOut, InCopy, sizeof(LocOut));
    return  LocOut;
}

/* RV64 *************************************************************/

/* create */

RV64i rV64iCreateU8  (RU8* InP)
{
    return _rV64iCopyPointer(InP);
}
RV64i rV64iCreateS8  (RS8* InP)
{
    return _rV64iCopyPointer(InP);
}

RV64i rV64iCreateU16 (RU16* InP)
{
    return _rV64iCopyPointer(InP);
}
RV64i rV64iCreateS16 (RS16* InP)
{
    return _rV64iCopyPointer(InP);
}

RV64i rV64iCreateU32 (RU32* InP)
{
    return _rV64iCopyPointer(InP);
}
RV64i rV64iCreateS32 (RS32* InP)
{
    return _rV64iCopyPointer(InP);
}

RV64f rV64fCreateF32 (RF32* InP)
{
    return _rV64fCopyPointer(InP);
}

/* RV128 ************************************************************/

/* create */

RV128i rV128iCreateU8   (RU8* InP)
{
    return _rV128iCopyPointer(InP);
}
RV128i rV128iCreateS8   (RS8* InP)
{
    return _rV128iCopyPointer(InP);
}

RV128i rV128iCreateU16  (RU16* InP)
{
    return _rV128iCopyPointer(InP);
}
RV128i rV128iCreateS16  (RS16* InP)
{
    return _rV128iCopyPointer(InP);
}

RV128i rV128iCreateU32  (RU32* InP)
{
    return _rV128iCopyPointer(InP);
}
RV128i rV128iCreateS32  (RS32* InP)
{
    return _rV128iCopyPointer(InP);
}

RV128f rV128fCreateF32  (RF32* InP)
{
#if defined(R_ARCH_USE_SSE2)
    RV128f LocOut;
    LocOut.u.m128 = _mm_load_ps(InP);
    return LocOut;
#else
    return _rV128fCopyPointer(InP);
#endif
}

RV128i rV128iCreateU64  (RU64* InP)
{
    return _rV128iCopyPointer(InP);
}
RV128i rV128iCreateS64  (RS64* InP)
{
    return _rV128iCopyPointer(InP);
}

RV128d rV128dCreateF64  (RF64* InP)
{
#if defined(R_ARCH_USE_SSE2)
    RV128d LocOut;
    LocOut.u.m128d = _mm_load_pd(InP);
    return LocOut;
#else
    return _rV128dCopyPointer(InP);
#endif
}

/* RV256 ************************************************************/

/* create */

RV256i rV256iCreateU8   (RU8* InP)
{
    return _rV256iCopyPointer(InP);
}
RV256i rV256iCreateS8   (RS8* InP)
{
    return _rV256iCopyPointer(InP);
}

RV256i rV256iCreateU16  (RU16* InP)
{
    return _rV256iCopyPointer(InP);
}
RV256i rV256iCreateS16  (RS16* InP)
{
    return _rV256iCopyPointer(InP);
}

RV256i rV256iCreateU32  (RU32* InP)
{
    return _rV256iCopyPointer(InP);
}
RV256i rV256iCreateS32  (RS32* InP)
{
    return _rV256iCopyPointer(InP);
}

RV256f rV256fCreateF32  (RF32* InP)
{
#if defined(R_ARCH_USE_AVX)
    RV256f  LocOut;
    LocOut.u.m256 = _mm256_load_ps(InP);
    return  LocOut;
#elif defined(R_ARCH_USE_SSE2)
    RV256f  LocOut;
    LocOut.u.m128[0] = _mm_load_ps(InP);
    LocOut.u.m128[1] = _mm_load_ps(InP + 4);
    return  LocOut;
#else
    return _rV256fCopyPointer(InP);
#endif
}

RV256i rV256iCreateU64  (RU64* InP)
{
    return _rV256iCopyPointer(InP);
}
RV256i rV256iCreateS64  (RS64* InP)
{
    return _rV256iCopyPointer(InP);
}

RV256d rV256dCreateF64  (RF64* InP)
{
#if defined(R_ARCH_USE_AVX)
    RV256d  LocOut;
    LocOut.u.m256d = _mm256_load_pd(InP);
    return  LocOut;
#elif defined(R_ARCH_USE_SSE2)
    RV256d  LocOut;
    LocOut.u.m128d[0] = _mm_load_pd(InP);
    LocOut.u.m128d[1] = _mm_load_pd(InP + 2);
    return  LocOut;
#else
    return _rV256dCopyPointer(InP);
#endif
}

/* RV512 ************************************************************/

#endif  /*  REFRACTOR_MATH_DETAIL_VREG_MATH_H  */