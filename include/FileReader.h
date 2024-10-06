#ifndef FILE_READER_H
#define FILE_READER_H

#include <iostream>
#include <fstream>
#include <vector>

#include "ExecutableProcess.h"

using namespace std;

class FileReader {
  private:
    fstream file;
    vector<int> processes_start_time;
    vector<ExecutableProcess> processes;

    void read_lines();

    void process_line_data(string line);

    void schedule_new_process(int start_time, int execution);

  public:
    FileReader() {};

    void read_file(string file_path);

    vector<int> get_process_start_time();

    vector<ExecutableProcess> get_processes();
};

#endif