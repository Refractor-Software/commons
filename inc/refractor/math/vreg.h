#ifndef     REFRACTOR_MATH_VREG_H
#define     REFRACTOR_MATH_VREG_H

#include    "refractor/core/core.h"

R_EXTERN_C_BEGIN

/* RV64 *************************************************************/

R_FWD_DECL(struct, RV64i);
R_FWD_DECL(struct, RV64f);

/* create */

RV64i rV64iCreateU8     (RU8*  /* [08] */);
RV64i rV64iCreateS8     (RS8*  /* [08] */);

RV64i rV64iCreateU16    (RU16* /* [04] */);
RV64i rV64iCreateS16    (RS16* /* [04] */);

RV64i rV64iCreateU32    (RU32* /* [02] */);
RV64i rV64iCreateS32    (RS32* /* [02] */);

RV64f rV64fCreateF32    (RF32* /* [02] */);

/* add */

RV64i rV64iAddU8        (RV64i InA, RV64i InB);
RV64i rV64iAddS8        (RV64i InA, RV64i InB);

RV64i rV64iAddU16       (RV64i InA, RV64i InB);
RV64i rV64iAddS16       (RV64i InA, RV64i InB);

RV64i rV64iAddU32       (RV64i InA, RV64i InB);
RV64i rV64iAddS32       (RV64i InA, RV64i InB);

RV64f rV64fAddF32       (RV64f InA, RV64f InB);

/* subtract */

RV64i rV64iSubU8        (RV64i InA, RV64i InB);
RV64i rV64iSubS8        (RV64i InA, RV64i InB);

RV64i rV64iSubU16       (RV64i InA, RV64i InB);
RV64i rV64iSubS16       (RV64i InA, RV64i InB);

RV64i rV64iSubU32       (RV64i InA, RV64i InB);
RV64i rV64iSubS32       (RV64i InA, RV64i InB);

RV64f rV64fSubF32       (RV64f InA, RV64f InB);

/* multiply */

RV64i rV64iMulU8        (RV64i InA, RV64i InB);
RV64i rV64iMulS8        (RV64i InA, RV64i InB);

RV64i rV64iMulU16       (RV64i InA, RV64i InB);
RV64i rV64iMulS16       (RV64i InA, RV64i InB);

RV64i rV64iMulU32       (RV64i InA, RV64i InB);
RV64i rV64iMulS32       (RV64i InA, RV64i InB);

RV64f rV64fMulF32       (RV64f InA, RV64f InB);

/* divide */

RV64i rV64iDivU8        (RV64i InA, RV64i InB);
RV64i rV64iDivS8        (RV64i InA, RV64i InB);

RV64i rV64iDivU16       (RV64i InA, RV64i InB);
RV64i rV64iDivS16       (RV64i InA, RV64i InB);

RV64i rV64iDivU32       (RV64i InA, RV64i InB);
RV64i rV64iDivS32       (RV64i InA, RV64i InB);

RV64f rV64fDivF32       (RV64f InA, RV64f InB);

/* RV128 ************************************************************/

R_FWD_DECL(struct, RV128i);
R_FWD_DECL(struct, RV128f);
R_FWD_DECL(struct, RV128d);

/* create */

RV128i rV128iCreateU8   (RU8*   /* [16] */);
RV128i rV128iCreateS8   (RS8*   /* [16] */);

RV128i rV128iCreateU16  (RU16*  /* [08] */);
RV128i rV128iCreateS16  (RS16*  /* [08] */);

RV128i rV128iCreateU32  (RU32*  /* [04] */);
RV128i rV128iCreateS32  (RS32*  /* [04] */);

RV128f rV128fCreateF32  (RF32*  /* [04] */);

RV128i rV128iCreateU64  (RU64*  /* [02] */);
RV128i rV128iCreateS64  (RS64*  /* [02] */);

RV128d rV128dCreateF64  (RF64*  /* [02] */);

