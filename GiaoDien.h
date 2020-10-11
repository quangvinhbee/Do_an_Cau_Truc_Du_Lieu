#include "IO_File.h"

void Draw_Case_1();
void Draw_Case_2();
void Draw_Case_3();
//===================================MENU CHINH========================================
int GetKey() {
    char key;
    key = _getch();
    if (key == -32 || key == 0)
        return -_getch();
    else return key;
}
const int so_item_menu_Main = 4;
//===========mau cua CTR==========================
void ColorAll() {
    system("Color B2");
    SetColor(15);
}
void Normal() {
    SetColor(12);
    SetBGColor(7);
}

void HighLight() {
    SetColor(4);
    SetBGColor(15);
}
void HighLight_Text() {
    SetColor(4);
    SetBGColor(11);
}
void Normal_Text() {
    SetColor(15);
    SetBGColor(11);
}

//==========VE KHUNG O DAY==================
void Draw_H(int x, int y, int dai) {
    gotoXY(x, y);
    printf("%c", char(204));
    for (int i = 1; i <= dai; i++) {
        gotoXY(x + i, y);
        printf("%c", char(205));
    }
    gotoXY(x + dai + 1, y);
    printf("%c", char(185));
}
void Draw_I(int x, int y, int rong) {
    gotoXY(x, y);
    printf("%c", char(203));
    for (int i = 1; i <= rong; i++) {
        gotoXY(x, y + i);
        printf("%c", char(186));
    }
    gotoXY(x, y + rong + 1);
    printf("%c", char(202));
}
void Draw_frame_Main(int x, int y, int rong, int dai) {
    ColorAll();
    gotoXY(x, y);
    printf("%c", char(201));
    for (int i = 1; i <= rong; i++) {
        printf("%c", char(205));
    }
    printf("%c", char(187));
    gotoXY(x, y + 1);
    for (int j = 1; j <= dai; j++) {
        gotoXY(x, y + j);
        printf("%c", char(186));
        gotoXY(x + rong + 1, y + j);
        printf("%c", char(186));
    }
    gotoXY(x, y + dai + 1);
    printf("%c", char(200));
    for (int k = 1; k <= rong; k++) {
        printf("%c", char(205));
    }
    printf("%c", char(188));
    HighLight();
    //gotoxy(3,Y); printf("      ");
    gotoxy(3, Y - 1);
    printf(" <ESC ");
    gotoxy(13 + 100, Y - 1);
    printf("%c ", 254);
    gotoxy(11 + 100, Y - 1);
    printf("%c ", 60);
    gotoxy(14 + 100, Y - 1);
    printf(" %c", 62);
    gotoxy(11 + 100, Y - 1 - 1);
    printf("  %c  ", 94);
    gotoxy(11 + 100, Y - 1 + 1);
    printf("  %c  ", 118);
    //gotoxy(3,Y+2); printf("      ");
    Normal_Text();

    gotoXY(45, 1);
    printf("- QUAN LI THU VIEN - NHOM 56 - ");
    Draw_H(0, 2, rong);
}
void Draw_frame(int x, int y, int rong, int dai) {
    gotoXY(x, y);
    printf("%c", char(201));
    for (int i = 1; i <= rong; i++) {
        printf("%c", char(205));
    }
    printf("%c", char(187));
    gotoXY(x, y + 1);
    for (int j = 1; j <= dai; j++) {
        gotoXY(x, y + j);
        printf("%c", char(186));
        gotoXY(x + rong + 1, y + j);
        printf("%c", char(186));
    }
    gotoXY(x, y + dai + 1);
    printf("%c", char(200));
    for (int k = 1; k <= rong; k++) {
        printf("%c", char(205));
    }
    printf("%c", char(188));
}

//===========CHAY CHU================
void intro() {
    char a[1000] = " - QUAN LI THU VIEN - NHOM 56     ", b[1000], c[40];
    strcpy(b, a);
    strcat(a, b);
    int strl = strlen(a);
    gotoxy(35,Y/5);
    printf("  _____ _______ _____ _______ _    _  _____ __  __ ");
    gotoxy(35,Y/5+1);
    printf(" |  __ \\__   __|_   _|__   __| |  | |/ ____|  \\/  |");
    gotoxy(35,Y/5+2);
    printf(" | |__) | | |    | |    | |  | |__| | |    | \\  / |");
    gotoxy(35,Y/5+3);
    printf(" |  ___/  | |    | |    | |  |  __  | |    | |\\/| |");
    gotoxy(35,Y/5+4);
    printf(" | |      | |   _| |_   | |  | |  | | |____| |  | |");
    gotoxy(35,Y/5+5);
    printf(" |_|      |_|  |_____|  |_|  |_|  |_|\\_____|_|  |_|");
    gotoxy(35,Y/5+7);
    printf("		   DE TAI: QUAN LI THU VIEN");
    gotoxy(35,Y/5+8);
    printf("		GIANG VIEN: LUU NGUYEN KY THU");
    gotoxy(35,Y/5+9);
    printf("		SINH VIEN THUC HIEN: ");
    gotoxy(35,Y/5+10);
    printf("			LAM QUANG VINH\t\t N17DCAT078 ");
    gotoxy(35,Y/5+11);
    printf("			LE VINH DUC TAI\t\t N17DCAT078 ");
    gotoxy(35,Y/5+12);
    printf("			BUI HONG HUY \t\t N17DCAT078 ");
    for (int i = 0; i < strl; i++) {
        strncpy(c, a + i, 30);
        c[30] = 0;
        Sleep(90);
        gotoXY(45, 1);
        printf("%s", c);
        int per = (i * 102 / strl);
        Sleep(0);
        gotoXY(i + 25, Y / 2+8);
        printf("%c %d%%", 219, per);
    }
    gotoXY(45, 1);
    printf("%s", b);
    Sleep(1000);
}
//===================OUTRO=====================
void outro() {
	system("cls");
	ColorAll();
	gotoxy(35,Y/5);
    printf("   _____  ____   ____  _____    ______     ________ ");
    gotoxy(35,Y/5+1);
    printf("  / ____|/ __ \\ / __ \\|  __ \\  |  _ \\ \\   / /  ____|");
    gotoxy(35,Y/5+2);
    printf(" | |  __| |  | | |  | | |  | | | |_) \\ \\_/ /| |__   ");
    gotoxy(35,Y/5+3);
    printf(" | | |_ | |  | | |  | | |  | | |  _ < \\   / |  __| ");
    gotoxy(35,Y/5+4);
    printf(" | |__| | |__| | |__| | |__| | | |_) | | |  | |____ ");
    gotoxy(35,Y/5+5);
    printf("  \\_____|\\____/ \\____/|_____/  |____/  |_|  |______|");
    char a[1000] = " - QUAN LI THU VIEN - NHOM 56  -  ", b[1000], c[40];
    strcpy(b, a);
    strcat(a, b);
    int strl = strlen(a);
    for (int i = 0; i < strl; i++) {
        strncpy(c, a + i, 30);
        c[30] = 0;
        Sleep(90);
        gotoXY(45, 1);
        printf("%s", c);
        int per = (i * 102 / strl);
        Sleep(0);
        gotoXY(i + 25, Y / 2+10);
        printf("%c %d%%", 219, per);
    }
    
    gotoXY(45, 1);
    printf("%s", b);
    while(1){
	}
}
//=========================MENu=================
void Draw_Button_Menu_Highligh(char td[so_item_menu_Main][50], int cot, int dong, int chon) {
    HighLight();
    gotoXY(cot, dong + 1 + (chon) * 4);
    printf("%s", "                            ");
    gotoXY(cot, dong + 2 + (chon) * 4);
    printf("%s", td[chon]);
    gotoXY(cot, dong + 3 + (chon) * 4);
    printf("%s", "                            ");
}
void Draw_Button_Menu_Normal(char td[so_item_menu_Main][50], int cot, int dong, int chon) {
    Normal();
    gotoXY(cot, dong + 1 + (chon) * 4);
    printf("%s", "                            ");
    gotoXY(cot, dong + 2 + (chon) * 4);
    printf("%s", td[chon]);
    gotoXY(cot, dong + 3 + (chon) * 4);
    printf("%s", "                            ");
}
int Up_Down_Menu_Chinh(char td[so_item_menu_Main][50]) {
    int cot_menu = 6 + X / 2 - 20;
    int dong_menu = Y / 2 - 10;
    Normal();
    system("cls");
    Draw_frame_Main(0, 0, X, Y);
    int chon = 0;
    for (int i = 0; i < so_item_menu_Main; i++) {
        Draw_Button_Menu_Normal(td, cot_menu, dong_menu, i);
    }
    Draw_Button_Menu_Highligh(td, cot_menu, dong_menu, chon);
    char kytu;
    do {
        kytu = GetKey();
        switch (kytu) {
        case UP:
            if (chon > 0) {
                Draw_Button_Menu_Normal(td, cot_menu, dong_menu, chon);
                chon--;
                Draw_Button_Menu_Highligh(td, cot_menu, dong_menu, chon);
            }
            break;
        case DOWN:
            if (chon + 1 < so_item_menu_Main) {
                Draw_Button_Menu_Normal(td, cot_menu, dong_menu, chon);
                chon++;
                Draw_Button_Menu_Highligh(td, cot_menu, dong_menu, chon);
            }
            break;
        case ENTER:
            return chon + 1;
        case ESC:
            return ESC;
        } // end switch
    } while (1);
}
void Menu_Chinh() {
    char thucdon[so_item_menu_Main][50] = {
        "      1. QUAN LI DOC GIA    ",
        "      2. QUAN LI SACH       ",
        "      3. MUON TRA SACH      ",
        "      4. EXIT               "
    };
    int chon = 0;
    while (1) {
        chon = Up_Down_Menu_Chinh(thucdon);
        switch (chon) {
        case 1:

            Draw_Case_1();
            break;
        case 2:
            Draw_Case_2();
            break;
        case 3:
            Draw_Case_3();
            break;
        case 4:
            //system("exit");
            outro();
            exit(1);
        case ESC:
            break;
        }
    }
}
void theme() {
    ColorAll();
    Draw_frame_Main(0, 0, X, Y);

    //intro();
    Menu_Chinh();
}

//===================================MENU CASE 1========================================
const int sodong_dsdg = 17;
int sl_page; // tong so luong trang	 

