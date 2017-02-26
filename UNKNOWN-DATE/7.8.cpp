
#include <cstring> 


#include <iostream> 


#define INF  

using namespace std; 


int readLineDistinct(int array[], int max) 


{ 


 int _array[20];



 bool just_over_num=false; 


 int num=0; 


 int dit=0; 


 int count=0; 


 char ch; 


 while(cin.get(ch) && count < max) 


 { 


     if(ch==' ' || ch=='\t') 


     { 


         if(just_over_num==true) 


             count++; 


             just_over_num=false; 


         num=dit=0; 


         continue; 


     } 


     else if (ch=='\n') 


     { 


         if(just_over_num==true) 


             count++; 


             just_over_num=false; 


         break; 


     } 


     else 


     { 


         num*=10; 


         num+=(ch-48); 


         just_over_num=true; 


         _array[count]=num; 


     } 


 } 


 bool _vaild[count]; 


 for(int i=0;i<count;i++) 


     _vaild[i]=true; 


 for(int i=0;i<count;i++) 


 { 


     for(int j=i+1;j<count;j++) 


     { 


         if(_array[i]==_array[j]) 


             _vaild[j]=false; 


     } 


 } 


 int r_count=0; 


 for(int i=0;i<count;i++) 


 { 


     if(_vaild[i]) 


     { 


         array[r_count]=_array[i]; 


         r_count++; 


     } 


 } 


 return r_count; 


} 

void print(int data[], int length) { 
    for (int i = 0; i < length; ++ i) { 
        cout << data[i] << " "; 
    } 
    cout << endl; 
} 
 
int main() { 
    for (int i = 0; i < 2; ++ i) { 
        int data[10]; 
        int count = readLineDistinct(data, 10); 
        print(data, count); 
    } 
} 
