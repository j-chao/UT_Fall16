/* Name: 		Justin Chao
 * UT EID: 		jc55395
 * Course: 		Introduction to Scientific Programming
 * Assignment: 	Midterm Question 4: Squares and Lines
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

class Point {
    public:
        double x;
        double y;

        Point (double x, double y) : x(x), y(y) {};
        Point() : x(0), y(0) {};
        void printPoint () const {
            cout << "Point (" << x << ", " << y << ")" << endl;
        }
};

class Line : public Point {
    public:
		Point p1;
		Point p2;

		Line (const Point& p1, const Point& p2) : p1(p1), p2(p2) {}
        Line() : p1(0,0), p2(0,0) {};

		double getDistance (const Point& point1, const Point& point2) const {
			double dist = sqrt(pow((p2.x - p1.x),2) + pow((p2.y - p1.y),2));
			return dist;
		}
};

class Square: public Line {
    public:
        Line l1;

        Square (const Line& la1) 
        : l1(la1) {};

        double getArea (const Line& line1) const {
            double area = pow(line1.getDistance(p1, p2), 2);
            return area;
        }

        double getPerimeter (const Line& line1) const {
            double peri = line1.getDistance(p1, p2) * 4;
            return peri;
        }
};


int main() {
    printf ("\n ========================= PROGRAM START ========================= \n");
    double a, b, c, d;
    cout << "Enter (x, y) coordinates for Point A: " << endl;
    cin >> a >> b;
    cout << "Enter (x, y) coordinates for Point B: " << endl;
    cin >> c >> d;
    Point pa(a, b);
    Point pb(c, d);

    //make line from two points
    Line l1(pa, pb);

    double res = l1.getDistance(pa, pb);
    cout << " \nLength of line AB: " << res << endl;

    Point pc(a+res, b);
    Point pd(c+res, d);
    Point pe(c-res, d);
    Point pf(a-res, b);

    cout << " \nOther Points: " << endl;
    pa.printPoint();
    pb.printPoint(); pc.printPoint();
    pd.printPoint();
    pe.printPoint();
    pf.printPoint();

    printf ("\n\n ========================= PROGRAM END ========================= \n");
    return 0;
}