void Draw_Title_Case1(int x, int y, int dai) { // tieu de cua ds
    Draw_H(x, y + 2, dai);
    //Ma doc gia
    gotoXY(x + 1, y + 1);
    printf("%s %c", " MA DOC GIA ", 186);
    //Ho
    gotoXY(x + 14, y);
    printf("%c", 203);
    gotoXY(x + 14, y + 2);
    printf("%c", 206);
    gotoXY(x + 16, y + 1);
    printf("%s %c", "        HO       ", 186);
    //Ten
    gotoXY(x + 34, y);
    printf("%c", 203);
    gotoXY(x + 34, y + 2);
    printf("%c", 206);
    gotoXY(x + 37, y + 1);
    printf("%s %c", "    TEN    ", 186);
    //Phai
    gotoXY(x + 49, y);
    printf("%c", 203);
    gotoXY(x + 49, y + 2);
    printf("%c", 206);
    gotoXY(x + 51, y + 1);
    printf("%s %c", "PHAI", 186);
    //Trang thai
    gotoXY(x + 56, y);
    printf("%c", 203);
    gotoXY(x + 56, y + 2);
    printf("%c", 206);
    gotoXY(x + 58, y + 1);
    printf("%s", "  TRANG THAI");
    //ve hang phan cach

    for (int i = y + 3; i < y + sodong_dsdg + 3; i++) {
        gotoXY(x + 14, i);
        printf("%c", 186);
        gotoXY(x + 34, i);
        printf("%c", 186);
        gotoXY(x + 49, i);
        printf("%c", 186);
        gotoXY(x + 56, i);
        printf("%c", 186);
    }
    gotoXY(x + 14, y + sodong_dsdg + 3);
    printf("%c", 202);
    gotoXY(x + 34, y + sodong_dsdg + 3);
    printf("%c", 202);
    gotoXY(x + 49, y + sodong_dsdg + 3);
    printf("%c", 202);
    gotoXY(x + 56, y + sodong_dsdg + 3);
    printf("%c", 202);
    //==========guide================

    gotoxy(78, y + sodong_dsdg + 3);
    HighLight();
    printf(" F1 ");
    Normal();
    printf(" SAP XEP  ");

    gotoxy(95, y + sodong_dsdg + 3);

    HighLight();
    printf(" F2 ");
    Normal();
    printf(" THEM MOI");

    gotoxy(78, y + sodong_dsdg + 5);

    HighLight();
    printf(" F3 ");
    Normal();
    printf(" CHINH SUA");

    gotoxy(95, y + sodong_dsdg + 5);

    HighLight();
    printf(" CTRL_S ");
    Normal();
    printf(" LUU");

    Normal_Text();
}
void Draw_View_1DG_Case1(DocGia dg) {
    //clear data view
    gotoxy(88, 7);
    printf("                          ");
    gotoxy(88, 9);
    printf("                          ");
    gotoxy(88, 11);
    printf("                          ");
    gotoxy(88, 13);
    printf("                          ");
    gotoxy(88, 15);
    printf("                          ");

    //dien thong tin vao view
    gotoxy(88, 7);
    printf("%d", dg.Mathe);
    gotoxy(88, 9);
    printf("%s", dg.Ho);
    gotoxy(88, 11);
    printf("%s", dg.Ten);
    gotoxy(88, 13);
    printf("%d   (1: NAM, 0: NU)", dg.phai);
    gotoxy(88, 15);
    printf("%d   (1: ACTIVE, 0: BLOCK)", dg.trangthai);
    gotoxy(88, 17);
    printf("%d QUYEN SACH", dg.dsmt.chuaTra);
}
void Draw_1_DG(DocGia dg, int x, int y) { // hien thi 1 doc gia trong ds

    Draw_View_1DG_Case1(dg);
    //Ma doc gia
    gotoXY(x + 1, y);
    printf("   %d", dg.Mathe);
    //Ho
    gotoXY(x + 16, y);
    printf("%s", dg.Ho);
    //Ten

    gotoXY(x + 36, y);
    printf("  %s", dg.Ten);
    //Phai
    if (dg.phai == 1) {
        gotoXY(x + 50, y);
        printf("  %s", "NAM");
    } else {
        gotoXY(x + 50, y);
        printf("  %s", "NU");
    }
    //Trang thai
    if (dg.trangthai == 1) {
        gotoXY(x + 57, y);
        printf("   %s", "HOAT DONG  ");
    } else {
        gotoXY(x + 57, y);
        printf("   %s", "BI KHOA  ");
    }

}
//==============2 nut sap xep=====================
void Draw_Button_Sort_Mathe(int x, int y) {
    gotoxy(x + 1, y + 1);
    printf("DANH SACH DANG SAP XEP THEO:");
    gotoxy(x + 1, y + 2);
    printf("(F1: doi cach sap xep)");
    x += 30;
    HighLight();
    gotoxy(x, y);
    printf("        ");
    gotoxy(x, y + 1);
    printf(" MA THE ");
    gotoxy(x, y + 2);
    printf("        ");
    Normal();
    gotoxy(x + 8, y);
    printf("        ");
    gotoxy(x + 8, y + 1);
    printf(" HO TEN ");
    gotoxy(x + 8, y + 2);
    printf("        ");
    Normal_Text();
}
void Draw_Button_Sort_HoTen(int x, int y) {
    gotoxy(x + 1, y + 1);
    printf("DANH SACH DANG SAP XEP THEO:");
    gotoxy(x + 1, y + 2);
    printf("(F1: doi cach sap xep)");
    x += 30;
    Normal();
    gotoxy(x, y);
    printf("        ");
    gotoxy(x, y + 1);
    printf(" MA THE ");
    gotoxy(x, y + 2);
    printf("        ");
    HighLight();
    gotoxy(x + 8, y);
    printf("        ");
    gotoxy(x + 8, y + 1);
    printf(" HO TEN ");
    gotoxy(x + 8, y + 2);
    printf("        ");
    Normal_Text();
}
//================DIALOG MESSS BOX YES NO / DELETE DG=================
int Dialog_Mess_Box(int x, int y, string str) {
    int check = 0, key;
    Normal_Text();
    Draw_frame(x, y, 26, 5);
    gotoxy(x + 1, y + 1);
    cout << str;
    while (1) {
        if (check == 1) {
            HighLight();
            gotoxy(x + 4, y + 3);
            printf("      ");
            gotoxy(x + 4, y + 4);
            printf("  YES ");
            gotoxy(x + 4, y + 5);
            printf("      ");

            Normal();
            gotoxy(x + 18, y + 3);
            printf("      ");
            gotoxy(x + 18, y + 4);
            printf("  NO  ");
            gotoxy(x + 18, y + 5);
            printf("      ");
        } else {
            Normal();
            gotoxy(x + 4, y + 3);
            printf("      ");
            gotoxy(x + 4, y + 4);
            printf(" YES  ");
            gotoxy(x + 4, y + 5);
            printf("      ");

            HighLight();
            gotoxy(x + 18, y + 3);
            printf("      ");
            gotoxy(x + 18, y + 4);
            printf("  NO  ");
            gotoxy(x + 18, y + 5);
            printf("      ");
        }
        key = GetKey();
        switch (key) {
        case LEFT:
            check = 1;
            break;
        case RIGHT:
            check = 0;
            break;
        case ENTER:
            Normal_Text();
            for (int i = x; i <= x + 27; i++) {
                for (int j = y; j < y + 7; j++) {
                    gotoxy(i, j);
                    printf(" ");
                }
            }
            return check;
        }
    }
}
// =============lam sach lai ds hien thi========================
void Clear_DSDG(int x, int y, int dai, int rong) {
    Normal_Text();
    for (int i = x; i < x + dai; i++) {
        for (int j = y; j < y + rong; j++) {
            gotoxy(i, j);
            printf(" ");
        }
    }
    Draw_Title_Case1(1, 6, 70);
}
void Show_DSDG(DanhSach_DG dsdg, int page_hientai, int x, int y, int sodong) { // hien thi dsdg cua 1 trang
    Normal_Text();
    Clear_DSDG(x + 1, y, 70, sodong_dsdg);
    for (int i = page_hientai * sodong_dsdg; i < page_hientai * sodong_dsdg + sodong; i++) {
        Draw_1_DG( * dsdg.DG[i], x, y + (i - page_hientai * sodong_dsdg));
    }
    //================page hien tai / sl page vi du trang 5/6==================
    gotoxy((x + 60) / 2, y + sodong_dsdg + 2);
    printf("Trang ");
    HighLight();
    printf("%d / %d", page_hientai + 1, sl_page);
    Normal();
    //==============in dong dau tien=====================
    HighLight_Text();
    Draw_1_DG( * dsdg.DG[page_hientai * sodong_dsdg], x, y);
}
void Draw_fram_view_case1() {
    //==================================VE KHUNG NHO BEN PHAI=======================
    int x_view = 74, y_view = 6, dai_view = 40, rong_view = 11;
    Draw_frame(x_view, y_view, dai_view, rong_view);
    Draw_H(x_view, y_view + 2, dai_view);
    Draw_H(x_view, y_view + 4, dai_view);
    Draw_H(x_view, y_view + 6, dai_view);
    Draw_H(x_view, y_view + 8, dai_view);
    Draw_H(x_view, y_view + 10, dai_view);
    gotoxy(x_view + 1, y_view + 1);
    printf("MA DOC GIA");
    gotoxy(x_view + 12, y_view);
    printf("%c", 203);
    gotoxy(x_view + 12, y_view + 1);
    printf("%c", 186);
    gotoxy(x_view + 12, y_view + 2);
    printf("%c", 206);
    gotoxy(x_view + 1, y_view + 3);
    printf("    HO   ");
    gotoxy(x_view + 12, y_view + 3);
    printf("%c", 186);
    gotoxy(x_view + 12, y_view + 4);
    printf("%c", 206);
    gotoxy(x_view + 1, y_view + 5);
    printf("   TEN  ");
    gotoxy(x_view + 12, y_view + 5);
    printf("%c", 186);
    gotoxy(x_view + 12, y_view + 6);
    printf("%c", 206);
    gotoxy(x_view + 1, y_view + 7);
    printf("   PHAI ");
    gotoxy(x_view + 12, y_view + 7);
    printf("%c", 186);
    gotoxy(x_view + 12, y_view + 8);
    printf("%c", 206);
    gotoxy(x_view + 1, y_view + 9);
    printf("TRANG THAI ");
    gotoxy(x_view + 12, y_view + 9);
    printf("%c", 186);
    gotoxy(x_view + 12, y_view + 10);
    printf("%c", 206);
    gotoxy(x_view + 1, y_view + 11);
    printf(" DANG MUON");
    gotoxy(x_view + 12, y_view + 11);
    printf("%c", 186);
    gotoxy(x_view + 12, y_view + 12);
    printf("%c", 202);

}
//===================XU LI NHAP 1 CHUOI======================
char * Input_Str(char str[], int x, int y, int length) {
    int k;
    int len;
    Normal_Text();
    gotoxy(x, y);
    len = strlen(str);
    cout << str;
    while (1) {
        k = GetKey();
        if (k >= 97 && k <= 122 && len < length) {
            str[len] = k - 32;
            gotoxy(x, y);
            len = strlen(str);
            cout << str;
        } else if (k >= 65 && k <= 96 && len < length) {
            str[len] = k;
            gotoxy(x, y);
            len = strlen(str);
            cout << str;
        } else if (k == BACKSPACE) {
            str[len - 1] = NULL;
            for (int i = 0; i < strlen(str) + 5; i++) {
                gotoxy(x + i, y);
                printf("   ");
            }
            gotoxy(x, y);
            len = strlen(str);
            cout << str;
        } else if (k == SPACE) {
            if (str[len - 1] != char(255) && len > 0 && len < length) {
                str[len] = 255;
            }
            gotoxy(x, y);
            len = strlen(str);
            cout << str;
        } else if (k == ENTER || k == TAB || k == DOWN || k == ESC || k == UP) {
            gotoxy(x, y);
            HighLight_Text();
            cout << str;
            return str;
        }
    };
    return str;
}
char * Input_Str_Int(char str[], int x, int y, int length) {
    int k;
    int len;
    Normal_Text();
    gotoxy(x, y);
    len = strlen(str);
    cout << str;
    while (1) {
        k = GetKey();
        if (k >= 97 && k <= 122 && len < length) {
            str[len] = k - 32;
            gotoxy(x, y);
            len = strlen(str);
            cout << str;
        } else if (k >= 65 && k <= 96 && len < length) {
            str[len] = k;
            gotoxy(x, y);
            len = strlen(str);
            cout << str;
        } else if (k >= 48 && k <= 57 && len < length) {
            str[len] = k;
            gotoxy(x, y);
            len = strlen(str);
            cout << str;
        } else if (k == BACKSPACE) {
            str[len - 1] = NULL;
            for (int i = 0; i < strlen(str) + 5; i++) {
                gotoxy(x + i, y);
                printf("   ");
            }
            gotoxy(x, y);
            len = strlen(str);
            cout << str;
        } else if (k == SPACE) {
            if (str[len - 1] != char(255) && len > 0 && len < length) {
                str[len] = 255;
            }
            gotoxy(x, y);
            len = strlen(str);
            cout << str;
        } else if (k == ENTER || k == TAB || k == DOWN || k == ESC || k == UP) {
            gotoxy(x, y);
            HighLight_Text();
            cout << str;
            return str;
        }
    };
    return str;
}
char * Input_Str_Int_Masach(char str[], int x, int y, int length) {
    int k;
    int len;
    Normal_Text();
    gotoxy(x, y);
    len = strlen(str);
    cout << str;
    while (1) {
        k = GetKey();
        if (k >= 97 && k <= 122 && len < length) {
            str[len] = k - 32;
            gotoxy(x, y);
            len = strlen(str);
            cout << str;
        } else if (k >= 65 && k <= 96 && len < length) {
            str[len] = k;
            gotoxy(x, y);
            len = strlen(str);
            cout << str;
        } else if (k == '-' && len < length) {
            str[len] = k;
            gotoxy(x, y);
            len = strlen(str);
            cout << str;
        } else if (k >= 48 && k <= 57 && len < length) {
            str[len] = k;
            gotoxy(x, y);
            len = strlen(str);
            cout << str;
        } else if (k == BACKSPACE) {
            str[len - 1] = NULL;
            for (int i = 0; i < strlen(str) + 5; i++) {
                gotoxy(x + i, y);
                printf("   ");
            }
            gotoxy(x, y);
            len = strlen(str);
            cout << str;
        } else if (k == SPACE) {
            if (str[len - 1] != char(255) && len > 0 && len < length) {
                str[len] = 255;
            }
            gotoxy(x, y);
            len = strlen(str);
            cout << str;
        } else if (k == ENTER || k == TAB || k == DOWN || k == ESC || k == UP) {
            gotoxy(x, y);
            HighLight_Text();
            cout << str;
            return str;
        }
    };
    return str;
}
//===============Hàm kiem tra du lieu dau vao cua 1 doc gia==================
int Check_Inp_DG(DocGia dg) {

    if (strlen(dg.Ho) == 0) {
        return 0;
    }
    if (strlen(dg.Ten) == 0) {
        return 0;
    }
    if (dg.phai != 0 && dg.phai != 1) {
        return 0;
    }
    if (dg.trangthai != 0 && dg.trangthai != 1) {
        return 0;
    }
    return 1;
}
int Input_0_1(int kt, int x, int y) {
    int key;
    int k = kt;
    Normal_Text();
    gotoxy(x, y);
    cout << k;
    do {
        key = GetKey();
        if (key == 48) {
            k = 0;
            gotoxy(x, y);
            cout << k;
        } else if (key == 49) {
            k = 1;
            gotoxy(x, y);
            cout << k;
        } else if (key == BACKSPACE) {
            k = NULL;
            gotoxy(x, y);
            cout << " ";
        } else if (key == ENTER || key == TAB || key == UP || key == DOWN) {
            HighLight_Text();
            gotoxy(x, y);
            cout << k;
            return k;
        }
    } while (k < 9);

}
int Input_0_1_2(int kt, int x, int y) {
    int key;
    int k = kt;
    Normal_Text();
    gotoxy(x, y);
    cout << k;
    do {
        key = GetKey();
        if (key == 48) {
            k = 0;
            gotoxy(x, y);
            cout << k;
        } else if (key == 49) {
            k = 1;
            gotoxy(x, y);
            cout << k;
        } else if (key == 50) {
            k = 2;
            gotoxy(x, y);
            cout << k;
        } else if (key == BACKSPACE) {
            k = NULL;
            gotoxy(x, y);
            cout << " ";
        } else if (key == ENTER || key == TAB || key == UP || key == DOWN) {
            HighLight_Text();
            gotoxy(x, y);
            cout << k;
            return k;
        }
    } while (k < 9);

}
int Input_Int(int kt, int x, int y) {
    int key;
    int k = kt;
    Normal_Text();
    gotoxy(x, y);
    cout << k;
    do {
        key = GetKey();
        if (key >= 48 && key <= 57) {
            k = k * 10 + (key - 48);
            gotoxy(x, y);
            cout << k;
        } else if (key == BACKSPACE) {
            k = k / 10;
            gotoxy(x, y);
            cout << "                   ";
            gotoxy(x, y);
            cout << k;
        } else if (key == ENTER || key == TAB || key == UP || key == DOWN) {
            HighLight_Text();
            gotoxy(x, y);
            cout << k;
            return k;
        }
    } while (1);

}
int Input_Int_99999(int kt, int x, int y) {
    int key;
    int k = kt;

    Normal_Text();
    gotoxy(x, y);
    cout << k;
    do {
        key = GetKey();
        if (key >= 48 && key <= 57 && k < 99999) {
            k = k * 10 + (key - 48);
            gotoxy(x, y);
            cout << k;
        } else if (key == BACKSPACE) {
            k = k / 10;
            gotoxy(x, y);
            cout << "                   ";
            gotoxy(x, y);
            cout << k;
        } else if (key == ESC) {
            gotoxy(x, y);
            cout << k;
            return k;
        } else if (key == ENTER || key == TAB || key == UP || key == DOWN) {
            if (k >= 10000 && k <= 99999) {
                HighLight_Text();
                gotoxy(x, y);
                cout << k;
                return k;
            } else {
                gotoxy(x, y);
                printf("MA DOC GIA CHUA DUNG!");
                Sleep(1000);
                gotoxy(x, y);
                printf("                     ");
                gotoxy(x, y);
                cout << k;
            }

        }
    } while (1);
}
enum DG_detail {
    MA_DG,
    HO_DG,
    TEN_DG,
    PHAI_DG,
    TRANGTHAI_DG
};
//========================THEM 1 DG MOI ========================
void Add_1_DG(NodeDG p) {
    DG_detail dg_detail = HO_DG;
    DocGia dg = DocGia();
    int chon = 0;
    char data[40];
    dg.Mathe = Random_MaDG(p);
    //clear data view 
    gotoxy(88, 7);
    printf("                         ");
    gotoxy(88, 9);
    printf("                         ");
    gotoxy(88, 11);
    printf("                         ");
    gotoxy(88, 13);
    printf("    (1: NAM, 0: NU)      ");
    gotoxy(88, 15);
    printf("    (1: ACTIVE, 0: BLOCK)");
    gotoxy(88, 7);
    cout << dg.Mathe;
    do {
        gotoxy(88, 9 + chon * 2);
        if (wherey() == 9) {
            cout << dg.Ho;
            char str[sizeof(dg.Ho)] = "";
            strcpy(str, dg.Ho);
            strcpy(dg.Ho, Input_Str(str, 88, 9 + chon * 2, sizeof(dg.Ho) - 1));
        } else if (wherey() == 11) {
            cout << dg.Ten;
            char str[sizeof(dg.Ten)] = "";
            strcpy(str, dg.Ten);
            strcpy(dg.Ten, Input_Str(str, 88, 9 + chon * 2, sizeof(dg.Ten) - 1));
        } else if (wherey() == 13) {
            gotoxy(88, 9 + chon * 2);
            cout << dg.phai;
            dg.phai = Input_0_1(dg.phai, 88, 9 + chon * 2);
        } else if (wherey() == 15) {
            gotoxy(88, 9 + chon * 2);
            cout << dg.trangthai;
            dg.trangthai = Input_0_1(dg.trangthai, 88, 9 + chon * 2);
        }
        int key = GetKey();
        switch (key) {
        case UP:
            if (chon > 0) {
                chon--;
            }
            break;
        case DOWN:
            if (chon + 1 < 4) {
                chon++;
            }
            break;
        case ENTER:
            if (chon + 1 < 4) {
                chon++;
            }
            break;
        case TAB:
            if (chon + 1 < 4) {
                chon++;
            }
            break;
        case CTRL_S:
            if (Check_Inp_DG(dg) == 1) {
                Insert_DG(p, dg);
                Save_Tree_File(p);
                //Read_Tree_File(p);

                //=======thong bao them thanh cong==========
                gotoxy(76, 19);
                Normal_Text();
                cout << "THEM DOC GIA THANH CONG!";
                Sleep(2000);
                gotoxy(76, 19);
                Normal_Text();
                cout << "                               ";
                gotoxy(88, 9 + chon * 2);
                return;
            } else {
                gotoxy(76, 19);
                HighLight_Text();
                cout << "DU LIEU NHAP VAO CHUA DUNG!";
                Sleep(2000);
                gotoxy(76, 19);
                Normal_Text();
                cout << "                            ";
                gotoxy(88, 9 + chon * 2);
                break;
            }

            case ESC:
                return;
        }

    } while (1);
    //	gotoxy(88,7); cout<<dg.Mathe;
    //	gotoxy(88,9); cin>>dg.Ho;
    //	gotoxy(88,11); cin>>dg.Ten;
    //	gotoxy(88,13); cin>>dg.phai;
    //	gotoxy(88,15); cin>>dg.trangthai;
}
//=============================EDIT 1 DG===============================
void Edit_1_DG(DocGia & dg, NodeDG & p) {
    int chon = 0;
    char data[40];
    //clear data view 
    Normal_Text();
    gotoxy(75, 19);
    cout << "DANG CHINH SUA! CTR+S DE LUU.!";
    HighLight_Text();
    gotoxy(88, 7);
    printf("                         ");
    gotoxy(88, 9);
    printf("                         ");
    gotoxy(88, 11);
    printf("                         ");
    gotoxy(88, 13);
    printf("    (1: NAM, 0: NU)      ");
    gotoxy(88, 15);
    printf("    (1: ACTIVE, 0: BLOCK)");

    gotoxy(88, 7);
    cout << dg.Mathe;
    gotoxy(88, 9);
    cout << dg.Ho;
    gotoxy(88, 11);
    cout << dg.Ten;
    gotoxy(88, 13);
    cout << dg.phai;
    gotoxy(88, 15);
    cout << dg.trangthai;

    do {

        gotoxy(88, 9 + chon * 2);
        if (wherey() == 9) {
            cout << dg.Ho;
            char str[sizeof(dg.Ho)] = "";
            strcpy(str, dg.Ho);
            strcpy(dg.Ho, Input_Str(str, 88, 9 + chon * 2, sizeof(dg.Ho) - 1));
        } else if (wherey() == 11) {
            cout << dg.Ten;
            char str[sizeof(dg.Ten)] = "";
            strcpy(str, dg.Ten);
            strcpy(dg.Ten, Input_Str(str, 88, 9 + chon * 2, sizeof(dg.Ten) - 1));
        } else if (wherey() == 13) {
            gotoxy(88, 9 + chon * 2);
            cout << dg.phai;
            dg.phai = Input_0_1(dg.phai, 88, 9 + chon * 2);
        } else if (wherey() == 15) {
            gotoxy(88, 9 + chon * 2);
            cout << dg.trangthai;
            dg.trangthai = Input_0_1(dg.trangthai, 88, 9 + chon * 2);
        }
        int key = GetKey();
        switch (key) {
        case UP:
            if (chon > 0) {
                chon--;
            }
            break;
        case DOWN:
            if (chon + 1 < 4) {
                chon++;
            }
            break;
        case ENTER:
            if (chon + 1 < 4) {
                chon++;
            }
            break;
        case TAB:
            if (chon + 1 < 4) {
                chon++;
            }
            break;
        case CTRL_S:
            if (Check_Inp_DG(dg) == 1) {
                gotoxy(75, 19);
                //Update_DG(p, dg);
                HighLight();
                cout << "  CHINH SUA DOC GIA THANH CONG!  ";
                Sleep(2000);
                gotoxy(75, 19);
                Normal_Text();
                cout << "                                 ";
                return;
            } else {
                gotoxy(75, 19);
                HighLight();
                cout << "   DU LIEU NHAP VAO CHUA DUNG!    ";
                Sleep(2000);
                gotoxy(75, 19);
                Normal_Text();
                cout << "                                  ";
                gotoxy(88, 9 + chon * 2);
                break;
            }

            case ESC:
                return;
        }

    } while (1);
}

