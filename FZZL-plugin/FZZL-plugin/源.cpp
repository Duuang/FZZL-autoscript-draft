#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string>
//#include <QtWidgets>

using namespace std;

void click(int x, int y) {
  SetCursorPos(x, y);
  mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
  mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
}

void send_click(HWND &hwnd, int x, int y) {
  SendMessage(hwnd,WM_LBUTTONDOWN,MK_LBUTTON,MAKELPARAM(x,y));
  SendMessage(hwnd,WM_LBUTTONUP,0,MAKELPARAM(x, y));
}

int main() {
  POINT p;
  HWND mainhwnd = FindWindowA(NULL, "����ָ�� - MuMuģ����");  //������
  HWND subhwnd = FindWindowExA(mainhwnd, NULL, NULL, NULL);  //�Ӵ���
  HWND subwinhwnd = FindWindowExA(subhwnd, NULL, NULL, NULL);  //��ʾͼ���subwin
  cout << subwinhwnd << endl;
  
  Sleep(5000);
  //SendMessage(subhwnd,WM_LBUTTONDOWN,MK_LBUTTON,MAKELPARAM(10,10));
  //SendMessage(subhwnd,WM_LBUTTONUP,0,MAKELPARAM(10, 10));
  cout << mainhwnd << endl;
  //HDC hdc = GetDC(subwinhwnd);
  //COLORREF clr = GetPixel(hdc, 918, 563);
  //cout << (int)GetRValue(clr) << ", " << (int)GetGValue(clr) << ", " << (int)GetBValue(clr) << endl;
  system("pause");
  //HWND hq = FindWindowA(NULL, "�±�ǩҳ - Google Chrome");
  RECT rect;    
  GetWindowRect(mainhwnd,&rect);     
  int w=rect.right-rect.left,h=rect.bottom-rect.top;  
  cout<<"��:"<<w<<" "<<"��:"<<h<<endl;  
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
  while (true) {  //ˢ1-10
    //break;
    send_click(subhwnd, 1149/1.5, 317/1.5); //��1-10
    Sleep(500);
    send_click(subhwnd, 991/1.5, 570/1.5);//���븱��
    Sleep(4000);
    send_click(subhwnd, 1092/1.5, 599/1.5);//ս��
    Sleep(1000);
    send_click(subhwnd, 1193/1.5, 284/1.5);//ѡ��ս
    Sleep(10000);
    //send_click(subhwnd, 1155, 670);
    Sleep(500);
    //send_click(subhwnd, 1155, 670);//����3
    ///Sleep(13000);
    HDC hdc = GetDC(subwinhwnd);
    while (true) {
      COLORREF clr = ::GetPixel(hdc, 1028/1.5, 460/1.5);

      if ((int)GetRValue(clr) == 245 && (int)GetGValue(clr) == 234 && (int)GetBValue(clr) == 110) {
        break;
      }
      send_click(subhwnd, 945/1.5, 667/1.5);
      Sleep(500);  //����2
      send_click(subhwnd, 945/1.5, 667/1.5);
    }   
  } 

  while (true) {  //ˢ3-4
    break;
    send_click(subhwnd, 1042, 307); //��3-10
    Sleep(500);
    send_click(subhwnd, 991, 570);//���븱��
    Sleep(500);
    send_click(subhwnd, 991, 570);//ѡ�����
    Sleep(1000);
    send_click(subhwnd, 1178, 672);//�Զ�Ѱ·
    Sleep(4000);
    send_click(subhwnd, 1092, 599);//ս��
    Sleep(1000);
    send_click(subhwnd, 1193, 284);//ѡ��ս
    //Sleep(10000);
    //send_click(subhwnd, 1155, 670);
    //Sleep(500);
    //send_click(subhwnd, 1155, 670);//����3
    ///Sleep(13000);
    HDC hdc = GetDC(subwinhwnd);
    while (true) {
      COLORREF clr = ::GetPixel(hdc, 1042, 307);

      if ((int)GetRValue(clr) == 3 && (int)GetGValue(clr) == 100 && (int)GetBValue(clr) == 219) {
        break;
      }
      send_click(subhwnd, 1092, 599);//ս��
      Sleep(500);
      send_click(subhwnd, 1193, 284);
      Sleep(500);
      send_click(subhwnd, 1193, 284);//ѡ��ս
      //send_click(subhwnd, 945, 667);
      //Sleep(500);  //����2
      //send_click(subhwnd, 945, 667);
    }   
  }


  while (true) {  //ˢ3-10
    break;
    send_click(subhwnd, 1113, 454); //��3-10
    Sleep(500);
    send_click(subhwnd, 991, 570);//���븱��
    Sleep(4000);
    send_click(subhwnd, 1092, 599);//ս��
    Sleep(1000);
    send_click(subhwnd, 1193, 284);//ѡ��ս
    Sleep(10000);
    //send_click(subhwnd, 1155, 670);
    Sleep(500);
    //send_click(subhwnd, 1155, 670);//����3
    ///Sleep(13000);
    HDC hdc = GetDC(subwinhwnd);
    while (true) {
      COLORREF clr = ::GetPixel(hdc, 918, 563);

      if ((int)GetRValue(clr) == 245 && (int)GetGValue(clr) == 234 && (int)GetBValue(clr) == 110) {
        break;
      }
      send_click(subhwnd, 945, 667);
      Sleep(500);  //����2
      send_click(subhwnd, 945, 667);
    }   
  }
  while (true) {  //ˢ1-10
    //break;
    send_click(subhwnd, 1149, 317); //��1-10
    Sleep(500);
    send_click(subhwnd, 991, 570);//���븱��
    Sleep(4000);
    send_click(subhwnd, 1092, 599);//ս��
    Sleep(1000);
    send_click(subhwnd, 1193, 284);//ѡ��ս
    Sleep(10000);
    //send_click(subhwnd, 1155, 670);
    Sleep(500);
    //send_click(subhwnd, 1155, 670);//����3
    ///Sleep(13000);
    HDC hdc = GetDC(subwinhwnd);
    while (true) {
      COLORREF clr = ::GetPixel(hdc, 1028, 460);

      if ((int)GetRValue(clr) == 245 && (int)GetGValue(clr) == 234 && (int)GetBValue(clr) == 110) {
        break;
      }
      send_click(subhwnd, 945, 667);
      Sleep(500);  //����2
      send_click(subhwnd, 945, 667);
    }   
  } 
  
  while (true) {  //ˢ���ѱ�
    send_click(subhwnd, 1015, 344); //ѡ60���Ѷ�
    Sleep(500);
    send_click(subhwnd, 630, 607);//����ս
    Sleep(4000);
    send_click(subhwnd, 1092, 599);//ս��
    Sleep(1000);
    send_click(subhwnd, 1193, 284);//ѡ��ս
    Sleep(20000);

    HDC hdc = GetDC(subwinhwnd);
    while (true) {
      send_click(subhwnd, 945, 667);
      Sleep(500);
      send_click(subhwnd, 945, 667);//����2
      COLORREF clr = ::GetPixel(hdc, 737, 589);

      if ((int)GetRValue(clr) == 255 && (int)GetGValue(clr) == 234 && (int)GetBValue(clr) == 0) {
        break;
      }

    }   
  } 
    


    
}