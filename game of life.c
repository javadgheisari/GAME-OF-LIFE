#include<stdio.h>
#include<windows.h>
#include<time.h>

const int m=25;
const int n=25;
void change (int arr1[m][n],int arr2[m][n]){
      for ( register int i =0 ;i<m;i++){
      for (register int j =0 ;j<n ;j++){
      arr1[i][j]=arr2[i][j];
      }
      }

}

void SetColor(int ForgC)
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}

void vaziat_func (int arr1[m][n],int arr2[m][n],int vaziat[m][n]){

    for ( register int i =0;i<25;i++){
      for ( register int j=0;j<25;j++)
    {
        int hamsaye=0;
        if(j!=0 && arr1[i][j-1]==1){
        hamsaye++;
        }
        if(j!=0 || i!=0 )
        if( arr1[i-1][j-1]==1){
        hamsaye++;
        }
        if(j!=0 || i!=24)
        if( arr1[i+1][j+1]==1){
        hamsaye++;
        }
        if(j!=24 || i!=0)
        if (arr1[i+1][j-1]==1){
        hamsaye++;
        }
        if(j!=24 || i!=0)
        if( arr1[i-1][j+1]==1){
        hamsaye++;
        }
        if(j!=24 && arr1[i][j+1]==1){
        hamsaye++;
        }
        if(i!=0 && arr1[i-1][j]==1){
        hamsaye++;
        }
        if(i!=24 && arr1[i+1][j]==1){
        hamsaye++;
        }
        vaziat[i][j]=hamsaye;
        for(int x;x<0;x++);
    }
    }

}

 void print_s(int arr2[m][n],int lives,int level){
      for (register int i =0 ; i<25 ;i++){
      for (register int j =0 ; j<25 ;j++){
            if (arr2[i][j]==1){
       char c=248;
        printf ("%c",c);
            }
            if (i==11 && j ==24 ){
                SetColor(14);
                printf("      level=%d",level);}
            if (i==12 && j ==24 ){
                printf("      live cells :) =%d",lives);}
                if (i==13 && j==24){
                int dead=625-lives;
                printf("      dead cells :( = %d",dead);
            }
           if (arr2[i][j]==0)
            printf(" ");

      }
      printf("\n");
      }

}

int  vaziat_arr2(int arr1[m][n],int arr2[m][n],int vaziat[m][n]){
      int lives =0;
     for (register int i=0;i<25;i++){
      for ( register int j =0 ;j<25 ;j++)
    {
      if (arr1[i][j]==0){
        if (vaziat[i][j]==3){
           arr2[i][j]=1;
           lives++;
           continue;
        }
        if(vaziat[i][j]<3 ){
            arr2[i][j]=0;
        }
         if (vaziat[i][j]>3){
            arr2[i][j]=0;
        }
      }
      if (arr1[i][j]==1){
        if (vaziat[i][j]==1){
          arr2[i][j]=0;
          continue;
        }
        if (vaziat[i][j]==0){
          arr2[i][j]=0;
          continue;
        }
          if (vaziat[i][j]>3){
          arr2[i][j]=0;
          continue;
          }
          if (vaziat[i][j]==2){
            arr2[i][j]=1;
            lives++;
            continue;
          }
          if (vaziat[i][j]==3){
            arr2[i][j]=1;
            lives++;
            continue;
          }
          }
    }
    }

return lives;

}
   int menu(){
        int d;
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
        printf("1.random mode");
        printf(" %c\n",186);
        printf("2.manual mode");
        printf(" %c\n",186);
        printf("3.show shapes");
        printf(" %c\n",186);
        printf("4.about game");
        printf("  %c\n",186);
        printf("5.exit");
        printf("        %c\n",186);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
        scanf("%d",&d);

        return d ;

}
void pr_start(){

    int i;
    int j;
int arr[23][32]={1,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,1,1,1,1,0,2,
                 1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,1,1,0,0,0,1,1,0,0,1,0,0,0,0,0,2,
                 1,0,0,1,1,0,0,0,1,1,1,1,1,0,0,0,1,0,1,0,1,0,1,0,0,1,1,1,1,1,0,2,
                 1,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,2,
                 1,1,1,1,1,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,1,1,1,1,1,0,2,
                 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
                 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
                 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
                 0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,2,
                 0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,2,
                 0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,2,
                 0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,2,
                 0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,2,
                 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
                 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
                 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
                 1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,2,
                 1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,2,
                 1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,2,
                 1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,2,
                 1,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,2,
                 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
                 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,
                 };
for(i=0;i<23;i++){
    for(j=0;j<32;j++){
    if(arr[i][j]==2){
     SetColor(4);
    printf("%c",186);
}
if(arr[i][j]==4){
     SetColor(4);
    printf("%c",188);
}
if(arr[i][j]==3){
     SetColor(4);
    printf("%c",205);
}
    if (arr[i][j]==0){
        printf(" ");
    }
if(arr[i][j]==1){
     SetColor(4);
    printf("%c",254);
    Sleep(30);
}
}
printf("\n");
}
}

