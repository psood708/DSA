#include <bits/stdc++.h>
using namespace std;

class heap
{
public:
    int arr[100];
    int size = 0;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void deletefromHeap()
    {
        if (size == 0)
        {
            cout << "nothing to delete" << endl;
            return;
        }
        // step 1: put last elment into first index
        arr[1] = arr[size];
        // step2: remove last index
        size--;

        // rake root node to its corrct position
        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex < size && arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
    }
};
void heapify(int arr[], int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i;      // left = 2*i
    int right = 2 * i + 1; // right = 2*i + 1

    // If left child is larger than root
    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    // If largest is not root
    if (largest != i)
    {
        swap(arr[largest], arr[i]); // Swap root with largest
        heapify(arr, n, largest);   // Recursively heapify the affected sub-tree
    }
}

void heapSort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        swap(arr[size], arr[1]);
        size--;

        heapify(arr, size, 1);
    }
}
// 40:10
int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deletefromHeap();
    cout << endl;
    h.print();

    priority_queue<int> pq;

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
    cout << "Printing th array now" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }

    heapSort(arr, n);

    cout << endl;
    cout << "Printing th sortd array now" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    pq.push(4);
    pq.push(10);
    pq.push(5);
    pq.push(3);
    pq.push(1);
    cout<<"Element at Top" << pq.top()<<endl;
    return 0;
}