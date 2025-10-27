#include<iostream>
#include<string>
#include<windows.h>
#include<fstream>
#include<ctime>

using namespace std;

void menu_banking();
bool loginUser();
void registerUser();
void banking_setting();
void deposit();
void dashboard_user();
void showBalance();
void history_deposit();
void update();
string format_vnd(long long n);
void transfer_money();
string title();
string get_time();
void showlogin_history();
void name_user();
string get_name_user();
void fake_faceid();
void shopping();

void TextColor(int color) { HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  SetConsoleTextAttribute(hConsole, color);  }

//------------------------------------ banking-------------------------------------------

// tiêu đề cho nhân vật
string title() {
    string content;
    ifstream file("text.txt"); 
    if (file.is_open()) {
        getline(file, content); 
        file.close();
    } else {
        content = "BANKING SYSTEM"; 
    }
    return content;
}

// bản cập nhật
void update(){int choice;
    do{system("cls");cout<<"\n\n";
        cout<<"\t\t=======================\n";
        cout<<"\t\tDevelop language: C++\n";
        cout<<"\t\t=======================\n\n";
        cout<<"\t1. version 1(finish)\n";
        cout<<"\t2. version 2\n";
        cout<<"\t3. version 3\n";
        cout<<"\t4. version 4\n";
        cout<<"\t--> ";cin>>choice;
        switch(choice){
            case 1:{
            system("start https://github.com/huiinguen/sourcecode/tree/main/c%2B%2B/banking/ver1");
            system("pause"); break;
            }
            case 2:{}
            case 3:{}
            case 4:{}
        }
    }while(choice!=0);
}

// banking setting
void banking_setting() {int choice;

    do {system("cls");cout << "\n\n";
        cout << "\t1. Thay đổi màu giao diện\n";
        cout << "\t2. Tùy chỉnh tiêu đề ứng dụng\n";
        cout << "\t0. Thoát\n";
        cout << "\t---> ";cin >> choice;

        switch (choice) {
        case 1: {int colorChoice;
            do {system("cls");
                cout << "\n\t\t🎨 Thiết lập màu cho Banking\n\n";
                cout << "\t2. Xanh lá\t3. Xanh biển\n";
                cout << "\t4. Đỏ\t\t5. Tím\n";
                cout << "\t7. Trắng\t75. Trắng phủ hồng\n";
                cout << "\t87. Trắng phủ nền\n";
                cout << "\t0. Quay lại\n";
                cout << "\t--> ";cin >> colorChoice;

                if (colorChoice == 0) break;

                TextColor(colorChoice);

                ofstream openfile("setting_color.txt", ios::out | ios::trunc);
                if (openfile.is_open()) {
                    openfile << colorChoice;
                    openfile.close();
                    cout << "\n✅ Đã lưu màu giao diện!\n";
                } else {
                    cout << "\n⚠️ Không thể lưu file màu!\n";
                }
                Sleep(800);
            } while (colorChoice != 0);
            break;
        }

        case 2: {string text;
            do{
                cout << "\n\tNhập tiêu đề mới cho ứng dụng: ";
                getline(cin, text);
            }while(text.length() <=1);

            ofstream openfile2("text.txt", ios::out | ios::trunc);
            if (openfile2.is_open()) {
                openfile2 << text;
                openfile2.close();
                cout << "\t✅ Đã lưu tiêu đề!\n";
            } else {
                cout << "\t⚠️ Không thể lưu tiêu đề!\n";
            }
            Sleep(800);
            break;
        }

        case 0:  break;

        default:
            cout << "\n⚠️ Lựa chọn không hợp lệ!\n";
            Sleep(800);
        }
    } while (choice != 0);
}

// đăng nhập bằng face id
void fake_faceid() {
    ofstream openfile("lichsudangnhap.txt");
    if(openfile.is_open()){
        openfile<<"["<<get_time()<<"]: đăng nhập face id thành công\n";
        system("start microsoft.windows.camera:");
        Sleep(3000); // mô phỏng quét mặt 3 giây
        system("taskkill /IM WindowsCamera.exe /F");
        cout << "\t✅ FaceID xác nhận thành công!\n";
    }else{
        cout<<"\n\t camera bị hư or không có thiết bị\n";
    }
    openfile.close();
}

