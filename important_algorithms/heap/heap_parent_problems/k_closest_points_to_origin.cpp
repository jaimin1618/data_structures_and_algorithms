#include<bits/stdc++.h>
using namespace std;
// Here KEY for making heap is SQRT(X^2 + Y^2) or distance from origin (0,0)
// {distance^2, {x,y}}, distance^2 to reduce calculation

class Point {
	int x, y;
public:
	Point(int a, int b): x(a), y(b) {};
	friend ostream& operator<<(ostream& out, const Point& p) {
		out << "(" << p.x << "," << p.y << ")";
		return out;
	}
	int get_x() const {
		return x;
	}
	int get_y() const {
		return y;
	}
};

using dist_point_pair = pair<int, Point>; // distance-Point, of course KEY is distance

vector<Point> KClosestPoints(const vector<Point>& points, int k) {
	priority_queue<dist_point_pair> maxH;

	for(const Point& point: points) {
		int dis = point.get_x() * point.get_x() + point.get_y() * point.get_y();
		pair<int, Point> p = make_pair<int,Point>(dis, point);
		maxH.push(p);
		if(maxH.size() > k) {
			maxH.pop();
		}
	}

	vector<Point> sol;
	while(!maxH.empty()) {
		auto p = maxH.top();
		Point point = p.second;
		sol.push_back(point);
	}

	return sol;
}

int main() {
	vector<Point> points = {
		{1, 2},
		{-2, 2},
		{5, 8},
		{0, 1}
	};
	int k = 2;


	return 0;
}