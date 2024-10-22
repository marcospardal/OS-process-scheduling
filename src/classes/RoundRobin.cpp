#include "RoundRobin.h"

void RoundRobin::execute_process() {
  if (!has_active_process()) return;

  this->execute_first_in_line();
}

void RoundRobin::execute_first_in_line() {
  bool process_did_not_finish = active_processes[0].get_execution_time() - this->quantum > 0;

  this->active_processes[0].execute(this->quantum, this->current_time);

  this->current_time += this->quantum;

  if (process_did_not_finish)
    this->send_process_to_the_end_of_queue();
}

void RoundRobin::send_process_to_the_end_of_queue() {
  ExecutableProcess process_to_move = this->active_processes[0];

  this->active_processes.erase(this->active_processes.begin());
  this->active_processes.push_back(process_to_move);
}