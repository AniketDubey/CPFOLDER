#include <iostream>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set                                       \
    tree<pair<int, int>, null_type, less<pair<int, int>>, \
         rb_tree_tag, tree_order_statistics_node_update>

int countPair(vector<int> v, int sum)
{
    int ans = 0;

    ordered_set st;
    int y = 0;
    for (auto i = v.rbegin(); i != v.rend(); i++)
    {
        int num = *i;
        if (st.empty())
            st.insert({num, y});

        else
        {
            int left = sum - num;
            ans += st.order_of_key({left, -1});
            st.insert({num, y});
        }
        y++;
    }

    return ans;
}
int main()
{

    int n;
    cin >> n;

    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8};

    int sum = 7;

    cout << countPair(v, sum);

    return 0;
}
