#include "ProcessQueue.h"

ProcessQueue::ProcessQueue(vector<ExecutableProcess> processes, string type) {
  this->waiting_processes = processes;
  this->type = type;
  this->current_time = 0;
}

void ProcessQueue::execute() {
  while(true) {
    check_running_processes();

    activate_eligible_processes();

    if (has_active_process()) execute_process();

    bool has_process_to_execute = has_active_process() || has_waiting_process();

    if (!has_process_to_execute)
      break;

    sleep(1);
  }
}

void ProcessQueue::check_running_processes() {
  int process_index = 0;

  for (auto& process : active_processes) {
    if (!process.is_active())
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
    }
    process_index++;
  }
}

bool ProcessQueue::has_active_process() {
  return this->active_processes.size();
}

bool ProcessQueue::has_waiting_process() {
  return this->waiting_processes.size();
}

void ProcessQueue::activate_process(int wating_process_index) {
  active_processes.push_back(waiting_processes[wating_process_index]);
  waiting_processes.erase(waiting_processes.begin() + wating_process_index);
}

void ProcessQueue::execute_process(int active_process_index, int time_units) {
  this->active_processes[active_process_index].execute(time_units, this->current_time);
}

void ProcessQueue::sleep(int time_units) {
  this->current_time += time_units;
}

void ProcessQueue::display_queue_performance() {
  cout << type << ": " << get_queue_response_time() << endl;
}

float ProcessQueue::get_queue_response_time() {
  float sum_response_time = 0;
  float average_response_time = 0;

  for (auto& process : finished_processes) {
    float process_response_time = process.get_start_execution_time() - process.get_arrival_time();

    sum_response_time += process_response_time;
  }

  average_response_time = sum_response_time / finished_processes.size();

  return average_response_time;
}