#pragma region Macros
#include <bits/stdc++.h>
using namespace std;
// input output utils
namespace siro53_io {
    // https://maspypy.github.io/library/other/io_old.hpp
    struct has_val_impl {
        template <class T>
        static auto check(T &&x) -> decltype(x.val(), std::true_type{});

        template <class T> static auto check(...) -> std::false_type;
    };

    template <class T>
    class has_val : public decltype(has_val_impl::check<T>(std::declval<T>())) {
    };

    // debug
    template <class T, enable_if_t<is_integral<T>::value, int> = 0>
    void dump(const T t) {
        cerr << t;
    }
    template <class T, enable_if_t<is_floating_point<T>::value, int> = 0>
    void dump(const T t) {
        cerr << t;
    }
    template <class T, typename enable_if<has_val<T>::value>::type * = nullptr>
    void dump(const T &t) {
        cerr << t.val();
    }
    void dump(__int128_t n) {
        if(n == 0) {
            cerr << '0';
            return;
        } else if(n < 0) {
            cerr << '-';
            n = -n;
        }
        string s;
        while(n > 0) {
            s += (char)('0' + n % 10);
            n /= 10;
        }
        reverse(s.begin(), s.end());
        cerr << s;
    }
    void dump(const string &s) { cerr << s; }
    void dump(const char *s) {
        int n = (int)strlen(s);
        for(int i = 0; i < n; i++) cerr << s[i];
    }
    template <class T1, class T2> void dump(const pair<T1, T2> &p) {
        cerr << '(';
        dump(p.first);
        cerr << ',';
        dump(p.second);
        cerr << ')';
    }
    template <class T> void dump(const vector<T> &v) {
        cerr << '{';
        for(int i = 0; i < (int)v.size(); i++) {
            dump(v[i]);
            if(i < (int)v.size() - 1) cerr << ',';
        }
        cerr << '}';
    }
    template <class T> void dump(const set<T> &s) {
        cerr << '{';
        for(auto it = s.begin(); it != s.end(); it++) {
            dump(*it);
            if(next(it) != s.end()) cerr << ',';
        }
        cerr << '}';
    }
    template <class Key, class Value> void dump(const map<Key, Value> &mp) {
        cerr << '{';
        for(auto it = mp.begin(); it != mp.end(); it++) {
            dump(*it);
            if(next(it) != mp.end()) cerr << ',';
        }
        cerr << '}';
    }
    template <class Key, class Value>
    void dump(const unordered_map<Key, Value> &mp) {
        cerr << '{';
        for(auto it = mp.begin(); it != mp.end(); it++) {
            dump(*it);
            if(next(it) != mp.end()) cerr << ',';
        }
        cerr << '}';
    }
    template <class T> void dump(const deque<T> &v) {
        cerr << '{';
        for(int i = 0; i < (int)v.size(); i++) {
            dump(v[i]);
            if(i < (int)v.size() - 1) cerr << ',';
        }
        cerr << '}';
    }
    template <class T> void dump(queue<T> q) {
        cerr << '{';
        while(!q.empty()) {
            dump(q.front());
            if((int)q.size() > 1) cerr << ',';
            q.pop();
        }
        cerr << '}';
    }