RV128i rV128iCreateV64  (RV64i* /* [02] */);
RV128f rV128fCreateV64  (RV64f* /* [02] */);

/* add */

RV128i rV128iAddU8      (RV128i InA, RV128i InB);
RV128i rV128iAddS8      (RV128i InA, RV128i InB);

RV128i rV128iAddU16     (RV128i InA, RV128i InB);
RV128i rV128iAddS16     (RV128i InA, RV128i InB);

RV128i rV128iAddU32     (RV128i InA, RV128i InB);
RV128i rV128iAddS32     (RV128i InA, RV128i InB);

RV128f rV128fAddF32     (RV128f InA, RV128f InB);

RV128i rV128iAddU64     (RV128i InA, RV128i InB);
RV128i rV128iAddS64     (RV128i InA, RV128i InB);

RV128d rV128dAddF64     (RV128d InA, RV128d InB);

/* subtract */

RV128i rV128iSubU8      (RV128i InA, RV128i InB);
RV128i rV128iSubS8      (RV128i InA, RV128i InB);

RV128i rV128iSubU16     (RV128i InA, RV128i InB);
RV128i rV128iSubS16     (RV128i InA, RV128i InB);

RV128i rV128iSubU32     (RV128i InA, RV128i InB);
RV128i rV128iSubS32     (RV128i InA, RV128i InB);

RV128f rV128fSubF32     (RV128f InA, RV128f InB);

RV128i rV128iSubU64     (RV128i InA, RV128i InB);
RV128i rV128iSubS64     (RV128i InA, RV128i InB);

RV128d rV128dSubF64     (RV128d InA, RV128d InB);

/* multiply */

RV128i rV128iMulU8      (RV128i InA, RV128i InB);
RV128i rV128iMulS8      (RV128i InA, RV128i InB);

RV128i rV128iMulU16     (RV128i InA, RV128i InB);
RV128i rV128iMulS16     (RV128i InA, RV128i InB);

RV128i rV128iMulU32     (RV128i InA, RV128i InB);
RV128i rV128iMulS32     (RV128i InA, RV128i InB);

RV128f rV128fMulF32     (RV128f InA, RV128f InB);

RV128i rV128iMulU64     (RV128i InA, RV128i InB);
RV128i rV128iMulS64     (RV128i InA, RV128i InB);

RV128d rV128dMulF64     (RV128d InA, RV128d InB);

/* divide */

RV128i rV128iDivU8      (RV128i InA, RV128i InB);
RV128i rV128iDivS8      (RV128i InA, RV128i InB);

RV128i rV128iDivU16     (RV128i InA, RV128i InB);
RV128i rV128iDivS16     (RV128i InA, RV128i InB);

RV128i rV128iDivU32     (RV128i InA, RV128i InB);
RV128i rV128iDivS32     (RV128i InA, RV128i InB);

RV128f rV128fDivF32     (RV128f InA, RV128f InB);

RV128i rV128iDivU64     (RV128i InA, RV128i InB);
RV128i rV128iDivS64     (RV128i InA, RV128i InB);

RV128d rV128dDivF64     (RV128d InA, RV128d InB);

/* RV256 ************************************************************/

R_FWD_DECL(struct, RV256i);
R_FWD_DECL(struct, RV256f);
R_FWD_DECL(struct, RV256d);

/* create */

RV256i rV256iCreateU8   (RU8*    /* [32] */);
RV256i rV256iCreateS8   (RS8*    /* [32] */);

RV256i rV256iCreateU16  (RU16*   /* [16] */);
RV256i rV256iCreateS16  (RS16*   /* [16] */);

RV256i rV256iCreateU32  (RU32*   /* [08] */);
RV256i rV256iCreateS32  (RS32*   /* [08] */);

RV256f rV256fCreateF32  (RF32*   /* [08] */);

RV256i rV256iCreateU64  (RU64*   /* [02] */);
RV256i rV256iCreateS64  (RS64*   /* [04] */);

RV256d rV256dCreateF64  (RF64*   /* [04] */);