// đăng ký tài khoản
void registerUser() {string password, name;

    ofstream openfile("name.txt", ios::out | ios::trunc);
    ofstream openfile2("password.txt", ios::out | ios::trunc);

    if(openfile.is_open() && openfile2.is_open()) {
        cout << "\n\n\t\tVui lòng nhập thông tin tên và mật khẩu\n\n";

        do{
            cout << "\t\t\t\t\tName: ";cin >> name;
            cout << "\t\t\t\t\tPassword: ";cin >> password;
            if(name.length() < 7  && password.length() <7) {
                cout << "\t\t Hệ thống cho thấy bạn đang sai!\n";
                cout << "\t\t❌ Tên phải có ít nhất 7 ký tự!\n";
                cout << "\t\t❌ Mật khẩu phải có ít nhất 7 ký tự!\n";
            }
        } while(name.length() < 7 && password.length() <7);

        openfile << name;
        openfile2 << password;

        openfile.close();
        openfile2.close();

        Sleep(1000);
        cout << "\t\t✅ Hệ thống đã ghi thành công.\n";
    } else {
        cout << "\n⚠️ Lỗi hệ thống: không thể mở file.\n";
    }
    Sleep(1000);
}

// đăng nhập
bool loginUser() {string password, check_password, name, check_name,note;
    ifstream openfile("name.txt");
    ifstream openfile2("password.txt");
    ofstream lichsu_dangnhap("lichsudangnhap.txt",ios::app);

    if (openfile.is_open() && openfile2.is_open()) {
        openfile >> check_name;
        openfile2 >> check_password;

        openfile.close();
        openfile2.close();

        cout << "\n\n\t\t\t\t\tName: ";cin >> name;
        cout << "\t\t\t\t\tPassword: ";cin >> password;

        if (check_name == name) {
            if (check_password == password) {
                cout << "\t\t✅ Đăng nhập thành công\n";
                Sleep(1000);
                lichsu_dangnhap<<"["<<get_time()<<"]: đăng nhập user and password thành công\n";
                return true;
            } else {
                cout << "\t\t❌ Mật khẩu sai!\n";
                Sleep(1000);
                lichsu_dangnhap<<"["<<get_time()<<"]: đăng nhập user and password thất bại\n";
                return false;
            }
        } else {
            cout << "\t\t❌ Tên đăng nhập không tồn tại!\n";
            Sleep(1000);
            return false;
        }
    } else {
        cout << "\t\t⚠️ Không thể mở file dữ liệu.\n";
        Sleep(1000);
        return false;
    }
    lichsu_dangnhap.close();

}
 
// menu banking(main)
void menu_banking(){int choice,check_color;
    ifstream openfile("setting_color.txt");
    if (openfile.is_open()){
        openfile >> check_color;
        TextColor(check_color); 
        openfile.close();
    }
    do{system("cls");cout << "\n\n";
        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣷⣶⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀                 "<<title()<<"\n";
        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⣿⣿⣿⣷⡒⢄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << "\n";
        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿⣿⣿⣿⣆⠙⡄⠀⠐⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << "\n";
        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⣤⣤⣤⣤⣤⣤⣤⣤⠤⢄⡀⠀⠀⣿⣿⣿⣿⣿⣿⡆⠘⡄⠀⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << "\n";
        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⢿⣿⣿⣿⣿⣿⣿⣿⣦⡈⠒⢄⢸⣿⣿⣿⣿⣿⣿⡀⠱⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << "\n";
        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣿⣿⣿⣿⣿⣿⣿⣦⠀⠱⣿⣿⣿⣿⣿⣿⣇⠀⢃⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << "\n";
        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢿⣿⣿⣿⣿⣿⣿⣷⡄⣹⣿⣿⣿⣿⣿⣿⣶⣾⣿⣶⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << "\n";
        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << "\n";
        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⣶⣿⣭⣍⡉⠙⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << "\n";
        cout << "⠀⠀⠀⠀⠀⠀⠀⢀⣠⣶⣿⣿⣿⣿⣿⣿⣿⣿⣷⣦⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << "\n";
        cout << "⠀⠀⠀⠀⠀⠀⠀⠉⠉⠛⠻⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡷⢂⣓⣶⣶⣶⣶⣤⣤⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀" << "\n";
        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⠟⢀⣴⢿⣿⣿⣿⠟⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠋⠉⠀⠀⠀⠀⠀⠀⠀" << "\n";
        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠤⠤⠤⠤⠙⣻⣿⣿⣿⣿⣿⣿⣾⣿⣿⡏⣠⠟⡉⣾⣿⣿⠋⡠⠊⣿⡟⣹⣿⢿⣿⣿⣿⠿⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << "\n";
        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⣶⣤⣭⣤⣼⣿⢛⣿⣿⣿⣿⣻⣿⣿⠇⠐⢀⣿⣿⡷⠋⠀⢠⣿⣺⣿⣿⢺⣿⣋⣉⣉⣩⣴⣶⣤⣤⣄⠀ ⠀⠀ ⠀⠀⠀ 1.Sign in⠀⠀" << "\n";
        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠛⠻⠿⣿⣿⣿⣇⢻⣿⣿⡿⠿⣿⣯⡀⠀⢸⣿⠋⢀⣠⣶⠿⠿⢿⡿⠈⣾⣿⣿⣿⣿⡿⠿⠛⠋⠁⠀⠀⠀  ⠀⠀⠀⠀ 2.Sign up⠀⠀" << "\n";
        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠻⢧⡸⣿⣿⣿⠀⠃⠻⠟⢦⢾⢣⠶⠿⠏⠀⠰⠀⣼⡇⣸⣿⣿⠟⠉⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠀ 3.Face id⠀" << "\n";
        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⣾⣶⣽⣿⡟⠓⠒⠀⠀⡀⠀⠠⠤⠬⠉⠁⣰⣥⣾⣿⣿⣶⣶⣷⡶⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  4.Setting⠀" << "\n";
        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠉⠉⠹⠟⣿⣿⡄⠀⠀⠠⡇⠀⠀⠀⠀⠀⢠⡟⠛⠛⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   5.Update" << "\n";
        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⠋⠹⣷⣄⠀⠐⣊⣀⠀⠀⢀⡴⠁⠣⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠀⠀⠀⠀⠀⠀⠀⠀⠀0.Exit" << "\n";
        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⣀⠤⠊⢁⡸⠀⣆⠹⣿⣧⣀⠀⠀⡠⠖⡑⠁⠀⠀⠀⠑⢄⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << "\n";
        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣦⣶⣿⣿⣟⣁⣤⣾⠟⠁⢀⣿⣆⠹⡆⠻⣿⠉⢀⠜⡰⠀⠀⠈⠑⢦⡀⠈⢾⠑⡾⠲⣄⠀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << "\n";
        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠖⠒⠚⠛⠛⠢⠽⢄⣘⣤⡎⠠⠿⠂⠀⠠⠴⠶⢉⡭⠃⢸⠃⠀⣿⣿⣿⠡⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << "\n";
        cout << "\t\t\t\t\t\t\t\t---> ";cin >> choice;
        switch (choice){
        case 1:{
            if (loginUser()){  dashboard_user();  }
            break;
        }
        case 2:{ registerUser();break;}
        case 3:{fake_faceid();dashboard_user();}
        case 4:{  banking_setting();break;}
        case 5:{ update();  break;  }
        }
    } while (choice != 0);
}

