#include <stdio.h>

int infinityRecursion(const int number)
{
    int returning = 0;
    const int max  = 500;
    if (number > max)
    {
        infinityRecursion(number - 1);
    }
    else
    {
        returning = 1;
    }
    
    return returning;
}

int main()
{
    const int number = 10000000;
    infinityRecursion(number);

    return 0;

}
