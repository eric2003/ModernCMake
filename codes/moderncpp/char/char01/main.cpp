#include <iostream>

void foo(char *in)
{
    printf("%s\n",in);
}

void bar(const char* in)
{
    printf("%s\n", in);
}

int main ( int argc, char **argv )
{
    {
        foo("haha");
        foo(const_cast<char*>("haha"));
    }
    {
        bar("haha");
    }

    return 0;
}
