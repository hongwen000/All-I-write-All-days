struct _struct 
{
    int x;
    struct 
    {
        int y, z;
    } nested;
}; 
int main()
{
//    struct _struct i= { .nested.y = 5, 6, .x = 1, 2 };
    int i=(1,2,4);
    return 0;

}
