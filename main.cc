//#define int long long
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <array>
#include <initializer_list>
#include <random>
#include <regex>
#include <tuple>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define fo(i,a,n) for (int i=a;i<n;i++)
#define of(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())

using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;
using LL = long long;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using PI = pair<int,int>;

template <typename T> void setmin(T& a, T b) { if (b < a) a = b; }
template <typename T> void setmax(T& a, T b) { if (b > a) a = b; }
template<class T>T sqr(T a){return a*a;}
template<class T,class T2>T mmin(T a,T2 b){return a<b?a:b;}
template<class T,class T2>T mmax(T a,T2 b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
#define min mmin
#define max mmax
#define abs aabs
LL gcd(LL a,LL b) { return b?gcd(b,a%b):a;}
const double EPS = 1e-8;

template <typename T>
typename T::value_type maximum(T &cont) {
    typename T::value_type best = *(cont.begin());
    for(typename T::value_type x : cont) setmax(best, x);
    return best;
}

template <typename T>
typename T::value_type maximum(T &cont, typename T::value_type best) {
    for(typename T::value_type x : cont) setmax(best, x);
    return best;
}

template <typename T>
typename T::value_type minimum(T &cont) {
    typename T::value_type best = *(cont.begin());
    for(typename T::value_type x : cont) setmin(best, x);
    return best;
}

template <typename T>
typename T::value_type minimum(T &cont, typename T::value_type best) {
    for(typename T::value_type x : cont) setmin(best, x);
    return best;
}

template <typename D>
D dPower(D base, LL exponent) {
    if (exponent < 0) {
        return dPower(1 / base, -exponent);
    }
    if (exponent == 0) {
        return 1;
    }
    if ((exponent & 1) == 1) {
        return dPower(base, exponent - 1) * base;
    } else {
        D res = dPower(base, exponent >> 1);
        return res * res;
    }
}

vector<int> range(int a, int b) {
    vector<int> tab;
    for(int i = a; i < b; ++i) tab.push_back(i);
    return tab;
}

vector<int> range(int n) {
    return range(0, n);
}

template<typename T1, typename T2>
vector<pair<T1,T2>> zip(vector<T1> &A, vector<T2> &B) {
    vector<pair<T1, T2>> ans;
    for(int i = 0; i < A.size() && i < B.size(); ++i)
        ans.push_back(make_pair(A[i], B[i]));
    return ans;
}

template<typename A, typename B>
pair<vector<A>, vector<B>> unzip(vector<pair<A, B>> &T) {
    pair<vector<A>, vector<B>> ans;
    for(pair<A, B> x : T) {
        T.first.push_back(x.first);
        T.second.push_back(x.second);
    }
    return ans;
}

template<typename A, typename B>
pair<B, A> rev(const pair<A,B> &p) {
    return make_pair(p.second, p.first);
}

template<typename A, typename B>
vector<pair<B, A>> rev(const vector<pair<A,B>> &T) {
    vector<pair<B, A>> ans;
    for(auto p : T) ans.push_back(make_pair(p.second, p.first));
    return ans;
}

template<typename T>
vector<T> read_tab(int n) {
    vector<T> ans(n);
    for(int i = 0; i < n; ++i) cin >> ans[i];
    return ans;
}

template<typename A, typename B>
vector<pair<A,B>> read_tab(int n) {
    vector<pair<A,B>> ans(n);
    for(int i = 0; i < n; ++i) cin >> ans[i].first >> ans[i].second;
    return ans;
}

template<typename T>
vector<vector<T>> read_matrix(int m, int n) {
    vector<vector<T>> mat(m, vector<T> (n));
    for(int i = 0; i < m; ++i)
    for(int j = 0; j < n; ++j)
        cin >> mat[i][j];
    return mat;
}

template<typename T>
vector<vector<T>> transpose(vector<vector<T>> &mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<T>> trans_mat(n, vector<T> (m));
    for(int i = 0; i < m; ++i)
    for(int j = 0; j < n; ++j)
        trans_mat[j][i] = mat[i][j];
    return trans_mat;
}

template<typename T>
vector<vector<T>> rotate(vector<vector<T>> &mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<T>> rot_mat(n, vector<T> (m));
    for(int i = 0; i < m; ++i)
    for(int j = 0; j < n; ++j)
        rot_mat[j][i] = mat[m-i][j];
    return rot_mat;
}

template<long long MOD>
struct ModInt
{
    long long x;
    ModInt() : x(0) { }
    ModInt(long long u) : x(u) { if (x >= MOD || x < 0) { x %= MOD; if (x < 0) x += MOD; } } 
    ModInt(const ModInt &m) : x(m.x) { }
    ModInt& operator=(const ModInt &m) { x = m.x; return *this; }
    friend bool operator==(const ModInt& a, const ModInt& b) { return a.x == b.x; }
    friend bool operator!=(const ModInt& a, const ModInt& b) { return a.x != b.x; }
    friend bool operator<(const ModInt& a, const ModInt& b) { return a.x < b.x; }
 
    ModInt& operator+=(const ModInt& m) { x += m.x; if (x >= MOD) x -= MOD; return *this; }
    ModInt& operator-=(const ModInt& m) { x -= m.x; if (x < 0) x += MOD; return *this; }
    ModInt& operator*=(const ModInt& m) { x = (x*m.x)%MOD; return *this; }    
 
    friend ModInt operator+(const ModInt& a, const ModInt &b) { return ModInt(a) += ModInt(b); }
    friend ModInt operator-(const ModInt& a, const ModInt &b) { return ModInt(a) -= ModInt(b); }
    friend ModInt operator*(const ModInt& a, const ModInt &b) { return ModInt(a) *= ModInt(b); }
 
    static long long fp(long long u, long long k) {
        if (k == 0) return 1;
        long long res = fp(u, k/2);
        res = (res*res) % MOD;
        if (k & 1) res = (res*u) % MOD;
        return res;
    }
 
    ModInt fastpow(long long k) { return ModInt(fp(x, k)); }
    ModInt inv() { return ModInt(fp(x, MOD-2)); }

    friend ostream& operator<<(ostream& os, const ModInt& v) {
        return (os << v.x);
    }
    friend istream& operator>>(istream& is, ModInt& v) {
        LL temp;
        is >> temp;
        v = ModInt(temp);
        return is;
    }

    ModInt& operator/=(const ModInt& m) { x = (x*fp(m.x, MOD - 2)) % MOD; return *this; }    
    friend ModInt operator/(const ModInt& a, const ModInt &b) { return ModInt(a) /= ModInt(b); }
};

template<typename C>
struct is_iterable {
  typedef long false_type;
  typedef char true_type;

  template<class T> static false_type check(...);
  template<class T> static true_type  check(int,
                    typename T::const_iterator = C().end());

  enum { value = sizeof(check<C>(0)) == sizeof(true_type) };
};

template <typename>
struct is_pair : std::false_type
{ };

template <typename T, typename U>
struct is_pair<std::pair<T, U>> : std::true_type
{ };

template<typename T> void print(T x);

template<class Tuple, std::size_t N>
struct TuplePrinter {
    static void print_tuple(const Tuple& t) 
    {
        TuplePrinter<Tuple, N-1>::print_tuple(t);
        std::cout << ",";
        print(std::get<N-1>(t));
    }
};

template<class Tuple>
struct TuplePrinter<Tuple, 1> {
    static void print_tuple(const Tuple& t) 
    {
        print(std::get<0>(t));
    }
};

template<class... Args>
void print(std::tuple<Args...>& t) {
    cout << "(";
    TuplePrinter<decltype(t), sizeof...(Args)>::print_tuple(t);
    cout << ")";
}

template<typename T>
void print(T x) {
    if constexpr (is_iterable<T>::value) {
        if constexpr (is_same<string, T>::value) {
            cout << '"' << x << '"';
        }
        else {
            cout << '[';
            bool fst = true;
            for(auto y : x) {
                if(!fst) cout << ',';
                fst = false;
                print(y);
            }
            cout << ']';
        }
    }
    else {
        if constexpr (is_pair<T>::value) {
            cout << '(';
            print(x.first);
            cout << ',';
            print(x.second);
            cout << ')';
        }
        else cout << x;
    }
}

template <typename T>
void prt(T x) {
    print(x);
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    set<int> se = {1,2,3};
    prt(se);
}
