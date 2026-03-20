#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>
using namespace std;

class Server
{
private:
	static int load = 0;

public:
	static int compute(long long A, long long B)
	{
		load += 1;
		if (A < 0)
		{
			throw std::invalid_argument("A is negative");
		}
		vector<int> v(A, 0);
		int real = -1, cmplx = sqrt(-1);
		if (B == 0)
			throw 0;
		real = (A / B) * real;
		int ans = v.at(B);
		return real + A - B * ans;
	}
	static int getLoad()
	{
		return load;
	}
};
int Server::load = 0;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		long long A, B;
		cin >> A >> B;

		/* Enter your code here. */
		try
		{
			int r = Server::compute(A, B);
			cout << r << endl;
		}
		catch (const bad_alloc &e)
		{
			cout << "Not enough memory" << endl;
		}
		catch (const exception &invArg)
		{
			cout << "Exception: " << invArg.what() << endl;
		}
		catch (...)
		{
			// Anything else
			cout << "Other Exception" << endl;
		}
	}
	cout << Server::getLoad() << endl;
	return 0;
}