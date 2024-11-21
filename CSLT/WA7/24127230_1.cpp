#include <iostream>
using namespace std;
#define SIZE 100
/* Information about the lecturer */
struct lecturer_information
{
    char name[SIZE];                         /* Lecturer name */
    unsigned int staff_id;                   /* Lecturer id */
    float height;                            /* Lecturer height */
    struct department_information *dept_ptr; /* Pointer to a second structure */
};
/* Information about the department */
struct department_information
{
    char name[SIZE];        /* String with the department name */
    unsigned int room_num;  /* Number of room */
    unsigned int floor_num; /* Number of floor that room located */
};
int main()
{
    // a null pointer so dont need to declare: ((lecturer_information *)0)
    cout << "Size of name[SIZE]: " << sizeof((*((lecturer_information *)0)).name) << " bytes\n";
    cout << "Size of staff_id: " << sizeof((*((lecturer_information *)0)).staff_id) << " bytes\n";
    cout << "Size of height: " << sizeof((*((lecturer_information *)0)).height) << " bytes\n";
    cout << "Size of dept_ptr: " << sizeof((*((lecturer_information *)0)).dept_ptr) << " bytes\n";
    cout << "Size of type struct lecturer_information: " << sizeof(lecturer_information) << " bytes";
    return 0;
}