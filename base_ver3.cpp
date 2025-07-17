#include <iostream>
#include <cmath>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <vector>
#include <math.h>
#include <iomanip>
#include <thread>
#include <iomanip>
#include<bitset> // dùng để mã hóa dạng 1-0
using namespace std;

// khai báo định danh các hàm 
void code_header();
void study();
void digital();
void cmd();
void mathuniver();

void times(time_t now = time(nullptr)){
    // Lấy thời gian hiện tại
    struct tm* localTime = localtime(&now);

    // In ra ngày/tháng/năm và giờ:phút:giây với số 0 đệm khi cần
    cout << "\t[ "
         << setw(2) << setfill('0') << localTime->tm_mday << "/"
         << setw(2) << setfill('0') << localTime->tm_mon + 1 << "/"
         << localTime->tm_year + 1900 << " | "
         << setw(2) << setfill('0') << localTime->tm_hour << ":"
         << setw(2) << setfill('0') << localTime->tm_min << ":"
         << setw(2) << setfill('0') << localTime->tm_sec
         << " ]";
}

void TextColor(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


void cmd(){ system("title ⚙️🛠️CMDBox "); int cmd; 
    do{system("cls");cout<<"\n\n";
        cout << "\t 1. Software                            \n";
        cout << "\t 2. Hardware                           \n";
        cout << "\t 3. Networking                          \n";
        cout << "\t 4. Fix error && system maintenance     \n";
        cout << "\t 5. Administration and systems          \n";
        cout << "\t 6. Setup CMD                           \n";
        cout << "\t 7. tiện ích nhanh                      \n";
        cout << "\t 8.return             0. Exit        \n";
        cout << "\t--> "; cin >> cmd;
        switch(cmd){
            case 1:{
                do{system("cls");cout<<"\n\n";
                    cout << "\t 1. LIỆT KÊ PHẦN MỀM TẢI VỀ \n";
                    cout << "\t 2. QUẢN LÝ TIẾN TRÌNH \n";
                    cout << "\t 3. CONTROL PANEL      \n";
                    cout << "\t 4. GỠ APP TRÊN CONTROL\n";
                    cout << "\t 5. RETURN    0.EXIT   \n";
                    cout<<"\t--> ";cin>>cmd;
                    switch(cmd){
                        case 1:{system("cls");system("wmic product get name,version");system("pause");}break;
                        case 2:{system("cls");system("tasklist");system("pause");}break;
                        case 3:{system("control");}break;
                        case 4:{system("control appwiz.cpl");}break;
                        case 0:{exit(0);}break;
                    }
                }while(cmd!=5);
            }break;
            case 2:{
                do{system("cls");cout<<"\n\n";
                    cout << "\t 1. THÔNG TIN CPU       2. THÔNG TIN RAM       \n";
                    cout << "\t 3. Ổ CỨNG VẬT LÝ       4. Ổ ĐĨA LOGIC         \n";                    
                    cout << "\t 5. DANH SÁCH DRIVER    6. BÁO CÁO PIN(laptop) \n";                    
                    cout << "\t 7. CÔNG CỤ DIRECTX     8. ĐỘ SÁNG MÀN HÌNH    \n";
                    cout << "\t 9. CARD MÀN HÌNH       10. TẮT MÀN HÌNH       \n";                    
                    cout << "\t 11. MAINBOARD          12. BIOS               \n";
                    cout << "\t 13. THÔNG TIN Ổ CỨNG                          \n";
                    cout << "\t 14. RETURN                  0. EXIT  \n";
                    cout<<"\t---> ";cin>>cmd;
                    switch(cmd){
                        case 1:{system("wmic cpu get name, maxclockspeed");system("pause");}break;
                        case 2:{system("wmic memorychip get capacity, speed");system("pause");}break;
                        case 3:{system("wmic diskdrive get model, size");system("pause");}break;
                        case 4:{system("wmic logicaldisk get name, size, freespace");system("pause");}break;
                        case 5:{system("driverquery");system("pause");}break;
                        case 6:{system("powercfg /batteryreport");system("start battery-report.html");}break;
                        case 7:{system("dxdiag");}break;
                        case 8:{ system("cls"); cout << "\n\n"; int number;
                            do{ system("cls");
                                cout << "\tĐỘ SÁNG (1 --> 100) | Thoát = 0 : ";  cin >> number;
                                cout << "\n";

                                if (number == 0) break; // Thoát vòng lặp nếu nhập 0

                                if (number < 1 || number > 100){
                                    cout << "\t⚠️  Sai giá trị! Nhập từ 1 đến 100.\n\n";
                                    Sleep(1000);
                                    continue; // Quay lại đầu vòng lặp
                                }
                                string cmd = "powershell -Command \"(Get-WmiObject -Namespace root/wmi -Class WmiMonitorBrightnessMethods).WmiSetBrightness(1," + to_string(number) + ")\"";
                                system(cmd.c_str());
                            } while (true);
                            break;
                        }
                        case 9:{system("wmic path win32_VideoController get name");system("pause");}break;
                        case 10:{system("powershell (Add-Type '[DllImport(\"user32.dll\")]^public static extern int SendMessage(int hWnd, int hMsg, int wParam, int lParam);' -name a -pas)::SendMessage(-1, 0x0112, 0xF170, 2)");}break;
                        case 11:{system("wmic baseboard get Manufacturer, Product, SerialNumber, Version");system("pause");}break;
                        case 12:{system("wmic bios get Caption, Manufacturer, ReleaseDate, SMBIOSBIOSVersion, Version");system("pause");}break;
                        case 13:{system("wmic diskdrive get Status");system("pause");}break;
                        case 0:{exit(0);}break;
                    }
                }while(cmd!=14);
            }break;
            case 3:{
                do{system("cls");cout<<"\n\n";
                    cout << "\t 1. XEM IP VÀ CẤU HÌNH MẠNG   \n";
                    cout << "\t 2. CẬP NHẬT IP               \n";
                    cout << "\t 3. MẬT KHẨU WIFI             \n";
                    cout << "\t 4. RETURN        0.EXIT      \n";
                    cout<<"\t--> ";cin>>cmd;
                    switch(cmd){
                        case 1:{system("cls");system("ipconfig/all");system("pause");}break;
                        case 2:{system("cls");system("ipconfig/renew");system("pause");}break;
                        case 3:{}break;
                        case 0:{exit(0);}break;
                    }
                }while(cmd!=4);
            }break;
            case 4:{
                do{system("cls");cout<<"\n\n";
                    cout << "\t 1. XÓA RÁC Ổ CỨNG            \n";
                    cout << "\t 2. XÓA RÁC THƯ MỤC 'TEMP     \n";
                    cout << "\t 3. KHỞI ĐỘNG MÁY             \n";
                    cout << "\t 4. QUÉT NHANH VIRUS          \n";
                    cout << "\t 5. QUÉT FULL VIRUS           \n";
                    cout << "\t 6. QUÉT & SỬA FILE LỖI       \n";
                    cout << "\t 7. QUÉT Ổ CỨNG               \n";
                    cout << "\t 8. return         0. Exit    \n"; 
                    cout << "\t--> "; cin >> cmd;
                    switch(cmd){
                        case 1:{system("cleanmgr");}break;
                        case 2:{system("rd /s /q \"%TEMP%\" && md \"%TEMP%\"");system("pause");}break;
                        case 3:{system("shutdown /r /t 0");}break;
                        case 4:{
                            cout << "\n\tĐang quét virus nhanh. Vui lòng chờ...\n";
                            system("cmd /c \"\"%ProgramFiles%\\Windows Defender\\MpCmdRun.exe\" -Scan -ScanType 1\"");
                            system("pause");
                        }break;
                        case 5:{
                            cout << "\n\tĐang thực hiện quét virus toàn bộ. Quá trình này có thể mất nhiều thời gian. Vui lòng chờ...\n";
                            system("cmd /c \"\"%ProgramFiles%\\Windows Defender\\MpCmdRun.exe\" -Scan -ScanType 2\"");
                            system("pause");
                        }break;
                        case 6:{string command="sfc/scannow";
                            string powershell_cmd = "powershell -Command \"Start-Process cmd -Verb RunAs -ArgumentList '/k " + command + "'\"";
                            system(powershell_cmd.c_str());
                        }break;
                        case 7:{string command="chkdsk";
                            string powershell_cmd = "powershell -Command \"Start-Process cmd -Verb RunAs -ArgumentList '/k " + command + "'\"";
                            system(powershell_cmd.c_str());
                        }break;
                        case 0:{exit(0);}break;
                        }
                }while(cmd!=8);
            }break;
            case 5:{
                do{system("cls");cout<<"\n\n";
                    cout << "\t 1. task manager        2. registry          \n";
                    cout << "\t 3. quản lý dịch vụ     4. quản lý thiết bị  \n";
                    cout << "\t 5. quản lý máy tính    6. khóa máy tạm thời \n";
                    cout << "\t 7. tắt windows update  8. bật windows update\n";
                    cout << "\t 9. return                         0. Exit   \n";
                    cout<<"\t--> ";cin>>cmd;
                    switch(cmd){
                        case 1:{system("taskmgr");}break;
                        case 2:{system("regedit");}break;
                        case 3:{system("services.msc");}break;
                        case 4:{system("devmgmt.msc");}break;
                        case 5:{system("compmgmt.msc");}break;
                        case 6:{system("rundll32.exe user32.dll,LockWorkStation");}break;
                        case 7:{system("net stop wuauserv && sc config wuauserv start= disabled");}break;
                        case 8:{system("sc config wuauserv start= demand && net start wuauserv");}break;
                        case 0:{exit(0);}break;
                    }
                }while(cmd!=9);
            }break;
            case 6:{
                do{system("cls");cout<<"\n\n";
                    cout<<"\t1. COLOR    2. return\n";                    
                    cout<<"\t--> ";cin>>cmd;
                    switch(cmd){
                     case 1:{int color;
                     do{ system("cls"); cout << "\n\n";
                        cout << "\t\t 1.  XANH TRỜI           2.  XANH LÁ CÂY       " << endl;
                        cout << "\t\t 3.  XANH NƯỚC BIỂN      4.  ĐỎ                " << endl;
                        cout << "\t\t 5.  TÍM                 7.  TRẮNG             " << endl;
                        cout << "\t\t 7.  TRẮNG               30. NỀN XANH,CHỮ TRẮNG" << endl;
                        cout << "\t\t 79. NỀN ĐỎ,CHỮ TRẮNG    87. NỀN TÍM,CHỮ TRẮNG " << endl;
                        cout << "\t\t           6.MENU          0 .EXIT             " << endl;
                        cout << "\t\t--> "; cin >> color;
                        if (color == 1)TextColor(1); if (color == 2) TextColor(2);
                        if (color == 3) TextColor(3); if (color == 4) TextColor(4);
                        if (color == 5) TextColor(5); if (color == 7) TextColor(7);
                        if (color == 30)TextColor(30); if (color == 79) TextColor(79);
                        if (color == 87) TextColor(87); if (color == 0) exit(0);
                    } while (color!=6);
                     }break;
                    }
                }while(cmd!=2);
            }break;
            case 7:{
                do{system("cls");cout<<"\n\n";
                    cout<<"\t1. danh sách thời tiết\n";
                    cout<<"\t2. thời tiết cụ thể\n";
                    cout<<"\t3. return\n";
                    cout<<"\t--> ";cin>>cmd;
                    switch(cmd){
                        case 1:{system("cls");cout<<"\n\n";
                        string cities[] = {"Hanoi", "Haiphong", "Danang", "Saigon", "Cantho", "Hue", "Nhatrang", "Vinh", "Thanhhoa", "Quangngai", "Quinhon", "Pleiku", "Buonmathuot", "Dalat", "Longxuyen", "Mytho", "CaMau", "Rachgia", "Tuyhoa", "Phanthiet", "Haiduong", "Backan", "Bacgiang", "Baclieu", "Bacninh", "BenTre", "BinhDinh", "BinhDuong", "BinhPhuoc", "BinhThuan", "Camau", "Caobang", "DienBien", "DongNai", "DongThap", "GiaLai", "HaGiang", "HaNam", "HaTinh", "HoaBinh", "HungYen", "KhanhHoa", "KienGiang", "KonTum", "LaiChau", "LamDong", "LangSon", "LaoCai", "LongAn", "NamDinh", "NgheAn", "NinhBinh", "NinhThuan", "PhuTho", "PhuYen", "QuangBinh", "QuangNam", "QuangNgai", "QuangNinh", "SocTrang", "SonLa", "TayNinh", "ThaiBinh", "ThaiNguyen", "ThanhHoa", "ThuaThienHue", "TienGiang", "TraVinh", "TuyenQuang", "VinhLong", "VinhPhuc", "YenBai"};
                        for (string city : cities){
                            string cmd = "powershell -Command \"(Invoke-WebRequest 'https://wttr.in/" + city + "?format=3').Content\""; system(cmd.c_str());
                        } system("pause");
                        }break;
                        case 2:{string city;  system("cls");cout<<"\n\n";
                            cout<<"\t1.Hanoi\t2.Haiphong\t3.Danang\t4.Saigon\t5.Vinh-Nghean\t6.Hue\n";
                            cout<<"\t--> ";cin>>cmd;
                            if(cmd==1){
                                city="Hanoi";
                                 string cmd = "powershell -Command \"(Invoke-WebRequest 'https://wttr.in/" + city + "?format=3').Content\"";
                                 system(cmd.c_str()); system("pause");
                            }  
                            if(cmd==2){
                                city="Haiphong";
                                 string cmd = "powershell -Command \"(Invoke-WebRequest 'https://wttr.in/" + city + "?format=3').Content\"";
                                system(cmd.c_str()); system("pause");
                            }  
                            if(cmd==3){city="Danang";
                                string cmd = "powershell -Command \"(Invoke-WebRequest 'https://wttr.in/" + city + "?format=3').Content\"";
                                system(cmd.c_str()); system("pause");
                            }
                            if(cmd==4){
                                city="Saigon";
                                 string cmd = "powershell -Command \"(Invoke-WebRequest 'https://wttr.in/" + city + "?format=3').Content\"";
                                system(cmd.c_str()); system("pause");
                            }
                            if(cmd==5){
                                city="Vinh";
                                 string cmd = "powershell -Command \"(Invoke-WebRequest 'https://wttr.in/" + city + "?format=3').Content\"";
                                system(cmd.c_str()); system("pause");
                            }
                            if(cmd==6){
                                city="Hue";
                                 string cmd = "powershell -Command \"(Invoke-WebRequest 'https://wttr.in/" + city + "?format=3').Content\"";
                                system(cmd.c_str()); system("pause");
                            }
                        }break;
                    }
                }while(cmd!=3);
            }break;
            case 0:{exit(0);}break;
            }
    }while(cmd!=8);
}


void study(){int study; system("title STUDY");
    do{system("cls");cout<<"\n\n";
        cout << "\t 1.MATH THPT        2.TÍNH NHANH" << endl;              
        cout << "\t 3.RETURN           0.EXIT   " << endl;               
        cout << "\t-->: "; cin >> study;
        switch(study){
            case 1:{system("title MATH THPT"); float pi = 3.14159, a, b, c, d, e, x, a2, b2, c2, a3, b3, c3, r,x2,y2,z2,x3,y3,z3, l,z, y,h;system("title MATH THPT");
                do{ system("cls"); cout << "\n\n";
                    cout << "\t\t 1. GIẢI PT                       " << endl;
                    cout << "\t\t 2. CĂN BẬC (2,3,4,5)             " << endl;
                    cout << "\t\t 3. TÍCH VÔ HƯỚNG 2 VECTO        " << endl;
                    cout << "\t\t 4. HÌNH NÓN-TRỤ-CẦU             " << endl;
                    cout << "\t\t 5. TÍCH CÓ HƯỚNG VÀ ỨNG DỤNG    " << endl;
                    cout << "\t\t 6. KHOẢNG CÁCH GIỮA 2 ĐIỂM      " << endl;
                    cout << "\t\t 7. return    0.exit  \n";
                    cout << "\t\t-->: "; cin >>study;
                    switch (study) {
                    case 1:{
                    do{system("cls");cout<<"\n\n";                        
                        cout << "\t\t 1.AX^2 + BX + C ( (BẬC 2)              " << endl;
                        cout << "\t\t 2.A.X^3 + B.X^2 + C.X^1 + D (BẬC 3)    " << endl;
                        cout << "\t\t 3.A.X^4 + B.X^2 + C (BẬC 4)            " << endl;
                        cout << "\t\t 4.A.X^4 + B.X^3 + C.X^2 +DX + E (BẬC 4) coming soon" << endl; 
                        cout << "\t\t 5.GIẢI PT 2 ẨN                         " << endl;
                        cout << "\t\t 6.GIẢI PT 3 ẨN                         " << endl;
                        cout << "\t\t 7. return    0.exit  \n";
                        cout<<"\t\t--> ";cin>>study;// 4 chx xong
                        switch(study){
                            case 1:{  system("cls"); cout << "\n\n";
                                cout << "\tA: "; cin >> a;  cout << "\tB: "; cin >> b;  cout << "\tC: ";  cin >> c;
                               
                                system("cls"); cout << "\n\n";
                                cout << "\tF(X)= 0 <=> f(x)=" << a << "X^2" << " + " << b << "X + " << c << " = 0\n";
                                cout << "\tF'(X)= 0 <=> F'(X)= " << a * 2 << "X" << " + " << b << "\n\n";
                    
                                float delta = pow(b, 2) - (4 * a * c);
                    
                                if (delta > 0) {
                                    cout << "\tX1= " << (-b + sqrt(delta)) / (2 * a);
                                    cout << "\tX2= " << (-b - sqrt(delta)) / (2 * a);
                                } else {
                                    if (delta == 0)  cout << "\tNO KEP ==> X= " << -b / (2 * a);
                                    else             cout << "\tVO NGHIEM";
                                }
                    
                                cout << "\n\n";  system("pause");
                            } break;
                            case 2:{ system("cls"); cout << "\n\n";
                                cout << "\tA(A!=0): "; cin >> a;  cout << "\tB: "; cin >> b;  cout << "\tC: "; cin >> c;  cout << "\tD: "; cin >> d; 
                                system("cls"); cout << "\n\n\n";
                    
                                cout << "\tf(x)= " << a << "X^3 + " << b << "X^2 + " << c << "X" << " + " << d << " = 0" << endl << endl;
                                cout << "\tF'(X)= 0 <=> F'(X)= " << 3 * a << "X^2" << " + " << 2 * b << "x" << " + " << c * 1 << " = 0 \n\n";
                    
                                float delta = pow(2 * b, 2) - 4 * 3 * a * c;
                    
                                if (delta > 0) {
                                    // công thức x1,x2
                                    float x1_bac3 = (-2 * b + sqrt(delta)) / (6 * a), x2_bac3 = (-2 * b - sqrt(delta)) / (6 * a);
                                    float x1_bac3_thanh_y1 = (a * pow(x1_bac3, 3)) + (b * pow(x1_bac3, 2)) + (c * x1_bac3) + d, x2_bac3_thanh_y2 = (a * pow(x2_bac3, 3)) + (b * pow(x2_bac3, 2)) + (c * x2_bac3) + d;
                                    // 3*a*2*pow(x1_bac3,1) là đạo hàm y'' của y để tính điều kiện cho chuẩn
                    
                                    cout << "\t\tX1: " << x1_bac3 << " ==> Y: " << x1_bac3_thanh_y1 << " ==> ";
                                    if (3 * a * 2 * pow(x1_bac3, 1) > 0) cout << "Yct";
                                    else                                 cout << "Ycd"; // Dùng f'' kiểm tra
                    
                                    cout << "\n\n";
                                    cout << "\t\tX2: " << x2_bac3 << " ==> Y: " << x2_bac3_thanh_y2 << " ==> ";
                                    if (3 * a * 2 * pow(x2_bac3, 1) > 0)  cout << "Yct";
                                    else                                  cout << "Ycd"; // f'' = 6ax
                                }
                    
                                if (delta == 0) {
                                    float no_kep = -2 * b / (6 * a);
                                    cout << "\tNGHIEM KEP: " << no_kep << endl;
                                }
                    
                                if (delta < 0)  cout << "\t vo nghiem\n\n";
                                system("pause");
                            }break;
                            case 3:{  system("cls"); cout << "\n\n";
                                cout << "\tA: "; cin >> a;   cout << "\tB: "; cin >> b;   cout << "\tC: "; cin >> c;
                              system("cls");  cout << "\n\n";
            
                                if (a == 0){  cout << "Đây không phải hàm bậc 4!" << endl;  break; }
                    
                                float check = -b / (2 * a); // để kiểm tra nghiệm thực
                                if (check < 0){
                                    cout << "\tF(x) = " << a << "x^4 + " << b << "x^2 + " << c << endl;
                                    cout << "\tF'(x) = " << 4 * a << "x^3 + " << 2 * b << "x" << endl << endl;
                                    cout << "\tX0 = 0 => Y: " << c << " ";
                                    float dao_ham_lan2 = 2 * b;
                                    if (dao_ham_lan2 > 0)        cout << "\t CỰC TIỂU";
                                    else if (dao_ham_lan2 < 0)   cout << "\t CỰC ĐẠI";
                                    else                         cout << "\t loading...";
                                }else{
                                    // đạo hàm có 3 nghiệm
                                    float x1_bac4 = sqrt(check), x2_bac4 = sqrt(check);
                                    float y0 = c;
                                    float y1_bac4 = a * pow(x1_bac4, 4) + b * pow(x1_bac4, 2) + c;
                                    float y2_bac4 = y1_bac4;
                    
                                    // đạo hàm bậc 2 tại các điểm
                                    float fx_lan2 = 2 * b;
                                    float daohamlan2_fx1 = 12 * a * pow(x1_bac4, 2) + 2 * b;
                                    float daohamlan2_fx2 = daohamlan2_fx1;
                                    cout << "\tF(x) = " << a << "x^4 + " << b << "x^2 + " << c << endl;
                                    cout << "\tF'(x) = " << 4 * a << "x^3 + " << 2 * b << "x" << endl << endl;
                    
                                    // tinnh x0
                                    cout << "\tX0= 0 <=> y: " << y0 << " ";
                                    if (fx_lan2 > 0)       cout << "\t CỰC TIỂU";
                                    else if (fx_lan2 < 0)  cout << "\t CỰC ĐẠI";
                                    else                   cout << "\t loading... ";
                                    cout << "\n";
                    
                                    // tinh x1
                                    cout << "\tX1= " << x1_bac4 << " ==y: " << y1_bac4 << " ";
                                    if (daohamlan2_fx1 > 0)       cout << "\t CỰC TIỂU";
                                    else if (daohamlan2_fx1 < 0)  cout << "\t CỰC ĐẠI";
                                    else                          cout << "\t loading...";
                                    cout << "\n";
                    
                                    // tinh x2
                                    cout << "\tX2= " << x2_bac4 << " ==y: " << y2_bac4 << " ";
                                    if (daohamlan2_fx2 > 0)       cout << "\t CỰC TIỂU";
                                    else if (daohamlan2_fx2 < 0)  cout << "\t CỰC ĐẠI";
                                    else                          cout << "\t loading...";
                                    cout << "\n";
                                }
                    
                                cout << "\n\n"; system("pause");
                            } break;
                            case 4:{system("cls");cout<<"\n\n";
                            cout<<"\ta: ";cin>>a;cout<<"\tb: ";cin>>b;cout<<"\tc: ";cin>>c;cout<<"\td: ";cin>>d;cout<<"\te: ";cin>>e;
                            system("cls");cout<<"\n\n";
            
                            cout<<"\tY=0 <=> Y= "<<a<<"x^4 + "<<b<<"x^3 + "<<c<<"x^2 + "<<d<<"x + "<<e<<" = 0\n";
                            cout<<"\tY'=0 <=> Y= "<<4*a<<"x^3 + "<<3*b<<"x^2 + "<<2*c<<"x + "<<d<<" = 0\n";
                            cout<<"\tY''=0 <=> Y''= "<<12*a<<"x^2 + "<<6*b<<"x + "<<2*c<<" = 0\n\n";
            
                            }break;
                            case 5:{
                            do{system("cls");cout<<"\n\n";
                                cout<<"\t1. 2PT    2. 3PT     3. RETURN   0.EXIT\n";
                                cout<<"\t--> ";cin>>study;
                                switch(study){
                                    case 1:{system("cls");cout<<"\n\n";
                                        cout<<"\ta(!=0): ";cin>>a; cout<<"\tb: ";cin>>b; cout<<"\tc: ";cin>>c; cout<<"\ta2: ";cin>>a2; cout<<"\tb2: ";cin>>b2; cout<<"\tc2: ";cin>>c2;
                                        system("cls");cout<<"\n";
                                        cout<<"\t      {"<<a<<"x + "<<b<<"y = "<<c<<" (1)\n";
                                        cout<<"\tPT <=>{\n";
                                        cout<<"\t      {"<<a2<<"x + "<<b2<<"y = "<<c2<<" (2)\n\n\n";
                                        
                                        if(a*b2==a2*b)  cout<<"\tPT VO NGHIEM HOAC VO SO NGHIEM\n";
                                        
                                        float x=(c*b2-c2*b)/(a*b2-a2*b);
                                        float y=(c-a*x)/b;
                                        cout<<"\tX= "<<x<<endl;
                                        cout<<"\tY= "<<y<<endl;
                    
                                        cout<<"\n";system("pause");
                                    }break;
                                    case 2:{system("cls");cout<<"\n\n";int a,b,c,a2,b2,c2,a3,b3,c3;
                                    cout<<"\ta: ";cin>>a;cout<<"\tb: ";cin>>b;cout<<"\tc: ";cin>>c;cout<<"\ta2: ";cin>>a2;cout<<"\tb2: ";cin>>b2;cout<<"\tc2: ";cin>>c2;cout<<"\ta3: ";cin>>a3;cout<<"\tb3: ";cin>>b3;cout<<"\tc3: ";cin>>c3;
                                   
                                    system("cls");cout<<"\n\n";
                                    cout<<"\t{"<<a<<"x + "<<b<<"y = "<<c<<endl;
                                    cout<<"\t{"<<a2<<"x + "<<b2<<"y = "<<c2<<endl;
                                    cout<<"\t{"<<a3<<"x + "<<b3<<"y = "<<c3<<endl;
                                    cout<<"\n\n";

                                    int del_d=a*b2-a2*b;
                                    int del_dx=c*b2-c2*b;
                                    int del_dy=a*c2-a2*c;
                                    float x=(float)del_dx/del_d,  y=(float)del_dy/del_d;

                                    cout<<"\tX= "<<x<<endl;
                                    cout<<"\tY= "<<y<<"\n\n";

                                    int thaynghiem=a3*x+b3*y;
                                    cout<<"\tCHECK: ";
                                    if(thaynghiem==c3){ cout<<"✅\n"; }
                                    else{ cout<<"✖️\n";}   system("pause");
                                    }break;
                                    case 0:exit(0);
                                }
                            }while(study!=3);
                            }break;
                            case 6:{system("cls");cout<<"\n\n";int a, b, c, d, a2, b2, c2, d2, a3, b3, c3, d3;
                                cout << "\ta1: "; cin >> a;  cout << "\tb1: "; cin >> b; cout << "\tc1: "; cin >> c;  cout << "\td1: "; cin >> d; cout << "\ta2: "; cin >> a2; cout << "\tb2: "; cin >> b2;cout << "\tc2: "; cin >> c2; cout << "\td2: "; cin >> d2;cout << "\ta3: "; cin >> a3; cout << "\tb3: "; cin >> b3; cout << "\tc3: "; cin >> c3; cout << "\td3: "; cin >> d3;
                                system("cls"); cout<<"\n\n";
                                cout << "\t    {" << a << "x + " << b << "y + " << c << "z = " << d << endl;
                                cout << "\t    {" << a2 << "x + " << b2 << "y + " << c2 << "z = " << d2 << endl;
                                cout << "\t    {" << a3 << "x + " << b3 << "y + " << c3 << "z = " << d3 << endl;
                                cout << "\n";
                            
                                //  delA
                                int delA = a * (b2 * c3 - c2 * b3) - b * (a2 * c3 - c2 * a3) + c * (a2 * b3 - b2 * a3);
                            
                                // Kiểm tra delA
                                if (delA == 0) {
                                    int del_aX = d * (b2 * c3 - c2 * b3) - b * (d2 * c3 - c2 * d3) + c * (d2 * b3 - b2 * d3);
                                    int del_aY = a * (d2 * c3 - c2 * d3) - d * (a2 * c3 - c2 * a3) + c * (a2 * d3 - d2 * a3);
                                    int del_aZ = a * (b2 * d3 - d2 * b3) - b * (a2 * d3 - d2 * a3) + d * (a2 * b3 - b2 * a3);
                            
                                    if (del_aX == 0 && del_aY == 0 && del_aZ == 0) {
                                        cout << "\tHe phuong trinh co vo so nghiem.\n";
                                    } else { cout << "\tHe phuong trinh vo nghiem.\n"; }
                                }
                            
                                // del_aX, del_aY, del_aZ
                                int del_aX = d * (b2 * c3 - c2 * b3) - b * (d2 * c3 - c2 * d3) + c * (d2 * b3 - b2 * d3);
                                int del_aY = a * (d2 * c3 - c2 * d3) - d * (a2 * c3 - c2 * a3) + c * (a2 * d3 - d2 * a3);
                                int del_aZ = a * (b2 * d3 - d2 * b3) - b * (a2 * d3 - d2 * a3) + d * (a2 * b3 - b2 * a3);
                            
                                // Tính nghiệm
                                float x = (float)del_aX / delA, y = (float)del_aY / delA, z = (float)del_aZ / delA;
                            
                                // In kết quả
                                cout << "\tX = " << x << endl;
                                cout << "\tY = " << y << endl;
                                cout << "\tZ = " << z << endl;
                            
                                // T kiểm tra
                                cout << "\n\tKiem tra nghiem:\n";
                                float ktra1 = a * x + b * y + c * z;
                                float ktra2 = a2 * x + b2 * y + c2 * z;
                                float ktra3 = a3 * x + b3 * y + c3 * z;
                                cout << "\tPt 1-> " << ktra1 << " ->d1 = " << d <<"\n";
                                cout << "\tPt 2-> " << ktra2 << " ->d2 = " << d2 <<"\n";
                                cout << "\tPt 3-> " << ktra3 << " ->d3 = " << d3 <<"\n";
                            system("pause");
                            }break;
                            case 0:{exit(0);}break;
                        }
                    }while(study!=7);
                    }break;
                    case 2:{
                        system("cls"); cout << "\n\n";
                        cout << "\t SỐ A: "; cin >> a;
                        system("cls");cout << "\n\n";
            
                        if (a < 0){
                            cout << "\tCAN BAC 2 CUA " << a << " = Khong thuc\n";
                            cout << "\t------- 3 CUA " << a << " = " << cbrt(a) << endl;
                            cout << "\t------- 4 CUA " << a << " = Khong thuc\n";
                            cout << "\t------- 5 CUA " << a << " = " << pow(a, 1.0 / 5.0) << endl; 
                        }else{
                            cout << "\tCAN BAC 2 CUA " << a << " = " << sqrt(a) << endl;
                            cout << "\t------- 3 CUA " << a << " = " << cbrt(a) << endl;
                            cout << "\t------- 4 CUA " << a << " = " << sqrt(sqrt(a)) << endl; 
                            cout << "\t------- 5 CUA " << a << " = " << pow(a, 1.0 / 5.0) << endl;
                        }
                        system("pause");
                    }break;
                    case 3:{ system("cls"); cout << "\n\n";
                        cout << "\t QUY ƯỚC '' LÀ VECTO :))\n\n";
                        cout << "\t1.AB\t2.COS('A','B')\t3.|'A'|\n\n";
                        cout << "\tX: "; cin >> a;    cout << "\tY: "; cin >> b;  cout << "\tX2: "; cin >> a2;  cout << "\tY2: "; cin >> b2;
                        cout << "\n\n";
            
                        cout << "\tA(" << a << "," << b << ")\tB(" << a2 << "," << b2 << ")\n";
                        cout << "\tAB: " << sqrt(pow(a2 - a, 2) + pow(b2 - b, 2)) << endl << endl;
            
                        cout << "\tA(" << a << "," << b << ")\tB(" << a2 << "," << b2 << ")\n";
                        cout << "\tCOS('A','B')= " << ((a * b) + (b * b2)) / sqrt(pow(a, 2) + pow(a2, 2)) * sqrt(pow(b, 2) + pow(b2, 2)) << endl << endl;
            
                        cout << "\t|'A'|= (" << a << "," << a2 << ")" << endl;
                        cout << "\tKQ= " << sqrt(pow(a, 2) + pow(a2, 2)) << endl<< endl;
                        system("pause");
                    }break;
                    case 4: { system("cls"); cout << "\n\n";
                        cout << "\tH: "; cin >> h;  cout << "\tR: "; cin >> r;  cout << "\tL: "; cin >> l;
            
                        system("cls"); cout << "\n\n";
                        cout << "\t HÌNH NÓN\n";
                        cout << "\t DIỆN TÍCH XUNG QUANH: " << pi * r * l << endl;
                        cout << "\t DIỆN TÍCH ĐÁY: " << pi * pow(r, 2) << endl;
                        cout << "\t DIỆN TÍCH TOÀN PHẦN: " << (pi * r * l) + (pi * pow(r, 2)) << endl;
                        cout << "\t THỂ TÍCH :" << (1.0 / 3.0) * pi * pow(r, 2) * h <<"\n\n";
            
                        cout << "\t HÌNH TRỤ\n";
                        cout << "\t DIỆN TÍCH XUNG QUANH: " << 2 * pi * r * h << endl;
                        cout << "\t DIỆN TÍCH ĐÁY: " << 2 * pi * pow(r, 2) << endl;
                        cout << "\t DIỆN TÍCH TOÀN PHẦN: " << (2 * pi * r * h) + (2 * pi * pow(r, 2)) << endl;
                        cout << "\t THỂ TÍCH: " << pi * pow(r, 2) * h <<"\n\n";
            
                        cout << "\t HÌNH CẦU\n";
                        cout << "\t DIỆN TÍCH HÌNH CẦU: " << 4 * pi * pow(r, 2) << endl;
                        cout << "\t THỂ TÍCH HÌNH CẦU: " << double(4.0 / 3.0) * pi * pow(r, 3) <<"\n\n";
                        system("pause");
                    } break;
                    case 5:{
                        do{ system("cls"); cout << "\n\n";
                            cout << "\t\t   1.TÍCH CÓ HƯỚNG                      " << endl;
                            cout << "\t\t   2.DIỆN TÍCH TAM GIÁC ABC             " << endl;
                            cout << "\t\t   3.DIỆN TÍCH HÌNH BÌNH HÀNH ABCD      " << endl;
                            cout << "\t\t   4.THỂ TÍCH KHỐI HỢP ABCD.A'B'C'D'    " << endl;
                            cout << "\t\t   5.THỂ TÍCH TỨ DIỆN ABCD              " << endl;
                            cout << "\t\t   6.RETURN  0.EXIT  \n";
                            cout << "\t\t--> "; cin >>study;
                            switch (study){
                            case 1:{ system("cls");cout << "\n\n";
                                cout << "\tX(A,B,C)\tB(A2,B2,C2)\n\n";
                                cout << "\tA: ";cin >> a;  cout << "\tB: "; cin >> b; cout << "\tC: "; cin >> c; cout << "\tA2: "; cin >> a2; cout << "\tB2: "; cin >> b2; cout << "\tC2: "; cin >> c2;cout<<"\tA3: ";cin>>a3;cout<<"\tB3: ";cin>>b3;cout<<"\tC3:";cin>>c3;
                                system("cls");cout << "\n\n";
            
                                cout<<"\tA("<<a<<","<<b<<","<<c<<") B("<<a2<<","<<b2<<","<<c2<<") C("<<a3<<","<<b3<<","<<c3<<")"<<"\n";
                                cout<<"\tAB=("<<a2-a<<","<<b2-b<<","<<c2-c<<") AC=("<<a3-a<<","<<b3-b<<","<<c3-c<<")\n";
                                cout<<"\tSabc= "<<1/2.0*sqrt(pow(((b2-b)*(c3-c))-((b3-b)*(c2-c)),2)+pow(((a2-a)*(c3-c))-((a3-a)*(c2-c)),2)+ pow(((a2-a)*(b3-b))-((a3-a)*(b2-b)),2))  <<"\n\n";system("pause");
                            }break;
                            case 2: { system("cls"); cout << "\n\n";
                                cout<<"\tA(a,b,c)\tB(a2,b2,c2)\tC(a3,b3,c3)\n\n";
                                cout << "\tA: "; cin >> a; cout << "\tB: "; cin >> b; cout << "\tC :"; cin >> c;cout << "\tA2: ";  cin >> a2; cout << "\tB2: "; cin >> b2; cout << "\tC2: ";cin >> c2;  cout << "\tA3: "; cin >> a3; cout << "\tB3: "; cin >> b3; cout << "\tC3: "; cin >> c3;
                                system("cls");cout << "\n\n";
                                cout << "\t A(" << a << "," << b << "," << c << ")  B(" << a2 << "," << b2 << "," << c2 << ")  C(" << a3 << "," << b3 << "," << c3 << ")"<<"\n\n";
                                cout << "\t AB=(" << a2 - a << "," << b2 - b << "," << c2 - c << ")\n";
                                cout << "\t AC= (" << a3 - a << "," << b3 - b << "," << c3 - c << ")\n\n";
                                cout << "\t [AB,AC] = [" <<((b2-b)*(c3-c))-((b3-b)*(c2-c))<<","<<((a2-a)*(c3-c))-((a3-a)*(c2-c))<<","<<((a2-a)*(b3-b))-((a3-a)*(b2-b)) << "]\n";
                                cout << "\t DO DAI AB,AC= " << sqrt(pow(((b2-b)*(c3-c))-((b3-b)*(c2-c)), 2) + pow(((a2-a)*(c3-c))-((a3-a)*(c2-c)), 2) + pow(((a2-a)*(b3-b))-((a3-a)*(b2-b)), 2)) << endl;
                                cout << "\t Sabc = " << 1 / 2.0 * sqrt(pow(((b2-b)*(c3-c))-((b3-b)*(c2-c)), 2) + pow(((a2-a)*(c3-c))-((a3-a)*(c2-c)), 2) + pow(((a2-a)*(b3-b))-((a3-a)*(b2-b)), 2)) <<"\n\n"; system("pause");
                            } break;
                            case 3:{system("cls");cout<<"\n\n";
                            cout<<"\tA(X,Y,Z) B(X2,Y2,Z3) D(X3,Y3,Z3)\n\n";
                            cout<<"\tX: ";cin>>x; cout<<"\tY: ";cin>>y; cout<<"\tZ: ";cin>>z; cout<<"\tX2: ";cin>>x2;cout<<"\tY2: ";cin>>y2;cout<<"\tZ2: ";cin>>z2; cout<<"\tX3: ";cin>>x3; cout<<"\tY3: ";cin>>y3; cout<<"\tZ3: ";cin>>z3;
                            system("cls");cout<<"\n\n";
            
                            cout<<"\tA("<<x<<","<<y<<","<<z<<") B("<<x2<<","<<y2<<","<<z2<<") D("<<x3<<","<<y3<<","<<z3<<")\n\n";
                            cout<<"\tAB= ("<<x2-x<<","<<y2-y<<","<<z2-z<<")  AD= ("<<x3-x<<","<<y3-y<<","<<z3-z<<")\n\n";
                            cout<<"\t[AB,AD]= "<<"["<<((y2-y)*(z3-z))-((y3-y)*(z2-z))  <<","<< ((x2-x)*(z3-z))-((x3-x)*(z2-z)) <<","<<((x2-x)*(y3-y))-((x3-x)*(y2-y))<<"]\n";
                            cout<<"\tSabcd= "<<sqrt(pow(((y2-y)*(z3-z))-((y3-y)*(z2-z)),2) + pow(((x2-x)*(z3-z))-((x3-x)*(z2-z)),2) + pow(((x2-x)*(y3-y))-((x3-x)*(y2-y)),2))<<"\n\n";system("pause");
                            }break;
                            case 4:{system("cls");cout<<"\n\n";
                                cout<<"\tA(X,Y,Z) B(X2,Y2,Z3) D(X3,Y3,Z3)\n\n";
                                cout<<"\tX: ";cin>>x; cout<<"\tY: ";cin>>y; cout<<"\tZ: ";cin>>z; cout<<"\tX2: ";cin>>x2;cout<<"\tY2: ";cin>>y2;cout<<"\tZ2: ";cin>>z2; cout<<"\tX3: ";cin>>x3; cout<<"\tY3: ";cin>>y3; cout<<"\tZ3: ";cin>>z3;cout<<"\tA: ";cin>>a;cout<<"\tB: ";cin>>b;cout<<"\tC: ";cin>>c;
                                system("cls");cout<<"\n\n";
                
                                cout<<"\tA("<<x<<","<<y<<","<<z<<") B("<<x2<<","<<y2<<","<<z2<<") D("<<x3<<","<<y3<<","<<z3<<") A'("<<a<<","<<b<<","<<c<<")\n\n";
                                cout<<"\tAB= ("<<x2-x<<","<<y2-y<<","<<z2-z<<")  AD= ("<<x3-x<<","<<y3-y<<","<<z3-z<<") AA'("<<a-x<<","<<b-y<<","<<c-z<<")"<<"\n\n";
                                cout<<"\t[AB,AD]= "<<"["<<((y3-y)*(z2-z))-((y2-y)*(z3-z))<<","<< ((x3-x)*(z2-z))-((x2-x)*(z3-z))<<","<<((x3-x)*(y2-y))-((x2-x)*(y3-y)) <<"]\n\n";
                                cout<<"\t[AB,AD]AA'= "<<(((y3-y)*(z2-z))-((y2-y)*(z3-z))*(a-x)) + ( ((x3-x)*(z2-z))-((x2-x)*(z3-z))*(b-y)) + (((x3-x)*(y2-y))-((x2-x)*(y3-y))*(c-z))<<"\n\n"; system("pause");
                            }break;
                            case 5: { system("cls"); cout << "\n\n";
                                cout << "\tA(X,Y,Z) B(X2,Y2,Z3) C(X3,Y3,Z3) D(X4,Y4,Z4)\n\n";
                                cout << "\tX: "; cin >> x; cout << "\tY: "; cin >> y; cout << "\tZ: "; cin >> z; cout << "\tX2: "; cin >> x2; cout << "\tY2: "; cin >> y2; cout << "\tZ2: "; cin >> z2; cout << "\tX3: "; cin >> x3; cout << "\tY3: "; cin >> y3; cout << "\tZ3: "; cin >> z3;cout << "\tA: "; cin >> a; cout << "\tB: "; cin >> b; cout << "\tC: "; cin >> c;
                                system("cls"); cout << "\n\n";
                            
                                cout << "\tA(" << x << "," << y << "," << z << ") B(" << x2 << "," << y2 << "," << z2 << ") C(" << x3 << "," << y3 << "," << z3 << ") D(" << a << "," << b << "," << c << ")\n\n";
                                cout << "\tAB= (" << x2 - x << "," << y2 - y << "," << z2 - z << ")  AC= (" << x3 - x << "," << y3 - y << "," << z3 - z << ") AD(" << a - x << "," << b - y << "," << c - z << ")" << "\n";
                                cout << "\t[AB,AC]=[" << ((y2 - y) * (z3 - z) - (y3 - y) * (z2 - z)) << ","  << -((x2 - x) * (z3 - z) - (x3 - x) * (z2 - z)) << ","  << ((x2 - x) * (y3 - y) - (x3 - x) * (y2 - y)) << "]\n";
                            
                                double tichvohuong = (((y2 - y) * (z3 - z) - (y3 - y) * (z2 - z)) * (a - x)) +(-((x2 - x) * (z3 - z) - (x3 - x) * (z2 - z))) * (b - y) +(((x2 - x) * (y3 - y) - (x3 - x) * (y2 - y))) * (c - z);
                                cout << "\t[AB.AC].AD=" <<tichvohuong << "\n";             
                                cout << "\tKQ= " << fabs(tichvohuong) / 6.0 << "\n\n"; system("pause");
                            } break;
                            case 0:{exit(0);}break;
                            }
                        } while (study != 6);
                    } break;
                    case 6:{ system("cls"); cout << "\n\n";
                        cout << "\tA: "; cin >> a; cout << "\tB: ";  cin >> b; cout << "\tC: "; cin >> c; cout << "\tA2: "; cin >> a2; cout << "\tB2: ";cin >> b2; cout << "\tC2: "; cin >> c2;
                        system("cls");cout<<"\n\n\n";
                        cout << "\tA(" << a << "," << b << "," << c << ")\tB(" << a2 << "," << b2 << "," << c2 << ")\n";
                        cout << "\tKQ= " << sqrt(pow(a2 - a, 2) + pow(b2 - b, 2) + pow(c2 - c, 2)) <<"\n\n";
                        system("pause");
                    } break;
                    case 0: exit(0);
                    }
                } while (study != 7);
            }break;
            case 2:{system("title TÍNH NHANH");
                do{system("cls");cout<<"\n\n";
                    cout << "\t 1. TÍNH NHANH SỐ N        2. TÌM SỐ CHÍNH PHƯƠNG ĐẾN N " << endl;   
                    cout << "\t 3. TÍNH HÌNH TRÒN         4. TÍNH HÌNH VUÔNG           " << endl;
                    cout << "\t 5. TÍNH HÌNH CHỮ NHẬT     6. TÍNH HÌNH TAM GIÁC        " << endl;  
                    cout << "\t 7. C(n,k) | A(n,k)                                     " << endl;        
                    cout << "\t 8.RETURN                                     0.EXIT   " << endl;               
                    cout << "\t-->: ";cin >> study;
                    switch(study){
                        case 1:{system("cls");cout<<"\n\n";int n;
                        cout<<"\tN: ";cin>>n;

                        int tong=0;
                        for(int i=1;i<=n;i++) tong+=i;
                        cout<<"\t1+...N: "<<tong<<endl;

                        long long tich=1;
                        for(int i=1;i<=n;i++) tich*=i;
                        cout<<"\t1*...N: "<<tich<<endl;

                        float thuong_n=1;
                        for(int i=1;i<=n;i++) thuong_n+=(float)1/i;
                        cout<<"\t1 + 1/2 + ...1/N: "<<thuong_n<<endl;

                        double mu_n;
                        for(int i=1;i<=n;i++) mu_n+=pow(i,2);
                        cout<<"\t1^2 +...+ n^2: "<<mu_n<<endl;

                        int n_giaithua=1;
                        for(int i=1;i<=n;i++)n_giaithua*=i;
                        cout<<"\t"<<n<<"! : "<<n_giaithua<<endl;

                        int sum=0;
                        for(int i=1;i<=n;i++){
                            tich*=i;  sum+=tich;
                        }
                        cout<<"\t1!+..N!= "<<sum<<endl;system("pause");
                        }break;
                        case 2:{cout<<"\n";int n;
                        cout<<"\tN: ";cin>>n;
                        for(int i=1;i<=n;i++){
                            if(sqrt(i)==(int)sqrt(i)){cout<<"\t "<<" "<<i<<" ";}
                        }cout<<"\n"; system("pause");
                        }break;
                        case 3:{cout<<"\n";int r;
                        cout<<"\tR: ";cin>>r;
                        cout<<"\tCHU VI: "<<2*3.14*r<<" | DIỆN TÍCH: "<< 3.14*pow(r,2)<<"\n\n"; system("pause");
                        }break;
                        case 4:{ cout<<"\n";int a;
                        cout<<"\tA: ";cin>>a;
                        cout<<"\tCHU VI: "<<4*a<<" | DIỆN TÍCH: "<<pow(a,2)<<" | ĐƯỜNG CHÉO: "<<a*sqrt(2)<<"\n\n";system("pause");
                        }break;
                        case 5:{cout<<"\n";int a,b;
                        cout<<"\tA: ";cin>>a;cout<<"\tB: ";cin>>b;
                        cout<<"\tCHU VI: "<<2*(a+b)<<" | DIỆN TÍCH: "<<a*b<<" | ĐỘ DÀI ĐƯỜNG CHÉO: "<<sqrt(pow(a,2)+pow(b,2))<<"\n\n";system("pause");
                        }break;
                        case 6:{cout<<"\n";int canha,canhb,canhc;
                        cout<<"\tA: ";cin>>canha;cout<<"\tB: ";cin>>canhb;cout<<"\tC: ";cin>>canhc;
                        cout<<"\tCHU VI: "<<canha+canhb+canhc<<"\n\n";system("pause");
                        }break;
                        case 7:{cout<<"\n\n";
                        long long n,k,n_k=1,n_gt=1,k_gt=1,n_giaithua=1,nk_giaithua=1;

                        cout<<"\tN: ";cin>>n; cout<<"\tK: ";cin>>k;
                        for(int i=1;i<=n;i++) n_gt*=i;
                        for(int i=1;i<=k;i++) k_gt*=i;
                        for(int i=1;i<=(n-k);i++)  n_k*=i;
                        long long a=n_gt/(k_gt*n_k);
                        cout<<"\tC(n,k): "<<a<<endl;

                        for (int i = 1; i <= n; i++) n_giaithua *= i;
                        for (int i = 1; i <= (n - k); i++) nk_giaithua *= i;
                        long long c=n_giaithua/nk_giaithua;
                        cout<<"\tA(n,k): "<<c<<endl; system("pause");
                        }break;
                        case 0: exit(0);
                    }
                } while (study != 8);
            }break;
            case 0:{exit(0);}break;
        }
    }while(study!=3);
}


void data(){int data;
        do{ system("cls"); cout << "\n\n";
            cout << "\t 1.DUNG LƯỢNG    2.TIME         " << endl;
            cout << "\t 3.TRADING       4.MÃ HÓA TEXT  " << endl;   
            cout << "\t 5.TIỀN ĐIỆN     6.TÍNH LẠM PHÁT" << endl;                          
            cout << "\t 0.EXIT          7.RETURN   " << endl;              
            cout<<"\t--> ";cin>>data;
            switch (data){
            case 1:{  double bit, byte, kilobyte, megabyte, gigabyte;
                do{ system("cls"); cout << "\n\n";
                    cout << "\t1. GB -> MB                   " << endl;
                    cout << "\t2. MB -> KB, GB               " << endl;
                    cout << "\t3. KB -> BYTE, MB             " << endl;
                    cout << "\t4. BYTE -> BIT, KB            " << endl;
                    cout << "\t5. BIT  -> BYTE, KB           " << endl;
                    cout << "\t6. BIT + BYTE + KB + MB -> GB " << endl;
                    cout << "\t7. BIT + BYTE + KB + GB -> MB " << endl;
                    cout << "\t8.RETURN         0.EXIT     " << endl<<endl;
                    cout << "\t--> ";cin >> data;
                    switch (data) {
                    case 1:{
                        cout << "\tGB: "; cin >> gigabyte;
                        cout << gigabyte << " GB= " << gigabyte * 1024 << " MB" << endl; system("pause");
                    } break;
                    case 2:{
                        cout << "\tMB: "; cin >> megabyte;
                        cout << megabyte << " MB= " << megabyte * 1024 << " KB" << endl;
                        cout << megabyte << " MB= " << megabyte * 0.0009765625 << " GB" << endl; system("pause");
                    } break;
                    case 3: {
                        cout << "\tKB: "; cin >> kilobyte;
                        cout << kilobyte << " KB= " << kilobyte * 1024 << " BYTE" << endl;
                        cout << kilobyte << " KB= " << kilobyte * 0.0009765625 << " MB" << endl; system("pause");
                    } break;
                    case 4: {
                        cout << "\tBYTE: ";  cin >> byte;
                        cout << byte << " BYTE= " << byte * 8 << " BIT" << endl;
                        cout << byte << " BYTE= " << byte * 0.0009765625 << " KB" << endl; system("pause");
                    } break;
                    case 5:{
                        cout << "\tBIT: ";cin >> bit;
                        cout << bit << " BIT= " << bit * 0.125 << " BYTE" << endl;
                        cout << bit << " BIT= " << bit * 0.0001220703125 << " KB" << endl; system("pause");
                    } break;
                    case 6: {
                        cout << "\tBIT: "; cin >> bit;cout << "\tBYTE: "; cin >> byte; cout << "\tKB: "; cin >> kilobyte;  cout << "\tMB: ";cin >> megabyte;
                        cout << "\tKQ = " << (bit * 1.1641532182693 * pow(10, -10)) + (byte * 9.3132257461548 * pow(10, -10)) + (kilobyte * 9.5367431640625 * pow(10, -7)) + (megabyte * 0.0009765625) << " GB" << endl; system("pause");
                    } break;
                    case 7: {
                        cout << "\tBIT: "; cin >> bit; cout << "\tBYTE: "; cin >> byte; cout << "\tKB: "; cin >> kilobyte; cout << "\tGB: "; cin >> gigabyte;
                        cout<<"\n\n";
                        cout << "\tKQ = " << (bit * 1.1920928955078 * pow(10, -7)) + (byte * 9.5367431640625 * pow(10, -7)) + (kilobyte * 0.0009765625) + (gigabyte * 1024) << " MB" << endl; system("pause");
                    }break;
                    case 0:{exit(0);}break;
                    }
                } while (data!=8);
            } break;
            case 2:{ double day, hour, minute, ms, second, thapky, theky, thiennienky;int datetime;
                do{ cout << "\n\n";system("cls");cout<<"\n\n";
                    cout << "\t 1. THẬP KỶ = NĂM           " << endl;
                    cout << "\t 2. THIÊN NIÊN KỶ = NĂM     " << endl;
                    cout << "\t 3. THẾ KỶ = NĂM            " << endl;
                    cout << "\t 4. NGÀY = (GIỜ,PHÚT,GIÂY)  " << endl;
                    cout << "\t 5. GIỜ = (NGÀY,PHÚT,GIÂY)  " << endl;
                    cout << "\t 6. PHÚT = (NGÀY,GIỜ,GIÂY)  " << endl;
                    cout << "\t 7. MILI GIÂY = (GIÂY,PHÚT) " << endl;
                    cout << "\t 8. GIỜ+PHÚT+GIÂY = GIỜ     " << endl;
                    cout << "\t 9. GIỜ+PHÚT+GIÂY = PHÚT    " << endl;
                    cout << "\t 10.GIỜ+PHÚT+GIÂY = GIÂY    " << endl;   
                    cout << "\t 11.RETURN       0.EXIT     " << endl;
                    cout << "\tCHOOSE: ";cin >> datetime;
                    switch (datetime){
                    case 1: {system("cls");cout << "\t THẬP KỶ: "; cin >> thapky;
                        cout << thapky << " THẬP KỶ = " << thapky * 10 << " NĂM" << endl; system("pause"); }break;
                    case 2: {system("cls");
                        cout << "\t THIÊN NHIÊN KỶ: ";cin >> thiennienky;
                        cout << thiennienky << " THIÊN NIÊN KỶ = " << thiennienky * 1000 << " NĂM" << endl; system("pause"); } break;
                    case 3: {   system("cls"); cout << "\t THẾ KỶ: ";cin >> theky;
                        cout << theky << " THẾ KỶ = " << theky * 100 << " NĂM" << endl; system("pause"); } break;
                    case 4:{ system("cls");
                        cout << "\tBAO NHIÊU NGÀY: "; cin >> day;
                        cout << day << " NGÀY = " << day * 24 << " GIỜ" << endl;
                        cout << day << " NGÀY = " << day * 1440 << " PHÚT " << endl;
                        cout << day << " NGÀY = " << day * 86400 << " GIÂY " << endl;  system("pause"); } break;
                    case 5: {
                        system("cls"); cout << "\t GIỜ: "; cin >> hour;
                        cout << hour << " GIỜ = " << hour * (0.04167) << " NGÀY" << endl;
                        cout << hour << " GIỜ = " << hour * 60 << " PHÚT" << endl;
                        cout << hour << " GIỜ = " << hour * 3600 << " GIÂY" << endl; system("pause"); } break;
                    case 6: { system("cls"); cout << "\t PHÚT: "; cin >> minute;
                        cout << minute << " PHÚT = " << minute * 0.000694444444 << " NGÀY" << endl;
                        cout << minute << " PHÚT = " << hour * (0.01667) << " GIỜ" << endl;
                        cout << minute << " PHÚT = " << minute * 60 << " GIÂY" << endl; system("pause"); } break;
                    case 7:  { system("cls");
                        cout << "\tMILI GIÂY: "; cin >> ms;
                        cout << ms << " MILI GIÂY = " << ms * 0.0000166667 << " PHÚT" << endl;
                        cout << ms << " MILI GIÂY = " << ms * 0.001 << " PHÚT" << endl; system("pause"); } break;
                    case 8: {
                        system("cls"); cout << "\tGIỜ: "; cin >> hour;
                        cout << "\tPHÚT: ";cin >> minute; cout << "\tGIÂY: ";cin >> second;
                        cout << hour << "GIỜ+" << minute << "PHÚT+" << second << "GIÂY= " << hour + (0.01667) + (0.00027778) << " GIỜ" << endl; system("pause"); }  break;
                    case 9:{
                        system("cls");cout << "\tGIỜ: "; cin >> hour;
                        cout << "\tPHÚT: ";cin >> minute;
                        cout << "\tGIÂY: ";cin >> second;
                        cout << hour << "GIỜ+" << minute << "PHÚT+" << second << "GIÂY= " << (hour * 60) + minute + (0.01667) << " PHÚT" << endl; system("pause"); }break;
                    case 10:{
                         system("cls");cout<<"\tGIỜ: ";cin>>hour;cout<<"\tPHÚT: ";cin>>minute;cout<<"\tGIÂY: ";cin>>second;
                         cout<<hour<<"GIỜ+"<<minute<<"PHÚT+"<<second<<"GIÂY= "<<(hour*3600)+(minute*60)+second<<" GIÂY"<<endl;system("pause"); }break;
                    case 0:{exit(0);}break;
                       }
                } while (datetime!=11);
            }break;
            case 3: {system("title TRADE");system("cls");cout<<"\n\n";
                cout<<"\t1.BUY/SELL      2.FUTURE DCA\n";
                cout<<"\t--> ";cin>>data;
                if(data==1){ system("cls");cout<<"\n\n";     
                    double money, input, output,phi_trade;
                    cout << fixed << setprecision(2);

                    cout << "\n\n\t💰USD: ";  cin >> money;
                    cout << "\t📉 GIÁ MUA COIN : "; cin >> input;
                    cout << "\t📈 GIÁ BÁN COIN: "; cin >> output;
                    cout << "\t💰 PHÍ TRADE(%): "; cin >> phi_trade;

                    cout << "\n\n\t📊 ĐANG TÍNH TOÁN...\n";Sleep(500);

                    float sl_coin = money / (input*(1+phi_trade/100));
                    float ban_coin = sl_coin * output*(1-phi_trade/100);
                    float loi_and_lo = ban_coin - money;
                    float person = (loi_and_lo / money) * 100;

                    cout << "\n\t🪙 SỐ LƯỢNG COIN MUA ĐƯỢC: " << sl_coin << " COIN";
                    cout << "\n\t💵 TIỀN THU VỀ : " << ban_coin << " USD";

                    if (loi_and_lo > 0){
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // xanh lá
                        cout << "\n\t📈 LỢI NHUẬN: +" << loi_and_lo << " USD";
                    }
                    else if (loi_and_lo < 0) {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // đỏ
                        cout << "\n\t📉 LỖ: " << loi_and_lo << " USD";
                    } else { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // trắng
                      cout << "\n\t⚖️ HÒA VỐN";}

                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // vàng
                    cout << "\n\t📌 TỈ LỆ %: " << person << " %\n\n";

                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // reset về màu trắng
                    system("pause");
                }

                if(data==2){system("cls");cout<<"\n\n";
                    cout<<"\t1.SHORT\t2.LONG\n";
                    cout<<"\t--> ";cin>>data;
                    if(data==1){
                        double base_usd,entry_price,step_percent,leverage;
                        int max_orders;

                    }
                }
            }break;
            case 4:{system("cls");cout<<"\n\n";
            string text;
            cout<<"\tTEXT: ";cin.ignore(); // cin.ignore giúp bỏ qua ký tự \n trong bộ nhớ
            getline(cin,text); // getline(cin, ?) đọc văn bản :)) 
            // hoa/thuong
            for(char &ch : text){
                bitset<8> binary(ch);
                if(ch>='a' && ch<='z') ch=ch-32;
                else{
                    if (ch>='A' && ch<='Z') ch=ch+32;
                }
            }
            cout<<"\t--> "<<text<<endl;
            // nhị phân
            string nhi_phan = "";
            for (char ch : text) {
                bitset<8> b(ch);
                nhi_phan += b.to_string() + " ";
            }
            cout<<"\t--> "<<nhi_phan<<endl;
            //ký tự đặc biệt
            string kytudacbiet = "";
            string kytu = "!@#$%^&*()_+=-[]{};:<>?";
            for (char ch : text) {
                kytudacbiet += kytu[ch % kytu.size()];
            }
            cout<<"\t--> "<<kytudacbiet<<endl;
            cout<<"\n"; system("pause");
            }break;
            case 5:{
                do{system("cls");cout<<"\n\n";
                    cout<<"\t1.TIỀN ĐIỆN/THÁNG     2.TIỀN ĐIỆN/N THÁNG     3.RETURN\n";
                    cout<<"\t--> ";cin>>data;
                    switch(data){
                        case 1:{int kwh;
                        float money;
                        cout<<"\n\n";
                        cout<<"\t KWH: ";cin>>kwh;
                        cout<<"\t TIỀN: ";cin>>money;
                        float cantra=kwh*money;
                        cout<<"\n\t--> "<<cantra<<".000 VND"<<endl<<endl; system("pause");
                        }break;
                        case 2:{system("cls");cout<<"\n\n";
                        int sothang;
                        double money;
                        int so_kwh[100];
                        cout<<"\t TIỀN ĐIỆN (loại bỏ .000): ";cin>>money;
                        cout<<"\t SỐ THÁNG: ";cin>>sothang;

                        for(int i=0;i<sothang;i++){
                            cout<<"\t THÁNG "<<i+1<<" KWH:  ";cin>>so_kwh[i];
                        }
                        int tong_kwh;
                        float tb_kwh;
                        double tb_money;
                        system("cls");cout<<"\n\n";
                        for(int i=0;i<sothang;i++){tong_kwh+=so_kwh[i];  tb_kwh=(float)tong_kwh/sothang*1.0;  tb_money=(double)tong_kwh*4.0/sothang;
                            cout<<"\t THÁNG "<<i+1<<" KWH: "<<so_kwh[i]<<" | TỔNG TIỀN: "<<so_kwh[i]*money<<".000"<<endl;
                        }
                        cout<<"\n\n\t TỔNG WHK: "<<tong_kwh<<" * GIÁ ĐIỆN "<<money<<".000 --> TỔNG: "<<tong_kwh*money<<".000 VND"<<endl;
                        cout<<"\t KWH TRUNG BÌNH "<<sothang<<" THÁNG: "<<tb_kwh<<endl;
                        cout<<"\t TIỀN ĐIỆN TRUNG BINH "<<sothang<<" THÁNG: "<<tb_money<<".000"<<"\n\n";   system("pause");
                        }break;
                    }
                }while(data!=3);
            }break;
            case 6:{cout<<"\n\n";  float CPI_hientai,CPI_goc;
            cout<<"\t GIÁ GỐC: ";cin>>CPI_goc;
            cout<<"\t GIÁ HIỆN TẠI: ";cin>>CPI_hientai;

            float lamphat=(CPI_hientai-CPI_goc)/CPI_goc*100;
            cout<<"\n\tKQ: "<<lamphat<<"%"<<"\n\n"; system("pause");
            }break;
            case 0:{exit(0);}break;
            }
        }while(data!=7);
}


void hdsd(){system("cls"); cout << "\n\n";system("title HDSD");
    cout << "┌─────────────────────────────────────────────────────────────────┐" << endl;
    cout << "│         HƯỚNG DẪN CÀI ĐẶT TIẾNG VIỆT CHO CODE                   │" << endl;
    cout << "├─────────────────────────────────────────────────────────────────┤" << endl;
    cout << "│B1: MỞ CONTROL PANEL                                             │" << endl;
    cout << "│NẾU KHÔNG CÓ THÌ GÕ (WIN +R) NHẬP 'CMD'--> NHẬP 'CONTROL PANEL'  │" << endl;
    cout << "│B2: NHẬP CHANGE DATE, TIME OR NUMBER FORMATS                     │" << endl;
    cout << "│B3: ADMINISTRATIVE                                               │" << endl;
    cout << "│B4: CHANGE SYSTEM LOCAL                                          │" << endl;
    cout << "│B5: TÍCH VÀO Ô Beta: Use Unicode UTF-8                           │" << endl;
    cout << "│B6: BẮT BUỘC KHỞI ĐỘNG LẠI MÁY                                   │" << endl;
    cout << "└─────────────────────────────────────────────────────────────────┘" << endl << endl; system("pause");
}

void introduction() {
    TextColor(10); // Xanh lá
    cout << "\tZalo: 0966030929\n";

    TextColor(11); // Xanh dương nhạt
    cout << "\tmail: hcao84539@gmail.com\n";

    TextColor(13); // Tím
    cout << "\tcre: huiinguyen\n";

    TextColor(7);  // Trả lại màu trắng mặc định
    cout << "\n\n";
}


void code_header(){int home; system("title HOME ");
    do{ system("cls");cout<<"\n\n";
        introduction();
        cout << "\t 1.DATA        2.STUDY " << endl;
        cout << "\t 3.CMD         4.HDSD " << endl;
        cout << "\t 5.SETTING     6.DALUONG" << endl;
        cout << "\t 0.EXIT    " << endl;
        cout << "\t--> ";cin >> home;
        switch (home){ 
        case 1:{data();}break; 
        case 2:{ study(); }break; 
        case 3:{ cmd();}break;
        case 4:{ hdsd(); } break;
        case 5:{ system("title SETTING");          
            do{ system("cls");cout<<"\n\n";
                cout << "\t 1.COLOR       2.CHẾ ĐỘ MÁY BAY    0.EXIT      5.RETURN " << endl;           
                cout<<"\t--> ";cin>>home;
                switch (home){
                case 1:{int color;
                    do{ system("cls"); cout << "\n\n";
                        cout << "\t\t 1.  XANH TRỜI           2.  XANH LÁ CÂY       " << endl;
                        cout << "\t\t 3.  XANH NƯỚC BIỂN      4.  ĐỎ                " << endl;
                        cout << "\t\t 5.  TÍM                 7.  TRẮNG           " << endl;
                        cout << "\t\t 30. NỀN XANH,CHỮ TRẮNG  79. NỀN ĐỎ,CHỮ TRẮNG" << endl;
                        cout << "\t\t 87. NỀN TÍM,CHỮ TRẮNG                       " << endl;                     
                        cout << "\t\t 6.MENU          0 .EXIT " << endl;
                        cout << "\t\tCHOOSE: "; cin >> color;
                        if (color == 1)TextColor(1);   if (color == 2) TextColor(2);
                        if (color == 3) TextColor(3);  if (color == 4) TextColor(4);
                        if (color == 5) TextColor(5);  if (color == 7) TextColor(7);
                        if (color == 30)TextColor(30); if (color == 79) TextColor(79);
                        if (color == 87) TextColor(87); if (color == 0) exit(0);
                    } while (color!=6);
                } break;
                case 2:{
                do{system("cls");cout<<"\n\n";
                cout << "\t   1.ONL      2.OFF   3.RETURN     0.EXIT  " << endl;               
                cout<<"\t--> ";cin>>home;
                switch(home){
                    case 1:{ system("powershell.exe -Command \"(Get-WmiObject -Namespace root/WMI -Class MSPower_DeviceEnable).Enable()\"");}break;
                    case 2:{ system("powershell.exe -Command \"(Get-WmiObject -Namespace root/WMI -Class MSPower_DeviceEnable).Disable()\"");}break; 
                    case 0:{exit(0);}break;
                }}while(home!=3);
                }break;
                case 0:{exit(0);}break;
            }
            }while(home!=5); 
        }break;
        case 6:{cout<<"\n";int daluong;
        cout<<"\t--> ";cin>>daluong;
        for(int i=1;i<=daluong;i++){
            system("cmd/c start base_ver3");
        }
        }break; 
    }
    }while(home!=0);
}

int main(){   
    code_header();
    return 0;
}
