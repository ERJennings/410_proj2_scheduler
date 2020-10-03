/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */

//TODO fill in content

#include "../includes/stats.h"

Stats::Stats(std::vector<PCB> &finished_vector) {
	av_wait_time = UNINITIALIZED;
	av_turnaround_time = UNINITIALIZED;
	av_response_time = UNINITIALIZED;
	vec = &finished_vector;
}

void Stats::showAllProcessInfo() {

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

}
