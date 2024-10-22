#include "ProcessQueue.h"

ProcessQueue::ProcessQueue(vector<ExecutableProcess> processes, string type, bool activate_single_process_by_time) {
  this->waiting_processes = processes;
  this->type = type;
  this->current_time = 0;
  this->activate_single_process_by_time = activate_single_process_by_time;
}

void ProcessQueue::execute() {
  while(has_active_process() || has_waiting_process()) {
    check_running_processes();

    activate_eligible_processes();

    if (has_active_process()) execute_process();
    else sleep(1);
  }
}

void ProcessQueue::check_running_processes() {
  int process_index = 0;

  for (auto& process : active_processes) {
    if (!process.is_active() && !process.can_execute())
      close_process(process_index);

    process_index++;
  }
}

void ProcessQueue::close_process(int process_index) {
  finished_processes.push_back(active_processes[process_index]);
  active_processes.erase(active_processes.begin() + process_index);
}

void ProcessQueue::activate_eligible_processes() {
  int process_index = 0;

  for (auto& process : this->waiting_processes) {
    if (process.get_arrival_time() <= this->current_time) {
      activate_process(process_index);
      
      if (this->activate_single_process_by_time)
        break;
    }
    process_index++;
  }
}

bool ProcessQueue::has_active_process() {
  return this->active_processes.size() > 0;
}

bool ProcessQueue::has_waiting_process() {
  return this->waiting_processes.size() > 0;
}

void ProcessQueue::activate_process(int wating_process_index) {
  active_processes.push_back(waiting_processes[wating_process_index]);
  waiting_processes.erase(waiting_processes.begin() + wating_process_index);
}

void ProcessQueue::sleep(int time_units) {
  this->current_time += time_units;
}

void ProcessQueue::display_queue_performance() {
  cout << type << " " << get_queue_turnaround_time() << " " << get_queue_response_time() << " " << this->get_queue_wait_time() << endl;
}

float ProcessQueue::get_queue_response_time() {
  float sum_response_time = 0;
  float average_response_time = 0;

  for (auto& process : finished_processes) {
    sum_response_time += (float)process.get_process_response_time();
  }

  average_response_time = sum_response_time / finished_processes.size();

  return average_response_time;
}

float ProcessQueue::get_queue_turnaround_time() {
  float sum_turnaround_time = 0;
  float average_turnaround_time = 0;

  for (auto& process : finished_processes) {
    sum_turnaround_time += (float)process.get_process_turnaround_time();
  }

  average_turnaround_time = sum_turnaround_time / finished_processes.size();

  return average_turnaround_time;
}

float ProcessQueue::get_queue_wait_time() {
  float sum_wait_time = 0;
  float average_wait_time = 0;

  for (auto& process : finished_processes) {
    sum_wait_time += (float)process.get_process_wait_time();
  }

  average_wait_time = sum_wait_time / finished_processes.size();

  return average_wait_time;
}