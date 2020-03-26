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

#define DEBUG printf("\nPassing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
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

template <typename T, typename ContainerT>
T maximum(ContainerT &cont) {
    T best = *(cont.begin());
    for(T x : cont) setmax(best, x);
    return best;
}

template <typename T, typename ContainerT>
T minimum(ContainerT &cont) {
    T best = *(cont.begin());
    for(T x : cont) setmin(best, x);
    return best;
}

template <typename T, typename ContainerT>
T maximum(ContainerT &cont, T best) {
    for(T x : cont) setmax(best, x);
    return best;
}

template <typename T, typename ContainerT>
T minimum(ContainerT &cont, T best) {
    for(T x : cont) setmin(best, x);
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

template<typename contT1, typename T1, typename contT2, typename T2>
vector<pair<T1,T2>> zip(contT1 &A, contT2 &B) {
    vector<pair<T1, T2>> ans;
    for(auto itA = A.begin(), itB = B.begin(); itA != A.end() && itB != B.end(); ++itA, itB)
        ans.push_back(make_pair(*itA, *itB));
    return ans;
}

template<typename A, typename B, typename cont>
pair<vector<A>, vector<B>> unzip(cont &T) {
    pair<vector<A>, vector<B>> ans;
    for(pair<A, B> x : T) {
        T.first.push_back(x.first);
        T.second.push_back(x.second);
    }
    return ans;
}

template<typename T>
vector<T> read_tab(int n) {
    vector<T> ans(n);
    for(int i = 0; i < n; ++i) cin >> ans[i];
    return ans;
}

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

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
