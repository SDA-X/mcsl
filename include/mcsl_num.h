#ifndef MCSL_NUM_H
#define MCSL_NUM_H

#include "sub/begin.h"

typedef struct _aoi32 _aoi32; /*array of i32*/
typedef struct _aoi64 _aoi64; /*array of i64*/

struct _aoi32{
	_i32* item;
	size_t len;
	size_t cap;
};

struct _aoi64{
	_i64* item;
	size_t len;
	size_t cap;
};

#define aoi32_null {NULL,0,0}
#define aoi64_null {NULL,0,0}

#ifdef MCSL_CPP
MCSL_EXTERN_C_OPEN
#endif

MCSL_API _u64 mcsl_n_prime_r(_u64 start,_u64 end, void *usrp, void (*sender)(void *usrp,_u64 x));
MCSL_INLINE_STATIC
_u64 mcsl_n_prime(_u64 start,_u64 end){return mcsl_n_prime_r(start,end,NULL,NULL);}
MCSL_API MCSL_ATTR (const) bool mcsl_is_prime(_u64 a);

#ifdef MCSL_CPP
MCSL_EXTERN_C_CLOSE
#endif

#define AOI_BVAR 32
#include "sub/dec/aoi.h"
#undef AOI_BVAR

#define AOI_BVAR 64
#include "sub/dec/aoi.h"
#undef AOI_BVAR

#define AOI_DEC_END
#include "sub/dec/aoi.h"
#undef AOI_DEC_END

#endif