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


struct Event {
    ll x, y1, y2;
    int type; // 1 = start, -1 = end

    Event(int x, int y1, int y2, int type)
        : x(x), y1(y1), y2(y2), type(type) {}

    bool operator<(const Event& other) const {
        return x < other.x;
    }
};

struct Interval {
    ll y1, y2;
    Interval(int y1, int y2) : y1(y1), y2(y2) {}
    ll length() const { return y2 - y1; }
};

struct Rectangle {
    ll x1, y1, x2, y2;
    Rectangle(int x1, int y1, int x2, int y2)
        : x1(x1), y1(y1), x2(x2), y2(y2) {}

    ll area() const {
        return (x2 - x1) * (y2 - y1);
    }

    Rectangle* intersect(const Rectangle& other) const {
        ll nx1 = max(this->x1, other.x1);
        ll ny1 = max(this->y1, other.y1);
        ll nx2 = min(this->x2, other.x2);
        ll ny2 = min(this->y2, other.y2);
        if (nx1 < nx2 && ny1 < ny2) {
            return new Rectangle(nx1, ny1, nx2, ny2);
        }
        return nullptr;
    }
};

vector<Interval> getUnionIntervals(const map<int, int>& yCount) {
    vector<Interval> intervals;
    int count = 0, start = -1;

    for (const auto& entry : yCount) {
        ll y = entry.first;
        if (count > 0 && start != -1 && y > start) {
            intervals.emplace_back(start, y);
        }
        count += entry.second;
        start = (count > 0) ? y : -1;
    }

    return intervals;
}

ll computeUnion(const vector<Rectangle>& rectangles) {
    vector<Event> events;
    for (const auto& rect : rectangles) {
        events.emplace_back(rect.x1, rect.y1, rect.y2, 1);
        events.emplace_back(rect.x2, rect.y1, rect.y2, -1);
    }

    sort(events.begin(), events.end());

    map<int, int> yCount;
    ll prevX = 0;
    ll result = 0;

    for (const auto& e : events) {
        int dx = e.x - prevX;
        if (dx > 0) {
            vector<Interval> unionIntervals = getUnionIntervals(yCount);
            for (const auto& in : unionIntervals) {
                result += dx * in.length();
            }
        }

        yCount[e.y1] += e.type;
        yCount[e.y2] -= e.type;
        prevX = e.x;
    }

    return result;
}

vector<Rectangle> intersectTwoLists(const vector<Rectangle>& A, const vector<Rectangle>& B) {
    vector<Rectangle> result;
    for (const auto& ra : A) {
        for (const auto& rb : B) {
            Rectangle* r = ra.intersect(rb);
            if (r != nullptr) {
                result.push_back(*r);
                delete r;
            }
        }
    }
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Rectangle> listA;
    vector<Rectangle> listB;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        Rectangle rect = Rectangle(x1, y1, x2, y2);
        listA.push_back(rect);
    }
    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        Rectangle rect = Rectangle(x1, y1, x2, y2);
        listB.push_back(rect);
    }

    vector<Rectangle> listT = listA;
    listT.insert(listT.end(), listB.begin(), listB.end());

    ll resultU = computeUnion(listT);

    vector<Rectangle> intersected = intersectTwoLists(listA, listB);
    ll resultI = computeUnion(intersected);
    cout << resultI << " " << resultU << "\n";
    return 0;
}