#include "pid.h"

__attribute__((unused)) void PID_calc(pid_type *pid, fp32 ref, fp32 set, const fp32 Kp, const fp32 Ki)
{
    pid->Kp = kp;
    pid->Ki = ki;
    pid->error_buffer[2] = pid->error_buffer[1];
    pid->error_buffer[1] = pid->error_buffer[0];
    pid->target = set;
    pid->actual = ref;
    pid->error_buffer[0] = set - ref;

    pid->Kp_out = pid->Kp * (pid->error_buffer[0] - pid->error_buffer[1]);
    pid->Ki_out = pid->Ki * pid->error_buffer[0];
    pid->pid_u = pid->Kp_out + pid->Ki_out;
    if (pid->pid_u > 204.0f)
    {
        pid->pid_u = 204.0f;
    }
    else if (pid->pid_u < -204.0f)
    {
        pid->pid_u = -204.0f;
    }

    pid->pid_out += pid->pid_u;
    if (pid->pid_u > 4095)
    {
        pid->pid_u = 4095;
    }
    else if (pid->pid_u < 0)
    {
        pid->pid_u = 0;
    }
}