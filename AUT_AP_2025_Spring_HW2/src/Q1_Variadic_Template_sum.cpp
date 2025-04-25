#include "Q1_Variadic_Template_sum.h"

// 显式实例化常用类型
template double JudgeNumber<int>(const int&);
template double JudgeNumber<double>(const double&);
template double JudgeNumber<float>(const float&);
template double JudgeNumber<const char*>(const char* const&);
template double JudgeNumber<3>(const char (&)[3]);
template double JudgeNumber<4>(const char (&)[4]);