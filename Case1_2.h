#include "Xu_Li_De.h"
#include "GiaoDien.h"
//===================================MENU CASE 1========================================
const int sodong_dsdg=17;
int sl_page; // tong so luong trang	 



void Draw_Title(int x,int y, int dai){ // tieu de cua ds
	Draw_H(x,y+2,dai);
	//Ma doc gia
	gotoXY(x+1,y+1);
	printf("%s %c"," MA DOC GIA ",186);
	//Ho
	gotoXY(x+14,y);
	printf("%c",203);
	gotoXY(x+14,y+2);
	printf("%c",206);
	gotoXY(x+16,y+1);
	printf("%s %c","        HO       ",186);
	//Ten
	gotoXY(x+34,y);
	printf("%c",203);
	gotoXY(x+34,y+2);
	printf("%c",206);
	gotoXY(x+37,y+1);
	printf("%s %c","    TEN    ",186);
	//Phai
	gotoXY(x+49,y);
	printf("%c",203);
	gotoXY(x+49,y+2);
	printf("%c",206);
	gotoXY(x+51,y+1);
	printf("%s %c","PHAI",186);
	//Trang thai
	gotoXY(x+56,y);
	printf("%c",203);
	gotoXY(x+56,y+2);
	printf("%c",206);
	gotoXY(x+58,y+1);
	printf("%s","  TRANG THAI");
	//ve hang phan cach
	
	for(int i = y+3; i<y+sodong_dsdg+3; i ++){
		gotoXY(x+14,i);
		printf("%c",186);
		gotoXY(x+34,i);
		printf("%c",186);
		gotoXY(x+49,i);
		printf("%c",186);
		gotoXY(x+56,i);
		printf("%c",186);
	}
	gotoXY(x+14,y+sodong_dsdg+3);
	printf("%c",202);
	gotoXY(x+34,y+sodong_dsdg+3);
	printf("%c",202);
	gotoXY(x+49,y+sodong_dsdg+3);
	printf("%c",202);
	gotoXY(x+56,y+sodong_dsdg+3);
	printf("%c",202);
	
}
void Draw_View_1DG_Case1(DocGia dg){
	//clear data view
	gotoxy(88,7); printf("                          ");
	gotoxy(88,9); printf("                          ");
	gotoxy(88,11); printf("                          ");
	gotoxy(88,13); printf("                          ");
	gotoxy(88,15); printf("                          ");
	
	
	//dien thong tin vao view
	gotoxy(88,7); printf("%d",dg.Mathe);
	gotoxy(88,9); printf("%s",dg.Ho);
	gotoxy(88,11); printf("%s",dg.Ten);
	gotoxy(88,13); printf("%d   (1: NAM, 0: NU)",dg.phai);
	gotoxy(88,15); printf("%d   (1: ACTIVE, 0: BLOCK)",dg.phai);
}
void Draw_1_DG(DocGia dg,int x,int y){ // hien thi 1 doc gia trong ds
	
	Draw_View_1DG_Case1(dg);
	//Ma doc gia
	gotoXY(x+1,y);
	printf("   %d",dg.Mathe);
	//Ho
	gotoXY(x+16,y);
	printf("%s",dg.Ho);
	//Ten
	
	gotoXY(x+36,y);
	printf("  %s",dg.Ten);
	//Phai
	if(dg.phai==1){
		gotoXY(x+50,y);
		printf("  %s","NAM");
	}else{
		gotoXY(x+50,y);
		printf("  %s","NU");
	}
	//Trang thai
	if(dg.trangthai==1){
		gotoXY(x+57,y);
		printf("   %s","HOAT DONG  ");
	}else{
		gotoXY(x+57,y);
		printf("   %s","BI KHOA  ");
	}
	
	
}
//==============2 nut sap xep=====================
void Draw_Button_Sort_Mathe(int x, int y){
	gotoxy(x+1,y+1);
	printf("DANH SACH DANG SAP XEP THEO:");
	gotoxy(x+1,y+2);
	printf("(F1: doi cach sap xep)");
	x+=30;
	HighLight();
	gotoxy(x,y);
	printf("        ");
	gotoxy(x,y+1);
	printf(" MA THE ");
	gotoxy(x,y+2);
	printf("        ");
	Normal();
	gotoxy(x+8,y);
	printf("        ");
	gotoxy(x+8,y+1);
	printf(" HO TEN ");
	gotoxy(x+8,y+2);
	printf("        ");
	Normal_Text();
}
void Draw_Button_Sort_HoTen(int x, int y){
	gotoxy(x+1,y+1);
	printf("DANH SACH DANG SAP XEP THEO:");
	gotoxy(x+1,y+2);
	printf("(F1: doi cach sap xep)");
	x+=30;
	Normal();
	gotoxy(x,y);
	printf("        ");
	gotoxy(x,y+1);
	printf(" MA THE ");
	gotoxy(x,y+2);
	printf("        ");
	HighLight();
	gotoxy(x+8,y);
	printf("        ");
	gotoxy(x+8,y+1);
	printf(" HO TEN ");
	gotoxy(x+8,y+2);
	printf("        ");
	Normal_Text();
}
//================DIALOG MESSS BOX YES NO / DELETE DG=================
int Dialog_Mess_Box(int x, int y){
	int check=0,key;
	Normal_Text();
	Draw_frame(x,y,26,5);
	gotoxy(x+1,y+1);
	printf("BAN CO CHAC CHAN MUON XOA?");
	while(1){
		if(check==1){
			HighLight();
			gotoxy(x+4,y+3);
			printf("      ");
			gotoxy(x+4,y+4);
			printf(" YES  ");
			gotoxy(x+4,y+5);
			printf("      ");	
			
			Normal();
			gotoxy(x+18,y+3);
			printf("      ");
			gotoxy(x+18,y+4);
			printf("  NO  ");
			gotoxy(x+18,y+5);
			printf("      ");		
		}else{
			Normal();
			gotoxy(x+4,y+3);
			printf("      ");
			gotoxy(x+4,y+4);
			printf(" YES  ");
			gotoxy(x+4,y+5);
			printf("      ");	
			
			HighLight();
			gotoxy(x+18,y+3);
			printf("      ");
			gotoxy(x+18,y+4);
			printf("  NO  ");
			gotoxy(x+18,y+5);
			printf("      ");	
		}
		key = GetKey();
		switch(key){
			case LEFT:
				check=1;
				break;
			case RIGHT:
				check=0;
				break;
			case ENTER:
				Normal_Text();
				for(int i=x;i<=x+27;i++){
					for(int j=y;j<y+7;j++){
						gotoxy(i,j);
						printf(" ");
					}
				}
				return check;
		}
	}
}
// =============lam sach lai ds hien thi========================
void Clear_DSDG(int x,int y,int dai,int rong){
	Normal_Text();
	for(int i=x; i<x+dai; i++){
		for(int j=y;j<y+rong;j++){
			gotoxy(i,j);
			printf(" ");
		}
	}
	Draw_Title(1,6,70);
}
void Show_DSDG(DanhSach_DG dsdg,int page_hientai,int x,int y,int sodong){// hien thi dsdg cua 1 trang
	Normal_Text();
	Clear_DSDG(x+1,y,70,sodong_dsdg);
	for(int i=page_hientai*sodong_dsdg; i<page_hientai*sodong_dsdg+sodong;i++){
		Draw_1_DG(*dsdg.DG[i],x,y+(i-page_hientai*sodong_dsdg));
	}
	//================page hien tai / sl page vi du trang 5/6==================
	gotoxy((x+60)/2,y+sodong_dsdg+2);
	printf("Trang ");
	HighLight();
	printf("%d / %d",page_hientai+1,sl_page);
	Normal();
	//==============in dong dau tien=====================
	HighLight_Text();
	Draw_1_DG(*dsdg.DG[page_hientai*sodong_dsdg],x,y);
}
void Draw_fram_view(){
	//==================================VE KHUNG NHO BEN PHAI=======================
	int x_view = 74, y_view = 6, dai_view = 40, rong_view = 9;
	Draw_frame(x_view,y_view,dai_view,rong_view);
	Draw_H(x_view,y_view+2,dai_view);
	Draw_H(x_view,y_view+4,dai_view);
	Draw_H(x_view,y_view+6,dai_view);
	Draw_H(x_view,y_view+8,dai_view);
	gotoxy(x_view+1,y_view+1); printf("MA DOC GIA");
	gotoxy(x_view+12,y_view); printf("%c",203);
	gotoxy(x_view+12,y_view+1); printf("%c",186);
	gotoxy(x_view+12,y_view+2); printf("%c",206);
	gotoxy(x_view+1,y_view+3); printf("    HO   ");
	gotoxy(x_view+12,y_view+3); printf("%c",186);
	gotoxy(x_view+12,y_view+4); printf("%c",206);
	gotoxy(x_view+1,y_view+5); printf("   TEN  ");
	gotoxy(x_view+12,y_view+5); printf("%c",186);
	gotoxy(x_view+12,y_view+6); printf("%c",206);
	gotoxy(x_view+1,y_view+7); printf("   PHAI ");
	gotoxy(x_view+12,y_view+7); printf("%c",186);
	gotoxy(x_view+12,y_view+8); printf("%c",206);
	gotoxy(x_view+1,y_view+9); printf("TRANG THAI ");
	gotoxy(x_view+12,y_view+9); printf("%c",186);
	gotoxy(x_view+12,y_view+10); printf("%c",202);
	
}
//===================XU LI NHAP 1 CHUOI======================
char* Input_Str(char str[],int x,int y,int length){
	int k;
	int len;
	Normal_Text();
	gotoxy(x,y);
	len = strlen(str);
	cout<<str;
	while(len<length){
		k = GetKey();
		if(k>=97 && k<=122 && len<length){
			str[len]=k-32;
			gotoxy(x,y);
			len = strlen(str);
			cout<<str;
		}else if(k>=65 && k<=96 && len<length){
			str[len]=k;
			gotoxy(x,y);
			len = strlen(str);
			cout<<str;
		}else if(k==BACKSPACE){
			str[len-1]=NULL;
			gotoxy(x,y);
			printf("                  ");
			gotoxy(x,y);
			len = strlen(str);
			cout<<str;
		}else if(k==SPACE){
			if(str[len-1]!=char(255) && len>0 && len<length){
				str[len]=255;
			}
			gotoxy(x,y);
			len = strlen(str);
			cout<<str;
		}else if(k==ENTER || k ==TAB || k ==DOWN || k==ESC || k==UP){
			gotoxy(x,y);
			HighLight_Text();
			cout<<str;
			return str;
		}
	};
	return str;
}
//===============Hàm kiem tra du lieu dau vao cua 1 doc gia==================
int Check_Inp_DG(DocGia dg){
	
	if(strlen(dg.Ho)==0){
		return 0;
	}
	if(strlen(dg.Ten)==0){
		return 0;
	}
	if(dg.phai!=0 && dg.phai!=1){
		return 0;
	}
	if(dg.trangthai!=0 && dg.trangthai!=1){
		return 0;
	}
	return 1;
}
int Input_0_1(int kt,int x,int y){
	int key;
	int k = kt;
	Normal_Text();
	gotoxy(x,y);
	cout<<k;
	do{
		key=GetKey();
		if(key == 48){
			k=0;
			gotoxy(x,y);
			cout<<k;
		}else if(key == 49){
			k=1;
			gotoxy(x,y);
			cout<<k;
		}else if(key == BACKSPACE){
			k=NULL;
			gotoxy(x,y);
			cout<<" ";
		}else if(key == ENTER || key == TAB || key ==UP || key ==DOWN){
			HighLight_Text();
			gotoxy(x,y);
			cout<<k;
			return k;
		}
	}while(k<9);
	
}
enum DG_detail{
	MA_DG,HO_DG,TEN_DG,PHAI_DG,TRANGTHAI_DG
};
//========================THEM 1 DG MOI ========================
void Add_1_DG(NodeDG p){
	DG_detail dg_detail=HO_DG;
	DocGia dg = DocGia();
	int chon=0;
	char data[40];
	dg.Mathe = Random_MaDG(p);
	//clear data view 
	gotoxy(88,7); printf("                         ");
	gotoxy(88,9); printf("                         ");
	gotoxy(88,11); printf("                         ");
	gotoxy(88,13); printf("    (1: NAM, 0: NU)      ");
	gotoxy(88,15); printf("    (1: ACTIVE, 0: BLOCK)");
	gotoxy(88,7); cout<<dg.Mathe;
	do{
		gotoxy(88,9+chon*2);
	 	if(wherey()==9){
	 		cout<<dg.Ho;
	 		char str[sizeof(dg.Ho)]="";
	 		strcpy(str,dg.Ho);
	 		strcpy(dg.Ho,Input_Str(str,88,9+chon*2,sizeof(dg.Ho)-1));
		 }else if(wherey()==11){
			cout<<dg.Ten;
	 		char str[sizeof(dg.Ten)]="";
	 		strcpy(str,dg.Ten);
	 		strcpy(dg.Ten,Input_Str(str,88,9+chon*2,sizeof(dg.Ten)-1));
		}else if(wherey()==13){
			gotoxy(88,9+chon*2);
			cout<<dg.phai;
			dg.phai = Input_0_1(dg.phai,88,9+chon*2);
		} else if(wherey()==15){
			gotoxy(88,9+chon*2);
			cout<<dg.trangthai;
			dg.trangthai = Input_0_1(dg.trangthai,88,9+chon*2);
		}
	 	int key = GetKey();
	 	switch(key){
	 		case UP:
	 			if(chon>0){
	 				chon--;
				 }
				 break;
			case DOWN:
	 			if(chon+1<4){
	 				chon++;
				}
				 break;
			case ENTER:
	 			if(chon+1<4){
	 				chon++;
				}
				 break;
			case TAB:
	 			if(chon+1<4){
	 				chon++;
				}
				 break;
			case CTRL_S:
				if(Check_Inp_DG(dg)==1){
					Insert_DG(p,dg);
					Save_Tree_File(p);
					Read_Tree_File(p);
					
					//=======thong bao them thanh cong==========
					gotoxy(76,17);
					Normal_Text();
					cout<<"THEM DOC GIA THANH CONG!";
					Sleep(2000);
					gotoxy(76,17);
					Normal_Text();
					cout<<"                               ";
					gotoxy(88,9+chon*2);
					return;
				}else{
					gotoxy(76,17);
					HighLight_Text();
					cout<<"DU LIEU NHAP VAO CHUA DUNG!";
					Sleep(2000);
					gotoxy(76,17);
					Normal_Text();
					cout<<"                            ";
					gotoxy(88,9+chon*2);
					break;
				}
				
			case ESC:
				return;
		 }
		
	}while(1);
//	gotoxy(88,7); cout<<dg.Mathe;
//	gotoxy(88,9); cin>>dg.Ho;
//	gotoxy(88,11); cin>>dg.Ten;
//	gotoxy(88,13); cin>>dg.phai;
//	gotoxy(88,15); cin>>dg.trangthai;
}
//=============================EDIT 1 DG===============================
void Edit_1_DG(DocGia &dg){
	int chon=0;
	char data[40];
	//clear data view 
	gotoxy(88,7); printf("                         ");
	gotoxy(88,9); printf("                         ");
	gotoxy(88,11); printf("                         ");
	gotoxy(88,13); printf("    (1: NAM, 0: NU)      ");
	gotoxy(88,15); printf("    (1: ACTIVE, 0: BLOCK)");
	
	
	gotoxy(88,7); cout<<dg.Mathe;
	gotoxy(88,9); cout<<dg.Ho;
	gotoxy(88,11); cout<<dg.Ten;
	gotoxy(88,13); cout<<dg.phai;
	gotoxy(88,15); cout<<dg.trangthai;
	
	do{
		
		gotoxy(88,9+chon*2);
	 	if(wherey()==9){
	 		cout<<dg.Ho;
	 		char str[sizeof(dg.Ho)]="";
	 		strcpy(str,dg.Ho);
	 		strcpy(dg.Ho,Input_Str(str,88,9+chon*2,sizeof(dg.Ho)-1));
		 }else if(wherey()==11){
			cout<<dg.Ten;
	 		char str[sizeof(dg.Ten)]="";
	 		strcpy(str,dg.Ten);
	 		strcpy(dg.Ten,Input_Str(str,88,9+chon*2,sizeof(dg.Ten)-1));
		}else if(wherey()==13){
			gotoxy(88,9+chon*2);
			cout<<dg.phai;
			dg.phai = Input_0_1(dg.phai,88,9+chon*2);
		} else if(wherey()==15){
			gotoxy(88,9+chon*2);
			cout<<dg.trangthai;
			dg.trangthai = Input_0_1(dg.trangthai,88,9+chon*2);
		}
	 	int key = GetKey();
	 	switch(key){
	 		case UP:
	 			if(chon>0){
	 				chon--;
				 }
				 break;
			case DOWN:
	 			if(chon+1<4){
	 				chon++;
				}
				 break;
			case ENTER:
	 			if(chon+1<4){
	 				chon++;
				}
				 break;
			case TAB:
	 			if(chon+1<4){
	 				chon++;
				}
				 break;
			case CTRL_S:
				if(Check_Inp_DG(dg)==1){
					gotoxy(76,17);
					Normal_Text();
					cout<<"CHINH SUA DOC GIA THANH CONG!";
					Sleep(2000);
					gotoxy(76,17);
					Normal_Text();
					cout<<"                               ";
					return;
				}else{
					gotoxy(76,17);
					HighLight_Text();
					cout<<"DU LIEU NHAP VAO CHUA DUNG!";
					Sleep(2000);
					gotoxy(76,17);
					Normal_Text();
					cout<<"                              ";
					gotoxy(88,9+chon*2);
					break;
				}
				
			case ESC:
				return;
		 }
		
	}while(1);
}

