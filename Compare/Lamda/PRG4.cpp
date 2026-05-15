#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Min-heap comparator
    auto cmp = [](int a, int b)
    {
        return a > b; // smallest element has highest priority
    };

    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.push(1);

    cout << "Min-heap order: ";
    while (!pq.empty())
    {
        cout << pq.top() << " "; // 1 2 5 8
        pq.pop();
    }
    cout << "\n";
    return 0;
}
