#include <fstream>
#include <cerrno>
#include <stdexcept>
#include <cstring>
#include <vector>
#include <iostream>

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "\nUsage: " << argv[0] << " <disk> [sector] (default is 0)\n\n";
    return 1;
  }
  std::string diskName = std::string() + argv[1];
  std::string sector = std::string() + "0";
  if (argc > 2) {
    sector = std::string() + argv[2];
  } else {
    sector = std::string() + "0";
  }
  std::string::size_type sz;
  int s = std::stoi (sector, &sz);
  //std::cout << s << "\n";
  //std::cout << diskName << "\n";
  std::string diskError = std::string() + diskName + ": ";
  std::ifstream disk(diskName, std::ios_base::binary);
  if(!disk)
    throw(std::runtime_error(diskError + std::strerror(errno)));
  disk.seekg(512 * s);
  if(!disk)
    throw(std::runtime_error(diskError + std::strerror(errno)));
  std::vector<char> buffer(512);
  disk.read(&buffer[0], 512);
  if(!disk)
    throw(std::runtime_error(diskError + std::strerror(errno)));
  for (auto i = buffer.begin(); i != buffer.end(); ++i)
    std::cout << *i;
}
