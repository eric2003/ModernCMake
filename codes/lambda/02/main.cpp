#include <iostream>

int main(int argc, char *argv[])
{
	auto f1 = [] {};
	f1();
	auto f2 = [] {
		std::cout << "hello\n";
	};
	auto f3 = [](int x) {
		std::cout << "x = " << x << std::endl;
	};
	f1();
	f2();
	f3(1);

	using fpt = void(*)(int x );
	fpt f4 = f3;
	f4(2);

	fpt f5 = [](int xx) {
		std::cout << "xx = " << xx << std::endl;
	};
	f5(2);

    return 0;
}