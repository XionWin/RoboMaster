#ifndef __SUB_TASK_H__
#define __SUB_TASK_H__

#ifdef __cplusplus
extern "C"
{
#endif

typedef int (*sub_task_run_func)();

typedef struct
{
    sub_task_run_func run;
} sub_task_t;

void sub_task_init();

#ifdef __cplusplus
}
#endif

#endif /* __SUB_TASK_H__ */