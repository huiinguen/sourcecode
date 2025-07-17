#include <iostream>
#include <cmath>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <vector>
#include <unistd.h>
#include <cmath>
#include <math.h>
#include <graphics.h>
#include <iomanip>
using namespace std;

// khai báo định danh các hàm 
void work();
void case_chinh();
void math();
void digital();
void cmd();
void mathuniver();
void writePoints(int point_app);

// ---------------------------chương trình tính điểm----------------------------------
// Hàm để đọc điểm từ file
int readPoints() {
    ifstream infile("point_app.txt");
    int point_app;
    if (infile.is_open()) {
        infile >> point_app;
        infile.close();
    } else {
        // Nếu không tìm thấy file, trả về 15 điểm mặc định
        point_app = 15;
    }
    return point_app;
}
// Hàm để ghi điểm vào file
void writePoints(int point_app) {
    ofstream outfile("point_app.txt");
    if (outfile.is_open()) {
        outfile << point_app;
        outfile.close();
    }
}


// ---------------------------chức năng------------------------
// function time
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
         << " ]" << endl;
}
//function color
void TextColor(int color){
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
//phân biệt thiết bị
bool isLaptop(SYSTEM_POWER_STATUS& status) {
    if (GetSystemPowerStatus(&status)) {
        return (status.BatteryFlag != 128);
    }
    return false;
}
void digital() {
    SYSTEM_POWER_STATUS status;
    if (isLaptop(status)) {
        std::cout << "\t THIẾT BỊ: LAPTOP" << std::endl;
        std::cout << "\t TRẠNG THÁI PIN: " << static_cast<int>(status.BatteryLifePercent) << "%" << std::endl;
        if (status.ACLineStatus == 1) {
            std::cout << "\t PIN ĐANG SẠC."<<std::endl;
        } 
    } else {
        std::cout << "\t THIẾT BỊ: PC" << std::endl;
    }
}
// function cmd
void cmd(){int cmd;
    system("title CMD");
    do{ system("cls");cout<<"\n\n";
      cout<<"\t╭────────────────────────────────╮───────────────────────────────╮" << endl;
      cout<<"\t│          THÔNG TIN MÁY         │       MẠNG MÁY TÍNH           │" << endl;
      cout<<"\t├────────────────────────────────┤───────────────────────────────┤" << endl;
      cout<<"\t│1.CẤU HÌNH MÁY  2.ĐỊA CHỈ MÁY   │  15. XEM WIFI                 │" << endl;
      cout<<"\t│3.PHẦN CỨNG     4.TRẠNG THÁI RAM│  16.GIẢI PHÓNG/LÀM MỚI IP     │" << endl;
      cout<<"\t│5.TÊN MÁY       6.WINVER        │  17.KTRA ĐƯỜNG TRUYỀN MÁY ĐÍCH│" << endl;
      cout<<"\t│7.PIN LAPTOP    8.HISTORY CMD   │  18.XÓA BỘ NHỚ CACHE DNS      │" << endl;
      cout<<"\t╰────────────────────────────────╯" << endl;
      cout<<"\t╭─────────────────────────────────╮" << endl;
      cout<<"\t│         QUẢN LÝ,SỬA LỖI         │" << endl;
      cout<<"\t├─────────────────────────────────┤" << endl;
      cout<<"\t│9.QUẢN LÝ HD(1)  10.QUẢN LÝ HD(2)│" << endl;
      cout<<"\t│11.SỬA FILE LỖI   12.SỬA Ổ CỨNG  │" << endl;
      cout<<"\t│13.COMPUTER MANAGER              │" << endl;
      cout<<"\t│14.BẢNG ĐIỀU KHIỂN               │" << endl;
      cout<<"\t╰─────────────────────────────────╯" << endl;
      cout<<"\t╭─────────────────────────────────────────╮" << endl;
      cout<<"\t│ 0.QUAY LẠI   00.EXIT   21.ĐA LUỒNG      │" << endl;
      cout<<"\t╰─────────────────────────────────────────╯" << endl;
      cout<<"\tCHOOSE: ";cin>>cmd;
      switch(cmd){
        case 1:{ system("systeminfo"); system("pause"); } break;
        case 2:{ system("ipconfig");  system("pause"); } break;
        case 3:{ system("wmic cpu get name, maxclockspeed, status"); system("pause"); } break;
        case 4:{ system("wmic memorychip get capacity, speed"); system("pause"); } break;
        case 5:{ system("hostname"); system("pause"); } break;
        case 6:{system("winver"); } break;
        case 7:{ system("battery-report.html");  } break;
        case 8:{system("doskey /history"); system("pause"); } break;
        case 9:{ system("tasklist"); system("pause"); } break;
        case 10:{system("taskmgr");} break;
        case 11:{ /*
        string link= "C:\\Users\\hcao8\\source\\project\\life\\source code\\adminitrator.bat";
        system("adminitrator.bat");
        Sleep(300);system("sfc/scannow");
         system("pause");*/
        } break;
        case 12:{ system("chkdsk"); system("pause"); } break;
        case 13:{ system("compmgmt.msc"); } break;
        case 14:{
          do{system("cls");cout<<"\n\n\n";
            cout << "\t╭───────────────────────────╮" << endl;
            cout << "\t│  1.MOUSE       2.KEYBOARD │" << endl;
            cout << "\t│  3.TIME        4.NETWORK  │" << endl;
            cout << "\t├───────────────────────────┤" << endl;
            cout << "\t│  0.QUAY LẠI     5.EXIT    │" << endl;
            cout << "\t╰───────────────────────────╯" << endl;
            cout << "\t\tCHOOSE: "; cin >> cmd;
            switch (cmd){
            case 1:{
              system("control mouse");}break;
              case 2:{system("control keyboard");}break;
              case 3:{system("control timedate.cpl");}break;
              case 4:{system("control ncpa.cpl");}break;
              case 5:{exit(0);}break;
          }
          }while(cmd!=0);
        } break;
        case 15:{ } break;
        case 16:{ system("ipconfig /release && ipconfig /renew"); system("pause"); } break;
        case 17:{
          string ip; 
          cout<<"\n\n";
          cout<<"\tIP: "; cin>>ip;
          string cmd="ping "+ip;
          system(cmd.c_str());
          system("pause");
        } break;
        case 18:{ system("ipconfig /flushdns"); system("pause");} break;
        case 00:{ exit(0); } break;
        case 21:{int cmd_daluong;
        cout<<"\tCMD?: ";cin>>cmd_daluong;
        for(int loop=1;loop<=cmd_daluong;loop++){
          system("cmd/c start cmd1");
        }
        }break;
      } 
    } while(cmd != 0);
  }
//-------------------------------------------------------------------


//function math thpt
void math(){
    int choice,sl=1;
    double pi=3.14,a,b,c,d,m,n,p,q,a2,b2,c2,d2,r,l,h,k,x0=0,alpha;
system("title MATH");
  do{  system("cls");cout<<"\n\n";
cout << "\t\t╭─────────────────────────────────────╮" << endl;
cout << "\t\t│             ĐẠI SỐ                  │" << endl;
cout << "\t\t├─────────────────────────────────────┤" << endl;
cout << "\t\t│   1. CỰC TRỊ HÀM SỐ (BẬC 2)         │" << endl;
cout << "\t\t│   2. CỰC TRỊ HÀM SỐ (BẬC 3)         │" << endl;
cout << "\t\t│   3. CỰC TRỊ HÀM SỐ (BẬC 4)         │" << endl;
cout << "\t\t│   4. CĂN BẬC (2,3,4,5)              │" << endl;
cout << "\t\t│   5. LOGARIT                        │" << endl;
cout << "\t\t│   6. LŨY THỪA LOGARIT               │" << endl;
cout << "\t\t╰─────────────────────────────────────╯" << endl;
cout << "\t\t╭─────────────────────────────────────╮" << endl;
cout << "\t\t│             HÌNH HỌC                │" << endl;
cout << "\t\t├─────────────────────────────────────┤" << endl;
cout << "\t\t│   7. TÍCH VÔ HƯỚNG 2 VECTO          │" << endl;
cout << "\t\t│   8. HÌNH NÓN-TRỤ-CẦU               │" << endl;
cout << "\t\t│   9.TÍCH CÓ HƯỚNG                   │" << endl;
cout << "\t\t│   10.KHOẢNG CÁCH GIỮA 2 ĐIỂM        │" << endl;
cout << "\t\t├─────────────────────────────────────┤" << endl;
cout << "\t\t│   11.EXIT              12.MENU      │" << endl;
cout << "\t\t╰─────────────────────────────────────╯" << endl<<endl;
cout << "\t\tCHOOSE: ";cin >> choice;
switch(choice){
    case 2:{ system("cls");
        cout<<"\tf(x)= A.X^3 + B.X^2 + C.X^1 + D"<<endl;
        cout<<"\tA: ";cin>>a;  cout<<"\tB: ";cin>>b;   cout<<"\tC: ";cin>>c;  cout<<"\tD: ";cin>>d;
        system("cls"); cout<<"\n\n\n";

        cout<<"\tf(x)= "<<a<<"X^"<<3<<" + "<<b<<"X^"<<2<<" + "<<c<<"X^"<<1<<" + "<<d<<" = 0"<<endl<<endl;
        cout<<"\tF'(X)= 0 <=> F'(X)= "<<3*a<<"X^"<<3-1<<" + "<<b*2<<"Y^"<<2-1<<" + "<<c*1<<"Z^"<<1-1<<" = 0 \n\n\n";
        double x1=((-(b*2))+sqrt(pow(b*2,2)-4*(a*3)*(c*1))) /(2*a*3);
        double x2=((-(b*2))-sqrt(pow(b*2,2)-4*(a*3)*(c*1))) /(2*a*3);

        cout<<"\t\tX1: "<<x1<<" ==> Y: "<<(a*pow(x1,3))+(b*pow(x1,2))+(c*x1*1)+d<<" ==> ";
        if( (a*pow(x1,3))+(b*pow(x1,2))+(c*x1*1) >(a*pow(x2,3))+(b*pow(x2,2))+(c*x2*1)+d)
        cout<<"Ycd";
        else
        cout<<"Yct";
        cout<<endl<<endl;
        cout<<"\t\tX2: "<<x2<<" ==> Y: "<<(a*pow(x2,3))+(b*pow(x2,2))+(c*x2*1)+d<<" ==> ";
        if((a*pow(x2,3))+(b*pow(x2,2))+(c*x2*1)+d > (a*pow(x1,3))+(b*pow(x1,2))+(c*x1*1) )
        cout<<"Ycd";
        else
        cout<<"Yct";
        cout<<"\n\n";
        system("pause");
    }break;
    case 1:{
      system("cls");cout<<"\tAX^2 + BX + C (A KHÁC 0)"<<endl<<endl;
      cout<<"\tA: ";cin>>a; cout<<"\tB: ";cin>>b; cout<<"\tC: ";cin>>c;
       system("cls"); cout<<"\n\n\n";
       cout<<"\tF(X)= 0 <=> f(x)="<<a<<"X^"<<2<<" + "<<b<<"X + "<<c<<" = 0"<<endl<<endl;
       cout<<"\tF'(X)= 0 <=> F'(X)= "<<a*2<<"X^"<<2-1<<" + "<<b<<endl<<endl;
       cout<<"\tX= "<<-b/2*a<<" <=>  y= "<<((-b/2*a)*a*2)+((-b/2*a)*b)+c<<" <=> ";
       if(a>0) cout<<"CỰC TIỂU";
       else 
       cout<<"CỰC ĐẠI";system("pause");
    }break;
    case 3:{  system("cls");cout<<"\tA.X^4 + B.X^2 +  + C\n\n";
      cout<<"\tA: ";cin>>a; cout<<"\tB: ";cin>>b; cout<<"\tC: ";cin>>d2;
      cout<<"\n\n";
      cout<<"CHƯƠNG TRÌNH TRÊN THUỘC: ";

      if(a>0){
        cout<<"\tĐỒ THỊ HÌNH W"<<endl<<endl;
        if(a>0&&b<0){
          cout<<"+ĐỒ THỊ CÓ 2 TIỂU VÀ 1 ĐẠI"<<endl;}
        else{
          cout<<"ĐỒ THỊ CÓ 1 TIỂU VÀ 2 ĐẠI"<<endl; }
      }
      else{
        cout<<"ĐỒ THỊ HÌNH M"<<endl<<endl;
        if(a>0&&b>=0){
          cout<<"CÓ 1 TIỂU"<<endl; }
        else{
          cout<<"CÓ 1 ĐẠI"<<endl; }
      }

      cout<<"\n\n";
      cout<<"\tF(X)= 0 <=> F(X)= "<<a<<"X^"<<4<<" + "<<b<<"x^"<<2<<" + "<<d2<<endl<<endl;
      cout<<"\tF'(X)=0 <=> F'(X)= "<<a*4<<"x^"<<4-1<<" + "<<b*2<<"x^"<<2-1<<endl<<endl;
      cout<<"\tX0= 0 =>Y: "<<d2 <<" ";

      if(a>0)
      cout<<"\t CỰC TIỂU";
      else
      cout<<"\t CỰC ĐẠI";
      
      cout<<"\n";
      cout<<"\tX1= "<<-b/2.0*a<<" =>Y: "<<((-b/2.0*a)*a*pow(-b/2.0*a,4))+((-b/2.0*a)*b*pow(-b/2.0*a,2))+d2<<" ";
       
      if(-b/2.0*a>0)
      cout<<"\t CỰC ĐẠI";
      else
      cout<<"\t CỰC TIỂU";
       
       cout<<"\n";
      cout<<"\tX2= "<<b/2.0*a<<" =>Y: "<<((b/2.0*a)*a*pow(b/2.0*a,4))+((b/2.0*a)*b*pow(b/2.0*a,2))+d2<<" ";
      if(-b/2.0*a>0)
      cout<<"\t CỰC ĐẠI";
      else
      cout<<"\t CỰC TIỂU";

      cout<<"\n\n"; system("pause");
    }break;
    case 4:{ do{system("cls");cout<<"\n\n";cout<<"\t0.exit\n";cout<<"\n\n";
      cout<<"\t SỐ A: ";cin>>a;cout<<"\n\n";
      cout<<"\tCĂN BẬC 2 CỦA "<<a<<" = "<<sqrt(a)<<endl;
      cout<<"\t------- 3 CỦA "<<a<<" = "<<cbrt(a)<<endl;
      cout<<"\t------- 4 CỦA "<<a<<" = "<<pow(a,1.0/4.0)<<endl;
      cout<<"\t------- 5 CỦA "<<a<<" = "<<pow(a,1.0/5.0)<<endl;system("pause");}while(a!=0);
    }break;
    case 5:{system("C:\\Users\\hcao8\\source\\project\\life\\picture\\logarit.png");system("logarit.png");
        do{system("cls");cout<<"\n\n";
         cout<<"\t1\t2\t5\t6\t7\t8"<<endl<<endl;
         cout<<"\t11\t12\t13"<<endl<<endl;
         cout<<"\t0.EXIT"<<endl<<endl;
         cout<<"\tCHOOSE: ";cin>>choice;
         switch(choice){
            case 1:{   cout<<"\ta: ";cin>>a;  cout<<"\tKQ= "<< log(1) / log(a)<<endl;system("pause"); }break;
            case 2:{ cout<<"\ta: ";cin>>a;  cout<<"\tKQ= "<<log(a) / log(a)<<endl;  system("pause");   }break;
            case 5:{   cout<<"\ta: ";cin>>a;cout<<"\tn1: ";cin>>a2;cout<<"\tn2: ";cin>>b2;   cout<<"\tKQ= "<<(log(a2) / log(a)) + (log(b2) / log(a))<<endl; system("pause");  }break;
            case 6:{   cout<<"\ta: ";cin>>a;cout<<"\tn1: ";cin>>a2;cout<<"\tn2: ";cin>>b2;  cout<<"\tKQ= "<<(log(a2) / log(a)) - (log(b2) / log(a))<<endl; system("pause");  }break;
            case 7:{   cout<<"\talpha: ";cin>>alpha;cout<<"\ta: ";cin>>a;cout<<"\tn: ";cin>>n;  cout<<"\tKQ= "<<alpha * (log(n) / log(a))<<endl; system("pause"); }break;
            case 8:{   cout<<"\tn: ";cin>>n;cout<<"\ta: ";cin>>a;  cout<<"\tKQ= "<<2 * (log(fabs(n)) / log(a))<<endl; system("pause");  }break;
            case 11:{  cout<<"\ta: ";cin>>a;cout<<"\tb: ";cin>>b;   cout<<"\tKQ= "<<1 / (log(a) / log(b))<<endl; system("pause"); }break;
            case 12:{ cout<<"\talpha: ";cin>>alpha;cout<<"\ta: ";cin>>a;cout<<"\tn: ";cin>>n;    cout<<"\tKQ= "<< (1 / alpha) * (log(n) / log(a))<<endl; system("pause");  }break;
            case 13:{  cout<<"\tc: ";cin>>c;cout<<"\ta: ";cin>>a;cout<<"\tb: ";cin>>b; cout<<"\tKQ= "<<pow(c, log(a) / log(b))<<endl; system("pause"); }break;
         }
        }while(choice!=0);
    }break;
    case 6:{system("C:\\Users\\hcao8\\source\\project\\life\\picture\\luythualogarit.png");system("luythualogarit.png");
        do{system("cls");cout<<"\n\n";
        cout<<"\t1\t2\t3\t4\t5\n\n";
        cout<<"\t7\t8\t9\t10\n\n";
        cout<<"\t11\t13\t14\t15\n\n";
        cout<<"\tCHOOSE: ";cin>>choice;
        switch(choice){
            case 1:{cout<<"\ta: ";cin>>a;cout<<"\tm: ";cin>>m;cout<<"\tn: ";cin>>n;
            cout<<"\tKQ= "<<pow(a,m+n)<<endl; system("pause");}break;
            case 2:{cout<<"\ta: ";cin>>a;cout<<"\tb: ";cin>>b;cout<<"\tn: ";cin>>n;
            cout<<"\tKQ= "<<pow(a,n)*pow(b,n)<<endl; system("pause");}break;
            case 3:{cout<<"\ta: ";cin>>a;cout<<"\tm: ";cin>>m;cout<<"\tn: ";cin>>n;
            cout<<"\tKQ= "<<pow(a,m-n);cout<<"\n";system("pause");}break;
            case 4:{cout<<"\ta: ";cin>>a;cout<<"\tb: ";cin>>b;cout<<"\tn: ";cin>>n;
            cout<<"\tKQ= "<<pow(a,n)/pow(b,n);cout<<"\n";system("pause");}break;
            case 5:{cout<<"\ta: ";cin>>a;cout<<"\tm: ";cin>>m;cout<<"\tn: ";cin>>n;
            cout<<"\tKQ= "<<pow(a,m*n);cout<<"\n";system("pause");}break;
            case 6:{}break;
            case 7:{cout<<"\ta: ";cin>>a;cout<<"\tb: ";cin>>b;cout<<"\tn: ";cin>>n;
            cout<<"\tKQ= "<<pow(a,1.0/n)*pow(b,1.0/n);cout<<"\n";system("pause");}break;
            case 8:{cout<<"\tn: ";cin>>n;cout<<"\ta: ";cin>>a;cout<<"\tp: ";cin>>p;
            cout<<"\tKQ= "<<pow(pow(a,1.0/n),p);cout<<"\n";system("pause");}break;
            case 9:{cout<<"\ta: ";cin>>a;cout<<"\tm: ";cin>>m;cout<<"\tn: ";cin>>n;
            cout<<"\tKQ= "<<1/pow(pow(a,m),1.0/n);cout<<"\n";system("pause");}break;
            case 10:{cout<<"\n: ";cin>>n;cout<<"\tk: ";cin>>k;cout<<"\ta: ";cin>>a;
            cout<<"\tKQ= "<<pow(a,1.0/n*k);cout<<"\n";system("pause");}break;
            case 11:{cout<<"\tn: ";cin>>n;cout<<"\ta: ";cin>>a;cout<<"\tb: ";cin>>b;
            cout<<"\tKQ= "<<pow(a,1.0/n)/pow(b,1.0/n);cout<<"\n";system("pause");}break;
            case 13:{cout<<"\tĐk n>0\n\n";
            cout<<"\tn: ";cin>>n;
            if(n<0){
                do{
                    cout << "\tn: ";cin >> n;
                }while(n>0);
            }
            cout<<"\tm: ";cin>>m;cout<<"\ta: ";cin>>a;
            cout<<"\tKQ= "<<pow(a,m/n);cout<<"\n";system("pause");
            }break;
            case 14:{cout<<"\ta: ";cin>>a;cout<<"\tn: ";cin>>n;
            cout<<"\tKQ= "<<1.0/pow(a,n);cout<<"\n";system("pause");}break;
        }
        }while(choice!=0);
    }break;
    case 7:{
      do{ system("cls");cout<<"\n\n\n";
      cout<<"\t MÁY TÍNH KO VIẾT ĐƯỢC VECTO NÊN QUY ƯỚC '' LÀ VECTO :))\n\n";
      cout<<"\t1.AB\t2.COS('A','B')"<<endl;
      cout<<"\t3.|'A'|"<<endl;
      cout<<"\t0.EXIT"<<endl;
      cout<<"\tCHOOSE: ";cin>>choice;
      switch(choice){
        case 1:{  system("cls"); cout<<"\tA(X,Y)\tB(X2,Y2)\n\n";
          cout<<"\tX: ";cin>>a; cout<<"\tY: ";cin>>b; cout<<"\tX2: ";cin>>a2; cout<<"\tY2: ";cin>>b2;
          system("cls"); cout<<"\tAB= "<<sqrt(pow(a2-a,2)+pow(b2-b,2))<<endl;system("pause");
        }break;
        case 2:{   system("cls");cout<<"\tA(a1,a2)\tB(b1,b2)"<<endl<<endl;
          cout<<"\ta1: ";cin>>a; cout<<"\ta2 ";cin>>b; cout<<"\tb1: ";cin>>a2; cout<<"\tb2: ";cin>>b2;
          system("cls");cout<<"\tCOS('A','B')= "<<((a*b)+(b*b2))/sqrt(pow(a,2)+pow(a2,2))*sqrt(pow(b,2)+pow(b2,2))<<endl;system("pause");
        }break;
        case 3:{ system("cls");  cout<<"\t|'A'|= (a,a1)"<<endl<<endl;
          cout<<"\tA: ";cin>>a;cout<<"\tA2: ";cin>>a2;
          cout<<"\tKQ= "<<sqrt(pow(a,2)+pow(a2,2))<<endl;system("pause");
        }break;
      }
      }while(choice!=0);
    }break;
    case 8:{ system("cls");cout<<"\n\n";
      cout<<"\tH: ";cin>>h;cout<<"\tR: ";cin>>r;cout<<"\tL: ";cin>>l; system("cls");
      cout<<"\t DIỆN TÍCH XUNG QUANH: "<<pi*r*l<<endl;
      cout<<"\t DIỆN TÍCH ĐÁY: "<<pi*pow(r,2)<<endl;
      cout<<"\t DIỆN TÍCH TOÀN PHẦN: "<<(pi*r*l)+(pi*pow(r,2))<<endl;
      cout<<"\t THỂ TÍCH :"<<(1.0/3.0)*pi*pow(r,2)*h<<endl<<endl;

      cout<<"\t HÌNH TRỤ\n";
      cout<<"\t DIỆN TÍCH XUNG QUANH: "<<2*pi*r*h<<endl;
      cout<<"\t DIỆN TÍCH ĐÁY: "<<2*pi*pow(r,2)<<endl;
      cout<<"\t DIỆN TÍCH TOÀN PHẦN: "<<(2*pi*r*h)+(2*pi*pow(r,2))<<endl;
      cout<<"\t THỂ TÍCH: "<<pi*r*h<<endl<<endl;

      cout<<"\t HÌNH CẦU\n";
      cout<<"\t DIỆN TÍCH HÌNH CẦU: "<<4*pi*pow(r,2)<<endl;
      cout<<"\t THỂ TÍCH HÌNH CẦU: "<<double(4.0/3.0)*pi*pow(r,3)<<endl<<endl;system("pause");
    }break;
    case 9:{
      system("cls");cout<<"\n\n"; cout<<"\tX(A,B,C)\tB(A2,B2,C2)\n\n";
      cout<<"\tA: ";cin>>a; cout<<"\tB: ";cin>>b; cout<<"\tC: ";cin>>c; cout<<"\tA2: ";cin>>a2; cout<<"\tB2: ";cin>>b2; cout<<"\tC2: ";cin>>c2;
      system("cls");
      cout<<"\tKQ= ["<<(b*c2)-(b2*c)<<","<<(c*a2)-(c2*a)<<","<<(a*b2)-(a2*b)<<"]"<<endl;system("pause");
    }break;
    case 10:{
      system("cls");cout<<"\tA(a,b,c)\tB(a2,b2,c2)"<<endl;
      cout<<"\tA: ";cin>>a;cout<<"\tB: ";cin>>b;cout<<"\tC: ";cin>>c;cout<<"\tA2: ";cin>>a2;cout<<"\tB2: ";cin>>b2;cout<<"\tC2: ";cin>>c2;
      cout<<"\tKQ= "<<sqrt(pow(a2-a,2)+pow(b2-b,2)+pow(c2-c,2))<<endl;system("pause");
    }break;
    case 11:{exit(0);}break;
  }
  }while(choice!=12);
}
// function math university
void mathuniver(){int mathuniver;
    do{system("cls");cout<<"\n\n";
       cout << "\t╭────────────────────────────╮\n";
       cout << "\t│       MENU CHÍNH           │\n";
       cout << "\t├────────────────────────────┤\n";
       cout << "\t│ 1. XÁC SUẤT THỐNG KÊ       │\n";
       cout << "\t│ 2. TOÁN CAO CẤP C2         │\n";
       cout << "\t├────────────────────────────┤\n";
       cout << "\t│        0.EXIT              │\n";
       cout << "\t╰────────────────────────────╯\n";
       cout<<"\tCHOOSE: ";cin>>mathuniver;
       switch(mathuniver){
       case 1:{
       do{system("cls");cout<<"\n\n";
           cout << "\t╭─────────────────────────────────╮\n";
           cout << "\t│             MENU CHÍNH          │\n";
           cout << "\t├─────────────────────────────────┤\n";
           cout << "\t│ 1.MÔ TẢ DỮ LIỆU(LỚP ĐƠN)        │\n";
           cout << "\t│ 2.MÔ TẢ DỮ LIỆU(LỚP KÉP)        │\n";
           cout << "\t│ 3.BẢNG PHÂN BỐ TẦN SỐ VÀ ĐỒ THỊ │\n";
           cout << "\t├─────────────────────────────────┤\n";
           cout << "\t│    0.MENU      00.EXIT          │\n";
           cout << "\t╰─────────────────────────────────╯\n";
           cout << "\tCHOOSE: "; cin >> mathuniver;
           switch (mathuniver) {
           case 1:{
               system("cls"); cout << "\n\n";
               int n; // số lượng lớp
               cout << "\tSỐ LƯỢNG LỚP: "; cin >> n;

               string phamVi[n];
               int tanSuat[n], tongTanSuat = 0;
               double trungBinh = 0, phuongSai = 0, doLechChuan = 0;

               // Nhập dữ liệu
               for (int i = 0; i < n; ++i) {
                   cout << "\tLỚP " << i + 1 << ": ";  cin >> phamVi[i];
                   cout << "\tTẦN SỐ " << i + 1 << ": ";  cin >> tanSuat[i];
                   tongTanSuat += tanSuat[i];
               }

               // Tính trung bình
               for (int i = 0; i < n; ++i) {
                   trungBinh += (tanSuat[i] * (i + 1));
               }
               trungBinh /= tongTanSuat;

               // Tính phương sai
               for (int i = 0; i < n; ++i) {
                   phuongSai += tanSuat[i] * pow((i + 1) - trungBinh, 2);
               }
               phuongSai /= tongTanSuat;

               // Tính độ lệch chuẩn
               doLechChuan = sqrt(phuongSai);

               system("cls"); cout << "\n\n\n";
               // In dữ liệu
               cout << "\tLỚP\tTẦN SỐ" << endl;
               for (int i = 0; i < n; ++i) {
                   cout << "\t| " << phamVi[i] << "\t" << tanSuat[i] << " |" << endl;
               }
               cout << "\n\n";
               // In kết quả
               cout << "\tTrung bình: " << trungBinh << endl;
               cout << "\tPhương sai: " << phuongSai << endl;
               cout << "\tĐộ lệch chuẩn: " << doLechChuan << endl << endl;
               system("pause");
           }break;

           case 2:{system("cls");cout<<"\n\n";
           
           }break;

           case 3: { system("cls"); cout << "\n\n";
               int n;
               cout << "\tSỐ LỚP: ";cin >> n;

               vector<int> lop(n);         // Vector quản lý lớp
               vector<int> tan_so(n);      // Vector quản lý tần số
               vector<float> phan_tram(n); // Vector quản lý phần trăm
               
               int tong_tan_so = 0; // Biến để lưu tổng tần số
               double tong_phantram=0;
               // Nhập dữ liệu và tính tổng tần số
               for (int i = 0; i < n; i++) {
                   cout << "\tLỚP " << i + 1 << ": "; cin >> lop[i];
                   cout << "\tTẦN SỐ " << i + 1 << ": ";cin >> tan_so[i];
                   tong_tan_so += tan_so[i];
               }

               // Tính phần trăm
               for (int i = 0; i < n; i++) {
                   phan_tram[i] = (tan_so[i] / (float)tong_tan_so) * 100;
                   tong_phantram+=phan_tram[i];
               }

               system("cls"); cout << "\n\n\n";
               // In ra màn hình
               cout << "\tLỚP\tTẦN SỐ\tPHẦN TRĂM\n";
               for (int i = 0; i < n; i++){
                   cout << "\t| " << lop[i] << "\t" << tan_so[i] << "\t" << phan_tram[i] << " |" << "\n";
               }
               cout<<"\n";
               cout<<"\tTỔNG TẦN SỐ: "<<tong_tan_so<<endl;
               cout<<"\tTỔNG PHẦN TRĂM: "<<tong_phantram<<endl<<endl;
               cout<<"\tCÁCH LÀM BÀI\n\n";
               cout<<"\t(TẦN SỐ / TỔNG TẦN SỐ)* 100\n\n";
               system("pause");
           } break;

           case 00: {exit(0);}break;

       }
       }while (mathuniver != 0);    
       }break;

       case 2:{}break;
       }
       }while (mathuniver != 0);
}


//function case_chinh
void case_chinh(){int choice;
system("title TOOL CƠ BẢN");
    do{ system("cls");cout<<"\n";
        cout << "\t╭────────────────────────╮" << endl;
        times(); 
        digital();
        cout << "\t╰────────────────────────╯" << endl<<endl;
        cout << "\t╭──────────────────────────────────────────╮" << endl;
        cout << "\t│             HỖ TRỢ CƠ BẢN                │" << endl;
        cout << "\t├──────────────────────────────────────────┤" << endl;
        cout << "\t│   1.ĐỔI DỮ LIỆU        2.SPAM TIN NHẮN   │" << endl;
        cout << "\t│   3.HỌC TẬP            4.CMD             │" << endl;
        cout << "\t│   5.APPLICATION        6.SETTING         │" << endl;
        cout << "\t│   7.HD SỬ DỤNG         8.CÁCH HOẠT ĐỘNG  │" << endl;
        cout << "\t╰──────────────────────────────────────────╯" << endl;
        cout << "\t╭──────────────────────────────────────────╮" << endl;
        cout << "\t│  9.WORK                     0.EXIT       │" << endl;
        cout << "\t╰──────────────────────────────────────────╯" << endl;
        cout << "\tCHOOSE: "; cin >> choice;
        switch (choice){
        case 1:{ system("title ĐỔI DỮ LIỆU");
            do{ system("cls"); cout << "\n\n\n\n";
                cout << "\t\t╭─────────────────────────────╮" << endl;
                cout << "\t\t│   1. QUY ĐỔI DUNG LƯỢNG     │" << endl;
                cout << "\t\t│   2. QUY ĐỔI TIỀN           │" << endl;
                cout << "\t\t│   3. QUY ĐỔI THỜI GIAN      │" << endl;
                cout << "\t\t│   4. CÁC HỆ ĐẾM MÁY TÍNH    │" << endl;
                cout << "\t\t├─────────────────────────────┤" << endl;
                cout << "\t\t│   5.QUAY LẠI      6.EXIT    │" << endl;
                cout << "\t\t╰─────────────────────────────╯" << endl;
                cout << "\tCHOOSE:  "; cin >> choice;
                switch (choice){
                case 1:{
                   long double bit, byte, kilobyte, megabyte, gigabyte;
                    do{ system("cls"); cout << "\n\n";
                        cout << "\t\t╭──────────────────────────────────╮" << endl;
                        cout << "\t\t│       QUY ĐỔI DUNG LƯỢNG         │" << endl;
                        cout << "\t\t├──────────────────────────────────┤" << endl;
                        cout << "\t\t│      1. GB = MB                  │" << endl;
                        cout << "\t\t│      2. MB = KB, GB              │" << endl;
                        cout << "\t\t│      3. KB = BYTE, MB            │" << endl;
                        cout << "\t\t│      4. BYTE = BIT, KB           │" << endl;
                        cout << "\t\t│      5. BIT = BYTE, KB           │" << endl;
                        cout << "\t\t│      6. BIT+BYTE+KB+MB = GB      │" << endl;
                        cout << "\t\t│      7. BIT+BYTE+KB+GB = MB      │" << endl;
                        cout << "\t\t├──────────────────────────────────┤" << endl;
                        cout << "\t\t│      8.QUAY LẠI       0.EXIT     │" << endl;
                        cout << "\t\t╰──────────────────────────────────╯" << endl << endl;
                        cout << "\tCHOOSE: ";cin >> choice;
                        switch (choice) {
                        case 1: { system("cls"); cout << "\tGB: "; cin >> gigabyte; cout << gigabyte << " GB= " << gigabyte * 1024 << " MB" << endl;system("pause"); }break;
                        case 2: { system("cls"); cout << "\tMB: "; cin >> megabyte; cout << megabyte << " MB= " << megabyte * 1024 << " KB" << endl; cout << megabyte << " MB= " << megabyte * 0.0009765625 << " GB" << endl; system("pause"); }  break;
                        case 3:{ system("cls"); cout << "\tKB: ";  cin >> kilobyte;cout << kilobyte << " KB= " << kilobyte * 1024 << " BYTE" << endl;cout << kilobyte << " KB= " << kilobyte * 0.0009765625 << " MB" << endl;system("pause"); } break;
                        case 4: { system("cls");cout << "\tBYTE: "; cin >> byte; cout << byte << " BYTE= " << byte * 8 << " BIT" << endl; cout << byte << " BYTE= " << byte * 0.0009765625 << " KB" << endl;system("pause"); } break;
                        case 5: { system("cls");cout << "\tBIT: ";cin >> bit;cout << bit << " BIT= " << bit * 0.125 << " BYTE" << endl;cout << bit << " BIT= " << bit * 0.0001220703125 << " KB" << endl; system("pause"); } break;
                        case 6: { system("cls"); cout << "\tBIT: "; cin >> bit; cout << "\tBYTE: "; cin >> byte; cout << "\tKB: "; cin >> kilobyte; cout << "\tMB: "; cin >> megabyte; cout << "\tKQ = " << (bit * 1.1641532182693 * pow(10, -10)) + (byte * 9.3132257461548 * pow(10, -10)) + (kilobyte * 9.5367431640625 * pow(10, -7)) + (megabyte * 0.0009765625) << " GB" << endl; system("pause"); }break;
                        case 7: { system("cls");cout << "\tBIT: "; cin >> bit; cout << "\tBYTE: "; cin >> byte;cout << "\tKB: "; cin >> kilobyte; cout << "\tGB: "; cin >> gigabyte; cout << "\tKQ = " << (bit * 1.1920928955078 * pow(10, -7)) + (byte * 9.5367431640625 * pow(10, -7)) + (kilobyte * 0.0009765625) + (gigabyte * 1024) << " MB" << endl; system("pause"); } break;
                        case 0:{exit(0);}break;
                        }
                    } while (choice!=8);
                } break;
                case 2:{ double usd, euro, yen, won, vnd, kip;
                    do{ system("cls");cout<<"\n\n";
                        cout << "\t╭─────────────────────────────────────╮" << endl;
                        cout << "\t│            QUY ĐỔI TIỀN             │" << endl;
                        cout << "\t├─────────────────────────────────────┤" << endl;
                        cout << "\t│  1.VND ⇔ (USD, EUR, YEN, WON, KIP) │" << endl;
                        cout << "\t│  2.USD ⇔ (VND, EUR, YEN, WON, KIP) │" << endl;
                        cout << "\t│  3.EUR ⇔ (VND, USD, YEN, WON)      │" << endl;
                        cout << "\t│  4.WON ⇔ (USD, YEN, VND, EUR)      │" << endl;
                        cout << "\t│  5.YEN ⇔ (USD, VND, WON, EUR)      │" << endl;
                        cout << "\t├─────────────────────────────────────┤" << endl;
                        cout << "\t│    6.QUAY LẠI            7.EXIT     │" << endl;
                        cout << "\t╰─────────────────────────────────────╯" << endl;
                        cout << "\t\tCHOOSE: "; cin >> choice;
                        switch (choice) {
                        case 1:{ system("cls");cout<<"\n\n"; cout << "\tVND: "; cin >> vnd;
                         cout << fixed << setprecision(0);
                            cout << vnd << " VND = " << vnd * (0.00004) << "  USD" << endl;
                            cout << vnd << " VND = " << vnd * (0.000037) << " EURO" << endl;
                            cout << vnd << " VND = " << vnd * (0.0061) << " YEN" << endl;
                            cout << vnd << " VND = " << vnd * (0.055) << " WON" << endl;
                            cout << vnd << " vnd = " << vnd * 0.86 << " KIP" << endl; system("pause"); } break;
                        case 2:{ system("cls");cout << "\n\n"; cout << "\tUSD: "; cin >> usd;
                         cout << fixed << setprecision(0);
                            cout << usd << " USD = " << usd * 25.265 << " VND" << endl;
                            cout << usd << " USD = " << usd * 0.93 << " EURO" << endl;
                            cout << usd << " USD = " << usd * 1.395 << " WON" << endl;
                            cout << usd << " USD = " << usd * 153.4 << " YEN" << endl;
                            cout << usd << " USD = " << usd * (21.844) << " KIP" << endl; system("pause"); } break;
                        case 3:{system("cls");cout << "\n\n"; cout << "\tEURO: ";cin >> euro;
                         cout << fixed << setprecision(0);
                            cout << euro << " EURO = " << euro * 27.090 << " VND" << endl;
                            cout << euro << " EURO = " << euro * 1.07 << " USD" << endl;
                            cout << euro << " EURO = " << euro * 1.496 << " WON" << endl;
                            cout << euro << " EURO = " << euro * 164.26 << " YEN" << endl; system("pause"); } break;
                        case 4:{ system("cls");cout << "\n\n"; cout << "\tWON: "; cin >> won;
                         cout << fixed << setprecision(0);
                            cout << won << " WON = " << won * 0.00072 << " USD" << endl;
                            cout << won << " WON = " << won * 18.1 << " VND" << endl;
                            cout << won << " WON = " << won * 0.00067 << " EURO" << endl;
                            cout << won << " WON = " << won * 0.11 << " YEN" << endl; system("pause"); } break;
                        case 5: { system("cls");cout << "\n\n"; cout << "\tYEN: ";cin >> yen;
                         cout << fixed << setprecision(0);
                            cout << yen << " YEN = " << yen * 0.0065 << " USD" << endl;
                            cout << yen << " YEN = " << yen * 164.7 << " VND" << endl;
                            cout << yen << " YEN = " << yen * 0.0061 << " EURO" << endl;
                            cout << yen << " YEN = " << yen * 9.11 << " WON" << endl;system("pause"); }break;
                        case 7:{exit(0);}break;
                        } 
                    } while (choice!=6);
                }break;
                case 3:{ double  day, hour, minute, ms, second, thapky, theky, thiennienky;int datetime;
                    do{ cout << "\n\n";system("cls");
                        cout << "\t╭─────────────────────────────────╮" << endl;
                        cout << "\t│            MỐC THẾ KỶ           │" << endl;
                        cout << "\t├─────────────────────────────────┤" << endl;
                        cout << "\t│      1. THẬP KỶ = NĂM           │" << endl;
                        cout << "\t│      2. THIÊN NIÊN KỶ = NĂM     │" << endl;
                        cout << "\t│      3. THẾ KỶ = NĂM            │" << endl;
                        cout << "\t│      4.(1,2,3)= GIỜ,PHÚT,GIÂY   │" << endl;
                        cout << "\t╰─────────────────────────────────╯" << endl;
                        cout << "\t╭─────────────────────────────────╮" << endl;
                        cout << "\t│        NGÀY/GIỜ/PHÚT/GIÂY       │" << endl;
                        cout << "\t├─────────────────────────────────┤" << endl;
                        cout << "\t│      5. NGÀY = (GIỜ,PHÚT,GIÂY)  │" << endl;
                        cout << "\t│      6. GIỜ = (NGÀY,PHÚT,GIÂY)  │" << endl;
                        cout << "\t│      7. PHÚT = (NGÀY,GIỜ,GIÂY)  │" << endl;
                        cout << "\t│      8. MILI GIÂY = (GIÂY,PHÚT) │" << endl;
                        cout << "\t│      9. GIỜ+PHÚT+GIÂY = GIỜ     │" << endl;
                        cout << "\t│      10.GIỜ+PHÚT+GIÂY = PHÚT    │" << endl;
                        cout << "\t│      11.GIỜ+PHÚT+GIÂY = GIÂY    │" << endl;   
                        cout << "\t├─────────────────────────────────┤" << endl;
                        cout << "\t│      0.QUAY LẠI     12.EXIT     │" << endl;
                        cout << "\t╰─────────────────────────────────╯" << endl;
                        cout << "\tCHOOSE: ";cin >> datetime;
                        switch (datetime){
                        case 1: {system("cls");cout << "\t THẬP KỶ: "; cin >> thapky;
                            cout << thapky << " THẬP KỶ = " << thapky * 10 << " NĂM" << endl; system("pause"); }break;
                        case 2: {system("cls");
                            cout << "\t THIÊN NHIÊN KỶ: ";cin >> thiennienky;
                            cout << thiennienky << " THIÊN NIÊN KỶ = " << thiennienky * 1000 << " NĂM" << endl; system("pause"); } break;
                        case 3: {   system("cls"); cout << "\t THẾ KỶ: ";cin >> theky;
                            cout << theky << " THẾ KỶ = " << theky * 100 << " NĂM" << endl; system("pause"); } break;
                        case 4:{system("cls");cout << "\t THẬP KỶ: "; cin >> thapky;cout << "\t THIÊN NHIÊN KỶ: ";cin >> thiennienky; cout << "\t THẾ KỶ: ";cin >> theky;
                        cout <<"\t_____________________HOUR__________________\n\n";
                        cout <<"\t│"<< fixed << setprecision(0);
                        cout <<"\t│"<< theky << " THẾ KỶ = " <<(theky*100)*8760<<"\n";
                        cout <<"\t│"<< thiennienky << " THIÊN NIÊN KỶ = " <<(thiennienky*1000)*8760<<"\n";
                        cout <<"\t│"<< thapky << " THẬP KỶ = " << (thapky*10)*8760<<"\n\n";
                        cout <<"\t│_____________________MINUTE__________________\n\n";
                        cout <<"\t│"<< theky << " THẾ KỶ = " <<((theky*100)*8760)*525600<<"\n";
                        cout <<"\t│"<< thiennienky << " THIÊN NIÊN KỶ = " <<(thiennienky*1000)*8760<<"\n";
                        cout <<"\t│"<< thapky << " THẬP KỶ = " << (thapky*10)*8760<<"\n";
                        cout <<"\t│_____________________________________________\n";
                        system("pause");
                        }break;
                        case 5:{ system("cls");
                            cout << "\tBAO NHIÊU NGÀY: "; cin >> day;
                            cout << day << " NGÀY = " << day * 24 << " GIỜ" << endl;
                            cout << day << " NGÀY = " << day * 1440 << " PHÚT " << endl;
                            cout << day << " NGÀY = " << day * 86400 << " GIÂY " << endl;  system("pause"); } break;
                        case 6: {
                            system("cls"); cout << "\t GIỜ: "; cin >> hour;
                            cout << hour << " GIỜ = " << hour * (0.04167) << " NGÀY" << endl;
                            cout << hour << " GIỜ = " << hour * 60 << " PHÚT" << endl;
                            cout << hour << " GIỜ = " << hour * 3600 << " GIÂY" << endl; system("pause"); } break;
                        case 7: { system("cls"); cout << "\t PHÚT: "; cin >> minute;
                            cout << minute << " PHÚT = " << minute * 0.000694444444 << " NGÀY" << endl;
                            cout << minute << " PHÚT = " << hour * (0.01667) << " GIỜ" << endl;
                            cout << minute << " PHÚT = " << minute * 60 << " GIÂY" << endl; system("pause"); } break;
                        case 8:  { system("cls");
                            cout << "\tMILI GIÂY: "; cin >> ms;
                            cout << ms << " MILI GIÂY = " << ms * 0.0000166667 << " PHÚT" << endl;
                            cout << ms << " MILI GIÂY = " << ms * 0.001 << " PHÚT" << endl; system("pause"); } break;
                        case 9: {
                            system("cls"); cout << "\tGIỜ: "; cin >> hour;
                            cout << "\tPHÚT: ";cin >> minute; cout << "\tGIÂY: ";cin >> second;
                            cout << hour << "GIỜ+" << minute << "PHÚT+" << second << "GIÂY= " << hour + (0.01667) + (0.00027778) << " GIỜ" << endl; system("pause"); }  break;
                        case 10:{
                            system("cls");cout << "\tGIỜ: "; cin >> hour;
                            cout << "\tPHÚT: ";cin >> minute;
                            cout << "\tGIÂY: ";cin >> second;
                            cout << hour << "GIỜ+" << minute << "PHÚT+" << second << "GIÂY= " << (hour * 60) + minute + (0.01667) << " PHÚT" << endl; system("pause"); }break;
                        case 11:{
                             system("cls");cout<<"\tGIỜ: ";cin>>hour;cout<<"\tPHÚT: ";cin>>minute;cout<<"\tGIÂY: ";cin>>second;
                             cout<<hour<<"GIỜ+"<<minute<<"PHÚT+"<<second<<"GIÂY= "<<(hour*3600)+(minute*60)+second<<" GIÂY"<<endl;system("pause"); }break;
                        case 12:{exit(0);}break;
                           }
                    } while (datetime!=0);
                 }break;
                case 4:{
                    do{system("cls");cout<<"\n\n";
                    cout<<"1.THẬP PHÂN --> NHỊ PHÂN\n";
                    cout<<"2.THẬP PHÂN -->HEXA\n";
                    cout<<"3.HEXA,NHỊ PHÂN -->THẬP PHÂN\n";
                    cout<<"0.exit\n";
                    cout<<"CHOOSE: ";cin>>choice;
                    switch(choice){
                    }
                    }while(choice!=0);
                }break;
                case 6:{exit(0);}break;
                }
            }while(choice!=5);
        }break; 
        case 2:{ system("cls"); system("python mess.py"); }break;
        case 3:{system("title HỌC TẬP"); system("cls"); cout<<"\n\n";
            do{system("cls");cout<<"\n\n\n";
                cout << "\t╭───────────────────────╮" << endl;
                cout << "\t│ 1. TOÁN CẤP 3         │" << endl;
                cout << "\t│ 2. TOÁN ĐẠI HỌC       │" << endl;
                cout << "\t╰───────────────────────╯" << endl;
                cout << "\t╭───────────────────────╮" << endl;
                cout << "\t│  0.EXIT   00.QUAY LẠI │" << endl;
                cout << "\t╰───────────────────────╯" << endl;
                cout << "\tCHOOSE: ";
                cin >> choice;
                switch (choice){
                case 1:{  math();}break;
                case 2:{  mathuniver();}break;
                case 0:{exit(0);}break;
            }
            }while(choice!=00);
        }break;
        case 4:{ cmd();}break;
        case 5:{ system("title APPICATION");
            do{system("cls");cout<<"\n\n";
                cout << "\t╭────────────────────────────────────╮\n";
                cout << "\t│1.QUAY MÀN HÌNH     2. NOTE         │\n";
                cout << "\t│3. PAINT            4.File Explorer │\n";
                cout << "\t│5. ĐỒNG HỒ          6.SETTING       │\n";
                cout << "\t├────────────────────────────────────┤\n";
                cout << "\t│        0. MENU      00. EXIT       │\n";
                cout << "\t╰────────────────────────────────────╯\n";
                cout << "\tCHOOSE: "; cin >> choice;
                switch (choice) {
                case 1: { system("python record.py"); } break;
                case 2:{ system("C:\\Users\\hcao8\\source\\project\\life\\file\\note.txt"); system("note.txt"); } break;
                case 3: { system("start mspaint"); } break;
                case 4: { system("explorer");} break;
                case 5: {   system("start ms-clock:");  } break;
                case 6:{system("start ms-settings:");}break;
                case 00:{  exit(0);} break;
                }
            } while (cmd != 0);
        }break;
        case 6:{ system("title SETTING");
            do{ system("cls");cout<<"\n\n\n";
                cout << "╭──────────────────────────────────╮" << endl;
                cout << "│1.COLOR       2.ĐỘ SÁNG MÀN HÌNH  │" << endl;
                cout << "│3.ÂM LƯỢNG    4.CHẾ ĐỘ MÁY BAY    │" << endl;
                cout << "│5.SETUP FULL PYTHON               │" << endl;
                cout << "├──────────────────────────────────┤" << endl;
                cout << "│       0.EXIT      00.MENU        │" << endl;
                cout << "╰──────────────────────────────────╯" << endl;
                cout << "\tCHOOSE: "; cin >> choice;
                switch (choice){
                case 1:{int color;
                    do{ system("cls"); cout << "\n\n\n";
                        cout << "\t\t╭───────────────────────────────────────────────╮" << endl;
                        cout << "\t\t│                    BẢNG MÀU                   │" << endl;
                        cout << "\t\t├───────────────────────────────────────────────┤" << endl;
                        cout << "\t\t│ 1. XANH TRỜI           2. XANH LÁ CÂY         │" << endl;
                        cout << "\t\t│ 3. XANH NƯỚC BIỂN      4. ĐỎ                  │" << endl;
                        cout << "\t\t│ 5. TÍM                 7. TRẮNG               │" << endl;
                        cout << "\t\t│ 7. TRẮNG               30. NỀN XANH,CHỮ TRẮNG │" << endl;
                        cout << "\t\t│ 79. NỀN ĐỎ,CHỮ TRẮNG   87. NỀN TÍM,CHỮ TRẮNG  │" << endl;
                        cout << "\t\t├───────────────────────────────────────────────┤" << endl;
                        cout << "\t\t│           0.MENU          00.EXIT             │" << endl;
                        cout << "\t\t╰───────────────────────────────────────────────╯" << endl;
                        cout << "\t\tCHOOSE: "; cin >> color;
                        if (color == 1)TextColor(1);
                        if (color == 2) TextColor(2);
                        if (color == 3) TextColor(3);
                        if (color == 4) TextColor(4);
                        if (color == 5) TextColor(5);
                        if (color == 7) TextColor(7);
                        if (color == 30) TextColor(30);
                        if (color == 79) TextColor(79);
                        if (color == 87) TextColor(87);
                        if(color==00)  exit(0);
                    } while (color!=0);
                } break;
                case 2:{ system("cls"); system("python C:\\Users\\hcao8\\source\\project\\life\\source code\\screen.py");  system("python screen.py"); }break;
                case 3:{ system("cls"); system("python C:\\Users\\hcao8\\source\\project\\life\\source code\\volum.py"); system("python volum.py"); }break;
                case 4:{
                do{system("cls");cout<<"\n\n";
                cout << "\t╭──────────────────────────────╮" << endl;
                cout << "\t│1.ONL  2.OFF  3.MENU    4.EXIT│" << endl;
                cout << "\t╰──────────────────────────────╯" << endl;
                cout<<"\tCHOOSE: ";cin>>choice;
                switch(choice){
                    case 1:{ system("powershell.exe -Command \"(Get-WmiObject -Namespace root/WMI -Class MSPower_DeviceEnable).Enable()\"");}break;
                    case 2:{ system("powershell.exe -Command \"(Get-WmiObject -Namespace root/WMI -Class MSPower_DeviceEnable).Disable()\"");}break; 
                    case 4:{exit(0);}break;
                }}while(choice!=3);
                }break;
                case 5:{system("pip install numpy && pip install pyautogui && pip install opencv-python && pip install pyperclip && pip install screen-brightness-control && pip install sounddevice");}break;
                case 0:{exit(0);}break;
            }
            }while(choice!=00);
          }break;
        case 7: { system("title HDSD");
              system("cls");times(); cout << "\n";
              cout << "┌─────────────────────────────────────────────────────────────────┐" << endl;
              cout << "│         HƯỚNG DẪN CÀI ĐẶT BIÊN DỊCH TIẾNG VIỆT                  │" << endl;
              cout << "├─────────────────────────────────────────────────────────────────┤" << endl;
              cout << "│B1: MỞ CONTROL PANEL                                             │" << endl;
              cout << "│NẾU KHÔNG CÓ THÌ GÕ (WIN +R) NHẬP 'CMD'--> NHẬP 'CONTROL PANEL'  │" << endl;
              cout << "│B2: NHẬP CHANGE DATE, TIME OR NUMBER FORMATS                     │" << endl;
              cout << "│B3: ADMINISTRATIVE                                               │" << endl;
              cout << "│B4: CHANGE SYSTEM LOCAL                                          │" << endl;
              cout << "│B5: TÍCH VÀO Ô Beta: Use Unicode UTF-8                           │" << endl;
              cout << "│B6: BẮT BUỘC KHỞI ĐỘNG LẠI MÁY                                   │" << endl;
              cout << "└─────────────────────────────────────────────────────────────────┘" << endl<< endl; system("pause"); 
        } break;
        case 8:{system("cls");cout<<"\n\n";
        
        }break;
        case 9:{work();} break;  
    }
    }while(choice!=0);
}

//function work
void work(){int work;
system("title WORK");
      do{system("cls"); cout << "\n";
            cout << "\t╭────────────────────────╮" << endl;
            times();
            digital();
            cout << "\t╰────────────────────────╯" << endl<<endl;
                cout << "\t╭────────────────────────────────────╮" << endl;
                cout << "\t│             LÀM VIỆC               │" << endl;
                cout << "\t├────────────────────────────────────┤" << endl;
                cout << "\t│ 1.DEPIN AIRDROP                    │" << endl;
                cout << "\t│ 2.WEB-TIỆN ÍCH                     │" << endl;
                cout << "\t│ 3.TOOL ĐA LUỒNG                    │" << endl; 
                cout << "\t│ 4.TẠO USER +PASS TỰ ĐỘNG SLL(error)│" << endl; //error
                cout << "\t╰────────────────────────────────────╯" << endl;
                cout << "\t╭────────────────────────────────────╮" << endl;
                cout << "\t│  5.EXIT  6.QUAY LẠI                │" << endl;
                cout << "\t╰────────────────────────────────────╯" << endl;
                cout << "\t CHOOSE: "; cin >> work;
                switch (work){
                case 1: {int airdrop;
                    do{ system("cls"); cout << "\n\n\n";
                        cout << "\t1.NODEPAY\t2.BLOCKMESH\t3.BLESS\n\n";
                        cout << "\t4.GRADIENT\t5.PIPE\t6.TENEO\n\n";
                        cout << "\t7.OPEN LOOP\t8.\n\n";
                        cout << "\t9.QUAY LẠI   0.EXIT\n\n";
                        cout << "\tCHOOSE: "; cin >> airdrop;
                        switch (airdrop){
                        case 1:{ ShellExecuteW(0, 0, L"https://app.nodepay.ai/dashboard", 0, 0, SW_SHOW);  ShellExecuteW(0, 0, L"https://chromewebstore.google.com/detail/nodepay-extension/lgmpfmgeabnnlemejacfljbmonaomfmm", 0, 0, SW_SHOW); } break;
                        case 2:{ ShellExecuteW(0, 0, L"https://app.blockmesh.xyz/ui/dashboard", 0, 0, SW_SHOW);   ShellExecuteW(0, 0, L"https://chromewebstore.google.com/detail/blockmesh-network/obfhoiefijlolgdmphcekifedagnkfjp", 0, 0, SW_SHOW); }  break;
                        case 3:{ ShellExecuteW(0, 0, L"https://chromewebstore.google.com/detail/bless/pljbjcehnhcnofmkdbjolghdcjnmekia", 0, 0, SW_SHOW);  ShellExecuteW(0, 0, L"https://bless.network/dashboard", 0, 0, SW_SHOW); } break;
                        case 4:{ ShellExecuteW(0, 0, L"https://chromewebstore.google.com/detail/gradient-sentry-node/caacbgbklghmpodbdafajbgdnegacfmo", 0, 0, SW_SHOW);  ShellExecuteW(0, 0, L"https://app.gradient.network/dashboard", 0, 0, SW_SHOW); } break;
                        case 5:{ ShellExecuteW(0, 0, L"https://chromewebstore.google.com/detail/pipe-guardian-node/gelgmmdfajpefjbiaedgjkpekijhkgbe", 0, 0, SW_SHOW); ShellExecuteW(0, 0, L"https://pipecdn.app/", 0, 0, SW_SHOW); } break;
                        case 6:{ ShellExecuteW(0, 0, L"https://chromewebstore.google.com/detail/teneo-community-node/emcclcoaglgcpoognfiggmhnhgabppkm", 0, 0, SW_SHOW);  ShellExecuteW(0, 0, L"https://dashboard.teneo.pro/dashboard", 0, 0, SW_SHOW); }break;
                        case 7:{ShellExecuteW(0, 0, L"https://openloop.so/dashboard", 0, 0, SW_SHOW); ShellExecuteW(0, 0, L"https://chromewebstore.google.com/detail/openloopso-sentry-node-ex/effapmdildnpkiaeghlkicpfflpiambm", 0, 0, SW_SHOW);}break;
                        case 0:{exit(0);}break;
                        }
                    } while (airdrop!=9);
                }break;
                case 2:{
                    do { system("cls"); cout << "\n\n\n";
                        cout<<"\t_______________________________WEB HỮU ÍCH_____________________________________\n\n";
                        cout << "\t1.SHADOWROCKET FREE    2.CAPCUT WEB    3.TRAO ĐỔI SUB\n";
                        cout << "\t4.MUA PROXY           5.MUA VPS       6.TÀI LIỆU LẬP TRÌNH TỔNG HỢP\n";
                        cout << "\t7.GIẢM DUNG LƯỢNG ẢNH/VIDEO           8.TÀI LIỆU THI MOS TIN HỌC\n";
                        cout << "\t9.GOLIKE-KIẾM TIỀN       10.CHECK VỊ TRÍ\n\n";
                        cout<<"\t_____________________________TIỆN ÍCH TRÌNH DUYỆT_______________________________\n\n";
                         cout << "\t11.LỌC BẠN BÈ FB     12.ĐỌC TIN NHẮN BỊ XÓA     13.DỊCH THUẬT\n";
                        cout << "\t14.MENU           0.EXIT\n";
                        cout << "\tCHOOSE: "; cin >> work;
                        switch (work){
                        case 1:{   system("cls"); ShellExecuteW(0, 0, L"https://idapple.csadata4g.me/", 0, 0, SW_SHOW);system("pause"); } break;
                        case 2:{  system("cls"); ShellExecuteW(0, 0, L"https://www.capcut.com/templates?enter_from=page_header&from_page=work_space&utm_campaign=71417362&utm_content=7124305287909100801&utm_medium=tiktok_anchor&utm_source=tiktok_anchor_template&templateId=7124305287909100801&start_tab=video", 0, 0, SW_SHOW);  } break;
                        case 3:{  system("cls"); ShellExecuteW(0, 0, L"https://traodoisub.com/home/", 0, 0, SW_SHOW); } break;
                        case 4:{ system("cls"); ShellExecuteW(0, 0, L"https://www.wwproxy.com/profile", 0, 0, SW_SHOW);   }  break;
                        case 5:{ system("cls"); ShellExecuteW(0, 0, L"https://vpsviet24h.com/", 0, 0, SW_SHOW);  }  break;
                        case 6:{ system("cls");  ShellExecuteW(0, 0, L"https://goalkicker.com/?fbclid=IwAR20VkJ6_dT8pRN9HfB3a4vVrfROouiWKPcAIKNv44d7rWyDQTwUldNqIAg", 0, 0, SW_SHOW);  }  break;
                        case 7:{  system("cls"); ShellExecuteW(0, 0, L"https://www.youcompress.com/videos/", 0, 0, SW_SHOW);  }  break;
                        case 8:{  system("cls"); ShellExecuteW(0, 0, L"https://blogdaytinhoc.com/tron-bo-tai-lieu-giao-trinh-luyen-thi-mos-2019-moi-nhat-830", 0, 0, SW_SHOW);  } break;
                        case 9:{  system("cls");  ShellExecuteW(0, 0, L"https://app.golike.net/home", 0, 0, SW_SHOW);  } break;
                        case 10:{  system("cls");  ShellExecuteW(0, 0, L"https://whatismyipaddress.com/vi-vn/index", 0, 0, SW_SHOW);  } break;
                        case 11:{  ShellExecuteW(0, 0, L"https://chromewebstore.google.com/detail/l%E1%BB%8Dc-b%E1%BA%A1n-b%C3%A8-kh%C3%B4ng-t%C6%B0%C6%A1ng-t%C3%A1/hlnhbiajcpmjpgpedgfdigiccejengbi?hl=vi", 0, 0, SW_SHOW); }break;
                        case 12:{   ShellExecuteW(0, 0, L"https://chromewebstore.google.com/detail/reveal-deleted-fb-message/oddpcajnaolfbinffajkacjhohhahlib?hl=vi", 0, 0, SW_SHOW);  } break;
                        case 13:{  ShellExecuteW(0, 0, L"https://chromewebstore.google.com/detail/google-d%E1%BB%8Bch/aapbdbdomjkkjkaonfhkkikfgjllcleb?hl=vi", 0, 0, SW_SHOW); } break;
                        case 0:{exit(0);}break;
                    }
                    } while (work !=14);
                }break;
                case 3:{ int number;string link;
                    do{system("cls");cout<<"\n\n";
                        cout << "\t╭───────────────────────────╮" << endl;
                        cout << "\t│     LỰA CHỌN CHỨC NĂNG    │" << endl;
                        cout << "\t├───────────────────────────┤" << endl;
                        cout << "\t│  1.                       │" << endl;
                        cout << "\t│  2.                       │" << endl;
                        cout << "\t│  3. TRAODOISUB            │" << endl;
                        cout << "\t│  4.                       │" << endl;
                        cout << "\t├───────────────────────────┤" << endl;
                        cout << "\t│  5. EXIT         6.MENU   │" << endl;
                        cout << "\t╰───────────────────────────╯" << endl;
                        cout << "\tCHOOSE: "; cin >> work;
                        switch (work){
                        case 1:{}break;                 
                        case 2: {} break;
                        case 3: {
                            do{ system("cls"); cout << "\n\n";
                                cout << "\t1.TDS FB\t2.TDS TIKTOK\n";
                                cout << "\t0.QUAY LẠI   3.EXIT\n";
                                cout << "\tCHOOSE: ";cin >> work;
                                switch (work) {
                                case 1: { system("cls"); cout << "\n\n";
                                    cout << "\tsố cửa sổ: "; cin >> number;
                                    link = "python C:\\Users\\hcao8\\source\\project\\life\\tool\\tds\\tdsfb.py";
                                    for (int i = 0; i <= number-1; i++) {
                                        string cmd = "cmd/c start "+link; // CMD : OPEON CMD  -- /C: MỞ LẠI VỚI LẦN LẶP KHÁC  --- START : MỞ --- TÊN FILE .
                                        system(cmd.c_str());
                                    } system("pause"); }break;
                                case 2: { system("cls");cout << "\n\n";
                                    cout << "\tsố cửa sổ: ";cin >> number;
                                    link = "python C:\\Users\\hcao8\\source\\project\\life\\tool\\tds\\tdstt.py";
                                    for (int i = 0; i <= number; i++){
                                        string cmd = "cmd/c start " + link; // CMD : OPEON CMD  -- /C: MỞ LẠI VỚI LẦN LẶP KHÁC  --- START : MỞ --- TÊN FILE .
                                        system(cmd.c_str());
                                    }system("pause"); }break;
                                case 3:{exit(0);}break;
                                }
                            } while (work != 0);
                        }break;
                        case 4:{ }break;
                        case 5:{exit(0);}break;
                    }
                    }while(work!=6);
                }break;
                case 4:{system("python account.py");}break;
                case 5:{exit(0);}break;
                case 6:{case_chinh();}break;
                }
            } while (work !=0);
}


int main(){
    case_chinh(); 
    return 0;
}
 