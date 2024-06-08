#ifndef     REFRACTOR_MATH_H
#define     REFRACTOR_MATH_H

#include    "refractor/core/core.h"

#define r_gigabytes(n)      (u64)(n * 1024 * 1024 * 1024)
#define r_megabytes(n)      (u64)(n * 1024 * 1024)
#define r_kilobytes(n)      (u64)(n * 1024)

#define r_min(a, b)         (((a)<(b))?(a):(b))
#define r_max(a, b)         (((a)>(b))?(a):(b))
#define r_clamp(a, b, x)    (((x)<(a))?(a):((b)<(x))?(b):(x))
#define r_wrap(a, b, x)     r_clamp(b, a, x)

#endif  /*  REFRACTOR_MATH_H  */
