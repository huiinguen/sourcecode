#include <iostream>
#include <windows.h>
#include <string>
#include <math.h>
#include <fstream>
#include <vector>

using namespace std;
void Textsetup(int setup) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), setup); }

void software(){int software;
    do{system("cls"); cout << "\n\n";
        cout << "\t╭───────────────────────────────────────────────────╮\n";
        cout << "\t│ 1. LIỆT KÊ PHẦN MỀM TẢI VỀ  2. QUẢN LÝ TIẾN TRÌNH │\n";
        cout << "\t│ 3. CONTROL PANEL            4. GỠ APP TRÊN CONTROL│\n";
        cout << "\t├───────────────────────────────────────────────────┤\n";
        cout << "\t│ 5. RETURN                             0.EXIT      │\n";
        cout << "\t╰───────────────────────────────────────────────────╯\n";
        cout << "\t--> ";cin >> software;
        switch (software){
        case 1:{system("cls");system("wmic product get name,version");system("pause");
        }break;
        case 2:
        {
            system("cls");
            system("tasklist");
            system("pause");
        }
        break;
        case 3:
        {
            system("control");
        }
        break;
        case 4:
        {
            system("control appwiz.cpl");
        }
        break;
        case 0:
        {
            exit(0);
        }
        break;
        }
    } while (software != 5);
}

void hardware()
{
    int hardware, number;
    do
    {
        system("cls");
        cout << "\n\n";
        cout << "\t╭───────────────────────────────────────────────╮\n";
        cout << "\t│ 1. THÔNG TIN CPU       2. THÔNG TIN RAM       │\n";
        cout << "\t│ 3. Ổ CỨNG VẬT LÝ       4. Ổ ĐĨA LOGIC         │\n";
        cout << "\t│ 5. DANH SÁCH DRIVER    6. BÁO CÁO PIN(laptop) │\n";
        cout << "\t│ 7. CÔNG CỤ DIRECTX     8. ĐỘ SÁNG MÀN HÌNH    │\n";
        cout << "\t│ 9. CARD MÀN HÌNH       10. TẮT MÀN HÌNH       │\n";
        cout << "\t│ 11. MAINBOARD          12. BIOS               │\n";
        cout << "\t│ 13. THÔNG TIN Ổ CỨNG                          │\n";
        cout << "\t├───────────────────────────────────────────────┤\n";
        cout << "\t│ 14. RETURN                           0. EXIT  │\n";
        cout << "\t╰───────────────────────────────────────────────╯\n";
        cout << "\t---> ";
        cin >> hardware;
        switch (hardware)
        {
        case 1:
        {
            system("wmic cpu get name, maxclockspeed");
            system("pause");
        }
        break;
        case 2:
        {
            system("wmic memorychip get capacity, speed");
            system("pause");
        }
        break;
        case 3:
        {
            system("wmic diskdrive get model, size");
            system("pause");
        }
        break;
        case 4:
        {
            system("wmic logicaldisk get name, size, freespace");
            system("pause");
        }
        break;
        case 5:
        {
            system("driverquery");
            system("pause");
        }
        break;
        case 6:
        {
            system("powercfg /batteryreport");
            system("start battery-report.html");
        }
        break;
        case 7:
        {
            system("dxdiag");
        }
        break;
        case 8:
        {
            system("cls");
            cout << "\n\n";
            int number;
            do
            {
                system("cls");
                cout << "\tĐỘ SÁNG (1 --> 100) | Thoát = 0 : ";
                cin >> number;
                cout << "\n";

                if (number == 0)
                    break; // Thoát vòng lặp nếu nhập 0

                if (number < 1 || number > 100)
                {
                    cout << "\t⚠️  Sai giá trị! Nhập từ 1 đến 100.\n\n";
                    Sleep(1000);
                    continue; // Quay lại đầu vòng lặp
                }
                string cmd = "powershell -Command \"(Get-WmiObject -Namespace root/wmi -Class WmiMonitorBrightnessMethods).WmiSetBrightness(1," + to_string(number) + ")\"";
                system(cmd.c_str());
            } while (true);
            break;
        }
        case 9:
        {
            system("wmic path win32_VideoController get name");
            system("pause");
        }
        break;
        case 10:
        {
            system("powershell (Add-Type '[DllImport(\"user32.dll\")]^public static extern int SendMessage(int hWnd, int hMsg, int wParam, int lParam);' -name a -pas)::SendMessage(-1, 0x0112, 0xF170, 2)");
        }
        break;
        case 11:
        {
            system("wmic baseboard get Manufacturer, Product, SerialNumber, Version");
            system("pause");
        }
        break;
        case 12:
        {
            system("wmic bios get Caption, Manufacturer, ReleaseDate, SMBIOSBIOSVersion, Version");
            system("pause");
        }
        break;
        case 13:
        {
            system("wmic diskdrive get Status");
            system("pause");
        }
        break;
        case 0:
        {
            exit(0);
        }
        break;
        }
    } while (hardware != 14);
}

