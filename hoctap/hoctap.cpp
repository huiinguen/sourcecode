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

void nhapso(int n,int array[100]){
    for(int i=0;i<n;i++){
        cout<<"GIÁ TRỊ THỨ["<<i+1<<"]: ";cin>>array[i];
    }
}

void math_thpt(int study){int n,array[100];
    double pi = 3.14159,r, l, z, y, h;
        switch (study){
        case 1:{nhapso(3,array);
            system("cls");
            cout << "\n\n\tF(X)= 0 <=> f(x)=" << array[0] << "X^2" << " + " << array[1] << "X + " << array[2] << " = 0\n";
            cout << "\tF'(X)= 0 <=> F'(X)= " << array[0] * 2 << "X" << " + " << array[1] << "\n\n";

            double delta = pow(array[1], 2) - (4 * array[0] * array[2]);

            if (delta > 0){
                cout << "\tX1= " << (-array[1] + sqrt(delta)) / (2 * array[0])<<"\n";
                cout << "\tX2= " << (-array[1] - sqrt(delta)) / (2 * array[0])<<"\n";
            }else{
                if (delta == 0)  cout << "\tNO KEP ==> X= " << -array[1] / (2 * array[0]);
                else             cout << "\tVO NGHIEM";
            }
            system("pause");
        }break;
        case 2:{nhapso(4,array);
            system("cls");

            cout << "\n\n\tf(x)= " << array[0] << "X^3 + " << array[1] << "X^2 + " << array[2] << "X" << " + " << array[3] << " = 0" << "\n\n";
            cout << "\tF'(X)= 0 <=> F'(X)= " << 3 * array[0] << "X^2" << " + " << 2 * array[1] << "x" << " + " << array[2] << " = 0 \n\n";

            float delta = pow(2 * array[1], 2) - 4 * 3 * array[0] * array[2];

            if (delta > 0){
                // công thức x1,x2
                float x1_bac3 = (-2 * array[1] + sqrt(delta)) / (6 * array[0]), x2_bac3 = (-2 * array[1] - sqrt(delta)) / (6 * array[0]);
                float x1_bac3_thanh_y1 = (array[0] * pow(x1_bac3, 3)) + (array[1] * pow(x1_bac3, 2)) + (array[2] * x1_bac3) + array[3], x2_bac3_thanh_y2 = (array[0] * pow(x2_bac3, 3)) + (array[1] * pow(x2_bac3, 2)) + (array[2] * x2_bac3) + array[3];
                // 3*a*2*pow(x1_bac3,1) là đạo hàm y'' của y để tính điều kiện cho chuẩn

                cout << "\t\tX1: " << x1_bac3 << " ==> Y: " << x1_bac3_thanh_y1 << " ==> ";
                if (3 * array[0] * 2 * pow(x1_bac3, 1) > 0)   cout << "Yct";
                else                                   cout << "Ycd"; // Dùng f'' kiểm tra

                cout << "\n\n\t\tX2: " << x2_bac3 << " ==> Y: " << x2_bac3_thanh_y2 << " ==> ";
                if (3 * array[0] * 2 * pow(x2_bac3, 1) > 0)  cout << "Yct";
                else                                  cout << "Ycd"; // f'' = 6ax
            }

            if (delta == 0){
                float no_kep = -2 * array[1] / (6 * array[0]);
                cout << "\tNGHIEM KEP: " << no_kep << endl;
            }

            if (delta < 0)  cout << "\t vo nghiem\n\n";
            system("pause");
        }break;
        case 3:{nhapso(3,array);
            system("cls");cout << "\n\n";

            if (array[0] == 0){
                cout << "Đây không phải hàm bậc 4!" << endl;   break;
            }

            float check = -array[1] / (2 * array[0]); // để kiểm tra nghiệm thực
            if (check < 0){ 
                cout << "\tF(x) = " << array[0] << "x^4 + " << array[1] << "x^2 + " << array[2] << endl;
                cout << "\tF'(x) = " << 4 * array[0] << "x^3 + " << 2 * array[1] << "x" << "\n\n";
                cout << "\tX0 = 0 => Y: " << array[2] << " ";
                float dao_ham_lan2 = 2 * array[1];
                if (dao_ham_lan2 > 0)       cout << "\t CỰC TIỂU";
                else if (dao_ham_lan2 < 0)  cout << "\t CỰC ĐẠI";
                else                        cout << "\t loading...";
            }else{
                // đạo hàm có 3 nghiệm
                float x1_bac4 = sqrt(check), x2_bac4 = sqrt(check);
                float y0 = array[2];
                float y1_bac4 = array[0] * pow(x1_bac4, 4) + array[1] * pow(x1_bac4, 2) + array[2];
                float y2_bac4 = y1_bac4;

                // đạo hàm bậc 2 tại các điểm
                float fx_lan2 = 2 * array[1];
                float daohamlan2_fx1 = 12 * array[0] * pow(x1_bac4, 2) + 2 * array[1];
                float daohamlan2_fx2 = daohamlan2_fx1;
                cout << "\tF(x) = " << array[0] << "x^4 + " << array[1] << "x^2 + " << array[2] << endl;
                cout << "\tF'(x) = " << 4 * array[0] << "x^3 + " << 2 * array[1] << "x" << "\n\n";

                // tinnh x0
                cout << "\tX0= 0 <=> y: " << y0 << " ";
                if (fx_lan2 > 0)         cout << "\t CỰC TIỂU";
                else if (fx_lan2 < 0)    cout << "\t CỰC ĐẠI";
                else                     cout << "\t loading... ";
                cout << "\n";

                // tinh x1
                cout << "\tX1= " << x1_bac4 << " ==y: " << y1_bac4 << " ";
                if (daohamlan2_fx1 > 0)        cout << "\t CỰC TIỂU";
                else if (daohamlan2_fx1 < 0)   cout << "\t CỰC ĐẠI";
                else                           cout << "\t loading...";
                cout << "\n";

                // tinh x2
                cout << "\tX2= " << x2_bac4 << " ==y: " << y2_bac4 << " ";
                if (daohamlan2_fx2 > 0)      cout << "\t CỰC TIỂU";
                else if (daohamlan2_fx2 < 0) cout << "\t CỰC ĐẠI";
                else                         cout << "\t loading...";
                cout << "\n";
            } system("pause");
        }break;
        case 4:{nhapso(6,array);
            if(array[0]==0) cout<<"\t MỜI NHẬP LẠI A[0]:";cin>>array[0];            
            system("cls");

            cout << "\n\t      {" << array[0] << "x + " << array[1] << "y = " << array[2] << " (1)\n";
            cout << "\tPT <=>{\n";
            cout << "\t      {" << array[3] << "x + " << array[4] << "y = " << array[5] << " (2)\n\n\n";

            if (array[0] * array[4] == array[3] * array[1])    cout << "\tPT VO NGHIEM HOAC VO SO NGHIEM\n";

            float D = array[0] * array[4] - array[1] * array[3];
            float Dx = array[2] * array[4] - array[1] * array[5];
            float Dy = array[0] * array[5] - array[2] * array[3];
            float x = Dx / D;
            float y = Dy / D;

            cout << "\tX= " << x << "\tY= " << y << endl;
            system("pause");
        }break;
        case 5:{nhapso(9,array);
            system("cls");
            cout << "\n\n\t{" << array[0] << "x + " << array[1] << "y = " << array[2] << endl;
            cout << "\t{" << array[3] << "x + " << array[4] << "y = " << array[5] << endl;
            cout << "\t{" << array[6] << "x + " << array[7] << "y = " << array[8] << endl;
            cout << "\n\n";

            int del_d = array[0] * array[4] - array[3] * array[1], del_dx = array[2] * array[4] - array[5] * array[1], del_dy = array[0] * array[5] - array[3] * array[2];
            float x = (float)del_dx / del_d, y = (float)del_dy / del_d;

            cout << "\tX= " << x << "\tY= " << y << endl;

            int thaynghiem = array[6] * x + array[7] * y;
            cout << "\tCHECK: ";
            if (thaynghiem == array[8]){   cout << "✅\n"; }
            else{                    cout << "✖️\n";  }
            system("pause");
        }break;
        case 6:{}break;
        case 7:{
            nhapso(12, array); 
            system("cls");

            cout << "\n\n\tHỆ PHƯƠNG TRÌNH 3 ẨN (3PT):\n";
            cout << "\t{ " << array[0] << "x + " << array[1] << "y + " << array[2] << "z = " << array[3] << endl;
            cout << "\t{ " << array[4] << "x + " << array[5] << "y + " << array[6] << "z = " << array[7] << endl;
            cout << "\t{ " << array[8] << "x + " << array[9] << "y + " << array[10] << "z = " << array[11] << endl;

            // Tính các định thức (quy tắc Cramer)
            float D = array[0] * (array[5] * array[10] - array[6] * array[9]) - array[1] * (array[4] * array[10] - array[6] * array[8]) + array[2] * (array[4] * array[9] - array[5] * array[8]);

            if (D == 0){
                cout << "\n\t⚠️  Hệ phương trình vô nghiệm hoặc vô số nghiệm (D = 0)\n";
                system("pause");
                break;
            }

            float Dx = array[3] * (array[5] * array[10] - array[6] * array[9]) - array[1] * (array[7] * array[10] - array[6] * array[11]) + array[2] * (array[7] * array[9] - array[5] * array[11]);
            float Dy = array[0] * (array[7] * array[10] - array[6] * array[11]) - array[3] * (array[4] * array[10] - array[6] * array[8]) + array[2] * (array[4] * array[11] - array[7] * array[8]);
            float Dz = array[0] * (array[5] * array[11] - array[7] * array[9]) - array[1] * (array[4] * array[11] - array[7] * array[8]) + array[3] * (array[4] * array[9] - array[5] * array[8]);

            // Tính nghiệm
            float x = Dx / D;
            float y = Dy / D;
            float z = Dz / D;

            cout << "\n\tKẾT QUẢ:\n";
            cout << "\tD  = " << D << endl;
            cout << "\tDx = " << Dx << endl;
            cout << "\tDy = " << Dy << endl;
            cout << "\tDz = " << Dz << endl;
            cout << "\n\tx = " << x << "\n\t   y = " << y << "\n\t   z = " << z << "\n\n";
            system("pause");
        }break;
        case 8:{system("cls");
            cout << "\n\t QUY ƯỚC '' LÀ VECTO\n\n";
            cout << "\t1.AB\t2.COS('A','B')\t3.|'A'|\n\n";
            nhapso(3,array);

            cout << "\n\n\tA(" << array[0] << "," << array[1] << ")\tB(" << array[2] << "," << array[3] << ")\n";
            cout << "\tAB: " << sqrt(pow(array[2] - array[0], 2) + pow(array[3] - array[1], 2)) << "\n\n";
            cout << "\tA(" << array[0] << "," << array[1] << ")\tB(" << array[2] << "," << array[3] << ")\n";

            float cosAB = (array[0]*array[2] + array[1]*array[3]) /(sqrt(pow(array[0],2)+pow(array[1],2)) * sqrt(pow(array[2],2)+pow(array[3],2)));
            cout << "\tCOS('A','B')= " << cosAB<<"\n";
            cout << "\t|'A'|= (" << array[0] << "," << array[2] << ")" << endl;
            cout << "\tKQ= " << sqrt(pow(array[0], 2) + pow(array[2], 2)) << "\n\n";
            system("pause");
        }break;
        case 9:{system("cls");
            cout << "\n\tH: ";cin >> h;
            cout << "\tR: ";cin >> r;
            cout << "\tL: ";cin >> l;
            system("cls");
            cout << "\n\n\t HÌNH NÓN\n";
            cout << "\t S XUNG QUANH: " << pi * r * l << endl;
            cout << "\t S ĐÁY: " << pi * pow(r, 2) << endl;
            cout << "\t DIỆN TÍCH TOÀN PHẦN: " << (pi * r * l) + (pi * pow(r, 2)) << endl;
            cout << "\t V TOAN DIEN :" << (1.0 / 3.0) * pi * pow(r, 2) * h << "\n\n";

            cout << "\t HÌNH TRỤ\n";
            cout << "\t S XUNG QUANH: " << 2 * pi * r * h << endl;
            cout << "\t S ĐÁY: " << 2 * pi * pow(r, 2) << endl;
            cout << "\t S TOÀN PHẦN: " << (2 * pi * r * h) + (2 * pi * pow(r, 2)) << endl;
            cout << "\t V TOAN PHAN: " << pi * pow(r, 2) * h << "\n\n";

            cout << "\t HÌNH CẦU\n";
            cout << "\t S HÌNH CẦU: " << 4 * pi * pow(r, 2) << endl;
            cout << "\t V HÌNH CẦU: " << double(4.0 / 3.0) * pi * pow(r, 3) << "\n\n";
            system("pause");
        }break;
        }
}

