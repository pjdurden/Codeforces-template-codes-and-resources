#include <bits/stdtr1c++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// use ordered_set temp;  
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// find_by_order(returns pointer) ->*temp.find_by_order(int) (position int the ordered set)
// order_of_key(returns int)-> temp.order_of_key(int) (number of items smaller than current)
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

// ordered_multiset
struct ordered_multiset { // multiset supporting duplicating values in set
    int len = 0;
    const long long ADD = 1000010;
    const long long MAXVAL = 1000000010;
    unordered_map<long long, long long> mp; // hash = 96814
    tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> T;

    ordered_multiset() { len = 0; T.clear(), mp.clear(); }
    inline void clear(){
        len = 0;
        T.clear(), mp.clear();
    }

    inline void insert(int x){
        len++, x += MAXVAL;
        int c = mp[x]++;
        T.insert((x * ADD) + c); }

    inline void erase(int x){//erase only 1 x(not all x)
        x += MAXVAL;
        int c = mp[x];
        if(c) {
            c--, mp[x]--, len--;
            T.erase((x*ADD) + c); } }

        /// 1-based index, returns the K'th element in the treap, -1 if none exists
    inline long long kth(int k){
        if (k < 1 || k > len) return -1;
        auto it = T.find_by_order(--k);
        return ((*it) / ADD) - MAXVAL;
    } 

    inline int lower_bound(int x){      // Count of value <x in treap
        x += MAXVAL;
        int c = mp[--x];
        return (T.order_of_key((x*ADD)+c)); }

    inline int upper_bound(int x){      // Count of value <=x in treap
        x += MAXVAL;
        int c = mp[x];
        return (T.order_of_key((x*ADD)+c)); }

    inline int size() { return len; }   // Number of elements in treap
};



void solve()
{

}

int main()
{
	
}