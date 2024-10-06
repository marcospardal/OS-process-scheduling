#include "ProcessQueue.h"

void ProcessQueue::execute() {

  while(true) {
    bool have_process_to_execute = has_active_process() && has_waiting_process();

    if (!have_process_to_execute)
      break;

    if (!has_active_process()) activate_eligible_processes();

    if (has_active_process()) execute_process();
    else sleep(1);
  }
}

bool ProcessQueue::has_active_process() {
  return this->active_processes.size();
}

bool ProcessQueue::has_waiting_process() {
  return this->waiting_processes.size();
}

void ProcessQueue::activate_eligible_processes() {
  int process_index = 0;

  for (const int process_start_time : this->processes_start_time) {
    if (process_start_time >= this->current_time) {
      activate_process(process_index);
    }
    process_index++;
  }
}

void ProcessQueue::activate_process(int waintg_process_index) {
  active_processes.push_back(waiting_processes[waintg_process_index]);
  waiting_processes.erase(waiting_processes.begin() + waintg_process_index);
}

void ProcessQueue::execute_process(int active_process_index, int time_units) {
  this->active_processes[active_process_index].execute(time_units, this->current_time);
}

void ProcessQueue::sleep(int time_units) {
  this->current_time = time_units;
}