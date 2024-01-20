//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
//    string key {"QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm"};
//    string encrypted{}, decrypted{}, message{};
//    size_t i{};
//    
//    cout << "Enter the secret message: ";
//    getline(cin, message);
//    cout << endl;
//    
//    for(char value: message)
//    {
//        for(i=0;i<alphabet.length();i++)
//        {
//            if(value==alphabet.at(i))
//                encrypted += key.at(i);
//        }
//        
//    }
//    cout << "\nEncrypted message: " << encrypted << endl;
//    
//    for(char value: encrypted)
//    {
//        for(i=0;i<key.length();i++)
//        {
//            if(value==key.at(i))
//                decrypted += alphabet.at(i);
//        }
//    }
//    cout << "\nDecrypted message: " << decrypted << endl;
// 
//    return 0;
//}





//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
//    string key {"QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm"};
//    string encrypted{}, decrypted{}, message{};
//    size_t i{};
//    
//    cout << "Enter the secret message: ";
//    getline(cin, message);
//    
//    for(char value: message)
//    {
//        i = alphabet.find(value);
//        if(i != string::npos)
//            encrypted += key.at(i);
//        else
//            encrypted += value;
//    }
//    cout << "\nEncrypted message: " << encrypted << endl;
//    
//    for(char value: encrypted)
//    {
//        i = key.find(value);
//        if(i != string::npos)
//            decrypted += alphabet.at(i);
//        else
//            decrypted += value;
//    }
//    cout << "\nDecrypted message: " << decrypted << endl << endl;
// 
//    return 0;
//}






#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;
 
string reverse(const string& s)
  {
  string rev(s.rbegin(), s.rend());  
  return rev;
  }
  
void pyramid(string strNormal)
  {
  string strTemp;
  string strReverse = reverse(strNormal);
  for (size_t i = 0; i < strNormal.length(); i++){
    strTemp.assign(strNormal.size() -i, ' ');
    strTemp += strNormal.substr(0, i + 1);
    strTemp += strReverse.substr(strReverse.size() -i, i);
    cout << strTemp << endl;
    }
  }  
int main()  
  {
  string strNormal("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdef");
  pyramid(strNormal);
  return 0;
  }