int main()
{

        pr_start();

        Sleep(500);
        system("cls");
    SetColor(15);
    int arr1[25][25]={};
    int arr2[25][25]={};
    int vaziat[25][25]={};

    int select = menu();
    system("cls");
    switch (select){
     case 1:{
       time_t t =time(NULL);
       srand(t);
       for (int i =0 ; i<25;i++){
       for (int j =0 ;j<25 ;j++){
        arr1[i][j]=(rand()%2);
      }}
        SetColor(14);
         for (int i =0 ; i<25;i++){
      for (int j =0 ;j<25 ;j++){
        if (arr1[i][j]==1)
        printf ("%c",248);
        if(arr1[i][j]==0)
       printf(" ");
      }
      printf("\n");
      }
      Sleep(70);
      system("cls");
      int level=1;
      while (1){
      vaziat_func(arr1,arr2,vaziat);
      int zendeha=vaziat_arr2(arr1,arr2,vaziat);
      print_s(arr2,zendeha,level);
      change(arr1,arr2);
      Sleep(70);
      system("cls");
      level++;

      }
  break ;
  }

  case 2:{
      printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
      printf("1.Enter coordinates");
      printf(" %c\n",186);
      printf("2.Select of screen");
      printf("  %c\n",186);
      printf("                    %c\n",186);
      printf("0.reset game");
      printf("        %c\n",186);
      printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
      int select_mokh;
      scanf("%d",&select_mokh);
      system("cls");
      switch(select_mokh){
        SetColor(15);
        case 1:{
         int num;
         printf("tedad selul haye zende ra vared konid: ");
         scanf("%d",&num);

   for(int c=0;c<num;c++){
   printf("mokhtasat noghte mored nazar ra ba format x,y vared konid:");
   int i,j;
   scanf("%d,%d",&i,&j);
   arr1[i+1][j+1]=1;
   }
     int level=1;
      while (1){
      vaziat_func(arr1,arr2,vaziat);
      int zendeha=vaziat_arr2(arr1,arr2,vaziat);
      print_s(arr2,zendeha,level);
      change(arr1,arr2);
      Sleep(70);
      system("cls");
      level++;
      }
break ;    }


        case 2:{

char arr_select[25][25];
for (int i=0;i<25;i++)
for (int j=0 ;j<25;j++)
    arr_select[i][j]=' ';

    int r=13;
    int c=13;
    arr_select[r][c]='_';
    char key;
    while (key !='k'){
        system("cls");
        for (int i=0;i<25;i++){
for (int j=0 ;j<25;j++){
    printf("%c",arr_select[i][j]);
}
printf("\n");
}
key=getche();
switch(key){

case 'w':
    if(arr_select[r-1][c]!='o')
    arr_select[r-1][c]='_';
    if(arr_select[r][c]=='_')
    arr_select[r][c]=' ';
    r--;
    break;
    case 's':
    if(arr_select[r+1][c]!='o')
    arr_select[r+1][c]='_';
    if(arr_select[r][c]=='_')
    arr_select[r][c]=' ';
    r++;
    break;
 case 'd':
    if(arr_select[r][c+1]!='o')
    arr_select[r][c+1]='_';
    if(arr_select[r][c]=='_')
    arr_select[r][c]=' ';
    c++;
    break;
    case 'a':
    if(arr_select[r][c-1]!='o')
    arr_select[r][c-1]='_';
    if(arr_select[r][c]=='_')
    arr_select[r][c]=' ';
    c--;
    break;

    case 'o':
    arr_select[r][c]='o';
    arr1[r][c]=1;
    break;

    case 'k':

    print_s(arr1,1,8);
      system("cls");
     int level=1;
      while (1){
      vaziat_func(arr1,arr2,vaziat);
      int zendeha=vaziat_arr2(arr1,arr2,vaziat);
      print_s(arr2,zendeha,level);
      change(arr1,arr2);
      Sleep(80);
      system("cls");
      level++;

      }

}
}
        }
      }
      break ;
      }
case 3:{
int select2;
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
printf("choose the option:");
printf("%c\n",186);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,186);
printf("1.glider");
printf("          %c\n",186);
printf("2.blinker");
printf("         %c\n",186);
printf("3.garden of eden");
printf("  %c\n",186);
printf("4.small exploder");
printf("  %c\n",186);
printf("5.exploder");
printf("        %c\n",186);
printf("                  %c\n",186);
printf("0.reset game");
printf("    %c\n",186);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
scanf("%d",&select2);
switch(select2){
    case 0:{
system("cls");
main();
break ;}
case 1:{
arr1[22][9]=arr1[21][10]=arr1[20][8]=arr1[20][9]=arr1[20][10]=1;
      print_s(arr1,1,8);
      system("cls");
     int level=1;
      while (1){
      vaziat_func(arr1,arr2,vaziat);
      int zendeha=vaziat_arr2(arr1,arr2,vaziat);
      print_s(arr2,zendeha,level);
      change(arr1,arr2);
      system("cls");
      level++;
      }
break ;  }

case 2:{
int i;
int j;
int arr1[25][25]={};
arr1[14][13]=arr1[14][14]=arr1[14][15]=arr1[13][14]=arr1[15][14]=1;

      print_s(arr1,1,8);
      Sleep(70);
      system("cls");
      int level=1;
      while (1){
      vaziat_func(arr1,arr2,vaziat);
      int zendeha=vaziat_arr2(arr1,arr2,vaziat);
      print_s(arr2,zendeha,level);
      change(arr1,arr2);
      Sleep(70);
      system("cls");
      level++;
      }
break ;
}

case 3:{
int arr1[25][25]={};
arr1[11][6]=arr1[15][6]=arr1[16][6]=arr1[7][7]=arr1[10][7]=arr1[11][7]=arr1[12][7]=arr1[13][7]=1;
arr1[14][7]=arr1[8][8]=arr1[9][8]=arr1[11][8]=arr1[12][8]=arr1[13][8]=arr1[14][8]=arr1[15][8]=1;
arr1[7][9]=arr1[9][9]=arr1[10][9]=arr1[11][9]=arr1[13][9]=arr1[15][9]=arr1[16][9]=1;
arr1[7][10]=arr1[8][10]=arr1[10][10]=arr1[11][10]=arr1[12][10]=arr1[14][10]=arr1[15][10]=arr1[16][10]=1;
arr1[8][11]=arr1[9][11]=arr1[10][11]=arr1[12][11]=arr1[13][11]=arr1[14][11]=1;
arr1[7][12]=arr1[8][12]=arr1[9][12]=arr1[12][12]=arr1[14][12]=arr1[15][12]=1;
arr1[7][13]=arr1[9][13]=arr1[10][13]=arr1[11][13]=arr1[13][13]=arr1[15][13]=arr1[16][13]=1;
arr1[8][14]=arr1[10][14]=arr1[11][14]=arr1[12][14]=arr1[15][14]=1;
arr1[8][15]=arr1[9][15]=arr1[10][15]=arr1[11][15]=arr1[14][15]=arr1[16][15]=1;
arr1[7][16]=arr1[8][16]=arr1[11][16]=arr1[13][16]=arr1[14][16]=arr1[15][16]=arr1[17][16]=1;
arr1[9][17]=arr1[10][17]=arr1[12][17]=arr1[16][17]=1;
      print_s(arr1,1,8);
      Sleep(70);
      system("cls");
      int level=1;
      while (1){
      vaziat_func(arr1,arr2,vaziat);
      int zendeha=vaziat_arr2(arr1,arr2,vaziat);
      print_s(arr2,zendeha,level);
      change(arr1,arr2);
      Sleep(70);
      system("cls");
      level++;
      }

      break ;
}
case 4:{
int arr1[25][25]={};
arr1[13][13]=arr1[14][12]=arr1[14][14]=arr1[14][13]=arr1[15][12]=arr1[15][14]=arr1[16][13]=1;
      print_s(arr1,1,8);
      Sleep(70);
      system("cls");
      int level=1;
      while (1){
      vaziat_func(arr1,arr2,vaziat);
      int zendeha=vaziat_arr2(arr1,arr2,vaziat);
      print_s(arr2,zendeha,level);
      change(arr1,arr2);
      Sleep(70);
      system("cls");
      level++;

      }

      break ;
}
case 5:{
int arr1[25][25]={};
arr1[11][11]=arr1[12][11]=arr1[13][11]=arr1[14][11]=arr1[15][11]=arr1[11][13]=arr1[15][13]=arr1[11][15]=arr1[12][15]=1;
arr1[13][15]=arr1[14][15]=arr1[15][15]=1;
      print_s(arr1,1,8);
      Sleep(70);
      system("cls");
      int level=1;
      while (1){
      vaziat_func(arr1,arr2,vaziat);
      int zendeha=vaziat_arr2(arr1,arr2,vaziat);
      print_s(arr2,zendeha,level);
      change(arr1,arr2);
      Sleep(70);
      system("cls");
      level++;

      }

      break ;
}
}
 default:{
 system("cls");
 printf("\n\n\n\n\n\n[The number entered is incorrect...!]\n");
 Sleep(800);
 system("cls");
 main();
    break;}
}
case 4:{
printf("Rules:\n");
printf("1.Any live cell with fewer than two live neighbours dies, as if by underpopulation.\n");
printf("2.Any live cell with two or three live neighbours lives on to the next generation.\n");
printf("3.Any live cell with more than three live neighbours dies, as if by overpopulation.\n");
printf("4.Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.\n");
printf("These rules, which compare the behavior of the automaton to real life, can be condensed into the following:\n");
printf("1.Any live cell with two or three neighbors survives.\n");
printf("2.Any dead cell with three live neighbors becomes a live cell.\n");
printf("3.All other live cells die in the next generation. Similarly, all other dead cells stay dead.\n");
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
printf("0.reset game\n");
int reset;
scanf("%d",&reset);
switch(reset){
case 0:{
system("clS");
main();    }
}
break ;
}
case 5:{
printf("[YOU ARE RETURNED...]\n");
break ;}
    }
}