int Check_MuonSach(DocGia * dg) {
    for (NodeMuonTra * p = dg -> dsmt.First; p != NULL; p = p -> next) {
        if (p -> muontra.trangthai == 0) {
            return 0;
        }
    }
    return 1;
}

enum Mode { // mode la gia tri co dinh
    MA_THE,
    HO_TEN
};
void Draw_Case_1() {
    int x = 1, y = 6, rong_title = 3, dai = 70, rong = rong_title + sodong_dsdg - 1;
    Mode mode;
    mode = MA_THE;
    //=================xu li giao dien====================
    system("cls");
    ColorAll();
    Draw_frame_Main(0, 0, X, Y); // ve lai khung, de tao case 1
    Draw_frame(x, y, dai, rong);
    Draw_fram_view_case1();
    //ColorAll();
    Draw_Title_Case1(x, y, dai);
    //==================== khoi tao cay=================
    DocGia dg;
    NodeDG tree;
    DanhSach_DG dsdg;
    Init_Tree(tree);
    Read_Tree_File(tree);
    dsdg.Reset_DSDG();
    dsdg.Insert_DG_to_DSDG(tree);
    //dsdg.Get_DSDG_QuaHan(tree);

    //========PHAN TRANG==========
    sl_page = 0; // tong so luong trang	 
    if (dsdg.n % sodong_dsdg == 0) {
        sl_page = dsdg.n / sodong_dsdg;
    } else {
        sl_page = dsdg.n / sodong_dsdg + 1;
    }
    int page_hientai = 0; // trang hien tai
    //int sodong_page=sodong_dsdg;//so dong hien tai cua trang hien tai (<=sodong_dsdg)

    //=========hien ds doc gia=========
    int chon = 0;
    char key;
    int so_item;
    if (dsdg.n < sodong_dsdg) {
        so_item = dsdg.n;
    } else {
        so_item = sodong_dsdg;
    }
    Draw_Button_Sort_Mathe(x, y - 3);
    Show_DSDG(dsdg, page_hientai, x, y + rong_title, so_item);

    do {
        key = GetKey();
        switch (key) {
        case UP:
            if (chon > 0) {
                Normal_Text();
                Draw_1_DG( * dsdg.DG[page_hientai * sodong_dsdg + chon], x, y + rong_title + chon);
                chon--;
                HighLight_Text();
                Draw_1_DG( * dsdg.DG[page_hientai * sodong_dsdg + chon], x, y + rong_title + chon);
            }
            break;
        case DOWN:
            if (chon + 1 < so_item) {
                Normal_Text();
                Draw_1_DG( * dsdg.DG[page_hientai * sodong_dsdg + chon], x, y + 3 + chon);
                chon++;
                HighLight_Text();
                Draw_1_DG( * dsdg.DG[page_hientai * sodong_dsdg + chon], x, y + 3 + chon);
            }
            break;
        case LEFT:
            if (page_hientai > 0) {
                if (dsdg.n < sodong_dsdg) {
                    so_item = dsdg.n;
                } else {
                    so_item = sodong_dsdg;
                }
                page_hientai--;
                Show_DSDG(dsdg, page_hientai, x, y + rong_title, so_item);
                chon = 0;
            }
            break;
        case RIGHT:
            if (page_hientai + 1 < sl_page) {
                if (page_hientai + 2 == sl_page) {
                    so_item = dsdg.n - (sodong_dsdg * (page_hientai + 1));
                } else {
                    so_item = sodong_dsdg;
                }
                page_hientai++;
                gotoxy(90, y - 3);

                Show_DSDG(dsdg, page_hientai, x, y + rong_title, so_item);
                chon = 0; //phai tra con tro ve 0 neu khong nguoi dung tro den cuoi dong va chuyen qua trang khac thi se bi loi
            }
            break;

        case F1:
            if (mode != MA_THE) {
                Normal_Text();
                dsdg.Sort_DSDG_Mathe();
                Draw_Button_Sort_Mathe(x, y - 3);
                page_hientai = 0;
                if (dsdg.n < sodong_dsdg) {
                    so_item = dsdg.n;
                } else {
                    so_item = sodong_dsdg;
                }
                Show_DSDG(dsdg, page_hientai, x, y + rong_title, so_item);
                chon = 0; // dua con tro ve vi tri hang dau tien
                mode = MA_THE;
                break;
            } else {
                //ColorAll();
                Normal_Text();
                dsdg.Sort_DSDG_Ten();
                Draw_Button_Sort_HoTen(x, y - 3);
                page_hientai = 0;
                if (dsdg.n < sodong_dsdg) {
                    so_item = dsdg.n;
                } else {
                    so_item = sodong_dsdg;
                }
                Show_DSDG(dsdg, page_hientai, x, y + rong_title, so_item);
                chon = 0; // dua con tro ve vi tri hang dau tien
                mode = HO_TEN;
                break;
            }
            //ColorAll();
            case F2:
                //DocGia dg;
                Add_1_DG(tree);
                dsdg.Reset_DSDG();
                dsdg.Insert_DG_to_DSDG(tree);

                //===============cap nhat sl page==================
                if (dsdg.n % sodong_dsdg == 0) {
                    sl_page = dsdg.n / sodong_dsdg;
                } else {
                    sl_page = dsdg.n / sodong_dsdg + 1;
                }
                Normal_Text();
                dsdg.Sort_DSDG_Mathe();
                Draw_Button_Sort_Mathe(x, y - 3);
                page_hientai = 0;
                if (dsdg.n < sodong_dsdg) {
                    so_item = dsdg.n;
                } else {
                    so_item = sodong_dsdg;
                }
                Show_DSDG(dsdg, page_hientai, x, y + rong_title, so_item);
                chon = 0; // dua con tro ve vi tri hang dau tien
                break;
            case F3:
                //DocGia dg;
                Edit_1_DG( * dsdg.DG[page_hientai * sodong_dsdg + chon], tree);
                Save_Tree_File(tree);
                //Read_Tree_File(tree);
                //===============cap nhat sl page==================
                if (dsdg.n % sodong_dsdg == 0) {
                    sl_page = dsdg.n / sodong_dsdg;
                } else {
                    sl_page = dsdg.n / sodong_dsdg + 1;
                }
                Normal_Text();
                dsdg.Sort_DSDG_Ten();
                Draw_Button_Sort_Mathe(x, y - 3);
                page_hientai = 0;
                if (dsdg.n < sodong_dsdg) {
                    so_item = dsdg.n;
                } else {
                    so_item = sodong_dsdg;
                }
                Show_DSDG(dsdg, page_hientai, x, y + rong_title, so_item);
                chon = 0; // dua con tro ve vi tri hang dau tien
                break;
            case DEL:
                //DocGia dg;>
                if (Check_MuonSach(dsdg.DG[page_hientai * sodong_dsdg + chon]) == 1) {
                    if (Dialog_Mess_Box(74, 20, "BAN CO CHAC CHAN MUON XOA?") == 1) {
                        Remove_DG(tree, dsdg.DG[page_hientai * sodong_dsdg + chon] -> Mathe);
                        Save_Tree_File(tree);
                        //Read_Tree_File(tree);
                        dsdg.Reset_DSDG();
                        dsdg.Insert_DG_to_DSDG(tree);

                        //===============cap nhat sl page==================
                        if (dsdg.n % sodong_dsdg == 0) {
                            sl_page = dsdg.n / sodong_dsdg;
                        } else {
                            sl_page = dsdg.n / sodong_dsdg + 1;
                        }
                        Normal_Text();
                        dsdg.Sort_DSDG_Mathe();
                        Draw_Button_Sort_Mathe(x, y - 3);
                        page_hientai = 0;
                        if (dsdg.n < sodong_dsdg) {
                            so_item = dsdg.n;
                        } else {
                            so_item = sodong_dsdg;
                        }
                        Show_DSDG(dsdg, page_hientai, x, y + rong_title, so_item);
                        chon = 0; // dua con tro ve vi tri hang dau tien
                    }
                } else {
                    HighLight();
                    gotoxy(74, 20);
                    printf("DOC GIA DANG MUON SACH, KHONG THE XOA");
                    Sleep(1000);
                    Normal_Text();
                    gotoxy(74, 20);
                    printf("                                     ");
                }

                break;

            case ESC:
                DeleteMemoryDocGia(tree);
                delete dsdg.DG;
                return;
        }
        // end switch
    } while (1);

}
//========================================MENU CASE 2=========================================================================
//============================================================================================================================
const int sodong_dsds = 17,
    sodong_dsdms = 20;
void Draw_Title_Case2(int x, int y, int dai) {
    Normal_Text(); //khung tim kiem
    gotoxy(3, 4);
    printf("TIM KIEM: ");
    Draw_frame(13, 3, 40, 1);
    Draw_H(x, y + 2, dai);
    //Ma ISBN
    gotoXY(x + 1, y + 1);
    printf("%s %c", "MA ISBN", 186);
    //Ten Sach
    gotoXY(x + 9, y);
    printf("%c", 203);
    gotoXY(x + 9, y + 2);
    printf("%c", 206);
    gotoXY(x + 12, y + 1);
    printf("%s %c", "        TEN SACH       ", 186);
    //Ten
    gotoXY(x + 36, y);
    printf("%c", 203);
    gotoXY(x + 36, y + 2);
    printf("%c", 206);
    gotoXY(x + 37, y + 1);
    printf("%s %c", " TEN TAC GIA  ", 186);
    //Phai
    gotoXY(x + 52, y);
    printf("%c", 203);
    gotoXY(x + 52, y + 2);
    printf("%c", 206);
    gotoXY(x + 54, y + 1);
    printf("%s %c", " THE LOAI ", 186);
    //Phai
    gotoXY(x + 65, y);
    printf("%c", 203);
    gotoXY(x + 65, y + 2);
    printf("%c", 206);
    gotoXY(x + 67, y + 1);
    printf("%s %c", "NXB", 186);
    //Trang thai
    gotoXY(x + 71, y);
    printf("%c", 203);
    gotoXY(x + 71, y + 2);
    printf("%c", 206);
    gotoXY(x + 72, y + 1);
    printf("%s", "SO TRg");
    //ve hang phan cach

    for (int i = y + 3; i < y + sodong_dsdg + 3; i++) {
        gotoXY(x + 9, i);
        printf("%c", 186);
        gotoXY(x + 36, i);
        printf("%c", 186);
        gotoXY(x + 52, i);
        printf("%c", 186);
        gotoXY(x + 65, i);
        printf("%c", 186);
        gotoXY(x + 71, i);
        printf("%c", 186);
    }
    gotoXY(x + 9, y + sodong_dsdg + 3);
    printf("%c", 202);
    gotoXY(x + 36, y + sodong_dsdg + 3);
    printf("%c", 202);
    gotoXY(x + 52, y + sodong_dsdg + 3);
    printf("%c", 202);
    gotoXY(x + 65, y + sodong_dsdg + 3);
    printf("%c", 202);
    gotoXY(x + 71, y + sodong_dsdg + 3);
    printf("%c", 202);
    //==========guide================

    gotoxy(96, y + sodong_dsdg + 3);
    HighLight();
    printf(" F11 ");
    Normal();
    printf(" TIM KIEM");

    gotoxy(80, y + sodong_dsdg + 3);
    HighLight();
    printf(" F2 ");
    Normal();
    printf(" THEM MOI");

    gotoxy(80, y + sodong_dsdg + 5);

    HighLight();
    printf(" F3 ");
    Normal();
    printf(" CHINH SUA");

    gotoxy(96, y + sodong_dsdg + 5);

    HighLight();
    printf(" CTRL_S ");
    Normal();
    printf(" LUU");

    Normal_Text();
}
void Draw_fram_view_case2() {
    //==================================VE KHUNG NHO BEN PHAI=======================
    int x_view = 80, y_view = 6, dai_view = 37, rong_view = 11;
    Normal_Text();
    Draw_frame(x_view, y_view, dai_view, rong_view);
    Draw_H(x_view, y_view + 2, dai_view);
    Draw_H(x_view, y_view + 4, dai_view);
    Draw_H(x_view, y_view + 6, dai_view);
    Draw_H(x_view, y_view + 8, dai_view);
    Draw_H(x_view, y_view + 10, dai_view);
    gotoxy(x_view + 1, y_view + 1);
    printf(" MA ISBN");
    gotoxy(x_view + 12, y_view);
    printf("%c", 203);
    gotoxy(x_view + 12, y_view + 1);
    printf("%c", 186);
    gotoxy(x_view + 12, y_view + 2);
    printf("%c", 206);
    gotoxy(x_view + 1, y_view + 3);
    printf(" TEN SACH");
    gotoxy(x_view + 12, y_view + 3);
    printf("%c", 186);
    gotoxy(x_view + 12, y_view + 4);
    printf("%c", 206);
    gotoxy(x_view + 1, y_view + 5);
    printf("TEN TAC GIA");
    gotoxy(x_view + 12, y_view + 5);
    printf("%c", 186);
    gotoxy(x_view + 12, y_view + 6);
    printf("%c", 206);
    gotoxy(x_view + 1, y_view + 7);
    printf(" THE LOAI");
    gotoxy(x_view + 12, y_view + 7);
    printf("%c", 186);
    gotoxy(x_view + 12, y_view + 8);
    printf("%c", 206);
    gotoxy(x_view + 1, y_view + 9);
    printf("   NXB");
    gotoxy(x_view + 12, y_view + 9);
    printf("%c", 186);
    gotoxy(x_view + 12, y_view + 10);
    printf("%c", 206);
    gotoxy(x_view + 1, y_view + 11);
    printf(" SO TRANG");
    gotoxy(x_view + 12, y_view + 11);
    printf("%c", 186);
    gotoxy(x_view + 12, y_view + 12);
    printf("%c", 202);

}

