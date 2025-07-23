#include <iostream>
#include <vector>
using namespace std;
class MangSoNguyen {
private:
    int size;
    int* arr;
public:
    MangSoNguyen();
    MangSoNguyen(int MAX);
    MangSoNguyen(const int a[], int MAX);
    MangSoNguyen(const MangSoNguyen& copy);
    void Xuat();
    ~MangSoNguyen();
};
MangSoNguyen::MangSoNguyen(): size(0), arr(NULL) {}
MangSoNguyen::MangSoNguyen(int MAX): size(MAX) {
    arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = 0;
}
MangSoNguyen::MangSoNguyen(const int a[], int MAX): size(MAX) {
    arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = a[i];
}
MangSoNguyen::MangSoNguyen(const MangSoNguyen& copy) {
    size = copy.size;
    arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = copy.arr[i];
    }
    
}
void MangSoNguyen::Xuat() {
    cout << "Mang so nguyen: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << '\n';
}
MangSoNguyen::~MangSoNguyen() {
    delete[] arr;
}
int main()
{
    MangSoNguyen msn1;
    msn1.Xuat();
    MangSoNguyen msn2(5);
    msn2.Xuat();
    int arr[10];
    for (int i = 0; i < 8; i++)
    {
        arr[i] = i * i;
    }
    MangSoNguyen msn3(arr, 8);
    msn3.Xuat();
    MangSoNguyen msn4(msn3);
    msn4.Xuat();
    return 0;
}