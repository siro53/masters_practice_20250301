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
struct Setup {
    Setup() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(15);
    }
} __Setup;
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

struct Solver {
    using D = double;

    int N; // 目的地の数
    int M; // 壁の数
    int sx, sy; // ドローンの初期位置
    D epsilon; // 風の影響（標準偏差）
    D delta; // 計測時の誤差（標準偏差）
    vector<pair<int, int>> targets; // 目的地
    vector<tuple<int, int, int, int>> walls; // 壁

    Solver() {}
    Solver(int N, int M, D epsilon, D delta, vector<pair<int, int>> targets, vector<tuple<int, int, int, int>> walls) {}

    D dist2(int x1, int x2, int y1, int y2) {
        D d1 = (D)(x1 - x2) * (x1 - x2);
        D d2 = (D)(y1 - y2) * (y1 - y2);
        return d1 + d2;
    }

    void get_path() {
        auto dp = make_vector<D>({1 << N, N}, LLINF);
        auto pre = make_vector<pair<int, int>>({1 << N, N}, {-1, -1});
        REP(i, N) {
            auto [tx, ty] = targets[i];
            dp[1 << i][i] = dist2(sx, sy, tx, ty);
        }
        REP(mask, 1 << N) REP(i, N) {
            auto [xi, yi] = targets[i];
            REP(j, N) {
                if(mask >> j & 1) continue;
                auto [xj, yj] = targets[j];
                auto d = dist2(xi, xj, yi, yj);
                int new_mask = mask | (1 << j);
                if(chmin(dp[new_mask][j], dp[mask][i] + d)) {
                    pre[new_mask][j] = {mask, i};
                }
            }
        }
        int now = (1 << N) - 1; 
    }

    void solve() {
    }
};

int main() {
    INT(N, M);
    DBL(epsilon, delta);
    INT(sx, sy);
    vector<pair<int, int>> targets(N);
    for(auto& [x, y] : targets) cin >> x >> y;
    vector<tuple<int, int, int, int>> walls(M);
    for(auto& [lx, ly, rx, ry] : walls) cin >> lx >> ly >> rx >> ry;

    Solver solver(N, M, epsilon, delta, targets, walls);
    solver.solve();
}