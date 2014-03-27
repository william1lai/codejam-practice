#include <iostream>

using namespace std;

typedef long long int64;

int main()
{
	int ncases;
	cin >> ncases;
	for (int i = 1; i <= ncases; i++)
	{
		int64 r, t;
		cin >> r >> t;

		int64 start = 2*r + 1;
		double final_ring_width = (-4 + sqrt(16.0 - 4.0*(-start*start + 4*start - 8*t)))/2.0;
		double ans = (final_ring_width - start)/4 + 1;
		cout << "Case #" << i << ": " << (int64)ans << "\n";
	}

	/* Derivation
	(s+e)*((e-s)/4)+1)/2 <= paint
	2*paint >= (s+e)*(.25e-.25s+1)
	8*paint >= (s+e)*(e-s+4)
	0 >= e^2 + 4e - s^2 + 4s - 8*paint
	e = (-4 + sqrt(16 - 4(-s^2 + 4s - 8*paint)))/2
	*/
	return 0;
}