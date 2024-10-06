#ifndef EXECUTABLE_PROCESS_H
#define EXECUTABLE_PROCESS_H


class ExecutableProcess {
  private:
    int start_time = -1;
    int finish_time = -1;
    int execution_time;
    int current_time;

    void start_process(); 

    bool can_execute();

    void execute_process(int time_units);

    bool will_not_finish(int time_units);

    void finish_process();


  public:
    ExecutableProcess(int execution_time) : execution_time(execution_time) {};

    void execute(int time_units, int current_time);

    bool is_active();
};

#endif