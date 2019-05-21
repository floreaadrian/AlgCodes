#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	static int x[1000001], y[1000001];
	int t, n;
	cin>>t;
	while(t--){
		cin>>n;
		for (int i = 0; i < n; i++)
			cin>>x[i]>>y[i];
		x[n] = x[0];
		y[n] = y[0];
		double cx = 0, cy = 0, area = 0;

		for (int i = 0; i < n; i++) {
			double w = x[i] * y[i+1] - x[i+1] * y[i];
			area += w;
			cx += w * (x[i] + x[i+1]) / 3;
			cy += w * (y[i] + y[i+1]) / 3;
		}

		cx /= area;
		cy /= area;
		if (fabs(cx) < 0.005 - 1e-9) cx = 0;
		if (fabs(cy) < 0.005 - 1e-9) cy = 0;
		cout<<fixed<<setprecision(2)<<cx + 1e-9 * (cx >= -1e-9 ? 1 : -1)<<" ";
		cout<<fixed<<setprecision(2)<<cy + 1e-9 * (cy >= -1e-9 ? 1 : -1)<<"\n";
	}
}
