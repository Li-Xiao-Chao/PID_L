#ifndef PID_H
#define PID_H

#include "s_typedef.h"

typedef struct {

    //PID����
    fp32 Kp;
    fp32 Ki;
    //Ŀ��ֵ
    fp32 target;
    //ʵ��ֵ
    fp32 actual;
    //PID���
    fp32 pid_out;
    //�������
    fp32 Kp_out;
    //�������
    fp32 Ki_out;
    //������
    fp32 error_buffer[3];
    //����仯ֵ
    fp32 pid_u;
} pid_type;

/**
  * @brief          PID����
  * @param[out]     pid: PID�ṹ������ָ��
  * @param[in]      ref: ��������
  * @param[in]      set: Ŀ��ֵ
  * @retval         PID���
  */
__attribute__((unused)) void PID_calc(pid_type *pid, fp32 ref, fp32 set, const fp32 Kp, const fp32 Ki);

#endif //PID_H
