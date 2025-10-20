cmake_minimum_required(VERSION 3.0)
project(CryptoTool)

include_directories(include)

add_executable(CryptoTool src/main.cpp src/Crypto.cpp src/FileHandler.cpp src/Menu.cpp)
