#ifndef ROUND_ROBIN_H
#define ROUND_ROBIN_H

#include "ProcessQueue.h"

using namespace std;

class RoundRobin : public ProcessQueue {
  private:
    int quantum;

  public:
    RoundRobin(vector<ExecutableProcess> processes, int quantum): ProcessQueue(processes, "RR ", false), quantum(quantum) {};

    void execute_process() override;

  private:
    void execute_first_in_line();

    void send_process_to_the_end_of_queue();
};

#endif