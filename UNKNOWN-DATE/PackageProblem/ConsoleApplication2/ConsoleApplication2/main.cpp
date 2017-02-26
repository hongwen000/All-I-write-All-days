#include <cstdio>
class PositiveEffect1 {}; 
class PositiveEffect2 {}; 
class PositiveEffect3 {}; 
class PositiveEffect4 {};
class LimitationsDilemmas1 {};
class LimitationsDilemmas2 {};
class LimitationsDilemmas3 {};
class LimitationsDilemmas4 {};
class Essay1: PositiveEffect1, PositiveEffect2, PositiveEffect3, PositiveEffect4 {};
class Essay2: PositiveEffect2, LimitationsDilemmas2 {};
class Essay3: LimitationsDilemmas2, LimitationsDilemmas3 {};
class Essay4: PositiveEffect4, LimitationsDilemmas4 {};
class Essay5: LimitationsDilemmas1, LimitationsDilemmas2 {};
class Essay6: LimitationsDilemmas4 , PositiveEffect1 {};
int main()
{
    printf("hello from ConsoleApplication2!\n");
    return 0;
}