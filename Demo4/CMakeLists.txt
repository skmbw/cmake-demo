# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (Demo4)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# 是否使用自己的 MathFunctions 库
option (USE_MYMATH "Use provided math implementation" ON) # ON 表示打开

# 加入一个配置头文件，用于处理 CMake 对源码的设置
# ${PROJECT_SOURCE_DIR} 和 ${PROJECT_BINARY_DIR} 是cmake定义的？是的，是cmake内置宏变量
# CMAKE_SOURCE_DIR 是一个cmake内置变量，指定了CMakeLists.txt的目录
configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )

# 是否加入 MathFunctions 库
if (USE_MYMATH)
  include_directories ("${PROJECT_SOURCE_DIR}/math") # 这个是添加头文件
  add_subdirectory (math) # 这个是添加源码子目录，或者模块子目录，里面有CMakeLists.txt
  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions) # 定义变量EXTRA_LIBS，它的值是MathFunctions
endif (USE_MYMATH)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 指定生成目标
add_executable (Demo ${DIR_SRCS})
target_link_libraries (Demo  ${EXTRA_LIBS})
