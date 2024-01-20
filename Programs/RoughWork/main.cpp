//#include <stdio.h>
//#include <string.h>
//
//
//int main()
//{
////    char c[13]= "hellomotto..";
////    printf("%s\n",c);
//
////    long long a{7'600'000'000};
////    printf("%lld\n",a);
//
//
//void *p{};
//char *c{};
//p = c;
//c = (char*)p;
//
//
//int a=5, b=4;
//
//printf("%d\n",a*=b);
//printf("%d\n",a=(a==b));
//printf("%d\n",a==b);
//
//
//}









//#include <iostream>
//#include <cstdlib>
//#include <pthread.h>
//
//using namespace std;
//
//#define NUM_THREADS 5
//
//void *PrintHello(void *threadid) {
//   long tid;
//   tid = (long)threadid;
//   cout << "Hello World! Thread ID, " << tid << endl;
//   pthread_exit(NULL);
//}
//
//int main () {
//   pthread_t threads[NUM_THREADS];
//   int rc;
//   int i;
//   
//   for( i = 0; i < NUM_THREADS; i++ ) {
//      cout << "main() : creating thread, " << i << endl;
//      rc = pthread_create(&threads[i], NULL, PrintHello, (void *)i);
//      
//      if (rc) {
//         cout << "Error:unable to create thread," << rc << endl;
//         exit(-1);
//      }
//   }
//   pthread_exit(NULL);
//}
//
//
//
//
//
//
//
//
//
////Live Demo
//#include <iostream>
//#include <ctime>
//
//using namespace std;
//
//int main() {
//   // current date/time based on current system
//   time_t now = time(0);
//   
//   // convert now to string form
//   char* dt = ctime(&now);
//
//   cout << "The local date and time is: " << dt << endl;
//
//   // convert now to tm struct for UTC
//   tm *gmtm = gmtime(&now);
//   dt = asctime(gmtm);
//   cout << "The UTC date and time is:"<< dt << endl;
//}


//#include<iostream>
//#include<vector>
////#include<climits>
////#include<cfloat>
//#include<string>
//using namespace std;
//int main()
//{
//    char a = 'a';
//    int i = 100000;
//    double j = 111937173.131736;
//    void *p{nullptr};
//    char *s{nullptr};
//    //p = static_cast<double*>(j);
//    int *p1{&i};
//    double *p2{&j};
//    vector<string> *p3{nullptr};
//    unsigned long long int *p4{nullptr};
//    cout << sizeof p1 << endl;
//    cout << sizeof p2 << endl;
//    cout << sizeof p3 << endl;
//    cout << sizeof p4 << endl;
//    cout << sizeof j << endl;
//    cout << p2 << endl;
//    cout << p << endl;
//    cout << sizeof(float) << endl;
//    cout <<  << endl;
//}

//#include <iostream>
//#include <string>  
//using namespace std;
//int main()  
//{  
////   int i;
////   int *pi = 0;
////   char *pc = 0;
////   void *pVoid{};
////
////   pVoid = pi;
////   pVoid = pc;
////
////   const int *pci = &i;	// pointer to const int
////   pVoid = const_cast<int *>(pci);		// error
////   
////   void *pvoid1;
////   char *j = static_cast<char*>(pvoid1);
//////   double *k = static_cast<double*>(j);
////   return 0;
//
//    int score[50] {100, 90, 80, 70, 60};
//    int *score_ptr {score};
//    string s{"ISHAN"};
//    char c{'I'};
//    int num{10};
//    int *j;
//    /*j = reinterpret_cast<int*>(num); //error    //or*/    j = (&num);
//    char *r{&c};
//    string *p{&s};
//    cout << p << "\t" << r << "\t" << j <<  endl;
//    cout << score << endl;
//    cout << *score << endl;
//    cout << score[0] << endl;
////    cout << *score[1] << endl;
//    cout << score_ptr + 1 << endl;
//    cout << (sizeof(score)/sizeof(score[0])) << endl;
//    size_t i;
//    for(i = 0; i<(sizeof(score)/sizeof(score[0])); i++)
//    {
//        if(score[i] == '\0')
//            break;
//    }
//    cout << i << endl;
//} 



#include <bits/stdc++.h> 
using namespace std; 
  
struct Queue { 
    stack<int> s1, s2; 
  
    void enQueue(int x) 
    { 
        // Move all elements from s1 to s2 
        while (!s1.empty()) { 
            s2.push(s1.top()); 
            s1.pop(); 
        } 
  
        // Push item into s1 
        s1.push(x); 
  
        // Push everything back to s1 
        while (!s2.empty()) { 
            s1.push(s2.top()); 
            s2.pop(); 
        } 
    } 
  
    // Dequeue an item from the queue 
    int deQueue() 
    { 
        // if first stack is empty 
        if (s1.empty()) { 
            cout << "Q is Empty"; 
            exit(0); 
        } 
  
        // Return top of s1 
        int x = s1.top(); 
        s1.pop(); 
        return x; 
    } 
}; 
  
// Driver code 
int main() 
{ 
    Queue q; 
    q.enQueue(1); 
    q.enQueue(2); 
    q.enQueue(3); 
  
    cout << q.deQueue() << '\n'; 
    cout << q.deQueue() << '\n'; 
    cout << q.deQueue() << '\n'; 
  
    return 0; 
} 