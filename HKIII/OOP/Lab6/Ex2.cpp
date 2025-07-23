#include <string>
#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <ctime>
using namespace std;

class Movie
{
private:
    string *Title;
    int *Duration; // in minutes
    int *ReleaseYear;

public:
    Movie();
    Movie(const string &t, const int &d, const int &y);
    Movie(const Movie &other);
    ~Movie();
    int getDuration();
    Movie &operator=(const Movie &other);
    friend istream &operator>>(istream &is, Movie &this);
    friend ostream &operator<<(ostream &os, const Movie &this);
};
class ScreeningRoom
{
private:
    string *RoomName;
    int *NumSeat;
    vector<SeatRow> *ListSeatRow;

public:
    ScreeningRoom();
    ScreeningRoom(const string &name, const int &num, const vector<SeatRow> &list);
    ScreeningRoom(const ScreeningRoom &other);
    ~ScreeningRoom();
    ScreeningRoom &operator=(const ScreeningRoom &other);
    friend istream &operator>>(istream &is, ScreeningRoom &this);
    friend ostream &operator<<(ostream &os, const ScreeningRoom &this);
};
class SeatRow
{
private:
    char *Lable;
    vector<Seat> *ListSeat;

public:
    SeatRow();
    SeatRow(const char &lable, const vector<Seat> &list);
    SeatRow(const SeatRow &other);
    ~SeatRow();
    SeatRow &operator=(const SeatRow &other);
    friend istream &operator>>(istream &is, SeatRow &this);
    friend ostream &operator<<(ostream &os, const SeatRow &this);
};
enum class SeatStatus
{
    reserved,
    available
};
enum class SeatType
{
    Regular,
    VIP,
    Couple
};
class Seat
{
private:
    int *SeatNumber;
    char *RowLable;
    SeatStatus *Status;
    SeatType *Type;

public:
    Seat();
    Seat(const int &num, const char &lable, const SeatStatus &stat, const SeatType &type);
    Seat(const Seat &other);
    ~Seat();
    Seat &operator=(const Seat &other);
    friend istream &operator>>(istream &is, Seat &this);
    friend ostream &operator<<(ostream &os, const Seat &this);
};
class ScreeningSchedule
{
private:
    Movie *movie;
    ScreeningRoom *room;
    string *Start;
    string *End; // auto calc
    int *BaseTicketPrice;

public:
    ScreeningSchedule();
    ScreeningSchedule(const Movie &m, const ScreeningRoom &r, const string &st, const int &p);
    ScreeningSchedule(const ScreeningSchedule &other);
    ~ScreeningSchedule();
    ScreeningSchedule &operator=(const ScreeningSchedule &other);
    void calculateAndSetEndTime();
    friend istream &operator>>(istream &is, ScreeningSchedule &this);
    friend ostream &operator<<(ostream &os, const ScreeningSchedule &this);
};

Movie::Movie() : Title(NULL), Duration(NULL), ReleaseYear(NULL) {}
Movie::Movie(const string &t, const int &d, const int &y) : Title(new string(t)), Duration(new int(d)), ReleaseYear(new int(y)) {}
Movie::Movie(const Movie &other) : Title(new string(*other.Title)), Duration(new int(*other.Duration)), ReleaseYear(new int(*other.ReleaseYear)) {}
Movie::~Movie()
{
    if (Title)
        delete Title;
    if (Duration)
        delete Duration;
    if (ReleaseYear)
        delete ReleaseYear;
}
int Movie::getDuration() const
{
    if (Duration)
    {
        return *Duration;
    }
    return 0;
}
Movie &Movie::operator=(const Movie &other)
{
    if (this == &other)
        return *this;
    delete Title;
    delete Duration;
    delete ReleaseYear;
    Title = new string(*other.Title);
    Duration = new int(*other.Duration);
    ReleaseYear = new int(*other.ReleaseYear);
    return *this;
}

