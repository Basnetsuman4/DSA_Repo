#include <iostream>
using namespace std;
#define Size 100


int arr1[Size], a, n, i, pos, up;

void input()
{
    cout << "Enter the size of array: " << endl;
    cin >> n;
    cout << "Enter the elements of array: " << endl;
    for (i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
}

void traverse_array()
{
    for (i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }
}


void insert_array()
{
    cout << "Enter the number you want to insert: " << endl;
    cin >> a;
    cout << "Enter the position at which element is to be inserted: " << endl;
    cin >> pos;
    for (i = n; i >= pos; i--)
    {
        arr1[i] = arr1[i - 1];
    }
    arr1[i] = a;
    n++;
    cout << "The new array is: " << endl;
    traverse_array();
}


void delete_array()
{
    cout << "Enter the position at which element is to be deleted: " << endl;
    cin >> pos;
    for (i = pos - 1; i < n - 1; i++)
    {
        arr1[i] = arr1[i + 1];
    }
    n--;
    cout << "The elements after deletion are: " << endl;
    traverse_array();
}


void update_array()
{
    cout << "Enter the number you want to update: " << endl;
    cin >> up;
    cout << "Enter the position at which element is to be updated: " << endl;
    cin >> pos;
    for (i = 0; i < n; i++)
    {
        if (i == pos)
        {
            arr1[i] = up;
        }
        cout << "The elements after update are: " << endl;
        for (i = 0; i < n; i++)
        {
            cout << arr1[i] << " ";
        }
    }
}


void merge_array()
{
    int m, j, arr2[Size];
    cout << "Enter the size of 2nd array" << endl;
    cin >> m;
    cout << "Enter the element of the array " << endl;
    for (i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    i = 0;
    for (j = n; j < n + m; j++)
    {

        arr1[j] = arr2[i];
        i++;
    }
    for (i = 0; i < n + m; i++)
    {
        cout << arr1[i] << " " << endl;
    }
}


int main()
{
    int c;
    cout << "Select the operation" << endl
         << "1. Insert" << endl
         << "2. Delete" << endl
         << "3. Traverse" << endl
         << "4. Update" << endl
         << "5. Merge" << endl;
    cin >> c;
    
    switch (c)
    {
    case 1:
        input();
        insert_array();
        break;
    
    case 2:
        input();
        delete_array();
        break;
    
    case 3:
        input();
        traverse_array();
        break;
    
    case 4:
        input();
        update_array();
        break;
    
    case 5:
        input();
        merge_array();
        break;
    
    default:
        cout << "Please select the correct input!!!" << endl;
        break;
    }
    return 0;
}