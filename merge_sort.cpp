#include <iostream>
#include <vector>
using namespace std;

vector <int> myArray;

void mergeSort(int left, int middle, int right)
{
    // create two temporary array
    vector <int> leftArray;
    vector <int> rightArray;
    int i, j, k;
    // insert left part in temp array
    for (i = left; i <= middle; i++)
        leftArray.push_back(myArray[i]);
    // insert right part in temp array
    for (i = middle+1; i <= right; i++)
        rightArray.push_back(myArray[i]);
    i = 0;
    j = 0;
    k = left;
    // compare left part with right part from temp array and update to input array
    while (i < leftArray.size() && j < rightArray.size())
        if (leftArray[i] <= rightArray[j])
            myArray[k++] = leftArray[i++];
        else
            myArray[k++] = rightArray[j++];
    // All other data is left in the array from left array
    while (i < leftArray.size())
        myArray[k++] = leftArray[i++];
    // All other data is left in the array from right array
    while (j < rightArray.size())
        myArray[k++] = rightArray[j++];
}

void mergeSortStyle(int left, int right)
{
    if (left == right) return;
    // divide array into two
    int middle;
    middle = left + (right - left) / 2;
    mergeSortStyle(left, middle); // array left part
    mergeSortStyle(middle+1, right); // array right part
    mergeSort(left, middle, right); // conquer array
}

void inputArray()
{
    cout << "Input array length (1 - 20) we will create a array automatically" << endl;
    int n, i;
    cin >> n;
    for (; n > 0; n--)
        myArray.push_back(rand() % 100);
}

void printArray()
{
    int i;
    for (i = 0; i < myArray.size(); i++)
        cout << myArray[i] << " ";
    cout << endl;
}

int main()
{
    inputArray();
    cout << "Unsorted array" << endl;
    printArray();
    mergeSortStyle(0, myArray.size() - 1);
    cout << "Sorted array" << endl;
    printArray();
    return 0;
}
