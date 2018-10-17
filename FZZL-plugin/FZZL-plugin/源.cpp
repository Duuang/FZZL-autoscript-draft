#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string>
//#include <QtWidgets>

using namespace std;


class Stage {
public:
  Stage(const string &stagedescr, int stagetype, int ifauto, float zoom);
  int StartPlay();  //开始刷
  int StopPlay();  //TODO 停止刷
  
private:
  int ClearBag();  //TODO 自动贩卖
  void Click(int x, int y);  //前台点击，把缩放算进去了，目前用不上
  void SendClick(int x, int y); //后台点击，把缩放算进去了
  string stage_descr;  //关卡描述，如：3-10
  int stage_map, stage_num;  //关卡大地图编号、关卡编号
  int stage_type;   //关卡种类
  int ifauto;    //是否开了自动
  float zoom;    //windows系统缩放比例
  HWND mainhwnd, subhwnd, subwinhwnd;  //主窗口、子窗口、显示图像的subwin
  static int stage_clickpos[10][10][20][2];  //代表每关开始时鼠标要点哪， pos[stagetype][stagenum][(x, y)];
};

int Stage::stage_clickpos[10][10][20][2] = {};  //TODO  之后把这补上

Stage::Stage(const string &stagedescr, int stagetype, int ifauto, float zoom) {
  stage_descr = stagedescr;
  stage_map = stage_descr[0] - 48;
  stage_num = stage_descr[3] - 48 + (stage_descr[2] - 48) * 10;
  stage_type = stagetype;
  this->ifauto = ifauto;
  this->zoom = zoom;
  mainhwnd = FindWindowA(NULL, "方舟指令 - MuMu模拟器");  //主窗口
  subhwnd = FindWindowExA(mainhwnd, NULL, NULL, NULL);  //子窗口
  subwinhwnd = FindWindowExA(subhwnd, NULL, NULL, NULL);  //显示图像的subwin
  cout << subwinhwnd << endl;
}

int Stage::StartPlay() {
  if (stage_type == 1) {
    stage_clickpos[1][1][10][0] = 1149;   //TODO  之后要去掉。。stage_clickpos要初始化
    stage_clickpos[1][1][10][1] = 317;    //................
    while (true) {  //刷1-10
      SendClick(stage_clickpos[stage_type][stage_map][stage_num][0], 
                stage_clickpos[stage_type][stage_map][stage_num][1]); //点1-10
      Sleep(500);
      SendClick(991, 570);//进入副本
      Sleep(4000);
      SendClick(1092, 599);//战斗
      Sleep(1000);
      SendClick(1193, 284);//选助战
      Sleep(10000);
      Sleep(500);
      HDC hdc = GetDC(subwinhwnd);
      while (true) {
        COLORREF clr = GetPixel(hdc, (int)(1028 / zoom), (int)(460 / zoom));

        if ((int)GetRValue(clr) == 245 && (int)GetGValue(clr) == 234 && (int)GetBValue(clr) == 110) {
          break;
        }
        SendClick(945, 667);  //技能2
        Sleep(500);  
        SendClick(945, 667);
      }   
    }
  }
  return 0;
}