void networking()
{
    int networking;
    do
    {
        system("cls");
        cout << "\n\n";
        cout << "\t╭──────────────────────────────╮\n";
        cout << "\t│ 1. XEM IP VÀ CẤU HÌNH MẠNG   │\n";
        cout << "\t│ 2. CẬP NHẬT IP               │\n";
        cout << "\t│ 3. MẬT KHẨU WIFI             │\n";
        cout << "\t├──────────────────────────────┤\n";
        cout << "\t│ 4. RETURN        0.EXIT      │\n";
        cout << "\t╰──────────────────────────────╯\n";
        cout << "\t--> ";
        cin >> networking;
        switch (networking)
        {
        case 1:
        {
            system("cls");
            system("ipconfig/all");
            system("pause");
        }
        break;
        case 2:
        {
            system("cls");
            system("ipconfig/renew");
            system("pause");
        }
        break;
        case 3:
        {
        }
        break;
        case 0:
        {
            exit(0);
        }
        break;
        }
    } while (networking != 4);
}

void fix_error_and_system_maintenance()
{
    int fix;
    do
    {
        system("cls");
        cout << "\n\n";
        cout << "\t╭──────────────────────────────╮\n";
        cout << "\t│ 1. XÓA RÁC Ổ CỨNG            │\n";
        cout << "\t│ 2. XÓA RÁC THƯ MỤC 'TEMP     │\n";
        cout << "\t│ 3. KHỞI ĐỘNG MÁY             │\n";
        cout << "\t│ 4. QUÉT NHANH VIRUS          │\n";
        cout << "\t│ 5. QUÉT FULL VIRUS           │\n";
        cout << "\t│ 6. QUÉT & SỬA FILE LỖI       │\n";
        cout << "\t│ 7. QUÉT Ổ CỨNG               │\n";
        cout << "\t├──────────────────────────────┤\n";
        cout << "\t│ 8. return         0. Exit    │\n";
        cout << "\t╰──────────────────────────────╯\n";
        cout << "\t--> ";
        cin >> fix;
        switch (fix)
        {
        case 1:
        {
            system("cleanmgr");
        }
        break;
        case 2:
        {
            system("rd /s /q \"%TEMP%\" && md \"%TEMP%\"");
            system("pause");
        }
        break;
        case 3:
        {
            system("shutdown /r /t 0");
        }
        break;
        case 4:
        {
            cout << "\n\tĐang quét virus nhanh. Vui lòng chờ...\n";
            system("cmd /c \"\"%ProgramFiles%\\Windows Defender\\MpCmdRun.exe\" -Scan -ScanType 1\"");
            system("pause");
        }
        break;
        case 5:
        {
            cout << "\n\tĐang thực hiện quét virus toàn bộ. Quá trình này có thể mất nhiều thời gian. Vui lòng chờ...\n";
            system("cmd /c \"\"%ProgramFiles%\\Windows Defender\\MpCmdRun.exe\" -Scan -ScanType 2\"");
            system("pause");
        }
        break;
        case 6:
        {
            string command = "sfc/scannow";
            string powershell_cmd = "powershell -Command \"Start-Process cmd -Verb RunAs -ArgumentList '/k " + command + "'\"";
            system(powershell_cmd.c_str());
        }
        break;
        case 7:
        {
            string command = "chkdsk";
            string powershell_cmd = "powershell -Command \"Start-Process cmd -Verb RunAs -ArgumentList '/k " + command + "'\"";
            system(powershell_cmd.c_str());
        }
        break;
        case 0:
        {
            exit(0);
        }
        break;
        }
    } while (fix != 8);
}

