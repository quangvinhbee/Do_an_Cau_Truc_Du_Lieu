#include "KhaiBao.h"

#include <iostream>

using namespace std;
int Convert_String_to_Int(string s) {
    int number = 0;
    for (auto ch: s) {
        number = (number * 10) + (ch - '0');
    }
    return number;
}
char * Convert_String_to_Char(string s, char str[]) {
    int k = sizeof(str);
    char str1[k];
    for (int i = 0; i < k; i++) {
        str1[i] = s[i];
    }
    return str1;
}
Date * GetDate_String(string str);
int Check_date_7(Date * date);
void Write_Tree_File(NodeDG & p, fstream & write) {
    if (p != NULL) {
        write << p -> docgia.Mathe << "," << p -> docgia.Ho << "," << p -> docgia.Ten << "," << p -> docgia.phai << "," << p -> docgia.trangthai << endl;
        write << p -> docgia.dsmt.Tong << endl;
        if (p -> docgia.dsmt.First != NULL && p -> docgia.dsmt.Tong > 0) {
            for (NodeMuonTra * pl = p -> docgia.dsmt.First; pl != NULL; pl = pl -> next) {
                //string ngaymuon=pl->muontra.Ngaymuon->ngay<<"/"+pl->muontra.Ngaymuon->thang<<"/"+pl->muontra.Ngaymuon->nam;
                //string ngaytra=NULL;
                if (pl -> muontra.Ngaytra != NULL) {
                    write << pl -> muontra.MASACH << "," << pl -> muontra.Ngaymuon -> ngay << "/" << pl -> muontra.Ngaymuon -> thang << "/" << pl -> muontra.Ngaymuon -> nam << "," << pl -> muontra.Ngaytra -> ngay << "/" << pl -> muontra.Ngaytra -> thang << "/" << pl -> muontra.Ngaytra -> nam << "," << pl -> muontra.trangthai << endl;
                } else {
                    write << pl -> muontra.MASACH << "," << pl -> muontra.Ngaymuon -> ngay << "/" << pl -> muontra.Ngaymuon -> thang << "/" << pl -> muontra.Ngaymuon -> nam << ",NULL," << pl -> muontra.trangthai << endl;
                }
            }
        }
        Write_Tree_File(p -> left, write);
        Write_Tree_File(p -> right, write);
    }
}
void Save_Tree_File(NodeDG & p) {
    fstream write;
    write.open("DSDG.txt", ios::out | ios::trunc);
    Write_Tree_File(p, write);
    write.close();
}
void Read_Tree_File(NodeDG & p) {
    DocGia dg;
    if(p!=NULL){
    	DeleteMemoryDocGia(p);
	}
	p=NULL;
    dg.dsmt = DS_MuonTra();
    MuonTra mt;
    fstream read;
    string data;
    int k = 0;
    read.open("DSDG.txt", ios:: in );
    while (!read.eof()) {
        //read.ignore();
        //ma the
        dg.dsmt = DS_MuonTra();
        getline(read, data, ',');
        dg.Mathe = Convert_String_to_Int(data);
        //ho
        getline(read, data, ',');
        strcpy(dg.Ho, data.c_str());
        //ten
        getline(read, data, ',');
        strcpy(dg.Ten, data.c_str());
        //gioi tinh
        getline(read, data, ',');
        dg.phai = Convert_String_to_Int(data);
        //trang thai
        getline(read, data);
        dg.trangthai = Convert_String_to_Int(data);
        //tong luong sach da muon
        getline(read, data);
        k = Convert_String_to_Int(data);
        //read>>data;
        //read.ignore();
        if (!(dg.Mathe == 0)) {
            while (!read.eof() && k > 0) {
                k--;
                //ma sach
                getline(read, data, ',');
                strcpy(mt.MASACH, data.c_str());
                //ngay muon
                getline(read, data, ',');
                mt.Ngaymuon = GetDate_String(data);

                //ngay tra
                getline(read, data, ',');
                if (data != "NULL") {
                    mt.Ngaytra = GetDate_String(data);
                } else {
                    mt.Ngaytra = NULL;
                }
                //trang thai
                getline(read, data);
                mt.trangthai = Convert_String_to_Int(data);
                if (Check_date_7(mt.Ngaymuon) == 0 && mt.trangthai == 0) {
                    dg.trangthai = 0;
                }
                Insert_Last_DSMT(dg.dsmt, mt);
            }
            Insert_DG(p, dg);
        }
    }
    read.close();
}
void Write_DS_DauSach_File(DS_DauSach & dsds, fstream & write) {
    if (dsds.n <= 0) {
        printf("DANH SACH DAU SACH RONG!");
    } else {
        //write<<dsds.n<<endl;
        for (int i = 0; i < dsds.n; i++) {
            write << dsds.node[i] -> ISBN << "," << dsds.node[i] -> Tensach << "," << dsds.node[i] -> Tacgia << "," << dsds.node[i] -> Theloai << "," << dsds.node[i] -> Sotrang << "," << dsds.node[i] -> Nxb << "," << dsds.node[i] -> Tongsoluongsach << "," << dsds.node[i] -> Soluongmuon << endl;
            if (dsds.node[i] -> pNext != NULL && dsds.node[i] -> Tongsoluongsach > 0) {
                for (NodeSach * p = dsds.node[i] -> pNext; p != NULL; p = p -> pNext) {
                    write << p -> sach.Masach << "," << p -> sach.Vitri << "," << p -> sach.Trangthai << endl;
                }
            }
        }
    }
    write.close();
}
void Save_DS_DauSach_File(DS_DauSach & dsds) {
    fstream write;
    write.open("DSDS.txt", ios::out | ios::trunc);
    Write_DS_DauSach_File(dsds, write);
    write.close();

}
void Read_DS_DauSach_File(DS_DauSach & dsds) {
    fstream read;
    string data;
    DauSach ds;
    Sach sach;
    if(dsds.n!=0){
    	DeleteAllDauSach(dsds);
	}
    dsds.n = 0;
    int k = 0;
    read.open("DSDS.txt", ios:: in );

    //n
    //	if(!read.eof()){
    //		getline(read,data);
    //		dsds.n = Convert_String_to_Int(data);
    //		cout<<dsds.n;
    //	}
    while (!read.eof()) {
        //ISBN
        ds = DauSach();
        ds.pNext = NULL;
        getline(read, data, ',');
        strcpy(ds.ISBN, data.c_str());
        //Ten sach
        getline(read, data, ',');
        strcpy(ds.Tensach, data.c_str());
        //Tac Gia
        getline(read, data, ',');
        strcpy(ds.Tacgia, data.c_str());

        //The loai
        getline(read, data, ',');
        strcpy(ds.Theloai, data.c_str());

        //So trang
        getline(read, data, ',');
        ds.Sotrang = Convert_String_to_Int(data);

        //Nam xb
        getline(read, data, ',');
        ds.Nxb = Convert_String_to_Int(data);
        //tong so luong sach
        getline(read, data, ',');
        ds.Tongsoluongsach = Convert_String_to_Int(data);
        getline(read, data);
        ds.Soluongmuon = Convert_String_to_Int(data);
        if (strcmp(ds.ISBN, "") != 0) {
            //day la noi xay ra cai ngu vcl
            k = ds.Tongsoluongsach;
            while (!read.eof() && k > 0) {
                k--;
                sach = Sach();
                //ma sach
                getline(read, data, ',');
                strcpy(sach.Masach, data.c_str());
                //vi tri
                getline(read, data, ',');
                strcpy(sach.Vitri, data.c_str());
                //trang thai
                getline(read, data);
                sach.Trangthai = Convert_String_to_Int(data);
                Insert_Sach_Last(ds.pNext, sach);
            }
            Add_DauSach(dsds, ds);
        }
    }
    read.close();
}
