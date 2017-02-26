

#include <iostream> 

using namespace std; 

int strlen(const char text[]) 

{ 

    int Length=0; 

    for(;;Length++) 

    { 

        if(text[Length] == 0) 

        {  

            return Length;  

        }  

    }  

}  

void strcpy(char to[], const char from[])  

{  

    for(int i=0;;i++)  

    {  

        if(from[i]=='\0')  

        {  

            to[i]=from[i];  

            break;  

        }  

        else  

        {  

            to[i]=from[i];  

        }  

    }  

}  

void strcat(char to[], const char from[])  

{  

    int Length=strlen(to);  

    strcpy(to+Length,from);  

}  

int strcmp(const char s1[], const char s2[])  

{  

    int Length1=strlen(s1);  

    int Length2=strlen(s2);  

    if(0==Length1 && 0==Length2)  

    {  

        return 0;  

    }  

    else if(0==Length1)  

    {  

        return -1;  

    }  

    else if(0==Length2)  

    {  

        return 1;  

    }  

    else  

    {  

        int min=Length1<Length2?Length1:Length2;  

        for(int i=0;i<min;i++)  

        {  

            if((int)s1[i] < (int)s2[i])  

                return -1;  

            else if((int)s1[i] > (int)s2[i])  

                return 1;  

        }  

        if(Length1<Length2)  

            return -1;  

        else if(Length1 >Length2)  

            return 1;  

        else  

            return 0;  

    }  

}  

void find(char *file, char*toFind)  

{  

    char buffer[256];  

    int lenBuffer=0;  

    int lenFile=strlen(file);  

    int lenToFind=strlen(toFind);  

    int i=0;  

    int line=1;  

    int col=0;  

    while(lenToFind<=lenFile-i)  

    {  

        if(file[i]=='\n')  

        {  

            col=0;  

            line++;  

        }  

        else  

        {  

            col++;  

            int j=0;  

            for(;j<lenToFind;j++)  

            {  

                buffer[j]=file[i+j];  

            }  

            buffer[j]='\0';  

            int cmp=strcmp(buffer,toFind);  

            if(cmp==0)  

            {  

                cout  <<"line = "<<line<<", ch = "<<col<<endl;  

            }  

            lenBuffer=0;
  

        } 

    i++; 

    } 

} 
#include <iostream> 
using namespace std; 
 
int main() { 
    char file[] = "Welcome to CentOS\n\n\ 
The Community ENTerprise Operating System\n\n\ 
CentOS is an Enterprise-class Linux Distribution derived from sources freely provided to \ 
the public by a prominent North American Enterprise Linux vendor. CentOS conforms fully with \ 
the upstream vendors redistribution policy and aims to be 100% binary compatible. (CentOS mainly \ 
changes packages to remove upstream vendor branding and artwork.)\n\n\ 
CentOS is developed by a small but growing team of core developers.  In turn the core developers \ 
are supported by an active user community including system administrators, network administrators, \ 
enterprise users, managers, core Linux contributors and Linux enthusiasts from around the world.\n\n\ 
CentOS has numerous advantages including: an active and growing user community, quickly rebuilt, \ 
tested, and QA'ed errata packages, an extensive mirror network, developers who are contactable and \ 
responsive reliable Enterprise Linux class distribution, multiple free support avenues including \ 
a wiki, IRC Chat, Email Lists, Forums, and a dynamic FAQ.\n\n"; 
 
    char toFind[100]; 
    cin >> toFind; 
    find(file, toFind); 
} 
     