    void debug_print() { cerr << endl; }
    template <class Head, class... Tail>
    void debug_print(const Head &h, const Tail &...t) {
        dump(h);
        if(sizeof...(Tail)) dump(' ');
        debug_print(t...);
    }
    // print
    template <class T, enable_if_t<is_integral<T>::value, int> = 0>
    void print_single(const T t) {
        cout << t;
    }
    template <class T, enable_if_t<is_floating_point<T>::value, int> = 0>
    void print_single(const T t) {
        cout << t;
    }
    template <class T, typename enable_if<has_val<T>::value>::type * = nullptr>
    void print_single(const T t) {
        cout << t.val();
    }
    void print_single(__int128_t n) {
        if(n == 0) {
            cout << '0';
            return;
        } else if(n < 0) {
            cout << '-';
            n = -n;
        }
        string s;
        while(n > 0) {
            s += (char)('0' + n % 10);
            n /= 10;
        }
        reverse(s.begin(), s.end());
        cout << s;
    }
    void print_single(const string &s) { cout << s; }
    void print_single(const char *s) {
        int n = (int)strlen(s);
        for(int i = 0; i < n; i++) cout << s[i];
    }
    template <class T1, class T2> void print_single(const pair<T1, T2> &p) {
        print_single(p.first);
        cout << ' ';
        print_single(p.second);
    }
    template <class T> void print_single(const vector<T> &v) {
        for(int i = 0; i < (int)v.size(); i++) {
            print_single(v[i]);
            if(i < (int)v.size() - 1) cout << ' ';
        }
    }
    template <class T> void print_single(const set<T> &s) {
        for(auto it = s.begin(); it != s.end(); it++) {
            print_single(*it);
            if(next(it) != s.end()) cout << ' ';
        }
    }
    template <class T> void print_single(const deque<T> &v) {
        for(int i = 0; i < (int)v.size(); i++) {
            print_single(v[i]);
            if(i < (int)v.size() - 1) cout << ' ';
        }
    }
    template <class T> void print_single(queue<T> q) {
        while(!q.empty()) {
            print_single(q.front());
            if((int)q.size() > 1) cout << ' ';
            q.pop();
        }
    }

    void print() { cout << '\n'; }
    template <class Head, class... Tail>
    void print(const Head &h, const Tail &...t) {
        print_single(h);
        if(sizeof...(Tail)) print_single(' ');
        print(t...);
    }

    // input
    template <class T, enable_if_t<is_integral<T>::value, int> = 0>
    void input_single(T &t) {
        cin >> t;
    }
    template <class T, enable_if_t<is_floating_point<T>::value, int> = 0>
    void input_single(T &t) {
        cin >> t;
    }
    template <class T, typename enable_if<has_val<T>::value>::type * = nullptr>
    void input_single(T &t) {
        cin >> t;
    }
    void input_single(__int128_t &n) {
        string s;
        cin >> s;
        if(s == "0") {
            n = 0;
            return;
        }
        bool is_minus = false;
        if(s[0] == '-') {
            s = s.substr(1);
            is_minus = true;
        }
        n = 0;
        for(int i = 0; i < (int)s.size(); i++) n = n * 10 + (int)(s[i] - '0');
        if(is_minus) n = -n;
    }
    void input_single(string &s) { cin >> s; }
    template <class T1, class T2> void input_single(pair<T1, T2> &p) {
        input_single(p.first);
        input_single(p.second);
    }
    template <class T> void input_single(vector<T> &v) {
        for(auto &e : v) input_single(e);
    }
    void input() {}
    template <class Head, class... Tail> void input(Head &h, Tail &...t) {
        input_single(h);
        input(t...);
    }
}; // namespace siro53_io
#ifdef DEBUG
#define debug(...)                                                             \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]: ", debug_print(__VA_ARGS__)
#else
#define debug(...) (void(0))
#endif
// io setup
// struct Setup {
//     Setup() {
//         cin.tie(0);
//         ios::sync_with_stdio(false);
//         cout << fixed << setprecision(15);
//     }
// } __Setup;
using namespace siro53_io;
// types
using ll = long long;
using i128 = __int128_t;
// input macros
#define INT(...)                                                               \
    int __VA_ARGS__;                                                           \
    input(__VA_ARGS__)
#define LL(...)                                                                \
    ll __VA_ARGS__;                                                            \
    input(__VA_ARGS__)
#define STRING(...)                                                            \
    string __VA_ARGS__;                                                        \
    input(__VA_ARGS__)
#define CHAR(...)                                                              \
    char __VA_ARGS__;                                                          \
    input(__VA_ARGS__)
#define DBL(...)                                                               \
    double __VA_ARGS__;                                                        \
    input(__VA_ARGS__)
#define LD(...)                                                                \
    long double __VA_ARGS__;                                                   \
    input(__VA_ARGS__)
#define UINT(...)                                                              \
    unsigned int __VA_ARGS__;                                                  \
    input(__VA_ARGS__)
