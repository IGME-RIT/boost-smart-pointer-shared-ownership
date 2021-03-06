// BoostSmartPointerSharedOwnership.cpp : Defines the entry point for the console application.
//

#define BOOST_SP_USE_QUICK_ALLOCATOR
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/shared_array.hpp>
#include <iostream>
#include <ctime>

int main()
{
	boost::shared_ptr<int> p1{ new int{1} };
	std::cout << *p1 << std::endl;
	boost::shared_ptr<int> p2{ p1 };
	p1.reset(new int{ 2 });
	std::cout << *p1.get() << std::endl;
	p1.reset();
	std::cout << std::boolalpha << static_cast<bool>(p2) << std::endl;

	auto px1 = boost::make_shared<int>(1);
	std::cout << typeid(px1).name() << std::endl;
	auto px2 = boost::make_shared<int[]>(10);
	std::cout << typeid(p2).name() << std::endl;

	boost::shared_array<int> pa1{ new int[1] };
	boost::shared_array<int> pa2{ pa1 };
	pa2[0] = 1;
	std::cout << pa1[0] << std::endl;

	boost::shared_ptr<int> pt;
	std::time_t then = std::time(nullptr);
	std::cout << then << std::endl;
	for (int i = 0; i < 1000000; ++i)
		pt.reset(new int{ i });
	std::time_t now = std::time(nullptr);
	std::cout << now << std::endl;
	std::cout << now - then << std::endl;

	//std::cin.get();

	return 0;
}

