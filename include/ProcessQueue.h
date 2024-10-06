#ifndef PROCESS_QUEUE_H
#define PROCESS_QUEUE_H

#include <vector>

#include "ExecutableProcess.h"

using namespace std;

class ProcessQueue {
  protected:
    vector<ExecutableProcess> waiting_processes;
    vector<ExecutableProcess> active_processes;
    vector<ExecutableProcess> finished_processes;
    vector<int> processes_start_time;
    int current_time = 0;

    void activate_eligible_processes();

    void activate_process(int waintg_process_index);

    bool has_active_process();

    bool has_waiting_process();

    void execute_process(int active_process_index, int time_units);

    virtual void execute_process() = 0;

  public:
    ProcessQueue(vector<ExecutableProcess> processes, vector<int> processes_start_time) : waiting_processes(processes), processes_start_time(processes_start_time) {};

    void execute();

    void sleep(int time_units);


};

#endif