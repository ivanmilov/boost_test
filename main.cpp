#include <iostream>
#define BOOST_THREAD_PROVIDES_FUTURE
#include <boost/thread.hpp>
#include <boost/thread/future.hpp>

using namespace std;

int int_no_param()
{
	static int s = 5;
	int k = s;
	s += 5;
	sleep(k);

	return k;
}

int main(int argc, char* argv[])
{
	std::vector<boost::shared_future<int>> futures;

	for (int i(0); i < 3; ++i)
		futures.push_back(boost::async(int_no_param));

	while (!futures.empty())
	{
		auto j = boost::wait_for_any(futures.begin(), futures.end());
		auto fut = *j;
		futures.erase(j);

		std::cout << fut.get() << '\n';
	}

	return 0;
}