#define ULL(...)                                                               \
    unsigned long long __VA_ARGS__;                                            \
    input(__VA_ARGS__)
#define VEC(name, type, len)                                                   \
    vector<type> name(len);                                                    \
    input(name);
#define VEC2(name, type, len1, len2)                                           \
    vector name(len1, vector<type>(len2));                                     \
    input(name);
// other macros
// https://trap.jp/post/1224/
#define OVERLOAD3(_1, _2, _3, name, ...) name
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define REP1(i, n) for(int i = 0; i < int(n); i++)
#define REP2(i, a, b) for(int i = (a); i < int(b); i++)
#define REP(...) OVERLOAD3(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define SORT(v) sort(ALL(v))
#define RSORT(v) sort(RALL(v))
#define UNIQUE(v)                                                              \
    sort(ALL(v)), (v).erase(unique(ALL(v)), (v).end()), v.shrink_to_fit()
#define REV(v) reverse(ALL(v))
#define SZ(v) ((int)(v).size())
#define MIN(v) (*min_element(ALL(v)))
#define MAX(v) (*max_element(ALL(v)))
// util const
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
constexpr int MOD = 1000000007;
constexpr int MOD2 = 998244353;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
// util functions
void Case(int i) { cout << "Case #" << i << ": "; }
int popcnt(int x) { return __builtin_popcount(x); }
int popcnt(ll x) { return __builtin_popcountll(x); }
template <class T> inline bool chmax(T &a, T b) {
    return (a < b ? a = b, true : false);
}
template <class T> inline bool chmin(T &a, T b) {
    return (a > b ? a = b, true : false);
}
template <class T, int dim>
auto make_vector_impl(vector<int>& sizes, const T &e) {
    if constexpr(dim == 1) {
        return vector(sizes[0], e);
    } else {
        int n = sizes[dim - 1];
        sizes.pop_back();
        return vector(n, make_vector_impl<T, dim - 1>(sizes, e));
    }
}
template <class T, int dim>
auto make_vector(const int (&sizes)[dim], const T &e = T()) {
    vector<int> s(dim);
    for(int i = 0; i < dim; i++) s[i] = sizes[dim - i - 1];
    return make_vector_impl<T, dim>(s, e);
}
vector<int> iota_gen(int n, int start = 0) {
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), start);
    return ord;
}
template<typename T>
vector<int> ord_sort(const vector<T>& v, bool greater = false) {
    auto ord = iota_gen((int)v.size());
    sort(ALL(ord), [&](int i, int j) {
        if(greater) return v[i] > v[j];
        return v[i] < v[j];
    });
    return ord;
}
#pragma endregion Macros


namespace geometry {
    // Point : 複素数型を位置ベクトルとして扱う
    // 実軸(real)をx軸、挙軸(imag)をy軸として見る
    using D = long double;
    using Point = std::complex<D>;
    const D EPS = 1e-7;
    const D PI = std::acos(D(-1));

    inline bool equal(const D &a, const D &b) { return std::fabs(a - b) < EPS; }

    // 単位ベクトル(unit vector)を求める
    Point unitVector(const Point &a) { return a / std::abs(a); }

    // 法線ベクトル(normal vector)を求める
    // 90度回転した単位ベクトルをかける
    // -90度がよければPoint(0, -1)をかける
    Point normalVector(const Point &a) { return a * Point(0, 1); }

    // 内積(dot product) : a・b = |a||b|cosΘ
    D dot(const Point &a, const Point &b) {
        return (a.real() * b.real() + a.imag() * b.imag());
    }

    // 外積(cross product) : a×b = |a||b|sinΘ
    D cross(const Point &a, const Point &b) {
        return (a.real() * b.imag() - a.imag() * b.real());
    }

    // 点pを反時計回りにtheta度回転
    // thetaはラジアン！！！
    Point rotate(const Point &p, const D &theta) {
        return Point(std::cos(theta) * p.real() - std::sin(theta) * p.imag(),
                     std::sin(theta) * p.real() + std::cos(theta) * p.imag());
    }

    // ラジアン->度
    D radianToDegree(const D &radian) { return radian * 180.0 / PI; }

