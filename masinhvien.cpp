#include<bits/stdc++.h>

using namespace std;
int n;
struct sinhvien{
    string name;
    string home;
    int yearofbirth;
    float mathes1;
    float phygical1;
    float chemistry1;
    float gpa;
    void getinfo(){
        cin>>name>>home>>yearofbirth>>mathes1>>phygical1>>chemistry1;
    }
    
    
    void display(){
        cout<<name<<" "<<home<<" "<<yearofbirth<<" "<<mathes1<<" "<<phygical1<<" "<<chemistry1<<" ";
        gpa=(mathes1+phygical1+chemistry1)/3;
        cout<<fixed<<setprecision(2)<<gpa<<endl;
    }
};
sinhvien a[10000];
void find(){
    string tenCanTim;
    cout << "nhap ten sinh vien can tim: ";
    cin.ignore();
    getline(cin, tenCanTim);

    bool timThay = false;
    for (int i = 0; i < n; ++i) {
        if (a[i].name == tenCanTim) {
            cout << "thong tin sinh vien can tim:" << endl;
            a[i].display();
            timThay = true;
            break;
        }
    }
    if (!timThay) {
        cout << "khong tim thay sinh vien: " << tenCanTim << endl;
    }
    cout<<"----------------------------------------------------------------"<<endl;

}
void sapxepmang(){
     for (int i = 0; i < n - 1; ++i) 
        for (int j = i + 1; j < n; ++j) 
            if (a[i].name > a[j].name) swap(a[i],a[j]);
}
int yeu=0,tb=0,kha=0,gioi=0;
void xeploaisinhvien(){
    
    for (int i=0;i<n;i++)
        if(a[i].gpa<5.5) yeu++;
        else
        if (a[i].gpa>=5.5&&a[i].gpa<6.5) tb++;
        else
        if(a[i].gpa>=6.5&&a[i].gpa<7.9) kha++;
        else
        if(a[i].gpa>=8) gioi++;
}
int main(){
    //int n;
    cin>>n;
    
    for(int i=0;i<n;i++)
        a[i].getinfo();
    sapxepmang();
    xeploaisinhvien();
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"hay chon thao tac ban muon: "<<endl;
    cout<<"1.tim kiem sinh vien theo ten."<<endl;
    cout<<"2.in ra danh sach sinh vien."<<endl;
    cout<<"3.in ra so sinh vien dat loai gioi."<<endl;
    cout<<"4.in ra so sinh vien dat loai kha."<<endl;
    cout<<"5.in ra so sinh vien dat loai trung binh."<<endl;
    cout<<"6.in ra so sinh vien dat loai yeu."<<endl;
    cout<<"7.thoat:"<<endl;
    int chon;
    while (chon!=7){
        cin>>chon;
        switch (chon){
            case 1:
                find();
                break;
            case 2:
                for (int i=0;i<n;i++)
                    a[i].display();
                break;
            case 3:
                cout<<"so sinh vien dat loai gioi la: "<<gioi<<endl;
                break;
            case 4:
                cout<<"so sinh vien dat loai kha la: "<<kha<<endl;
                break;
            case 5:
                cout<<"so sinh vien dat loai trung binh la: "<<tb<<endl;
                break;
            case 6:
                cout<<"so sinh vien dat loai yeu la: "<<yeu<<endl;
                break;
            case 7:
                return 0;
                break;
            default:
            cout<<"yeu cau chon lai:"<<endl;
                break;
        }
        

    }
    return 0;
}