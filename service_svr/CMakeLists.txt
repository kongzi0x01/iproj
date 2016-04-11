CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(service_svr CXX)

set(CMAKE_CXX_COMPILER g++)

SET(NAME service_svr)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/../framework)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/main)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/../protocol/inc)

# ???ɵĶ??????ļ?????Ŀ¼
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/)

# RELEASE?汾????ѡ??
SET(CMAKE_CXX_FLAGS "-g -DLOGGER" )

# Դ?ļ?????
FILE(GLOB SourceFiles  
"${PROJECT_SOURCE_DIR}/../framework/*.cpp"
"${PROJECT_SOURCE_DIR}/main/*.cpp"
"${PROJECT_SOURCE_DIR}/../protocol/inc/*.cc"
)

#???ɿ?ִ???ļ?
ADD_EXECUTABLE(${NAME} ${SourceFiles})

TARGET_LINK_LIBRARIES(${NAME} "/usr/local/lib/libprotobuf.a")
TARGET_LINK_LIBRARIES(${NAME} "/usr/local/lib/libprotoc.a")
TARGET_LINK_LIBRARIES(${NAME} "/usr/local/lib/liblog4cplus.so")
TARGET_LINK_LIBRARIES(${NAME} "libpthread.so")
TARGET_LINK_LIBRARIES(${NAME} "libevent.a")