    // 度->ラジアン
    D degreeToRadian(const D &degree) { return degree * PI / 180.0; }

    // 点の回転方向
    // 点a, b, cの位置関係について(aが基準点)
    int ccw(const Point &a, Point b, Point c) {
        b -= a, c -= a;
        // 点a, b, c が
        // 反時計回りの時、
        if(cross(b, c) > EPS) return 1;
        // 時計回りの時、
        if(cross(b, c) < -EPS) return -1;
        // c, a, bがこの順番で同一直線上にある時、
        if(dot(b, c) < 0) return 2;
        // a, b, cがこの順番で同一直線上にある場合、
        if(std::norm(b) < std::norm(c)) return -2;
        // cが線分ab上にある場合、
        return 0;
    }

    // Line : 直線を表す構造体
    // b - a で直線・線分を表せる
    struct Line {
        Point a, b;
        Line() = default;
        Line(Point a, Point b) : a(a), b(b) {}
        // Ax+By=C
        Line(D A, D B, D C) {
            if(equal(A, 0)) {
                a = Point(0, C / B), b = Point(1, C / B);
            } else if(equal(B, 0)) {
                a = Point(C / A, 0), b = Point(C / A, 1);
            } else if(equal(C, 0)) {
                a = Point(0, C / B), b = Point(1, (C - A) / B);
            } else {
                a = Point(0, C / B), b = Point(C / A, 0);
            }
        }
    };

    // Segment : 線分を表す構造体
    // Lineと同じ
    struct Segment : Line {
        Segment() = default;

        Segment(Point a, Point b) : Line(a, b) {}
        D get_dist() { return std::abs(a - b); }
    };

    // Circle : 円を表す構造体
    // pが中心の位置ベクトル、rは半径
    struct Circle {
        Point p;
        D r;

        Circle() = default;

        Circle(Point p, D r) : p(p), r(r) {}
    };

    // 2直線の直交判定 : a⊥b <=> dot(a, b) = 0
    bool isOrthogonal(const Line &a, const Line &b) {
        return equal(dot(a.b - a.a, b.b - b.a), 0);
    }
    // 2直線の平行判定 : a//b <=> cross(a, b) = 0
    bool isParallel(const Line &a, const Line &b) {
        return equal(cross(a.b - a.a, b.b - b.a), 0);
    }

    // 点cが直線ab上にあるか
    bool isPointOnLine(const Point &a, const Point &b, const Point &c) {
        return isParallel(Line(a, b), Line(a, c));
    }

    // 点cが"線分"ab上にあるか
    bool isPointOnSegment(const Point &a, const Point &b, const Point &c) {
        // |a-c| + |c-b| <= |a-b| なら線分上
        return (std::abs(a - c) + std::abs(c - b) < std::abs(a - b) + EPS);
    }

    // 直線lと点pの距離を求める
    D distanceBetweenLineAndPoint(const Line &l, const Point &p) {
        return std::abs(cross(l.b - l.a, p - l.a)) / std::abs(l.b - l.a);
    }

    // 線分lと点pの距離を求める
    // 定義：点pから「線分lのどこか」への最短距離
    D distanceBetweenSegmentAndPoint(const Segment &l, const Point &p) {
        if(dot(l.b - l.a, p - l.a) < EPS) return std::abs(p - l.a);
        if(dot(l.a - l.b, p - l.b) < EPS) return std::abs(p - l.b);
        return std::abs(cross(l.b - l.a, p - l.a)) / std::abs(l.b - l.a);
    }

    // 直線s, tの交点の計算
    Point crossPoint(const Line &s, const Line &t) {
        D d1 = cross(s.b - s.a, t.b - t.a);
        D d2 = cross(s.b - s.a, s.b - t.a);
        if(equal(std::abs(d1), 0) && equal(std::abs(d2), 0)) return t.a;
        return t.a + (t.b - t.a) * (d2 / d1);
    }

    // 線分s, tの交点の計算
    Point crossPoint(const Segment &s, const Segment &t) {
        return crossPoint(Line(s), Line(t));
    }

