const int MAX_SIZE_DS = 500;
const int MAX_SIZE_DMS_ISBN = 500;
char * Get_ISBN_from_MaSach(char masach[]);
//
//==========================================DANH SACH LIEN KET DON===================================

struct Sach {
    char Masach[10];
    int Trangthai;
    //	0: cho muon duoc
    //	1: da cho muon
    //	2: da thanh ly
    char Vitri[20];
    Sach() {
        strcpy(Masach, "");
        strcpy(Vitri, "");
        Trangthai = 0;
    }
    Sach(char * masach, char * vitri, int trangthai) {
        strcpy(Masach, masach);
        strcpy(Vitri, vitri);
        Trangthai = trangthai;
    }
};
struct NodeSach {
    Sach sach;
    NodeSach * pNext;
};
struct DS_DMS {
    NodeSach * First; // node quan li dau ds
    //NodeSach * Last; // node quan li cuoi ds
};

void Init_NodeSach(NodeSach * & First) {
    First = NULL;
}

void Insert_Sach_First(NodeSach * & First, Sach & sach) {
    NodeSach * node = new NodeSach;
    node -> sach = sach;
    node -> pNext = First;
    First = node;
}
void Insert_Sach_After(NodeSach * & node, Sach & sach) {

    if (node == NULL) {
        printf("VI TRI THEM SACH KHONG PHU HOP!");
        return;
    }

    NodeSach * nodeNew = new NodeSach;
    nodeNew -> sach = sach;
    nodeNew -> pNext = node -> pNext;
    node -> pNext = nodeNew;

}
void Insert_Sach_Last(NodeSach * & First, Sach & sach) {
    if (First == NULL) {
        Insert_Sach_First(First, sach);
    } else {
        NodeSach * p;
        for (p = First; p -> pNext != NULL; p = p -> pNext);
        Insert_Sach_After(p, sach);
    }
}

void Insert_Sach_Sort(NodeSach * & First, Sach & sach) {
    NodeSach * p;
    if (First == NULL) {
        Insert_Sach_First(First, sach);
        return;
    }
    for (p = First; p -> pNext != NULL; p = p -> pNext) {
        if (strcmp(p -> sach.Masach, sach.Masach) > 0 && strcmp(p -> pNext -> sach.Masach, sach.Masach) < 0) {
            Insert_Sach_After(p, sach);
        }
    }
}

void Delete_All_DMS(NodeSach * & First) {
    NodeSach * p;
    while (First != NULL) {
        p = First;
        First = p -> pNext;
        delete p;
    }
}
void Update_Sach(NodeSach * node, Sach sach) {
    if (node == NULL) {
        printf("KHONG THE CAP NHAT SACH!");
    } else {
        node -> sach = sach;
    }
}
int Delete_Sach(NodeSach *&First, char masach[]){
	NodeSach *ptr;
	NodeSach *p=First;
	if(First==NULL){
		return 0;
	}
	if(strcmp(First->sach.Masach,masach)==0){
		p=First;
		First=p->pNext;
		delete p;
		return 1;
	}
//	for(p=First; p->pNext!=NULL && strcmp(masach,p->pNext->sach.Masach)!=0; p=p->pNext);
//	if(strcmp(p->sach.Masach,masach)==0 && p->pNext!=NULL){
//			ptr=p->pNext;
//			p->pNext=ptr->pNext;
//			delete p; 
//			return;
//	}
	for(p=First; p->pNext!=NULL; p=p->pNext){
		if(strcmp(p->pNext->sach.Masach,masach)==0){
			ptr=p->pNext;
			p->pNext=ptr->pNext;
			delete ptr;
			return 1;
		}
	}
	return 0;
}
Sach * Get_Sach(NodeSach * & First, char masach[]) {
    for (NodeSach * p = First; p != NULL; p = p -> pNext) {
        if (strcmp(p -> sach.Masach, masach) == 0) {
            return &p -> sach;
        }
    }
    return NULL;
}
NodeSach * Get_NodeSach(NodeSach * & First, char masach[]) {
    NodeSach * p = First;
    for (p; p -> pNext != NULL; p = p -> pNext) {
        if (strcmp(p -> sach.Masach, masach) == 0) {
            return p;
        }
    }
    return NULL;
}
NodeSach * Get_NodeSach_from_ISBN(NodeSach * & First, char ISBN[]) {
    NodeSach * p = First;
    if (First != NULL) {
        for (p; p -> pNext != NULL; p = p -> pNext) {
            if (strcmp(ISBN, Get_ISBN_from_MaSach(p -> sach.Masach)) == 0) {
                return p;
            }
        }
    } else {
        return NULL;
    }
}

