#include <iostream>
#include <math.h>
#include <windows.h>
#include <map>

using namespace std;

unsigned long long tinhGiaiThua(int n){
    unsigned long long ketQua = 1;
    for (int i = 2; i <= n; ++i) ketQua *= i;
    return ketQua;
}

unsigned long long demSoHoanVi(const string &chuoi){
    map<char, int> demKyTuLap;

    for (char kyTu : chuoi) {demKyTuLap[kyTu]++;}

    // Hiển thị phân tích số lần xuất hiện
    cout << "\nPhan tich ky tu\n";
    for (auto cap : demKyTuLap){
        cout << "Ky tu " << cap.first << " : " << cap.second << " Lan\n";
    }

    unsigned long long tuSo = tinhGiaiThua(chuoi.length());

    unsigned long long mauSo = 1;
    for (auto cap : demKyTuLap){
        mauSo *= tinhGiaiThua(cap.second);
    }

    return tuSo / mauSo;
}


void hoc_tap(){int study;
    do{system("cls");
        cout << "\n\n\t===============HỌC TOÁN====================\n";
        cout << "\t 1.MATH THPT   2.TÍNH NHANH    3.UNIVER  \n";
        cout<<"\t=================================================\n";
        cout << "\t 4.RETURN " << endl;
        cout << "\t-->: ";cin >> study;
        switch (study){
        case 1:{float pi = 3.14159, a, b, c, d,x, a2, b2, c2, d2, a3, b3, c3, d3, r, x2, y2, z2, x3, y3, z3, l, z, y, h;
            do{system("cls");
                cout << "\n\n\t---------------GIAI PT--------------------------------------------\n";
                cout << "\t 1.AX^2 + BX + C ( (BẬC 2)          " << endl;
                cout << "\t 2.A.X^3 + B.X^2 + C.X^1 + D (BẬC 3)  " << endl;
                cout << "\t 3.A.X^4 + B.X^2 + C (BẬC 4)          " << endl;
                cout << "\t 4.GIẢI PT 2 ẨN " << "\n";
                cout << "\t 5.GIẢI PT 3 ẨN " << "\n";
                cout << "\t--------------------------------------------------------------------\n\n";
                cout << "\t 6.TÍCH VÔ HƯỚNG 2 VECTO\n";
                cout << "\t 7.HÌNH NÓN-TRỤ-CẦU " << "\n\n";
                cout << "\t ------------TÍCH CÓ HƯỚNG VÀ ỨNG DỤNG-------------------------------\n";
                cout << "\t 8.TÍCH CÓ HƯỚNG                    9.DIỆN TÍCH TAM GIÁC ABC          " << endl;
                cout << "\t 10.DIỆN TÍCH HÌNH BÌNH HÀNH ABCD   11.THỂ TÍCH KHỐI HỢP ABCD.A'B'C'D'   " << endl;
                cout << "\t 12.THỂ TÍCH TỨ DIỆN ABCD             " << endl;
                cout << "\t---------------------------------------------------------------------\n";
                cout << "\t 13. KHOẢNG CÁCH GIỮA 2 ĐIỂM   " << endl;
                cout << "\t---------------------------------------------------------------------\n";
                cout << "\t 14. RETURN    \n";
                cout << "\t-->  ";cin >> study;
                switch(study){
                case 1:{system("cls");
                    cout << "\n\tA: ";cin >> a; 
                    cout << "\tB: ";cin >> b; 
                    cout << "\tC: ";cin >> c;

                    system("cls");
                    cout << "\n\n\tF(X)= 0 <=> f(x)=" << a << "X^2" << " + " << b << "X + " << c << " = 0\n";
                    cout << "\tF'(X)= 0 <=> F'(X)= " << a * 2 << "X" << " + " << b << "\n\n";

                    float delta = pow(b, 2) - (4 * a * c);

                    if (delta > 0){
                        cout << "\tX1= " << (-b + sqrt(delta)) / (2 * a);
                        cout << "\tX2= " << (-b - sqrt(delta)) / (2 * a);
                    }else{
                        if (delta == 0)   cout << "\tNO KEP ==> X= " << -b / (2 * a);
                        else              cout << "\tVO NGHIEM";
                    }
                    system("pause");
                }break;
                case 2:{system("cls");
                    cout << "\n\tA(A!=0): ";cin >> a;
                    cout << "\tB: ";cin >> b;
                    cout << "\tC: ";cin >> c;
                    cout << "\tD: ";cin >> d;
                    system("cls");

                    cout << "\n\n\tf(x)= " << a << "X^3 + " << b << "X^2 + " << c << "X" << " + " << d << " = 0" << "\n\n";
                    cout << "\tF'(X)= 0 <=> F'(X)= " << 3 * a << "X^2" << " + " << 2 * b << "x" << " + " << c * 1 << " = 0 \n\n";

                    float delta = pow(2 * b, 2) - 4 * 3 * a * c;

                    if (delta > 0){
                        // công thức x1,x2
                        float x1_bac3 = (-2 * b + sqrt(delta)) / (6 * a), x2_bac3 = (-2 * b - sqrt(delta)) / (6 * a);
                        float x1_bac3_thanh_y1 = (a * pow(x1_bac3, 3)) + (b * pow(x1_bac3, 2)) + (c * x1_bac3) + d, x2_bac3_thanh_y2 = (a * pow(x2_bac3, 3)) + (b * pow(x2_bac3, 2)) + (c * x2_bac3) + d;
                        // 3*a*2*pow(x1_bac3,1) là đạo hàm y'' của y để tính điều kiện cho chuẩn

                        cout << "\t\tX1: " << x1_bac3 << " ==> Y: " << x1_bac3_thanh_y1 << " ==> ";
                        if (3 * a * 2 * pow(x1_bac3, 1) > 0)    cout << "Yct";
                        else                                    cout << "Ycd"; // Dùng f'' kiểm tra

                        cout << "\n\n\t\tX2: " << x2_bac3 << " ==> Y: " << x2_bac3_thanh_y2 << " ==> ";
                        if (3 * a * 2 * pow(x2_bac3, 1) > 0)   cout << "Yct";
                        else                                   cout << "Ycd"; // f'' = 6ax
                    }

                    if (delta == 0){
                        float no_kep = -2 * b / (6 * a);
                        cout << "\tNGHIEM KEP: " << no_kep << endl;
                    }

                    if (delta < 0)    cout << "\t vo nghiem\n\n";
                    system("pause");
                }break;
                case 3:{system("cls");
                    cout << "\n\tA: ";cin >> a;
                    cout << "\tB: ";cin >> b;
                    cout << "\tC: ";cin >> c;
                    system("cls");cout << "\n\n";

                    if (a == 0){
                        cout << "Đây không phải hàm bậc 4!" << endl;   break;
                    }

                    float check = -b / (2 * a); // để kiểm tra nghiệm thực
                    if (check < 0){
                        cout << "\tF(x) = " << a << "x^4 + " << b << "x^2 + " << c << endl;
                        cout << "\tF'(x) = " << 4 * a << "x^3 + " << 2 * b << "x" << "\n\n";
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
                        cout << "\tF'(x) = " << 4 * a << "x^3 + " << 2 * b << "x" <<"\n\n";

                        // tinnh x0
                        cout << "\tX0= 0 <=> y: " << y0 << " ";
                        if (fx_lan2 > 0)        cout << "\t CỰC TIỂU";
                        else if (fx_lan2 < 0)   cout << "\t CỰC ĐẠI";
                        else                    cout << "\t loading... ";
                        cout << "\n";

                        // tinh x1
                        cout << "\tX1= " << x1_bac4 << " ==y: " << y1_bac4 << " ";
                        if (daohamlan2_fx1 > 0)      cout << "\t CỰC TIỂU";
                        else if (daohamlan2_fx1 < 0) cout << "\t CỰC ĐẠI";
                        else                         cout << "\t loading...";
                        cout << "\n";

                        // tinh x2
                        cout << "\tX2= " << x2_bac4 << " ==y: " << y2_bac4 << " ";
                        if (daohamlan2_fx2 > 0)      cout << "\t CỰC TIỂU";
                        else if (daohamlan2_fx2 < 0) cout << "\t CỰC ĐẠI";
                        else                         cout << "\t loading...";
                        cout << "\n";
                    }
                    system("pause");
                }break;
                case 4:{
                    do{system("cls");
                        cout << "\n\t1. (2PT)    2. (3PT)     3. RETURN  \n";
                        cout << "\t--> ";cin >> study;
                        switch (study){
                        case 1:{system("cls");
                            cout << "\n\n\ta(!=0): ";cin >> a;
                            cout << "\tb: ";cin >> b;
                            cout << "\tc: ";cin >> c;
                            cout << "\ta2: ";cin >> a2;
                            cout << "\tb2: ";cin >> b2;
                            cout << "\tc2: ";cin >> c2;
                            system("cls");

                            cout << "\n\t      {" << a << "x + " << b << "y = " << c << " (1)\n";
                            cout << "\tPT <=>{\n";
                            cout << "\t      {" << a2 << "x + " << b2 << "y = " << c2 << " (2)\n\n\n";

                            if (a * b2 == a2 * b)   cout << "\tPT VO NGHIEM HOAC VO SO NGHIEM\n";

                            float x = (c * b2 - c2 * b) / (a * b2 - a2 * b);
                            float y = (c - a * x) / b;
                            cout << "\tX= " << x << "\tY= " << y << endl;
                            system("pause");
                        }break;
                        case 2:{system("cls");
                            int a, b, c, a2, b2, c2, a3, b3, c3;
                            cout << "\n\n\ta: ";cin >> a;  cout << "\tb: ";cin >> b;  cout << "\tc: ";cin >> c;  cout << "\ta2: ";cin >> a2;  cout << "\tb2: ";cin >> b2; cout << "\tc2: ";cin >> c2;  cout << "\ta3: ";cin >> a3; cout << "\tb3: ";cin >> b3; cout << "\tc3: ";cin >> c3;

                            system("cls");
                            cout << "\n\n\t{" << a << "x + " << b << "y = " << c << endl;
                            cout << "\t{" << a2 << "x + " << b2 << "y = " << c2 << endl;
                            cout << "\t{" << a3 << "x + " << b3 << "y = " << c3 << endl;
                            cout << "\n\n";

                            int del_d = a * b2 - a2 * b, del_dx = c * b2 - c2 * b, del_dy = a * c2 - a2 * c;
                            float x = (float)del_dx / del_d, y = (float)del_dy / del_d;

                            cout << "\tX= " << x << "\tY= " << y << endl;

                            int thaynghiem = a3 * x + b3 * y;
                            cout << "\tCHECK: ";
                            if (thaynghiem == c3){
                                cout << "✅\n";
                            }else{
                                cout << "✖️\n";
                            }
                            system("pause");
                        }break;
                        case 0:exit(0);
                        }
                    } while (study != 3);
                }break;
                case 5:{system("cls");
                    cout << "\n\ta1: ";cin >> a; cout << "\tb1: ";cin >> b;  cout << "\tc1: ";cin >> c; cout << "\td1: ";cin >> d; cout << "\ta2: ";cin >> a2; cout << "\tb2: ";cin >> b2; cout << "\tc2: ";cin >> c2; cout << "\td2: ";cin >> d2; cout << "\ta3: ";cin >> a3;  cout << "\tb3: ";cin >> b3;  cout << "\tc3: ";cin >> c3;  cout << "\td3: ";cin >> d3;
                    system("cls");

                    cout << "\n\n\t    {" << a << "x + " << b << "y + " << c << "z = " << d << endl;
                    cout << "\t    {" << a2 << "x + " << b2 << "y + " << c2 << "z = " << d2 << endl;
                    cout << "\t    {" << a3 << "x + " << b3 << "y + " << c3 << "z = " << d3 << endl;
                    cout << "\n";

                    //  delA
                    int delA = a * (b2 * c3 - c2 * b3) - b * (a2 * c3 - c2 * a3) + c * (a2 * b3 - b2 * a3);

                    // Kiểm tra delA
                    if (delA == 0){
                        int del_aX = d * (b2 * c3 - c2 * b3) - b * (d2 * c3 - c2 * d3) + c * (d2 * b3 - b2 * d3);
                        int del_aY = a * (d2 * c3 - c2 * d3) - d * (a2 * c3 - c2 * a3) + c * (a2 * d3 - d2 * a3);
                        int del_aZ = a * (b2 * d3 - d2 * b3) - b * (a2 * d3 - d2 * a3) + d * (a2 * b3 - b2 * a3);

                        if (del_aX == 0 && del_aY == 0 && del_aZ == 0){
                            cout << "\tHe phuong trinh co vo so nghiem.\n";
                        }else{
                            cout << "\tHe phuong trinh vo nghiem.\n";
                        }
                    }

                    // del_aX, del_aY, del_aZ
                    int del_aX = d * (b2 * c3 - c2 * b3) - b * (d2 * c3 - c2 * d3) + c * (d2 * b3 - b2 * d3);
                    int del_aY = a * (d2 * c3 - c2 * d3) - d * (a2 * c3 - c2 * a3) + c * (a2 * d3 - d2 * a3);
                    int del_aZ = a * (b2 * d3 - d2 * b3) - b * (a2 * d3 - d2 * a3) + d * (a2 * b3 - b2 * a3);

                    // Tính nghiệm
                    float x = (float)del_aX / delA, y = (float)del_aY / delA, z = (float)del_aZ / delA;

                    // In kết quả
                    cout << "\tX = " << x << "\tY= " << y << "\tZ= " << z << endl;

                    // T kiểm tra
                    cout << "\n\tKiem tra nghiem:\n";
                    float ktra1 = a * x + b * y + c * z;
                    float ktra2 = a2 * x + b2 * y + c2 * z;
                    float ktra3 = a3 * x + b3 * y + c3 * z;
                    cout << "\tPt 1-> " << ktra1 << " ->d1 = " << d << "\n";
                    cout << "\tPt 2-> " << ktra2 << " ->d2 = " << d2 << "\n";
                    cout << "\tPt 3-> " << ktra3 << " ->d3 = " << d3 << "\n";
                    system("pause");
                }break;
                case 6:{system("cls");
                    cout << "\n\t QUY ƯỚC '' LÀ VECTO\n\n";
                    cout << "\t1.AB\t2.COS('A','B')\t3.|'A'|\n\n";
                    cout << "\tX: ";cin >> a;  cout << "\tY: ";cin >> b;  cout << "\tX2: ";cin >> a2;  cout << "\tY2: ";cin >> b2;

                    cout << "\n\n\tA(" << a << "," << b << ")\tB(" << a2 << "," << b2 << ")\n";
                    cout << "\tAB: " << sqrt(pow(a2 - a, 2) + pow(b2 - b, 2)) << "\n\n";

                    cout << "\tA(" << a << "," << b << ")\tB(" << a2 << "," << b2 << ")\n";
                    cout << "\tCOS('A','B')= " << ((a * b) + (b * b2)) / sqrt(pow(a, 2) + pow(a2, 2)) * sqrt(pow(b, 2) + pow(b2, 2)) << "\n\n";
                    cout << "\t|'A'|= (" << a << "," << a2 << ")" << endl;
                    cout << "\tKQ= " << sqrt(pow(a, 2) + pow(a2, 2)) << "\n\n";
                    system("pause");
                }break;
                case 7:{system("cls");
                    cout << "\n\tH: ";cin >> h;  cout << "\tR: ";cin >> r;  cout << "\tL: ";cin >> l;

                    system("cls");
                    cout << "\n\n\t HÌNH NÓN\n";
                    cout << "\t DIỆN TÍCH XUNG QUANH: " << pi * r * l << endl;
                    cout << "\t DIỆN TÍCH ĐÁY: " << pi * pow(r, 2) << endl;
                    cout << "\t DIỆN TÍCH TOÀN PHẦN: " << (pi * r * l) + (pi * pow(r, 2)) << endl;
                    cout << "\t THỂ TÍCH :" << (1.0 / 3.0) * pi * pow(r, 2) * h << "\n\n";

                    cout << "\t HÌNH TRỤ\n";
                    cout << "\t DIỆN TÍCH XUNG QUANH: " << 2 * pi * r * h << endl;
                    cout << "\t DIỆN TÍCH ĐÁY: " << 2 * pi * pow(r, 2) << endl;
                    cout << "\t DIỆN TÍCH TOÀN PHẦN: " << (2 * pi * r * h) + (2 * pi * pow(r, 2)) << endl;
                    cout << "\t THỂ TÍCH: " << pi * pow(r, 2) * h << "\n\n";

                    cout << "\t HÌNH CẦU\n";
                    cout << "\t DIỆN TÍCH HÌNH CẦU: " << 4 * pi * pow(r, 2) << endl;
                    cout << "\t THỂ TÍCH HÌNH CẦU: " << double(4.0 / 3.0) * pi * pow(r, 3) << "\n\n";
                    system("pause");
                }break;
                case 8:{system("cls");
                    cout << "\n\n\tX(A,B,C)\tB(A2,B2,C2)\tC(A3,B3,C3)\n\n";
                    cout << "\tA: ";cin >> a;  cout << "\tB: ";cin >> b;  cout << "\tC: ";cin >> c; cout << "\tA2: ";cin >> a2;  cout << "\tB2: ";cin >> b2; cout << "\tC2: ";cin >> c2; cout << "\tA3: ";cin >> a3; cout << "\tB3: ";cin >> b3; cout << "\tC3:";cin >> c3;
                    system("cls");

                    cout << "\n\n\tA(" << a << "," << b << "," << c << ") B(" << a2 << "," << b2 << "," << c2 << ") C(" << a3 << "," << b3 << "," << c3 << ")" << "\n";
                    cout << "\tAB=(" << a2 - a << "," << b2 - b << "," << c2 - c << ") AC=(" << a3 - a << "," << b3 - b << "," << c3 - c << ")\n";
                    cout << "\tSabc= " << 1 / 2.0 * sqrt(pow(((b2 - b) * (c3 - c)) - ((b3 - b) * (c2 - c)), 2) + pow(((a2 - a) * (c3 - c)) - ((a3 - a) * (c2 - c)), 2) + pow(((a2 - a) * (b3 - b)) - ((a3 - a) * (b2 - b)), 2)) << "\n\n";
                    system("pause");
                }break;
                case 9:{system("cls");
                    cout << "\n\n\tA(a,b,c)\tB(a2,b2,c2)\tC(a3,b3,c3)\n\n";
                    cout << "\tA: ";cin >> a;
                    cout << "\tB: ";cin >> b;
                    cout << "\tC :";cin >> c;
                    cout << "\tA2: ";cin >> a2;
                    cout << "\tB2: ";cin >> b2;
                    cout << "\tC2: ";cin >> c2;
                    cout << "\tA3: ";cin >> a3;
                    cout << "\tB3: ";cin >> b3;
                    cout << "\tC3: ";cin >> c3;
                    system("cls");

                    cout << "\n\n\t A(" << a << "," << b << "," << c << ")  B(" << a2 << "," << b2 << "," << c2 << ")  C(" << a3 << "," << b3 << "," << c3 << ")" << "\n\n";
                    cout << "\t AB=(" << a2 - a << "," << b2 - b << "," << c2 - c << ")\n";
                    cout << "\t AC= (" << a3 - a << "," << b3 - b << "," << c3 - c << ")\n\n";
                    cout << "\t [AB,AC] = [" << ((b2 - b) * (c3 - c)) - ((b3 - b) * (c2 - c)) << "," << ((a2 - a) * (c3 - c)) - ((a3 - a) * (c2 - c)) << "," << ((a2 - a) * (b3 - b)) - ((a3 - a) * (b2 - b)) << "]\n";
                    cout << "\t DO DAI AB,AC= " << sqrt(pow(((b2 - b) * (c3 - c)) - ((b3 - b) * (c2 - c)), 2) + pow(((a2 - a) * (c3 - c)) - ((a3 - a) * (c2 - c)), 2) + pow(((a2 - a) * (b3 - b)) - ((a3 - a) * (b2 - b)), 2)) << endl;
                    cout << "\t Sabc = " << 1 / 2.0 * sqrt(pow(((b2 - b) * (c3 - c)) - ((b3 - b) * (c2 - c)), 2) + pow(((a2 - a) * (c3 - c)) - ((a3 - a) * (c2 - c)), 2) + pow(((a2 - a) * (b3 - b)) - ((a3 - a) * (b2 - b)), 2)) << "\n\n";
                    system("pause");
                }break;
                case 10:{system("cls");
                    cout << "\n\n\tA(X,Y,Z) B(X2,Y2,Z3) D(X3,Y3,Z3)\n\n";
                    cout << "\tX: ";cin >> x;
                    cout << "\tY: ";cin >> y;
                    cout << "\tZ: ";cin >> z;
                    cout << "\tX2: ";cin >> x2;
                    cout << "\tY2: ";cin >> y2;
                    cout << "\tZ2: ";cin >> z2;
                    cout << "\tX3: ";cin >> x3;
                    cout << "\tY3: ";cin >> y3;
                    cout << "\tZ3: ";cin >> z3;
                    system("cls");

                    cout << "\n\n\tA(" << x << "," << y << "," << z << ") B(" << x2 << "," << y2 << "," << z2 << ") D(" << x3 << "," << y3 << "," << z3 << ")\n\n";
                    cout << "\tAB= (" << x2 - x << "," << y2 - y << "," << z2 - z << ")  AD= (" << x3 - x << "," << y3 - y << "," << z3 - z << ")\n\n";
                    cout << "\t[AB,AD]= " << "[" << ((y2 - y) * (z3 - z)) - ((y3 - y) * (z2 - z)) << "," << ((x2 - x) * (z3 - z)) - ((x3 - x) * (z2 - z)) << "," << ((x2 - x) * (y3 - y)) - ((x3 - x) * (y2 - y)) << "]\n";
                    cout << "\tSabcd= " << sqrt(pow(((y2 - y) * (z3 - z)) - ((y3 - y) * (z2 - z)), 2) + pow(((x2 - x) * (z3 - z)) - ((x3 - x) * (z2 - z)), 2) + pow(((x2 - x) * (y3 - y)) - ((x3 - x) * (y2 - y)), 2)) << "\n\n";
                    system("pause");
                }break;
                case 11:{system("cls");
                    cout << "\n\n\tA(X,Y,Z) B(X2,Y2,Z3) D(X3,Y3,Z3)\n\n";
                    cout << "\tX: ";cin >> x;
                    cout << "\tY: ";cin >> y;
                    cout << "\tZ: ";cin >> z;
                    cout << "\tX2: ";cin >> x2;
                    cout << "\tY2: ";cin >> y2;
                    cout << "\tZ2: ";cin >> z2;
                    cout << "\tX3: ";cin >> x3;
                    cout << "\tY3: ";cin >> y3;
                    cout << "\tZ3: ";cin >> z3;
                    cout << "\tA: ";cin >> a;
                    cout << "\tB: ";cin >> b;
                    cout << "\tC: ";cin >> c;
                    system("cls");

                    cout << "\n\n\tA(" << x << "," << y << "," << z << ") B(" << x2 << "," << y2 << "," << z2 << ") D(" << x3 << "," << y3 << "," << z3 << ") A'(" << a << "," << b << "," << c << ")\n\n";
                    cout << "\tAB= (" << x2 - x << "," << y2 - y << "," << z2 - z << ")  AD= (" << x3 - x << "," << y3 - y << "," << z3 - z << ") AA'(" << a - x << "," << b - y << "," << c - z << ")" << "\n\n";
                    cout << "\t[AB,AD]= " << "[" << ((y3 - y) * (z2 - z)) - ((y2 - y) * (z3 - z)) << "," << ((x3 - x) * (z2 - z)) - ((x2 - x) * (z3 - z)) << "," << ((x3 - x) * (y2 - y)) - ((x2 - x) * (y3 - y)) << "]\n\n";
                    cout << "\t[AB,AD]AA'= " << (((y3 - y) * (z2 - z)) - ((y2 - y) * (z3 - z)) * (a - x)) + (((x3 - x) * (z2 - z)) - ((x2 - x) * (z3 - z)) * (b - y)) + (((x3 - x) * (y2 - y)) - ((x2 - x) * (y3 - y)) * (c - z)) << "\n\n";
                    system("pause");
                }break;
                case 12:{system("cls");
                    cout << "\n\n\tA(X,Y,Z) B(X2,Y2,Z3) C(X3,Y3,Z3) D(X4,Y4,Z4)\n\n";
                    cout << "\tX: ";cin >> x;
                    cout << "\tY: ";cin >> y;
                    cout << "\tZ: ";cin >> z;
                    cout << "\tX2: ";cin >> x2;
                    cout << "\tY2: ";cin >> y2;
                    cout << "\tZ2: ";cin >> z2;
                    cout << "\tX3: ";cin >> x3;
                    cout << "\tY3: ";cin >> y3;
                    cout << "\tZ3: ";cin >> z3;
                    cout << "\tX4: ";cin >> a;
                    cout << "\tY4: ";cin >> b;
                    cout << "\tZ4: ";cin >> c;
                    system("cls");

                    cout << "\n\n\tA(" << x << "," << y << "," << z << ") B(" << x2 << "," << y2 << "," << z2 << ") C(" << x3 << "," << y3 << "," << z3 << ") D(" << a << "," << b << "," << c << ")\n\n";
                    cout << "\tAB= (" << x2 - x << "," << y2 - y << "," << z2 - z << ")  AC= (" << x3 - x << "," << y3 - y << "," << z3 - z << ") AD(" << a - x << "," << b - y << "," << c - z << ")" << "\n";
                    cout << "\t[AB,AC]=[" << ((y2 - y) * (z3 - z) - (y3 - y) * (z2 - z)) << "," << -((x2 - x) * (z3 - z) - (x3 - x) * (z2 - z)) << "," << ((x2 - x) * (y3 - y) - (x3 - x) * (y2 - y)) << "]\n";

                    double tichvohuong = (((y2 - y) * (z3 - z) - (y3 - y) * (z2 - z)) * (a - x)) + (-((x2 - x) * (z3 - z) - (x3 - x) * (z2 - z))) * (b - y) + (((x2 - x) * (y3 - y) - (x3 - x) * (y2 - y))) * (c - z);
                    cout << "\t[AB.AC].AD=" << tichvohuong << "\n";
                    cout << "\tKQ= " << fabs(tichvohuong) / 6.0 << "\n\n";
                    system("pause");
                }break;
                case 13:{system("cls");
                    cout << "\n\tA: ";cin >> a;
                    cout << "\tB: ";cin >> b;
                    cout << "\tC: ";cin >> c;
                    cout << "\tA2: ";cin >> a2;
                    cout << "\tB2: ";cin >> b2;
                    cout << "\tC2: ";cin >> c2;
                    system("cls");

                    cout << "\n\n\tA(" << a << "," << b << "," << c << ")\tB(" << a2 << "," << b2 << "," << c2 << ")\n";
                    cout << "\tKQ= " << sqrt(pow(a2 - a, 2) + pow(b2 - b, 2) + pow(c2 - c, 2)) << "\n\n";
                    system("pause");
                }break;
                case 0:exit(0);
                }
            } while (study != 14);
         }break;
        case 2:{int a, b, n, r;
            do{system("cls");
                cout << "\n\t 1. TÍNH NHANH SỐ N       2. TÍNH HÌNH TRÒN" << endl;
                cout << "\t 3. TÍNH HÌNH VUÔNG        4. TÍNH HÌNH CHỮ NHẬT" << endl;
                cout << "\t 5. TÍNH HÌNH TAM GIÁC     6. C(n,k) | A(n,k)" << endl;
                cout << "\t 7. RETURN                                     " << endl;
                cout << "\t-->: ";cin >> study;
                switch (study){
                case 1:{system("cls");
                    cout << "\n\tN: ";cin >> n;

                    int tong = 0;
                    for (int i = 1; i <= n; i++)tong += i;
                    cout << "\t1+...+" << n << ": " << tong << endl;

                    long long tich = 1;
                    for (int i = 1; i <= n; i++)tich *= i;
                    cout << "\t1*..." << n << ": " << tich << endl;

                    float thuong_n = 1;
                    for (int i = 1; i <= n; i++) thuong_n += (float)1 / i;
                    cout << "\t1 + 1/2 + ...1/" << n << ": " << thuong_n << endl;

                    long double mu_n;
                    for (int i = 1; i <= n; i++) mu_n += pow(i, 2);
                    cout << "\t1^2 +...+ " << n << "^2: " << mu_n << endl;

                    int n_giaithua = 1;
                    for (int i = 1; i <= n; i++)n_giaithua *= i;
                    cout << "\t" << n << "! : " << n_giaithua << endl;

                    int sum = 0;
                    for (int i = 1; i <= n; i++){
                        tich *= i;  sum += tich;
                    }
                    cout << "\t1!+...+" << n << "!= " << sum << endl;

                    // số chính phương
                    cout << "\t SỐ CHÍNH PHƯƠNG: ";
                    for (int i = 1; i <= n; i++){
                        if (sqrt(i) == (int)sqrt(i)) {cout << "\t " << " " << i << " ";}
                    }
                    system("pause");
                }break;
                case 2:{ cout << "\n\tR: ";cin >> r;
                    cout << "\tCHU VI: " << 2 * 3.14 * r << " | DIỆN TÍCH: " << 3.14 * pow(r, 2) << "\n\n";
                    system("pause");
                }break;
                case 3:{ cout << "\n\tA: ";cin >> a;
                    cout << "\tCHU VI: " << 4 * a << " | DIỆN TÍCH: " << pow(a, 2) << " | ĐƯỜNG CHÉO: " << a * sqrt(2) << "\n\n";
                    system("pause");
                }break;
                case 4:{  cout << "\n\tA: ";cin >> a;  cout << "\tB: ";cin >> b;
                    cout << "\tCHU VI: " << 2 * (a + b) << " | DIỆN TÍCH: " << a * b << " | ĐỘ DÀI ĐƯỜNG CHÉO: " << sqrt(pow(a, 2) + pow(b, 2)) << "\n\n";
                    system("pause");
                }break;
                case 5:{ int canha, canhb, canhc;
                    cout << "\n\tA: "; cin >> canha;
                    cout << "\tB: "; cin >> canhb;
                    cout << "\tC: ";cin >> canhc;
                    cout << "\tCHU VI: " << canha + canhb + canhc << "\n\n";
                    system("pause");
                }break;
                case 6:{long long n, k, n_k = 1, n_gt = 1, k_gt = 1, n_giaithua = 1, nk_giaithua = 1;

                    cout << "\n\n\tN: ";cin >> n;
                    cout << "\tK: ";cin >> k;
                    for (int i = 1; i <= n; i++) n_gt *= i;
                    for (int i = 1; i <= k; i++) k_gt *= i;
                    for (int i = 1; i <= (n - k); i++)    n_k *= i;
                    long long a = n_gt / (k_gt * n_k);
                    cout << "\tC(n,k): " << a << endl;

                    for (int i = 1; i <= n; i++)   n_giaithua *= i;
                    for (int i = 1; i <= (n - k); i++)   nk_giaithua *= i;
                    long long c = n_giaithua / nk_giaithua;
                    cout << "\tA(n,k): " << c << endl;
                    system("pause");
                }break;
                case 0:exit(0);
                }
            } while (study != 7);
        }break;
        case 3:{
            do{system("cls");
                cout << "\n\n\t==========TOAN ROI RAC==========\n";
                cout << "\t1.HOAN VI LAP      2.MENH DE\n";
                cout << "\t==========TOAN MA TRAN==========\n";
                cout << "\t3.CONG MA TRAN      4.NHAN MA TRAN\n";
                cout << "\t================================\n";
                cout << "\t5.RETURN\n";
                cout << "\t--> ";cin >> study;
                switch (study){
                case 1:{string chuoi;system("cls");
                    cout << "\n\n\tnhap chuoi: ";cin >> chuoi;
                    unsigned long long sohoanvi = demSoHoanVi(chuoi);
                    cout << "\n\tSo hoan vi cua chuoi: " << sohoanvi << endl;
                    system("pause");
                }break;
                case 2:{system("cls");
                    cout << "\n\nso dong: ";cin >> study;

                    int q[study], p[study], phep_hoi[study], phep_tuyen[study],  phep_keo[study], phep_tuongduong[study], phu_dinh[study];

                    for (int i = 1; i <= study; i++){
                        cout << "\tP[" << i << "]: ";cin >> p[i];
                        cout << "\tQ[" << i << "]: ";cin >> q[i];
                    }

                    for (int i = 1; i <= study; i++){
                        phu_dinh[i] = !p[i];
                        phep_hoi[i] = p[i] && q[i];
                        phep_tuyen[i] = p[i] || q[i];
                        phep_keo[i] = !p[i] || q[i];
                        phep_tuongduong[i] = p == q;
                    }
                    system("cls");
                    cout << "\n\n\tP Q|Phu dinh|Phep hoi|Phep tuyen|Phep keo|Phep tuong duong|\n";
                    for (int i = 1; i <= study; i++){
                        cout << "\t" << p[i] << " " << q[i] << "|     " << phu_dinh[i] << "       " << phep_hoi[i] << "         " << phep_tuyen[i] << "          " << phep_keo[i] << "           " << phep_tuongduong[i] << endl;
                    }
                    system("pause");
                }break;
                case 3:{system("cls");
                    int a[100][100],b[100][100],n;
                    cout<<"\n\n\tNhap so cot: ";cin>>n; 
                    
                    cout<<"\n\tMa tran A\n";
                    for(int i=0;i<n;++i){
                        for(int j=0;j<n;++j){
                            cout<<"\tA["<<i+1<<"]["<<j+1<<"]= ";cin>>a[i][j];
                        }
                    }
                    cout<<"\n\tMa tran B\n";
                    for(int i=0;i<n;++i){
                        for(int j=0;j<n;++j){
                            cout<<"\tB["<<i+1<<"]["<<j+1<<"]= ";cin>>b[i][j];
                        }
                    }
                    system("cls");cout<<"\n\n\tKQ\n";
                    for(int i=0;i<n;++i){
                        for(int j=0;j<n;++j){
                           cout<<a[i][i]+b[i][j]<<" ";
                        } cout<<"\n";
                    }
                    system("pause");
                }break;
                case 0:exit(0);break;
                }
            } while (study != 5);
        }break;
        case 0: exit(0);break;
        }
    } while (study != 4);
}

int main(){
    hoc_tap();
    return 0;
}