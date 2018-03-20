void myprint(char* msg, int len);

int choose(int a, int b)
{
    if(a >= b) {
        myprint("a >= b!\n", 9);
    }
    else {
        myprint("a < b!\n", 9);
    }
    return 0;
}
