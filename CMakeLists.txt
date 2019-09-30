cmake_minimum_required(VERSION 3.14)
project(FinancialCalculator)

set(CMAKE_CXX_STANDARD 14)

add_executable(FinancialCalculator main.cpp FinancialCalculator.h FinancialCalculator.cpp)

target_link_libraries(FinancialCalculator PRIVATE m)