struct DS_DMS_MangConTro {
    Sach * sach[1000];
    void Init_Ds_Dms_ISBN(int sosach) {}
    void Update_Sach_DS_DMS(NodeSach * First) {
        int k = 0;
        if (First != NULL) {
            for (NodeSach * p = First; p != NULL; p = p -> pNext) {
                if (strcmp(p -> sach.Masach, "") != 0) {
                    sach[k] = & p -> sach;
                    k++;
                }

            }
        }
    }
    void ResetDS_DMS(){
    	delete sach;
	}

};
void DeleteAllNodeSach(NodeSach* &First){
	NodeSach *removeNode;
	while(First != NULL){
		removeNode = First;
		First = First->pNext;
		delete removeNode;
	}
}

//du lieu 1 node trong ds mang tuyen tinh
//
//==========================================MANG CON TRO: DAU SACH===============================
struct DauSach {
    char ISBN[7];
    char Tensach[25], Tacgia[15], Theloai[15];
    int Sotrang, Nxb;
    NodeSach * pNext;
    //them thuoc tinh
    int Tongsoluongsach, Soluongmuon;
    DauSach() {
        strcpy(ISBN, "");
        strcpy(Tensach, "");
        strcpy(Tacgia, "");
        strcpy(Theloai, "");
        Sotrang = 0;
        Nxb = 1900;
        pNext = NULL;
        Tongsoluongsach = 0;
        Soluongmuon = 0;
    }
    DauSach(char * isbn, char * tensach, char * tacgia, char * theloai, int sotrang, int nxb) {
        strcpy(ISBN, isbn);
        strcpy(Tensach, tensach);
        strcpy(Tacgia, tacgia);
        strcpy(Theloai, theloai);
        Sotrang = sotrang;
        Nxb = nxb;

        Tongsoluongsach = 0;
        Soluongmuon = 0;
    }

};
// danh sach mang tuyen tinh
struct DS_DauSach {
    int n;
    DauSach * node[MAX_SIZE_DS];

    void Init_DSDS() {
        n = 0;
    }
    void Add_DauSach_Last(DS_DauSach & dsds, DauSach dausach) {
        if (dsds.n > MAX_SIZE_DS) {
            printf("DANH SACH DAU SACH DAY!");
        } else {
            dsds.node[dsds.n] = new DauSach();
            * dsds.node[dsds.n] = dausach;
            dsds.n++;
        }
    }

};

