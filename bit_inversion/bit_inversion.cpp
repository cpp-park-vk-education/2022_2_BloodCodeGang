#include "bit_inversion.h"

unsigned int invert(unsigned int N, size_t K) {
    return N ^ (1 << K);
}

void start(std::istream &in, std::ostream &out) {
    unsigned int N = 0;
    size_t K = 0;
    in >> N >> K;
    out << invert(N, K) << std::endl;
}
