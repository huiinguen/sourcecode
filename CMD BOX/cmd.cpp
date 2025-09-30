#include <iostream>
#include <windows.h>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
void TextColor(int color) {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);}

// hàm gọi api window lấy thông tin phần cứng
string getMainboardInfo() {
    HKEY hKey;
    const char* subKey = "HARDWARE\\DESCRIPTION\\System\\BIOS";
    if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, subKey, 0, KEY_READ, &hKey) != ERROR_SUCCESS)
        return "Unknown Mainboard";

    char buf[256];
    DWORD bufSize = sizeof(buf);
    DWORD type = 0;

    // Thử đọc Manufacturer
    if (RegQueryValueExA(hKey, "BaseBoardManufacturer", NULL, &type, (LPBYTE)buf, &bufSize) != ERROR_SUCCESS) {
        RegCloseKey(hKey);
        return "Unknown Mainboard";
    }
    string manufacturer(buf);

    bufSize = sizeof(buf);
    if (RegQueryValueExA(hKey, "BaseBoardProduct", NULL, &type, (LPBYTE)buf, &bufSize) != ERROR_SUCCESS) {
        RegCloseKey(hKey);
        return manufacturer;
    }
    string product(buf);

    RegCloseKey(hKey);
    return manufacturer + " " + product;
}

string getBIOSVersion() {
    HKEY hKey;
    const char* subKey = "HARDWARE\\DESCRIPTION\\System\\BIOS";
    if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, subKey, 0, KEY_READ, &hKey) != ERROR_SUCCESS)
        return "Unknown BIOS";

    char buf[256];
    DWORD bufSize = sizeof(buf);
    DWORD type = 0;

    if (RegQueryValueExA(hKey, "BIOSVersion", NULL, &type, (LPBYTE)buf, &bufSize) != ERROR_SUCCESS) {
        RegCloseKey(hKey);
        return "Unknown BIOS";
    }

    RegCloseKey(hKey);
    return string(buf);
}

string getDiskInfo(const string& driveLetter) {
    ULARGE_INTEGER freeBytesAvailable, totalBytes, freeBytes;
    if (GetDiskFreeSpaceExA(driveLetter.c_str(), &freeBytesAvailable, &totalBytes, &freeBytes)) {
        double totalGB = (double)totalBytes.QuadPart / (1024 * 1024 * 1024);
        double freeGB  = (double)freeBytes.QuadPart / (1024 * 1024 * 1024);

        ostringstream oss;
        oss << "Total: " << fixed << setprecision(2) << totalGB
            << " GB, Free: " << freeGB << " GB";
        return oss.str();
    }
    return "Disk info unavailable";
}

string getBatteryInfo() {
    SYSTEM_POWER_STATUS sps;
    if (GetSystemPowerStatus(&sps)) {
        string status;
        if (sps.ACLineStatus == 1) status = "⚡ Charging";
        else if (sps.ACLineStatus == 0) status = "🔋 On Battery";
        else status = "❓ Unknown";
        return to_string((int)sps.BatteryLifePercent) + "% " + status;
    }
    return "Unavailable";
}

string getCPUName() {
    HKEY hKey = NULL;
    const char* subKey = "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0";
    LONG res = RegOpenKeyExA(HKEY_LOCAL_MACHINE, subKey, 0, KEY_READ, &hKey);
    if (res != ERROR_SUCCESS || hKey == NULL) {
        if (hKey) RegCloseKey(hKey);
        return "Unknown CPU";
    }

    CHAR buffer[512];
    DWORD bufSize = sizeof(buffer);
    DWORD type = 0;
    res = RegQueryValueExA(hKey, "ProcessorNameString", NULL, &type, (LPBYTE)buffer, &bufSize);
    RegCloseKey(hKey);

    if (res != ERROR_SUCCESS) return "Unknown CPU";
    // ensure null-terminated
    buffer[(bufSize > 0 && bufSize < sizeof(buffer)) ? bufSize - 1 : sizeof(buffer) - 1] = '\0';
    return string(buffer);
}

