#include <iostream>
#include <gtest/gtest.h>

#include "Q1_Variadic_Template_sum.h"
#include "Q2_Word_Frequency.h"


#include <iostream>
#include <gtest/gtest.h>

int main(int argc, char **argv) {
	if (false) { // 设置为false以运行测试
		// 调试代码示例
		std::cout << countWords("Test debug output")["test"] << std::endl;
	}
	else {
		::testing::InitGoogleTest(&argc, argv);
		std::cout << "RUNNING TESTS..." << std::endl;
		int ret = RUN_ALL_TESTS();
		if (!ret) std::cout << "<<<SUCCESS>>>" << std::endl;
		else std::cout << "FAILED" << std::endl;
		return ret;
	}
	return 0;
}