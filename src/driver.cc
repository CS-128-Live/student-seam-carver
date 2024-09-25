#include "image_processing.hpp"

using namespace std;

void PrintUsage(const std::string& program_name) {
  cout << "Usage: " << program_name << " <image_name> <new_width> <new_height>"
       << endl;
}

int main(int argc, char* argv[]) {
  if (argc != 4) {
    PrintUsage(argv[0]);
    return 1;
  }

  // MP PART: 3
}