#include "user.h"
#include "menu.h"
#include <unistd.h>

int main(int argc, char* argv[]) {
  LOGIN* userlist[100]; // 사용자목록 포인터 배열 (최대 100)
  int is_login=0; // 로그인 여부 (0 NO, 1 Yes)
  int menu_id;
  char menu[20];
  int mf;
  if (argc != 2) {
    printf("Usage : manager <datafile>\n");
    return 0;
  }
  if(access(argv[1], F_OK) != 0){
    printf("No file: %s. Make file('1' for yes, '2' for no)?", argv[1]);
    scanf("%d", &mf);
    getchar();
    if(mf==1){
	printf("make new file!\n");
	return 0;
    } else { return -1; }
  }
  int count = load_file(userlist, argv[1]);
  while(1){
    if(is_login==0){
      printf(">");
      gets(menu);
    } else{
      printf("#");
      gets(menu);
    }
    menu_id = ask_menu(is_login, menu);
    switch(menu_id){
	case 1: is_login = login(userlist, count); break;
	case 2: join(userlist, count); count++; break;
	case 3: list(userlist, count); break;
	case 4: save_file(userlist, count, argv[1]); return 0;
	case 5: printf("wrong input!\n"); break;
	case 6: is_login = logout(is_login); break;
	case 7: printf("%s\n", menu); break;
	default: printf("no menu input!\n"); break;
    }
  }
  return 0;
}