void Insert_DauSach_Position(DS_DauSach & dsds, DauSach dausach, int vitri) {
    if (vitri < 0) {
        printf("VI TRI THEM DAU SACH KHONG PHU HOP!");
    }
    int i;
    dsds.node[dsds.n] = new DauSach();
    for (i = dsds.n - 1; i >= vitri; i--) {
        * dsds.node[i + 1] = * dsds.node[i];
    }
    * dsds.node[vitri] = dausach;
    dsds.n++;
}
void Add_DauSach(DS_DauSach & dsds, DauSach dausach) {
    if (dsds.n > MAX_SIZE_DS) {
        printf("DANH SACH DAU SACH DAY!");
    } else {
        for (int i = 0; i < dsds.n; i++) {
            if (strcmp(dausach.Theloai, dsds.node[i] -> Theloai) < 0) {
                Insert_DauSach_Position(dsds, dausach, i);
                return;
            }

            if (strcmp(dausach.Theloai, dsds.node[i] -> Theloai) == 0) {
                if (strcmp(dausach.Tensach, dsds.node[i] -> Tensach) <= 0) {
                    Insert_DauSach_Position(dsds, dausach, i);
                    return;
                }
            }
        }
        dsds.node[dsds.n] = new DauSach();
        * dsds.node[dsds.n] = dausach;
        dsds.n++;
    }
}
int Exist_DauSach(DS_DauSach dsds, DauSach * ds) {
    if (dsds.n <= 0) {
        printf("DANH SACH DAU SACH RONG!");
        return -1;
    } else {
        for (int i = 0; i < dsds.n; i++) {
            if (strcmp(dsds.node[i] -> ISBN, ds -> ISBN) == 0) {
                return i;
            }
        }
    }
    return -1;
}

DauSach * Search_DauSach_ISBN(DS_DauSach dsds, char ISBN[]) {
    if (dsds.n < 0) {
        printf("DANH SACH DAU SACH RONG!");
        return NULL;
    }
    for (int i = 0; i < dsds.n; i++) {
        if (strcmp(dsds.node[i] -> ISBN, ISBN) == 0) {
            return dsds.node[i];
        }
    }
    return NULL;
}
void Delete_DauSach(DS_DauSach &dsds, int vitri){
	for(int i=vitri; i<dsds.n-1;i++){
		dsds.node[i]=dsds.node[i+1];
	}
	delete dsds.node[dsds.n-1];
	dsds.n--;
}
void DeleteAllDauSach(DS_DauSach &dsds){
	for(int i=0; i<dsds.n;i++){
		DeleteAllNodeSach(dsds.node[i]->pNext);
		delete dsds.node[i];
	}
	dsds.n=0;
}

//
//======================================DANH SACH LIEN KET KEP====================================

struct Date {
    int ngay, thang, nam;
};
Date * Get_Date_Today() {
    Date * today;
    time_t now = time(0);
    tm * ltm = localtime( & now);
    today -> ngay = ltm -> tm_mday;
    today -> thang = ltm -> tm_mon + 1;
    today -> nam = ltm -> tm_year + 1900;
    return today;
}
int julianDay(int year, int month, int day) {

    int a = (14 - month) / 12;
    int y = year + 4800 - a;
    int m = month + 12 * a - 3;
    int jdn = day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
    
    //int jdn = 365*year + year/4 - year/100 + year/400 + day + (153*month+8)/5;
    return jdn;
}
int diff(Date * date1, Date * date2) {
    return abs(julianDay(date1 -> nam, date1 -> thang, date1 -> ngay) - julianDay(date2 -> nam, date2 -> thang, date2 -> ngay));
}
struct MuonTra {
    char MASACH[20];
    Date * Ngaymuon, * Ngaytra;
    int trangthai;
    /*
     * 0: Dang muon
     * 1: Da tra
     * 2: Lam mat
     */
    MuonTra() {}
};
struct NodeMuonTra {
    MuonTra muontra;
    NodeMuonTra * prev;
    NodeMuonTra * next;
};

struct DS_MuonTra {
    NodeMuonTra * First;
    NodeMuonTra * Last;
    /*
     * thuoc tinh them 
     */
    int Tong; // tong so luong sach da muon
    int chuaTra; // so luong sach dang muon + lam mat

    DS_MuonTra() {
        First = NULL;
        Last = NULL;
        Tong = 0;
        chuaTra = 0;
    }~DS_MuonTra() {}
};


