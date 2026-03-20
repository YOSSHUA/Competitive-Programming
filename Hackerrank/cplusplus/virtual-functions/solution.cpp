#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;
class Person
{
protected:
    int id;

protected:
    int uid;
    string name;
    int age;

public:
    virtual void getdata() = 0;
    virtual void putdata() = 0;
};

class Professor : public Person
{
private:
    static int uid;
    int publications;
    string cur_id;

public:
    int get_publications() { return publications; };
    void getdata()
    {
        string line;
        getline(std::cin, line); // read end of line
        getline(std::cin, line);
        // Create a string stream from the line
        istringstream iss(line);
        iss >> name >> age >> publications;
        id = this->uid++;
    };
    void putdata()
    {
        cout << name << " " << age << " " << publications << " " << id << '\n';
    }
};

int Professor::uid = 1;

class Student : public Person
{
private:
    static int uid;
    int marks[6];

public:
    int get_marks_sum()
    {
        int r = 0;
        for (int i = 0; i < 6; i++)
            r += marks[i];
        return r;
    }
    void getdata()
    {
        // cout << "Started student input\n";
        string line;
        getline(std::cin, line); // read end of line
        getline(std::cin, line);
        // Create a string stream from the line
        istringstream iss(line);
        iss >> name >> age;
        for (int i = 0; i < 6; i++)
            iss >> marks[i];
        id = this->uid++;
        // cout << "Finsihed student input" << name<<" " << age << " " << get_marks_sum()<< "\n";
    };
    void putdata()
    {
        cout << name << " " << age << " " << get_marks_sum() << " " << id << endl;
    }
};

int Student::uid = 1;

int main()
{

    int n, val;
    cin >> n; // The number of objects that is going to be created.
    Person *per[n];

    for (int i = 0; i < n; i++)
    {

        cin >> val;
        if (val == 1)
        {
            // If val is 1 current object is of type Professor
            per[i] = new Professor;
        }
        else
            per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.
    }

    for (int i = 0; i < n; i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;
}
