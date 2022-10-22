#include <sstream>

#include <gtest/gtest.h>

#include "BitCounter.h"


TEST(BitCount, BaseTest) {
    std::stringstream ss_in;
    ss_in << "0 2334" << std::endl;
    std::stringstream ss_out;
    run(ss_in, ss_out);
    unsigned int result = 0;
    ss_out >> result;
    unsigned int expected_result = 0;
    EXPECT_EQ(expected_result, result);
}
