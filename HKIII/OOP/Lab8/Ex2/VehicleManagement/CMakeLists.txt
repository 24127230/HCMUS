cmake_minimum_required(VERSION 3.10)

# Tên project
project(VehicleManagement)

# Sử dụng chuẩn C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Thêm thư mục include vào đường dẫn tìm kiếm
include_directories(include)

# Tìm tất cả file cpp trong src/ và main/
file(GLOB SRC_FILES src/*.cpp main/*.cpp)

# Tạo file thực thi VehicleManager từ tất cả file .cpp
add_executable(VehicleManager ${SRC_FILES})
