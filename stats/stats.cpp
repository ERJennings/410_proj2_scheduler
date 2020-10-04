/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */

#include "../includes/stats.h"
#include <vector>

Stats::Stats(std::vector<PCB> &finished_vector) {

	av_response_time = UNINITIALIZED;
	av_turnaround_time = UNINITIALIZED;
	av_wait_time = UNINITIALIZED;
	vec = &finished_vector;

	calcStats();

}

void Stats::showAllProcessInfo() {
	for (int i = 0; i < vec->size(); i++) {
		//Remember this for later reference: http://www.cplusplus.com/reference/cstdio/printf/

		//Process 1 Required CPU time:2  arrived:0 started:0 finished:2
		printf("Process %d Required CPU time:%d arrived:%d started:%d finished:%d\n", vec->at(i).process_number, vec->at(i).required_cpu_time,
						vec->at(i).arrival_time, vec->at(i).start_time,  vec->at(i).finish_time);
	}
}

float Stats::get_av_response_time() {
	return av_response_time;
}

float Stats::get_av_turnaround_time() {
	return av_turnaround_time;
}

float Stats::get_av_wait_time() {
	return av_wait_time;
}

void Stats::calcStats(){

	av_response_time = 0;
	av_turnaround_time = 0;
	av_wait_time = 0;

	int index = vec->size() - 1;

	for (int i = 0; i < vec->size(); i++) {

		av_response_time += ((vec->at(index)).start_time) -
				((vec->at(index)).arrival_time);

		av_turnaround_time += ((vec->at(index)).finish_time)
				- ((vec->at(index)).arrival_time);

		av_wait_time += ((vec->at(index)).finish_time) -
				((vec->at(index)).arrival_time) - ((vec->at(index)).required_cpu_time);

		index--;
	}

	av_response_time /= vec->size();
	av_turnaround_time /= vec->size();
	av_wait_time /= vec->size();

}
