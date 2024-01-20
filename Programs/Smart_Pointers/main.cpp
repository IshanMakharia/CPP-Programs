#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Test {
private:
    int data;
public:
    Test() : data{0}  { cout << "Test constructor (" << data << ")" << endl; }
    Test(int data) : data{data}  { cout << "\tTest constructor (" << data << ")" << endl; }
    int get_data() const  { return data; }
    ~Test()  { cout << "\tTest destructor (" << data << ")" << endl; }
};

unique_ptr<vector<shared_ptr<Test>>> make() {
    return make_unique<vector<shared_ptr<Test>>> ();
}

void fill(vector<shared_ptr<Test>> &vec, int n) {
    int temp;
    for (int i=1; i<=n; i++) {
        cout << "Enter data point [" << i << "] : ";
        cin >> temp;
        vec.push_back(make_shared<Test>(temp));
    }
}

void display(const vector<shared_ptr<Test>> &vec) {
    cout << "\n==========Displaying Vector Data==========" << endl;
    for(const auto &values: vec) {
        cout << values->get_data() << endl;
    }
    cout << "=======================================" << endl;
}

int main() {
    unique_ptr<vector<shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    cout << "How many data point do you want to enter: ";
    int n;
    cin >> n;
    fill(*vec_ptr, n);
    display(*vec_ptr);
    return 0;
}