ScreeningRoom::ScreeningRoom() : RoomName(NULL), NumSeat(NULL), ListSeatRow(NULL) {}
ScreeningRoom::ScreeningRoom(const string &name, const int &num, const vector<SeatRow> &list) : RoomName(new string(name)), NumSeat(new int(num)), ListSeatRow(new vector<SeatRow>(list)) {}
ScreeningRoom::ScreeningRoom(const ScreeningRoom &other) : RoomName(new string(*other.RoomName)), NumSeat(new int(*other.NumSeat)), ListSeatRow(new vector<SeatRow>(*other.ListSeatRow)) {}
ScreeningRoom::~ScreeningRoom()
{
    if (RoomName)
        delete RoomName;
    if (NumSeat)
        delete NumSeat;
    if (ListSeatRow)
        delete ListSeatRow;
}
ScreeningRoom &ScreeningRoom::operator=(const ScreeningRoom &other)
{
    if (this == &other)
        return *this;
    delete RoomName;
    delete NumSeat;
    delete ListSeatRow;
    RoomName = new string(*other.RoomName);
    NumSeat = new int(*other.NumSeat);
    ListSeatRow = new vector<SeatRow>(*other.ListSeatRow);
    return *this;
}
SeatRow::SeatRow() : Lable(NULL), ListSeat(NULL) {}
SeatRow::SeatRow(const char &lable, const vector<Seat> &list) : Lable(new char(lable)), ListSeat(new vector<Seat>(list)) {}
SeatRow::SeatRow(const SeatRow &other) : Lable(new char(*other.Lable)), ListSeat(new vector<Seat>(*other.ListSeat)) {}
SeatRow::~SeatRow()
{
    if (Lable)
        delete Lable;
    if (ListSeat)
        delete ListSeat;
}
SeatRow &SeatRow::operator=(const SeatRow &other)
{
    if (this == &other)
        return *this;
    delete Lable;
    delete ListSeat;
    Lable = new char(*other.Lable);
    ListSeat = new vector<Seat>(*other.ListSeat);
    return *this;
}
Seat::Seat() : SeatNumber(NULL), RowLable(NULL), Status(NULL), Type(NULL) {}
Seat::Seat(const int &num, const char &lable, const SeatStatus &stat, const SeatType &type) : SeatNumber(new int(num)), RowLable(new char(lable)), Status(new SeatStatus(stat)), Type(new SeatType(type)) {}
Seat::Seat(const Seat &other) : SeatNumber(new int(*other.SeatNumber)), RowLable(new char(*other.RowLable)), Status(new SeatStatus(*other.Status)), Type(new SeatType(*other.Type)) {}
Seat::~Seat()
{
    if (SeatNumber)
        delete SeatNumber;
    if (RowLable)
        delete RowLable;
    if (Status)
        delete Status;
    if (Type)
        delete Type;
}
Seat &Seat::operator=(const Seat &other)
{
    if (this == &other)
        return *this;
    delete SeatNumber;
    delete RowLable;
    delete Status;
    delete Type;
    SeatNumber = new int(*other.SeatNumber);
    RowLable = new char(*other.RowLable);
    Status = new SeatStatus(*other.Status);
    Type = new SeatType(*other.Type);
    return *this;
}
ScreeningSchedule::ScreeningSchedule() : movie(NULL), room(NULL), Start(NULL), End(NULL), BaseTicketPrice(NULL) {}
ScreeningSchedule::ScreeningSchedule(const Movie &m, const ScreeningRoom &r, const string &st, const int &p) : movie(new Movie(m)), room(new ScreeningRoom(r)), Start(new string(st)), End(new string), BaseTicketPrice(new int(p))
{
    // tính time end
    calculateAndSetEndTime();
}
ScreeningSchedule::ScreeningSchedule(const ScreeningSchedule &other) : movie(new Movie(*other.movie)), room(new ScreeningRoom(*other.room)), Start(new string(*other.Start)), End(new string(*other.End)), BaseTicketPrice(new int(*other.BaseTicketPrice)) {}
ScreeningSchedule::~ScreeningSchedule()
{
    if (movie)
        delete movie;
    if (room)
        delete room;
    if (Start)
        delete Start;
    if (End)
        delete End;
    if (BaseTicketPrice)
        delete BaseTicketPrice;
}
ScreeningSchedule &ScreeningSchedule::operator=(const ScreeningSchedule &other)
{
    if (this == &other)
        return *this;
    delete movie;
    delete room;
    delete Start;
    delete End;
    delete BaseTicketPrice;
    movie = new Movie(*other.movie);
    room = new ScreeningRoom(*other.room);
    Start = new string(*other.Start);
    End = new string(*other.End);
    BaseTicketPrice = new int(*other.BaseTicketPrice);
    return *this;
}
void ScreeningSchedule::calculateAndSetEndTime()
{
    if (!movie || !Start || !End)
    {
        cerr << "Error: Don't have enought data to calculate end time." << endl;
        return;
    }
    tm tm_start = {}; // Khởi tạo tất cả các thành viên về 0
    stringstream ss(*Start);
    ss >> get_time(&tm_start, "%d-%m-%Y %H:%M");

    if (ss.fail())
    {
        cerr << "Error: Start time format is invalid: " << *Start << endl;
        return;
    }
    // 2. Chuyển đổi tm sang time_t
    // mktime chuẩn hóa tm_start và trả về time_t
    time_t time_start = mktime(&tm_start);

    if (time_start == -1)
    {
        cerr << "Error: Cannot convert valid starting time." << endl;
        return;
    }
    // 3. Thêm thời lượng phim (tính bằng phút) vào thời gian bắt đầu
    time_start += movie->getDuration() * 60; // Chuyển phút thành giây
    // 4. Chuyển đổi time_t kết quả trở lại tm
    // localtime trả về con trỏ tới một đối tượng tm tĩnh, nên cần sao chép
    tm tm_end = *localtime(&time_start);
    // 5. Định dạng tm kết quả thành chuỗi thời gian kết thúc
    stringstream ss_end;
    ss_end << put_time(&tm_end, "%d-%m-%Y %H:%M");
    // Gán chuỗi thời gian kết thúc đã tính toán vào thuộc tính End
    // Giải phóng bộ nhớ cũ nếu có và cấp phát mới
    delete End;
    End = new string(ss_end.str());
}