char * Get_ISBN(char str[]) {
    char str1[6] = "";
    int size = strlen(str) - 1, size1 = 0;
    int i = 0;
    str1[size1] = char(str[size1]);
    if (size > 5) {
        for (i = 1; i < size - 1; i++) {
            if (str[i] == char(255) && str[i + 1] != char(255)) {
                size1++;
                str1[size1] = char(str[i + 1]);
            }
            if (strlen(str1) + 2 > sizeof(str1)) {
                return str1;
            }
        }
    } else {
        for (i = 1; i < size - 1; i++) {
            if (str[i] != char(255)) {
                size1++;
                str1[size1] = char(str[i]);
            }
            if (strlen(str1) >= sizeof(str1)) {
                return str1;
            }
        }
    }
    srand(time(0));
    if (size1 < 4) {
        while (size1 + 2 < sizeof(str1)) {
            int k = rand() % 10 + 48;
            size1++;
            str1[size1] = char(k);
        }
    }
    return str1;
}
char * Get_ISBN_from_MaSach(char masach[]) {
    char str[10] = "";
    int size_str = -1;
    while (size_str < 6) {
        size_str++;
        if (masach[size_str] != 45 && size_str + 1 < strlen(masach)) {
            str[size_str] = masach[size_str];
        } else {
            return str;
        }
    }
    return str;
}
int Input_Year(int kt, int x, int y) {
    int key, year_cur;
    int k = kt;

    time_t t = time(NULL);
    tm * timePtr = localtime( & t);
    year_cur = timePtr -> tm_year + 1900;
    Normal_Text();
    gotoxy(x, y);
    cout << k;
    do {
        key = GetKey();
        if (key >= 48 && key <= 57 && k < 999) {
            k = k * 10 + (key - 48);
            gotoxy(x, y);
            cout << k;
        } else if (key == BACKSPACE) {
            k = k / 10;
            gotoxy(x, y);
            cout << "                   ";
            gotoxy(x, y);
            cout << k;
        } else if (key == ENTER || key == TAB || key == UP || key == DOWN) {
            if (k > 1700 && k <= year_cur) {
                HighLight_Text();
                gotoxy(x, y);
                cout << k;
                return k;
            } else {
                gotoxy(x, y);
                printf("NAM CHUA DUNG!");
                Sleep(1000);
                gotoxy(x, y);
                printf("              ");
                gotoxy(x, y);
                cout << k;
            }

        }
    } while (1);
}
int Check_DS(DauSach ds, DS_DauSach dsds) {
    if (strcmp(ds.ISBN, "") == 0) {
        return 0;
    }
    if (strcmp(ds.Tensach, "") == 0) {
        return 0;
    }
    if (strcmp(ds.Tacgia, "") == 0) {
        return 0;
    }
    if (ds.Nxb < 1700) {
        return 0;
    }
    if (ds.Sotrang < 2) {
        return 0;
    }
    return 1;

}
void Add_1_DS(DS_DauSach & dsds) {
    DauSach dausach = DauSach();
    dausach.pNext = NULL;
    int chon = 0;
    char data[40];
    //clear data view 
    gotoxy(93, 7);
    printf("                        ");
    gotoxy(93, 9);
    printf("                        ");
    gotoxy(93, 11);
    printf("                        ");
    gotoxy(93, 13);
    printf("                        ");
    gotoxy(93, 15);
    printf("                        ");
    gotoxy(93, 17);
    printf("                        ");
    do {
        gotoxy(93, 7 + chon * 2);
        if (wherey() == 7) {
            cout << dausach.ISBN;
            char str[sizeof(dausach.ISBN)] = "";
            strcpy(str, dausach.ISBN);
            strcpy(dausach.ISBN, Input_Str(str, 93, 7 + chon * 2, sizeof(dausach.ISBN) - 1));
        } else if (wherey() == 9) {
            cout << dausach.Tensach;
            char str[sizeof(dausach.Tensach)] = "";
            strcpy(str, dausach.Tensach);
            strcpy(dausach.Tensach, Input_Str(str, 93, 7 + chon * 2, sizeof(dausach.Tensach) - 1));
            strcpy(str, dausach.Tensach);
            if (strcmp(dausach.ISBN, "") == 0) {
                char str1[5] = "";
                strcpy(str1, Get_ISBN(dausach.Tensach));
                strcpy(dausach.ISBN, str1);
                gotoxy(93, 7);
                cout << dausach.ISBN;
                gotoxy(93, 9);
                cout << dausach.Tensach;
            }

        } else if (wherey() == 11) {
            cout << dausach.Tacgia;
            char str[sizeof(dausach.Tacgia)] = "";
            strcpy(str, dausach.Tacgia);
            strcpy(dausach.Tacgia, Input_Str(str, 93, 7 + chon * 2, sizeof(dausach.Tacgia) - 1));
        } else if (wherey() == 13) {
            cout << dausach.Theloai;
            char str[sizeof(dausach.Theloai)] = "";
            strcpy(str, dausach.Theloai);
            strcpy(dausach.Theloai, Input_Str(str, 93, 7 + chon * 2, sizeof(dausach.Theloai) - 1));
        } else if (wherey() == 15) {
            cout << dausach.Nxb;
            dausach.Nxb = Input_Year(dausach.Nxb, 93, 7 + chon * 2);
        } else if (wherey() == 17) {
            cout << dausach.Sotrang;
            dausach.Sotrang = Input_Int(dausach.Sotrang, 93, 7 + chon * 2);
        }
        int key = GetKey();
        switch (key) {
        case UP:
            if (chon > 0) {
                chon--;
            }
            break;
        case DOWN:
            if (chon + 1 < 6) {
                chon++;
            }
            break;
        case ENTER:
            if (chon + 1 < 6) {
                chon++;
            }
            break;
        case TAB:
            if (chon + 1 < 6) {
                chon++;
            }
            break;
        case CTRL_S:
            if (strcmp(dausach.ISBN, "") == 0) {
                char str[6] = "";
                strcpy(str, Get_ISBN(dausach.Tensach));
                strcpy(dausach.ISBN, str);
            }
            for (int i = 0; i < dsds.n; i++) {
                if (strcmp(dsds.node[i] -> ISBN, dausach.ISBN) == 0) {
                    gotoxy(81, 19);
                    printf("MA ISBN BI TRUNG!");
                    gotoxy(81, 19);
                    Sleep(1000);
                    printf("                 ");
                    gotoxy(93, 7);
                    printf("                 ");
                    strcpy(dausach.ISBN, "");
                    chon = 0;
                    break;
                }
            }
            if (Check_DS(dausach, dsds) == 1) {
                Add_DauSach(dsds, dausach);
                Save_DS_DauSach_File(dsds);
                //Read_DS_DauSach_File(dsds);
                gotoxy(81, 19);
                printf("THEM DAU SACH THANH CONG!");
                gotoxy(81, 19);
                Sleep(2000);
                printf("                         ");
                return;
            } else {
                gotoxy(81, 19);
                printf("LOI DU LIEU! KHONG THE THEM SACH");
                gotoxy(81, 19);
                Sleep(2000);
                printf("                                ");
            }
            break;

        case ESC:
            return;
        }

    } while (1);
}
void Edit_1_DS(DS_DauSach & dsds, DauSach & dausach) {
    int chon = 0;
    DauSach ds = dausach;
    char data[40];
    //clear data view 
    gotoxy(93, 7);
    cout << dausach.ISBN;
    gotoxy(93, 9);
    cout << dausach.Tensach;
    gotoxy(93, 11);
    cout << dausach.Tacgia;
    gotoxy(93, 13);
    cout << dausach.Theloai;
    gotoxy(93, 15);
    cout << dausach.Nxb;
    gotoxy(93, 17);
    cout << dausach.Sotrang;
    do {
        gotoxy(93, 9 + chon * 2);
        if (wherey() == 9) {
            cout << dausach.Tensach;
            char str[sizeof(dausach.Tensach)] = "";
            strcpy(str, dausach.Tensach);
            strcpy(dausach.Tensach, Input_Str(str, 93, 9 + chon * 2, sizeof(dausach.Tensach) - 1));
        } else if (wherey() == 11) {
            cout << dausach.Tacgia;
            char str[sizeof(dausach.Tacgia)] = "";
            strcpy(str, dausach.Tacgia);
            strcpy(dausach.Tacgia, Input_Str(str, 93, 9 + chon * 2, sizeof(dausach.Tacgia) - 1));
        } else if (wherey() == 13) {
            cout << dausach.Theloai;
            char str[sizeof(dausach.Theloai)] = "";
            strcpy(str, dausach.Theloai);
            strcpy(dausach.Theloai, Input_Str(str, 93, 9 + chon * 2, sizeof(dausach.Theloai) - 1));
        } else if (wherey() == 15) {
            cout << dausach.Nxb;
            dausach.Nxb = Input_Year(dausach.Nxb, 93, 9 + chon * 2);
        } else if (wherey() == 17) {
            cout << dausach.Sotrang;
            dausach.Sotrang = Input_Int(dausach.Sotrang, 93, 9 + chon * 2);
        }
        int key = GetKey();
        switch (key) {
        case UP:
            if (chon > 0) {
                chon--;
            }
            break;
        case DOWN:
            if (chon + 1 < 5) {
                chon++;
            }
            break;
        case ENTER:
            if (chon + 1 < 5) {
                chon++;
            }
            break;
        case TAB:
            if (chon + 1 < 5) {
                chon++;
            }
            break;
        case CTRL_S:
            if (Check_DS(dausach, dsds) == 1) {
                Save_DS_DauSach_File(dsds);
                Read_DS_DauSach_File(dsds);
                gotoxy(81, 19);
                printf("CHINH SUA DAU SACH THANH CONG!");
                gotoxy(81, 19);
                Sleep(2000);
                printf("                              ");
                return;
            } else {
                gotoxy(81, 19);
                printf("LOI DU LIEU!");
                gotoxy(81, 19);
                Sleep(2000);
                printf("                 ");
            }
            break;

        case ESC:
            dausach = ds;
            return;
        }

    } while (1);
}
void Draw_1_DauSach_View(DauSach ds) {
    int x_view = 79, y_view = 6, dai_view = 37, rong_view = 11;
    gotoxy(x_view + 14, y_view + 1);
    printf("                        ");
    gotoxy(x_view + 14, y_view + 3);
    printf("                        ");
    gotoxy(x_view + 14, y_view + 5);
    printf("                        ");
    gotoxy(x_view + 14, y_view + 7);
    printf("                        ");
    gotoxy(x_view + 14, y_view + 9);
    printf("                        ");
    gotoxy(x_view + 14, y_view + 11);
    printf("                        ");

    gotoxy(x_view + 14, y_view + 1);
    printf("%s", ds.ISBN);
    gotoxy(x_view + 14, y_view + 3);
    printf("%s", ds.Tensach);
    gotoxy(x_view + 14, y_view + 5);
    printf("%s", ds.Tacgia);
    gotoxy(x_view + 14, y_view + 7);
    printf("%s", ds.Theloai);
    gotoxy(x_view + 14, y_view + 9);
    printf("%d", ds.Nxb);
    gotoxy(x_view + 14, y_view + 11);
    printf("%d", ds.Sotrang);
}