void calc_speech(int study){double a, b, n, r;
        switch (study){
        case 10:{system("cls");
            cout << "\n\tN: ";cin >> n;

            int tong = 0;
            for (int i = 1; i <= n; i++)tong += i;
            cout << "\t1+...+" << n << ": " << tong << endl;

            long long tich = 1;
            for (int i = 1; i <= n; i++)tich *= i;
            cout << "\t1*...*" << n << ": " << tich << endl;

            double thuong_n = 1;
            for (int i = 1; i <= n; i++) thuong_n += (float)1 / i;
            cout << "\t1 + 1/2 + ...+1/" << n << ": " << thuong_n << endl;

            long double mu_n;
            for (int i = 1; i <= n; i++) mu_n += pow(i, 2);
            cout << "\t1^2 +...+ " << n << "^2: " << mu_n << endl;

            int n_giaithua = 1;
            for (int i = 1; i <= n; i++) n_giaithua *= i;
            cout << "\t" << n << "! : " << n_giaithua << endl;

            int sum = 0;
            for (int i = 1; i <= n; i++){
                tich *= i;  sum += tich;
            }
            cout << "\t1!+...+" << n << "!= " << sum << endl;

            // số chính phương
            cout << "\tSỐ CHÍNH PHƯƠNG: ";
            for (int i = 1; i <= n; i++){
                if (sqrt(i) == (int)sqrt(i)){
                    cout << i << " ";
                }
            }
            cout << "\n";system("pause");
        }break;
        case 11:{
            cout << "\n\tR(BAN KINH): ";cin >> r;
            cout << "\tCHU VI: " << 2 * 3.14 * r << " | S: " << 3.14 * pow(r, 2) << "\n\n";  system("pause");
        }break;
        case 12:{
            cout << "\n\tA(CANH): ";cin >> a;
            cout << "\tCHU VI: " << 4 * a << " | S: " << pow(a, 2) << " | ĐƯỜNG CHÉO: " << a * sqrt(2) << "\n\n"; system("pause");
        }break;
        case 13:{
            cout << "\n\tA: ";cin >> a;
            cout << "\tB: ";cin >> b;
            cout << "\tCHU VI: " << 2 * (a + b) << " | S: " << a * b << " | ĐỘ DÀI ĐƯỜNG CHÉO: " << sqrt(pow(a, 2) + pow(b, 2)) << "\n\n";system("pause");
        }break;
        case 14:{
            double p, s, canha, canhb, canhc;
            cout << "\n\tCANH A: ";cin >> canha;
            cout << "\tCANH B: ";cin >> canhb;
            cout << "\tCANH C: ";cin >> canhc;

            p = (canha + canhb + canhc) / 2;
            s = sqrt(p * (p - canha) * (p - canhb * (p - canhc)));

            cout << "\tCHU VI: " << canha + canhb + canhc << "\n\n";
            cout << "\tNUA CHU VI: " << p << "\n";
            cout << "\tDIEN TICH: " << s << "\n";  system("pause");
        }break;
        case 15:{long long n, k, n_k = 1, n_gt = 1, k_gt = 1, n_giaithua = 1, nk_giaithua = 1;
            cout << "\n\n\tN: ";cin >> n;
            cout << "\tK: "; cin >> k;
            for (int i = 1; i <= n; i++)  n_gt *= i;
            for (int i = 1; i <= k; i++) k_gt *= i;
            for (int i = 1; i <= (n - k); i++) n_k *= i;
            long long a = n_gt / (k_gt * n_k);
            cout << "\tC(n,k): " << a << endl;

            for (int i = 1; i <= n; i++) n_giaithua *= i;
            for (int i = 1; i <= (n - k); i++) nk_giaithua *= i;
            long long c = n_giaithua / nk_giaithua;
            cout << "\tA(n,k): " << c << endl;  system("pause");
        }break;
        }
}

