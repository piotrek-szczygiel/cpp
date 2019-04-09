cmake_minimum_required(VERSION 3.13)
project(lab4)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab4 main.cpp Product.cpp Product.h Service.cpp Service.h Date.cpp Date.h Commodity.cpp Commodity.h CommodityWithBail.cpp CommodityWithBail.h)