void Draw_1_DauSach(DauSach ds, int x, int y) {
    Draw_1_DauSach_View(ds);
    gotoxy(x + 1, y);
    printf("%s", ds.ISBN);
    gotoxy(x + 10, y);
    printf("%s", ds.Tensach);
    gotoxy(x + 37, y);
    printf("%s", ds.Tacgia);
    gotoxy(x + 53, y);
    printf("%s", ds.Theloai);
    gotoxy(x + 66, y);
    printf("%d", ds.Nxb);
    gotoxy(x + 72, y);
    printf("%d", ds.Sotrang);
}
void Clear_DSDS(int x, int y, int dai, int rong) {
    Normal_Text();
    for (int i = x + 1; i < x + dai; i++) {
        for (int j = y; j < y + rong; j++) {
            gotoxy(i, j);
            printf(" ");
        }
    }
    Draw_Title_Case2(x, y - 3, dai); //-3 do title
}
void Show_DSDS(DS_DauSach ds, int page_hientai, int x, int y, int sodong) { // hien thi dsdg cua 1 trang
    Normal_Text();
    Clear_DSDS(x, y, 77, sodong_dsds);
    for (int i = page_hientai * sodong_dsdg; i < page_hientai * sodong_dsdg + sodong; i++) {
        Draw_1_DauSach( * ds.node[i], x, y + (i - page_hientai * sodong_dsdg));
    }
    //================page hien tai / sl page vi du trang 5/6==================
    gotoxy((x + 60) / 2, y + sodong_dsdg + 2);
    printf("Trang ");
    HighLight();
    printf("%d / %d", page_hientai + 1, sl_page);
    Normal();
    //==============in dong dau tien=====================
    HighLight_Text();
    Draw_1_DauSach( * ds.node[page_hientai * sodong_dsdg], x, y);
}
//=========================================DRAW DANH MUC SACH CUA 1 DAU SACH==============================================================
//========================================================================================================================================
int Input_Int_99(int kt, int x, int y) {
    int key, year_cur;
    int k = kt;

    Normal_Text();
    gotoxy(x, y);
    cout << k;
    do {
        key = GetKey();
        if (key >= 48 && key <= 57 && k * 10 < 99) {
            k = k * 10 + (key - 48);
            gotoxy(x, y);
            cout << k << " sach";
        } else if (key == BACKSPACE) {
            k = k / 10;
            gotoxy(x, y);
            cout << "                   ";
            gotoxy(x, y);
            cout << k << " sach";
        } else if (key == ESC) {
            return 0;
        } else if (key == ENTER || key == TAB || key == UP || key == DOWN) {
            if (k == 0) {
                gotoxy(x, y);
                cout << "SO LUONG PHAI >0";
                Sleep(1000);
                gotoxy(x, y);
                cout << "                 ";
                gotoxy(x, y);
                cout << k << " sach";
            } else {
                HighLight_Text();
                gotoxy(x, y);
                cout << k << " sach";
                return k;
            }

        }
    } while (1);

}
char * Generate_MaSach(char ISBN[], int k) {
    char str[10] = "", str_temp[10] = "";
    strcpy(str, ISBN);
    int size = strlen(str) - 1, j = strlen(str_temp) - 1;
    size++;
    str[size] = char(45);
    while (k > 0) {
        j++;
        str_temp[j] = char((k % 10) + 48);
        k = k / 10;
    }
    for (int i = strlen(str_temp) - 1; i >= 0; i--) {
        size++;
        str[size] = str_temp[i];
    }
    return str;
}
void Draw_Title_DMS(int x, int y, int dai) {
    Draw_H(x, y + 2, dai);
    //Ma sach
    gotoXY(x + 1, y + 1);
    printf("%s %c", "   MA SACH  ", 186);
    //Vi tri
    gotoXY(x + 14, y);
    printf("%c", 203);
    gotoXY(x + 14, y + 2);
    printf("%c", 206);
    gotoXY(x + 16, y + 1);
    printf("%s %c", "                  VI TRI               ", 186);
    //Trang thai
    gotoXY(x + 56, y);
    printf("%c", 203);
    gotoXY(x + 56, y + 2);
    printf("%c", 206);
    gotoXY(x + 58, y + 1);
    printf("%s", "  TRANG THAI   ");

    for (int i = y + 3; i < y + sodong_dsdms + 3; i++) {
        gotoXY(x + 14, i);
        printf("%c", 186);
        gotoXY(x + 56, i);
        printf("%c", 186);
    }
    gotoXY(x + 14, y + sodong_dsdms + 3);
    printf("%c", 202);
    gotoXY(x + 56, y + sodong_dsdms + 3);
    printf("%c", 202);

    //==========guide================

    gotoxy(96, y + sodong_dsdg + 3);
    HighLight();
    printf(" DEL ");
    Normal();
    printf(" XOA");

    gotoxy(80, y + sodong_dsdg + 3);
    HighLight();
    printf(" F2 ");
    Normal();
    printf(" THEM MOI");

    gotoxy(80, y + sodong_dsdg + 5);

    HighLight();
    printf(" F3 ");
    Normal();
    printf(" CHINH SUA");

    gotoxy(96, y + sodong_dsdg + 5);

    HighLight();
    printf(" CTRL_S ");
    Normal();
    printf(" LUU");

    Normal_Text();
}
int sl_page_dms = 0;
void Draw_1_Sach(Sach sach, int x, int y) {
    gotoxy(x + 3, y);
    cout << sach.Masach;
    gotoxy(x + 16, y);
    cout << sach.Vitri;
    gotoxy(x + 58, y);
    if (sach.Trangthai == 0) {
        printf("CHO MUON DUOC");
    } else if (sach.Trangthai == 1) {
        printf("DA CHO MUON");
    } else {
        printf("DA THANH LY");
    }
}
void Clear_Screen_DMS(int x, int y, int dai, int rong) {

    Normal_Text();
    for (int i = x; i < x + dai + 1; i++) {
        for (int j = y; j < y + rong + 1; j++) {
            gotoxy(i, j);
            printf(" ");
        }
    }
    Draw_Title_DMS(x - 1, y - 3, 77);
}
void Show_DS_DMS(DS_DMS_MangConTro ds_dms, int page_hientai, int x, int y, int sodong) { // hien thi dsds cua 1 trang
    Normal_Text();
    Clear_Screen_DMS(x + 1, y, 75, 19);
    for (int i = page_hientai * sodong_dsdms; i < page_hientai * sodong_dsdms + sodong; i++) {
        Draw_1_Sach( * ds_dms.sach[i], x, y + (i - page_hientai * sodong_dsdms));
    }
    //================page hien tai / sl page vi du trang 5/6==================
    gotoxy((x + 65) / 2, y + sodong_dsdms + 2);
    printf("Trang ");
    HighLight();
    printf("%d / %d", page_hientai + 1, sl_page_dms);
    Normal();
    //==============in dong dau tien=====================
    HighLight_Text();
    Draw_1_Sach( * ds_dms.sach[page_hientai * sodong_dsdms], x, y);
}
void Draw_fram_view_Sach() {
    //==================================VE KHUNG NHO BEN PHAI=======================
    int x_view = 80, y_view = 6, dai_view = 37, rong_view = 5;
    Normal_Text();
    Draw_frame(x_view, y_view, dai_view, rong_view);
    Draw_H(x_view, y_view + 2, dai_view);
    Draw_H(x_view, y_view + 4, dai_view);
    gotoxy(x_view + 1, y_view + 1);
    printf(" MA SACH");
    gotoxy(x_view + 12, y_view);
    printf("%c", 203);
    gotoxy(x_view + 12, y_view + 1);
    printf("%c", 186);
    gotoxy(x_view + 12, y_view + 2);
    printf("%c", 206);
    gotoxy(x_view + 1, y_view + 3);
    printf("  VI TRI  ");
    gotoxy(x_view + 12, y_view + 3);
    printf("%c", 186);
    gotoxy(x_view + 12, y_view + 4);
    printf("%c", 206);
    gotoxy(x_view + 1, y_view + 5);
    printf("TRANG THAI");
    gotoxy(x_view + 12, y_view + 5);
    printf("%c", 186);
    gotoxy(x_view + 12, y_view + 6);
    printf("%c", 202);
}
int Check_1_sach(Sach sach) {
    if (strcmp(sach.Vitri, "") == 0) {
        Sleep(2000);
        return 0;
    }
    if (sach.Trangthai < 0 && sach.Trangthai > 2) {
        Sleep(2000);
        return 0;
    }
    if (strcmp(sach.Masach, "") == 0) {
        Sleep(2000);
        return 0;
    }
    return 1;
}
int Exist_masach(DauSach dausach, char masach[]){
	NodeSach * p = dausach.pNext;
	for(p = dausach.pNext; p!=NULL; p=p->pNext){
		if(strcmp(p->sach.Masach,masach)==0){
			//printf("%s----------",p->sach.Masach);
			return 0;
		}
	}
	return 1;
}
void Add_1_Sach(DauSach & dausach, DS_DMS_MangConTro & ds_dms) {
    Normal_Text();
    for (int i = 80; i < 119; i++) {
        for (int j = 3; j < 16; j++) {
            gotoxy(i, j);
            printf(" ");
        }
    }

    gotoxy(80, 4);
    printf("Nhap them: ");
    Draw_frame(90, 3, 20, 1);

    Sach sach;
    int n = 0; //so sach nhap them
    gotoxy(92, 4);
    n = Input_Int_99(n, 92, 4);

    int chon = 0;
    bool check = true;
    bool check_ms=false;
    int thutu =0;
    while (n > 0) {
        Draw_fram_view_Sach();
        gotoxy(93, 7);
        printf("                    ");
        gotoxy(93, 9);
        printf("                    ");
        gotoxy(93, 11);
        printf("                    ");
        thutu=0;
        check_ms=false;
		while(check_ms==false){
			strcpy(sach.Masach, Generate_MaSach(dausach.ISBN, dausach.Tongsoluongsach + thutu));
			if(Exist_masach(dausach,sach.Masach)==1){
				check_ms=true;
			}
			thutu++;
		}
        
        gotoxy(93, 7);
        cout << sach.Masach;
        n--;
        check = true;
        while (check == true) {
            gotoxy(93, 9 + chon * 2);
            if (wherey() == 9) {
                char str[sizeof(sach.Vitri)] = "";
                strcpy(str, sach.Vitri);
                strcpy(sach.Vitri, Input_Str_Int(str, 93, 9 + chon * 2, sizeof(sach.Vitri)));
            } else if (wherey() == 11) {
                sach.Trangthai = Input_0_1_2(sach.Trangthai, 93, 9 + chon * 2);
            }
            int key = GetKey();
            switch (key) {
            case UP:
                if (chon > 0) {
                    chon--;
                }
                break;
            case DOWN:
                if (chon + 1 < 2) {
                    chon++;
                }
                break;
            case ENTER:
                if (chon + 1 < 2) {
                    chon++;
                }
                break;
            case TAB:
                if (chon + 1 < 2) {
                    chon++;
                }
                break;
            case CTRL_S:
                if (Check_1_sach(sach) == 1) {
                    Insert_Sach_Last(dausach.pNext, sach);
                    dausach.Tongsoluongsach++;
                    int so_item_dms = 0;
                    if (dausach.Tongsoluongsach < sodong_dsdms) {
                        so_item_dms = dausach.Tongsoluongsach;
                    } else {
                        so_item_dms = sodong_dsdms;
                    }
                    if (dausach.Tongsoluongsach > 0) {
                        ds_dms.ResetDS_DMS();
                        ds_dms.Update_Sach_DS_DMS(dausach.pNext);
                    }
                    Show_DS_DMS(ds_dms, 0, 1, 6, so_item_dms);
                    chon = 0;
                    check = false;
                } else {
                    gotoxy(93, 14);
                    printf("LOI DU LIEU!");
                    Sleep(1000);
                    gotoxy(93, 14);
                    printf("              ");
                }
                break;
            case ESC:
                return;
            }

        }
    }

}
void Edit_1_Sach(DS_DMS_MangConTro & ds_dms, int vitri) {
    int chon = 0;
    bool check = true;
    check = true;
    Draw_fram_view_Sach();
    Sach * sach;
    sach = ds_dms.sach[vitri];
    gotoxy(93, 7);
    cout << sach -> Masach;
    gotoxy(93, 9);
    cout << sach -> Vitri;
    gotoxy(93, 11);
    cout << sach -> Trangthai;
    while (check == true) {
        gotoxy(93, 9 + chon * 2);
        if (wherey() == 9) {
            char str[sizeof(sach -> Vitri)] = "";
            strcpy(str, sach -> Vitri);
            strcpy(sach -> Vitri, Input_Str_Int(str, 93, 9 + chon * 2, sizeof(sach -> Vitri)));
        } else if (wherey() == 11) {
            sach -> Trangthai = Input_0_1_2(sach -> Trangthai, 93, 9 + chon * 2);
        }
        int key = GetKey();
        switch (key) {
        case UP:
            if (chon > 0) {
                chon--;
            }
            break;
        case DOWN:
            if (chon + 1 < 2) {
                chon++;
            }
            break;
        case ENTER:
            if (chon + 1 < 2) {
                chon++;
            }
            break;
        case TAB:
            if (chon + 1 < 2) {
                chon++;
            }
            break;
        case CTRL_S:
            if (Check_1_sach( * sach) == 1) {
                gotoxy(93, 14);
                HighLight();
                printf("CHINH SUA THANH CONG!");
                Sleep(1900);
                gotoxy(93, 14);
                Normal_Text();
                printf("                       ");
                check = false;
            } else {
                gotoxy(93, 14);
                printf("LOI DU LIEU!");
                Sleep(1000);
                gotoxy(93, 14);
                printf("              ");
            }
            break;
        case ESC:
            return;
        }

    }

}
void Draw_DS_DMS(DauSach & dausach) {
    int x = 1, y = 3, rong_title = 3, dai = 77, rong = rong_title + sodong_dsdms - 1;

    //=================xu li giao dien====================
    system("cls");
    ColorAll();
    Draw_frame_Main(0, 0, X, Y); // ve lai khung, de tao case 1
    Draw_frame(x, y, dai, rong);
    Draw_Title_DMS(x, y, dai);
    //=====================khoi tao du lieu====================
    DS_DMS_MangConTro ds_dms;
    if (dausach.Tongsoluongsach > 0) {
        ds_dms.Init_Ds_Dms_ISBN(dausach.Tongsoluongsach);
        ds_dms.Update_Sach_DS_DMS(dausach.pNext);
    }

    //========PHAN TRANG==========
    sl_page_dms = 0; // tong so luong trang	 
    if (dausach.Tongsoluongsach % sodong_dsdms == 0) {
        sl_page_dms = dausach.Tongsoluongsach / sodong_dsdms;
    } else {
        sl_page_dms = dausach.Tongsoluongsach / sodong_dsdms + 1;
    }
    //===========So item=============
    int so_item_dms;
    if (dausach.Tongsoluongsach < sodong_dsdms) {
        so_item_dms = dausach.Tongsoluongsach;
    } else {
        so_item_dms = sodong_dsdms;
    }
    int page_hientai = 0; // trang hien tai
    int chon = 0;
    int key;

    if (dausach.Tongsoluongsach > 0) {
        Show_DS_DMS(ds_dms, page_hientai, x, y + rong_title, so_item_dms);
    }
    while (1) {
        key = GetKey();
        switch (key) {
        case UP:
            if (chon > 0 && dausach.Tongsoluongsach > 0) {
                Normal_Text();
                Draw_1_Sach( * ds_dms.sach[page_hientai * sodong_dsdms + chon], x, y + rong_title + chon);
                chon--;
                HighLight_Text();
                Draw_1_Sach( * ds_dms.sach[page_hientai * sodong_dsdms + chon], x, y + rong_title + chon);
            }
            break;
        case DOWN:
            if (chon + 1 < so_item_dms && dausach.Tongsoluongsach > 0) {
                Normal_Text();
                Draw_1_Sach( * ds_dms.sach[page_hientai * sodong_dsdms + chon], x, y + rong_title + chon);
                chon++;
                HighLight_Text();
                Draw_1_Sach( * ds_dms.sach[page_hientai * sodong_dsdms + chon], x, y + rong_title + chon);
            }
            break;
        case LEFT:
            if (page_hientai > 0) {
                sl_page_dms = 0; // tong so luong trang	 
                if (dausach.Tongsoluongsach % sodong_dsdms == 0) {
                    sl_page_dms = dausach.Tongsoluongsach / sodong_dsdms;
                } else {
                    sl_page_dms = dausach.Tongsoluongsach / sodong_dsdms + 1;
                }
                //================================================
                if (dausach.Tongsoluongsach < sodong_dsdms) {
                    so_item_dms = dausach.Tongsoluongsach;
                } else {
                    so_item_dms = sodong_dsdms;
                }
                page_hientai--;
                Show_DS_DMS(ds_dms, page_hientai, x, y + rong_title, so_item_dms);
                chon = 0;
            }
            break;
        case RIGHT:
            if (page_hientai + 1 < sl_page_dms) {
                //========PHAN TRANG==========
                sl_page_dms = 0; // tong so luong trang	 
                if (dausach.Tongsoluongsach % sodong_dsdms == 0) {
                    sl_page_dms = dausach.Tongsoluongsach / sodong_dsdms;
                } else {
                    sl_page_dms = dausach.Tongsoluongsach / sodong_dsdms + 1;
                }
                //================================================
                if (page_hientai + 2 == sl_page_dms) {
                    so_item_dms = dausach.Tongsoluongsach - (sodong_dsdms * (page_hientai + 1));
                } else {
                    so_item_dms = sodong_dsdms;
                }
                page_hientai++;
                Show_DS_DMS(ds_dms, page_hientai, x, y + rong_title, so_item_dms);
                chon = 0; //phai tra con tro ve 0 neu khong nguoi dung tro den cuoi dong va chuyen qua trang khac thi se bi loi
            }
            break;
        case F2:
            Add_1_Sach(dausach, ds_dms);
            HighLight();
            gotoxy(80, 15);
            printf("THEM SACH THANH CONG");
            Sleep(1900);
            gotoxy(80, 15);
            Normal_Text();
            printf("                     ");
            for(int i=80; i<119; i++){
            	for(int j=3; j<15; j++){
            		gotoxy(i,j);
            		printf(" ");
				}
			}
            page_hientai = 0;
            if (dausach.Tongsoluongsach < sodong_dsdms) {
                so_item_dms = dausach.Tongsoluongsach;
            } else {
                so_item_dms = sodong_dsdms;
            }
            Show_DS_DMS(ds_dms, page_hientai, x, y + rong_title, so_item_dms);
            chon = 0;
            break;
        case F3:
            Edit_1_Sach(ds_dms, page_hientai * sodong_dsdms + chon);
            page_hientai = 0;
            if (dausach.Tongsoluongsach < sodong_dsdms) {
                so_item_dms = dausach.Tongsoluongsach;
            } else {
                so_item_dms = sodong_dsdms;
            }
            Show_DS_DMS(ds_dms, page_hientai, x, y + rong_title, so_item_dms);
            chon = 0;
            break;
        case DEL:
            if (ds_dms.sach[page_hientai * sodong_dsdms + chon] -> Trangthai != 1) {
                if (Dialog_Mess_Box(85, 5, "BAN CO CHAC CHAN MUON XOA") == 1) {
                    if (Delete_Sach(dausach.pNext, ds_dms.sach[page_hientai * sodong_dsdms + chon] -> Masach) == 1) {
                        dausach.Tongsoluongsach--;
                        HighLight();
                        gotoxy(80, 10);
                        printf("XOA SACH THANH CONG!");
                        Sleep(1000);
                        Normal_Text();
                        gotoxy(80, 10);
                        printf("                     ");
                    }

                    if (dausach.Tongsoluongsach > 0) {
                        ds_dms.Init_Ds_Dms_ISBN(dausach.Tongsoluongsach);
                        ds_dms.Update_Sach_DS_DMS(dausach.pNext);
                    }
                    page_hientai = 0;
                    if (dausach.Tongsoluongsach < sodong_dsdms) {
                        so_item_dms = dausach.Tongsoluongsach;
                    } else {
                        so_item_dms = sodong_dsdms;
                    }
                    Show_DS_DMS(ds_dms, page_hientai, x, y + rong_title, so_item_dms);
                    chon = 0;
                }
            } else {
                HighLight();
                gotoxy(80, 10);
                printf("SACH DA CO DOC GIA MUON, KHONG THE XOA!");
                Sleep(1000);
                Normal_Text();
                gotoxy(80, 10);
                printf("                                       ");
            }

            break;
        case ESC:
            return;
        }
    }
}
//===========================================================================================================================================
//===============================================CHUC NANG TIM KIEM==========================================================================
void Show_Search_DauSach(DS_DauSach & dsds, int pos[], int n) {
    int page_hientai = 0; // trang hien tai
    int chon = 0;
    int key;
    int so_item;
    Normal_Text();
    if (n > 17) {
        so_item = 17;
        for (int i = 0; i < 17; i++) {
            Draw_1_DauSach( * dsds.node[pos[i]], 1, 9 + i);
        }
    } else {
        so_item = n;
        for (int i = 0; i < n; i++) {
            Draw_1_DauSach( * dsds.node[pos[i]], 1, 9 + i);
        }
    }
    HighLight_Text();
    Draw_1_DauSach( * dsds.node[pos[0]], 1, 9);
    while (1) {
        key = GetKey();
        switch (key) {
        case UP:
            if (chon > 0) {
                Normal_Text();
                Draw_1_DauSach( * dsds.node[pos[chon]], 1, 9 + chon);
                chon--;
                HighLight_Text();
                Draw_1_DauSach( * dsds.node[pos[chon]], 1, 9 + chon);
            }
            break;
        case DOWN:
            if (chon + 1 < so_item) {
                Normal_Text();
                Draw_1_DauSach( * dsds.node[pos[chon]], 1, 9 + chon);
                chon++;
                HighLight_Text();
                Draw_1_DauSach( * dsds.node[pos[chon]], 1, 9 + chon);
            }
            break;
        case ENTER:
            Draw_DS_DMS( * dsds.node[pos[chon]]);	
            Save_DS_DauSach_File(dsds);
            Read_DS_DauSach_File(dsds);
            return;
        case ESC:
            return;
        }
    }
}
void Search_DauSach(DS_DauSach & dsds) {
    int pos[MAX_SIZE_DS];
    DauSach dausach;
    int x = 14, y = 4;
    int n = dsds.n;
    for (int i = 0; i < n; i++) {
        pos[i] = i;
    }
    HighLight();
    gotoxy(60,4);
    printf(" DANG TIM KIEM ");
    Normal_Text();
    //===============Xu li khi nhap vao=========================
    int k;
    int len, length;
    Normal_Text();
    gotoxy(x, y);
    char str[sizeof(dausach)] = "", str1[sizeof(dausach)] = "";
    len = strlen(str);
    length = sizeof(str);
    cout << str;
    while (1) {
        Normal_Text();
        Clear_DSDS(1, 9, 77, sodong_dsds);
        if (n > 17) {
            for (int i = 0; i < 17; i++) {
                Draw_1_DauSach( * dsds.node[pos[i]], 1, 9 + i);
            }
        } else {
            for (int i = 0; i < n; i++) {
                Draw_1_DauSach( * dsds.node[pos[i]], 1, 9 + i);
            }
        }
        gotoxy(x, y);
        cout << str;
        k = GetKey();
        if (k >= 97 && k <= 122 && len < length) {
            str[len] = k - 32;
            gotoxy(x, y);
            len = strlen(str);
            cout << str;
            for (int i = 0; i < n;) {
                strncpy(str1, dsds.node[pos[i]] -> Tensach, len);
                if (strstr(dsds.node[pos[i]] -> Tensach, str) == NULL) {
                    for (int j = i; j < n - 1; j++) {
                        pos[j] = pos[j + 1];
                    }
                    n--;
                } else {
                    i++;
                }
            }
        } else if (k >= 65 && k <= 96 && len < length) {
            str[len] = k;
            gotoxy(x, y);
            len = strlen(str);
            cout << str;
            for (int i = 0; i < n;) {
                strncpy(str1, dsds.node[pos[i]] -> Tensach, len);
                if (strstr(dsds.node[pos[i]] -> Tensach, str) == NULL) {
                    for (int j = i; j < n - 1; j++) {
                        pos[j] = pos[j + 1];
                    }
                    n--;
                } else {
                    i++;
                }

            }
        } else if (k == BACKSPACE) {
            str[len - 1] = NULL;
            for (int i = 0; i < len + 5; i++) {
                gotoxy(x + i, y);
                printf("  ");
            }
            gotoxy(x, y);
            len = strlen(str);
            cout << str;
            n = dsds.n;
            for (int i = 0; i < n; i++) {
                pos[i] = i;
            }
            for (int i = 0; i < n;) {
                if (strstr(dsds.node[pos[i]] -> Tensach, str) == NULL) {
                    for (int j = i; j < n - 1; j++) {
                        pos[j] = pos[j + 1];
                    }
                    n--;
                } else {
                    i++;
                }
            }

        } else if (k == SPACE) {
            if (str[len - 1] != char(255) && len > 0 && len < length) {
                str[len] = 255;
            }
            gotoxy(x, y);
            len = strlen(str);
            cout << str;
            for (int i = 0; i < n;) {
                if (strstr(dsds.node[pos[i]] -> Tensach, str) == NULL) {
                    for (int j = i; j < n - 1; j++) {
                        pos[j] = pos[j + 1];
                        pos[n - 1] = 0;
                    }
                    n--;
                } else {
                    i++;
                }
            }

        } else if (k == ENTER || k == TAB || k == DOWN || k == UP) {
            gotoxy(x, y);
            HighLight_Text();
            cout << str;
            Show_Search_DauSach(dsds, pos, n);
            return;
        } else if (k == ESC) {
        	gotoxy(60,4);
    		printf("                ");
            return;
        }
    };

}
//====================================================DRAW CASE 2============================================================================
//===========================================================================================================================================
bool Check_DauSach(DauSach ds) {
    for (NodeSach * p = ds.pNext; p != NULL; p = p -> pNext) {
        if (p -> sach.Trangthai != 0) return false;
    }
    return true;
}
void Draw_Case_2() {
    int x = 1, y = 6, rong_title = 3, dai = 77, rong = rong_title + sodong_dsdg - 1;
    //=================xu li giao dien====================
    system("cls");
    ColorAll();
    Draw_frame_Main(0, 0, X, Y); // ve lai khung, de tao case 1
    Draw_frame(x, y, dai, rong);
    Draw_Title_Case2(x, y, dai);
    Draw_fram_view_case2();

    //ColorAll();
    //==========================khoi tao danh sach mang con tro=============================
    DS_DauSach dsds;
    dsds.Init_DSDS();
    DauSach ds;
    Read_DS_DauSach_File(dsds);
    //========PHAN TRANG==========
    sl_page = 0; // tong so luong trang	 
    if (dsds.n % sodong_dsds == 0) {
        sl_page = dsds.n / sodong_dsds;
    } else {
        sl_page = dsds.n / sodong_dsds + 1;
    }
    //===========So item=============
    int so_item;
    if (dsds.n < sodong_dsds) {
        so_item = dsds.n;
    } else {
        so_item = sodong_dsds;
    }
    int page_hientai = 0; // trang hien tai
    int chon = 0;
    int key;
    Show_DSDS(dsds, page_hientai, x, y + 3, so_item);
    while (1) {
        key = GetKey();
        switch (key) {
        case UP:
            if (chon > 0) {
                Normal_Text();
                Draw_1_DauSach( * dsds.node[page_hientai * sodong_dsds + chon], x, y + rong_title + chon);
                chon--;
                HighLight_Text();
                Draw_1_DauSach( * dsds.node[page_hientai * sodong_dsds + chon], x, y + rong_title + chon);
            }
            break;
        case DOWN:
            if (chon + 1 < so_item) {
                Normal_Text();
                Draw_1_DauSach( * dsds.node[page_hientai * sodong_dsds + chon], x, y + rong_title + chon);
                chon++;
                HighLight_Text();
                Draw_1_DauSach( * dsds.node[page_hientai * sodong_dsds + chon], x, y + rong_title + chon);
            }
            break;
        case LEFT:
            if (page_hientai > 0) {
                if (dsds.n < sodong_dsds) {
                    so_item = dsds.n;
                } else {
                    so_item = sodong_dsds;
                }
                page_hientai--;
                Show_DSDS(dsds, page_hientai, x, y + 3, so_item);
                chon = 0;
            }
            break;
        case RIGHT:
            if (page_hientai + 1 < sl_page) {
                if (page_hientai + 2 == sl_page) {
                    so_item = dsds.n - (sodong_dsds * (page_hientai + 1));
                } else {
                    so_item = sodong_dsdg;
                }
                page_hientai++;
                gotoxy(90, y - 3);

                Show_DSDS(dsds, page_hientai, x, y + 3, so_item);
                chon = 0; //phai tra con tro ve 0 neu khong nguoi dung tro den cuoi dong va chuyen qua trang khac thi se bi loi
            }
            break;

        case F2:
            Add_1_DS(dsds);
            if (dsds.n < sodong_dsds) {
                so_item = dsds.n;
            } else {
                so_item = sodong_dsds;
            }
            page_hientai = 0;
            Show_DSDS(dsds, page_hientai, x, y + 3, so_item);
            chon = 0;
            break;
        case F3:
            Edit_1_DS(dsds, * dsds.node[page_hientai * sodong_dsdg + chon]);
            if (dsds.n < sodong_dsds) {
                so_item = dsds.n;
            } else {
                so_item = sodong_dsds;
            }
            page_hientai = 0;
            Show_DSDS(dsds, page_hientai, x, y + 3, so_item);
            chon = 0;
            break;
        case F11:
            Search_DauSach(dsds);
            if (dsds.n < sodong_dsds) {
                so_item = dsds.n;
            } else {
                so_item = sodong_dsds;
            }
            //====khoi tao lai giao dien=======
            system("cls");
            ColorAll();
            Draw_frame_Main(0, 0, X, Y); // ve lai khung, de tao case 1
            Draw_frame(x, y, dai, rong);
            Draw_Title_Case2(x, y, dai);
            Draw_fram_view_case2();
            //===========================================
            page_hientai = 0;
            Show_DSDS(dsds, page_hientai, x, y + 3, so_item);
            chon = 0;
            break;
        case ENTER:
            Draw_DS_DMS( * dsds.node[page_hientai * sodong_dsds + chon]);
            Save_DS_DauSach_File(dsds);
            Read_DS_DauSach_File(dsds);
            //====khoi tao lai giao dien=======
            system("cls");
            ColorAll();
            Draw_frame_Main(0, 0, X, Y); // ve lai khung, de tao case 1
            Draw_frame(x, y, dai, rong);
            Draw_Title_Case2(x, y, dai);
            Draw_fram_view_case2();
            //==================================
            if (dsds.n < sodong_dsds) {
                so_item = dsds.n;
            } else {
                so_item = sodong_dsds;
            }
            page_hientai = 0;
            Draw_fram_view_case2();
            Show_DSDS(dsds, page_hientai, x, y + 3, so_item);
            chon = 0;

            break;
        case DEL:
            if (Check_DauSach( * dsds.node[page_hientai * sodong_dsds + chon])) {
                int check = Dialog_Mess_Box(80, 19, "BAN CO CHAC CHAN MUON XOA");
                if (check == 1) {
                    Delete_DauSach(dsds, page_hientai * sodong_dsds + chon);
                    gotoxy(80, 19);
                    HighLight();
                    printf("SACH DA DUOC XOA THANH CONG");
                    Sleep(1700);
                    Normal_Text();
                    gotoxy(80, 19);
                    printf("                            ");
                }
            } else {
                HighLight();
                gotoxy(80, 19);
                printf("SACH DA CO DOC GIA MUON");
                Sleep(1500);
                Normal_Text();
                gotoxy(80, 19);
                printf("                       ");

            }

            Save_DS_DauSach_File(dsds);
            Read_DS_DauSach_File(dsds);
            //==================================
            if (dsds.n < sodong_dsds) {
                so_item = dsds.n;
            } else {
                so_item = sodong_dsds;
            }
            page_hientai = 0;
            Draw_fram_view_case2();
            Show_DSDS(dsds, page_hientai, x, y + 3, so_item);
            chon = 0;
            break;
        case ESC:
        	delete dsds.node;
            return;
        }
    }
    Save_DS_DauSach_File(dsds);
}
//====================================================DRAW CASE 3============================================================================
//===========================================================================================================================================

