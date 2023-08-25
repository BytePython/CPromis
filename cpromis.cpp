#include <cstddef>
#include <iostream>
#include <vector>



using namespace std;


class Student
{
    public:
        string name;
        int id;
        void idPrint(){
            cout << id << endl;
        }

};


int main(){
    Student a{"Jeff",123};
    Student b{"Jess",321};
    vector<Student> A{a,b};
    cout << a.name << endl;
    a.idPrint();

    for(size_t i =0; i<A.size();i++){
        A[i].idPrint();
    }


    return 0;
}
