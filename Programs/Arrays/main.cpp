#include<iostream>

using namespace std;

int main()
{
//    char vowel[]{'a','e','i','o','u'};
//    cout << "\nThe first vowel : " << vowel[0] << endl;
//    cout << "The last vowel : " << vowel[4] << endl;
//    
//    cin >> vowel[5];
//    cout << vowel << endl;

//   int a[]{10,20,30,40,50};
//   cout << a << endl;
   
//   int i = 10;
//   int j = i++ + ++i;
//   cout << j << endl;
   
//   int num{0};
//   num = 100.2;
//   cout << num << endl;   

//   int num1 = 5;
//   int num2 = 6;
//   cout << (num1 == num2) << endl;
//   cout << boolalpha;
//   cout << (num1 == num2) << endl;
   
//for(;;)
//cout << "answer:" << 5 + 5 * 5 - 5 / 5 << "\b\b\b\b\b\b\b\b\b";

    int a[100],i,n,j,temp;
    cout << "enter number of elements: ";
    cin >> n;
    cout << "enter the elements:";
    for(i=0;i<n;i++)
        cin >> a[i];
    cout << "\nUnsorted array:"<<endl;
    for(i=0;i<n;i++)
        cout << a[i] << endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    cout << "\nSorted array:" << endl;
    for(i=0;i<n;i++)
        cout << a[i] << endl;
    char ans;
    do{
    int key;
    bool found;
    cout << "enter the key to search:";
    cin >> key;
    for(i=0;i<n;i++)
    {
        if(key==a[i])
        {
            found = true;
            break;
        }
        else
            found = false;
    }
    cout << found << endl;
    cout << "do you want to search any other key(Y/N): ";
    cin>>ans;
    }while(ans != 'n' && ans!='N');
return 0;   
}