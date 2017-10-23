#include <cstdlib>
#include <vector>
#include <list>
using namespace std;
int CustomerNum = 0;
int Totaltime = 0;
struct T_en {
    int OccurTime;
    int NType;
};
struct T_node {
    int ArrivalTime;
    int Durtation;
};
list<T_en> ev;
vector<list<T_node>> q;
void OpenForday() {
  T_en en;
  en.OccurTime = 0;
  en.NType = 0; //设定第一个事件(客户到达事件);
  ev.push_back(en);
}
void CustomerArrived() //客户到达处理模块
{
  T_en en;
  en.NType = 0;
  CustomerNum++;
  int Durtime = random() % 20;
  int intertime = random() % 10;
  auto t=en.OccurTime+intertime;
  InsertList(ev, (t, 0));
  i = Minimum(q);
  Enqueue(q[i], (en.OccurTime, Durtime)); // 入队
  if (QueueLength(q[i])==1)
  InsertList(ev, (en.Occurtime + Durtime, i));
};
void CustomerDeparture() {
    i = en.NType;
DelQueue(q[i], Customer);
TotalTime = TotalTime + en.OccurTime - Customer.ArrivalTime;
if (!QueueEmpty(q[i])
{
  GetHead(q[i], Customer);
  InsertList(ev, (en.OccurTime + Customer.Durtation, i));
}
}
void BankSimulation() {
  OpenForday();
  while (!ev.empty()) {
      auto en = ev.front();
    ev.pop_front();
    if (en.NType == 0)
      CustomerArrived();
    else
      CustomerDeparture();
  }
}
