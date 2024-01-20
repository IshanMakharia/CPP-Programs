//#include <iostream>
//
//using namespace std;
//
//void read(int[], int&);
//void print(int[], int&);
//void apply_all(int[], int&, int[], int&);
//
//int main()
//{
//    int m, n;
//    cout << "Enter the size of array1: ";
//    cin >> m;
//    int arr1[m];
//    cout << "Enter the " << m << " elements of array1:" << endl;
//    read(arr1, m);
//    cout << "Enter the size array2: ";
//    cin >> n;
//    int arr2[n];
//    cout << "Enter the " << n << " elements of array2:" << endl;
//    read(arr2, n);
//    print(arr1, m);
//    print(arr2, n);
//    apply_all(arr1, m, arr2, n);
//}
//
//void read(int arr[], int &size){
//    for(int i=0; i<size; i++)
//        cin >> arr[i];
//}
//
//void print(int arr[], int &size){
//    cout << "\nArray:" << endl;
//    for(int i=0; i<size; i++)
//        cout << arr[i] << " ";
//    cout << endl;
//}
//
//void apply_all(int arr1[], int &m, int arr2[], int &n){
//    int i, j, k=0, arr3[m*n];
//    for(i=0; i<m; i++)
//    {
//        for(j=0; j<n; j++)
//        {
//            arr3[k] = arr1[i] * arr2[j];
//            //cout << arr3[k] << " ";
//            k++;
//        }
//    }
//    for(auto v: arr3)
//        cout << v << " ";
//    cout << endl;
//}




#include <iostream>

using namespace std;

void read(int*, const size_t&);
void print(const int *const, const size_t&);
int* apply_all(const int *const, const size_t&, const int *const, const size_t&);

int main()
{
    size_t m, n;
    cout << "Enter the size of array1: ";
    cin >> m;
    int arr1[m];
    cout << "Enter the " << m << " elements of array1:" << endl;
    read(arr1, m);
    cout << "Enter the size array2: ";
    cin >> n;
    int arr2[n];
    cout << "Enter the " << n << " elements of array2:" << endl;
    read(arr2, n);
    print(arr1, m);
    print(arr2, n);
    int *arr3 = apply_all(arr1, m, arr2, n);
    const size_t o{m*n};
    cout << "\nResult:";
    print(arr3, o);
    delete [] arr3;
    cout << endl;
    return 0;
}

void read(int *arr, const size_t &size){
    for(size_t i=0; i<size; i++)
        cin >> arr[i];
}

void print(const int *const arr, const size_t &size){
    cout << "\nArray: " << endl;
    cout << "[ ";
    for(size_t i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << "]";
    cout << endl;
}

int* apply_all(const int *const arr1, const size_t &m, const int *const arr2, const size_t &n){
    int *arr3{nullptr}, k{};
    arr3 = new int[m*n];
    for(size_t i=0; i<n; i++){
        for(size_t j=0; j<m; j++){
            arr3[k] = arr2[i] * arr1[j];
            k++;
        }
    }
    return arr3;
}