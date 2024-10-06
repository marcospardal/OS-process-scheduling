#include "FCFS.h"

void FCFS::execute_process() {
  if (!has_active_process()) return;

  int execute_until_finish = active_processes[0].get_execution_time();
  active_processes[0].execute(execute_until_finish, current_time);
 
  this->current_time += execute_until_finish;
}