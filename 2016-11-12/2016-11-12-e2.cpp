/* 
 
*Author:Choas Lee 
 
*Date:2012-02-28 
 
*/ 
 
#include<stdio.h> 
//#define UNIXEVN 
 
#if defined(UNIXENV) 
 
#include<sys/time.h> 
 
#endif 
 
#define N 1000000 
 
#define COE 1000000 
 
float add(float a,float b){return a+b;} 
 
float minus(float a,float b){return a-b;} 
 
float multiply(float a,float b){return a*b;} 
 
float divide(float a,float b){return a/b;} 
 
typedef float (*pf)(float,float); 
 
void switch_impl(float a,float b,char op) 
 
{ 
 
      float result=0.0; 
 
      switch(op) 
 
      { 
 
             case '+': 
 
                    result=add(a,b); 
 
                    break; 
 
             case '-': 
 
                    result=minus(a,b); 
 
                    break; 
 
             case '*': 
 
                    result=multiply(a,b); 
 
                    break; 
 
             case '/': 
 
                    result=divide(a,b); 
 
                    break; 
 
      } 
 
} 
 
void switch_fp_impl(float a,float b,pf p) 
 
{ 
 
      float result=0.0; 
 
      result=p(a,b); 
 
} 
 
int conversion(struct timeval tmp_time) 
 
{ 
 
      return tmp_time.tv_sec*COE+tmp_time.tv_usec; 
 
} 
 
int main() 
 
{ 
 
      int i=0; 
 
#if defined(UNIXENV) 
 
      struct timeval start_point,end_point; 
 
  
 
      gettimeofday(&start_point,NULL); 
 
#endif 
 
      for(i=0;i<N;i++) 
 
      { 
 
             switch_impl(12.32,54.14,'-'); 
 
      } 
 
#if defined(UNIXENV) 
 
      gettimeofday(&end_point,NULL); 
 
      printf("check point 1:%d\n",conversion(end_point)-conversion(start_point)); 
 
      
 
      gettimeofday(&start_point,NULL); 
 
#endif 
 
      for(i=0;i<N;i++) 
 
      { 
 
             switch_fp_impl(12.32,54.14,minus); 
 
      } 
 
#if defined(UNIXENV) 
 
      gettimeofday(&end_point,NULL); 
 
      printf("check point 2:%d\n",conversion(end_point)-conversion(start_point)); 
 
#endif 
 
      return 0; 
 
} 
