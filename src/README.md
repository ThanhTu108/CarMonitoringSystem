# Logging Introduction (fmt syntax)
Spdlog utillizes the modern, type safe {fmt} libray format syntas instead of old-school printf specifiers. This prevent runtime crashes caused by mismatched typed specifiers

## Api
```c++
template <typename... T>
void print(format_string<T...> fmt, T&&... args);
```