/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 7, 2019
 *      Author: keith
 *
 *      implements round robin scheduling algorithm
 *      pre-emptive
 */

//TODO fill in content

#include "../includes/scheduler_RR.h"

bool  Scheduler_RR::time_to_switch_processes(int tick_count, PCB &p) {

	//bool change = Scheduler::time_to_switch_processes(tick_count, p);
	//return change;

	int remaining = p.remaining_cpu_time;
	int required = p.required_cpu_time;
	if (remaining > 0 && preemptive && (required - remaining) % time_slice ==0) {
		return true;
	}
	else if (remaining <= 0) {
		return true;
	}
	return false;

}

void Scheduler_RR::sort() {

}