void Stage::Click(int x, int y) {
  SetCursorPos((int)(x / zoom), (int)(y / zoom));
  mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
  mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

void Stage::SendClick(int x, int y) {
  x = (int)(x / zoom);
  y = (int)(y / zoom);
  SendMessage(subhwnd, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(x, y));
  SendMessage(subhwnd, WM_LBUTTONUP, 0, MAKELPARAM(x, y));
}

int main() {
  string stagedescr = "1-10";
  int stagetype = 1;
  cout << "enter stage descr\n";
  //cin >> stagenum;
  cout << "enter stage type\n";
  //cin >> stagetype;
  Stage currentstage(stagedescr, stagetype, 1, 1.5);
  currentstage.StartPlay();


  
  /*
  POINT p;
  HWND mainhwnd = FindWindowA(NULL, "方舟指令 - MuMu模拟器");  //主窗口
  HWND subhwnd = FindWindowExA(mainhwnd, NULL, NULL, NULL);  //子窗口
  HWND subwinhwnd = FindWindowExA(subhwnd, NULL, NULL, NULL);  //显示图像的subwin
  cout << subwinhwnd << endl;
  
  Sleep(5000);
  //SendMessage(subhwnd,WM_LBUTTONDOWN,MK_LBUTTON,MAKELPARAM(10,10));
  //SendMessage(subhwnd,WM_LBUTTONUP,0,MAKELPARAM(10, 10));
  cout << mainhwnd << endl;
  //HDC hdc = GetDC(subwinhwnd);
  //COLORREF clr = GetPixel(hdc, 918, 563);
  //cout << (int)GetRValue(clr) << ", " << (int)GetGValue(clr) << ", " << (int)GetBValue(clr) << endl;
  system("pause");
  //HWND hq = FindWindowA(NULL, "新标签页 - Google Chrome");
  RECT rect;    
  GetWindowRect(mainhwnd,&rect);     
  int w=rect.right-rect.left,h=rect.bottom-rect.top;  
  cout<<"宽:"<<w<<" "<<"高:"<<h<<endl;  
  //MoveWindow(mainhwnd,100,100, w, h, false); 
  Sleep(1000);


  /*
  //hq = (HWND)(0x00060330);
  GetCursorPos(&p);
  SendMessage(hq,WM_LBUTTONDOWN,MK_LBUTTON,MAKELPARAM(1637,812));
  00705BC
001204DE
  SendMessage(hq,WM_LBUTTONUP,0,MAKELPARAM(1637,812));
  Sleep(20000);
  system("pause");

 //1058, 750
   //705, 500
   //245, 234, 110
  HDC hdc = GetDC(NULL);
  COLORREF clr = ::GetPixel(hdc, 1007, 700);
  cout << (int)GetRValue(clr) << ", " << (int)GetGValue(clr) << ", " << (int)GetBValue(clr) << endl;
  system("pause");
  */
  /*
  while (true) {  //刷1-10
    //break;
    SendClick(subhwnd, 1149/1.5, 317/1.5); //点1-10
    Sleep(500);
    SendClick(subhwnd, 991/1.5, 570/1.5);//进入副本
    Sleep(4000);
    SendClick(subhwnd, 1092/1.5, 599/1.5);//战斗
    Sleep(1000);
    SendClick(subhwnd, 1193/1.5, 284/1.5);//选助战
    Sleep(10000);
    //SendClick(subhwnd, 1155, 670);
    Sleep(500);
    //SendClick(subhwnd, 1155, 670);//技能3
    ///Sleep(13000);
    HDC hdc = GetDC(subwinhwnd);
    while (true) {
      COLORREF clr = ::GetPixel(hdc, 1028/1.5, 460/1.5);

      if ((int)GetRValue(clr) == 245 && (int)GetGValue(clr) == 234 && (int)GetBValue(clr) == 110) {
        break;
      }
      SendClick(subhwnd, 945/1.5, 667/1.5);
      Sleep(500);  //技能2
      SendClick(subhwnd, 945/1.5, 667/1.5);
    }   
  } 

  while (true) {  //刷3-4
    break;
    SendClick(subhwnd, 1042, 307); //点3-10
    Sleep(500);
    SendClick(subhwnd, 991, 570);//进入副本
    Sleep(500);
    SendClick(subhwnd, 991, 570);//选择队伍
    Sleep(1000);
    SendClick(subhwnd, 1178, 672);//自动寻路
    Sleep(4000);
    SendClick(subhwnd, 1092, 599);//战斗
    Sleep(1000);
    SendClick(subhwnd, 1193, 284);//选助战
    //Sleep(10000);
    //SendClick(subhwnd, 1155, 670);
    //Sleep(500);
    //SendClick(subhwnd, 1155, 670);//技能3
    ///Sleep(13000);
    HDC hdc = GetDC(subwinhwnd);
    while (true) {
      COLORREF clr = ::GetPixel(hdc, 1042, 307);

      if ((int)GetRValue(clr) == 3 && (int)GetGValue(clr) == 100 && (int)GetBValue(clr) == 219) {
        break;
      }
      SendClick(subhwnd, 1092, 599);//战斗
      Sleep(500);
      SendClick(subhwnd, 1193, 284);
      Sleep(500);
      SendClick(subhwnd, 1193, 284);//选助战
      //SendClick(subhwnd, 945, 667);
      //Sleep(500);  //技能2
      //SendClick(subhwnd, 945, 667);
    }   
  }


  while (true) {  //刷3-10
    break;
    SendClick(subhwnd, 1113, 454); //点3-10
    Sleep(500);
    SendClick(subhwnd, 991, 570);//进入副本
    Sleep(4000);
    SendClick(subhwnd, 1092, 599);//战斗
    Sleep(1000);
    SendClick(subhwnd, 1193, 284);//选助战
    Sleep(10000);
    //SendClick(subhwnd, 1155, 670);
    Sleep(500);
    //SendClick(subhwnd, 1155, 670);//技能3
    ///Sleep(13000);
    HDC hdc = GetDC(subwinhwnd);
    while (true) {
      COLORREF clr = ::GetPixel(hdc, 918, 563);

      if ((int)GetRValue(clr) == 245 && (int)GetGValue(clr) == 234 && (int)GetBValue(clr) == 110) {
        break;
      }
      SendClick(subhwnd, 945, 667);
      Sleep(500);  //技能2
      SendClick(subhwnd, 945, 667);
    }   
  }
  while (true) {  //刷1-10
    //break;
    SendClick(subhwnd, 1149, 317); //点1-10
    Sleep(500);
    SendClick(subhwnd, 991, 570);//进入副本
    Sleep(4000);
    SendClick(subhwnd, 1092, 599);//战斗
    Sleep(1000);
    SendClick(subhwnd, 1193, 284);//选助战
    Sleep(10000);
    //SendClick(subhwnd, 1155, 670);
    Sleep(500);
    //SendClick(subhwnd, 1155, 670);//技能3
    ///Sleep(13000);
    HDC hdc = GetDC(subwinhwnd);
    while (true) {
      COLORREF clr = ::GetPixel(hdc, 1028, 460);

      if ((int)GetRValue(clr) == 245 && (int)GetGValue(clr) == 234 && (int)GetBValue(clr) == 110) {
        break;
      }
      SendClick(subhwnd, 945, 667);
      Sleep(500);  //技能2
      SendClick(subhwnd, 945, 667);
    }   
  } 
  
  while (true) {  //刷高难本
    SendClick(subhwnd, 1015, 344); //选60级难度
    Sleep(500);
    SendClick(subhwnd, 630, 607);//点挑战
    Sleep(4000);
    SendClick(subhwnd, 1092, 599);//战斗
    Sleep(1000);
    SendClick(subhwnd, 1193, 284);//选助战
    Sleep(20000);

    HDC hdc = GetDC(subwinhwnd);
    while (true) {
      SendClick(subhwnd, 945, 667);
      Sleep(500);
      SendClick(subhwnd, 945, 667);//技能2
      COLORREF clr = ::GetPixel(hdc, 737, 589);

      if ((int)GetRValue(clr) == 255 && (int)GetGValue(clr) == 234 && (int)GetBValue(clr) == 0) {
        break;
      }

    }   
  } 
    
*/

    
}