NodeMuonTra * createNodeMT(MuonTra & mt) {
    NodeMuonTra * newNode = new NodeMuonTra;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    newNode -> muontra = mt;

    return newNode;
}
void Insert_First_DSMT(DS_MuonTra & DSMT, MuonTra & mt) {
    NodeMuonTra * nodeMT = createNodeMT(mt);
    nodeMT -> next = DSMT.First;

    if (DSMT.First = NULL) DSMT.Last = nodeMT;
    else DSMT.First -> prev = nodeMT;

    DSMT.First = nodeMT;
}
void Insert_Last_DSMT(DS_MuonTra & DSMT, MuonTra & mt) {
    NodeMuonTra * nodeMT = createNodeMT(mt);
    if (DSMT.First == NULL) {
        DSMT.First = nodeMT;
        DSMT.Last = nodeMT;
    } else {
        DSMT.Last -> next = nodeMT;
        nodeMT -> prev = DSMT.Last;
        DSMT.Last = nodeMT;
    }
    DSMT.Tong++;
    if (mt.trangthai != 1) DSMT.chuaTra++;
}
void DeleteAllMuonTra(DS_MuonTra &DSMT){
	NodeMuonTra *removeNode;
	while(DSMT.First != NULL){
		removeNode = DSMT.First;
		DSMT.First = DSMT.First->next;
		delete removeNode;
	}
}
//=========================================================================================================================================
//============================================CAY NHI PHAN TIM KIEM=============================================
//=========================KHAI BAO=============================
struct DocGia {
    int Mathe;
    char Ho[20], Ten[10];
    int phai;
    int trangthai;
    DS_MuonTra dsmt;
    DocGia() {
        strcpy(Ho, "");
        strcpy(Ten, "");
        phai = 1;
        trangthai = 1;
    }
};

struct NodeDocGia {
    DocGia docgia;
    NodeDocGia * left;
    NodeDocGia * right;
};
typedef struct NodeDocGia * NodeDG;
//============================CÁC HÀM XU LÍ CÂY NHI PHÂN================================
void Init_Tree(NodeDG & p) { // khoi tao tree
    p = NULL;
}

