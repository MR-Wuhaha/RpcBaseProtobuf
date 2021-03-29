cmake_minimum_required(VERSION 2.8)

set(SRCS
    channel.cpp
    Epoll.cpp
    Eventloop.cpp
    main.cpp
    otherFun.cpp
    Task.cpp
    ThreadPool.cpp
    Timer.cpp
    Log.cpp
    LogFile.cpp
    TimeRound.cpp
    RPC/RpcChannel.cpp
    RPC/Service.cpp
    RPC/protoFile/add.pb.cc
)
#find the protobuf path and dynamic lib file path
find_package(Protobuf)
set(_PROTOBUF_LIBPROTOBUF protobuf::libprotobuf)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall -Wno-unused-variable -pthread")
add_executable(Mserver ${SRCS})
target_link_libraries(Mserver ${_PROTOBUF_LIBPROTOBUF})