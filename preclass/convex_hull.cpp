#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


struct Point
{
    ll x, y;
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

ll distSq(Point p1, Point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y);
}

// 0 --> p, q and r are collinear
// 1 --> Clockwise
// 2 --> Counterclockwise
ll orientation(Point p, Point q, Point r)
{
    ll val = (q.y - p.y) * (r.x - q.x) -
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
   ll o = orientation(p0, *p1, *p2);
   if (o == 0)
     return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;

   return (o == 2)? -1: 1;
}

// Prints convex hull of a set of n points.
vector<Point> convexHull(vector<Point> points, int n)
{
   // Find the bottommost point
   int ymin = points[0].y, min = 0;
   for (int i = 1; i < n; i++)
   {
     int y = points[i].y;

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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Point> points;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        Point point = {x, y};
        points.push_back(point);
    }
    vector<Point> v = convexHull(points, n);

    if (v.size() < 3) {
        cout << 0 << "\n";
        return 0;
    }
    // printing area
    ll lsum = 0;
    ll rsum = 0;
    for (int i = 0; i < v.size() - 1; i++) {
        lsum += v[i].x * v[i + 1].y;
        rsum += v[i].y * v[i + 1].x;
    }
    lsum += v[v.size() - 1].x * v[0].y;
    rsum += v[v.size() - 1].y * v[0].x;

    cout <<  setprecision(10) << fixed << (double) (.5 * abs(lsum - rsum)) << "\n";
}