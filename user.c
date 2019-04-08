#include "user.h"

int load_file(LOGIN* list[], char* filename){
#ifdef DEBUG
     printf("DEBUG|load_file()\n");
#endif

  int count=0;
  FILE *datafile = fopen(filename, "r");
#ifdef DEBUG
  printf("DEBUG|file open\n");
#endif
  if(datafile == NULL){
    fclose(datafile);
    datafile = fopen(filename, "w+");
  }
  while(!feof(datafile)){
    list[count]=(LOGIN*)malloc(sizeof(LOGIN));
    fscanf(datafile," %s %s\n",list[count]->id,list[count]->password);
    count++;
  }
  printf("%d records read!\n",count);\
  fclose(datafile);
  return count;
}

void join(LOGIN* list[], int count){
#ifdef DEBUG
    printf("DEBUG|join()\n");
#endif
  char id[20], pass[20];
  while(1){
    printf("Enter new user id >> ");
    scanf("%s", id);
    int dup=0;
    for(int i=0;i<count;i++){
      if(strcmp(id, list[i]->id)==0) {
        dup=1; break;
      }
    }
    if(dup==1){
      printf("Already exist!!\n");
    }
    else{
      printf("Enter password >> ");
      scanf("%s", pass);
      list[count] = (LOGIN*)malloc(sizeof(LOGIN));
      strcpy(list[count]->id, id);
      strcpy(list[count]->password, pass);
      printf("New user added!\n");
      break;
    }
  }
}

int login(LOGIN* list[], int count){
#ifdef DEBUG
    printf("DEBUG|login()\n");
#endif
  char id[20], pass[20];
  printf("Enter user id >> ");
  scanf("%s", id);
  getchar();
  int dup=0, found;
  for(int i=0;i<count;i++){
    if(strcmp(id, list[i]->id)==0) {
      dup=1;
      found = i;
      break;
    }
  }
  if(dup!=1){
    printf("No such user!!\n");
    return -1;
  }
  else{
    printf("Enter password >> ");
    scanf("%s", pass);
    getchar();
    if(strcmp(list[found]->password, pass)==0){
      printf("Welcome %s!!\n", id);
      return 1;
    }
    else{
      printf("Password incorrect!!\n");
      return 0;
    }
  }
}

int logout(int is_login){
#ifdef DEBUG
    printf("DEBUG|logout()\n");
#endif
  printf("Logout!!\n");
  return 0;
}

void save_file(LOGIN* list[], int count, char* filename){
#ifdef DEBUG
    printf("DEBUG|save_file()");
#endif
  FILE *datafile = fopen(filename, "w");
  for(int i=0; i<count; i++){
    fprintf(datafile, "%s %s\n", list[i]->id, list[i]->password);
  }
  printf("%s Saved!\n", filename);
  fclose(datafile);
}

void list(LOGIN* list[], int count){
#ifdef DEBUG
    printf("DEBUG|list()\n");
#endif
    printf("\tid\tpwd\n");
    for(int i=0; i<count; i++){
	printf("\t%s\t%s\n", list[i]->id, list[i]->password);
    }
}
