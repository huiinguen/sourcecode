#include<iostream>
#include<string>
#include<windows.h>
#include<fstream>
#include<ctime>

using namespace std;

// khai báo hàm
void menu();
void menu_banking();
void setting();
bool sign_in();
void sign_up();
void banking_setting();
void deposit();
void graphics_user();
void read_deposit();
void history_deposit();
void update();

void TextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color); 
}

//---------------------- banking---------------------------

// bản cập nhật
void update(){int choice;
    do{system("cls");cout<<"\n\n";
        cout<<"\t\t phiên bản banking(source code)\n\n";
        cout<<"\t1. version 1\n";
        cout<<"\t2. version 2\n";
        cout<<"\t3. version 3\n";
        cout<<"\t4. version 4\n";
        cout<<"\t--> ";cin>>choice;
        switch(choice){
            case 1:{cout<<"\n";
            cout<<"\tmô tả: bản cập nhật ban đầu\n";
            cout<<"\tchức năng: hạn chế nhiều\n";
            cout<<"\tLink sourc: \n";
            system("start ");
            system("pause");
            }
            case 2:{}
            case 3:{}
            case 4:{}
        }
    }while(choice!=0);
}
// banking setting
void banking_setting(){int choice;
    do{system("cls");cout<<"\n\t";
        cout<<"\t1.Color\n";
        cout<<"\t2.\n";
        cout<<"\t0.Exit\n";
        cout<<"\t---> ";cin>>choice;

        if(choice==1){
            do{system("cls");cout<<"\n";
            cout << "\t\t\tSetup màu cho banking\n\n";
            cout << "\t2.xanh        3.xanh biển              4.đỏ        5.tím\n";
            cout << "\t7. trắng      75.trắng phủ hồng        87. trắng phủ nền\n";
            cout << "\t0.Exit\n";
            cout << "\t--> ";cin >> choice;
            if (choice == 2)TextColor(2);
            else if (choice == 3)TextColor(3);
            else if(choice==4)TextColor(4);
            else if(choice==5)TextColor(5);
            else if(choice==7)TextColor(7);
            else if (choice == 75)TextColor(75);
            else if (choice == 87)TextColor(87);
            }while(choice!=0);
        }
        if(choice==2){}
    }while(choice!=0);
}

// đăng ký tài khoản
void sign_up(){string password;
     ofstream openfile("sign_up_account.txt");
     if(openfile.is_open()){
        cout<<"\n\n\tHệ thống đang mở để đọc dữ liệu\n";
        cout<<"\tPassword: ";cin>>password;
        openfile<<password;
        openfile.close();
        Sleep(1000); cout << "\tHệ thống đã ghi thành công.\n";
     }
     else{
        cout<<"\nn lỗi hệ thống\n";
     }
}

// đăng nhập
bool sign_in() {string password, check_password;
    ifstream openfile("sign_up_account.txt");

    if (openfile.is_open()) {
        openfile >> check_password;
        openfile.close();

        cout << "\n\n\tPassword: "; 
        cin >> password;

        if (check_password != password) {
            cout << "\tWarning! Mật khẩu sai\n";
            Sleep(1000);
            return false;
        } else {
            cout << "\t✅ Đăng nhập thành công\n";
            Sleep(1000);
            return true;
        }
    } else {
        cout << "\tWarning! Không thể mở file dữ liệu.\n";
        Sleep(1000);
        return false;
    }
}

// menu banking(main)
void menu_banking(){int choice;
    do{system("cls");cout<<"\n\n";
        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣷⣶⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << "\n";
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
        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠻⢧⡸⣿⣿⣿⠀⠃⠻⠟⢦⢾⢣⠶⠿⠏⠀⠰⠀⣼⡇⣸⣿⣿⠟⠉⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠀ 3.Setting⠀" << "\n";
        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⣾⣶⣽⣿⡟⠓⠒⠀⠀⡀⠀⠠⠤⠬⠉⠁⣰⣥⣾⣿⣿⣶⣶⣷⡶⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  4.Update⠀" << "\n";
        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠉⠉⠹⠟⣿⣿⡄⠀⠀⠠⡇⠀⠀⠀⠀⠀⢠⡟⠛⠛⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   0.Exit" << "\n";
        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⠋⠹⣷⣄⠀⠐⣊⣀⠀⠀⢀⡴⠁⠣⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << "\n";
        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⣀⠤⠊⢁⡸⠀⣆⠹⣿⣧⣀⠀⠀⡠⠖⡑⠁⠀⠀⠀⠑⢄⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << "\n";
        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣦⣶⣿⣿⣟⣁⣤⣾⠟⠁⢀⣿⣆⠹⡆⠻⣿⠉⢀⠜⡰⠀⠀⠈⠑⢦⡀⠈⢾⠑⡾⠲⣄⠀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << "\n";
        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠖⠒⠚⠛⠛⠢⠽⢄⣘⣤⡎⠠⠿⠂⠀⠠⠴⠶⢉⡭⠃⢸⠃⠀⣿⣿⣿⠡⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << "\n";
        cout << "\t\t\t\t\t\t\t---> ";cin >> choice;
        switch (choice){
        case 1:{
            if (sign_in()){graphics_user();}
            break;
        }
        case 2:{sign_up();Sleep(1000);break;}
        case 3:{banking_setting();break;}
        case 4:{update();break;}
    }
    }while(choice!=0);
}

//--------------------------graphics user----------------------

// nạp tiền
void deposit(){string money;
     ofstream openfile("deposit.txt");
     if(openfile.is_open()){
        cout<<"\tdang ghi du lieu vao he thong\n";
        cout<<"\tPassword: ";cin>>money;
        openfile<<money;
        openfile.close();
        cout << "\tDang ky thanh cong.\n";
     }else{cout<<"\nloi he thong\n";}
}

// đọc số tiền
void read_deposit(){string money;
    ifstream openfile("deposit.txt");
    if(openfile.is_open()){
        openfile>>money;
        cout<<"\tMoney: "<<money<<endl;
    }
    else{cout<<"\terror\n";}
}

// lịch sử nạp tiền
void history_deposit(){

}
// hàm chính user(main)
void graphics_user(){int choice;
    do{system("cls");cout<<"\n\n";
        read_deposit();
        cout<<"\n\n";
        cout<<"\t1. Nạp tiền\n";
        cout<<"\t2. Lịch sử nạp tiền\n";
        cout<<"\t--> ";cin>>choice;
        switch(choice){
            case 1:{deposit();break;}
            case 2:{history_deposit();break;}
        }
    }while(choice!=0);
}


//-------------------------------------------------------------
int main(){
    menu_banking();
    return 0;
}