void administrator_and_system(){ int admin;
    do{
        system("cls");  cout << "\n\n";
        cout << "\t╭─────────────────────────────────────────────╮\n";
        cout << "\t│ 1. task manager        2. registry          |\n";
        cout << "\t│ 3. quản lý dịch vụ     4. quản lý thiết bị  │\n";
        cout << "\t│ 5. quản lý máy tính    6. khóa máy tạm thời │\n";
        cout << "\t│ 7. tắt windows update  8. bật windows update│\n";
        cout << "\t├─────────────────────────────────────────────┤\n";
        cout << "\t│ 9. return                         0. Exit   │\n";
        cout << "\t╰─────────────────────────────────────────────╯\n";
        cout << "\t--> "; cin >> admin;
        switch (admin){
        case 1:system("taskmgr"); break;
        case 2:system("regedit");break;
        case 3:system("services.msc");break;
        case 4:system("devmgmt.msc");break;
        case 5:system("compmgmt.msc");break;
        case 6:system("rundll32.exe user32.dll,LockWorkStation");break;
        case 7:system("net stop wuauserv && sc config wuauserv start= disabled");break;
        case 8:system("sc config wuauserv start= demand && net start wuauserv");break;
        case 0:exit(0);
        break;
        }
    } while (admin != 9);
}

void setup(){int setup;
        do{  system("cls"); cout << "\n\n";
            cout << "\t\t╭───────────────────────────────────────────────╮" << endl;
            cout << "\t\t│                    BẢNG MÀU                   │" << endl;
            cout << "\t\t├───────────────────────────────────────────────┤" << endl;
            cout << "\t\t│ 1.  XANH TRỜI           2.  XANH LÁ CÂY       │" << endl;
            cout << "\t\t│ 3.  XANH NƯỚC BIỂN      4.  ĐỎ                │" << endl;
            cout << "\t\t│ 5.  TÍM                 7.  TRẮNG             │" << endl;
            cout << "\t\t│ 7.  TRẮNG               30. NỀN XANH,CHỮ TRẮNG│" << endl;
            cout << "\t\t│ 79. NỀN ĐỎ,CHỮ TRẮNG    87. NỀN TÍM,CHỮ TRẮNG │" << endl;
            cout << "\t\t├───────────────────────────────────────────────┤" << endl;
            cout << "\t\t│           6.MENU          0 .EXIT             │" << endl;
            cout << "\t\t╰───────────────────────────────────────────────╯" << endl;
            cout << "\t\tCHOOSE: "; cin >> setup;
            if (setup == 1)Textsetup(1);
            if (setup == 2)Textsetup(2);
            if (setup == 3)Textsetup(3);
            if (setup == 4)Textsetup(4);
            if (setup == 5)Textsetup(5);
            if (setup == 7)Textsetup(7);
            if (setup == 30)Textsetup(30);
            if (setup == 79)Textsetup(79);
            if (setup == 87)Textsetup(87);
            if (setup == 0)exit(0);
        } while (setup != 6);
}