istream &operator>>(istream &is, Movie &obj)
{
    string line;
    string titleStr;
    int durationInt;
    int releaseYearInt;
    if (getline(is, titleStr, '|') &&
    (is >> durationInt) && is.ignore(1, '|') && // Đọc int, sau đó bỏ qua 1 ký tự '|'
    (is >> releaseYearInt)) {
        // Cấp phát bộ nhớ nếu con trỏ là nullptr, sau đó gán giá trị
        if (!obj.Title)
            obj.Title = new string();
        if (!obj.Duration)
            obj.Duration = new int();
        if (!obj.ReleaseYear)
            obj.ReleaseYear = new int();
        *obj.Title = titleStr;
        *obj.Duration = durationInt;
        *obj.ReleaseYear = releaseYearInt;
    }
    else
    {
        is.setstate(ios::failbit); // Đặt cờ lỗi nếu phân tích cú pháp thất bại
        cerr << "Error: Movie data format is invalid." << endl;
    }
    return is;
}
ostream &operator<<(ostream &os, const Movie &obj)
{
    // Format: Title|Duration|ReleaseYear
    os << *obj.Title << "|" << *obj.Duration << "|" << *obj.ReleaseYear;
    return os;
}
istream &operator>>(istream &is, ScreeningRoom &obj) {
    string roomNameStr, numSeatStr, numSeatRowsStr;

    if (getline(is, roomNameStr, '|') &&
        getline(is, numSeatStr, '|') &&
        getline(is, numSeatRowsStr, '|')) // Đọc số hàng ghế
    {
        if (!room.RoomName) room.RoomName = new string();
        if (!room.NumSeat) room.NumSeat = new int();
        if (!room.ListSeatRow) room.ListSeatRow = new vector<SeatRow>();

        *room.RoomName = roomNameStr;
        *room.NumSeat = stoi(numSeatStr);
        int numSeatRows = stoi(numSeatRowsStr);

        room.ListSeatRow->clear(); // Xóa hàng ghế cũ nếu có

        // Đọc từng hàng ghế
        for (int i = 0; i < numSeatRows; ++i) {
            SeatRow tempSeatRow;
            string currentSeatRowData;
            if (i < numSeatRows -1) { // Nếu không phải hàng cuối cùng, đọc đến dấu '|'
                getline(is, currentSeatRowData, '|');
            } else { // Nếu là hàng cuối cùng, đọc đến hết dòng
                getline(is, currentSeatRowData);
            }

            if (is.fail()) {
                is.setstate(ios::failbit);
                cerr << "Error:." << endl;
                return is;
            }

            stringstream seatRowSs(currentSeatRowData);
            seatRowSs >> tempSeatRow; // Gọi operator>> của SeatRow
            if (seatRowSs.fail()) {
                is.setstate(ios::failbit);
                cerr << "" << endl;
                return is;
            }
            room.ListSeatRow->push_back(tempSeatRow);
        }
    } else {
        is.setstate(ios::failbit);
        cerr << "Err: ." << endl;
    }
    return is;
}
ostream &operator<<(ostream &os, const ScreeningRoom &obj)  {
    // Định dạng: RoomName|NumSeat|NumSeatRows|SeatRow1_data|SeatRow2_data|...
    os << *room.RoomName << "|" << *room.NumSeat << "|" << room.ListSeatRow->size();
    for (const auto& seatRow : *room.ListSeatRow) {
        os << "|" << seatRow; // Gọi operator<< của SeatRow
    }
    return os;
}
istream &operator>>(istream &is, SeatRow &this) {
    string line;
    if (getline(is, line)) { // Đọc cả dòng
        stringstream ss(line);
        string tempLable, tempNumSeatsStr;
        
        if (getline(ss, tempLable, '|') && getline(ss, tempNumSeatsStr, '|')) {
            if (!seatRow.Lable) seatRow.Lable = new char();
            if (!seatRow.ListSeat) seatRow.ListSeat = new vector<Seat>();

            *seatRow.Lable = tempLable[0];
            int numSeats = stoi(tempNumSeatsStr);

            seatRow.ListSeat->clear(); 
            
            for (int i = 0; i < numSeats; ++i) {
                string seatData;
                Seat tempSeat;
                string seatNumStr, rowLableStr, statusStr, typeStr;
                if (getline(ss, seatNumStr, '|') &&
                    getline(ss, rowLableStr, '|') &&
                    getline(ss, statusStr, '|') &&
                    getline(ss, typeStr, '|')) // Đọc đến dấu '|' cuối cùng của Seat
                {
                    if (!tempSeat.SeatNumber) tempSeat.SeatNumber = new int();
                    if (!tempSeat.RowLable) tempSeat.RowLable = new char();
                    if (!tempSeat.Status) tempSeat.Status = new SeatStatus();
                    if (!tempSeat.Type) tempSeat.Type = new SeatType();

                    *tempSeat.SeatNumber = stoi(seatNumStr);
                    *tempSeat.RowLable = rowLableStr[0];
                    *tempSeat.Status = static_cast<SeatStatus>(stoi(statusStr));
                    *tempSeat.Type = static_cast<SeatType>(stoi(typeStr));
                    seatRow.ListSeat->push_back(tempSeat);
                } else {
                    is.setstate(ios::failbit);
                    cerr << "Error: Seat data format in row is invalid." << endl;
                    return is;
                }
            }
        } else {
            is.setstate(ios::failbit);
            cerr << "Error: Seat row data format is invalid." << endl;
        }
    }
    return is;
}
ostream &operator<<(ostream &os, const SeatRow &this) {
    // Định dạng: Lable|NumSeats|Seat1_data|Seat2_data|...
    os << *seatRow.Lable << "|" << seatRow.ListSeat->size();
    for (const auto& seat : *seatRow.ListSeat) {
        os << "|" << seat; // Gọi operator<< của Seat
    }
    return os;
}
istream &operator>>(istream &is, Seat &obj) {
    string line;
    if (getline(is, line)) { // Đọc cả dòng
        stringstream ss(line);
        string tempNum, tempLable, tempStatus, tempType;

        if (getline(ss, tempNum, '|') &&
            getline(ss, tempLable, '|') &&
            getline(ss, tempStatus, '|') &&
            getline(ss, tempType))
        {
            // Cấp phát bộ nhớ nếu nullptr, sau đó gán giá trị
            if (!seat.SeatNumber) obj.SeatNumber = new int();
            if (!seat.RowLable) obj.RowLable = new char();
            if (!seat.Status) obj.Status = new SeatStatus();
            if (!seat.Type) obj.Type = new SeatType();

            *obj.SeatNumber = stoi(tempNum);
            *obj.RowLable = tempLable[0]; // Lấy ký tự đầu tiên
            *obj.Status = static_cast<SeatStatus>(stoi(tempStatus));
            *obj.Type = static_cast<SeatType>(stoi(tempType));
        } else {
            is.setstate(ios::failbit);
            cerr << "Error: = Seat data format is invalid." << endl;
        }
    }
    return is;
}
ostream &operator<<(ostream &os, const Seat &this) {
    // Định dạng: SeatNumber|RowLable|Status(int)|Type(int)
    os << *seat.SeatNumber << "|" << *seat.RowLable << "|"
       << static_cast<int>(*seat.Status) << "|" << static_cast<int>(*seat.Type);
    return os;
}
istream &operator>>(istream &is, ScreeningSchedule &this);
ostream &operator<<(ostream &os, const ScreeningSchedule &this);







format: 
