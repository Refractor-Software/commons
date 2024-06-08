#ifndef     REFRACTOR_CORE_DETAIL_GNULNX_CORE_H
#define     REFRACTOR_CORE_DETAIL_GNULNX_CORE_H

typedef     unsigned char       RU8;
typedef     unsigned short      RU16;
typedef     unsigned int        RU32;
typedef     unsigned long long  RU64;

typedef     signed char         RS8;
typedef     signed short        RS16;
typedef     signed int          RS32;
typedef     signed long long    RS64;

typedef     float               RF32;
typedef     double              RF64;

#include "unistd.h"
#define r_file_get_cwd  getcwd

#endif  /*  REFRACTOR_CORE_DETAIL_GNULNX_CORE_H  */
