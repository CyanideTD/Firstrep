#include<iostream>
#include<fstream>
using namespace std;
typedef long long int ll;
bool miller(ll p, int iteration);
ll expmod(ll x, int n, int m);
int main() {
	ll n;
	ifstream in("hw2.dat");
	while (!in.eof())
	{
		in >> n;
		cout << n;
		if (miller(n, 5))
			cout << "    " << "true" << endl;
		else
			cout << "    " << "false" << endl;
	}
}
bool miller(ll p, int k) {
	ll s=0;
	if (p < 2)
	{
		return false;
	}
	if (p != 2 && p % 2 == 0)
	{
		return false;
	}
	ll d = p - 1;
	while (d % 2 == 0)
	{
		d /= 2;
		s++;
	}
	for (int i = 1; i <= k; i++)
	{
		ll a = rand() % (p - 3) + 1;
		ll x = expmod(a, d, p);
		if (x == 1 || x == p - 1)
			continue;
		for (int j = 1; j <= s - 1; j++)
		{
			x = (x*x)%p;
			if (x == 1)
				return false;
			if (x == p - 1)
				break;
		}
		if (x != 1 && x != p - 1)
		{
			return false;
		}
	}
	return true;
}
ll expmod(ll x, int n, int m) {
	ll a = 1;
	ll b = x;
	while (n > 0)
	{
		if (n % 2 == 1)
			a = (a*b) % m;
		b = (b*b) % m;
		n = n / 2;
	}
	return a%m;
}