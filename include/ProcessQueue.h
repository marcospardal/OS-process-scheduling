#ifndef PROCESS_QUEUE_H
#define PROCESS_QUEUE_H

#include <vector>

#include "ExecutableProcess.h"

using namespace std;

class ProcessQueue {
  protected:
    vector<ExecutableProcess> processes;
    vector<ExecutableProcess> active_processes;
    vector<ExecutableProcess> finished_processes;
    vector<int> processes_start_time;

  public:
    ProcessQueue(vector<ExecutableProcess> processes, vector<int> processes_start_time) : processes(processes), processes_start_time(processes_start_time) {};

    virtual void execute() = 0;
};

#endif