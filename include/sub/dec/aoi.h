#ifndef MCSL_NUM_H
#error "Never include sub/dec/aoi.h directly"
#endif

#if !defined(AOI_DEC_BEGIN) && !defined(AOI_DEC_END)
#define AOI_DEC_BEGIN

#define _AOI_CONCAT(a,b) a ## b
#define _AOI_CONCAT2(a,b,c) a ## b ## c
#define _AOI_CONCAT_X(a,b) _AOI_CONCAT(a,b)
#define _AOI_CONCAT_X2(a,b,c) _AOI_CONCAT2(a,b,c)
#define _AOI_NVAR(s,bvar) _AOI_CONCAT(s,bvar)
#define _AOI_NVAR_P(s,bvar) _AOI_CONCAT2(s,bvar,*)
#define _AOI_NVAR_PF(s,bvar) _AOI_CONCAT2(s,bvar,_p)
#define _AOI_AOVAR(s,bvar) _AOI_CONCAT(s,bvar)
#define AOI_NVAR _AOI_NVAR(_i,AOI_BVAR)
#define AOI_NVAR_P _AOI_NVAR_P(_i,AOI_BVAR)
#define AOI_NVAR_PF _AOI_NVAR_PF(_i,AOI_BVAR)
#define AOI_AOVAR _AOI_AOVAR(_aoi,AOI_BVAR)
#define AOI_NVAR2 _AOI_NVAR(i,AOI_BVAR)
#define AOI_NVAR2_P _AOI_NVAR_PF(i,AOI_BVAR)
#define AOI_AOVAR2 _AOI_AOVAR(aoi,AOI_BVAR)
#define AOI_FUNC(T,NAME) _AOI_CONCAT_X(T,NAME)
#define AOI_FUNC2(T,NAME) _AOI_CONCAT_X2(__,T,NAME)
#define AOI_FUNC3(T1,NAME,T2) _AOI_CONCAT_X2(T1,NAME,T2)
#define AOI_SIZE_VAR sizeof(AOI_NVAR)
#define AOI_ITEM_MALLOC(n) (AOI_NVAR*)mcsl_malloc((n)*AOI_SIZE_VAR)
#define AOI_ITEM_CALLOC(n) (AOI_NVAR*)mcsl_calloc((n),AOI_SIZE_VAR)
#define AOI_ITEM_REALLOC(item,n) (AOI_NVAR*)mcsl_realloc(item,(n)*AOI_SIZE_VAR)
#define AOI_SIZE_N(n) ((n)*AOI_SIZE_VAR)
#endif/*AOI_DEC_BEGIN*/

#if defined(AOI_DEC_BEGIN) && !defined(AOI_DEC_END)

#ifndef AOI_BVAR
#error "AOI_BVAR not exists"
#endif

#if (AOI_BVAR != 32) && (AOI_BVAR != 64)
#error "AOI_BVAR valid only on 32 and 64"
#endif

#ifdef MCSL_CPP
MCSL_EXTERN_C_OPEN
#endif

MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1,2))
void AOI_FUNC(AOI_NVAR2_P,_del_i)(AOI_NVAR* z,size_t *l,size_t i){
	if ((i >= *l) || (--*l == i)) return;
	mcsl_memmove(z + i, z + i + 1, AOI_SIZE_N(*l-i));
}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1,2))
void AOI_FUNC(AOI_NVAR2_P,_del_l)(AOI_NVAR* z,size_t *l,size_t i1,size_t i2){
	i2 = (i2 >= *l) ? *l-1 : i2;
	if ((i1 >= *l) || (i1 > i2)) return;
	*l -= i2-i1+1;
	mcsl_memmove(z + i1, z + i2+1, AOI_SIZE_N(*l-i1));
}

MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void AOI_FUNC(AOI_AOVAR2,_set_null)(AOI_AOVAR *z){
	z->item = NULL; z->cap = 0; z->len = 0;
}

MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void AOI_FUNC(AOI_AOVAR2,_init)(AOI_AOVAR *z){
	z->len = 0; z->cap = 1;
	z->item = AOI_ITEM_MALLOC(z->cap);
}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void AOI_FUNC(AOI_AOVAR2,_free)(AOI_AOVAR *z){
	if (z->item != NULL && z->cap != 0)
		mcsl_free(z->item);
	AOI_FUNC(AOI_AOVAR2,_set_null)(z);
}

MCSL_API MCSL_ATTR (nonnull(1)) void AOI_FUNC(AOI_AOVAR2,_init_n)(AOI_AOVAR *z,ssize_t n);
MCSL_API MCSL_ATTR (nonnull(1)) void AOI_FUNC(AOI_AOVAR2,_refresh)(AOI_AOVAR *z);
MCSL_API MCSL_ATTR (nonnull(1)) void AOI_FUNC(AOI_AOVAR2,_shrink_to_fit)(AOI_AOVAR *z);

