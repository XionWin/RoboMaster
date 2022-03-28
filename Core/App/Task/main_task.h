#ifndef __MAIN_TASK_H__
#define __MAIN_TASK_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "color.h"

typedef int (*main_task_run_func)();

typedef struct
{
    main_task_run_func run;
} main_task_t;


void main_task_init();

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_TASK_H__ */