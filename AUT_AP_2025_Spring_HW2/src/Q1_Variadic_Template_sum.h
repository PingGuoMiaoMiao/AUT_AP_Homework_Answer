#ifndef Q1_VARIADIC_TEMPLATE_SUM_H
#define Q1_VARIADIC_TEMPLATE_SUM_H

#include <string>
#include <type_traits>
#include <stdexcept>

// 基础类型判断
template<typename T>
constexpr bool is_numeric_type = std::is_arithmetic_v<T>;

// 字符串类型判断
template<typename T>
constexpr bool is_string_type = std::is_convertible_v<T, std::string_view>;

// 主模板声明
template<typename T>
double JudgeNumber(const T& value) {
    if constexpr (is_numeric_type<T>) {
        return static_cast<double>(value);
    } else if constexpr (is_string_type<T>) {
        try {
            size_t pos;
            double num = std::stod(std::string(value), &pos);
            if (pos != std::string(value).length()) {
                throw std::invalid_argument("Invalid numeric string");
            }
            return num;
        } catch (...) {
            return 0.0;
        }
    } else {
        static_assert(is_numeric_type<T> || is_string_type<T>,
                     "Unsupported type for sum function");
        return 0.0;
    }
}

// 字符数组特化
template<size_t N>
double JudgeNumber(const char (&str)[N]) {
    try {
        return std::stod(str);
    } catch (...) {
        return 0.0;
    }
}

// 主求和函数
template<typename... Args>
auto sum(const Args&... args) {
    return (JudgeNumber(args) + ...);
}

#endif // Q1_VARIADIC_TEMPLATE_SUM_H