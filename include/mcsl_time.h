#ifndef MCSL_TIME_H
#define MCSL_TIME_H

#include "sub/begin.h"
#include <time.h>

#ifdef MCSL_CPP
MCSL_EXTERN_C_OPEN
#endif

MCSL_API void mcsl_sleep(_f64 msec);

#ifdef MCSL_CPP
MCSL_EXTERN_C_CLOSE
#endif

#endif/*MCSL_TIME_H*/