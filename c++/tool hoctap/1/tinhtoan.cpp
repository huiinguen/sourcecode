#include <iostream>
#include<math.h>
#include <iomanip>
#include <string>
#include <windows.h>
#include <bitset>

using namespace std;

void TextColor(int color){ SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); }

void tinh_toan(){ int data;
        do{ system("cls"); cout << "\n";
            cout << "\t 1.DUNG LƯỢNG    2.TIME         " << endl;
            cout << "\t 3.TRADING       4.MÃ HÓA TEXT  " << endl;   
            cout << "\t 5.TIỀN ĐIỆN     6.TÍNH LẠM PHÁT" << endl;                          
            cout << "\t 7.SPAM TEXT     8.RETURN   " << endl;              
            cout<<"\t--> ";cin>>data;
            switch (data){
            case 1:{  double bit, byte, kilobyte, megabyte, gigabyte;
                do{ system("cls"); cout << "\n";
                    cout << "\t1. GB -> MB                   " << endl;
                    cout << "\t2. MB -> KB, GB               " << endl;
                    cout << "\t3. KB -> BYTE, MB             " << endl;
                    cout << "\t4. BYTE -> BIT, KB            " << endl;
                    cout << "\t5. BIT  -> BYTE, KB           " << endl;
                    cout << "\t6. BIT + BYTE + KB + MB -> GB " << endl;
                    cout << "\t7. BIT + BYTE + KB + GB -> MB " << endl;
                    cout << "\t8. RETURN         " << endl<<endl;
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
                do{ system("cls");cout<<"\n";
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
                    cout << "\t 11.RETURN       " << endl;
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
            case 3: {system("title TRADE");system("cls");cout<<"\n";
                cout<<"\t1.BUY/SELL      2.FUTURE DCA\n";
                cout<<"\t--> ";cin>>data;
                if(data==1){ system("cls");cout<<"\n\n";     
                    double money, input, output,phi_trade;
                    cout << fixed << setprecision(2);

                    cout << "\n\n\t💰USD: ";  cin >> money;
                    cout << "\t📉 GIÁ MUA  : "; cin >> input;
                    cout << "\t📈 GIÁ BÁN  : "; cin >> output;
                    cout << "\t💰 PHÍ TRADE(%): "; cin >> phi_trade;
                    cout << "\n\n\t📊 ĐANG TÍNH TOÁN...\n";Sleep(500);

                    float sl_coin = money / (input*(1+phi_trade/100));
                    float ban_coin = sl_coin * output*(1-phi_trade/100);
                    float loi_and_lo = ban_coin - money;
                    float person = (loi_and_lo / money) * 100;

                    cout << "\n\t🪙 SỐ LƯỢNG COIN: " << sl_coin << " COIN";
                    cout << "\n\t💵 TỔNG TIỀN: " << ban_coin << " USD";

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
                    cout << "\n\t📌 TỈ LỆ(%): " << person << " %\n\n";

                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // reset về màu trắng  system("pause");

                }

                if(data==2){system("cls");cout<<"\n\n";
                }
                
                if(data==0){exit(0);}
                cout<<"\n\n";system("pause");
            }break;
            case 4:{system("cls");cout<<"\n";
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
                do{system("cls");cout<<"\n";
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
                        case 0:{exit(0);}break;
                    }
                }while(data!=3);
            }break;
            case 6:{system("cls");cout<<"\n";  float CPI_hientai,CPI_goc;
            cout<<"\t LOẠI BỎ DẤU PHÂN CÁCH(VND)\n\n";
            cout<<"\t GIÁ GỐC: ";cin>>CPI_goc;
            cout<<"\t GIÁ HIỆN TẠI: ";cin>>CPI_hientai;

            float lamphat=(CPI_hientai-CPI_goc)/CPI_goc*100;
            cout<<"\n\tKQ: "<<lamphat<<"%"<<"\n\n"; system("pause");
            }break;
            case 7:{system("cls");cout<<"\n\n";string text;
            int n;
            cout<<"\tso lan: ";cin>>n;
            cin.ignore();
            cout<<"\tTEXT: ";cin>>text;
            getline(cin,text);
            for (int i = 0; i < n; ++i){
                cout<< text << endl;
            } system("pause");
            }break;
            case 0:{exit(0);}break;
            }
        }while(data!=8);
}

int main() {
    tinh_toan();
    return 0;
}