Date * GetDate_String(string str) {
    Date * date;
    date = new Date;
    char str1[6] = "";
    string str_s = str1;
    int len = str.length(), k = 0, i = 0;
    while (str[k] != '/') {
        str1[i] = str[k];
        i++;
        k++;
        str_s = str1;
    }
    date -> ngay = Convert_String_to_Int(str_s);
    for (int j = 0; j < 6; j++) str1[j] = NULL;
    k++;
    i = 0;
    while (str[k] != '/') {
        str1[i] = str[k];
        i++;
        k++;
        str_s = str1;
    }
    date -> thang = Convert_String_to_Int(str_s);
    strcpy(str1, "");
    k++;
    i = 0;
    while (k < str.length()) {
        str1[i] = str[k];
        i++;
        k++;
        str_s = str1;
    }
    date -> nam = Convert_String_to_Int(str_s);
    strcpy(str1, "");
    k++;
    i = 0;
    return date;
}
int LeapYear(int year) // tinh nam nhuan
{
    if (year % 400 == 0) return 1;
    else if (year % 100 != 0 && year % 4 == 0) return 1;
    return 0;
}
int Check_date_7(Date * date) {
    int a[15];
    gotoxy(15, 28);
    printf("TOI DAY");
    gotoxy(15, 28);
    printf("        ");
    a[0] = 31;
    a[1] = 28;
    a[2] = 31;
    a[3] = 30;
    a[4] = 31;
    a[5] = 30;
    a[6] = 31;
    a[7] = 31;
    a[8] = 30;
    a[9] = 31;
    a[10] = 30;
    a[11] = 31;
    if (LeapYear(date -> nam)) a[1] = 29;
    Date * date_tmp = Get_Date_Today();

    int date1 = date -> ngay, mon = date -> thang, year = date -> nam;
    date1 += 7;
    if (date1 > a[mon - 1]) {
        date1 = date1 - a[mon - 1];
        mon++;
    }
    if (mon > 12) {
        year++;
        mon = mon - 12;
    }
    if (year == date_tmp -> nam) {
        if (mon == date_tmp -> thang) {
            if (date1 < date_tmp -> ngay) {
                return 0;
            } else {
                return 1;
            }
        } else if (mon < date_tmp -> thang) {
            return 0;
        } else return 1;
    } else if (year < date_tmp -> nam) {
        return 0;
    } else return 1;
}
//================================MUON SACH=========================================================
int Check_MT_DG(DocGia dg) {
    if (dg.dsmt.chuaTra == 3 || dg.trangthai == 0) {
        return 0;
    }
    return 1;
}
int Check_MT_MaSach_DG(DocGia dg, char masach[]) {
    char str1[6] = "", str2[6] = "";
    strcpy(str2, Get_ISBN_from_MaSach(masach));
    for (NodeMuonTra * p = dg.dsmt.First; p != NULL; p = p -> next) {
        strcpy(str1, Get_ISBN_from_MaSach(p -> muontra.MASACH));
        if (strcmp(str1, str2) == 0 && p -> muontra.trangthai == 0) {
            return 0;
        }
    }
    return 1;
}
void clear_screen(int x, int y, int dai, int rong) {
    Normal_Text();
    for (int i = x; i < x + dai + 1; i++) {
        for (int j = y; j < y + rong + 1; j++) {
            gotoxy(i, j);
            printf(" ");
        }
    }
}
void Draw_case_DangMuonSach(DocGia dg, DS_DauSach dsds) {
    Draw_frame(3, 16, 52, 5);
    Draw_H(3, 18, 52);
    Draw_I(13, 18, 3);
    Draw_I(44, 18, 3);
    gotoxy(14, 17);
    DauSach * ds = NULL;
    int dem = 0;
    char isbn[10] = "";
    printf("DANH SACH SACH DOC GIA DANG MUON");

    for (NodeMuonTra * p = dg.dsmt.First; p != NULL; p = p -> next) {
        strcpy(isbn, Get_ISBN_from_MaSach(p -> muontra.MASACH));
        ds = Search_DauSach_ISBN(dsds, isbn);
        if (p -> muontra.trangthai == 0) {
            gotoxy(4, 19 + dem);
            printf("%s", p -> muontra.MASACH);
            gotoxy(14, 19 + dem);
            printf("%s", ds -> Tensach);
            gotoxy(45, 19 + dem);
            printf("%d/%d/%d", p -> muontra.Ngaymuon -> ngay, p -> muontra.Ngaymuon -> thang, p -> muontra.Ngaymuon -> nam);
            dem++;
        }
    }
}
void Draw_case_Muonsach() {
    int x = 3, y = 6;
    int key;
    int check = 1;
    bool check_continue = true;
    //=================xu li giao dien====================
    system("cls");
    ColorAll();
    Draw_frame_Main(0, 0, X, Y); // ve lai khung, de tao case 1
    Normal_Text(); //khung tim kiem
    gotoxy(3, 4);
    printf("NHAP MA THE : ");
    Draw_frame(20, 3, 35, 1);
    //ColorAll();
    //==================== khoi tao cay=================
    DocGia dg;
    NodeDG tree;
    Init_Tree(tree);
    Read_Tree_File(tree);
    //===============khoi tao danh sach mang con tro=============================
    DS_DauSach dsds;
    dsds.Init_DSDS();
    DauSach * ds = NULL;
    Sach * sach = NULL;
    Read_DS_DauSach_File(dsds);
    //======================================================
    int madocgia = 0;
    NodeDG nodeDG = NULL;
    //===================TIM THONG TIN DOC GIA=============================

    while (nodeDG == NULL && check == 1) {
        madocgia = Input_Int_99999(madocgia, 21, 4);
        if (madocgia <= 9999) return;
        nodeDG = Search_DG(tree, madocgia);
        if (nodeDG == NULL) {
            gotoxy(x + 5, y + 5);
            printf("KHONG TIM THAY DOC GIA!");
            Sleep(1000);
            gotoxy(x + 5, y + 5);
            printf("                       ");
            check = Dialog_Mess_Box(x + 5, y + 5, "BAN CO MUON TIEP TUC?");
            if (check == 0) return;
        }

    }
    //======================IN THONG TIN DOC GIA=============================
    Normal_Text();
    Draw_frame(x, y, 52, 8);
    gotoxy(x + 3, y + 1);
    printf("MA THE:      %d", nodeDG -> docgia.Mathe);
    gotoxy(x + 3, y + 3);
    printf("HO TEN:      %s %s", nodeDG -> docgia.Ho, nodeDG -> docgia.Ten);
    gotoxy(x + 3, y + 5);
    printf("PHAI:        ");
    if (nodeDG -> docgia.phai == 1) printf("NAM");
    else printf("NU");
    gotoxy(x + 3, y + 7);
    printf("TRANG THAI:  ");
    if (nodeDG -> docgia.trangthai == 1) printf("HOAT DONG");
    else printf("BI KHOA");

    Draw_case_DangMuonSach(nodeDG -> docgia, dsds);
    while (check_continue) {
        if (Check_MT_DG(nodeDG -> docgia) == 1) {
            clear_screen(60, 3, 57, 20);
            //==================================TIM KIEM SACH======================================
            Normal_Text(); //khung tim kiem
            gotoxy(60, 4);
            printf("NHAP MA SACH : ");
            Draw_frame(75, 3, 40, 1);

            //==================================tim kiem============================================
            char masach[10] = "";
            char isbn[10] = "";
            while (sach == NULL && check_continue) {
                strcpy(masach, Input_Str_Int_Masach(masach, 76, 4, sizeof(masach) - 1));
                strcpy(isbn, Get_ISBN_from_MaSach(masach));
                if (isbn != NULL) {
                    ds = Search_DauSach_ISBN(dsds, isbn);
                }
                if (ds != NULL) {
                    sach = Get_Sach(ds -> pNext, masach);
                    if (sach == NULL) {
                        gotoxy(x + 70, y + 5);
                        printf("KHONG TIM THAY MA SACH NAY!");
                        Sleep(1000);
                        gotoxy(x + 70, y + 5);
                        printf("                            ");
                    }
                } else {
                    gotoxy(x + 70, y + 5);
                    printf("KHONG TIM THAY SACH NAY!");
                    Sleep(1000);
                    gotoxy(x + 70, y + 5);
                    printf("                         ");
                    check = Dialog_Mess_Box(75, 18, "BAN CO MUON TIEP TUC?");
                    if (check == 0) {
                        check_continue = false;
                        return;
                    }
                }

            }
            //======================IN THONG TIN SACH=============================
            Normal_Text();
            Draw_frame(60, 6, 55, 8);
            gotoxy(61, 7);
            printf("MA SACH:        %s", sach -> Masach);
            gotoxy(61, 9);
            printf("TEN SACH:       %s", ds -> Tensach);
            gotoxy(61, 11);
            printf("SO LUONG SACH:  %d", ds -> Tongsoluongsach);
            gotoxy(61, 13);
            printf("TRANG THAI:     ");
            if (sach -> Trangthai == 0) {
                printf("CHO MUON DUOC");
            } else if (sach -> Trangthai == 1) {
                printf("SACH DA DUOC MUON");
            } else {
                printf("SACH DA THANH LY");
            }

            if (sach -> Trangthai == 0) {
                Date * today = Get_Date_Today();
                gotoxy(61, 16);
                printf("NGAY CHO MUON:  ");
                HighLight();
                printf("%d/%d/%d", today -> ngay, today -> thang, today -> nam);
                if (Check_MT_MaSach_DG(nodeDG -> docgia, masach) == 1) { //check trung dau sach khong duoc muon
                    check = Dialog_Mess_Box(75, 18, "BAN CO CHAC CHAN CHO MUON?");
                    //===============================CHO MUON SACH====================================
                    if (check == 1) {
                        MuonTra mt;
                        strcpy(mt.MASACH, masach);
                        mt.Ngaymuon = today;
                        mt.Ngaytra = NULL;
                        mt.trangthai = 0;
                        Insert_Last_DSMT(nodeDG -> docgia.dsmt, mt);
                        sach -> Trangthai = 1;
                        ds -> Soluongmuon++;
                        Save_DS_DauSach_File(dsds);
                        Save_Tree_File(tree);
                        HighLight();
                        gotoxy(65, 25);
                        printf("CHO MUON SACH THANH CONG");
                        Sleep(2000);
                        gotoxy(65, 25);
                        Normal_Text();
                        printf("                          ");
                        Draw_case_DangMuonSach(nodeDG -> docgia, dsds);
                    }
                } else {
                    gotoxy(65, 25);
                    HighLight();
                    printf("DOC GIA DA MUON SACH NAY ROI!");
                    Sleep(2000);
                    gotoxy(65, 25);
                    Normal_Text();
                    printf("                                      ");
                }

            }
            check = Dialog_Mess_Box(75, 18, "BAN CO MUON TIEP TUC?");
            sach = NULL;
            if (check == 0) {
                check_continue = false;
            }
        } else {
            clear_screen(60, 3, 57, 20);
            gotoxy(70, 5);
            HighLight();
            printf("DOC GIA KHONG DU DIEU KIEN MUON SACH");
            Sleep(2000);
            gotoxy(70, 5);
            Normal_Text();
            printf("                                      ");
            check = Dialog_Mess_Box(75, 10, "BAN CO MUON TIEP TUC?");
            sach = NULL;
            if (check == 0) {
                check_continue = false;
            }
        }
        if (check_continue == false) {
            Sleep(1000);
            delete ds;
            delete sach;
            DeleteMemoryDocGia(tree);
            delete dsds.node;
            return;
        }
    }

}