string getTotalRAM() {
    MEMORYSTATUSEX ms;
    ms.dwLength = sizeof(ms);
    if (!GlobalMemoryStatusEx(&ms)) return "Unknown RAM";

    // total physical memory in bytes -> convert to GB
    double totalGB = (double)ms.ullTotalPhys / (1024.0 * 1024.0 * 1024.0);
    // format to 2 decimal places
    ostringstream oss;
    oss << fixed << setprecision(2) << totalGB << " GB";
    return oss.str();
}
//----------------------------------------------------------

void software(int choice){
    switch (choice){
    case 1:{  system("cls");  system("wmic product get name,version");  system("pause"); }break;
    case 2:{ system("cls");  system("tasklist");  system("pause"); }break;
    case 3:system("control");break;
    }
}

void hardware(int choice){ int number;
    switch (choice){
    case 4: {system("cls");
    cout << "\t========= THONG TIN HE THONG =======\n";
    TextColor(2);
    cout << "\n\t[CPU] " << getCPUName() << "\n";
    TextColor(3);
    cout << "\n\t[RAM] " << getTotalRAM() << "\n";
    TextColor(4);
    cout << "\n\t[PIN] " << getBatteryInfo() << "\n";
    TextColor(5);
    cout << "\n\t[MAINBOARD] " << getMainboardInfo() << "\n";
    TextColor(6);
    cout << "\n\t[BIOS] " << getBIOSVersion() << "\n";
    TextColor(7);
    cout << "\n\t[DISK C] " << getDiskInfo("C:\\") << "\n";
    system("pause");TextColor(7);
    }break;
    case 5:{system("driverquery");system("pause"); }break;
    case 6:{
        cout << "\n\t🔋 Đang tạo báo cáo pin laptop...\n";
        system("powercfg /batteryreport /output C:\\battery_report.html");
        cout << "\t📄 Báo cáo đã được lưu tại: C:\\battery_report.html\n";
        cout << "\t👉 Đang mở báo cáo...\n";
        system("start C:\\battery_report.html");
        break;
    }
    case 7:system("dxdiag");  break;
    case 8:{system("cls"); int number;
        do{system("cls");
            cout << "\n\tĐỘ SÁNG (1 --> 100) | Thoát = 0 : ";cin >> number;
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
    case 9: system("powershell (Add-Type '[DllImport(\"user32.dll\")]^public static extern int SendMessage(int hWnd, int hMsg, int wParam, int lParam);' -name a -pas)::SendMessage(-1, 0x0112, 0xF170, 2)");break;
    }
}

void networking(int choice){
    switch (choice){
    case 10:{system("cls"); system("ipconfig/all"); system("pause"); }break;
    case 11:{system("cls");system("ipconfig/renew"); system("pause");  }break;
    case 12:{system("cls");
        string wifi;
        cout << "\n\tNhập tên WiFi muốn xem mật khẩu: "; cin >> ws; getline(cin, wifi); // cho phép nhập có khoảng trắng
        string cmd = "netsh wlan show profiles name=\"" + wifi + "\" key=clear";
        system(cmd.c_str());  system("pause");
    }break;
    }
}

void fix_error_and_system_maintenance(int choice){
    switch (choice){
    case 13:{ system("cleanmgr"); }break;
    case 14:{system("rd /s /q \"%TEMP%\" && md \"%TEMP%\""); system("pause"); }break;
    case 15: system("shutdown /r /t 0"); break;
    case 16:{  cout << "\n\tĐang quét virus nhanh. Vui lòng chờ...\n";
        system("cmd /c \"\"%ProgramFiles%\\Windows Defender\\MpCmdRun.exe\" -Scan -ScanType 1\"");
        system("pause");
    }break;
    case 17:{ cout << "\n\tĐang thực hiện quét virus toàn bộ. Vui lòng chờ...\n";
        system("cmd /c \"\"%ProgramFiles%\\Windows Defender\\MpCmdRun.exe\" -Scan -ScanType 2\"");  
        system("pause");
    }break;
    case 18:{
        string command = "sfc/scannow";
        string powershell_cmd = "powershell -Command \"Start-Process cmd -Verb RunAs -ArgumentList '/k " + command + "'\"";
        system(powershell_cmd.c_str());
    }break;
    case 19:{
        string command = "chkdsk";
        string powershell_cmd = "powershell -Command \"Start-Process cmd -Verb RunAs -ArgumentList '/k " + command + "'\"";  
        system(powershell_cmd.c_str());
    }break;
    }
}

void administrator_and_system(int choice){
    switch (choice){
    case 20:system("taskmgr");break;
    case 21:system("regedit"); break;
    case 22:system("services.msc"); break;
    case 23:system("devmgmt.msc"); break;
    case 24: system("compmgmt.msc"); break;
    case 25: system("rundll32.exe user32.dll,LockWorkStation"); break;
    case 26:{cout<<"\n";
        cout<<"\t1.TURN ONL\t2.TURN OFF\n";
        cout<<"\t---> ";cin>>choice;
        switch(choice){
            case 1:{system("sc config wuauserv start= demand && net start wuauserv"); break;}
            case 2:{system("net stop wuauserv && sc config wuauserv start= disabled");break;}
        }
    }break;
    }
}

void intro() {system("cls");
    string cpu = getCPUName();
    string ram = getTotalRAM();
    string battery = getBatteryInfo();

    TextColor(2);
    cout << "\n\t═════════════════════════════════════════════════════════════════════════════════════\n";
    TextColor(3);
    cout << "\t🚀  Version: 1.0+            | ";
    TextColor(3);
    cout << "CPU: " << cpu << "\n";
    TextColor(4);
    cout << "\t👨‍💻  By: Huiinguyen 🛠️⚙️✅    | ";
    TextColor(4);
    cout << "RAM: " << ram << "\n";
    TextColor(5);
    cout << "\t🌐  Language: C++, Python 🐍 | ";
    TextColor(5);
    cout << "Battery: " << battery << "\n";
    TextColor(2);
    cout << "\t═════════════════════════════════════════════════════════════════════════════════════\n";
    TextColor(7);
}

/*
void SOS(int choice) {

}
*/

void function(int choice) {
    system("cls");
    TextColor(3); // Màu xanh lam/cyan cho tiêu đề nổi bật
    cout << "\t⚡️  SYSTEM UTILITY TOOLKIT ⚙️ | PHÂN TÍCH & LỘ TRÌNH\n";
    TextColor(7); // Trắng

    cout << "\t🟢  **HIỆN TRẠNG PHIÊN BẢN (Current Release):**\n";
    TextColor(11); // Vàng nhạt cho các đầu mục
    cout << "\t   • 💻 **Software Management:** Quản lý Phần mềm, Tiến trình, Control Panel.\n";
    cout << "\t   • 💾 **Hardware Diagnostics:** CPU, RAM, BIOS, Mainboard, Disk, Battery Information...\n";
    cout << "\t   • 🌐 **Network Interrogation:** IP Configuration, WiFi Status, IP Renewal Protocol.\n";
    cout << "\t   • 🛡️ **System Maintenance:** Antivirus Scan, SFC, CHKDSK, Deep Cleanup Utility.\n";
    cout << "\t   • 🔑 **Administrative Access:** Taskmgr, Registry Editor, Services Control, Lock Screen, Windows Update.\n\n";
    TextColor(7);

    cout << "\t🚀 **LỘ TRÌNH PHÁT TRIỂN (ROADMAP 🛣️):**\n";
    TextColor(10); // Xanh lá cây
    cout << "\t   [PHASE 1] - Tối ưu & Mở rộng\n";
    cout << "\t   1. **🚨 SOS Module:** Bổ sung CÔNG CỤ CỨU HỘ KHẨN CẤP hệ thống.\n";
    cout << "\t   2. **🎨 User Interface:** Tùy chỉnh Giao diện Động (Color Themes, Window Resize).\n";
    cout << "\t   3. **📄 Data Export:** Xuất Báo cáo Hiệu năng Hệ thống ra file (TXT, HTML - định dạng chuyên nghiệp).\n";
    cout << "\t   4. **📡 Advanced API:** Tích hợp sâu hơn vào Windows Core (WMI, COM Objects - Truy cập cấp độ Kernel).\n";
    cout << "\t   5. **⚙️ Multi-Threading:** Bổ sung Module Python/Async cho xử lý song song, tăng tốc độ phản hồi.\n\n";
    TextColor(7);

    cout << "\t🎯 **TẦM NHÌN (VISION):**\n";
    cout << "\t   => **KIẾN TẠO** một **ALL-IN-ONE UTILITY SUITE** mạnh mẽ cho Bảo trì & Kiểm soát Windows.\n";
    cout << "\t      **Ứng dụng:** Học thuật, Nghiên cứu Chuyên sâu và Hỗ trợ Kỹ thuật Thực tế.\n\n";

    TextColor(4); // Màu đỏ/hồng nổi bật cho phần kết
    cout << "\t==================================================================\n";
    TextColor(7);

    system("pause");
}
void maintain(){int cmd;
    do{ intro();
        cout << "\t╭────────────────────────────────────────────────────────────────────────────────────────╮\n";
        cout << "\t│          SOFTWARE                 │                    HARDWARE                        │\n";
        cout << "\t│ 1. LIỆT KÊ PHẦN MỀM TẢI VỀ        │ 4. THÔNG TIN PHẦN CỨNG    5.DANH SÁCH DRIVER       │\n";
        cout << "\t│ 2. QUẢN LÝ TIẾN TRÌNH             │ 6. BÁO CÁO PIN(laptop)    7. CÔNG CỤ DIRECTX       │\n";
        cout << "\t│ 3. CONTROL PANEL                  │ 8. ĐỘ SÁNG MÀN HÌNH       9. TẮT MÀN HÌNH          │\n";
        cout << "\t├────────────────────────────────────────────────────────────────────────────────────────┤\n";
        cout << "\t│          NETTWORKING              │         FIX ERROR && SYSTEM MAINTENANCE            │\n";
        cout << "\t│ 10. XEM IP VÀ CẤU HÌNH MẠNG       │ 13. XÓA RÁC Ổ CỨNG       14. XÓA RÁC THƯ MỤC 'TEMP │\n";
        cout << "\t│ 11. CẬP NHẬT IP                   │ 15. KHỞI ĐỘNG MÁY        16. QUÉT NHANH VIRUS      │\n";
        cout << "\t│ 12. MẬT KHẨU WIFI                 │ 17. QUÉT FULL VIRUS      18. QUÉT & SỬA FILE LỖI   │\n";
        cout << "\t│                                   │ 19. QUÉT Ổ CỨNG                                    │\n";
        cout << "\t├────────────────────────────────────────────────────────────────────────────────────────┤\n";
        cout << "\t│                           ADMINISTRATION AND SYSTEMS                                   │\n";
        cout << "\t│ 20. TASK MANAGER        21. REGISTRY      22. QUẢN LÝ DỊCH VỤ    23. QUẢN LÝ THIẾT BỊ  │\n";
        cout << "\t│ 24. QUẢN LÝ MÁY TÍNH    25. KHÓA MÁY TẠM THỜI    26. TẮT/BẬT(WINDOW UPDATE)            │\n";
        cout << "\t╰────────────────────────────────────────────────────────────────────────────────────────╯\n\n";
        cout << "\t╭────────────────────────────────────────────────────────────────────────────────────────╮\n";
        cout << "\t│  27. CHƯƠNG TRÌNH KHẨN CẤP(comming soon)      28.FUNCTION           0.EXIT             │\n";
        cout << "\t╰────────────────────────────────────────────────────────────────────────────────────────╯\n";
        cout << "\tNHAP SO--> ";cin >> cmd;
        if (cmd >= 1 && cmd <= 3)software(cmd);
        else if (cmd >= 4 && cmd <= 9)hardware(cmd);
        else if (cmd >= 10 && cmd <= 12)networking(cmd);
        else if (cmd >= 13 && cmd <= 19)fix_error_and_system_maintenance(cmd);
        else if (cmd >= 20 && cmd <= 26)administrator_and_system(cmd);
        //  if(cmd==27) SOS(cmd);
        if(cmd==28) function(cmd);
    } while (cmd != 0);
}

int main() {
    maintain(); 
    return 0;
}