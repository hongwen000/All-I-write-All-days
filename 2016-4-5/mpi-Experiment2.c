void main(){
   int pid1=fork();
   printf("**1**\n");
   if(pid1==0){int pid2=fork();printf("**2**\n");}
   else printf("**3**\n");
}

