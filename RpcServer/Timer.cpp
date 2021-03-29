#include"Timer.h"
#include<functional>
#include<sys/time.h>
#include"Log.h"
Timer_node::Timer_node(channel* _Cha_Ptr,int time_out):
Cha_Ptr(_Cha_Ptr),Is_deleted(false)
{
    struct timeval now;
    gettimeofday(&now, NULL);
    // 以毫秒计
    //now.tv_sec代表秒，并且返回的是从1970年1月1日至今的秒数，now.tv_usec代表微妙
    Vail_time =
      (((now.tv_sec % 10000) * 1000) + (now.tv_usec / 1000)) + time_out;
}

bool Timer_node::Is_Vail()
{
    struct timeval now;
    gettimeofday(&now, NULL);
    // 以毫秒计
    int now_time =
      (((now.tv_sec % 10000) * 1000) + (now.tv_usec / 1000));
    return Vail_time < now_time;
}

bool Timer_node::Is_Delete()
{
    return Is_deleted;
}

void Timer_node::update(int time_out)
{
    Is_deleted = false;
    struct timeval now;
    gettimeofday(&now, NULL);
    // 以毫秒计
    Vail_time =
      (((now.tv_sec % 10000) * 1000) + (now.tv_usec / 1000)) + time_out;
}
Timer_node::~Timer_node()
{
    Cha_Ptr->Close();
    delete Cha_Ptr;
}

void Timer_node::set_delete()
{
    Is_deleted = true;
}

int Timer_node::get_fd()
{
    return Cha_Ptr->get_fd();
}

void Priority_queue::push(int fd,Time_Node_Ptr Node)
{
    Mqueue.push_back(Node);
    Mmap[fd] = Mqueue.size()-1;
    int index = Mqueue.size()-1;
    while(index > 0)
    {
        int pre_index = (index-1)/2;
        if(*Mqueue[pre_index] > *Mqueue[index])
        {
            Time_Node_Ptr temp = Mqueue[pre_index];
            Mqueue[pre_index] = Mqueue[index];
            Mqueue[index] = temp;
            Mmap[Mqueue[pre_index]->get_fd()] = pre_index;
            Mmap[Mqueue[index]->get_fd()] = index;
            index = pre_index;
        }
        else
        {
            break;
        }
    }
}

void Priority_queue::update(int fd)
{
    if(Mmap.count(fd) == 0)
    {
        return;
    }
    int index = Mmap[fd];
    while(index*2 + 1 < Mqueue.size())
    {
        int next_index = index*2+1;
        if(index*2+2 < Mqueue.size())
        {
            next_index = *Mqueue[index*2+1] < *Mqueue[index*2+2]?index*2+1:index*2+2;
        }
        if(*Mqueue[index] > *Mqueue[next_index])
        {
            Time_Node_Ptr temp = Mqueue[next_index];
            Mqueue[next_index] = Mqueue[index];
            Mqueue[index] = temp;
            Mmap[Mqueue[index]->get_fd()] = index;
            Mmap[Mqueue[next_index]->get_fd()] = next_index;
            index = next_index;
        }
        else
        {
            break;
        }
    }
}

void Priority_queue::pop()
{
    if(Mqueue.size() == 0)
    {
        return;
    }
    Mmap.erase(Mqueue.front()->get_fd());
    Mqueue.pop_front();
}

Timer_manager::Timer_manager()
{
    pthread_mutex_init(&Mutex,NULL);
}

void Timer_manager::add_node(Time_Node_Ptr new_node)
{
    Lock_Guard lock(Mutex);
    Timer_Que.push(new_node);
}

void* Timer_manager::handle_manage(void* ptr)
{
    Timer_manager* MT_manager = (Timer_manager*)(ptr);
    while(true)
    {
        Lock_Guard lock(MT_manager->Mutex);
        if(!MT_manager->Timer_Que.empty())
        {
            if(MT_manager->Timer_Que.top()->Is_Vail())
            {
                LOG<<"client fd: " + to_string(MT_manager->Timer_Que.top()->Cha_Ptr->get_fd()) + " time_out";
                //cout<<"client fd: "<<MT_manager->Timer_Que.top()->Cha_Ptr->get_fd()<<" time_out"<<endl;
                MT_manager->Timer_Que.pop();
            }
            else if(MT_manager->Timer_Que.top()->Is_Delete())
            {
                LOG<<"client fd: " + to_string(MT_manager->Timer_Que.top()->Cha_Ptr->get_fd()) + " client_has_closed";
                //cout<<"client fd: "<<MT_manager->Timer_Que.top()->Cha_Ptr->get_fd()<<" client_has_closed"<<endl;
                MT_manager->Timer_Que.pop();
            }
        }
        lock.unlock();
        sleep(1);
    }
}