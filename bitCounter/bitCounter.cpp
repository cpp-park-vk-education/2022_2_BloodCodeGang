#include "bitCounter.h"

int countBits(unsigned number) {
  int count = 0;
  while (number > 0) {
    if (number & 1) {
      count++;
    }
    number >>= 2;
  }
  return count;
}

void run(std::istream &input, std::ostream &output) {
  unsigned number;

  input >> number;
  output << countBits(number) << std::endl;
}
