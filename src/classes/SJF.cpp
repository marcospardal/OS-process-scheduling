#include "SJF.h"

void SJF::execute_process() {
  this->reorder_process_queue();

  if (!has_active_process()) return;

  this->execute_shorter();
}

void SJF::reorder_process_queue() {
  std::sort(this->active_processes.begin(), this->active_processes.end(), this->find_shorter_execution_time);
}

bool SJF::find_shorter_execution_time(const ExecutableProcess &a, const ExecutableProcess &b) {
  return a.get_execution_time() <= b.get_execution_time();
}

void SJF::execute_shorter() {
  int execution_time = this->calculate_total_execution_time();

  this->active_processes[0].execute(execution_time, this->current_time);
  this->current_time += execution_time;
}

int SJF::calculate_total_execution_time() {
  int current_process_left_time = active_processes[0].get_execution_time();
  bool has_next_process = waiting_processes.size() > 1;
  int next_process_arrival_time = waiting_processes[0].get_arrival_time();
  int total_time_to_execute = current_process_left_time;
  bool can_finish_current_process_until_next = next_process_arrival_time - this->current_time >= current_process_left_time;

  if (has_next_process && !can_finish_current_process_until_next) {
    total_time_to_execute = next_process_arrival_time - this->current_time;
  }

  return total_time_to_execute;
}