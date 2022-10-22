#include <sstream>

#include <gtest/gtest.h>

#include "bit_inversion.h"

TEST(Bit, BaseTest) {
    std::stringstream ss_in;
    ss_in << "25 1" << std::endl;
    std::stringstream ss_out;
    start(ss_in, ss_out);
    unsigned int result = 0;
    ss_out >> result;
    unsigned int expected_result = 27;
    EXPECT_EQ(expected_result, result);
}