RV256i rV256iCreateV64  (RV64i*  /* [04] */);
RV256i rV256iCreateV128 (RV128i* /* [02] */);

RV256f rV256fCreateV64  (RV64f*  /* [04] */);
RV256f rV256fCreateV128 (RV128f* /* [02] */);

RV256d rV256dCreateV128 (RV128d* /* [02] */);

/* add */

RV256i rV256iAddU8      (RV256i InA, RV256i InB);
RV256i rV256iAddS8      (RV256i InA, RV256i InB);

RV256i rV256iAddU16     (RV256i InA, RV256i InB);
RV256i rV256iAddS16     (RV256i InA, RV256i InB);

RV256i rV256iAddU32     (RV256i InA, RV256i InB);
RV256i rV256iAddS32     (RV256i InA, RV256i InB);

RV256f rV256fAddF32     (RV256f InA, RV256f InB);

RV256i rV256iAddU64     (RV256i InA, RV256i InB);
RV256i rV256iAddS64     (RV256i InA, RV256i InB);

RV256d rV256dAddF64     (RV256d InA, RV256d InB);

/* subtract */

RV256i rV256iSubU8      (RV256i InA, RV256i InB);
RV256i rV256iSubS8      (RV256i InA, RV256i InB);

RV256i rV256iSubU16     (RV256i InA, RV256i InB);
RV256i rV256iSubS16     (RV256i InA, RV256i InB);

RV256i rV256iSubU32     (RV256i InA, RV256i InB);
RV256i rV256iSubS32     (RV256i InA, RV256i InB);

RV256f rV256fSubF32     (RV256f InA, RV256f InB);

RV256i rV256iSubU64     (RV256i InA, RV256i InB);
RV256i rV256iSubS64     (RV256i InA, RV256i InB);

RV256d rV256dSubF64     (RV256d InA, RV256d InB);

/* multiply */

RV256i rV256iMulU8      (RV256i InA, RV256i InB);
RV256i rV256iMulS8      (RV256i InA, RV256i InB);

RV256i rV256iMulU16     (RV256i InA, RV256i InB);
RV256i rV256iMulS16     (RV256i InA, RV256i InB);

RV256i rV256iMulU32     (RV256i InA, RV256i InB);
RV256i rV256iMulS32     (RV256i InA, RV256i InB);

RV256f rV256fMulF32     (RV256f InA, RV256f InB);

RV256i rV256iMulU64     (RV256i InA, RV256i InB);
RV256i rV256iMulS64     (RV256i InA, RV256i InB);

RV256d rV256dMulF64     (RV256d InA, RV256d InB);

/* divide */

RV256i rV256iDivU8      (RV256i InA, RV256i InB);
RV256i rV256iDivS8      (RV256i InA, RV256i InB);

RV256i rV256iDivU16     (RV256i InA, RV256i InB);
RV256i rV256iDivS16     (RV256i InA, RV256i InB);

RV256i rV256iDivU32     (RV256i InA, RV256i InB);
RV256i rV256iDivS32     (RV256i InA, RV256i InB);

RV256f rV256fDivF32     (RV256f InA, RV256f InB);

RV256i rV256iDivU64     (RV256i InA, RV256i InB);
RV256i rV256iDivS64     (RV256i InA, RV256i InB);

RV256d rV256dDivF64     (RV256d InA, RV256d InB);

/* RV512 ************************************************************/

R_FWD_DECL(struct, RV512i);
R_FWD_DECL(struct, RV512f);
R_FWD_DECL(struct, RV512d);

/* create */

RV512i rV512iCreateU8   (RU8*    /* [64] */);
RV512i rV512iCreateS8   (RS8*    /* [64] */);

RV512i rV512iCreateU16  (RU16*   /* [32] */);
RV512i rV512iCreateS16  (RS16*   /* [32] */);

RV512i rV512iCreateU32  (RU32*   /* [16] */);
RV512i rV512iCreateS32  (RS32*   /* [16] */);

