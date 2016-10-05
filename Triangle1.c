#include<stdio.h>
#include<math.h>
int main(){
	int x1, x2, x3, y1, y2, y3, x0, y0;
	float s, s1, s2, s3, p, p1, p2, p3, a, b, c, l, m, n;
	scanf ("%d %d\n", &x1, &y1);
	scanf ("%d %d\n", &x2, &y2);
	scanf ("%d %d\n", &x3, &y3);
	scanf ("%d %d\n", &x0, &y0);
	a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	b = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
	c = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
	p = (a + b + c) / 2;
	l = sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
	m = sqrt((x0 - x2) * (x0 - x2) + (y0 - y2) * (y0 - y2));
	n = sqrt((x3 - x0) * (x3 - x0) + (y3 - y0) * (y3 - y0));
	p1 = (a + l + m) / 2;
	p2 = (m + b + n) / 2;
	p3 = (l + n + c) / 2;
	if ((((a + b) > c) && ((a + c) > b) && ((b + c) > a)) && ((m + l) > a) && ((m + n) > b) && ((n + l) > c)) {
		s = sqrt(p * (p - a) * (p - b) * (p - c));
		s1 = sqrt(p1 * (p1 - a) * (p1 - m) * (p1 - l));
		s2 = sqrt(p2 * (p2 - m) * (p2 - b) * (p2 - n));
		s3 = sqrt(p3 * (p3 - n) * (p3 - l) * (p3 - c));
		if (s == (s1 + s2 + s3)) {
			printf("YES\n");
		} 
		else {
    			printf("NO\n");
		} 
	} 
	return 0;
}
