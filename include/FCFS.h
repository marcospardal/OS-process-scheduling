#ifndef FCFS_H
#define FCFS_H

#include "ProcessQueue.h"

#include <vector>

using namespace std;

class FCFS : public ProcessQueue {
  private:

  public:
    FCFS(vector<ExecutableProcess> processes): ProcessQueue(processes, "FCFS") {};

    void execute_process() override;
};

#endif