    // 線分sと線分tが交差しているかどうか
    // bound:線分の端点を含むか
    bool isIntersect(const Segment &s, const Segment &t, bool bound) {
        return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) < bound &&
               ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) < bound;
    }

    // 線分sとtの距離
    D distanceBetweenSegments(const Segment &s, const Segment &t) {
        if(isIntersect(s, t, 1)) return (D)(0);
        D ans = distanceBetweenSegmentAndPoint(s, t.a);
        ans = std::min(ans, distanceBetweenSegmentAndPoint(s, t.b));
        ans = std::min(ans, distanceBetweenSegmentAndPoint(t, s.a));
        ans = std::min(ans, distanceBetweenSegmentAndPoint(t, s.b));
        return ans;
    }

    // 射影(projection)
    // 直線(線分)lに点pから引いた垂線の足を求める
    Point projection(const Line &l, const Point &p) {
        D t = dot(p - l.a, l.a - l.b) / std::norm(l.a - l.b);
        return l.a + (l.a - l.b) * t;
    }

    Point projection(const Segment &l, const Point &p) {
        D t = dot(p - l.a, l.a - l.b) / std::norm(l.a - l.b);
        return l.a + (l.a - l.b) * t;
    }

    // 反射(reflection)
    // 直線lを対称軸として点pと線対称の位置にある点を求める
    Point reflection(const Line &l, const Point &p) {
        return p + (projection(l, p) - p) * (D)2.0;
    }

    // 2つの円の交差判定
    // 返り値は共通接線の数
    int isIntersect(const Circle &c1, const Circle &c2) {
        D d = std::abs(c1.p - c2.p);
        // 2つの円が離れている場合
        if(d > c1.r + c2.r + EPS) return 4;
        // 外接している場合
        if(equal(d, c1.r + c2.r)) return 3;
        // 内接している場合
        if(equal(d, std::abs(c1.r - c2.r))) return 1;
        // 内包している場合
        if(d < std::abs(c1.r - c2.r) - EPS) return 0;
        return 2;
    }

    // 2つの円の交点
    std::vector<Point> crossPoint(const Circle &c1, const Circle &c2) {
        std::vector<Point> res;
        int mode = isIntersect(c1, c2);
        // 2つの中心の距離
        D d = std::abs(c1.p - c2.p);
        // 2円が離れている場合
        if(mode == 4) return res;
        // 1つの円がもう1つの円に内包されている場合
        if(mode == 0) return res;
        // 2円が外接する場合
        if(mode == 3) {
            D t = c1.r / (c1.r + c2.r);
            res.emplace_back(c1.p + (c2.p - c1.p) * t);
            return res;
        }
        // 内接している場合
        if(mode == 1) {
            if(c2.r < c1.r - EPS) {
                res.emplace_back(c1.p + (c2.p - c1.p) * (c1.r / d));
            } else {
                res.emplace_back(c2.p + (c1.p - c2.p) * (c2.r / d));
            }
            return res;
        }
        // 2円が重なる場合
        D rc1 = (c1.r * c1.r + d * d - c2.r * c2.r) / (2 * d);
        D rs1 = std::sqrt(c1.r * c1.r - rc1 * rc1);
        if(c1.r - std::abs(rc1) < EPS) rs1 = 0;
        Point e12 = (c2.p - c1.p) / std::abs(c2.p - c1.p);
        res.emplace_back(c1.p + rc1 * e12 + rs1 * e12 * Point(0, 1));
        res.emplace_back(c1.p + rc1 * e12 + rs1 * e12 * Point(0, -1));
        return res;
    }

    // 点pが円cの内部(円周上も含む)に入っているかどうか
    bool isInCircle(const Circle &c, const Point &p) {
        D d = std::abs(c.p - p);
        return (equal(d, c.r) || d < c.r - EPS);
    }

    // 円cと直線lの交点
    std::vector<Point> crossPoint(const Circle &c, const Line &l) {
        std::vector<Point> res;
        D d = distanceBetweenLineAndPoint(l, c.p);
        // 交点を持たない
        if(d > c.r + EPS) return res;
        // 接する
        Point h = projection(l, c.p);
        if(equal(d, c.r)) {
            res.emplace_back(h);
            return res;
        }
        Point e = unitVector(l.b - l.a);
        D ph = std::sqrt(c.r * c.r - d * d);
        res.emplace_back(h - e * ph);
        res.emplace_back(h + e * ph);
        return res;
    }

    // 点pを通る円cの接線
    // 2本あるので、接点のみを返す
    std::vector<Point> tangentToCircle(const Point &p, const Circle &c) {
        return crossPoint(c,
                          Circle(p, std::sqrt(std::norm(c.p - p) - c.r * c.r)));
    }

    // 円の共通接線
    std::vector<Line> tangent(const Circle &a, const Circle &b) {
        std::vector<Line> ret;
        // 2円の中心間の距離
        D g = std::abs(a.p - b.p);
        // 円が内包されている場合
        if(equal(g, 0)) return ret;
        Point u = unitVector(b.p - a.p);
        Point v = rotate(u, PI / 2);
        for(int s : {-1, 1}) {
            D h = (a.r + b.r * s) / g;
            if(equal(h * h, 1)) {
                ret.emplace_back(a.p + (h > 0 ? u : -u) * a.r,
                                 a.p + (h > 0 ? u : -u) * a.r + v);

            } else if(1 - h * h > 0) {
                Point U = u * h, V = v * std::sqrt(1 - h * h);
                ret.emplace_back(a.p + (U + V) * a.r,
                                 b.p - (U + V) * (b.r * s));
                ret.emplace_back(a.p + (U - V) * a.r,
                                 b.p - (U - V) * (b.r * s));
            }
        }
        return ret;
    }

    // 多角形の面積を求める
    D PolygonArea(const std::vector<Point> &p) {
        D res = 0;
        int n = p.size();
        for(int i = 0; i < n - 1; i++) res += cross(p[i], p[i + 1]);
        res += cross(p[n - 1], p[0]);
        return res * 0.5;
    }

    // 凸多角形かどうか
    bool isConvex(const std::vector<Point> &p) {
        int n = p.size();
        int now, pre, nxt;
        for(int i = 0; i < n; i++) {
            pre = (i - 1 + n) % n;
            nxt = (i + 1) % n;
            now = i;
            if(ccw(p[pre], p[now], p[nxt]) == -1) return false;
        }
        return true;
    }

    // 凸包 O(NlogN)
    std::vector<Point> ConvexHull(std::vector<Point> p) {
        int n = (int)p.size(), k = 0;
        std::sort(p.begin(), p.end(), [](const Point &a, const Point &b) {
            return (a.real() != b.real() ? a.real() < b.real()
                                         : a.imag() < b.imag());
        });
        std::vector<Point> ch(2 * n);
        // 一直線上の3点を含める -> (< -EPS)
        // 含め無い -> (< EPS)
        for(int i = 0; i < n; ch[k++] = p[i++]) { // lower
            while(k >= 2 &&
                  cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1]) < EPS)
                --k;
        }
        for(int i = n - 2, t = k + 1; i >= 0; ch[k++] = p[i--]) { // upper
            while(k >= t &&
                  cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1]) < EPS)
                --k;
        }
        ch.resize(k - 1);
        return ch;
    }

    // 多角形gに点pが含まれているか?
    // 含まれる:2, 辺上にある:1, 含まれない:0
    int isContained(const std::vector<Point> &g, const Point &p) {
        bool in = false;
        int n = (int)g.size();
        for(int i = 0; i < n; i++) {
            Point a = g[i] - p, b = g[(i + 1) % n] - p;
            if(imag(a) > imag(b)) swap(a, b);
            if(imag(a) <= EPS && EPS < imag(b) && cross(a, b) < -EPS) in = !in;
            if(cross(a, b) == 0 && dot(a, b) <= 0) return 1;
        }
        return (in ? 2 : 0);
    }

    // 凸多角形pを直線lで切断し、その左側を返す
    std::vector<Point> ConvexCut(std::vector<Point> p, Line l) {
        std::vector<Point> ret;
        int sz = (int)p.size();
        for(int i = 0; i < sz; i++) {
            Point now = p[i];
            Point nxt = p[i == sz - 1 ? 0 : i + 1];
            if(ccw(l.a, l.b, now) != -1) ret.emplace_back(now);
            if(ccw(l.a, l.b, now) * ccw(l.a, l.b, nxt) < 0) {
                ret.emplace_back(crossPoint(Line(now, nxt), l));
            }
        }
        return ret;
    }

} // namespace geometry
const int MAX_TURN = 5000;
using D = double;
int N, M;
int X; // 点の数
double eps, delta;
int sx, sy;
vector<int> px, py;
vector<int> lx, ly, rx, ry;
set<int> visited_p;
int c, h;
vector<bool> seen;
vector<tuple<char, int, int>> outputs; // 出力結果
void accelarate(int x, int y) {
  cout << "A " << x << ' ' << y << endl;
  outputs.push_back(make_tuple('A', x, y));
  return;
}
void survey(int x, int y) {
  cout << "S " << x << ' ' << y << endl;
  return;
}
D dist2(int x1, int x2, int y1, int y2) {
  D d1 = (D)(x1 - x2) * (x1 - x2);
  D d2 = (D)(y1 - y2) * (y1 - y2);
  return d1 + d2;
}
vector<int> get_order() {
  auto dp = make_vector<D>({1 << N, N}, LLINF);
  auto pre = make_vector<pair<int, int>>({1 << N, N}, {-1, -1});
  REP(i, N) {
      dp[1 << i][i] = dist2(sx, sy, px[i], py[i]);
  }
  REP(mask, 1 << N) REP(i, N) {
      int xi = px[i], yi = py[i];
      REP(j, N) {
          if(mask >> j & 1) continue;
          int xj = px[j], yj = py[j];
          auto d = dist2(xi, xj, yi, yj);
          int new_mask = mask | (1 << j);
          if(chmin(dp[new_mask][j], dp[mask][i] + d)) {
              pre[new_mask][j] = {mask, i};
          }
      }
  }
  int now_mask = (1 << N) - 1;
  int now_i = 0;
  D mn = LLINF;
  REP(i, N) if(chmin(mn, dp[(1 << N) - 1][i])) {
      now_i = i;
  }
  vector<int> ret = {now_i};
  while(1) {
      auto [pre_mask, pre_i] = pre[now_mask][now_i];
      now_mask = pre_mask;
      now_i = pre_i;
      if(now_i == -1) break;
      ret.push_back(now_i);
  }
  return ret;
}
void init() {
  cin >> N >> M >> eps >> delta;
  X = N + M + M + 1;
  cin >> sx >> sy;
  px.resize(N);
  py.resize(N);
  for(int i = 0; i < N; i++) {
    cin >> px[i] >> py[i];
  }
  lx.resize(M);
  ly.resize(M);
  rx.resize(M);
  ry.resize(M);
  for(int i = 0; i < M; i++) {
    cin >> lx[i] >> ly[i] >> rx[i] >> ry[i];
  }
}
int get_x(int i) {
  if(i < N) {
    return px[i];
  } else if(i < N + M) {
    return lx[i - N];
  } else if(i < N + M + M) {
    return rx[i - N - M];
  } else {
    return sx;
  }
}
int get_y(int i) {
  if(i < N) {
    return py[i];
  } else if(i < N + M) {
    return ly[i - N];
  } else if(i < N + M + M) {
    return ry[i - N - M];
  } else {
    return sy;
  }
}
const double inf = -1;
const double inf2 = 1e18;
vector<int> dijkstra(vector<vector<pair<int, double>>> &G, int s, int t) {
  vector<vector<int>> path(X, vector<int>{});
  priority_queue<tuple<double, int, vector<int>>, vector<tuple<double, int, vector<int>>>, greater<tuple<double, int, vector<int>>>> pq;
  pq.push(make_tuple(0, s, vector<int>{}));
  vector<double> dist(X, inf2);
  dist[s] = 0;
  while(!pq.empty()) {
    auto [c, u, vec] = pq.top();
    pq.pop();
    if(c > dist[u]) {
      continue;
    }
    for(auto [v, cost] : G[u]) {
      double nc = c + cost;
      if(nc < dist[v]) {
        dist[v] = nc;
        vector<int> nvec = vec;
        nvec.emplace_back(v);
        path[v] = nvec;
        pq.push(make_tuple(nc, v, nvec));
      }
    }
  }
  return path[t];
}