enum Mode {// mode la gia tri co dinh
		MA_THE,HO_TEN
	};
void Draw_Case_1(){
	int x=1, y=6,rong_title = 3, dai=70, rong = rong_title+sodong_dsdg-1;
	Mode mode;
	mode = MA_THE;
	//=================xu li giao dien====================
	system("cls");
	ColorAll();
	Draw_frame_Main(0,0,X,Y); // ve lai khung, de tao case 1
	Draw_frame(x,y,dai,rong);
	Draw_fram_view();
	//ColorAll();
	Draw_Title(x,y,dai);
	//==================== khoi tao cay=================
	DocGia dg;
	NodeDG tree;
	DanhSach_DG dsdg;
	Init_Tree(tree);
	Read_Tree_File(tree);
	dsdg.Reset_DSDG();
	dsdg.Insert_DG_to_DSDG(tree);
	
	//========PHAN TRANG==========
	sl_page=0; // tong so luong trang	 
	if(dsdg.n % sodong_dsdg ==0){
		sl_page = dsdg.n/sodong_dsdg;
	}else{
		sl_page = dsdg.n/sodong_dsdg+1;
	}
	int page_hientai = 0; // trang hien tai
	//int sodong_page=sodong_dsdg;//so dong hien tai cua trang hien tai (<=sodong_dsdg)
	
	//=========hien ds doc gia=========
	int chon=0;
	char key;
	int so_item; 
	if(dsdg.n<sodong_dsdg){
		so_item = dsdg.n;
	}else{
		so_item = sodong_dsdg;
	}
	Draw_Button_Sort_Mathe(x,y-3);
	Show_DSDG(dsdg,page_hientai,x,y+rong_title,so_item);
	
	do
   {
      key = GetKey();
      switch (key)
      {
    case UP:
         if (chon > 0)
         {
         	Normal_Text();
            Draw_1_DG(*dsdg.DG[page_hientai*sodong_dsdg+chon],x,y+rong_title+chon);
            chon--;
            HighLight_Text();
            Draw_1_DG(*dsdg.DG[page_hientai*sodong_dsdg+chon],x,y+rong_title+chon);
         }
         break;
    case DOWN:
         if (chon + 1 < so_item)
         {
            Normal_Text();
            Draw_1_DG(*dsdg.DG[page_hientai*sodong_dsdg+chon],x,y+3+chon);
            chon++;
            HighLight_Text();
            Draw_1_DG(*dsdg.DG[page_hientai*sodong_dsdg+chon],x,y+3+chon);
         }
         break;
    case LEFT:
         if (page_hientai > 0)
         {
         	if(dsdg.n<sodong_dsdg){
				so_item = dsdg.n;
			}else{
				so_item = sodong_dsdg;
			}
         	page_hientai--;
            Show_DSDG(dsdg,page_hientai,x,y+rong_title,so_item);
            chon=0;
         }
         break;
    case RIGHT:
         if (page_hientai + 1< sl_page)
         {
         	
         	if(page_hientai+2==sl_page){
      			so_item=dsdg.n - (sodong_dsdg*(page_hientai+1));
	  		}else{
	  			so_item=sodong_dsdg;
			}
			page_hientai++;
			gotoxy(90,y-3);
         	
            Show_DSDG(dsdg,page_hientai,x,y+rong_title,so_item);
            chon=0; //phai tra con tro ve 0 neu khong nguoi dung tro den cuoi dong va chuyen qua trang khac thi se bi loi
         }
         break;
    
    case F1:
    	if(mode != MA_THE){
    		Normal_Text();
	    	dsdg.Sort_DSDG_Mathe();
	    	Draw_Button_Sort_Mathe(x,y-3);
	    	page_hientai=0;
	    	if(dsdg.n<sodong_dsdg){
				so_item = dsdg.n;
			}else{
				so_item = sodong_dsdg;
			}
	        Show_DSDG(dsdg,page_hientai,x,y+rong_title,so_item);
			chon=0; // dua con tro ve vi tri hang dau tien
			mode = MA_THE;
	        break;
		}else{
			//ColorAll();
	    	Normal_Text();
	    	dsdg.Sort_DSDG_Ten();
	    	Draw_Button_Sort_HoTen(x,y-3);
	    	page_hientai=0;
	    	if(dsdg.n<sodong_dsdg){
				so_item = dsdg.n;
			}else{
				so_item = sodong_dsdg;
			}
	        Show_DSDG(dsdg,page_hientai,x,y+rong_title,so_item);
			chon=0; // dua con tro ve vi tri hang dau tien
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
		if(dsdg.n % sodong_dsdg ==0){
			sl_page = dsdg.n/sodong_dsdg;
		}else{
			sl_page = dsdg.n/sodong_dsdg+1;
		}
			Normal_Text();
	    	dsdg.Sort_DSDG_Mathe();
	    	Draw_Button_Sort_Mathe(x,y-3);
	    	page_hientai=0;
	    	if(dsdg.n<sodong_dsdg){
				so_item = dsdg.n;
			}else{
				so_item = sodong_dsdg;
			}
	        Show_DSDG(dsdg,page_hientai,x,y+rong_title,so_item);
			chon=0; // dua con tro ve vi tri hang dau tien
	        break;
	case F3:
    	//DocGia dg;
       	Edit_1_DG(*dsdg.DG[page_hientai*sodong_dsdg+chon]);
    	Save_Tree_File(tree);
		Read_Tree_File(tree);
		//===============cap nhat sl page==================
		if(dsdg.n % sodong_dsdg ==0){
			sl_page = dsdg.n/sodong_dsdg;
		}else{
			sl_page = dsdg.n/sodong_dsdg+1;
		}
			Normal_Text();
	    	dsdg.Sort_DSDG_Ten();
	    	Draw_Button_Sort_Mathe(x,y-3);
	    	page_hientai=0;
	    	if(dsdg.n<sodong_dsdg){
				so_item = dsdg.n;
			}else{
				so_item = sodong_dsdg;
			}
	        Show_DSDG(dsdg,page_hientai,x,y+rong_title,so_item);
			chon=0; // dua con tro ve vi tri hang dau tien
	        break;
	case DEL:
    	//DocGia dg;>
    	if(Dialog_Mess_Box(74,20)==1){
    		Remove_DG(tree,dsdg.DG[page_hientai*sodong_dsdg+chon]->Mathe);
	    	Save_Tree_File(tree);
			Read_Tree_File(tree);
	        dsdg.Reset_DSDG();
			dsdg.Insert_DG_to_DSDG(tree);
        
		//===============cap nhat sl page==================
		if(dsdg.n % sodong_dsdg ==0){
			sl_page = dsdg.n/sodong_dsdg;
		}else{
			sl_page = dsdg.n/sodong_dsdg+1;
		}
			Normal_Text();
	    	dsdg.Sort_DSDG_Mathe();
	    	Draw_Button_Sort_Mathe(x,y-3);
	    	page_hientai=0;
	    	if(dsdg.n<sodong_dsdg){
				so_item = dsdg.n;
			}else{
				so_item = sodong_dsdg;
			}
	        Show_DSDG(dsdg,page_hientai,x,y+rong_title,so_item);
			chon=0; // dua con tro ve vi tri hang dau tien
		}
    	break;
	
	case ESC:
		return;
	}
	// end switch
   } while (1);
	
}
