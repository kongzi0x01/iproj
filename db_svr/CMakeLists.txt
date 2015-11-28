CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(db_svr CXX)

set(CMAKE_CXX_COMPILER g++)

SET(NAME db_svr)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/../framework)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/main)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/../protocol/inc)

# 生成的二进制文件输出目录
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/)

# RELEASE版本编译选项
SET(CMAKE_CXX_FLAGS "-g -DLOGGER" )

# 源文件搜索
FILE(GLOB SourceFiles  
"${PROJECT_SOURCE_DIR}/../framework/*.cpp"
"${PROJECT_SOURCE_DIR}/main/*.cpp"
"${PROJECT_SOURCE_DIR}/../protocol/inc/*.cc"
)

#生成可执行文件
ADD_EXECUTABLE(${NAME} ${SourceFiles})

TARGET_LINK_LIBRARIES(${NAME} "/usr/local/lib/libprotobuf.a")
TARGET_LINK_LIBRARIES(${NAME} "/usr/local/lib/libprotoc.a")
TARGET_LINK_LIBRARIES(${NAME} "/usr/local/lib/liblog4cplus.so")