void Insert_DG(NodeDG & p, DocGia dg) { //them 1 doc gia vao cay nhi phan
    if (p == NULL) {
        p = new NodeDocGia;
        p -> docgia = dg;
        p -> left = NULL;
        p -> right = NULL;
    } else {
        if (dg.Mathe < p -> docgia.Mathe) Insert_DG(p -> left, dg);
        else if (dg.Mathe > p -> docgia.Mathe) Insert_DG(p -> right, dg);
    }
}
NodeDG Search_DG(NodeDG & p, int mathe) { //tim kiem 1 doc gia theo ma the
    NodeDG nodeDG = p;
    while (nodeDG != NULL && nodeDG -> docgia.Mathe != mathe) {
        if (nodeDG -> docgia.Mathe < mathe) nodeDG = nodeDG -> right;
        else nodeDG = nodeDG -> left;
    }
    return nodeDG;
}
void Update_DG(NodeDG &p, DocGia dg){
	NodeDG nodeDG = p;
    while (nodeDG != NULL && nodeDG -> docgia.Mathe != dg.Mathe) {
        if (nodeDG -> docgia.Mathe < dg.Mathe) nodeDG = nodeDG -> right;
        else nodeDG = nodeDG -> left;
        if(nodeDG -> docgia.Mathe = dg.Mathe){
        	nodeDG -> docgia= dg;
        	return;
		}
    }
}
void Remove_DG_case3(NodeDG & p, NodeDG & rp) { // tim nut thay the nut can phai xoa (nut cuc trai cua nhanh phai nut can xoa)
    if (p -> left != NULL) { // neu chua phai la cuc trai thi duyet tiep
        Remove_DG_case3(p -> left, rp);
    } else {
        rp -> docgia = p -> docgia; //gan nut can xoa bang nut thay the (that ra la xoa nut thay the chu k phai la xoa p)
        rp = p; // gan lai dia chi con tro
        p = p -> right; // neu nut thay the co nhanh phai thi gan lai nhanh phai vao nut thay the
    }
}
void Remove_DG(NodeDG & p, int mathe) {
    if (p == NULL) printf("\n\t\tKhong tim thay doc gia can xoa!\n");
    else {
        if (mathe < p -> docgia.Mathe) Remove_DG(p -> left, mathe);
        else if (mathe > p -> docgia.Mathe) Remove_DG(p -> right, mathe);
        else { // da tim thay ma the can xoa docgia.mathe=mathe
            NodeDG rp = p;
            if (rp -> left == NULL) { // p la nut la hoac nut co 1 cay con ben phai
                p = rp -> right;
            } else if (rp -> right == NULL) { // p la nut la hoac nut co 1 cay con ben trai
                p = rp -> left;
            } else { // p co 2 cay con ben trai va phai
                Remove_DG_case3(rp -> right, p);
            }
            delete rp;
        }
    }
}
int Count_DG_dequi(NodeDG p) { // dem so luong doc gia
    // dem theo phuong phap de qui// han che la khong the dem dc nut goc ne phai +1 
    if (p != NULL) {
        if (p -> left != NULL && p -> right != NULL) return Count_DG_dequi(p -> left) + 1 + Count_DG_dequi(p -> right) + 1;
        if (p -> left != NULL && p -> right == NULL) return Count_DG_dequi(p -> left) + 1;
        if (p -> left == NULL && p -> right != NULL) return Count_DG_dequi(p -> right) + 1;
    } else {
        return 0;
    }

}
int Count_DG(NodeDG p) { //duyet theo phuong phap binh thuong
    NodeDG root = p, rp = p;
    int count = 0;
    while (root) {
        count++;
        if (root -> left == NULL) {
            root = root -> right;
        } else {

        }
    }

}
int Update_1DG(NodeDG p, DocGia & dg) {
    NodeDG node = Search_DG(p, dg.Mathe);
    if (node == NULL) {
        printf("\n \t \t Khong the update Doc gia !");
    } else {
        dg.Mathe = node -> docgia.Mathe; // cap nhat ma the de dam bao ma the khong bi thay doi
        node -> docgia = dg;
    }
}
void DeleteMemoryDocGia(NodeDG &node){
	if(node != NULL){
		DeleteMemoryDocGia(node->left);
		DeleteMemoryDocGia(node->right);
		DeleteAllMuonTra(node->docgia.dsmt);
		
		delete node;
//		node = NULL;
	}
}
int Random_MaDG(NodeDG p) { //tao so random sao cho tong node ben trai root = tong node ben phai root
    //printf("Toi day!");
    int random = 00000;
    if (p == NULL) {
        random = (99999 + 10000) / 2;
    } else {
        if (Count_DG_dequi(p -> left) > Count_DG_dequi(p -> right)) {
            do {
                //printf("Toi day!");
                random = rand() % (99999 - p -> docgia.Mathe) + p -> docgia.Mathe; // random tu 55555 den 99999
            } while (Search_DG(p, random) != NULL);
        } else {
            do {
                //printf("Toi day!");
                random = rand() % (p -> docgia.Mathe) + 10000; // random tu 10000 den 55555
            } while (Search_DG(p, random) != NULL);
        }
    }
    return random;
}
void Traverse_LNR(NodeDG & p) {
    if (p != NULL) {
        Traverse_LNR(p -> left);
        printf("%d\t%s\t%s\t%d\t\t%d\n", p -> docgia.Mathe, p -> docgia.Ho, p -> docgia.Ten, p -> docgia.phai, p -> docgia.trangthai);
        Traverse_LNR(p -> right);
    }
}
//==================================DANH SÁCH DOC GIA THEO MANG CON TRO (BST) ===============================
const int MAX_SIZE_DSDG = 99999 - 10000;

