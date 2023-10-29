#ifndef MCSL_BEGIN_H
#error "Never include sub/version.h directly"
#endif

/*My C Standard library (MCSL)*/
/*created on 12 October 2023 (39200cb920677a094b70afce23d49a41bc7dc61dcde6051e66cf9fe76ade0a93)*/

#ifndef MCSL_VERSION_H
#define MCSL_VERSION_H

#define MCSL_STRINGIFY(s)         MCSL_TOSTRING(s)
#define MCSL_TOSTRING(s) #s

#define __MCSL_VERSION_INT(a, b, c) ((a)<<16 | (b)<<8 | (c))
#define __MCSL_VERSION_DOT(a, b, c) a ##.## b ##.## c
#define __MCSL_VERSION(a, b, c) __MCSL_VERSION_DOT(a, b, c)

#define __MCSL_VERSION_MAJOR(a) ((a) >> 16)
#define __MCSL_VERSION_MINOR(a) (((a) & 0x00FF00) >> 8)
#define __MCSL_VERSION_MICRO(a) ((a) & 0xFF)

#define MCSL_VERSION_MAJOR  0
#define MCSL_VERSION_MINOR  0
#define MCSL_VERSION_MICRO  0

#define MCSL_VERSION_INT   __MCSL_VERSION_INT(MCSL_VERSION_MAJOR, \
                                               MCSL_VERSION_MINOR, \
                                               MCSL_VERSION_MICRO)
#define MCSL_VERSION       __MCSL_VERSION(MCSL_VERSION_MAJOR,     \
                                           MCSL_VERSION_MINOR,     \
                                           MCSL_VERSION_MICRO)
#define MCSL_BUILD         MCSL_VERSION_INT
#define MCSL_VERSION_VARIAN 1121023

#define MCSL_IDENT         "mcsl-" MCSL_STRINGIFY(MCSL_VERSION) "-" MCSL_STRINGIFY(MCSL_VERSION_VARIAN)


#endif /*MCSL_VERSION_H*/