void math_uni(int study){
    switch (study){
    case 16:{string chuoi;
        system("cls");
        cout << "\n\n\tnhap chuoi: ";cin >> chuoi;
        unsigned long long sohoanvi = demSoHoanVi(chuoi);
        cout << "\n\tSo hoan vi cua chuoi: " << sohoanvi << endl;
        system("pause");
    }break;
    case 17:{system("cls");
        cout << "\n\nso dong: ";cin >> study;

        int q[study], p[study], phep_hoi[study], phep_tuyen[study], phep_keo[study], phep_tuongduong[study], phu_dinh[study];

        for (int i = 1; i <= study; i++){
            cout << "\tP[" << i << "]: ";cin >> p[i];
            cout << "\tQ[" << i << "]: ";cin >> q[i];
        }

        for (int i = 1; i <= study; i++){
            phu_dinh[i] = !p[i];
            phep_hoi[i] = p[i] && q[i];
            phep_tuyen[i] = p[i] || q[i];
            phep_keo[i] = !p[i] || q[i];
            phep_tuongduong[i] = (p[i] == q[i]);
        }

        system("cls");
        cout << "\n\n\tP Q|Phu dinh|Phep hoi|Phep tuyen|Phep keo|Phep tuong duong|\n";
        for (int i = 1; i <= study; i++)
        {
            cout << "\t" << p[i] << " " << q[i] << "|     " << phu_dinh[i] << "       " << phep_hoi[i] << "         " << phep_tuyen[i] << "          " << phep_keo[i] << "           " << phep_tuongduong[i] << endl;
        }
        system("pause");
    }break;
    case 18:{system("cls");
        int a[100][100], b[100][100], n;
        cout << "\n\n\tNhap so cot: ";cin >> n;

        cout << "\n\tMa tran A\n";
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                cout << "\tA[" << i + 1 << "][" << j + 1 << "]= ";cin >> a[i][j];
            }
        }
        cout << "\n\tMa tran B\n";
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                cout << "\tB[" << i + 1 << "][" << j + 1 << "]= ";cin >> b[i][j];
            }
        }
        system("cls");cout << "\n\n\tKQ\n";
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                cout << a[i][j] + b[i][j] << " ";
            }
            cout << "\n";
        }system("pause");
    }break;
    case 19:{system("cls");
        int n, k, n_gt = 1, k_gt = 1, n_k = 1;
        float xac_suat;
        cout << "\n\n\tNOTE: ĐỔI XÁC SUẤT '%' SANG THẬP PHÂN VD: 50% = 0.5\n\n";
        cout << "\tN: ";cin >> n;
        cout << "\tK: ";cin >> k;
        cout << "\tXAC SUAT: ";cin >> xac_suat;
        for (int i = 1; i <= n; i++)n_gt *= i;
        for (int i = 1; i <= k; i++)k_gt *= i;
        for (int i = 1; i <= (n - k); i++)n_k *= i;
        long long a = n_gt / (k_gt * n_k);
        cout << "\tKQ: " << a * pow(xac_suat, k) * pow(1 - xac_suat, n - k);
        system("pause");
    }break;
    }
}

