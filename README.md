基于谷歌Protobuf实现的Rpc服务器
========================
## 使用前需要安装谷歌的protobuf包
1、使用谷歌的protobuf实现rpc请求<br>
2、在发送RPC请求与应答时，消息的格式为 **"方法名称 序列化后的protobuf消息"** <br>
3、用户创建RPC的方法需要在RpcServer/RPC/Service.cpp定义自己的方法名称和处理的逻辑，并在创建服务器时通过方法名称注册到服务器中；同时在RpcClient/RpcClient.cpp中定义相同名称的调用，同时在构造函数中注册到调用的方法中<br>
4、客户端与服务器端均使用非阻塞的socket，服务端采用reactor模型，通过时间轮管理长连接<br>
5、日志与线程池采用双缓冲队列实现写日志与线程任务的执行<br>
<br>

## 代码使用方法
cd RpcBaseProtobuf/RpcClient<br>
mkdir build<br>
cmake ..<br>
make<br>
<br>
cd RpcBaseProtobuf/RpcServer<br>
mkdir build<br>
cmake ..<br>
make<br>

### 启动服务器
cd RpcBaseProtobuf/RpcServer/build<br>
./Mserver<br>

### 启动客户端测试连接
cd RpcBaseProtobuf/RpcClient/build<br>
./RpcClient<br>

## 连接成功后RpcClient会输出调用结果<br>
## RpcServer会将调用写入RpcServer/Log/Server.txt中<br>