//=======================================TRA SACH=====================================================
void Draw_case_TraSach() {
    int x = 3, y = 6;
    int key;
    int check = 1;
    bool check_continue = true;
    //=================xu li giao dien====================
    system("cls");
    ColorAll();
    Draw_frame_Main(0, 0, X, Y); // ve lai khung, de tao case 1
    Normal_Text(); //khung tim kiem
    gotoxy(3, 4);
    printf("NHAP MA THE : ");
    Draw_frame(20, 3, 35, 1);
    //ColorAll();
    //==================== khoi tao cay=================
    DocGia dg;
    NodeDG tree;
    Init_Tree(tree);
    Read_Tree_File(tree);
    //===============khoi tao danh sach mang con tro=============================
    DS_DauSach dsds;
    dsds.Init_DSDS();
    Sach * sach = NULL;
    Read_DS_DauSach_File(dsds);
    //======================================================
    int madocgia = 0;
    NodeDG nodeDG = NULL;
    //===================TIM THONG TIN DOC GIA=============================

    while (nodeDG == NULL && check == 1) {
        madocgia = Input_Int_99999(madocgia, 21, 4);
        if (madocgia <= 9999) return;
        nodeDG = Search_DG(tree, madocgia);
        if (nodeDG == NULL) {
            gotoxy(x + 5, y + 5);
            printf("KHONG TIM THAY DOC GIA!");
            Sleep(1000);
            gotoxy(x + 5, y + 5);
            printf("                       ");
            check = Dialog_Mess_Box(x + 5, y + 5, "BAN CO MUON TIEP TUC?");
            if (check == 0) return;
        }

    }
    //======================IN THONG TIN DOC GIA=============================
    Normal_Text();
    Draw_frame(x, y, 52, 8);
    gotoxy(x + 3, y + 1);
    printf("MA THE:      %d", nodeDG -> docgia.Mathe);
    gotoxy(x + 3, y + 3);
    printf("HO TEN:      %s %s", nodeDG -> docgia.Ho, nodeDG -> docgia.Ten);
    gotoxy(x + 3, y + 5);
    printf("PHAI:        ");
    if (nodeDG -> docgia.phai == 1) printf("NAM");
    else printf("NU");
    gotoxy(x + 3, y + 7);
    printf("TRANG THAI:  ");
    if (nodeDG -> docgia.trangthai == 1) printf("HOAT DONG");
    else printf("BI KHOA");
    MuonTra * mt[6];
    DauSach * ds[6];
    bool vitri_check[6];
    int n = 0;
    char isbn[10] = "";
    for (NodeMuonTra * p = nodeDG -> docgia.dsmt.First; p != NULL; p = p -> next) {
        if (p -> muontra.trangthai == 0) {
            strcpy(isbn, Get_ISBN_from_MaSach(p -> muontra.MASACH));
            ds[n] = Search_DauSach_ISBN(dsds, isbn);
            mt[n] = & p -> muontra;
            vitri_check[n] = false;
            n++;
        }
    }
    //========================giao dien tra sach====================
    x = 60, y = 6;
    Draw_frame(x, y, 55, 5);
    Draw_H(x, y + 2, 55);
    Draw_I(x + 13, y + 2, 3);
    Draw_I(x + 44, y + 2, 3);
    gotoxy(x + 15, y + 1);
    printf("DANH SACH SACH DOC GIA DANG MUON");
    int dem = 0;
    int chon = 0;
    for (int i = 0; i < n; i++) {
        gotoxy(x + 1, y + 3 + i);
        printf("%s", mt[i] -> MASACH);
        gotoxy(x + 14, y + 3 + i);
        printf("%s", ds[i] -> Tensach);
        gotoxy(x + 45, y + 3 + i);
        printf("%d/%d/%d", mt[i] -> Ngaymuon -> ngay, mt[i] -> Ngaymuon -> thang, mt[i] -> Ngaymuon -> nam);
    }
    gotoxy(x + 15, y + 7);
    HighLight();
    printf(" CTRL + ENTER DE TRA SACH ");
    Normal_Text();
    //===============================================================
    gotoxy(x + 57, y + 3);
    printf("<");
    while (1) {
        key = GetKey();
        switch (key) {
        case UP:
            if (chon > 0) {
                gotoxy(x + 57, y + 3 + chon);
                printf(" ");
                chon--;
                gotoxy(x + 57, y + 3 + chon);
                printf("<");
            }
            break;
        case DOWN:
            if (chon + 1 < n + 1) {
                gotoxy(x + 57, y + 3 + chon);
                printf(" ");
                chon++;
                gotoxy(x + 57, y + 3 + chon);
                printf("<");
            }
            break;
        case ENTER:
            if (vitri_check[chon] == true) {
                vitri_check[chon] = false;
            } else {
                vitri_check[chon] = true;
            }
            for (int i = 0; i < n; i++) {
                if (vitri_check[i] == true) {
                    HighLight_Text();
                }
                gotoxy(x + 1, y + 3 + i);
                printf("%s", mt[i] -> MASACH);
                gotoxy(x + 14, y + 3 + i);
                printf("%s", ds[i] -> Tensach);
                gotoxy(x + 45, y + 3 + i);
                printf("%d/%d/%d", mt[i] -> Ngaymuon -> ngay, mt[i] -> Ngaymuon -> thang, mt[i] -> Ngaymuon -> nam);
                Normal_Text();
            }
            gotoxy(x + 58, y + 3 + chon);
            break;
        case CTRL_ENTER:
            gotoxy(x + 6, y + 9);
            printf("TOI DAY");
            gotoxy(x + 6, y + 9);
            printf("        ");
            if (n > 0) {
                for (int i = 0; i < n; i++) {
                    if (vitri_check[i] == true) {

                        for (NodeMuonTra * p = nodeDG -> docgia.dsmt.First; p != NULL; p = p -> next) {
                            if (p -> muontra.trangthai == 0 && strcmp(p -> muontra.MASACH, mt[i] -> MASACH) == 0) {
                                p -> muontra.trangthai = 1;
                                p -> muontra.Ngaytra = Get_Date_Today();
                                nodeDG -> docgia.dsmt.chuaTra--;
                                nodeDG -> docgia.trangthai = 1;
                                for (NodeSach * pl = ds[i] -> pNext; pl != NULL; pl = pl -> pNext) {
                                    if (strcmp(mt[i] -> MASACH, pl -> sach.Masach) == 0) {
                                        pl -> sach.Trangthai = 0;
                                    }
                                }
                            }
                        }
                    }
                }
                for (NodeMuonTra * p = nodeDG -> docgia.dsmt.First; p != NULL; p = p -> next) {
                    if (Check_date_7(p -> muontra.Ngaymuon) == 0 && p -> muontra.trangthai == 0) {
                        nodeDG -> docgia.trangthai = 0;
                    }
                }

                Save_DS_DauSach_File(dsds);
                Save_Tree_File(tree);
                HighLight();
                gotoxy(65, 25);
                printf("TRA SACH THANH CONG");
                Sleep(2000);
                gotoxy(65, 25);
                Normal_Text();
                printf("                      ");
                delete ds;
                delete sach;
                DeleteMemoryDocGia(tree);
                delete dsds.node;
                return;
            }

            break;
        case ESC:
            delete ds;
            delete sach;
            DeleteMemoryDocGia(tree);
            delete dsds.node;
            return;
            break;
        }
    }
    while (1) {
        key = GetKey();
        if (key == ESC) return;
    }
}
void Draw_1_DG_QH(DocGia dg, int x, int y) { // hien thi 1 doc gia trong ds

    Normal_Text();
    for(int i = 75; i<119; i++){
    	for(int j = 23; j<26; j++){
    		gotoxy(i, j);
            printf(" ");
		}
	}
	//===============khoi tao danh sach mang con tro=============================
    DS_DauSach dsds;
    dsds.Init_DSDS();
    Sach * sach = NULL;
    Read_DS_DauSach_File(dsds);
    DauSach *ds;
    char isbn[10] = "";
    //--------------------------------------------------------------------------
    int x_view = 74, y_view = 19;
    Draw_frame(x_view, y_view, 40, 6);
    Draw_H(x_view, y_view + 2, 40);
    Draw_I(x_view + 13, y_view + 2, 4);
    Draw_I(x_view + 30, y_view + 2, 4);
    gotoxy(x_view + 15, y_view + 1);
    printf("DANH SACH SACH QUA HAN");
    gotoxy(x_view + 3, y_view + 3);
    printf("MA SACH");
    gotoxy(x_view + 17, y_view + 3);
    printf("NGAY MUON");
    gotoxy(x_view + 31, y_view + 3);
    printf("SO NGAY QH");
    Date * today = Get_Date_Today();
    int temp = 0;
    for (NodeMuonTra * p = dg.dsmt.First; p != NULL; p = p -> next) {
        if (p -> muontra.trangthai == 0) {
            if (diff(today, p -> muontra.Ngaymuon) > 7) {
                temp++;
                gotoxy(x_view + 1, y_view + 3 + temp);
                printf("          ");
                gotoxy(x_view + 14, y_view + 3 + temp);
                printf("          ");
                gotoxy(x_view + 31, y_view + 3 + temp);
                printf("          ");
				//========================TEN SACH================
				strcpy(isbn, Get_ISBN_from_MaSach(p -> muontra.MASACH));
            	ds = Search_DauSach_ISBN(dsds, isbn);
            	strcpy(isbn, "");
            	//================================================
                gotoxy(x_view + 1, y_view + 3 + temp);
                printf(p -> muontra.MASACH);
                gotoxy(x_view + 14, y_view + 3 + temp);
                printf("%d/%d/%d", p -> muontra.Ngaymuon -> ngay, p -> muontra.Ngaymuon -> thang, p -> muontra.Ngaymuon -> nam);
                gotoxy(x_view + 31, y_view + 3 + temp);
                //printf("%d %s", diff(today, p -> muontra.Ngaymuon),ds->Tensach);
                printf("%d", diff(today, p -> muontra.Ngaymuon));
            }
        }
    }

    //HighLight_Text();
    Draw_View_1DG_Case1(dg);
    //Ma doc gia
    gotoXY(x + 1, y);
    printf("   %d", dg.Mathe);
    //Ho
    gotoXY(x + 16, y);
    printf("%s", dg.Ho);
    //Ten

    gotoXY(x + 36, y);
    printf("  %s", dg.Ten);
    //Phai
    if (dg.phai == 1) {
        gotoXY(x + 50, y);
        printf("NAM");
    } else {
        gotoXY(x + 50, y);
        printf("NU");
    }
    //Thoi gian qua han
    gotoXY(x + 57, y);
    if (dg.trangthai == 1) {
        gotoXY(x + 57, y);
        printf("HOAT DONG");
    } else {
        gotoXY(x + 57, y);
        printf("BI KHOA");
    }
	delete dsds.node;
	delete sach;
	delete ds;
}

