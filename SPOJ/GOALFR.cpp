#include <cmath>
#include <iostream>
#define eps 10e-10
#define sq(x) ((x)*(x))

using namespace std;

struct POINT {
	double x, y;
};

struct CIRCLE {
	POINT c;
	double r;
};

bool cross(POINT p1, POINT p2, CIRCLE p) {
	double a, b, c, d;
	POINT t;

	t.x = p2.x - p1.x;
	t.y = p2.y - p1.y;

	a = sq(t.x) + sq(t.y);
	b = 2.0 * (t.x * (p1.x - p.c.x) + t.y * (p1.y - p.c.y));
	c = sq(p.c.x) + sq(p.c.y);
	c += sq(p1.x) + sq(p1.y);
	c -= 2.0 * (p.c.x * p1.x + p.c.y * p1.y);
	c -= sq(p.r);
	d = b * b - 4 * a * c;
	if(fabs(a) < eps || d < -eps) return false;
	return true;
}

int main() {
	CIRCLE port;
	POINT raul, pus = {52.0, 3.66}, minu = {52.0, -3.66};
	int t;
	cin>>t;
	cout<<eps;
	while(t--) {
		cin>>raul.x>>raul.y>>port.c.x>>port.c.y>>port.r;
		if(cross(raul, pus, port) && cross(raul, minu, port)) cout<<"No goal...\n";
		else cout<<"Goal!\n";
	}
	return 0;
}
