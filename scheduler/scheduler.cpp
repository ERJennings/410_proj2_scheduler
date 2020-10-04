/*
 * scheduler.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

#include "../includes/scheduler.h"

void Scheduler::add(PCB p) {
	ready_q->push(p);
}

PCB Scheduler::getNext() {
	PCB next = ready_q->front();
	ready_q->pop();
	return next;
}

bool Scheduler::isEmpty() {
	return ready_q->empty();;
}

bool Scheduler::time_to_switch_processes(int tick_count, PCB &p) {

	if (tick_count >= p.remaining_cpu_time && !preemptive) {

	}

	else if (preemptive) {
		if (tick_count >= time_slice){
			return true;
		}
	}

	return false;
}