//--------------------------------------graphics user--------------------------------------

// nạp tiền
void deposit() {
    long long money = 0, current = 0;
    cout << "\t\t💰 Nạp Tiền: ";cin >> money;

    if (money <= 0) {
        cout << "\t\t⚠️ Số tiền không hợp lệ!\n";
        return;
    }

    // Đọc số dư hiện tại
    ifstream sodu("deposit.txt");
    if (sodu.is_open()) sodu >> current;
    sodu.close();

    long long total = current + money;

    // Ghi lại số dư mới
    ofstream sodu_moi("deposit.txt", ios::trunc);
    sodu_moi << total;
    sodu_moi.close();

    // Ghi lịch sử nạp tiền
    ofstream history("lichsugiaodich.txt", ios::app);
    history << "[" << get_time() << "] Nạp: " << format_vnd(money) << " | Tổng: " << format_vnd(total) << "\n";
    history.close();

    cout << "\t✅ Đã nạp thành công " << format_vnd(money) << endl;
    Sleep(1000);
}

// định dạng tiền(vnd)
string format_vnd(long long n) {
    string s = to_string(n);
    int insertPosition = s.length() - 3;
    while (insertPosition > 0) {
        s.insert(insertPosition, ".");
        insertPosition -= 3;
    }
    return s + " VND";
}

// đọc số tiền
void showBalance() {long long money = 0;
    ifstream openfile("deposit.txt");

    if (!openfile.is_open()) {
        cout << "\t⚠️ Không thể mở file số dư.\n";
        return;
    }

    if (!(openfile >> money)) {
        cout << "\t⚠️ File rỗng hoặc lỗi dữ liệu.\n";
        openfile.close();
        return;
    }

    openfile.close();
    cout << "\t💰 Số dư: " << format_vnd(money);
}