RV512f rV512fCreateF32  (RF32*   /* [16] */);

RV512i rV512iCreateU64  (RU64*   /* [08] */);
RV512i rV512iCreateS64  (RS64*   /* [08] */);

RV512d rV512dCreateF64  (RF64*   /* [08] */);

RV512i rV512iCreateV64  (RV64i*  /* [08] */);
RV512i rV512iCreateV128 (RV128i* /* [04] */);
RV512i rV512iCreateV256 (RV256i* /* [02] */);

RV512f rV512fCreateV64  (RV64f*  /* [08] */);
RV512f rV512fCreateV128 (RV128f* /* [04] */);
RV512f rV512fCreateV256 (RV256f* /* [02] */);

RV512d rV512dCreateV128 (RV128d* /* [04] */);
RV512d rV512dCreateV256 (RV256d* /* [02] */);

/* add */

RV512i rV512iAddU8      (RV512i InA, RV512i InB);
RV512i rV512iAddS8      (RV512i InA, RV512i InB);

RV512i rV512iAddU16     (RV512i InA, RV512i InB);
RV512i rV512iAddS16     (RV512i InA, RV512i InB);

RV512i rV512iAddU32     (RV512i InA, RV512i InB);
RV512i rV512iAddS32     (RV512i InA, RV512i InB);

RV512f rV512fAddF32     (RV512f InA, RV512f InB);

RV512i rV512iAddU64     (RV512i InA, RV512i InB);
RV512i rV512iAddS64     (RV512i InA, RV512i InB);

RV512d rV512dAddF64     (RV512d InA, RV512d InB);

/* subtract */

RV512i rV512iSubU8      (RV512i InA, RV512i InB);
RV512i rV512iSubS8      (RV512i InA, RV512i InB);

RV512i rV512iSubU16     (RV512i InA, RV512i InB);
RV512i rV512iSubS16     (RV512i InA, RV512i InB);

RV512i rV512iSubU32     (RV512i InA, RV512i InB);
RV512i rV512iSubS32     (RV512i InA, RV512i InB);

RV512f rV512fSubF32     (RV512f InA, RV512f InB);

RV512i rV512iSubU64     (RV512i InA, RV512i InB);
RV512i rV512iSubS64     (RV512i InA, RV512i InB);

RV512d rV512dSubF64     (RV512d InA, RV512d InB);

/* multiply */

RV512i rV512iMulU8      (RV512i InA, RV512i InB);
RV512i rV512iMulS8      (RV512i InA, RV512i InB);

RV512i rV512iMulU16     (RV512i InA, RV512i InB);
RV512i rV512iMulS16     (RV512i InA, RV512i InB);

RV512i rV512iMulU32     (RV512i InA, RV512i InB);
RV512i rV512iMulS32     (RV512i InA, RV512i InB);

RV512f rV512fMulF32     (RV512f InA, RV512f InB);

RV512i rV512iMulU64     (RV512i InA, RV512i InB);
RV512i rV512iMulS64     (RV512i InA, RV512i InB);

RV512d rV512dMulF64     (RV512d InA, RV512d InB);

/* divide */

RV512i rV512iDivU8      (RV512i InA, RV512i InB);
RV512i rV512iDivS8      (RV512i InA, RV512i InB);

RV512i rV512iDivU16     (RV512i InA, RV512i InB);
RV512i rV512iDivS16     (RV512i InA, RV512i InB);

RV512i rV512iDivU32     (RV512i InA, RV512i InB);
RV512i rV512iDivS32     (RV512i InA, RV512i InB);

RV512f rV512fDivF32     (RV512f InA, RV512f InB);

RV512i rV512iDivU64     (RV512i InA, RV512i InB);
RV512i rV512iDivS64     (RV512i InA, RV512i InB);

RV512d rV512dDivF64     (RV512d InA, RV512d InB);

R_EXTERN_C_END

#include    "__detail/vreg_math.h"

#endif  /*  REFRACTOR_MATH_VREG_H  */
