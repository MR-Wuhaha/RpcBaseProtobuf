#ifndef _TIMER
#define _TIMER
#include<memory>
#include<queue>
#include<deque>
#include"channel.h"
#include<pthread.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
class Timer_node
{
    friend class Timer_manager;
    public:
        bool operator<(const Timer_node& other) const
        {
            return this->Vail_time < other.Vail_time;
        }
        bool operator>(const Timer_node& other) const
        {
            return this->Vail_time > other.Vail_time;
        }
        Timer_node(channel* Cha_Ptr,int time_out);
        ~Timer_node();
        bool Is_Vail();
        bool Is_Delete();
        void update(int time_out);
        void set_delete();
        int get_fd();
    private:
        bool Is_deleted;
        int Vail_time;
        channel* Cha_Ptr;
};
typedef shared_ptr<Timer_node> Time_Node_Ptr;
struct Timer_cmp
{
    bool operator()(const Time_Node_Ptr& t1,const Time_Node_Ptr& t2) const
    {
        return *t1 > *t2;
    }
};

//管理过期时间的优先队列，在更新的时候动态改变当前堆的位置，通过哈希表快速定位到节点并更新
//由于这个过程涉及到同个队列的更新操作，会出现大量的同步操作，降低并发，慎用
class Priority_queue
{
    private:
        unordered_map<int,int> Mmap;
        deque<Time_Node_Ptr> Mqueue;
    public:
        Priority_queue(){};
        void push(int fd,Time_Node_Ptr Node);
        void pop();
        void update(int fd);
};

class Timer_manager
{
    public:
        Timer_manager();
        ~Timer_manager();
        void add_node(Time_Node_Ptr new_ndoe);
        static void* handle_manage(void*);
        //void handle_manage();make
    private:
        pthread_mutex_t Mutex;
        priority_queue<Time_Node_Ptr,deque<Time_Node_Ptr>,Timer_cmp> Timer_Que;
};
#endif