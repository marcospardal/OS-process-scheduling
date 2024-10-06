#ifndef PROCESS_QUEUE_H
#define PROCESS_QUEUE_H

#include <vector>
#include <iostream>

#include "ExecutableProcess.h"

using namespace std;

class ProcessQueue {
  protected:
    string type;
    vector<ExecutableProcess> waiting_processes;
    vector<ExecutableProcess> active_processes;
    vector<ExecutableProcess> finished_processes;
    int current_time;

    void activate_eligible_processes();

    void activate_process(int waintg_process_index);

    bool has_active_process();

    bool has_waiting_process();

    void execute_process(int active_process_index, int time_units);

    virtual void execute_process() = 0;

    void check_running_processes();

    void close_process(int process_index);

    float get_queue_response_time();

  public:
    ProcessQueue(vector<ExecutableProcess> processes, string type);

    void execute();

    void sleep(int time_units);

    void display_queue_performance();
};

#endif