MCSL_API MCSL_ATTR (nonnull(1)) void AOI_FUNC(AOI_AOVAR2,_add_in)(AOI_AOVAR *z,size_t i,AOI_NVAR x);
MCSL_API MCSL_ATTR (nonnull(1,3)) void AOI_FUNC(AOI_AOVAR2,_add_in_aoi)(AOI_AOVAR *z,size_t i,AOI_AOVAR *x);

MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void AOI_FUNC(AOI_AOVAR2,_add)(AOI_AOVAR *z, AOI_NVAR x){AOI_FUNC(AOI_AOVAR2,_add_in)(z,z->len,x);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void AOI_FUNC(AOI_AOVAR2,_add_aoi)(AOI_AOVAR *z, AOI_AOVAR *x){AOI_FUNC(AOI_AOVAR2,_add_in_aoi)(z,z->len,x);}

MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void AOI_FUNC(AOI_AOVAR2,_set)(AOI_AOVAR *z, size_t i, AOI_NVAR x){if (i < z->len) *(z->item+i) = x;}
MCSL_API MCSL_ATTR (nonnull(1,2)) void AOI_FUNC(AOI_AOVAR2,_set_aoi)(AOI_AOVAR *z, AOI_AOVAR *x);

MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
AOI_NVAR AOI_FUNC(AOI_AOVAR2,_get)(AOI_AOVAR *z, size_t i){return *(z->item+i);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
size_t AOI_FUNC(AOI_AOVAR2,_get_len)(AOI_AOVAR *z){return z->len;}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
size_t AOI_FUNC(AOI_AOVAR2,_get_cap)(AOI_AOVAR *z){return z->cap;}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
AOI_NVAR* AOI_FUNC(AOI_AOVAR2,_get_item)(AOI_AOVAR *z){return z->item;}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void AOI_FUNC(AOI_AOVAR2,_del_i)(AOI_AOVAR *z, size_t i){AOI_FUNC(AOI_NVAR2_P,_del_i)(z->item,&z->len,i);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void AOI_FUNC(AOI_AOVAR2,_del_l)(AOI_AOVAR *z, size_t i1,size_t i2){AOI_FUNC(AOI_NVAR2_P,_del_l)(z->item,&z->len,i1,i2);}
MCSL_API MCSL_ATTR (nonnull(1)) void AOI_FUNC(AOI_AOVAR2,_del_search)(AOI_AOVAR *z,AOI_NVAR x);
MCSL_API MCSL_ATTR (nonnull(1)) void AOI_FUNC(AOI_AOVAR2,_del_dup)(AOI_AOVAR *z);

MCSL_API MCSL_ATTR (nonnull(1)) ssize_t AOI_FUNC(AOI_NVAR2_P,_found)(AOI_NVAR* x,size_t n,AOI_NVAR c);
MCSL_API MCSL_ATTR (nonnull(1)) size_t AOI_FUNC(AOI_NVAR2_P,_search)(AOI_NVAR* x,size_t n,AOI_NVAR c);

MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
ssize_t AOI_FUNC(AOI_AOVAR2,_found)(AOI_AOVAR *z,AOI_NVAR c){return AOI_FUNC(AOI_NVAR2_P,_found)(z->item,z->len,c);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
size_t AOI_FUNC(AOI_AOVAR2,_search)(AOI_AOVAR *z,AOI_NVAR c){return AOI_FUNC(AOI_NVAR2_P,_search)(z->item,z->len,c);}

MCSL_API MCSL_ATTR (nonnull(1)) cstring AOI_FUNC(AOI_AOVAR2,_to_str)(AOI_AOVAR *z);
MCSL_API MCSL_ATTR (nonnull(1)) cstring AOI_FUNC(AOI_AOVAR2,_to_str_d_chr)(AOI_AOVAR *z,char d);
MCSL_API MCSL_ATTR (nonnull(1,2)) cstring AOI_FUNC(AOI_AOVAR2,_to_str_d_cstr)(AOI_AOVAR *z,const cstring d);
MCSL_API MCSL_ATTR (nonnull(1,2)) void AOI_FUNC(AOI_AOVAR2,_to_aoc)(AOI_AOVAR *z,_aoc *x);
MCSL_API MCSL_ATTR (nonnull(1,2)) void AOI_FUNC(AOI_AOVAR2,_to_aoc_d_chr)(AOI_AOVAR *z,_aoc *x,char d);
MCSL_API MCSL_ATTR (nonnull(1,2,3)) void AOI_FUNC(AOI_AOVAR2,_to_aoc_d_cstr)(AOI_AOVAR *z,_aoc *x,const cstring d);
MCSL_API MCSL_ATTR (nonnull(1)) void AOI_FUNC(AOI_AOVAR2,_reverse)(AOI_AOVAR *z);

MCSL_API MCSL_ATTR (nonnull(1)) _i64 AOI_FUNC(AOI_NVAR2_P,_sum)(AOI_NVAR* x,size_t n);

MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
_i64 AOI_FUNC(AOI_AOVAR2,_sum)(AOI_AOVAR *z){return AOI_FUNC(AOI_NVAR2_P,_sum)(z->item,z->len);}

MCSL_API MCSL_ATTR (nonnull(1)) void AOI_FUNC(AOI_NVAR2_P,_sort_min)(AOI_NVAR* x,size_t n);
MCSL_API MCSL_ATTR (nonnull(1)) void AOI_FUNC(AOI_NVAR2_P,_sort_min_f)(AOI_NVAR* x,size_t n, _i32 (*compar)(const void*,const void*));
MCSL_API MCSL_ATTR (nonnull(1)) void AOI_FUNC(AOI_NVAR2_P,_sort_max)(AOI_NVAR* x,size_t n);
MCSL_API MCSL_ATTR (nonnull(1)) void AOI_FUNC(AOI_NVAR2_P,_sort_max_f)(AOI_NVAR* x,size_t n, _i32 (*compar)(const void*,const void*));

MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void AOI_FUNC(AOI_AOVAR2,_sort_min)(AOI_AOVAR *z){AOI_FUNC(AOI_NVAR2_P,_sort_min)(z->item,z->len);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void AOI_FUNC(AOI_AOVAR2,_sort_min_f)(AOI_AOVAR *z, _i32 (*compar)(const void*,const void*)){AOI_FUNC(AOI_NVAR2_P,_sort_min_f)(z->item,z->len,compar);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void AOI_FUNC(AOI_AOVAR2,_sort_max)(AOI_AOVAR *z){AOI_FUNC(AOI_NVAR2_P,_sort_max)(z->item,z->len);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void AOI_FUNC(AOI_AOVAR2,_sort_max_f)(AOI_AOVAR *z, _i32 (*compar)(const void*,const void*)){AOI_FUNC(AOI_NVAR2_P,_sort_max_f)(z->item,z->len,compar);}

MCSL_API MCSL_ATTR (nonnull(1)) bool AOI_FUNC(AOI_NVAR2_P,_is_sort_min)(AOI_NVAR* x,size_t n);
MCSL_API MCSL_ATTR (nonnull(1)) bool AOI_FUNC(AOI_NVAR2_P,_is_sort_max)(AOI_NVAR* x,size_t n);
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
bool AOI_FUNC(AOI_AOVAR2,_is_sort_min)(AOI_AOVAR *z){return AOI_FUNC(AOI_NVAR2_P,_is_sort_min)(z->item,z->len);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
bool AOI_FUNC(AOI_AOVAR2,_is_sort_max)(AOI_AOVAR *z){return AOI_FUNC(AOI_NVAR2_P,_is_sort_max)(z->item,z->len);}

MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
_f64 AOI_FUNC(AOI_NVAR2_P,_mean)(AOI_NVAR* x,size_t n){return ((_f64)AOI_FUNC(AOI_NVAR2_P,_sum)(x,n)) / n;}
MCSL_API MCSL_ATTR (nonnull(1)) _f64 AOI_FUNC(AOI_NVAR2_P,_median)(AOI_NVAR* x,size_t n);
MCSL_API MCSL_ATTR (nonnull(1)) AOI_NVAR AOI_FUNC(AOI_NVAR2_P,_mode)(AOI_NVAR* x,size_t n);

MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
_f64 AOI_FUNC(AOI_AOVAR2,_mean)(AOI_AOVAR *z){return AOI_FUNC(AOI_NVAR2_P,_mean)(z->item,z->len);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
_f64 AOI_FUNC(AOI_AOVAR2,_median)(AOI_AOVAR *z){return AOI_FUNC(AOI_NVAR2_P,_median)(z->item,z->len);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
AOI_NVAR AOI_FUNC(AOI_AOVAR2,_mode)(AOI_AOVAR *z){return AOI_FUNC(AOI_NVAR2_P,_mode)(z->item,z->len);}

MCSL_API MCSL_ATTR (nonnull(1)) AOI_NVAR AOI_FUNC(AOI_NVAR2_P,_min)(AOI_NVAR* x,size_t n);
MCSL_API MCSL_ATTR (nonnull(1)) AOI_NVAR AOI_FUNC(AOI_NVAR2_P,_max)(AOI_NVAR* x,size_t n);
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
AOI_NVAR AOI_FUNC(AOI_AOVAR2,_min)(AOI_AOVAR *z){return AOI_FUNC(AOI_NVAR2_P,_min)(z->item,z->len);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
AOI_NVAR AOI_FUNC(AOI_AOVAR2,_max)(AOI_AOVAR *z){return AOI_FUNC(AOI_NVAR2_P,_max)(z->item,z->len);}


#ifdef MCSL_CPP
MCSL_EXTERN_C_CLOSE
#endif

#ifdef MCSL_CPP
namespace mcsl{
class AOI_AOVAR2{
private:
	__typeof__ (AOI_AOVAR :: item) __item;
	__typeof__ (AOI_AOVAR :: len) __len;
	__typeof__ (AOI_AOVAR :: cap) __cap;
	MCSL_ALWAYS_INLINE AOI_AOVAR* __self(){return (AOI_AOVAR*)this;}
	MCSL_ALWAYS_INLINE AOI_AOVAR* __to_c_aoi(const AOI_AOVAR2 &z){return (AOI_AOVAR*)&z;}
	MCSL_ALWAYS_INLINE AOI_AOVAR* __to_c_aoi(const AOI_AOVAR2 *z){return (AOI_AOVAR*)z;}
	MCSL_ALWAYS_INLINE void __init_self(){AOI_FUNC(AOI_AOVAR2,_init)(__self());}
public:
	AOI_AOVAR2(){__init_self();}
	~AOI_AOVAR2(){AOI_FUNC(AOI_AOVAR2,_free)(__self());}
	MCSL_ALWAYS_INLINE MCSL_WUR __typeof__(__len) len(){return __len;}
	MCSL_ALWAYS_INLINE MCSL_WUR __typeof__(__cap) cap(){return __cap;}
	MCSL_ALWAYS_INLINE MCSL_WUR __typeof__(__item) item(){return __item;}
	MCSL_ALWAYS_INLINE void free(){AOI_FUNC(AOI_AOVAR2,_free)(__self()); __init_self();}
	MCSL_ALWAYS_INLINE void shrink_to_fit(){AOI_FUNC(AOI_AOVAR2,_shrink_to_fit)(__self());}
	MCSL_ALWAYS_INLINE void refresh(){AOI_FUNC(AOI_AOVAR2,_refresh)(__self());}
	MCSL_ALWAYS_INLINE void reverse(){AOI_FUNC(AOI_AOVAR2,_reverse)(__self());}
	MCSL_ALWAYS_INLINE MCSL_WUR ssize_t found(AOI_NVAR c){return AOI_FUNC(AOI_AOVAR2,_found)(__self(),c);}
	MCSL_ALWAYS_INLINE MCSL_WUR size_t search(AOI_NVAR c){return AOI_FUNC(AOI_AOVAR2,_search)(__self(),c);}
	MCSL_ALWAYS_INLINE MCSL_WUR bool is_sort_min(){return AOI_FUNC(AOI_AOVAR2,_is_sort_min)(__self());}
	MCSL_ALWAYS_INLINE MCSL_WUR bool is_sort_max(){return AOI_FUNC(AOI_AOVAR2,_is_sort_max)(__self());}
	MCSL_ALWAYS_INLINE void sort_min(){return AOI_FUNC(AOI_AOVAR2,_sort_min)(__self());}
	MCSL_ALWAYS_INLINE void sort_max(){return AOI_FUNC(AOI_AOVAR2,_sort_max)(__self());}
	MCSL_ALWAYS_INLINE _i64 sum(){return AOI_FUNC(AOI_AOVAR2,_sum)(__self());}
	MCSL_ALWAYS_INLINE MCSL_WUR _f64 mean(){return AOI_FUNC(AOI_AOVAR2,_mean)(__self());}
	MCSL_ALWAYS_INLINE MCSL_WUR _f64 median(){return AOI_FUNC(AOI_AOVAR2,_median)(__self());}
	MCSL_ALWAYS_INLINE MCSL_WUR AOI_NVAR mode(){return AOI_FUNC(AOI_AOVAR2,_mode)(__self());}
	MCSL_ALWAYS_INLINE MCSL_WUR AOI_NVAR min(){return AOI_FUNC(AOI_AOVAR2,_min)(__self());}
	MCSL_ALWAYS_INLINE MCSL_WUR AOI_NVAR max(){return AOI_FUNC(AOI_AOVAR2,_max)(__self());}
	MCSL_ALWAYS_INLINE MCSL_WUR cstring to_str(){return AOI_FUNC(AOI_AOVAR2,_to_str)(__self());}
	MCSL_ALWAYS_INLINE MCSL_WUR cstring to_str(char d){return AOI_FUNC(AOI_AOVAR2,_to_str_d_chr)(__self(),d);}
	MCSL_ALWAYS_INLINE MCSL_WUR cstring to_str(const cstring d){return AOI_FUNC(AOI_AOVAR2,_to_str_d_cstr)(__self(),d);}
	MCSL_ALWAYS_INLINE void add(AOI_NVAR x){AOI_FUNC(AOI_AOVAR2,_add)(__self(),x);}
	MCSL_ALWAYS_INLINE void add(AOI_AOVAR *z){AOI_FUNC(AOI_AOVAR2,_add_aoi)(__self(),z);}
	MCSL_ALWAYS_INLINE void add(const AOI_AOVAR2 &z){AOI_FUNC(AOI_AOVAR2,_add_aoi)(__self(),__to_c_aoi(z));}
	MCSL_ALWAYS_INLINE void add_in(size_t i,AOI_NVAR x){AOI_FUNC(AOI_AOVAR2,_add_in)(__self(),i,x);}
	MCSL_ALWAYS_INLINE void add_in(size_t i,AOI_AOVAR *z){AOI_FUNC(AOI_AOVAR2,_add_in_aoi)(__self(),i,z);}
	MCSL_ALWAYS_INLINE void add_in(size_t i,const AOI_AOVAR2 &z){AOI_FUNC(AOI_AOVAR2,_add_in_aoi)(__self(),i,__to_c_aoi(z));}
	MCSL_ALWAYS_INLINE void set(AOI_AOVAR *z){AOI_FUNC(AOI_AOVAR2,_set_aoi)(__self(),z);}
	MCSL_ALWAYS_INLINE void set(const AOI_AOVAR2 &z){AOI_FUNC(AOI_AOVAR2,_set_aoi)(__self(),__to_c_aoi(z));}
	MCSL_ALWAYS_INLINE void del(size_t i){AOI_FUNC(AOI_AOVAR2,_del_i)(__self(),i);}
	MCSL_ALWAYS_INLINE void del(size_t i1,size_t i2){AOI_FUNC(AOI_AOVAR2,_del_l)(__self(),i1,i2);}
	MCSL_ALWAYS_INLINE void del_dup(){AOI_FUNC(AOI_AOVAR2,_del_dup)(__self());}
	MCSL_ALWAYS_INLINE void del_search(AOI_NVAR x){AOI_FUNC(AOI_AOVAR2,_del_search)(__self(),x);}
	MCSL_ALWAYS_INLINE MCSL_WUR AOI_NVAR get(size_t i){return __item[i];}

	MCSL_ALWAYS_INLINE MCSL_WUR AOI_NVAR operator[](ssize_t i){return get( (i >= 0) ? i : len() + i );}

	MCSL_ALWAYS_INLINE AOI_AOVAR2& operator<<(AOI_NVAR x){add(x); return *this;}
	MCSL_ALWAYS_INLINE AOI_AOVAR2& operator<<(const AOI_AOVAR &z){add((AOI_AOVAR*)&z); return *this;}
	MCSL_ALWAYS_INLINE AOI_AOVAR2& operator<<(const AOI_AOVAR2 &z){add(z); return *this;}
};/*AOI_AOVAR2*/
}/*mcsl*/
#endif/*MCSL_CPP*/

#endif /*AOI_DEC_BEGIN && !AOI_DEC_END*/

#if defined(AOI_DEC_BEGIN) && defined(AOI_DEC_END)
#undef AOI_DEC_BEGIN
#undef _AOI_CONCAT
#undef _AOI_CONCAT2
#undef _AOI_CONCAT_X
#undef _AOI_CONCAT_X2
#undef _AOI_NVAR
#undef _AOI_NVAR_P
#undef _AOI_NVAR_PF
#undef _AOI_AOVAR
#undef AOI_NVAR
#undef AOI_NVAR_P
#undef AOI_NVAR_PF
#undef AOI_AOVAR
#undef AOI_NVAR2
#undef AOI_NVAR_P2
#undef AOI_AOVAR2
#undef AOI_FUNC
#undef AOI_FUNC2
#undef AOI_FUNC3
#undef AOI_SIZE_VAR
#undef AOI_ITEM_MALLOC
#undef AOI_ITEM_CALLOC
#undef AOI_ITEM_REALLOC
#undef AOI_SIZE_N
#endif
