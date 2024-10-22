#ifndef SJF_H
#define SJF_H

#include "ProcessQueue.h"

#include <vector>
#include <algorithm>

using namespace std;

class SJF : public ProcessQueue {
  public:
    SJF(vector<ExecutableProcess> processes): ProcessQueue(processes, "SJF", true) {};

    void execute_process() override;
  
  private:
    void reorder_process_queue();

    static bool find_shorter_execution_time(const ExecutableProcess &a, const ExecutableProcess &b);

    void execute_shorter();

    int calculate_total_execution_time();
};

#endif