#include <fstream>
#include <cstring>
#include <vector>
#include <iostream>

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "\nUsage: sudo " << argv[0] << " <disk> [sector] (default is 0)\n\n";
    return 1;
  }
  std::string diskName = std::string() + argv[1];
  std::string sector = std::string() + "0";
  if (argc > 2) sector += std::string() + argv[2];
  std::string::size_type sz;
  int s = std::stoi (sector, &sz);
  std::string diskError = std::string() + diskName + ": ";
  std::ifstream disk(diskName, std::ios_base::binary);
  if(!disk) return 2;
  disk.seekg(512 * s);
  if(!disk) return 3;
  std::vector<char> buffer(512);
  disk.read(&buffer[0], 512);
  if(!disk) return 4;
  for (auto i = buffer.begin(); i != buffer.end(); ++i)
    std::cout << *i;
}