void menu(){ int choice;
    do{system("cls");cout<<"\n";
    cout << "\t╭────────────────────────────────────────────────────────────╮\n";
    cout << "\t│                        GIẢI PT                             │\n";
    cout << "\t│ 1. AX^2 + BX + C  (BẬC 2)          6. HỆ PT 3 ẨN (2PT)     │\n";
    cout << "\t│ 2. AX^3 + BX^2 + CX + D (BẬC 3)    7. HỆ PT 3 ẨN (3PT)     │\n";
    cout << "\t│ 3. AX^4 + BX^2 + C (BẬC 4)         8. TÍCH VÔ HƯỚNG 2 VECTO│\n";
    cout << "\t│ 4. HỆ PT 2 ẨN(2PT)                 9. HÌNH NÓN-TRỤ-CẦU     │\n";
    cout << "\t│ 5. HỆ PT 2 ẨN(3PT)                                         │\n";
    cout << "\t├────────────────────────────────────────────────────────────┤\n";
    cout << "\t│                       TÍNH NHANH                           │\n";
    cout << "\t│ 10. TÍNH NHANH SỐ N       11. TÍNH HÌNH TRÒN               │\n";
    cout << "\t│ 12. TÍNH HÌNH VUÔNG       13. TÍNH HÌNH CHỮ NHẬT           │\n";
    cout << "\t│ 14. TÍNH HÌNH TAM GIÁC    15. C(n,k) & A(n,k)              │\n";
    cout << "\t├────────────────────────────────────────────────────────────┤\n";
    cout << "\t│                     TOÁN RỜI RẠC                           │\n";
    cout << "\t│ 16.HOAN VI LAP            17.MENH DE                       │\n";
    cout << "\t│ 18.CONG MA TRAN           19.NHAN MA TRAN(coming soon)     │\n";
    cout << "\t╰────────────────────────────────────────────────────────────╯\n\n";
    cout << "\t╭────────────────────────────────────────────────────────────╮\n";
    cout << "\t│   0.EXIT                                                   │\n";
    cout << "\t╰────────────────────────────────────────────────────────────╯\n";
    cout << "\t--> ";cin>>choice;
    if(choice>=1 && choice<=9) math_thpt(choice);
    if(choice>=10 && choice<=15) calc_speech(choice);
    if(choice>=16 && choice<=19) math_uni(choice);
    }while(choice!=0);

}

int main(){
    menu();
    return 0;
}