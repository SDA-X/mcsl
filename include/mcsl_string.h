#ifndef MCSL_STRING_H
#define MCSL_STRING_H

#include "sub/begin.h"
#include <string.h>

#define MCSL_STR_COLOR "\x1b["
#define MCSL_STR_COLOR_RESET "\x1b[0m"
#define MCSL_STR_BG_BLACK "40;"
#define MCSL_STR_BG_RED "41;"
#define MCSL_STR_BG_GREEN "42;"
#define MCSL_STR_BG_YELLOW "43;"
#define MCSL_STR_BG_BLUE "44;"
#define MCSL_STR_BG_UNGU "45;"
#define MCSL_STR_BG_CYAN "46;"
#define MCSL_STR_BG_WHITE "47;"
#define MCSL_STR_BG_GRAY "40;"
#define MCSL_STR_BG_BRIGHT_RED "101;"
#define MCSL_STR_BG_BRIGHT_GREEN "102;"
#define MCSL_STR_BG_BRIGHT_YELLOW "103;"
#define MCSL_STR_BG_BRIGHT_BLUE "104;"
#define MCSL_STR_BG_BRIGHT_UNGU "105;"
#define MCSL_STR_BG_BRIGHT_CYAN "106;"
#define MCSL_STR_BG_BRIGHT_WHITE "107;"
#define MCSL_STR_FG_BLACK "30m"
#define MCSL_STR_FG_RED "31m"
#define MCSL_STR_FG_GREEN "32m"
#define MCSL_STR_FG_YELLOW "33m"
#define MCSL_STR_FG_BLUE "34m"
#define MCSL_STR_FG_UNGU "35m"
#define MCSL_STR_FG_CYAN "36m"
#define MCSL_STR_FG_WHITE "37m"
#define MCSL_STR_FG_GRAY "90m"
#define MCSL_STR_FG_BRIGHT_RED "91m"
#define MCSL_STR_FG_BRIGHT_GREEN "92m"
#define MCSL_STR_FG_BRIGHT_YELLOW "93m"
#define MCSL_STR_FG_BRIGHT_BLUE "94m"
#define MCSL_STR_FG_BRIGHT_UNGU "95m"
#define MCSL_STR_FG_BRIGHT_CYAN "96m"
#define MCSL_STR_FG_BRIGHT_WHITE "97m"

#define MCSL_STR_COLOR_BLACK MCSL_STR_COLOR MCSL_STR_FG_BLACK
#define MCSL_STR_COLOR_RED MCSL_STR_COLOR MCSL_STR_FG_RED
#define MCSL_STR_COLOR_GREEN MCSL_STR_COLOR MCSL_STR_FG_GREEN
#define MCSL_STR_COLOR_YELLOW MCSL_STR_COLOR MCSL_STR_FG_YELLOW
#define MCSL_STR_COLOR_BLUE MCSL_STR_COLOR MCSL_STR_FG_BLUE
#define MCSL_STR_COLOR_UNGU MCSL_STR_COLOR MCSL_STR_FG_UNGU
#define MCSL_STR_COLOR_CYAN MCSL_STR_COLOR MCSL_STR_FG_CYAN
#define MCSL_STR_COLOR_WHITE MCSL_STR_COLOR MCSL_STR_FG_WHITE
#define MCSL_STR_COLOR_GRAY MCSL_STR_COLOR MCSL_STR_FG_GRAY
#define MCSL_STR_COLOR_BRIGHT_RED MCSL_STR_COLOR MCSL_STR_FG_BRIGHT_RED
#define MCSL_STR_COLOR_BRIGHT_GREEN MCSL_STR_COLOR MCSL_STR_FG_BRIGHT_GREEN
#define MCSL_STR_COLOR_BRIGHT_YELLOW MCSL_STR_COLOR MCSL_STR_FG_BRIGHT_YELLOW
#define MCSL_STR_COLOR_BRIGHT_BLUE MCSL_STR_COLOR MCSL_STR_FG_BRIGHT_BLUE
#define MCSL_STR_COLOR_BRIGHT_UNGU MCSL_STR_COLOR MCSL_STR_FG_BRIGHT_UNGU
#define MCSL_STR_COLOR_BRIGHT_CYAN MCSL_STR_COLOR MCSL_STR_FG_BRIGHT_CYAN
#define MCSL_STR_COLOR_BRIGHT_WHITE MCSL_STR_COLOR MCSL_STR_FG_BRIGHT_WHITE

#if MCSL_CAN_GET_ARGS

#define MCSL_STR_COLOR_BLACK_F(...) MCSL_STR_COLOR_BLACK __VA_ARGS__ MCSL_STR_COLOR_RESET
#define MCSL_STR_COLOR_RED_F(...) MCSL_STR_COLOR_RED __VA_ARGS__ MCSL_STR_COLOR_RESET
#define MCSL_STR_COLOR_GREEN_F(...) MCSL_STR_COLOR_GREEN __VA_ARGS__ MCSL_STR_COLOR_RESET
#define MCSL_STR_COLOR_YELLOW_F(...) MCSL_STR_COLOR_YELLOW __VA_ARGS__ MCSL_STR_COLOR_RESET
#define MCSL_STR_COLOR_BLUE_F(...) MCSL_STR_COLOR_BLUE __VA_ARGS__ MCSL_STR_COLOR_RESET
#define MCSL_STR_COLOR_UNGU_F(...) MCSL_STR_COLOR_UNGU __VA_ARGS__ MCSL_STR_COLOR_RESET
#define MCSL_STR_COLOR_CYAN_F(...) MCSL_STR_COLOR_CYAN __VA_ARGS__ MCSL_STR_COLOR_RESET
#define MCSL_STR_COLOR_WHITE_F(...) MCSL_STR_COLOR_WHITE __VA_ARGS__ MCSL_STR_COLOR_RESET
#define MCSL_STR_COLOR_GRAY_F(...) MCSL_STR_COLOR_GRAY __VA_ARGS__ MCSL_STR_COLOR_RESET
#define MCSL_STR_COLOR_BRIGHT_RED_F(...) MCSL_STR_COLOR_BRIGHT_RED __VA_ARGS__ MCSL_STR_COLOR_RESET
#define MCSL_STR_COLOR_BRIGHT_GREEN_F(...) MCSL_STR_COLOR_BRIGHT_GREEN __VA_ARGS__ MCSL_STR_COLOR_RESET
#define MCSL_STR_COLOR_BRIGHT_YELLOW_F(...) MCSL_STR_COLOR_BRIGHT_YELLOW __VA_ARGS__ MCSL_STR_COLOR_RESET
#define MCSL_STR_COLOR_BRIGHT_BLUE_F(...) MCSL_STR_COLOR_BRIGHT_BLUE __VA_ARGS__ MCSL_STR_COLOR_RESET
#define MCSL_STR_COLOR_BRIGHT_UNGU_F(...) MCSL_STR_COLOR_BRIGHT_UNGU __VA_ARGS__ MCSL_STR_COLOR_RESET
#define MCSL_STR_COLOR_BRIGHT_CYAN_F(...) MCSL_STR_COLOR_BRIGHT_CYAN __VA_ARGS__ MCSL_STR_COLOR_RESET
#define MCSL_STR_COLOR_BRIGHT_WHITE_F(...) MCSL_STR_COLOR_BRIGHT_WHITE __VA_ARGS__ MCSL_STR_COLOR_RESET

#endif

#define mcsl_str_make mcsl_strdup
#define mcsl_str_make_l mcsl_strndup

#define mcsl_str_make_alloca(s)\
	(__extension__({\
		const cstring __old = (s);\
		size_t __len = mcsl_str_get_len (__old) + 1;\
		cstring __new = (cstring) mcsl_alloca (__len);\
		(cstring) mcsl_memcpy (__new, __old, __len);\
	}))

#define mcsl_str_make_l_alloca(s,n)\
	(__extension__({\
		const cstring __old = (s);\
		size_t __len = mcsl_strnlen (__old, (n));\
		cstring __new = (cstring) mcsl_alloca (__len + 1);\
		*(__new+__len) = '\0';\
		(cstring) mcsl_memcpy (__new, __old, __len);\
	}))

#ifdef MCSL_CPP
MCSL_EXTERN_C_OPEN
#endif

MCSL_API MCSL_WUR MCSL_ATTR (nonnull(1)) _i64 mcsl_str_to_i64(const cstring s);
MCSL_API MCSL_WUR MCSL_ATTR (nonnull(1)) _u64 mcsl_str_to_u64(const cstring s);
MCSL_API MCSL_WUR MCSL_ATTR (nonnull(1)) _f32 mcsl_str_to_f32(const cstring s);
MCSL_API MCSL_WUR MCSL_ATTR (nonnull(1)) _f64 mcsl_str_to_f64(const cstring s);
MCSL_API MCSL_WUR MCSL_ATTR (nonnull(1)) _f128 mcsl_str_to_f128(const cstring s);

