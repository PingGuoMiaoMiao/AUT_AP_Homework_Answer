#ifndef Q1_VARIADIC_TEMPLATE_SUM_H
#define Q1_VARIADIC_TEMPLATE_SUM_H

#include <string>
#include <string_view>
#include <type_traits>
#include <limits>  // For NaN

// 核心转换函数，返回 double 类型的数值
template<typename T>
double JudgeNumber(const T& num);

// 专门处理 std::string 类型的特化
template<>
double JudgeNumber<std::string>(const std::string& str);

// 专门处理 const char* 类型的特化
template<>
double JudgeNumber<const char*>(const char* const& str);

// 专门处理 std::string_view 类型的特化
template<>
double JudgeNumber<std::string_view>(const std::string_view& str);

// 核心的求和模板
template<typename... Args>
double sum(const Args&... args) {
    return (JudgeNumber(args) + ...);
}

#endif // Q1_VARIADIC_TEMPLATE_SUM_H