// chuyển tiền
void transfer_money() {
    long long deposit = 0, money = 0,tong=0,tong2=0;
    string nguoinhan,noidung,nganhang;

    ifstream openfile("deposit.txt");
    if (openfile.is_open()) openfile >> deposit;
    openfile.close();

    system("cls");cout<<"\n\n";

    cout << "\n\t\t Chuyển số tiền? : ";cin >> money;
    cout<<"\t\t Người nhận: ";cin>>nguoinhan;
    cout<<"\t\t Ngân hàng: ";cin>>nganhang;
    cout<<"\t\t Nội dung: ";cin>>noidung;

    if (money <= 0) {
        cout << "\t⚠️ Số tiền không hợp lệ!\n";
        return;
    }

    if (deposit >= money) {
        tong = deposit - money;
        ofstream file("deposit.txt", ios::trunc);
        file << tong;
        file.close();

        Sleep(1000); cout << "\t✅ Chuyển tiền thành công!\n";
        cout << "\t💰 Số dư còn lại: " << format_vnd(tong) << endl;
    } else {
        Sleep(1000);cout << "\t❌ Số dư không đủ!\n";
    }

    // ghi lịch sử chuyển tiền
    ofstream history("lichsugiaodich.txt",ios::app);
    ifstream deposit1("deposit.txt");
    if(deposit1.is_open()){
        deposit1>>tong2;
        deposit1.close();
    }
    tong2-=money;
    history<<"\n["<<get_time()<<"][THÔNG TIN CHUYỂN TIỀN]"<<endl;
    history<<"Người gửi:"<<get_name_user()<<endl;
    history<<"Người nhận: "<<nguoinhan<<endl;
    history<<"Chuyển Tiền: "<<format_vnd(money)<<" | Còn: "<<format_vnd(tong2)<<endl;
    history<<"Ngân hàng: "<<nganhang<<endl;
    history<<"Nội dung: "<<noidung<<endl;
    history.close();
    cout << "\t✅ Đã chuyển thành công " << format_vnd(money) << endl;
    Sleep(1000);
}

// lấy thời gian
string get_time() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    char buffer[80];
    sprintf(buffer, "%04d/%02d/%02d %02d:%02d:%02d",
            1900 + ltm->tm_year,
            1 + ltm->tm_mon,
            ltm->tm_mday,
            ltm->tm_hour,
            ltm->tm_min,
            ltm->tm_sec);

    return string(buffer);
}

// lịch sử nạp tiền
void history_deposit() {
    ifstream openfile("lichsugiaodich.txt");

    if (!openfile.is_open()) {
        cout << "\n⚠️ Lỗi: Không thể mở file lịch sử giao dịch!\n";
        return;
    }

    string line;
    system("cls");
    cout << "\n====================== 🧾 LỊCH SỬ NẠP TIỀN ========================\n";

    bool empty = true;
    while (getline(openfile, line)) {  // đọc từng dòng
        if (!line.empty()) {
            cout << "🔹 " << line << endl;
            empty = false;
        }
    }

    if (empty)  cout << "❌ Chưa có giao dịch nào!\n";

    openfile.close();
    cout << "=========================================================\n";
    system("pause");
}

// đọc lịch sử đăng nhập
void showlogin_history() {
    ifstream openfile("lichsudangnhap.txt"); 

    if (!openfile.is_open()) {
        cout << "\t⚠️ Lỗi: Không thể mở file lịch sử đăng nhập!\n";
        return;
    }

    string line;
    bool empty = true;
    system("cls");
    cout << "\n===================== 🧾 LỊCH SỬ ĐĂNG NHẬP =====================\n";

    while (getline(openfile, line)) {
        if (!line.empty()) {
            cout << "🔹 " << line << endl;
            empty = false;
        }
    }

    if (empty)
        cout << "❌ Chưa có lịch sử đăng nhập!\n";

    openfile.close();
    cout << "===============================================================\n";
    system("pause");
}

// tên user trong giao diện
void name_user(){string line;
    ifstream openfile("name.txt");
    if(openfile.is_open()){
        openfile>>line;
        cout<<"\tNAME: "<<line;
        openfile.close();
    }
}

// tên user cho tác vụ khác
string get_name_user() { string line;
    ifstream openfile("name.txt");
    if (openfile.is_open()) {
        openfile >> line;
        openfile.close();
        return line;
    } else {
        return "USER_ERROR";
    }
}

//mua sắm
void shopping(){int choice;
    system("cls");cout<<"\n\n";
    cout<<"\t1. Voucher taxi\n";
    cout<<"\t2. Vé máy bay\n";
    cout<<"\t--> ";cin>>choice;
    switch(choice){

    }
}

// hàm chính user(main)
void dashboard_user(){int choice;
    do{system("cls");cout<<"\n\n";
        cout << "\n\t=========================================\n";
        name_user();cout<<" |";showBalance();
        cout << "\n\t=========================================\n\n\n\n";

        cout << "\t1. Nạp tiền\n";
        cout << "\t2. Chuyển tiền\n";
        cout << "\t3. Lịch sử nạp tiền\n";
        cout << "\t4. Lịch sử đăng nhập\n";
        cout << "\t5. Mua sắm(comming soon)\n";
        cout << "\t0. Đăng xuất\n";
        cout<<"\t--> ";cin>>choice;
        switch(choice){
            case 1:{deposit();break;}
            case 2:{transfer_money();break;}
            case 3:{history_deposit();break;}
            case 4:{showlogin_history();break;}
            case 5:{shopping();break;}
        }
    }while(choice!=0);
}

//--------------------------------------------------------------------------
int main(){
    menu_banking();
    return 0;
}
