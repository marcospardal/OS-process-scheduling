#include "FileReader.h"

using namespace std;

void FileReader::read_file(string file_path) {
  try {
    file.open(file_path);

    read_lines();
  } catch (const std::runtime_error& e) {
    cerr << "Can't read input file " << e.what() << std::endl; 
  }
}

void FileReader::read_lines() {
  try {
    string line;
    while (getline(file, line)) {
      process_line_data(line);
    }
  } catch (const std::runtime_error& e) {
    cerr << "Error reading line " << e.what() << std::endl; 
  }
}

void FileReader::process_line_data(string line) {
  int break_at = line.find(' ');

  int start_time = stoi(line.substr(0, break_at));
  int execution_time = stoi(line.substr(break_at, line.size()));

  schedule_new_process(start_time, execution_time);
}

void FileReader::schedule_new_process(int start_time, int execution_time) {
  ExecutableProcess new_process = ExecutableProcess(execution_time);

  processes_start_time.push_back(start_time);
  processes.push_back(new_process);
}

vector<int> FileReader::get_process_start_time() {
  return processes_start_time;
}

vector<ExecutableProcess> FileReader::get_processes() {
  return processes;
}