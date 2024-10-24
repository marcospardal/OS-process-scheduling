#include <iostream>
#include <vector>
#include <memory>

#include "FileReader.h"
#include "FCFS.h"
#include "SJF.h"
#include "RoundRobin.h"

using namespace std;

int main() {
  FileReader file_reader = FileReader();
  vector<unique_ptr<ProcessQueue>> queues;

  file_reader.read_file("../data/input.txt");

  queues.push_back(make_unique<FCFS>(file_reader.get_processes()));
  queues.push_back(make_unique<SJF>(file_reader.get_processes()));
  queues.push_back(make_unique<RoundRobin>(file_reader.get_processes(), 2));

  for (const auto& queue : queues) {
    queue->execute();
  }

  for (const auto& queue : queues) {
    queue->display_queue_performance();
  }
}