[[noreturn]] void f()
{
    throw "error";
    // OK
}
 
void q [[noreturn]] (int i)
{
    // behavior is undefined if called with an argument <= 0
    if (i > 0)
        throw "positive";
}
 
// void h() [[noreturn]]; // error: attribute applied to function type of h, not h itself
 
int main()
{
    try { f(); } catch(...) {}
    try { q(42); } catch(...) {}
}