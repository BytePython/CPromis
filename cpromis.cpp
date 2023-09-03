#include <boost/json/object.hpp>
#include <boost/json/serialize.hpp>
#include <cstddef>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/json/src.hpp>

using namespace std;
using namespace boost::json;


class Student
{
    public:
        std::string name;
        int id;
        Student(std::string name, int id){
            this->name = name;
            this->id = id;
        }
        void idPrint(){
            cout << id << endl;
        }
        value toJson(){
            value temp{{"name", name}, {"id", id}};
            return temp;
        }
};

Student fromJson(value j){
    object k{j.as_object()};
    std::string name = k["name"].as_string();

    Student a(k["name"],k["id"]);
    return
}

int writeJson(vector<Student> &students){
    fstream out;
    out.open("students.txt",ios::app);
    if(!out){
        return 1;
    }

    for(int i =0; i< students.size(); i++){
        out << serialize(students[i].toJson()) << '\n';
    }
    out.close();
    return 0;

};
vector<Student> readJson(){
    fstream in;
    in.open("students.txt");
    if(!in){
        in.close();
        throw "Failed to read";
    }
    std::string line;
    while(getline(in,line)){

    }
};





int main(){
    Student a("Jeff",123);
    value a_json = a.toJson();
    Student b("Jess",321);
    vector<Student> A{a,b};
    cout << a.name << '\n';
    a.idPrint();
    for(size_t i =0; i<A.size();i++){
        A[i].idPrint();
    }
    writeJson(A);
    #if 0
    std::string L{serialize(a_json)};
    value J{parse(L)};
    object K{J.as_object()};
    cout << K["name"] << "\n";
    #endif

    return 0;
}
