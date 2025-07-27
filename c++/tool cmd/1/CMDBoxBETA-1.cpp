#include<iostream>
#include<windows.h>
#include<string>
#include<math.h>
#include<fstream>
using namespace std;
void TextColor(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void graphics_and_function(){ system("title ⚙️🛠️CMDBox"); int cmd;  system("color 2");

    do{system("cls");cout<<"\n\n";
        cout<<"\t\tBETA-1\n\n";
        cout << "\t╭────────────────────────────────────────╮\n";
        cout << "\t│ 1. Software                         (4)│\n";
        cout << "\t│ 2. Hardware                         (7)│\n";
        cout << "\t│ 3. Networking                       (3)│\n";
        cout << "\t│ 4. Fix error && system maintenance  (2)│\n";
        cout << "\t│ 5. Administration and systems       (8)│\n";
        cout << "\t│ 6. Setup CMD                        (2)│\n";
        cout << "\t│ 7. tien ich nhanh                   (2)│(coming soon)\n";
        cout << "\t├────────────────────────────────────────┤\n";
        cout << "\t│ 8. DA LUONG             0. Exit        │\n";
        cout << "\t╰────────────────────────────────────────╯\n";
        cout << "\t--> "; cin >> cmd;
        switch(cmd){
            case 1:{
                do{system("cls");cout<<"\n\n";
                    cout << "\t╭─────────────────────────────╮\n";
                    cout << "\t│ 1. liet ke phan mem tai ve  │\n";
                    cout << "\t│ 2. quan ly tien trinh       │\n";
                    cout << "\t│ 3. control panel            │\n";
                    cout << "\t│ 4. go app tren control      │\n";
                    cout << "\t├─────────────────────────────┤\n";
                    cout << "\t│ 5. return       0.exit      │\n";
                    cout << "\t╰─────────────────────────────╯\n";
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
                    cout << "\t╭──────────────────────────────────╮\n";
                    cout << "\t│ 1. thong tin cpu                 │\n";
                    cout << "\t│ 2. thong tin ram                 │\n";
                    cout << "\t│ 3. o cung vat ly                 │\n";
                    cout << "\t│ 4. o dia logic                   │\n";
                    cout << "\t│ 5. danh sach driver              │\n";
                    cout << "\t│ 6. bao cao pin(laptop)           │\n";
                    cout << "\t│ 7. cong cu directx               │\n";
                    cout << "\t│ 8. do sang man hinh              │\n";
                    cout << "\t│ 9. thong tin card man hinh       │\n";
                    cout << "\t│ 10. tat man hinh                 │\n";
                    cout << "\t├──────────────────────────────────┤\n";
                    cout << "\t│ 11. return              0. Exit  │\n";
                    cout << "\t╰──────────────────────────────────╯\n";
                    cout<<"\t---> ";cin>>cmd;
                    switch(cmd){
                        case 1:{system("wmic cpu get name, maxclockspeed");system("pause");}break;
                        case 2:{system("wmic memorychip get capacity, speed");system("pause");}break;
                        case 3:{system("wmic diskdrive get model, size");system("pause");}break;
                        case 4:{system("wmic logicaldisk get name, size, freespace");system("pause");}break;
                        case 5:{system("driverquery");system("pause");}break;
                        case 6:{system("powercfg /batteryreport");system("start battery-report.html");}break;
                        case 7:{system("dxdiag");}break;
                        case 8:{cout<<"\n\n";int light;
                        cout<<"\tdo sang: ";cin>>light;

                        if(light<0|| light >100){
                            do{
                                cout<<"\tdo sang: ";cin>>light;
                                string cmd = "powershell -Command \"(Get-WmiObject -Namespace root/wmi -Class WmiMonitorBrightnessMethods).WmiSetBrightness(1," + to_string(light) + ")\"";
                                system(cmd.c_str());
                            }while(light<0 || light>100);
                        }
                        else{
                            string cmd = "powershell -Command \"(Get-WmiObject -Namespace root/wmi -Class WmiMonitorBrightnessMethods).WmiSetBrightness(1," + to_string(light) + ")\"";
                            system(cmd.c_str());
                        }
                        }break;
                        case 9:{system("wmic path win32_VideoController get name");system("pause");}break;
                        case 10:{system("powershell (Add-Type '[DllImport(\"user32.dll\")]^public static extern int SendMessage(int hWnd, int hMsg, int wParam, int lParam);' -name a -pas)::SendMessage(-1, 0x0112, 0xF170, 2)");}break;
                        case 0:{exit(0);}break;
                    }
                }while(cmd!=11);
            }break;
            case 3:{
                do{system("cls");cout<<"\n\n";
                    cout << "\t╭──────────────────────────────╮\n";
                    cout << "\t│ 1.xem ip va cau hinh mang    │\n";
                    cout << "\t│ 2. cap phat ip               │\n";
                    cout << "\t│ 3. danh sach wifi da luu     │\n";
                    cout << "\t├──────────────────────────────┤\n";
                    cout << "\t│ 4. return        0. Exit     │\n";
                    cout << "\t╰──────────────────────────────╯\n";
                    cout<<"\t--> ";cin>>cmd;
                    switch(cmd){
                        case 1:{system("cls");system("ipconfig/all");system("pause");}break;
                        case 2:{system("cls");system("ipconfig/renew");system("pause");}break;
                        case 3:{system("cls");system("netsh wlan show profiles");system("pause");}break;
                        case 0:{exit(0);}break;
                    }
                }while(cmd!=4);
            }break;
            case 4:{
                do{system("cls");cout<<"\n\n";
                    cout << "\t╭──────────────────────────────╮\n";
                    cout << "\t│ 1. xoa rac                   │\n";
                    cout << "\t│ 2. khoi dong may             │\n";
                    cout << "\t├──────────────────────────────┤\n";
                    cout << "\t│ 3. return         0. Exit    │\n";
                    cout << "\t╰──────────────────────────────╯\n";
                    cout<<"\t--> ";cin>>cmd;
                    switch(cmd){
                        case 1:{system("cleanmgr");}break;
                        case 2:{system("shutdown /r /t 0");}break;
                        case 0:{exit(0);}break;
                    }
                }while(cmd!=3);
            }break;
            case 5:{
                do{system("cls");cout<<"\n\n";
                    cout << "\t╭──────────────────────────────╮\n";
                    cout << "\t│ 1. task manager              |\n";
                    cout << "\t│ 2. registry                  │\n";
                    cout << "\t│ 3. quan ly dich vu           │\n";
                    cout << "\t│ 4. quan ly thiet bi          │\n";
                    cout << "\t│ 5. quan ly may tinh          │\n";
                    cout << "\t│ 6. khoa may tam thoi         │\n";
                    cout << "\t│ 7. tat windows update        │\n";
                    cout << "\t│ 8. bat windows update        │\n";
                    cout << "\t├──────────────────────────────┤\n";
                    cout << "\t│ 9. return          0. Exit   │\n";
                    cout << "\t╰──────────────────────────────╯\n";
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
                    cout<<"\t1. COLOR\n";
                    cout<<"\t3. return\n";
                    cout<<"\t--> ";cin>>cmd;
                    switch(cmd){
                     case 1:{int color;
                     do{ system("cls"); cout << "\n\n";
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
                        cout << "\t\tCHOOSE: "; cin >> color;
                        if (color == 1)TextColor(1);
                        if (color == 2) TextColor(2);
                        if (color == 3) TextColor(3);
                        if (color == 4) TextColor(4);
                        if (color == 5) TextColor(5);
                        if (color == 7) TextColor(7);
                        if (color == 30)TextColor(30);
                        if (color == 79) TextColor(79);
                        if (color == 87) TextColor(87);
                        if (color == 0) exit(0);
                    } while (color!=6);
                     }break;
                    }
                }while(cmd!=3);
            }break;
            case 8:{cout<<"\n\n";
            cout<<"\tCMD: ";cin>>cmd;
            if(cmd<10 && cmd>0){ for(int i=1;i<=cmd;i++){ system("cmd/c start CMDBox");}  }
            if(cmd<1) cout<<"\terror\n";
            if(cmd>10)   cout<<"\tWARNING!  \n";
            }break;
            case 7:{
                do{system("cls");cout<<"\n\n";
                    cout<<"\t1.thoi tiet\n";
                    cout<<"\t2.return\n";
                    cout<<"\t--> ";cin>>cmd;
                    switch(cmd){
                        case 1:{system("cls");cout<<"\n\n";
                        cout<<"\t1. list thoi tiet\t2.thoi tiet/tinh\n";
                        cout<<"\t--> ";cin>>cmd;
                        if (cmd == 1) {
                            string cities[] = {   "Hanoi", "Haiphong", "Danang", "Saigon", "Cantho", "Hue", "Nhatrang", "Vinh", "Thanhhoa",  "Quangngai", "Quinhon", "Pleiku", "Buonmathuot", "Dalat", "Longxuyen", "Mytho", "CaMau",  "Rachgia", "Tuyhoa", "Phanthiet", "Haiduong", "Backan", "Bacgiang", "Baclieu", "Bacninh",       "BenTre", "BinhDinh", "BinhDuong", "BinhPhuoc", "BinhThuan", "Camau", "Caobang", "DienBien", "DongNai", "DongThap", "GiaLai", "HaGiang", "HaNam", "HaTinh", "HoaBinh", "HungYen", "KhanhHoa",   "KienGiang", "KonTum", "LaiChau", "LamDong", "LangSon", "LaoCai", "LongAn", "NamDinh", "NgheAn",  "NinhBinh", "NinhThuan", "PhuTho", "PhuYen", "QuangBinh", "QuangNam", "QuangNgai", "QuangNinh", "SocTrang", "SonLa", "TayNinh", "ThaiBinh", "ThaiNguyen", "ThanhHoa", "ThuaThienHue", "TienGiang",  "TraVinh", "TuyenQuang", "VinhLong", "VinhPhuc", "YenBai"};

                            for (string city : cities) {
                                string cmd = "powershell -Command \"(Invoke-WebRequest 'https://wttr.in/" + city + "?format=3').Content\"";
                                system(cmd.c_str());
                            }  system("pause");
                        }
                        if(cmd==2){ string city;
                            system("cls");cout<<"\n\n";
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
                        }
                        }break;
                    }

                }while(cmd<2);
            }break;
            }
    }while(cmd!=0);
}

int main(){
    graphics_and_function();
}