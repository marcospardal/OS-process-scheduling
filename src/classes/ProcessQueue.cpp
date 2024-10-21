#include "ProcessQueue.h"

ProcessQueue::ProcessQueue(vector<ExecutableProcess> processes, string type) {
  this->waiting_processes = processes;
  this->type = type;
  this->current_time = 0;
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

void ProcessQueue::sleep(int time_units) {
  this->current_time += time_units;
}

void ProcessQueue::display_queue_performance() {
  cout << type << ": \n" << endl;
  cout << "\t response time - " << get_queue_response_time() << endl;
  cout << "\t turnaround time - " << get_queue_turnaround_time() << endl;
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

float ProcessQueue::get_queue_turnaround_time() {
  float sum_turnaround_time = 0;
  float average_turnaround_time = 0;

  for (auto& process : finished_processes) {
    float process_turnaround_time = process.get_conclusion_time() - process.get_arrival_time();

    sum_turnaround_time += process_turnaround_time;
  }

  average_turnaround_time = sum_turnaround_time / finished_processes.size();

  return average_turnaround_time;
}

float ProcessQueue::get_queue_wait_time() {

}