int main() {
  cin.tie(0); cout.tie(0);
  ios::sync_with_stdio(false);
  using D = double; 
  init();
  vector<vector<double>> dist(X, vector<double>(X, inf));
  for(int i = 0; i < X; i++) {
    for(int j = 0; j < X; j++) {
      auto s1 = geometry::Segment(
        geometry::Point(get_x(i), get_y(i)),
        geometry::Point(get_x(j), get_y(j))
      );
      bool is_cross = false;
      for(int k = 0; k < M; k++) {
        if((i >= N && i < N + M + M) && (k == i - N || k == i - N - M)) {
          continue;
        }
        auto s2 = geometry::Segment(
          geometry::Point(lx[k], ly[k]),
          geometry::Point(rx[k], ry[k])
        );
        if(geometry::isIntersect(s1, s2, false)) {
          is_cross = true;
        }
      }
      if(!is_cross) {
        dist[i][j] = hypot(get_x(i) - get_x(j), get_y(i) - get_y(j));
      }
    }
  }
  vector<vector<pair<int, double>>> G(X, vector<pair<int, double>>(X));
  for(int i = 0; i < X; i++) {
    for(int j = 0; j < X; j++) {
      if(i == j) {
        continue;
      }
      if(dist[i][j] < 0.1) {
        continue;
      }
      G[i].push_back(make_pair(j, dist[i][j]));
    }
  }
  // とりあえず順に訪問する。
  int x, y;
  int vx = 0, vy = 0;
  x = sx;
  y = sy;
  seen.assign(N, false);
  vector<pair<int, int>> targets(N + M + M);
  for(int i = 0; i < N; i++) {
    targets[i] = make_pair(px[i], py[i]);
  }
  for(int i = 0; i < M; i++) {
    targets[i + N] = make_pair(lx[i], ly[i]);
  }
  for(int i = 0; i < M; i++) {
    targets[i + N + M] = make_pair(rx[i], ry[i]);
  }
  targets.push_back(make_pair(sx, sy));
  auto orders = get_order();
  for(int i = 0; i < N; i++) {
    vector<int> order = i == 0 ? dijkstra(G, N + M + M, orders[0]) : dijkstra(G, orders[i], orders[i + 1]);
    reverse(order.begin(), order.end());

    cerr << orders[i] << ": ";
    for(int j = order.size() - 1; j >= 0; j--) {
        int k = order[j];
        cerr << "(" << get_x(k) << ", " << get_y(k) << ")," << " ";
    } 
    cerr << endl;
    
    while(!order.empty() && accumulate(seen.begin(), seen.end(), 0) < N && (int) outputs.size() < MAX_TURN) {
      assert(!order.empty());
      int tid = order.back();
      auto [tx, ty] = targets[tid];
      int nvx = tx - x;
      int nvy = ty - y;
      int ax = nvx - vx;
      int ay = nvy - vy;
      if(hypot(nvx, nvy) < 500) {
        order.pop_back();
        continue;
      }

      if((D)ax * ax + (D)ay * ay > 500 * 500) {
          D ok = 0, ng = 1;
          for(int _e = 0; _e < 200; _e++) {
              D mid = (ok + ng) / 2;
              D nax = D(ax) * mid, nay = D(ay) * mid;
              if(nax * nax + nay * nay <= 500 * 500) {
                  ok = mid;
              } else {
                  ng = mid;
              }
          }
          ax *= ok;
          ay *= ok;
      }
      accelarate(ax, ay);
      
      cin >> c >> h;
      if(h > 0) {
        for(int f = 0; f < h; f++) {
          int q;
          cin >> q;
          seen[q] = true;
        }
      }

      vx += ax;
      vy += ay;
      if(c == 1) {
        vx = 0, vy = 0;
      }
      x += vx;
      y += vy;
      // debug(x, y, vx, vy);
    }
  }

  return 0;
}