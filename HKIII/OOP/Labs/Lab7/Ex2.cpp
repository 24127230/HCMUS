#include <iostream>
#include <string>
#include <vector>
#include <limits> // Dùng cho numeric_limits
#include <algorithm> // Dùng cho remove_if
using namespace std;

// --- Class Person ---
class Person
{
protected:
    string fullName;
    string dateOfBirth;
    string address;
public:
    Person(string name = "", string birth = "__/__/____", string addr = "");
    virtual ~Person();
    virtual void input();
    virtual void output() const;
};
// --- Class Employee ---
class Employee : public Person {
private:
    string department;
    double salaryCoefficient; // Hệ số lương
    double allowance;         // Phụ cấp

public:
    Employee(string name = "", string birth = "__/__/____", string addr = "", string dept = "", double coeff = 0.0, double allow = 0.0);
    ~Employee();
    void input() override;
    void output() const override;
    double getSalary();
};


Person::Person(string name, string birth, string addr) : fullName(name), dateOfBirth(birth), address(addr) {}
Person::~Person() {}
void Person::input() {
    if (cin.peek() == '\n') 
        cin.ignore();
    cout << "Enter Full Name: ";
    getline(cin, fullName);
    cout << "Enter Date of Birth: ";
    getline(cin, dateOfBirth);
    cout << "Enter address: ";
    getline(cin, address);
}
void Person::output() const {
    cout << "--INFORMATION--\n";
    cout << "Full Name: " << fullName << endl;
    cout << "Date of Birth: " << dateOfBirth << endl;
    cout << "address: " << address << endl;
}
Employee::Employee(string name, string birth, string addr, string dept, double coeff, double allow) : Person(name, birth, addr), department(dept), salaryCoefficient(coeff), allowance(allow) {}
Employee::~Employee() {}
void Employee::input() {
    Person::input(); // Gọi input của lớp cha
    cout << "Enter Department: ";
    getline(cin, department);
    cout << "Enter Salary Coefficient: ";
    cin >> salaryCoefficient;
    cout << "Enter Allowance: ";
    cin >> allowance;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer sau khi đọc số
}

void Employee::output() const {
    Person::output(); // Gọi output của lớp cha
    cout << "Department: " << department << endl;
    cout << "Salary Coefficient: " << salaryCoefficient << endl;
    cout << "Allowance: " << allowance << endl;
}
double Employee::getSalary()
{
    return salaryCoefficient * 1200 + allowance;
}

int main()
{
    int n;
    cout << "Enter number of employee: ";
    cin >> n;
    cout << endl;
    vector<Employee> employees(n);
    for (int i = 0; i < n; ++i) {
        cout << "---Employee #" << i + 1 << "---\n";
        employees[i].input();
    }
    double minSalary, maxSalary;
    cout << "\nEnter salary range to filter:\n";
    cout << "Min: ";
    cin >> minSalary;
    cout << "Max: ";
    cin >> maxSalary;


    cout << "\n___Filtered list of employees___\n";
    for (int i = 0; i < n; ++i)
    {
        double salary = employees[i].getSalary();
        if (salary >= minSalary && salary <= maxSalary)
            employees[i].output();
    }
    
    return 0;
}