void tien_ich(){ int tien_ich;
    do{
                system("cls");  cout << "\n\n";
                cout << "\t1. danh sách thời tiết\n";
                cout << "\t2. thời tiết cụ thể\n";
                cout << "\t3. return\n";
                cout << "\t--> ";cin >> tien_ich;
                switch (tien_ich){
                case 1:{  system("cls");
                    cout << "\n\n";
                    string cities[] = {"Hanoi", "Haiphong", "Danang", "Saigon", "Cantho", "Hue", "Nhatrang", "Vinh", "Thanhhoa", "Quangngai", "Quinhon", "Pleiku", "Buonmathuot", "Dalat", "Longxuyen", "Mytho", "CaMau", "Rachgia", "Tuyhoa", "Phanthiet", "Haiduong", "Backan", "Bacgiang", "Baclieu", "Bacninh", "BenTre", "BinhDinh", "BinhDuong", "BinhPhuoc", "BinhThuan", "Camau", "Caobang", "DienBien", "DongNai", "DongThap", "GiaLai", "HaGiang", "HaNam", "HaTinh", "HoaBinh", "HungYen", "KhanhHoa", "KienGiang", "KonTum", "LaiChau", "LamDong", "LangSon", "LaoCai", "LongAn", "NamDinh", "NgheAn", "NinhBinh", "NinhThuan", "PhuTho", "PhuYen", "QuangBinh", "QuangNam", "QuangNgai", "QuangNinh", "SocTrang", "SonLa", "TayNinh", "ThaiBinh", "ThaiNguyen", "ThanhHoa", "ThuaThienHue", "TienGiang", "TraVinh", "TuyenQuang", "VinhLong", "VinhPhuc", "YenBai"};
                    for (string city : cities)
                    {
                        string cmd = "powershell -Command \"(Invoke-WebRequest 'https://wttr.in/" + city + "?format=3').Content\"";
                        system(cmd.c_str());
                    } system("pause");
                }break;
                case 2:{
                    string city; system("cls");
                    cout << "\n\n";
                    cout << "\t1.Hanoi\t2.Haiphong\t3.Danang\t4.Saigon\t5.Vinh-Nghean\t6.Hue\n";
                    cout << "\t--> ";cin >> tien_ich;
                    if (tien_ich==1){
                        city = "Hanoi";
                        string cmd = "powershell -Command \"(Invoke-WebRequest 'https://wttr.in/" + city + "?format=3').Content\"";
                        system(cmd.c_str()); system("pause");
                    }
                    if (tien_ich==    2){
                        city = "Haiphong";
                        string cmd = "powershell -Command \"(Invoke-WebRequest 'https://wttr.in/" + city + "?format=3').Content\"";
                        system(cmd.c_str());    system("pause");
                    }
                    if (tien_ich==    3){
                        city = "Danang";
                        string cmd = "powershell -Command \"(Invoke-WebRequest 'https://wttr.in/" + city + "?format=3').Content\"";
                        system(cmd.c_str());system("pause");
                    }
                    if (tien_ich==    4){
                        city = "Saigon";
                        string cmd = "powershell -Command \"(Invoke-WebRequest 'https://wttr.in/" + city + "?format=3').Content\"";
                        system(cmd.c_str());system("pause");
                    }
                    if (tien_ich==    5){
                        city = "Vinh";
                        string cmd = "powershell -Command \"(Invoke-WebRequest 'https://wttr.in/" + city + "?format=3').Content\"";
                        system(cmd.c_str());system("pause");
                    }
                    if (tien_ich==    6){
                        city = "Hue";
                        string cmd = "powershell -Command \"(Invoke-WebRequest 'https://wttr.in/" + city + "?format=3').Content\"";
                        system(cmd.c_str());system("pause");
                    }
                } break;
                }
            } while (tien_ich != 3);
}

void graphics_and_function(){int cmd; system("title ⚙️🛠️CMDBox BETA-3");

    do{ system("cls");cout << "\n\n";
        cout << "\t╭────────────────────────────────────────╮\n";
        cout << "\t│ 1. Software                            │\n";
        cout << "\t│ 2. Hardware                            │\n";
        cout << "\t│ 3. Networking                          │\n";
        cout << "\t│ 4. Fix error && system maintenance     │\n";
        cout << "\t│ 5. Administration and systems          │\n";
        cout << "\t│ 6. Setup CMD                           │\n";
        cout << "\t│ 7. tiện ích nhanh                      │\n";
        cout << "\t├────────────────────────────────────────┤\n";
        cout << "\t│ 8. đa luồng             0. Exit        │\n";
        cout << "\t╰────────────────────────────────────────╯\n";
        cout << "\t--> "; cin >> cmd;
        switch (cmd) {
        case 1: software(); break;
        case 2:hardware();break;
        case 3:networking();break;
        case 4: fix_error_and_system_maintenance();break;
        case 5:administrator_and_system(); break;
        case 6:setup();break;
        case 7: tien_ich(); break;
        case 8: { cout << "\n\n";cout << "\tCMD: "; cin >> cmd;
            if (cmd < 10 && cmd > 0){
                for (int i = 1; i <= cmd; i++){system("cmd/c start CMDBox");}
            }
            if (cmd < 1)cout << "\terror\n";
            if (cmd > 10){
                cout << "\tWARNING!  \n";Sleep(1000);
            }
        }break;
        }
    } while (cmd != 0);
}

int main(){
    graphics_and_function();
}