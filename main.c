#include "user.h"
#include "menu.h"

int main(int argc, char* argv[]) {
  LOGIN* userlist[100]; // 사용자목록 포인터 배열 (최대 100)
  int is_login=0; // 로그인 여부 (0 NO, 1 Yes)
  int menu_id;
  char mnf;
  if (argc != 2) {
    printf("Usage : manager <datafile>\nmake new file?(y/n)");
    scanf("%c", &mnf);
    if(mnf == 'y'){
	printf("create new file");
    }
    return 0;
  }
  int count = load_file(userlist, argv[1]);
  while(1){
    if(is_login==0) is_login = login(userlist, count);
    menu_id = ask_menu(is_login); // 현재 로그인 되었는지의 여부를 파라미터로 알려야 한다.
    if(menu_id==1) join(userlist, count);
    else if (menu_id==2) is_login = login(userlist, count);
    else if (menu_id==3) logout(&is_login);
    else break;
  }
  save_file(userlist, count, argv[1]);
  return 0;
}