void Draw_Title_Case_DGQH(int x, int y, int dai) {
    HighLight();
    gotoxy(x + 25, y - 2);
    printf("  DANH SACH DOC GIA QUA HAN  ");
    gotoxy(x + 25, y - 1);
    printf("                             ");
    gotoxy(x + 25, y - 3);
    printf("                             ");

    Normal_Text();
    Draw_H(x, y + 2, dai);
    //Ma doc gia
    gotoXY(x + 1, y + 1);
    printf("%s %c", " MA DOC GIA ", 186);
    //Ho
    gotoXY(x + 14, y);
    printf("%c", 203);
    gotoXY(x + 14, y + 2);
    printf("%c", 206);
    gotoXY(x + 16, y + 1);
    printf("%s %c", "        HO       ", 186);
    //Ten
    gotoXY(x + 34, y);
    printf("%c", 203);
    gotoXY(x + 34, y + 2);
    printf("%c", 206);
    gotoXY(x + 37, y + 1);
    printf("%s %c", "    TEN    ", 186);
    //Phai
    gotoXY(x + 49, y);
    printf("%c", 203);
    gotoXY(x + 49, y + 2);
    printf("%c", 206);
    gotoXY(x + 51, y + 1);
    printf("%s %c", "PHAI", 186);
    //Trang thai
    gotoXY(x + 56, y);
    printf("%c", 203);
    gotoXY(x + 56, y + 2);
    printf("%c", 206);
    gotoXY(x + 58, y + 1);
    printf("%s", "TRANG THAI");
    //ve hang phan cach

    for (int i = y + 3; i < y + sodong_dsdg + 3; i++) {
        gotoXY(x + 14, i);
        printf("%c", 186);
        gotoXY(x + 34, i);
        printf("%c", 186);
        gotoXY(x + 49, i);
        printf("%c", 186);
        gotoXY(x + 56, i);
        printf("%c", 186);
    }
    gotoXY(x + 14, y + sodong_dsdg + 3);
    printf("%c", 202);
    gotoXY(x + 34, y + sodong_dsdg + 3);
    printf("%c", 202);
    gotoXY(x + 49, y + sodong_dsdg + 3);
    printf("%c", 202);
    gotoXY(x + 56, y + sodong_dsdg + 3);
    printf("%c", 202);
    //==========guide================

    Normal_Text();
}
void Clear_DSDG_QH(int x, int y, int dai, int rong) {
    Normal_Text();
    for (int i = x; i < x + dai; i++) {
        for (int j = y; j < y + rong; j++) {
            gotoxy(i, j);
            printf(" ");
        }
    }
    
    Draw_Title_Case_DGQH(1, 6, 70);
}
void Show_DSDG_QH(DanhSach_DG dsdg, int page_hientai, int x, int y, int sodong) { // hien thi dsdg cua 1 trang
    Normal_Text();
    Clear_DSDG_QH(x + 1, y, 70, sodong_dsdg);
    for (int i = page_hientai * sodong_dsdg; i < page_hientai * sodong_dsdg + sodong; i++) {
    	
        Draw_1_DG_QH( * dsdg.DG[i], x, y + (i - page_hientai * sodong_dsdg));
    }
    //================page hien tai / sl page vi du trang 5/6==================
    gotoxy((x + 60) / 2, y + sodong_dsdg + 2);
    printf("Trang ");
    HighLight();
    printf("%d / %d", page_hientai + 1, sl_page);
    Normal();
    //==============in dong dau tien=====================
    HighLight_Text();
    Draw_1_DG_QH( * dsdg.DG[page_hientai * sodong_dsdg], x, y);
}
void Draw_case_DGQG_QH() {
    int x = 1, y = 6, rong_title = 3, dai = 70, rong = rong_title + sodong_dsdg - 1;
    
    //==================== khoi tao cay=================
    DocGia dg;
    NodeDG tree;
    DanhSach_DG dsdg;
    Init_Tree(tree);
    Read_Tree_File(tree);
    dsdg.Reset_DSDG();
    //dsdg.Insert_DG_to_DSDG(tree);
    dsdg.Get_DSDG_QuaHan(tree);
    
	//=================xu li giao dien====================
    system("cls");
    ColorAll();
    if(dsdg.n==0){
    	gotoxy(40,10);
    	HighLight();
    	printf("KHONG CO DOC GIA QUA HAN");
    	Normal_Text();
    	Sleep(2000);
    	return;
	}
    Draw_frame_Main(0, 0, X, Y); // ve lai khung, de tao case 1
    Draw_frame(x, y, dai, rong);
    Draw_fram_view_case1();
    //ColorAll();
    Draw_Title_Case_DGQH(x, y, dai);
    //========PHAN TRANG==========
    sl_page = 0; // tong so luong trang	 
    if (dsdg.n % sodong_dsdg == 0) {
        sl_page = dsdg.n / sodong_dsdg;
    } else {
        sl_page = dsdg.n / sodong_dsdg + 1;
    }
    int page_hientai = 0; // trang hien tai
    //int sodong_page=sodong_dsdg;//so dong hien tai cua trang hien tai (<=sodong_dsdg)

    //=========hien ds doc gia=========
    int chon = 0;
    char key;
    int so_item;
    if (dsdg.n < sodong_dsdg) {
        so_item = dsdg.n;
    } else {
        so_item = sodong_dsdg;
    }
    //Draw_Button_Sort_Mathe(x,y-3);
    Show_DSDG_QH(dsdg, page_hientai, x, y + rong_title, so_item);

    do {
        key = GetKey();
        switch (key) {
        case UP:
            if (chon > 0) {
                Normal_Text();
                Draw_1_DG_QH( * dsdg.DG[page_hientai * sodong_dsdg + chon], x, y + rong_title + chon);
                chon--;
                HighLight_Text();
                Draw_1_DG_QH( * dsdg.DG[page_hientai * sodong_dsdg + chon], x, y + rong_title + chon);
            }
            break;
        case DOWN:
            if (chon + 1 < so_item) {
                Normal_Text();
                Draw_1_DG_QH( * dsdg.DG[page_hientai * sodong_dsdg + chon], x, y + rong_title + chon);
                chon++;
                HighLight_Text();
                Draw_1_DG_QH( * dsdg.DG[page_hientai * sodong_dsdg + chon], x, y + rong_title + chon);
            }
            break;
        case LEFT:
            if (page_hientai > 0) {
                if (dsdg.n < sodong_dsdg) {
                    so_item = dsdg.n;
                } else {
                    so_item = sodong_dsdg;
                }
                page_hientai--;
                Show_DSDG(dsdg, page_hientai, x, y + rong_title, so_item);
                chon = 0;
            }
            break;
        case RIGHT:
            if (page_hientai + 1 < sl_page) {

                if (page_hientai + 2 == sl_page) {
                    so_item = dsdg.n - (sodong_dsdg * (page_hientai + 1));
                } else {
                    so_item = sodong_dsdg;
                }
                page_hientai++;
                gotoxy(90, y - 3);

                Show_DSDG(dsdg, page_hientai, x, y + rong_title, so_item);
                chon = 0; //phai tra con tro ve 0 neu khong nguoi dung tro den cuoi dong va chuyen qua trang khac thi se bi loi
            }
            break;
        case ESC:
            DeleteMemoryDocGia(tree);
            delete dsdg.DG;
            return;
        }
        // end switch
    } while (1);
}
void Draw_Title_Case_Top10(int x, int y, int dai) {
    HighLight();
    gotoxy(42, 4);
    printf(" TOP 10 DAU SACH DUOC MUON NHIEU NHAT ");
    gotoxy(42, 3);
    printf("                                      ");
    gotoxy(42, 5);
    printf("                                      ");
    Normal_Text();
    Draw_H(x, y + 2, dai);
    //Ma ISBN
    gotoXY(x + 1, y + 1);
    printf("%s %c", "MA ISBN", 186);
    //Ten Sach
    gotoXY(x + 9, y);
    printf("%c", 203);
    gotoXY(x + 9, y + 2);
    printf("%c", 206);
    gotoXY(x + 12, y + 1);
    printf("%s %c", "        TEN SACH       ", 186);
    //Ten
    gotoXY(x + 36, y);
    printf("%c", 203);
    gotoXY(x + 36, y + 2);
    printf("%c", 206);
    gotoXY(x + 37, y + 1);
    printf("%s %c", " TEN TAC GIA  ", 186);
    //Phai
    gotoXY(x + 52, y);
    printf("%c", 203);
    gotoXY(x + 52, y + 2);
    printf("%c", 206);
    gotoXY(x + 54, y + 1);
    printf("%s %c", " THE LOAI ", 186);
    //Phai
    gotoXY(x + 65, y);
    printf("%c", 203);
    gotoXY(x + 65, y + 2);
    printf("%c", 206);
    gotoXY(x + 67, y + 1);
    printf("%s %c", "NXB", 186);
    //Trang thai
    gotoXY(x + 71, y);
    printf("%c", 203);
    gotoXY(x + 71, y + 2);
    printf("%c", 206);
    gotoXY(x + 72, y + 1);
    printf("%s", "LUOT MUON");
    //ve hang phan cach

    for (int i = y + 3; i < y + 10 + 3; i++) {
        gotoXY(x + 9, i);
        printf("%c", 186);
        gotoXY(x + 36, i);
        printf("%c", 186);
        gotoXY(x + 52, i);
        printf("%c", 186);
        gotoXY(x + 65, i);
        printf("%c", 186);
        gotoXY(x + 71, i);
        printf("%c", 186);
    }
    gotoXY(x + 9, y + 10 + 3);
    printf("%c", 202);
    gotoXY(x + 36, y + 10 + 3);
    printf("%c", 202);
    gotoXY(x + 52, y + 10 + 3);
    printf("%c", 202);
    gotoXY(x + 65, y + 10 + 3);
    printf("%c", 202);
    gotoXY(x + 71, y + 10 + 3);
    printf("%c", 202);
    //==========guide================

    Normal_Text();
}
void Draw_case_Top10() {
    //===============khoi tao danh sach mang con tro=============================
    DS_DauSach dsds;
    dsds.Init_DSDS();
    Sach * sach = NULL;
    Read_DS_DauSach_File(dsds);
    DauSach * ds_temp;
    //===========================================================================
    bool swapped = false;
    do {
        swapped = false;
        for (int i = 1; i < dsds.n; i++) {
            if (dsds.node[i - 1] -> Soluongmuon < dsds.node[i] -> Soluongmuon) {
                ds_temp = dsds.node[i - 1];
                dsds.node[i - 1] = dsds.node[i];
                dsds.node[i] = ds_temp;
                swapped = true;
            }
        }
    } while (swapped == true);

    //=================xu li giao dien====================
    int x = 17, y = 6, rong_title = 3, dai = 80, rong = rong_title + 10 - 1;
    system("cls");
    ColorAll();
    Draw_frame_Main(0, 0, X, Y); // ve lai khung, de tao case 1
    Draw_frame(x, y, dai, rong);
    Draw_Title_Case_Top10(x, y, dai);
    //====================================================

    for (int i = 0; i < 10; i++) {
        if (dsds.node[i] -> Soluongmuon != 0) {
            gotoxy(x + 1, y + i + 3);
            printf("%s", dsds.node[i] -> ISBN);
            gotoxy(x + 10, y + i + 3);
            printf("%s", dsds.node[i] -> Tensach);
            gotoxy(x + 37, y + i + 3);
            printf("%s", dsds.node[i] -> Tacgia);
            gotoxy(x + 53, y + i + 3);
            printf("%s", dsds.node[i] -> Theloai);
            gotoxy(x + 66, y + i + 3);
            printf("%d", dsds.node[i] -> Nxb);
            gotoxy(x + 72, y + i + 3);
            printf("%d", dsds.node[i] -> Soluongmuon);
        }
    }
    int key = 0;
    while (1) {
        key = GetKey();
        if (key == ESC) {
            return;
        }
    }
}
int Up_Down_Menu_Case3(char td[5][50]) {
    int cot_menu = 6 + X / 2 - 20;
    int dong_menu = Y / 2 - 10;
    Normal();
    system("cls");
    int so_item_menu_case3 = 5;
    Draw_frame_Main(0, 0, X, Y);
    int chon = 0;
    for (int i = 0; i < so_item_menu_case3; i++) {
        Draw_Button_Menu_Normal(td, cot_menu, dong_menu, i);
    }
    Draw_Button_Menu_Highligh(td, cot_menu, dong_menu, chon);
    char kytu;
    do {
        kytu = GetKey();
        switch (kytu) {
        case UP:
            if (chon > 0) {
                Draw_Button_Menu_Normal(td, cot_menu, dong_menu, chon);
                chon--;
                Draw_Button_Menu_Highligh(td, cot_menu, dong_menu, chon);
            }
            break;
        case DOWN:
            if (chon + 1 < so_item_menu_case3) {
                Draw_Button_Menu_Normal(td, cot_menu, dong_menu, chon);
                chon++;
                Draw_Button_Menu_Highligh(td, cot_menu, dong_menu, chon);
            }
            break;
        case ENTER:
            return chon + 1;
        case ESC:
            return ESC;
        } // end switch
    } while (1);
}
void Menu_Case_3() {
    char thucdon[5][50] = {
        "      1. MUON SACH          ",
        "      2. TRA SACH           ",
        "      3. DANH SACH QUA HAN  ",
        "      4. TOP 10 DAU SACH    ",
        "      5. QUAY LAI           "
    };
    int chon = 0;
    while (1) {
        chon = Up_Down_Menu_Case3(thucdon);
        switch (chon) {
        case 1:
            Draw_case_Muonsach();
            break;
        case 2:
            Draw_case_TraSach();
            break;
        case 3:
            Draw_case_DGQG_QH();
            break;
        case 4:
            Draw_case_Top10();
            break;
        case 5:
            Normal();
            system("cls");
            Draw_frame_Main(0, 0, X, Y);
            for (int i = 1; i <= 49; i++) {
                gotoxy(35 + i, 10);
                printf("%c %d%c", 219, i * 2, 37);
                Sleep(10);
            }
            gotoxy(35 + 50, 10);
            printf("%c %d%c", 219, 50 * 2, 37);
            Sleep(1000);
            return;

        case ESC:
            Normal();
            system("cls");
            Draw_frame_Main(0, 0, X, Y);
            for (int i = 1; i <= 49; i++) {
                gotoxy(35 + i, 10);
                printf("%c %d%c", 219, i * 2, 37);
                Sleep(10);
            }
            gotoxy(35 + 50, 10);
            printf("%c %d%c", 219, 50 * 2, 37);
            Sleep(1000);
            return;
        }
    }
}
void Draw_Case_3() {
    Menu_Case_3();
}
