#include <iostream>
#include <string>
using namespace std;
bool IsValidNumber(string num) {
    if (num[0] != '-' && (num[0] > '9' || num[0] < '0')) return false; 
    for (int index = 1; index < num.length(); index++)
        if (num[index] > '9' || num[index] < '0')
            return false;
    return true;
}
unsigned char mod256(const string& bigNum) {
    unsigned long long remainder = 0;
    for (char digit : bigNum) {
        remainder = (remainder * 10 + (digit - '0')) % 256;
    }
    return static_cast<unsigned char>(remainder);
}
string getBit(char num) {
    string arr = "";
    for (int NumOfShift = 7; NumOfShift >= 0; NumOfShift--) {
        arr += to_string((num >> NumOfShift) & 1);
    }
    return arr;
}
char getInputNum(string inum) { 
    bool Signed = 0;
    if (inum[0] == '-') {
        Signed = 1;
        inum.erase(inum.begin());
    }
    unsigned char num = mod256(inum);
    if (Signed) {
        num = (~num + 1) & 0xFF;
    }
    return static_cast<char>(num);
}

char getNum(string arr) {
    char num = 0;
    for (int index = 0; index < 8; index++)
    {
        if (arr[index] == '1')
            num += (1 << (7 - index));
    } 
    return num;
}
string addBin(string A, string B) {
    string res = "";
    int carry = 0;
    for (int index = 7; index >= 0; index--) {
        int sum = (A[index]-'0') + (B[index]-'0') + carry;
        res = to_string(sum % 2) + res;
        carry = sum / 2;
    }
    return res;
}
string twoComplement(string arr) {
    for (char& bit : arr) {
        bit = (bit == '0') ? '1' : '0';
    }
    return addBin(arr, "00000001");
}
string subtractBin(string A, string B) {
    return addBin(A, twoComplement(B));
}
string multiplyBinary(string A, string B) {
    // Đảm bảo đủ 8 bit
    while (A.length() < 8) A = "0" + A;
    while (B.length() < 8) B = "0" + B;

    // Kiểm tra dấu
    bool negative = false;
    if (A[0] == '1') {
        A = twoComplement(A);
        negative = !negative;
    }
    if (B[0] == '1') {
        B = twoComplement(B);
        negative = !negative;
    }

    string result = "00000000";

    // Nhân kiểu "shift + cộng"
    for (int i = 7; i >= 0; i--) {
        if (B[i] == '1') {
            string temp = A;
            // Dịch trái theo vị trí bit
            for (int k = 0; k < 7 - i; k++)
                temp += "0";  // dịch trái => thêm 0 bên phải
            // Giữ 8 bit cuối (vì mô phỏng tràn 8-bit)
            if (temp.length() > 8)
                temp = temp.substr(temp.length() - 8);
            result = addBin(result, temp);
        }
    }

    // Nếu kết quả âm → đổi sang 2’s complement
    if (negative)
        result = twoComplement(result);

    return result.substr(result.length() - 8);
}string divideBinary(string A, string B) {
    while (A.length() < 8) A = "0" + A;
    while (B.length() < 8) B = "0" + B;
    if(B == "00000000") return "";
    bool negative = false;
    if (A[0] == '1') {
        A = twoComplement(A);
        negative = !negative;
    }
    if (B[0] == '1') {
        B = twoComplement(B);
        negative = !negative;
    }

    string quotient = "00000000";
    string remainder = "00000000";

    for (int i = 0; i < 8; i++) {
        // Dịch trái remainder và thêm bit A[i]
        remainder = remainder.substr(1, 7) + A[i];

        // Nếu remainder >= B thì trừ đi và đặt bit quotient = 1
        string diff = subtractBin(remainder, B);
        if (diff[0] != '1') { // remainder >= B
            remainder = diff;
            quotient = quotient.substr(1, 7) + "1";
        } else {
            quotient = quotient.substr(1, 7) + "0";
        }
    }

    if (negative)
        quotient = twoComplement(quotient);

    return quotient.substr(quotient.length() - 8);
}

string modBinary(string A, string B) {
    while (A.length() < 8) A = "0" + A;
    while (B.length() < 8) B = "0" + B;
    if(B == "00000000") return "";

    bool negative = false;
    if (A[0] == '1') {
        A = twoComplement(A);
        negative = true;
    }
    if (B[0] == '1') {
        B = twoComplement(B);
    }

    string remainder = "00000000";

    for (int i = 0; i < 8; i++) {
        remainder = remainder.substr(1, 7) + A[i];
        string diff = subtractBin(remainder, B);
        if (diff[0] != '1') {
            remainder = diff;
        }
    }

    if (negative)
        remainder = twoComplement(remainder);

    return remainder.substr(remainder.length() - 8);
}



int main() {
    string inputA, inputB;
    string arrA = "", arrB = "";
    cout << "Input A (Decimal): "; getline(cin, inputA);
    while(!IsValidNumber(inputA)) {
        cout << "Invalid number! Please enter a valid signed integer:";
        getline(cin, inputA);
    }

    cout << "Input B (Decimal): "; getline(cin, inputB);
    while(!IsValidNumber(inputB)) {
        cout << "Invalid number! Please enter a valid signed integer:";
        getline(cin, inputB);
    }
    int A = getInputNum(inputA), B = getInputNum(inputB);
    arrA = getBit(A);
    arrB = getBit(B);
    cout << "A (Binary): " << arrA << endl;
    cout << "B (Binary): " << arrB << endl;
    cout << "A + B (Binary): " << addBin(arrA, arrB) << endl; 
    cout << "A + B (Decimal): " << static_cast<int>(getNum(addBin(arrA, arrB))) << endl;
    cout << "A - B (Binary): " << subtractBin(arrA, arrB) << endl; 
    cout << "A - B (Decimal): " << static_cast<int>(getNum(subtractBin(arrA, arrB))) << endl;
    cout << "A * B (Binary): " << multiplyBinary(arrA, arrB) << endl; 
    cout << "A * B (Decimal): " << static_cast<int>(getNum(multiplyBinary(arrA, arrB))) << endl;
    cout << "A / B (Binary): " << divideBinary(arrA, arrB) << endl; 
    cout << "A / B (Decimal): ";
    if (divideBinary(arrA, arrB) != "") cout << static_cast<int>(getNum(divideBinary(arrA, arrB)));
    cout << endl;
    cout << "A % B (Binary): " << modBinary(arrA, arrB) << endl; 
    cout << "A % B (Decimal): ";
    if (modBinary(arrA, arrB) != "") cout << static_cast<int>(getNum(modBinary(arrA, arrB)));
    cout << endl;
    return 0;
}