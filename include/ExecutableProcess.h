#ifndef EXECUTABLE_PROCESS_H
#define EXECUTABLE_PROCESS_H


class ExecutableProcess {
  private:
    int start_time;
    int finish_time;
    int execution_time;
    int current_time;
    int arrival_time;

    void start_process(); 

    void execute_process(int time_units);

    bool will_not_finish(int time_units);

    void finish_process();


  public:
    ExecutableProcess(int execution_time, int arrival_time);

    bool can_execute();

    void execute(int time_units, int current_time);

    bool is_active();

    int get_execution_time();

    int get_arrival_time();

    int get_start_execution_time();

    int get_conclusion_time();
};

#endif