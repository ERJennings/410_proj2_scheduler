/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */

//TODO fill in content

#include "../includes/scheduler_SRTF.h"

bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p) {
	int remainingTime = p.remaining_cpu_time;
	if (remainingTime > 0 && remainingTime > ready_q->front().remaining_cpu_time) {
		return true;
	}
	else if (remainingTime <= 0) {
		return true;
	}
	return false;
}

void Scheduler_SRTF::sort() {
	std::vector<PCB> sortingVector;

	for (int i =0; i< ready_q->size(); i++){
		sortingVector.push_back(ready_q->front());
		ready_q->pop();
	}

	// Not efficient according to CPSC 420 but it works.
	PCB higher;
	for (int i = 0; i < sortingVector.size(); i++) {
		for (int j = 0; j < sortingVector.size(); j++) {
			if (sortingVector[i].remaining_cpu_time > sortingVector[j].remaining_cpu_time) {
				higher = sortingVector[i];
				sortingVector[i] = sortingVector[j];
				sortingVector[j] = higher;
			}
		}
	}

	for (int a = 0; a < sortingVector.size(); a++) {
		ready_q->push(sortingVector[a]);
	}
}
