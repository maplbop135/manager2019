#include "menu.h"
#include <string.h>

int ask_menu(int is_login, char *menu){
#ifdef DEBUG
    printf("DEBUG|ask_menu()\n");
#endif
// 파라미터 : 로그인여부 (0 No, 1Yes)
// 리턴값 : 선택한 메뉴번호
// 메뉴번호 : 1. Sign up 2. Log in 3. Log out 0. Exit
  int menu2;
  if(is_login==0){
    if(!strcmp(menu, "login")) menu2=1;
    else if(!strcmp(menu, "join")) menu2=2;
    else if(!strcmp(menu, "list")) menu2=3;
    else if(!strcmp(menu, "exit")) menu2=4;
    else menu2=5;
  }
  else{
    if(!strcmp(menu, "logout")) menu2=6;
    else menu2=7;
  }
  return menu2;
}
