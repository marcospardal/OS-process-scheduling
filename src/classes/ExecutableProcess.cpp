#include "ExecutableProcess.h"
#include <iostream>

using namespace std;

ExecutableProcess::ExecutableProcess(int execution_time, int arrival_time) {
  start_time = -1;
  finish_time = -1;

  this->execution_time = execution_time;
  this->arrival_time = arrival_time;
}

void ExecutableProcess::execute(int time_units, int current_time) {
  this->current_time = current_time;

  if (this->can_execute()) {
    if (!this->is_active()) this->start_process();

    this->execute_process(time_units);
  } else {
    throw runtime_error("Can't execute process");
  }
}

bool ExecutableProcess::can_execute() {
  return this->finish_time == -1;
}

bool ExecutableProcess::is_active() {
  return this->start_time != -1 && this->finish_time == -1;
}

void ExecutableProcess::start_process() {
  this->start_time = this->current_time;
}

void ExecutableProcess::execute_process(int time_units) {
  if (this->will_not_finish(time_units)) this->execution_time -= time_units;
  else finish_process();
}

bool ExecutableProcess::will_not_finish(int time_units) {
  return time_units < this->execution_time;
}

void ExecutableProcess::finish_process() {
  this->finish_time = this->current_time + this->execution_time;
  this->execution_time = 0;
}

int ExecutableProcess::get_execution_time() {
  return this->execution_time;
}

int ExecutableProcess::get_arrival_time() {
  return this->arrival_time;
}

int ExecutableProcess::get_start_execution_time() {
  return this->start_time;
}

int ExecutableProcess::get_conclusion_time() {
  return this->finish_time;
}