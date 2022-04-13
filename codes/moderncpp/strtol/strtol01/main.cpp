#include <iostream>

int main ( int argc, char **argv )
{
    {
        char szNumbers[] = "2001 60c0c0 -1101110100110100100000 0x6fffff";
        char * pEnd;
        long int li1, li2, li3, li4;
        li1 = strtol (szNumbers,&pEnd,10);
        li2 = strtol (pEnd,&pEnd,16);
        li3 = strtol (pEnd,&pEnd,2);
        li4 = strtol (pEnd,NULL,0);
        std::cout << "The decimal equivalents are: ";
        std::cout <<  li1 << " ";
        std::cout <<  li2 << " ";
        std::cout <<  li3 << " ";
        std::cout <<  li4 << std::endl;

    }

    return 0;
}
