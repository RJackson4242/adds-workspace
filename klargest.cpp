#include <vector>
#include <queue>

using namespace std;

int kth_largest(vector<int> values, int k)
{
    priority_queue queue = priority_queue<int>(values.begin(), values.end());
    for (int i = 1; i < k; i++)
    {
        queue.pop();
    }
    return queue.top();
}