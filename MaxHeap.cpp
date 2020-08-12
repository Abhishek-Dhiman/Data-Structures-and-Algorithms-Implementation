#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int INF = (int)1e18;
class MaxHeap
{
private:
    vector <int> v;
    void max_heapify(int idx)
    {
        while (idx < v.size())
        {
            int left_child_val = -1, right_child_val = -1;
            if (2 * idx < v.size())
                left_child_val = v[2 * idx];
            if (2 * idx + 1 < v.size())
                right_child_val = v[2 * idx + 1];

            int largest = max(left_child_val, right_child_val);

            if (largest == -1)
                break;
            else if (largest == left_child_val)
            {
                swap(v[idx], v[2 * idx]);
                idx = 2 * idx;
                max_heapify(idx);
            }
            else if (largest == right_child_val)
            {
                swap(v[idx], v[2 * idx + 1]);
                idx = 2 * idx + 1;
                max_heapify(idx);
            }
        }
    }
public:
    MaxHeap()
    {
        v.pb(-INF);
    }
    void push_to_heap(int val)
    {
        v.pb(val);
        int idx = v.size() - 1;
        int par = idx / 2;

        while (v[idx] > v[par] && idx > 1)
        {
            swap(v[idx], v[par]);
            idx = par;
            par = par / 2;
        }
    }
    void pop_from_heap()
    {
        if (v.size() == 0 || v.size() == 1)
        {
            cout << "No elements are present in heap" << "\n";
            return;
        }
        int end = v.size() - 1;
        swap(v[1], v[end]);
        v.pop_back();
        max_heapify(1);
    }
    void display()
    {
        if (v.size() == 1)
        {
            cout << "No elements are present in heap" << "\n";
            return;
        }
        for (int i = 1; i < v.size(); i++)
            cout << v[i] << " ";
        cout << "\n";
    }
    int extract_max()
    {
        return v[1];
    }
};
int main() {
    // User input
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    MaxHeap hobj;
    for (int i = 0; i < n; i++)
    {
        hobj.push_to_heap(a[i]);
    }

    cout << hobj.extract_max() << "\n";
    hobj.display();
    hobj.pop_from_heap();
    hobj.display();
    hobj.pop_from_heap();
    hobj.display();
    return 0;
}
