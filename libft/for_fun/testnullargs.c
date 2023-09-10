
int sum(int count, ...)
{
    int res = 0;
    __builtin_va_list args;
    __builtin_va_start(args,count);

    for(int i =0; i<count ;i++) res+= __builtin_va_arg(args,int);

    __builtin_va_end(args);
    return res;
    
}
int main()
{
    int su = sum(3,1111,5555,4444);   
}