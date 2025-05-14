#pragma optimize("O3")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

double PI = 3.14159265358979323846;
struct Point
{
    double x, y;
    bool isCircle;
};

Point p0; // first point
Point nextToTop(stack<Point> &S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}

void swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

double distSq(Point p1, Point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y);
}

// 0 --> p, q and r are collinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    double val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // collinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

// A function used by library function qsort() to sort an array of
// points with respect to the first point
int compare(const void *vp1, const void *vp2)
{
   Point *p1 = (Point *)vp1;
   Point *p2 = (Point *)vp2;

   // Find orientation
   int o = orientation(p0, *p1, *p2);
   if (o == 0)
     return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;

   return (o == 2)? -1: 1;
}

// Prints convex hull of a set of n points.
vector<Point> convexHull(vector<Point> points, int n)
{
   // Find the bottommost point
   double ymin = points[0].y, min = 0;
   for (int i = 1; i < n; i++)
   {
    double y = points[i].y;

     // Pick the bottom-most or choose the left
     // most point in case of tie
     if ((y < ymin) || (ymin == y &&
         points[i].x < points[min].x))
        ymin = points[i].y, min = i;
   }

   // Place the bottom-most point at first position
   swap(points[0], points[min]);

   // Sort n-1 points with respect to the first point.
   // A point p1 comes before p2 in sorted output if p2
   // has larger polar angle (in counterclockwise
   // direction) than p1
   p0 = points[0];
   sort(points.begin() + 1, points.end(), [](const Point &a, const Point &b) {
    int o = orientation(p0, a, b);
    if (o == 0)
        return distSq(p0, a) < distSq(p0, b);
    return o == 2;
    });


//    cout << "points order" << endl;
//    for (int i = 0; i < n; i++) {
//         cout << points[i].x << " " << points[i].y << endl;
//    }

   // If two or more points make same angle with p0,
   // Remove all but the one that is farthest from p0
   // Remember that, in above sorting, our criteria was
   // to keep the farthest point at the end when more than
   // one points have same angle.
   int m = 1; // Initialize size of modified array
   for (int i=1; i<n; i++)
   {
       // Keep removing i while angle of i and i+1 is same
       // with respect to p0
       while (i < n-1 && orientation(p0, points[i],
                                    points[i+1]) == 0)
          i++;


       points[m] = points[i];
       m++;  // Update size of modified array
   }

//    cout << "points order after removing angle" << endl;
//    for (int i = 0; i < m; i++) {
//         cout << points[i].x << " " << points[i].y << endl;
//    }

   vector<Point> v;
   if (m < 3) {
    return v;
   }
   // Create an empty stack and push first three points
   // to it.
   stack<Point> S;
   S.push(points[0]);
   S.push(points[1]);
   S.push(points[2]);

   // Process remaining n-3 points
   for (int i = 3; i < m; i++)
   {
      // Keep removing top while the angle formed by
      // points next-to-top, top, and points[i] makes
      // a non-left turn
      while (S.size()>1 && orientation(nextToTop(S), S.top(), points[i]) != 2)
         S.pop();
      S.push(points[i]);
   }

   // Now stack has the output points, print contents of stack
   while (!S.empty())
   {
       Point p = S.top();
       v.push_back(p);
       S.pop();
   }
   reverse(v.begin(), v.end());
   return v;
}
double arcLength(const Point& p1, const Point& p2, double radius) {
    double chordLength = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));

    double halfAngle = asin(min(1.0, chordLength / (2 * radius)));
    double angle = 2 * halfAngle;
    
    return radius * angle;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string str;
    cin >> str;

    vector<Point> points;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'C') {
            double radius = 0.5;
            double centerX = i + 0.5;
            double centerY = 0.5;
            int numPoints = 10000; 
        
            for (int j = 0; j < numPoints; j++) {
                double angle = 2 * PI * (j / (double)(numPoints - 1)); 
                double x = centerX + radius * cos(angle);
                double y = centerY + radius * sin(angle);
                points.push_back({x, y, true});
            }
            
            // // 4 points
            points.push_back({i + 0.0, 0.5, true});
            points.push_back({i + 0.5, 0.0, true});
            points.push_back({i + 1.0, 0.5, true});
            points.push_back({i + 0.5, 1.0, true});
        } else if (str[i] == 'S') {
            points.push_back({i + 0.0, 0.0, false});
            points.push_back({i + 1.0, 0.0, false});
            points.push_back({i + 1.0, 1.0, false});
            points.push_back({i + 0.0, 1.0, false});
        } else if (str[i] == 'T') {
            points.push_back({i + 0.0, 0.0, false});
            points.push_back({i + 0.5, (double) sqrt(3) / 2, false});
            points.push_back({i + 1.0, 0.0, false});
        }
    }

    vector<Point> v = convexHull(points, points.size());
    // cout << "v size : " << v.size() << endl;

    // for (int i = 0; i < v.size(); i++) {
    //     cout << v[i].x << " " << v[i].y << endl;
    // }

    double total = 0;
    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i].isCircle && v[i + 1].isCircle) {
            if (v[i].y == v[i + 1].y) {
                total += sqrt(pow(v[i].x - v[i + 1].x, 2) + pow(v[i].y - v[i + 1].y, 2)); 
            } else {
                total += arcLength(v[i], v[i + 1], 0.5);
            }
            

        } else {
            total += sqrt(pow(v[i].x - v[i + 1].x, 2) + pow(v[i].y - v[i + 1].y, 2)); 
        }
    }
    if (v[v.size() - 1].isCircle && v[0].isCircle) {
        total += arcLength(v[v.size() - 1], v[0], 0.5);
    } else {
        total += sqrt(pow(v[v.size() - 1].x - v[0].x, 2) + pow(v[v.size() - 1].y - v[0].y, 2)); 
    }
    cout << setprecision(10) << fixed << total << endl;

}