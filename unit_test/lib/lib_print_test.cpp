#include "../../lib/lib_print/lib_print.h"
#include <gtest/gtest.h>

TEST(LIB_PRINT_TEST, test_print1) {
  std::string test_input = "test lib print str";
  testing::internal::CaptureStdout();
  lib_print::Instance().printSmth(test_input.c_str());
  std::string test_output = testing::internal::GetCapturedStdout();
  std::string test_expexted = "test lib print str\n";
  EXPECT_EQ(test_output, test_input);
}