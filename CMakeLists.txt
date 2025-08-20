cmake_minimum_required(VERSION 3.16)
project(GreedySnake)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 启用更详细的编译输出
# set(CMAKE_VERBOSE_MAKEFILE ON)

# 设置输出目录
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 或者更精确的文件收集方式（推荐）
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS 
    "src/*.cpp"
    "src/*.c"
)

# 添加可执行文件
add_executable(${PROJECT_NAME} main.cpp ${SOURCES})

# 包含目录设置
target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# 链接库（如果有）
# target_link_libraries(${PROJECT_NAME} PRIVATE some_library)

# 安装规则（可选）
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

install(DIRECTORY include/ DESTINATION include)

# include_directories(${CMAKE_SOURCE_DIR}/include)

# file(GLOB SOURCES CONFIGURE_DEPENDS  "src/*.cpp")

# add_executable(main main.cpp ${SOURCES})
