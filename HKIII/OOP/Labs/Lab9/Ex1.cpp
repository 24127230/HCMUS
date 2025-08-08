#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Course {
protected:
    string courseName;
    int numberOfSessions;
    int tuitionPerSession;
public:
    Course(string name = "none", int numSesion = 0, int tuition = 0);
    ~Course();
    virtual int totalTuition() const = 0;
    virtual print() const = 0;
};
class StandardCourse : public Course
{
private:
public:
    StandardCourse(string name = "none", int numSesion = 0, int tuition = 0);
    ~StandardCourse();
    int totalTuition() const override;
    print() const override;
};
class AdvancedCourse : public Course
{
private:
    int expertSurcharge;
public:
    AdvancedCourse(string name = "none", int numSesion = 0, int tuition = 0, int surcharge = 0);
    ~AdvancedCourse();
    int totalTuition() const override;
    print() const override;
};


Course::Course(string name, int numSesion, int tuition) : courseName(name), numberOfSessions(numSesion), tuitionPerSession(tuition) {}
Course::~Course() {}
StandardCourse::StandardCourse(string name, int numSesion, int tuition) : Course(name, numSesion, tuition) {}
StandardCourse::~StandardCourse() {}
int StandardCourse::totalTuition() const {
    return numberOfSessions * tuitionPerSession * 1000;
}
StandardCourse::print() const {
    cout << "Standard" << setw(5) << "| ";
    cout << courseName << setw(27 - courseName.length()) << "| ";
    cout << "Sessions: " << numberOfSessions << setw(27) << "| " ;
    cout << totalTuition();
    cout << endl;
}
AdvancedCourse::AdvancedCourse(string name, int numSesion, int tuition, int surcharge) : Course(name, numSesion, tuition), expertSurcharge(surcharge) {}
AdvancedCourse::~AdvancedCourse() {}
int AdvancedCourse::totalTuition() const {
    return ((numberOfSessions * tuitionPerSession) * ((100 + expertSurcharge) / 100.0)) * 1000;
}
AdvancedCourse::print() const {
    cout << "Advanced" << setw(5) << "| ";
    cout << courseName << setw(27 - courseName.length()) << "| ";
    cout << "Sessions: " << numberOfSessions << ". Expert fee: " << expertSurcharge << "%" << setw(9) << "| " ;
    cout << totalTuition();
    cout << endl;
}
int main() {
    vector<Course*> courses = {
        new StandardCourse("Basic C++ Programming", 8, 250),
        new AdvancedCourse("Artificial Intelligence", 12, 500, 10),
        new StandardCourse("Web Design", 6, 300),
        new AdvancedCourse("Data Analytics", 10, 400, 15)
    };
    int totalTuitionAllCoures = 0;
    cout << "Type       | Course Name              | Info                                | Tuition       \n";
    cout << "-----------|--------------------------|-------------------------------------|---------------\n";
    for (Course* it : courses) {
        it->print();
        totalTuitionAllCoures += it->totalTuition();
    }
    cout << "Total tuition of all coures: " << totalTuitionAllCoures << endl;
    for (Course* it : courses)
    {
        delete it;
    }
}
