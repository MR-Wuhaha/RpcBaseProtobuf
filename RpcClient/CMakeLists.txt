cmake_minimum_required(VERSION 2.8)

set(SRCS
    Channel.cpp
    Epoll.cpp
    main.cpp
    otherFun.cpp
    RpcClient.cpp
    protoFile/add.pb.cc
)

find_package(Protobuf)
set(_PROTOBUF_LIBPROTOBUF protobuf::libprotobuf)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall -Wno-unused-variable -pthread")
add_executable(RpcClient ${SRCS})
target_link_libraries(RpcClient ${_PROTOBUF_LIBPROTOBUF})