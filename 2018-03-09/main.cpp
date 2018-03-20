#include "tcp_client.h"
int main()
{
    ClientInterface interface;
    int a;
    std::cin >> a;
    std::cout << "Starting Client" << std::endl;
    interface.startClient("lixinrui000.cn", "7568");
    while(1)
    {
        sleep(10);
    }
}
