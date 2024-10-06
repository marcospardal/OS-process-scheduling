#include <iostream>
#include <vector>
#include <memory>

#include "FileReader.h"
#include "FCFS.h"


using namespace std;

int main() {
  FileReader file_reader = FileReader();
  vector<unique_ptr<ProcessQueue>> queues;

  file_reader.read_file("../data/input.txt");

  queues.push_back(make_unique<FCFS>(file_reader.get_processes()));

  for (const auto& queue : queues) {
    queue->execute();
  }

  for (const auto& queue : queues) {
    queue->display_queue_performance();
  }
}