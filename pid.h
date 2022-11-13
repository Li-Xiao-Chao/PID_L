#ifndef PID_H
#define PID_H

#include "s_typedef.h"

typedef struct {

    //PID参数
    fp32 Kp;
    fp32 Ki;
    //目标值
    fp32 target;
    //实际值
    fp32 actual;
    //PID输出
    fp32 pid_out;
    //比例输出
    fp32 Kp_out;
    //积分输出
    fp32 Ki_out;
    //误差缓存区
    fp32 error_buffer[3];
    //输出变化值
    fp32 pid_u;
} pid_type;

/**
  * @brief          PID计算
  * @param[out]     pid: PID结构体数据指针
  * @param[in]      ref: 反馈数据
  * @param[in]      set: 目标值
  * @retval         PID输出
  */
__attribute__((unused)) void PID_calc(pid_type *pid, fp32 ref, fp32 set, const fp32 Kp, const fp32 Ki);

#endif //PID_H
