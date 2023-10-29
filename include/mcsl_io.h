#ifndef MCSL_IO_H
#define MCSL_IO_H

#include "sub/begin.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdio.h>

#ifdef MCSL_WIN
#include <io.h>
#define MCSL_PATH_SEPARATOR '\\'
# ifndef R_OK
# define R_OK 4
# endif
# ifndef W_OK
# define W_OK 2
# endif
# ifndef X_OK
# define X_OK 1
# endif
# ifndef F_OK
# define F_OK 0
# endif
#else
#define MCSL_PATH_SEPARATOR '/'
#endif

#ifdef MCSL_CPP
MCSL_EXTERN_C_OPEN
#endif

#ifdef MCSL_WIN
MCSL_INLINE_STATIC cstring realpath(const cstring path, cstring buf){
	_u32 b = GetFullPathName(path,
				-1,buf, NULL);
	return (b == 0) ? NULL : buf;
}
#endif

MCSL_INLINE_STATIC MCSL_WUR bool mcsl_file_check_exist(const cstring path){return access(path,F_OK) == 0;}
MCSL_INLINE_STATIC MCSL_WUR bool mcsl_file_check_read(const cstring path){return access(path,R_OK) == 0;}
MCSL_INLINE_STATIC MCSL_WUR bool mcsl_file_check_write(const cstring path){return access(path,W_OK) == 0;}
MCSL_INLINE_STATIC MCSL_WUR bool mcsl_file_check_execute(const cstring path){return access(path,X_OK) == 0;}

MCSL_INLINE_STATIC MCSL_WUR bool mcsl_is_folder(const cstring path){
	struct stat st; return (stat(path, &st) == 0) ? S_ISDIR(st.st_mode) : false;
}
#define mcsl_is_dir mcsl_is_folder
MCSL_INLINE_STATIC MCSL_WUR bool mcsl_is_file(const cstring path){
	struct stat st; return (stat(path, &st) == 0) ? S_ISREG(st.st_mode) : false;
}

MCSL_API MCSL_WUR cstring mcsl_where_is_this();

#define MYIN_FILENO STDIN_FILENO
#define MYOUT_FILENO STDOUT_FILENO

MCSL_INLINE_STATIC MCSL_ATTR (nonnull(2))
void __myout_out(_i32 fd,void* data, size_t l){write(fd,data,l);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(2))
void __myout_out_cstr(_i32 fd,const cstring s){write(fd,(void*)s,mcsl_str_get_len(s));}
MCSL_INLINE_STATIC
void __myout_outc(_i32 fd,_i32 c){__myout_out(fd,(void*)&c,1);}
#define __myout_out_chr __myout_outc
MCSL_INLINE_STATIC
void __myout_out_line(_i32 fd){__myout_outc(fd,'\n');}

MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void myout_out(void* data, size_t l){__myout_out(MYOUT_FILENO,data,l);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void myout_out_cstr(const cstring s){__myout_out_cstr(MYOUT_FILENO,s);}
MCSL_INLINE_STATIC
void myout_outc(_i32 c){__myout_outc(MYOUT_FILENO,c);}
#define myout_out_chr myout_outc
MCSL_INLINE_STATIC
void myout_out_line(){__myout_out_line(MYOUT_FILENO);}

MCSL_API bool __myin_set_raw(_i32 fd);
MCSL_API bool __myin_reset(_i32 fd);
MCSL_INLINE_STATIC bool myin_set_raw(){return __myin_set_raw(MYIN_FILENO);}
MCSL_INLINE_STATIC bool myin_reset(){return __myin_reset(MYIN_FILENO);}

/*integer input*/
MCSL_INLINE_STATIC _i32 __myin_getc(_i32 fd){_i32 res = 0; read(fd,&res,sizeof(res)); return res;}
MCSL_INLINE_STATIC _i32 myin_getc(){return __myin_getc(MYIN_FILENO);}

MCSL_API MCSL_ATTR (nonnull(2)) void __myin_in(_i32 fd,_aoc *z);
MCSL_API MCSL_ATTR (nonnull(2)) void __myin_in_ec(_i32 fd,_aoc *z,const cstring ec);
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void myin_in(_aoc *z){__myin_in(MYIN_FILENO,z);}
MCSL_INLINE_STATIC MCSL_ATTR (nonnull(1))
void myin_in_ec(_aoc *z,const cstring ec){__myin_in_ec(MYIN_FILENO,z,ec);}

#ifdef MCSL_CPP
MCSL_EXTERN_C_CLOSE
#endif

#ifdef MCSL_CPP
MCSL_INLINE_STATIC
void __myin_in(_i32 fd,mcsl::aoc &z){__myin_in(fd,(_aoc*)&z);}
MCSL_INLINE_STATIC
void __myin_in_ec(_i32 fd,mcsl::aoc &z,const cstring ec){__myin_in_ec(fd,(_aoc*)&z,ec);}
MCSL_INLINE_STATIC
void __myin_in(_i32 fd,mcsl::aoc &z,const cstring ec){__myin_in_ec(fd,(_aoc*)&z,ec);}

MCSL_INLINE_STATIC
void myin_in(mcsl::aoc &z){myin_in((_aoc*)&z);}
MCSL_INLINE_STATIC
void myin_in_ec(mcsl::aoc &z,const cstring ec){myin_in_ec((_aoc*)&z,ec);}
MCSL_INLINE_STATIC
void myin_in(mcsl::aoc &z,const cstring ec){myin_in_ec((_aoc*)&z,ec);}
#endif

#endif/*MCSL_IO_H*/