MCSL_API MCSL_WUR MCSL_ATTR (nonnull(1)) _i64 mcsl_str_to_i64_fast(const cstring s);
MCSL_API MCSL_WUR MCSL_ATTR (nonnull(1)) _u64 mcsl_str_to_u64_fast(const cstring s);
MCSL_API MCSL_WUR MCSL_ATTR (nonnull(1)) _f32 mcsl_str_to_f32_fast(const cstring s);
MCSL_API MCSL_WUR MCSL_ATTR (nonnull(1)) _f64 mcsl_str_to_f64_fast(const cstring s);
MCSL_API MCSL_WUR MCSL_ATTR (nonnull(1)) _f128 mcsl_str_to_f128_fast(const cstring s);

MCSL_API MCSL_WUR MCSL_ATTR (nonnull(1)) size_t mcsl_str_is_uint(const cstring s);
MCSL_INLINE_STATIC MCSL_WUR MCSL_ATTR (nonnull(1)) size_t mcsl_str_is_int(const cstring s){
	return (*s != '-') ? mcsl_str_is_uint(s) : (*(s+1) != '\0') ? mcsl_str_is_uint(s+1) : 0;
}
MCSL_API MCSL_WUR MCSL_ATTR (nonnull(1)) size_t mcsl_str_is_float(const cstring s);

MCSL_API MCSL_WUR cstring __mcsl_int_to_str(_i64 num, cstring buf, bool use_buf, _i32 ndigit, bool use_ndigit);
MCSL_API MCSL_WUR cstring __mcsl_uint_to_str(_u64 num, cstring buf, bool use_buf, _i32 ndigit, bool use_ndigit);
/*MCSL_API MCSL_WUR cstring __mcsl_float_to_str(_f64 num, cstring buf, bool use_buf, _i32 ndigit, bool use_ndigit);*/

MCSL_API MCSL_WUR MCSL_ATTR (malloc) cstring mcsl_int_to_str(_i64 num);
MCSL_API MCSL_WUR MCSL_ATTR (malloc) cstring mcsl_uint_to_str(_u64 num);
/*MCSL_API MCSL_WUR MCSL_ATTR (malloc) cstring mcsl_float_to_str(_f64 num);*/

#define mcsl_int_to_str_alloca(__a)\
	(__extension__\
		({\
			MCSL_REG _u32 l;\
			MCSL_REG cstring r;\
			MCSL_REG _i64 _a_ = (_i64)(__a);\
			if (_a_ < 0){\
				_a_ = -_a_;\
				l = (mcsl_lenu(_a_)) + 1;\
			}\
			else l = mcsl_lenu(_a_);\
			r = (cstring)mcsl_alloca(l+1); *r = '-';\
			*(r+l) = '\0'; l--; *(r+l) = '0';\
			while (_a_){\
				*(r+l) = (_a_ % 0xA) + 0x30; l--;\
				_a_ /= 0xA;\
			}\
			r;\
		}))

#define mcsl_uint_to_str_alloca(__a)\
	(__extension__\
	({\
		MCSL_REG _u64 _a_ = (_u64)(__a);\
		MCSL_REG _u32 l = mcsl_lenu(_a_);\
		MCSL_REG cstring r = (cstring)mcsl_alloca(l+1);\
		*(r+l) = '\0'; l--; *(r+l) = '0';\
		while (_a_){\
			*(r+l) = (_a_ % 0xA) + 0x30; l--;\
			_a_ /= 0xA;\
		}\
		r;\
	}))

/*#define mcsl_float_to_str_alloca(__a)\
	(__extension__({\
		_f64 a = (_f64)(__a);\
		_u32 l = mcsl_lend(a);\
		cstring r = (cstring)MCSL_alloca(l+ 1 + 2 + 3);\
		__mcsl_float_to_str(a,r,l+3,true,true);\
		r;\
	}))
*/
MCSL_INLINE_STATIC MCSL_WUR MCSL_ATTR (nonnull(1))
ssize_t mcsl_str_found_chr(const cstring s, char c){
	cstring _s = mcsl_strchr(s,c);
	return (!_s) ? -1 : (ssize_t)((size_t)_s-(size_t)s);
}
MCSL_INLINE_STATIC MCSL_WUR MCSL_ATTR (nonnull(1,2))
ssize_t mcsl_str_found_cstr(const cstring s,const cstring c){
	cstring _s = mcsl_strstr(s,c);
	return (!_s) ? -1 : (ssize_t)((size_t)_s-(size_t)s);
}
MCSL_INLINE_STATIC MCSL_WUR MCSL_ATTR (nonnull(1))
size_t mcsl_str_search_chr(const cstring s, char c){
	size_t res = 0;
	cstring _s = mcsl_strchr(s,c);
	while (_s){
		++res;
		_s = mcsl_strchr(_s+1,c);
	}
	return res;
}
MCSL_INLINE_STATIC MCSL_WUR MCSL_ATTR (nonnull(1,2))
size_t mcsl_str_search_cstr(const cstring s, const cstring c){
	size_t res = 0;
	size_t lc = mcsl_str_get_len(c);
	cstring _s = mcsl_strstr(s,c);
	while (_s){
		++res;
		_s = mcsl_strstr(_s+lc,c);
	}
	return res;
}
#define mcsl_str_compare(a,b) (mcsl_strcmp((a),(b)) == 0)
#define mcsl_str_l_compare(a,b,l) (mcsl_strncmp((a),(b),(l)) == 0)

MCSL_API MCSL_ATTR (nonnull(1)) void mcsl_str_to_lower_case(cstring s);
MCSL_API MCSL_ATTR (nonnull(1)) void mcsl_str_to_upper_case(cstring s);
MCSL_API MCSL_ATTR (nonnull(1)) void mcsl_str_to_capital_case(cstring s);
MCSL_API MCSL_ATTR (nonnull(1)) void mcsl_str_to_title_case(cstring s);

MCSL_API MCSL_WUR MCSL_ATTR (nonnull(1)) bool mcsl_str_is_lower_case(const cstring s);
MCSL_API MCSL_WUR MCSL_ATTR (nonnull(1)) bool mcsl_str_is_upper_case(const cstring s);
MCSL_API MCSL_WUR MCSL_ATTR (nonnull(1)) bool mcsl_str_is_capital_case(const cstring s);
MCSL_API MCSL_WUR MCSL_ATTR (nonnull(1)) bool mcsl_str_is_title_case(const cstring s);

MCSL_INLINE_STATIC MCSL_WUR char mcsl_chr_to_lower(char c){
	return ((c >= 'A') && (c <= 'Z')) ? c + 0x20 : c;
}
MCSL_INLINE_STATIC MCSL_WUR char mcsl_chr_to_upper(char c){
	return ((c >= 'a') && (c <= 'z')) ? c - 0x20 : c;
}

MCSL_INLINE_STATIC MCSL_WUR bool mcsl_chr_is_lower(char c){
	return ((c >= 'a') && (c <= 'z'));
}
MCSL_INLINE_STATIC MCSL_WUR bool mcsl_chr_is_upper(char c){
	return ((c >= 'A') && (c <= 'Z'));
}

MCSL_INLINE_STATIC bool mcsl_chr_is_int(char c){
	return (c >= '0' && c <= '9');
}

#define mcsl_chr_is_num mcsl_chr_is_int

/*aoc function*/

MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void aoc_set_null(_aoc *z){z->str = NULL; z->len = 0; z->cap = 0;}
MCSL_INLINE_STATIC MCSL_ATTR(nonnull(1))
void aoc_init(_aoc *z){
	z->len = 0; z->cap = 1;
	z->str = (cstring)mcsl_malloc(1);
	*z->str = '\0';
}
MCSL_API MCSL_ATTR(nonnull(1)) void aoc_init_n(_aoc *z,ssize_t n);
MCSL_INLINE_STATIC MCSL_ATTR(nonnull(1))
void aoc_free(_aoc *z){
	if (z->str != NULL && z->cap != 0)
		mcsl_free(z->str);
	aoc_set_null(z);
}
MCSL_API MCSL_ATTR(nonnull(1)) void aoc_shrink_to_fit(_aoc *z);
MCSL_API MCSL_ATTR(nonnull(1)) void aoc_refresh(_aoc *z);

MCSL_INLINE_STATIC MCSL_WUR _aoc aoc_new(){
	_aoc res;
	aoc_init(&res);
	return res;
}

MCSL_API MCSL_ATTR (nonnull(1)) void aoc_add_in_self(_aoc *z,size_t i,size_t l);
MCSL_API MCSL_ATTR (nonnull(1)) void aoc_add_in_self2(_aoc *z,size_t i,size_t i1,size_t i2);
MCSL_API MCSL_ATTR (nonnull(1)) void aoc_add_in_chr(_aoc *z,size_t i,char c);
MCSL_API MCSL_ATTR (nonnull(1,3)) void aoc_add_in_cstr_l_noc(_aoc *z,size_t i,const cstring s, size_t l);
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1,3))
void aoc_add_in_cstr_l(_aoc *z,size_t i,const cstring s,size_t l){aoc_add_in_cstr_l_noc(z,i,s,mcsl_strnlen(s,l));}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1,3))
void aoc_add_in_cstr(_aoc *z,size_t i,const cstring s){aoc_add_in_cstr_l_noc(z,i,s,mcsl_str_get_len(s));}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1,3))
void aoc_add_in_aoc(_aoc *z,size_t i,_aoc *s){(z != s) ? aoc_add_in_cstr_l_noc(z,i,s->str,s->len) : aoc_add_in_self(z,i,z->len); }
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1,3))
void aoc_add_in_aoc_l(_aoc *z,size_t i,_aoc *s,size_t l){(z != s) ? aoc_add_in_cstr_l_noc(z,i,s->str,(l <= s->len) ? l : s->len) : aoc_add_in_self(z,i,l); }
MCSL_API MCSL_ATTR (nonnull(1)) void aoc_add_in_int(_aoc *z,size_t i,_i64 a);
MCSL_API MCSL_ATTR (nonnull(1)) void aoc_add_in_uint(_aoc *z,size_t i,_u64 a);
/*MCSL_API MCSL_ATTR (nonnull(1)) void aoc_add_in_float(_aoc *z,size_t i,_f64 a);*/

MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void aoc_add_self(_aoc *z,size_t l){aoc_add_in_self(z,z->len,l);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void aoc_add_self2(_aoc *z,size_t i1,size_t i2){aoc_add_in_self2(z,z->len,i1,i2);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void aoc_add_chr(_aoc *z,char c){aoc_add_in_chr(z,z->len,c);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1,2))
void aoc_add_cstr_l(_aoc *z,const cstring s,size_t l){aoc_add_in_cstr_l(z,z->len,s,l);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1,2))
void aoc_add_cstr_l_noc(_aoc *z,const cstring s,size_t l){aoc_add_in_cstr_l_noc(z,z->len,s,l);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1,2))
void aoc_add_cstr(_aoc *z, const cstring s){aoc_add_cstr_l_noc(z,s,mcsl_str_get_len(s));}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1,2))
void aoc_add_aoc(_aoc *z,_aoc *s){(z != s) ? aoc_add_cstr_l_noc(z,s->str,s->len) : aoc_add_self(z,z->len);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1,2))
void aoc_add_aoc_l(_aoc *z,_aoc *s,size_t l){(z != s) ? aoc_add_cstr_l_noc(z,s->str,l) : aoc_add_self(z,l);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void aoc_add_int(_aoc *z, _i64 a){aoc_add_in_int(z,z->len,a);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void aoc_add_uint(_aoc *z, _u64 a){aoc_add_in_uint(z,z->len,a);}
/*MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void aoc_add_float(_aoc *z, _f64 a){aoc_add_in_float(z,z->len,a);}*/

MCSL_API MCSL_ATTR (nonnull(1)) void aoc_set_chr(_aoc *z,char c);
MCSL_API MCSL_ATTR (nonnull(1,2)) void aoc_set_cstr_l_noc(_aoc *z,const cstring s, size_t l);
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1,2))
void aoc_set_cstr_l(_aoc *z,const cstring s, size_t l){aoc_set_cstr_l_noc(z,s,mcsl_strnlen(s,l));}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1,2))
void aoc_set_cstr(_aoc *z,const cstring s){aoc_set_cstr_l_noc(z,s,mcsl_str_get_len(s));}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1,2))
void aoc_set_aoc(_aoc *z,_aoc *s){if (z != s) aoc_set_cstr_l_noc(z,s->str,s->len);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1,2))
void aoc_set_aoc_l(_aoc *z,_aoc *s,size_t l){if (z != s) aoc_set_cstr_l_noc(z,s->str,(l <= s->len) ? l : s->len);}
MCSL_API MCSL_ATTR (nonnull(1)) void aoc_set_self(_aoc *z,size_t l);
MCSL_API MCSL_ATTR (nonnull(1)) void aoc_set_self2(_aoc *z,size_t i1,size_t i2);
MCSL_API MCSL_ATTR (nonnull(1)) void aoc_set_int(_aoc *z, _i64 a);
MCSL_API MCSL_ATTR (nonnull(1)) void aoc_set_uint(_aoc *z, _u64 a);
/*MCSL_API MCSL_ATTR (nonnull(1)) void aoc_set_float(_aoc *z, _f64 a);*/

MCSL_API MCSL_ATTR (nonnull(1)) void aoc_set_in_self(_aoc *z, size_t i1,size_t i2,size_t l);
MCSL_API MCSL_ATTR (nonnull(1)) void aoc_set_in_self2(_aoc *z, size_t i1,size_t i2,size_t _i1,size_t _i2);
MCSL_API MCSL_ATTR (nonnull(1)) void aoc_set_in_chr(_aoc *z, size_t i1,size_t i2,char c);
MCSL_API MCSL_ATTR (nonnull(1,4)) void aoc_set_in_cstr_l_noc(_aoc *z, size_t i1,size_t i2,const cstring s,size_t l);
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1,4))
void aoc_set_in_cstr_l(_aoc *z, size_t i1,size_t i2,const cstring s,size_t l){aoc_set_in_cstr_l_noc(z,i1,i2,s,mcsl_strnlen(s,l));}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1,4))
void aoc_set_in_cstr(_aoc *z,size_t i1,size_t i2,const cstring s){aoc_set_in_cstr_l_noc(z,i1,i2,s,mcsl_str_get_len(s));}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1,4))
void aoc_set_in_aoc(_aoc *z,size_t i1,size_t i2,_aoc *s){aoc_set_in_cstr_l_noc(z,i1,i2,s->str,s->len);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1,4))
void aoc_set_in_aoc_l(_aoc *z,size_t i1,size_t i2,_aoc *s,size_t l){aoc_set_in_cstr_l_noc(z,i1,i2,s->str,l);}
MCSL_API MCSL_ATTR (nonnull(1)) void aoc_set_in_int(_aoc *z, size_t i1,size_t i2,_i64 a);
MCSL_API MCSL_ATTR (nonnull(1)) void aoc_set_in_uint(_aoc *z, size_t i1,size_t i2,_u64 a);
/*MCSL_API MCSL_ATTR (nonnull(1)) void aoc_set_in_float(_aoc *z, size_t i1,size_t i2,_f64 a);*/

MCSL_API MCSL_ATTR (nonnull(1)) void aoc_del_i(_aoc *z,size_t i);
MCSL_API MCSL_ATTR (nonnull(1)) void aoc_del_l(_aoc *z,size_t i1,size_t i2);
MCSL_API MCSL_ATTR (nonnull(1)) void aoc_del_search_chr(_aoc *z,char c);
MCSL_API MCSL_ATTR (nonnull(1,2)) void aoc_del_search_cstr_l_noc(_aoc *z,const cstring s,size_t l);
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1,2))
void aoc_del_search_cstr_l(_aoc *z,const cstring s,size_t l){aoc_del_search_cstr_l_noc(z,s,mcsl_strnlen(s,l));}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1,2))
void aoc_del_search_cstr(_aoc *z,const cstring s){aoc_del_search_cstr_l_noc(z,s,mcsl_str_get_len(s));}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1,2))
void aoc_del_search_aoc(_aoc *z,_aoc *s){aoc_del_search_cstr_l_noc(z,s->str,s->len);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1,2))
void aoc_del_search_aoc_l(_aoc *z,_aoc *s,size_t l){aoc_del_search_cstr_l_noc(z,s->str,l);}

MCSL_API MCSL_ATTR (nonnull(1)) void aoc_set_search_chr_chr(_aoc *z,char c,char g);
MCSL_API MCSL_ATTR (nonnull(1,3)) void aoc_set_search_chr_cstr(_aoc *z,char c,const cstring g);
MCSL_API MCSL_ATTR (nonnull(1,2)) void aoc_set_search_cstr_chr(_aoc *z,const cstring c,char g);
MCSL_API MCSL_ATTR (nonnull(1,2,3)) void aoc_set_search_cstr_cstr(_aoc *z,const cstring c, const cstring g);

MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void aoc_to_lower_case(_aoc *z){if (z->str != NULL) mcsl_str_to_lower_case(z->str);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void aoc_to_upper_case(_aoc *z){if (z->str != NULL) mcsl_str_to_upper_case(z->str);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void aoc_to_title_case(_aoc *z){if (z->str != NULL) mcsl_str_to_title_case(z->str);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void aoc_to_capital_case(_aoc *z){if (z->str != NULL) mcsl_str_to_capital_case(z->str);}

MCSL_INLINE_STATIC MCSL_WUR MCSL_ATTR (nonnull(1))
bool aoc_is_lower_case(_aoc *z){return (z->str != NULL) ? mcsl_str_is_lower_case(z->str) : false;}
MCSL_INLINE_STATIC MCSL_WUR MCSL_ATTR (nonnull(1))
bool aoc_is_upper_case(_aoc *z){return (z->str != NULL) ? mcsl_str_is_upper_case(z->str) : false;}
MCSL_INLINE_STATIC MCSL_WUR MCSL_ATTR (nonnull(1))
bool aoc_is_title_case(_aoc *z){return (z->str != NULL) ? mcsl_str_is_title_case(z->str) : false;}
MCSL_INLINE_STATIC MCSL_WUR MCSL_ATTR (nonnull(1))
bool aoc_is_capital_case(_aoc *z){return (z->str != NULL) ? mcsl_str_is_capital_case(z->str) : false;}

MCSL_INLINE_STATIC MCSL_WUR MCSL_ATTR (nonnull(1))
ssize_t aoc_found_chr(_aoc *z,char c){return (z->str != NULL) ? mcsl_str_found_chr(z->str,c) : -1;}
MCSL_INLINE_STATIC MCSL_WUR MCSL_ATTR (nonnull(1))
ssize_t aoc_found_cstr(_aoc *z,const cstring s){return (z->str != NULL) ? mcsl_str_found_cstr(z->str,s) : -1;}
MCSL_INLINE_STATIC MCSL_WUR MCSL_ATTR (nonnull(1))
ssize_t aoc_found_aoc(_aoc *z,_aoc *s){return (z->str != NULL) ? mcsl_str_found_cstr(z->str,s->str) : -1;}

MCSL_INLINE_STATIC MCSL_WUR MCSL_ATTR (nonnull(1))
size_t aoc_search_chr(_aoc *z,char c){return (z->str != NULL) ? mcsl_str_search_chr(z->str,c) : 0;}
MCSL_INLINE_STATIC MCSL_WUR MCSL_ATTR (nonnull(1))
size_t aoc_search_cstr(_aoc *z,const cstring s){return (z->str != NULL) ? mcsl_str_search_cstr(z->str,s) : 0;}
MCSL_INLINE_STATIC MCSL_WUR MCSL_ATTR (nonnull(1))
size_t aoc_search_aoc(_aoc *z,_aoc *s){return (z->str != NULL) ? mcsl_str_search_cstr(z->str,s->str) : 0;}

MCSL_INLINE_STATIC MCSL_WUR MCSL_ATTR (nonnull(1,2))
bool aoc_compare(_aoc *z1, _aoc *z2){return (z1->len == z2->len) ? mcsl_str_l_compare(z1->str,z2->str,z1->len) : false;}

MCSL_API MCSL_ATTR (nonnull(1)) void aoc_reverse(_aoc *z);

/*aos function*/

#ifdef MCSL_CPP
MCSL_EXTERN_C_CLOSE
#endif

#ifdef MCSL_CPP
namespace mcsl{
class aoc{
private:
	__typeof__(_aoc::str) __str;
	__typeof__(_aoc::len) __len;
	__typeof__(_aoc::cap) __cap;
	MCSL_ALWAYS_INLINE _aoc* __self(){return (_aoc*)this;}
	MCSL_ALWAYS_INLINE _aoc* __to_c_aoc(const aoc &z){return (_aoc*)&z;}
	MCSL_ALWAYS_INLINE _aoc* __to_c_aoc(const aoc *z){return (_aoc*)z;}
	MCSL_ALWAYS_INLINE void __init_self(){aoc_init(__self());}
public:
	aoc(){__init_self();}
	aoc(_aoc *z){__init_self(); aoc_set_aoc(__self(),z);}
	aoc(_aoc *z, size_t l){__init_self(); aoc_set_aoc_l(__self(),z,l);}
	aoc(const aoc &z){__init_self(); aoc_set_aoc(__self(),__to_c_aoc(z));}
	aoc(const aoc &z, size_t l){__init_self(); aoc_set_aoc_l(__self(),__to_c_aoc(z),l);}
	aoc(const cstring s){__init_self(); aoc_set_cstr(__self(),s);}
	aoc(const cstring s,size_t l){__init_self(); aoc_set_cstr_l(__self(),s,l);}
	~aoc(){aoc_free(__self());}
	MCSL_ALWAYS_INLINE MCSL_WUR MCSL_ATTR (const) __typeof__(__len) len(){return __len;}
	MCSL_ALWAYS_INLINE MCSL_WUR MCSL_ATTR (const) __typeof__(__cap) cap(){return __cap;}
	MCSL_ALWAYS_INLINE MCSL_WUR MCSL_ATTR (const) const cstring str(){return __str;}
	MCSL_ALWAYS_INLINE void shrink_to_fit(){aoc_shrink_to_fit(__self());}
	MCSL_ALWAYS_INLINE void refresh(){aoc_refresh(__self());}
	MCSL_ALWAYS_INLINE void free(){aoc_free(__self()); __init_self();}
	MCSL_ALWAYS_INLINE void reverse(){aoc_reverse(__self());}
	MCSL_ALWAYS_INLINE void to_lower_case(){aoc_to_lower_case(__self());}
	MCSL_ALWAYS_INLINE void to_upper_case(){aoc_to_upper_case(__self());}
	MCSL_ALWAYS_INLINE void to_title_case(){aoc_to_title_case(__self());}
	MCSL_ALWAYS_INLINE void to_capital_case(){aoc_to_capital_case(__self());}
	MCSL_ALWAYS_INLINE MCSL_WUR bool is_lower_case(){return aoc_is_lower_case(__self());}
	MCSL_ALWAYS_INLINE MCSL_WUR bool is_upper_case(){return aoc_is_upper_case(__self());}
	MCSL_ALWAYS_INLINE MCSL_WUR bool is_title_case(){return aoc_is_title_case(__self());}
	MCSL_ALWAYS_INLINE MCSL_WUR bool is_capital_case(){return aoc_is_capital_case(__self());}
	MCSL_ALWAYS_INLINE MCSL_WUR ssize_t found(char c){return aoc_found_chr(__self(),c);}
	MCSL_ALWAYS_INLINE MCSL_WUR ssize_t found(const cstring s){return aoc_found_cstr(__self(),s);}
	MCSL_ALWAYS_INLINE MCSL_WUR ssize_t found(_aoc* z){return aoc_found_aoc(__self(),z);}
	MCSL_ALWAYS_INLINE MCSL_WUR ssize_t found(const aoc &z){return aoc_found_aoc(__self(),__to_c_aoc(z));}
	MCSL_ALWAYS_INLINE MCSL_WUR size_t search(char c){return aoc_search_chr(__self(),c);}
	MCSL_ALWAYS_INLINE MCSL_WUR size_t search(const cstring s){return aoc_search_cstr(__self(),s);}
	MCSL_ALWAYS_INLINE MCSL_WUR size_t search(_aoc* z){return aoc_search_aoc(__self(),z);}
	MCSL_ALWAYS_INLINE MCSL_WUR size_t search(const aoc &z){return aoc_search_aoc(__self(),__to_c_aoc(z));}

	MCSL_ALWAYS_INLINE void add(char c){aoc_add_chr(__self(),c);}
	MCSL_ALWAYS_INLINE void add(const cstring s){aoc_add_cstr(__self(),s);}
	MCSL_ALWAYS_INLINE void add(const cstring s,size_t l){aoc_add_cstr_l(__self(),s,l);}
	MCSL_ALWAYS_INLINE void add(_aoc *z){aoc_add_aoc(__self(),z);}
	MCSL_ALWAYS_INLINE void add(_aoc *z,size_t l){aoc_add_aoc_l(__self(),z,l);}
	MCSL_ALWAYS_INLINE void add(const aoc &z){aoc_add_aoc(__self(),__to_c_aoc(z));}
	MCSL_ALWAYS_INLINE void add(const aoc &z,size_t l){aoc_add_aoc_l(__self(),__to_c_aoc(z),l);}
	MCSL_ALWAYS_INLINE void add_int(_i64 a){aoc_add_int(__self(),a);}
	MCSL_ALWAYS_INLINE void add_uint(_u64 a){aoc_add_uint(__self(),a);}
	/*MCSL_ALWAYS_INLINE void add_float(_f64 a){aoc_add_float(__self(),a);}*/
	MCSL_ALWAYS_INLINE void add_self(size_t l){aoc_add_self(__self(),l);}
	MCSL_ALWAYS_INLINE void add_self(size_t i1,size_t i2){aoc_add_self2(__self(),i1,i2);}

	MCSL_ALWAYS_INLINE void add_in(size_t i,char c){aoc_add_in_chr(__self(),i,c);}
	MCSL_ALWAYS_INLINE void add_in(size_t i,const cstring s){aoc_add_in_cstr(__self(),i,s);}
	MCSL_ALWAYS_INLINE void add_in(size_t i,const cstring s,size_t l){aoc_add_in_cstr_l(__self(),i,s,l);}
	MCSL_ALWAYS_INLINE void add_in(size_t i,_aoc *z){aoc_add_in_aoc(__self(),i,z);}
	MCSL_ALWAYS_INLINE void add_in(size_t i,_aoc *z,size_t l){aoc_add_in_aoc_l(__self(),i,z,l);}
	MCSL_ALWAYS_INLINE void add_in(size_t i,const aoc &z){aoc_add_in_aoc(__self(),i,__to_c_aoc(z));}
	MCSL_ALWAYS_INLINE void add_in(size_t i,const aoc &z,size_t l){aoc_add_in_aoc_l(__self(),i,__to_c_aoc(z),l);}
	MCSL_ALWAYS_INLINE void add_in_int(size_t i,_i64 a){aoc_add_in_int(__self(),i,a);}
	MCSL_ALWAYS_INLINE void add_in_uint(size_t i,_u64 a){aoc_add_in_uint(__self(),i,a);}
	/*MCSL_ALWAYS_INLINE void add_in_float(size_t i,_f64 a){aoc_add_in_float(__self(),i,a);}*/
	MCSL_ALWAYS_INLINE void add_in_self(size_t i,size_t l){aoc_add_in_self(__self(),i,l);}
	MCSL_ALWAYS_INLINE void add_in_self(size_t i,size_t i1,size_t i2){aoc_add_in_self2(__self(),i,i1,i2);}

	MCSL_ALWAYS_INLINE void set(char c){aoc_set_chr(__self(),c);}
	MCSL_ALWAYS_INLINE void set(const cstring s){aoc_set_cstr(__self(),s);}
	MCSL_ALWAYS_INLINE void set(const cstring s,size_t l){aoc_set_cstr_l(__self(),s,l);}
	MCSL_ALWAYS_INLINE void set(_aoc *z){aoc_set_aoc(__self(),z);}
	MCSL_ALWAYS_INLINE void set(_aoc *z,size_t l){aoc_set_aoc_l(__self(),z,l);}
	MCSL_ALWAYS_INLINE void set(const aoc &z){aoc_set_aoc(__self(),__to_c_aoc(z));}
	MCSL_ALWAYS_INLINE void set(const aoc &z,size_t l){aoc_set_aoc_l(__self(),__to_c_aoc(z),l);}
	MCSL_ALWAYS_INLINE void set_int(_i64 a){aoc_set_int(__self(),a);}
	MCSL_ALWAYS_INLINE void set_uint(_u64 a){aoc_set_uint(__self(),a);}
	/*MCSL_ALWAYS_INLINE void set_float(_f64 a){aoc_set_float(__self(),a);}*/
	MCSL_ALWAYS_INLINE void set_self(size_t l){aoc_set_self(__self(),l);}
	MCSL_ALWAYS_INLINE void set_self(size_t i1,size_t i2){aoc_set_self2(__self(),i1,i2);}	

	MCSL_ALWAYS_INLINE void set_in(size_t i1,size_t i2,char c){aoc_set_in_chr(__self(),i1,i2,c);}
	MCSL_ALWAYS_INLINE void set_in(size_t i1,size_t i2,const cstring s){aoc_set_in_cstr(__self(),i1,i2,s);}
	MCSL_ALWAYS_INLINE void set_in(size_t i1,size_t i2,const cstring s,size_t l){aoc_set_in_cstr_l(__self(),i1,i2,s,l);}
	MCSL_ALWAYS_INLINE void set_in(size_t i1,size_t i2,_aoc *z){aoc_set_in_aoc(__self(),i1,i2,z);}
	MCSL_ALWAYS_INLINE void set_in(size_t i1,size_t i2,_aoc *z,size_t l){aoc_set_in_aoc_l(__self(),i1,i2,z,l);}
	MCSL_ALWAYS_INLINE void set_in(size_t i1,size_t i2,const aoc &z){aoc_set_in_aoc(__self(),i1,i2,__to_c_aoc(z));}
	MCSL_ALWAYS_INLINE void set_in(size_t i1,size_t i2,const aoc &z,size_t l){aoc_set_in_aoc_l(__self(),i1,i2,__to_c_aoc(z),l);}
	MCSL_ALWAYS_INLINE void set_in_int(size_t i1,size_t i2,_i64 a){aoc_set_in_int(__self(),i1,i2,a);}
	MCSL_ALWAYS_INLINE void set_in_uint(size_t i1,size_t i2,_u64 a){aoc_set_in_uint(__self(),i1,i2,a);}
	/*MCSL_ALWAYS_INLINE void set_in_float(size_t i1,size_t i2,_f64 a){aoc_set_in_float(__self(),i1,i2,a);}*/
	MCSL_ALWAYS_INLINE void set_in_self(size_t i1,size_t i2,size_t l){aoc_set_in_self(__self(),i1,i2,l);}
	MCSL_ALWAYS_INLINE void set_in_self(size_t i1,size_t i2,size_t _i1,size_t _i2){aoc_set_in_self2(__self(),i1,i2,_i1,_i2);}

	MCSL_ALWAYS_INLINE MCSL_WUR char get(size_t i){return (i < len()) ? *(__str+i) : '\0';}

	MCSL_ALWAYS_INLINE void del(size_t i){aoc_del_i(__self(),i);}
	MCSL_ALWAYS_INLINE void del(size_t i1,size_t i2){aoc_del_l(__self(),i1,i2);}

	MCSL_ALWAYS_INLINE void del_search(char c){aoc_del_search_chr(__self(),c);}
	MCSL_ALWAYS_INLINE void del_search(const cstring s){aoc_del_search_cstr(__self(),s);}
	MCSL_ALWAYS_INLINE void del_search(const cstring s,size_t l){aoc_del_search_cstr_l(__self(),s,l);}
	MCSL_ALWAYS_INLINE void del_search(_aoc *z){aoc_del_search_aoc(__self(),z);}
	MCSL_ALWAYS_INLINE void del_search(_aoc *z,size_t l){aoc_del_search_aoc_l(__self(),z,l);}
	MCSL_ALWAYS_INLINE void del_search(const aoc &z){aoc_del_search_aoc(__self(),__to_c_aoc(z));}
	MCSL_ALWAYS_INLINE void del_search(const aoc &z,size_t l){aoc_del_search_aoc_l(__self(),__to_c_aoc(z),l);}

	MCSL_ALWAYS_INLINE void set_search(char c, char g){aoc_set_search_chr_chr(__self(),c,g);}
	MCSL_ALWAYS_INLINE void set_search(char c, const cstring g){aoc_set_search_chr_cstr(__self(),c,g);}
	MCSL_ALWAYS_INLINE void set_search(char c, _aoc *g){aoc_set_search_chr_cstr(__self(),c,g->str);}
	MCSL_ALWAYS_INLINE void set_search(char c, const aoc &g){aoc_set_search_chr_cstr(__self(),c,g.str());}
	MCSL_ALWAYS_INLINE void set_search(const cstring c, char g){aoc_set_search_cstr_chr(__self(),c,g);}
	MCSL_ALWAYS_INLINE void set_search(_aoc *c, char g){aoc_set_search_cstr_chr(__self(),c->str,g);}
	MCSL_ALWAYS_INLINE void set_search(const aoc &c, char g){aoc_set_search_cstr_chr(__self(),c.str(),g);}
	MCSL_ALWAYS_INLINE void set_search(const cstring c,const cstring g){aoc_set_search_cstr_cstr(__self(),c,g);}
	MCSL_ALWAYS_INLINE void set_search(const cstring c,_aoc *g){aoc_set_search_cstr_cstr(__self(),c,g->str);}
	MCSL_ALWAYS_INLINE void set_search(const cstring c,const aoc &g){aoc_set_search_cstr_cstr(__self(),c,g.str());}
	MCSL_ALWAYS_INLINE void set_search(_aoc *c,const cstring g){aoc_set_search_cstr_cstr(__self(),c->str,g);}
	MCSL_ALWAYS_INLINE void set_search(_aoc *c,_aoc *g){aoc_set_search_cstr_cstr(__self(),c->str,g->str);}
	MCSL_ALWAYS_INLINE void set_search(_aoc *c,const aoc &g){aoc_set_search_cstr_cstr(__self(),c->str,g.str());}
	MCSL_ALWAYS_INLINE void set_search(const aoc &c,const cstring g){aoc_set_search_cstr_cstr(__self(),c.str(),g);}
	MCSL_ALWAYS_INLINE void set_search(const aoc &c,_aoc *g){aoc_set_search_cstr_cstr(__self(),c.str(),g->str);}
	MCSL_ALWAYS_INLINE void set_search(const aoc &c,const aoc &g){aoc_set_search_cstr_cstr(__self(),c.str(),g.str());}

	MCSL_ALWAYS_INLINE void operator=(char c){set(c);}
	MCSL_ALWAYS_INLINE void operator=(const cstring s){set(s);}
	MCSL_ALWAYS_INLINE void operator=(const _aoc &z){set((_aoc*)&z);}
	MCSL_ALWAYS_INLINE void operator=(const aoc &z){set(z);}
	MCSL_ALWAYS_INLINE void operator=(_i64 a){set_int(a);}
	MCSL_ALWAYS_INLINE void operator=(_u64 a){set_uint(a);}
	/*MCSL_ALWAYS_INLINE void operator=(_f64 a){set_float(a);}*/

	MCSL_ALWAYS_INLINE aoc& operator+(char c){add(c); return *this;}
	MCSL_ALWAYS_INLINE aoc& operator+(const cstring s){add(s); return *this;}
	MCSL_ALWAYS_INLINE aoc& operator+(_aoc &z){add(&z); return *this;}
	MCSL_ALWAYS_INLINE aoc& operator+(const aoc &z){add(z); return *this;}
	MCSL_ALWAYS_INLINE aoc& operator+(_i64 a){add_int(a); return *this;}
	MCSL_ALWAYS_INLINE aoc& operator+(_u64 a){add_uint(a); return *this;}
	/*MCSL_ALWAYS_INLINE aoc& operator+(_f64 a){add_float(a); return *this;}*/

	MCSL_ALWAYS_INLINE aoc& operator<<(char c){add(c); return *this;}
	MCSL_ALWAYS_INLINE aoc& operator<<(const cstring s){add(s); return *this;}
	MCSL_ALWAYS_INLINE aoc& operator<<(_aoc &z){add(&z); return *this;}
	MCSL_ALWAYS_INLINE aoc& operator<<(const aoc &z){add(z); return *this;}
	MCSL_ALWAYS_INLINE aoc& operator<<(_i64 a){add_int(a); return *this;}
	MCSL_ALWAYS_INLINE aoc& operator<<(_u64 a){add_uint(a); return *this;}
	/*MCSL_ALWAYS_INLINE aoc& operator<<(_f64 a){add_float(a); return *this;}*/

	MCSL_ALWAYS_INLINE MCSL_WUR char operator[](ssize_t i){return get( (i >= 0) ? i : len() + i );}

	MCSL_ALWAYS_INLINE void operator--(){del(len()-1);}
	MCSL_ALWAYS_INLINE void operator-=(size_t l){
		if (l >= len()) l = len();
		del(len()-l,len()-1);
	}
};/*aoc*/
}/*mcsl*/
#endif /*MCSL_CPP*/

#ifdef MCSL_CPP
MCSL_EXTERN_C_OPEN
#endif
/*aos*/
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void aos_set_null(_aos *z){z->item = NULL; z->len = 0; z->cap = 0;}
MCSL_API MCSL_ATTR (nonnull(1)) void aos_init(_aos *z);
MCSL_API MCSL_ATTR (nonnull(1)) void aos_free(_aos *z);
MCSL_API MCSL_ATTR (nonnull(1)) void aos_refresh(_aos *z);
MCSL_API MCSL_ATTR (nonnull(1)) void aos_shrink_to_fit(_aos *z);

MCSL_API MCSL_ATTR (nonnull(1)) void aos_add_in_chr(_aos *z,size_t i,char c);
MCSL_API MCSL_ATTR (nonnull(1,3)) void aos_add_in_cstr_l_noc(_aos *z,size_t i,const cstring s,size_t l);
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1,3))
void aos_add_in_cstr_l(_aos *z,size_t i,const cstring s,size_t l){aos_add_in_cstr_l_noc(z,i,s,mcsl_strnlen(s,l));}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1,3))
void aos_add_in_cstr(_aos *z,size_t i,const cstring s){aos_add_in_cstr_l_noc(z,i,s,mcsl_strlen(s));}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1,3))
void aos_add_in_aoc(_aos *z,size_t i,_aoc *s){aos_add_in_cstr_l_noc(z,i,s->str,s->len);}
MCSL_API MCSL_ATTR (nonnull(1,3)) void aos_add_in_cstr_d_chr(_aos *z,size_t i,const cstring s,char d);
MCSL_API MCSL_ATTR (nonnull(1,3,4)) void aos_add_in_cstr_d_cstr(_aos *z,size_t i,const cstring s,const cstring d);
MCSL_API MCSL_ATTR (nonnull(1,3)) void aos_add_in_cstr_p(_aos *z,size_t i,const cstring* s,size_t n);
MCSL_API MCSL_ATTR (nonnull(1,3)) void aos_add_in_aos(_aos *z,size_t i,_aos *x);
MCSL_API MCSL_ATTR (nonnull(1)) void aos_add_in_int(_aos *z,size_t i,_i64 x);
MCSL_API MCSL_ATTR (nonnull(1)) void aos_add_in_uint(_aos *z,size_t i,_u64 x);
/*MCSL_API MCSL_ATTR (nonnull(1)) void aos_add_in_float(_aos *z,size_t i,_f64 x);*/

MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void aos_add_chr(_aos *z,char c){aos_add_in_chr(z,z->len,c);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1,2))
void aos_add_cstr_l_noc(_aos *z,const cstring s,size_t l){aos_add_in_cstr_l_noc(z,z->len,s,l);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1,2))
void aos_add_cstr_l(_aos *z,const cstring s,size_t l){aos_add_in_cstr_l(z,z->len,s,l);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1,2))
void aos_add_cstr(_aos *z,const cstring s){aos_add_in_cstr(z,z->len,s);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1,2))
void aos_add_aoc(_aos *z,_aoc *s){aos_add_in_aoc(z,z->len,s);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1,2))
void aos_add_cstr_d_chr(_aos *z,const cstring s,char d){aos_add_in_cstr_d_chr(z,z->len,s,d);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1,2,3))
void aos_add_cstr_d_cstr(_aos *z,const cstring s,const cstring d){aos_add_in_cstr_d_cstr(z,z->len,s,d);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1,2))
void aos_add_cstr_p(_aos *z,const cstring* s,size_t n){aos_add_in_cstr_p(z,z->len,s,n);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1,2))
void aos_add_aos(_aos *z,_aos *x){aos_add_in_aos(z,z->len,x);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void aos_add_int(_aos *z,_i64 x){aos_add_in_int(z,z->len,x);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void aos_add_uint(_aos *z,_u64 x){aos_add_in_uint(z,z->len,x);}
/*MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void aos_add_float(_aos *z,_f64 x){aos_add_in_float(z,z->len,x);}*/

MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
_aoc* aos_get(_aos *z,size_t i){return &*(z->item+i);}

MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void aos_set_chr(_aos *z,size_t i,char c){if (i < z->len) aoc_set_chr(aos_get(z,i),c);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void aos_set_cstr_l_noc(_aos *z,size_t i,const cstring s,size_t l){if (i < z->len) aoc_set_cstr_l_noc(aos_get(z,i),s,l);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void aos_set_cstr_l(_aos *z,size_t i,const cstring s,size_t l){if (i < z->len) aoc_set_cstr_l(aos_get(z,i),s,l);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void aos_set_cstr(_aos *z,size_t i,const cstring s){if (i < z->len) aoc_set_cstr(aos_get(z,i),s);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void aos_set_aoc(_aos *z,size_t i,_aoc *s){if (i < z->len) aoc_set_aoc(aos_get(z,i),s);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void aos_set_int(_aos *z,size_t i,_i64 a){if (i < z->len) aoc_set_int(aos_get(z,i),a);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void aos_set_uint(_aos *z,size_t i,_u64 a){if (i < z->len) aoc_set_uint(aos_get(z,i),a);}
/*MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void aos_set_float(_aos *z,size_t i,_f64 a){if (i < z->len) aoc_set_float(aos_get(z,i),a);}*/
MCSL_API MCSL_ATTR (nonnull(1)) void aos_set_cstr_p(_aos *z,const cstring* s,size_t n);
MCSL_API MCSL_ATTR (nonnull(1)) void aos_set_aos(_aos *z,_aos *x);

MCSL_API MCSL_ATTR (nonnull(1)) void aos_del_i(_aos *z,size_t i);
MCSL_API MCSL_ATTR (nonnull(1)) void aos_del_l(_aos *z,size_t i1,size_t i2);
MCSL_API MCSL_ATTR (nonnull(1)) void aos_del_dup(_aos *z);
MCSL_API MCSL_ATTR (nonnull(1)) void aos_del_search(_aos *z,const cstring s);

MCSL_API MCSL_ATTR (nonnull(1)) MCSL_WUR ssize_t aos_found(_aos *z,const cstring s);
MCSL_API MCSL_ATTR (nonnull(1)) MCSL_WUR size_t aos_search(_aos *z,const cstring s);

MCSL_API MCSL_ATTR (nonnull(1)) void aos_to_lower_case(_aos *z);
MCSL_API MCSL_ATTR (nonnull(1)) void aos_to_upper_case(_aos *z);
MCSL_API MCSL_ATTR (nonnull(1)) void aos_to_title_case(_aos *z);
MCSL_API MCSL_ATTR (nonnull(1)) void aos_to_capital_case(_aos *z);

MCSL_API MCSL_ATTR (nonnull(1)) bool aos_is_lower_case(_aos *z);
MCSL_API MCSL_ATTR (nonnull(1)) bool aos_is_upper_case(_aos *z);
MCSL_API MCSL_ATTR (nonnull(1)) bool aos_is_title_case(_aos *z);
MCSL_API MCSL_ATTR (nonnull(1)) bool aos_is_capital_case(_aos *z);

MCSL_API MCSL_ATTR (nonnull(1)) MCSL_WUR cstring aos_to_str(_aos *z);
MCSL_API MCSL_ATTR (nonnull(1)) MCSL_WUR cstring aos_to_str_d_chr(_aos *z,char d);
MCSL_API MCSL_ATTR (nonnull(1)) MCSL_WUR cstring aos_to_str_d_cstr(_aos *z,const cstring s);

#ifdef MCSL_CPP
MCSL_EXTERN_C_CLOSE
#endif

#ifdef MCSL_CPP
namespace mcsl{
class aos{
private:
	__typeof__ (_aos :: item) __item;
	__typeof__ (_aos :: len) __len;
	__typeof__ (_aos :: cap) __cap;
	MCSL_ALWAYS_INLINE _aos* __self(){return (_aos*)this;}
	MCSL_ALWAYS_INLINE _aos* __to_c_aos(const aos &z){return (_aos*)&z;}
	MCSL_ALWAYS_INLINE _aos* __to_c_aos(const aos *z){return (_aos*)z;}
	MCSL_ALWAYS_INLINE void __init_self(){aos_init(__self());}
public:
	aos(){__init_self();}
	aos(_aos *z){__init_self(); set(z);}
	aos(_aos &z){__init_self(); set(z);}
	aos(const aos &z){__init_self(); set(z);}
	~aos(){aos_free(__self());}
	MCSL_ALWAYS_INLINE MCSL_WUR MCSL_ATTR (const) __typeof__(__len) len() const {return __len;}
	MCSL_ALWAYS_INLINE MCSL_WUR MCSL_ATTR (const) __typeof__(__cap) cap() const {return __cap;}
	MCSL_ALWAYS_INLINE MCSL_WUR MCSL_ATTR (const) __typeof__ (__item) item(){return __item;}
	MCSL_ALWAYS_INLINE void free(){aos_free(__self()); __init_self();}
	MCSL_ALWAYS_INLINE void refresh();
	MCSL_ALWAYS_INLINE void shrink_to_fit();
	MCSL_ALWAYS_INLINE MCSL_WUR ssize_t found(const cstring s){return aos_found(__self(),s);}
	MCSL_ALWAYS_INLINE MCSL_WUR ssize_t found(_aoc *s){return aos_found(__self(),(const cstring)s->str);}
	MCSL_ALWAYS_INLINE MCSL_WUR ssize_t found(_aoc &s){return aos_found(__self(),(const cstring)s.str);}
	MCSL_ALWAYS_INLINE MCSL_WUR ssize_t found(aoc &s){return aos_found(__self(),s.str());}
	MCSL_ALWAYS_INLINE MCSL_WUR size_t search(const cstring s){return aos_search(__self(),s);}
	MCSL_ALWAYS_INLINE MCSL_WUR size_t search(_aoc *s){return aos_search(__self(),(const cstring)s->str);}
	MCSL_ALWAYS_INLINE MCSL_WUR size_t search(_aoc &s){return aos_search(__self(),(const cstring)s.str);}
	MCSL_ALWAYS_INLINE MCSL_WUR size_t search(aoc &s){return aos_search(__self(),s.str());}
	MCSL_ALWAYS_INLINE void to_lower_case(){aos_to_lower_case(__self());}
	MCSL_ALWAYS_INLINE void to_upper_case(){aos_to_upper_case(__self());}
	MCSL_ALWAYS_INLINE void to_title_case(){aos_to_title_case(__self());}
	MCSL_ALWAYS_INLINE void to_capital_case(){aos_to_capital_case(__self());}
	MCSL_ALWAYS_INLINE MCSL_WUR bool is_lower_case(){return aos_is_lower_case(__self());}
	MCSL_ALWAYS_INLINE MCSL_WUR bool is_upper_case(){return aos_is_upper_case(__self());}
	MCSL_ALWAYS_INLINE MCSL_WUR bool is_title_case(){return aos_is_title_case(__self());}
	MCSL_ALWAYS_INLINE MCSL_WUR bool is_capital_case(){return aos_is_capital_case(__self());}
	MCSL_ALWAYS_INLINE void del(size_t i){aos_del_i(__self(),i);}
	MCSL_ALWAYS_INLINE void del(size_t i1,size_t i2){aos_del_l(__self(),i1,i2);}
	MCSL_ALWAYS_INLINE void del_dup(){aos_del_dup(__self());}
	MCSL_ALWAYS_INLINE void del_search(const cstring s){aos_del_search(__self(),s);}
	MCSL_ALWAYS_INLINE MCSL_WUR cstring to_str(){return aos_to_str(__self());}
	MCSL_ALWAYS_INLINE MCSL_WUR cstring to_str(char d){return aos_to_str_d_chr(__self(),d);}
	MCSL_ALWAYS_INLINE MCSL_WUR cstring to_str(const cstring d){return aos_to_str_d_cstr(__self(),d);}
	MCSL_ALWAYS_INLINE MCSL_WUR cstring to_str(_aoc *d){return aos_to_str_d_cstr(__self(),(const cstring)d->str);}
	MCSL_ALWAYS_INLINE MCSL_WUR cstring to_str(_aoc &d){return aos_to_str_d_cstr(__self(),(const cstring)d.str);}
	MCSL_ALWAYS_INLINE MCSL_WUR cstring to_str(aoc &d){return aos_to_str_d_cstr(__self(),d.str());}
	MCSL_ALWAYS_INLINE MCSL_WUR aoc& get(size_t i){return *(aoc*)&__item[i];}
	MCSL_ALWAYS_INLINE void add(char d){aos_add_chr(__self(),d);}
	MCSL_ALWAYS_INLINE void add(const cstring s){aos_add_cstr(__self(),s);}
	MCSL_ALWAYS_INLINE void add(const cstring s,size_t l){aos_add_cstr_l(__self(),s,l);}
	MCSL_ALWAYS_INLINE void add(_aoc *s){aos_add_aoc(__self(),s);}
	MCSL_ALWAYS_INLINE void add(_aoc &s){aos_add_aoc(__self(),&s);}
	MCSL_ALWAYS_INLINE void add(aoc &s){aos_add_aoc(__self(),(_aoc*)&s);}
	MCSL_ALWAYS_INLINE void add(const cstring* s,size_t n){aos_add_cstr_p(__self(),s,n);}
	MCSL_ALWAYS_INLINE void add(_aos *s){aos_add_aos(__self(),s);}
	MCSL_ALWAYS_INLINE void add(_aos &s){aos_add_aos(__self(),&s);}
	MCSL_ALWAYS_INLINE void add(const aos &s){aos_add_aos(__self(),__to_c_aos(s));}
	MCSL_ALWAYS_INLINE void add_int(_i64 a){aos_add_int(__self(),a);}
	MCSL_ALWAYS_INLINE void add_uint(_u64 a){aos_add_uint(__self(),a);}
	/*MCSL_ALWAYS_INLINE void add_float(_f64 a){aos_add_float(__self(),a);}*/
	MCSL_ALWAYS_INLINE void add_in(size_t i,char d){aos_add_in_chr(__self(),i,d);}
	MCSL_ALWAYS_INLINE void add_in(size_t i,const cstring s){aos_add_in_cstr(__self(),i,s);}
	MCSL_ALWAYS_INLINE void add_in(size_t i,const cstring s,size_t l){aos_add_in_cstr_l(__self(),i,s,l);}
	MCSL_ALWAYS_INLINE void add_in(size_t i,_aoc *s){aos_add_in_aoc(__self(),i,s);}
	MCSL_ALWAYS_INLINE void add_in(size_t i,_aoc &s){aos_add_in_aoc(__self(),i,&s);}
	MCSL_ALWAYS_INLINE void add_in(size_t i,aoc &s){aos_add_in_aoc(__self(),i,(_aoc*)&s);}
	MCSL_ALWAYS_INLINE void add_in(size_t i,const cstring* s,size_t n){aos_add_in_cstr_p(__self(),i,s,n);}
	MCSL_ALWAYS_INLINE void add_in(size_t i,_aos *s){aos_add_in_aos(__self(),i,s);}
	MCSL_ALWAYS_INLINE void add_in(size_t i,_aos &s){aos_add_in_aos(__self(),i,&s);}
	MCSL_ALWAYS_INLINE void add_in(size_t i,const aos &s){aos_add_in_aos(__self(),i,__to_c_aos(s));}
	MCSL_ALWAYS_INLINE void add_in_int(size_t i,_i64 a){aos_add_in_int(__self(),i,a);}
	MCSL_ALWAYS_INLINE void add_in_uint(size_t i,_u64 a){aos_add_in_uint(__self(),i,a);}
	/*MCSL_ALWAYS_INLINE void add_in_float(size_t i,_f64 a){aos_add_in_float(__self(),i,a);}*/
	MCSL_ALWAYS_INLINE void set(size_t i,char d){aos_set_chr(__self(),i,d);}
	MCSL_ALWAYS_INLINE void set(size_t i,const cstring s){aos_set_cstr(__self(),i,s);}
	MCSL_ALWAYS_INLINE void set(size_t i,const cstring s,size_t l){aos_set_cstr_l(__self(),i,s,l);}
	MCSL_ALWAYS_INLINE void set(size_t i,_aoc *s){aos_set_aoc(__self(),i,s);}
	MCSL_ALWAYS_INLINE void set(size_t i,_aoc &s){aos_set_aoc(__self(),i,&s);}
	MCSL_ALWAYS_INLINE void set(size_t i,aoc &s){aos_set_aoc(__self(),i,(_aoc*)&s);}
	MCSL_ALWAYS_INLINE void set_int(size_t i,_i64 a){aos_set_int(__self(),i,a);}
	MCSL_ALWAYS_INLINE void set_uint(size_t i,_u64 a){aos_set_uint(__self(),i,a);}
	/*MCSL_ALWAYS_INLINE void set_float(size_t i,_f64 a){aos_set_float(__self(),i,a);}*/
	MCSL_ALWAYS_INLINE void set(_aos *z){aos_set_aos(__self(),z);}
	MCSL_ALWAYS_INLINE void set(_aos &z){aos_set_aos(__self(),&z);}
	MCSL_ALWAYS_INLINE void set(const aos &z){aos_set_aos(__self(),__to_c_aos(z));}
	MCSL_ALWAYS_INLINE void set(const cstring* s,size_t n){aos_set_cstr_p(__self(),s,n);}

	MCSL_ALWAYS_INLINE aos& operator<<(char d){add(d); return *this;}
	MCSL_ALWAYS_INLINE aos& operator<<(const cstring s){add(s); return *this;}
	MCSL_ALWAYS_INLINE aos& operator<<(_aoc &s){add(s); return *this;}
	MCSL_ALWAYS_INLINE aos& operator<<(aoc &s){add(s); return *this;}
	MCSL_ALWAYS_INLINE aos& operator<<(_aos &s){add(s); return *this;}
	MCSL_ALWAYS_INLINE aos& operator<<(const aos &s){add(s); return *this;}
	MCSL_ALWAYS_INLINE aos& operator<<(_i64 a){add_int(a); return *this;}
	MCSL_ALWAYS_INLINE aos& operator<<(_u64 a){add_uint(a); return *this;}
	/*MCSL_ALWAYS_INLINE aos& operator<<(_f64 a){add_float(a); return *this;}*/

	MCSL_ALWAYS_INLINE MCSL_WUR aoc& operator[](ssize_t i){return get( (i >= 0) ? i : len() + i );}

	MCSL_ALWAYS_INLINE void operator=(_aos &z){set(z);}
	MCSL_ALWAYS_INLINE void operator=(const aos &z){set(z);}

	MCSL_ALWAYS_INLINE void operator--(){del(len()-1);}
	MCSL_ALWAYS_INLINE void operator-=(size_t l){
		if (l >= len()) l = len();
		del(len()-l,len()-1);
	}
};/*aos*/

#include <type_traits>
/*list*/
template<typename T>
class aoit{
private:
	T* __item = NULL;
	size_t __len = 0;
	size_t __cap = 0;
	const size_t __max_len = SIZE_MAX / sizeof(T);
	bool __is_item_class = std::is_class<T>::value;
	bool __is_item_pointer = std::is_pointer<T>::value;
	MCSL_ALWAYS_INLINE void item_alloc_if_lc(){
		if (__len >= __cap){
			__is_item_class = std::is_class<T>::value;
			__is_item_pointer = std::is_pointer<T>::value;
			if (__cap == 0) __cap = 2;
			__cap <<= 1;
			__item = (T*)mcsl_realloc(__item, __cap * sizeof(T));
			if (__is_item_class || __is_item_pointer) mcsl_memset(&__item[__len],0,(__cap-__len)*sizeof(T));
		}
	}
	MCSL_ALWAYS_INLINE void item_alloc_if_lc_n(size_t n){
		if ((__len+n) > __cap){
			__is_item_class = std::is_class<T>::value;
			__is_item_pointer = std::is_pointer<T>::value;
			if (__cap == 0) __cap = 2;
			do __cap <<= 1; while (__len+n > __cap);
			__item = (T*)mcsl_realloc(__item, __cap * sizeof(T));
			if (__is_item_class || __is_item_pointer) mcsl_memset(&__item[__len],0,(__cap-__len)*sizeof(T));
		}
	}
	MCSL_LOCAL void free();
public:
	aoit() = default;
	aoit(const aoit<T> &a){this->set(a);}
	~aoit(){this->free();}
	MCSL_PUBLIC MCSL_ATTR (nothrow) void __add_args(_u32 n,...);

	MCSL_PUBLIC void clear();
	MCSL_ALWAYS_INLINE MCSL_ATTR (const) size_t len(){return __len;}
	MCSL_ALWAYS_INLINE MCSL_ATTR (const) size_t cap(){return __cap;}
	MCSL_ALWAYS_INLINE const T* item(){return (const T*)__item;}
	MCSL_ALWAYS_INLINE MCSL_ATTR (const) const size_t max_len(){return __max_len;}
	MCSL_PUBLIC MCSL_ATTR (nothrow) void add(const T& a);
	MCSL_ALWAYS_INLINE void push_back(const T& a){add(a);}
	MCSL_PUBLIC MCSL_ATTR (nothrow) void add_in(size_t i,const T& a);
	MCSL_ALWAYS_INLINE void insert(size_t i,const T& a){add_in(i,a);}
	MCSL_ALWAYS_INLINE void push_front(const T& a){add_in(0,a);}
	MCSL_PUBLIC MCSL_ATTR (nothrow) void add_null();

	template <typename ... _T>
	MCSL_ALWAYS_INLINE void add(const _T& ... args){__add_args(sizeof...(args),(&args) ...);}
	MCSL_PUBLIC MCSL_ATTR (nothrow) void del(size_t i);
	MCSL_ALWAYS_INLINE void pop_back(){del(__len-1);}
	MCSL_ALWAYS_INLINE void pop_front(){del(0);}
	MCSL_PUBLIC MCSL_ATTR (nothrow) void del_l(size_t i1,size_t i2);
	MCSL_ALWAYS_INLINE void set(size_t i,const T& a){if (i < __len) *(__item+i) = a;}
	MCSL_PUBLIC MCSL_ATTR (nothrow) void set(const aoit<T> &a);
	MCSL_ALWAYS_INLINE bool is_empty(){return __len == 0;}
	MCSL_ALWAYS_INLINE T& get(size_t i){return *(__item+i);}
	MCSL_ALWAYS_INLINE void operator=(const aoit<T> &a){set(a);}
	MCSL_ALWAYS_INLINE T& operator[](ssize_t i){return this->get( (i >= 0) ? i : this->__len + i);}
	MCSL_ALWAYS_INLINE aoit<T>& operator<<(const T &x){this->add(x);return *this;}
	MCSL_ALWAYS_INLINE void reverse(){
		size_t i; size_t e;
		if (__is_item_class){
			for (e = __len-1,i = 0; i < __len/2; i++,e--){
				T* t1 = &*(__item+i); T* t2 = &*(__item+e);
				MCSL_SWAP_PTR(t1,t2,T*);
			}
		}
		else if (__is_item_pointer)
			for (e = __len-1,i = 0; i < __len/2; i++,e--)
				MCSL_SWAP_PTR(*(__item+i),*(__item+e),T);
		else
			for (e = __len-1,i = 0; i < __len/2; i++,e--)
				MCSL_SWAP_NUM(*(__item+i),*(__item+e));
	}
	MCSL_ALWAYS_INLINE T* begin(){return (__len > 0) ? (T*)nullptr : (T*)&*__item;}
	MCSL_ALWAYS_INLINE T* end(){return (__len > 0) ? (T*)nullptr : (T*)&__item[__len-1];}
};

template<typename T>
void aoit<T>::free(){
	if (__is_item_class){
		size_t i = 0;
		while (i < __len){
			(*(__item+i)).~T();
			i++;
		}
	}
	if (__item != NULL) mcsl_free(__item);
	__item = NULL; __len = 0; __cap = 0;
}
template<typename T>
void aoit<T>::clear(){
	if (__is_item_class){
		size_t i = 0;
		while (i < __len){
			(*(__item+i)).~T();
			i++;
		}
	}
	if (__item != NULL) mcsl_free(__item);
	__item = NULL;
	__len = 0; __cap = 2;
	__item = (T*)mcsl_calloc(__cap,sizeof(T));
}
template<typename T>
void aoit<T>::add(const T& a){
	item_alloc_if_lc();
	__item[__len] = a;
	__len++;
}
template<typename T>
void aoit<T>::add_null(){
	item_alloc_if_lc();
	mcsl_memset(__item+__len,0,sizeof(T));
	__len++;
}
template<typename T>
void aoit<T>::add_in(size_t i,const T& a){
	if (i >= __len) return;
	item_alloc_if_lc();
	mcsl_memmove(__item+i+1,__item+i,(__len-i) * sizeof(T));
	if (__is_item_class) mcsl_memset(__item+i,0,sizeof(T));
	(*(__item+i)) = a;
	__len++;
}
template<typename T>
void aoit<T>::__add_args(_u32 n, ...){
	__builtin_va_list v_lst;
	if (n == 0) return;
	item_alloc_if_lc_n(n);
	__builtin_va_start(v_lst,n);
	do{
		*(__item+__len) = *((T*)__builtin_va_arg(v_lst,T*));
		__len++;
	}while (--n);
	__builtin_va_end(v_lst);
}
template<typename T>
void aoit<T>::del(size_t i){
	if (i >= __len) return;
	if (__is_item_class)
		(*(__item+i)).~T();
	--__len;
	mcsl_memmove(__item+i,__item+i+1,(__len-i) * sizeof(T));
	if (__is_item_class) mcsl_memset(__item+__len,0,sizeof(T));
}
template<typename T>
void aoit<T>::del_l(size_t i1,size_t i2){
	size_t i;
	i2 = (i2 >= __len) ? __len-1 : i2;
	if ((i1 >= __len) || (i1 > i2)) return;
	if (__is_item_class){
		for (i = i1; i <= i2; i++){
			(*(__item+i)).~T();
			mcsl_memset(&*(__item+i),0,sizeof(T));
		}

	}
	i = i1; i1 = (__len -= (i2 = i2-i1+1)) - i1;
	if (i1 > 0)
		mcsl_memmove(&*(__item+i),&*(__item+i+i2), i1 * sizeof(T));
}
template<typename T>
void aoit<T>::set(const aoit<T> &a){
	if (__cap != 0)
		this->free();
	__cap = a.__cap;
	__len = a.__len;
	__is_item_class = a.__is_item_class;
	__is_item_pointer = a.__is_item_pointer;
	__item = (T*)mcsl_calloc(__cap,sizeof(T));
	if (__is_item_class){
		size_t i = 0;
		while (i < __len){
			*(__item+i) = *(a.__item+i);
			i++;
		}
	}
	else
		mcsl_memcpy(__item,a.__item,sizeof(T) * __len);
}

}/*mcsl*/
#endif/*MCSL_CPP*/

#endif /*MCSL_STRING_H*/