enum MODE_DG {
    MODE_MaThe,
    MODE_Ten,
    MODE_QH
};
struct DanhSach_DG {
    int n;
    DocGia * DG[MAX_SIZE_DSDG];
    int SoNgayQH[MAX_SIZE_DSDG];
    MODE_DG mode;
    DanhSach_DG() {
        mode = MODE_MaThe;
    }
    void Insert_DG_to_DSDG(NodeDG & p) { // Them Theo LNR (thu tu tang dan theo key)
        if (p != NULL) {
            Insert_DG_to_DSDG(p -> left);
            DG[n++] = & p -> docgia;
            Insert_DG_to_DSDG(p -> right);
        }
    }
    void Reset_DSDG() {
        n = 0;
    }
    void GetAll_DSDG(NodeDG & p) {
        Reset_DSDG();
        Insert_DG_to_DSDG(p);
        mode = MODE_MaThe;
    }
    int Compare_DG(DocGia * dg1, DocGia * dg2) {
        if (mode == MODE_MaThe) {
            return dg1 -> Mathe - dg2 -> Mathe;
        } else if (mode == MODE_Ten) {
            if (strcmp(dg1 -> Ten, dg2 -> Ten) == 0) {
                return strcmp(dg1 -> Ho, dg1 -> Ho);
            } else return strcmp(dg1 -> Ten, dg2 -> Ten);
        }
        return 0;
    }
    void Partition(int low, int high) {
        int i = low, j = high;
        DocGia * pivot, * temp;
        pivot = DG[(i + j) / 2];
        int qhTemp = 0;
        int pivotQH = SoNgayQH[(i + j) / 2];
        do {
            if (mode == MODE_QH) {
                while (SoNgayQH[i] > pivotQH) i++;
                while (SoNgayQH[j] < pivotQH) j--;
            } else {
                while (Compare_DG(DG[i], pivot) < 0) i++;
                while (Compare_DG(DG[j], pivot) > 0) j--;
            }
            if (i <= j) {
                if (mode == MODE_QH) {
                    qhTemp = SoNgayQH[i];
                    SoNgayQH[i] = SoNgayQH[j];
                    SoNgayQH[j] = qhTemp;
                }
                temp = DG[i];
                DG[i] = DG[j];
                DG[j] = temp;
                i++;
                j--;
            }
        } while (i <= j);
        if (low < j) Partition(low, j);
        if (i < high) Partition(i, high);
    }
    void Sort_DSDG_Mathe() {
        if (mode != MODE_MaThe && n > 0) {
            mode = MODE_MaThe;
            Partition(0, n - 1);
        }
    }
    void Sort_DSDG_Ten() {
        if (mode != MODE_Ten && n > 0) {
            mode = MODE_Ten;
            Partition(0, n - 1);
        }
    }
    void SortDocGiaQuaHan() {
        if (mode != MODE_QH && n > 0) {
            mode = MODE_QH;
            Partition(0, n - 1);
        }
    }

    int Check_QH_DG(NodeDG p) {
        int ngayQH = 7, qh;
        gotoxy(80, 20);
        printf("TOI DAY");
        gotoxy(80, 20);
        printf("       ");
        Date * today = new Date;
        today = Get_Date_Today();
        for (NodeMuonTra * mt = p -> docgia.dsmt.First; mt != NULL; mt = mt -> next) {
            if (mt -> muontra.trangthai == 0) {
                qh = diff(today, mt -> muontra.Ngaymuon);
                if (qh > ngayQH) {
                    ngayQH = qh;
                }
            }
        }
        if (ngayQH > 7) return ngayQH;
        else return 0;
    }
    void Insert_DGQH_to_DSDG(NodeDG & p) { // THEM DOC GIA QUA HAN VAO DSDG
        if (p != NULL) {
            Insert_DGQH_to_DSDG(p -> left);
            if (p -> docgia.dsmt.chuaTra > 0) {
                if (Check_QH_DG(p) > 7) {
                    DG[n++] = & p -> docgia;
                    SoNgayQH[n - 1] = Check_QH_DG(p);
                }
            }
            Insert_DGQH_to_DSDG(p -> right);
        }
    }
    void Get_DSDG_QuaHan(NodeDG & p) {
        Reset_DSDG();
        Insert_DGQH_to_DSDG(p);
        SortDocGiaQuaHan();
    }

};
