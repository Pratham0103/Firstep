#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#define ESC 27
#define UP 72
#define DO 80
#define RI 77
#define LE 75
#define EN 13
char matrix[3][3];
class s{char name[80];
	 int score;
	 int life;
	 public:
	  s()
	  {score=0;
	  life=4;}
	 void lif()
	  { life--;}
	 void scor()
	  {score++;}
	 void nam()
	 {gets(name);}
	 void disp();
	 void display()
	 {
	 cout<<name<<" "<<score<<endl;
	 }
	 int rlife()
	 {
	 return life;
	 }
	 int rscore()
	 {
	 return score;
	 }
	}u,uu;
void s::disp()
	{
	  gotoxy(72,1);
	  cout<<"SCORE:"<<score;
	  gotoxy(75,25);
	  for(int j=0;j<life;j++)
	  {cout<<"";}
	 };
int div(int);
int heck(int,int);
int brek(int,int);
void find(int,int);
char check();
int days();
int years(int year);
int months(int month,int year);
void clender();
void value();
void get_player_move();
void get_computer_move();
void disp_matrix();
void shoot();
void calculater();
void Games();
void factors_o();
void sel(int x,int y);
void menu();
void gm_menu();
void gm_opt(int);
void tic_toe();
void main()
{
clrscr();
menu();
int x=0,y=0,xend=0,yend=0,opti=0;;
sel(x,y);
char ch;
while(1)
{
 ch=getch();
 if(ch==RI&&xend<=0)
 {
 clrscr();
 menu();
 opti+=1;
 xend+=1;
 x=x+11;
 sel(x,y);
 }
 else if(ch==ESC)
 break;
 if(ch==LE&&xend==1)
 {
 clrscr();
 menu();
 opti-=1;
 xend-=1;
 x=x-11;
 sel(x,y);
 }
 else if(ch==DO&&yend==0)
 {
 clrscr();
 menu();
 opti+=2;
 yend+=1;
 y=y+5;
 sel(x,y);
 }
 if(ch==UP&&yend==1)
 {
 clrscr();
 menu();
 opti-=2;
 yend-=1;
 y=y-5;
 sel(x,y);
 }
 else if(ch==EN)
 {switch(opti)
  {
  case 0:clender();clrscr();menu();sel(x,y);break;
  case 1:calculater();clrscr();menu();sel(x,y);break;
  case 2:Games();clrscr();menu();sel(x,y);break;
  case 3:factors_o();clrscr();menu();sel(x,y);break;
  }
 }
}
}

void sel(int x,int y)
{
gotoxy(9+x,9+y);
for(int i=0;i<12;i++)
cout<<"-";
gotoxy(9+x,9+y+5);
for(i=0;i<12;i++)
cout<<"-";
for(i=0;i<4;i++)
 {gotoxy(9+x,10+y+i);
 cout<<"|";
 }
for(i=0;i<4;i++)
 {gotoxy(9+x+11,10+y+i);
 cout<<"|";
 }
}
void menu()
{clrscr();
gotoxy(10,10);
cout<<"calender";
gotoxy(21,10);
cout<<"calculater";
gotoxy(10,15);
cout<<"Games";
gotoxy(21,15);
cout<<"Factors";
}
void calculater()
{
clrscr();
char b[30],sp[8];
int c[3],h=0,k=0,d=0,end;
int sum[9]={0};
int x=0,y=0,exi=1;
gotoxy(10,10);
cout<<"->Enter the expression you want to perform ex:3+4=7";
gotoxy(10,11);
cout<<"->press\'=\'to perform calculation";
gotoxy(1,1);
for(int i=0;i<15;i++)
{
b[h]=getch();
if(b[h]=='=')
i=50;
else if(b[h]==ESC)
 {exi=0;
  menu();
  sel(x+11,y);
  break;
 }
 if(b[h]=='+'||b[h]=='-'||b[h]=='*'||b[h]=='/')
  {
  cout<<b[h];
  while(k<h)
   {
   sum[d]=(sum[d]*10)+((int)b[k]-48); //-48 to convert it into number
   k++;
   }
  sp[d]=b[h];;
  k=h+1;
  end=++d;
  }
 else if(b[h]!=ESC)
 cout<<b[h];
 h++;
 }
 if(exi==1)
 {
 while(k<(h-1))
  {
  sum[d]=(sum[d]*10)+((int)b[k]-48); //-48 to convert it into number
  k++;
  }
 end=end+1;
 for(d=0;d<end;d++)
  {
  switch(sp[d])
   {
   case '+':sum[d+1]=sum[d]+sum[d+1];break;
   case '-':sum[d+1]=sum[d]-sum[d+1];break;
   case '*':sum[d+1]=sum[d]*sum[d+1];break;
   case '/':sum[d+1]=sum[d]/sum[d+1];break;
   }
  }
 cout<<sum[d-1];
 gotoxy(10,12);
 cout<<"->\"Press any key\" to Exit";
 getch();
 }
}
void Games()
{
int y=0,opt=0;
gm_menu();
gm_opt(y);
char ch;
 while(1)
 {
 ch=getch();
 if(ch==DO&&opt==0)
  {y=y+2;
   clrscr();
   gm_menu();
   gm_opt(y);
   opt+=1;
  }
  else if(ch==UP&&opt==1)
  {y=y-2;
   clrscr();
   gm_menu();
   gm_opt(y);
   opt-=1;
  }
  if(ch==ESC)
  break;
  else if(ch==EN)
  {
  switch(opt)
   {
   case 0:tic_toe();clrscr();gm_menu();gm_opt(y);break;
   case 1:shoot();clrscr();gm_menu();gm_opt(y);break;
   }
  }
 }
}
void factors_o()
{
 clrscr();
 int b=0;
 int d=0,fl=0;
 cout<<"Enter a number:";
 cin>>b;
 d=div(b);
 if(d!=0)
 {
 fl=heck(b,d);
  if(fl==0)
  {    cout<<b<<"=";
     find(b,d);
  }
  else
  {
  cout<<b<<"="<<d<<"*";
  }
 }
 else
 {
 cout<<b<<"="<<b;
 }
getch();
}
void gm_menu()
{
 clrscr();
 gotoxy(25,10);
 cout<<"Games";
 gotoxy(22,12);
 cout<<"1.";
 gotoxy(22,14);
 cout<<"2.";
 gotoxy(25,12);
 cout<<"Tic-Tac-Toe";
 gotoxy(25,14);
 cout<<"Shooting";
}
void gm_opt(int y)
{
int i;
gotoxy(24,12+y);
cout<<"|";
gotoxy(36,12+y);
cout<<"|";
gotoxy(24,11+y);
for(i=0;i<13;i++)
cout<<"-";
gotoxy(24,13+y);
for(i=0;i<13;i++)
cout<<"-";
}
void tic_toe()
{
clrscr();
char done;
cout<<"this is the game of tic tac toe.\n";
cout<<"you will play against computer.\n";
done=' ';
value();
do{
cout<<"\t\t\ttic-tac-toe\n";
disp_matrix();
get_player_move();
clrscr();
done=check();
if(done!=' ')
break;
get_computer_move();
done=check();
}
while(done==' ');
if(done=='x')
cout<<"you won!\n";
else
cout<<"i won!!!\n";
disp_matrix();
delay(1000);
}
void value()
{
int i,j;
for(i=0;i<3;i++)
for(j=0;j<3;j++)matrix[i][j]=' ';
}
void get_player_move()
{
int x,y;
cout<<"enter x,y cordinates for your move:";
cin>>x>>y;
x--;
y--;
if(matrix[x][y]!=' ')
{
cout<<"invalid move,try again.\n";
get_player_move();
}
else matrix[x][y]='x';
}
void get_computer_move()
{
int i,j;
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
if(matrix[i][j]==' ')break;
if(matrix[i][j]==' ')break;
}
if(i*j==4)
{
cout<<"draw\n";
exit(0);
}
else
matrix[i][j]='0';
}
void disp_matrix(void)
{
int t;
 for(t=0;t<3;t++)
 {
 cout<<matrix[t][0]<<"|"<<matrix[t][1]<<"|"<<matrix[t][2];
 if(t!=2)
 cout<<"\n-|-|-\n";
 }
cout<<"\n";
}
char check()
{
int i;
for(i=0;i<3;i++)
if(matrix[i][0]==matrix[i][1]&&matrix[i][0]==matrix[i][2])
return matrix[i][0];
for(i=0;i<3;i++)
if(matrix[0][i]==matrix[1][i]&&matrix [0][i]==matrix[2][i])
return matrix[0][i];
if(matrix[0][0]==matrix[1][1]&&matrix[1][1]==matrix[2][2])
return matrix[0][0];
if(matrix[0][2]==matrix[1][1]&&matrix[1][1] ==matrix[2][0])
return matrix[0][2];
return' ';
}
void shoot()
{
clrscr();
randomize();
fstream f;
int v=0,l=10;
if(!f)
{
f.open("shoot.dat",ios::out);
v=1;
}
else
f.open("shoot.dat",ios::in);
char x;
int y,RND;
gotoxy(25,12);
cout<<"WELCOME to the world of SHOOTING";
gotoxy(25,14);
cout<<"press \'->\' to shoot";
delay(2000);
clrscr();
while(1)
{
u.disp();
gotoxy(1,l);
cout<<"====\n\b||";
RND=(rand()%21)+2;
gotoxy(80,RND);
cout<<"*";
 while(1)
 {
 x=getch();
  if(x==UP&&l>2)
  {
  clrscr();
  l=l-1;
  u.disp();
  gotoxy(80,RND);
  cout<<"*";
  gotoxy(1,l);
  cout<<"====\n\b||";
  }
  else if(x==DO&&l<22)
  {
  clrscr();
  u.disp();
  gotoxy(80,RND);
  cout<<"*";
  l=l+1;
  gotoxy(1,l);
  cout<<"====\n\b||";
  }
  if(x==RI&&l<23&&l>1)
  {
   for(int i=0;i<75;i++)
   {
    clrscr();
    gotoxy(75,25);
    u.disp();
    gotoxy(80,RND);
    cout<<"*";
    gotoxy(1,l);
    cout<<"====\n\b||";
    gotoxy(5+i,l);
    cout<<"->";
    delay(10);
   }
   delay(555);
   break;
  }
 if(x==ESC)
 break;
 }
clrscr();
if(l==RND)
u.scor();
else
u.lif();
if(u.rlife()==0)
break;
if(x==ESC)
break;
}
cout<<"enter your name:";
u.nam();
gotoxy(35,10);
cout<<"Score Bord\n";
if(v==1)
{
f.write((char*)&u,sizeof(u));
}
else
 {
  int flag=0;
  ofstream f1("temp.dat");
  while(f.read((char*)&uu,sizeof(uu)))
  {
  if(u.rscore()>uu.rscore())
   {
   flag=1;
   f1.write((char*)&u,sizeof(u));
   f1.write((char*)&uu,sizeof(uu));
   break;
   }
   else
   f1.write((char*)&uu,sizeof(uu));
  }
  if(flag==0)
  f1.write((char*)&u,sizeof(u));
   if(!f.eof())
  {
   while(f.read((char*)&uu,sizeof(uu)))
   f1.write((char*)&uu,sizeof(uu));
  }
 f1.close();
 f.close();
 remove("shoot.dat");
 rename("temp.dat","shoot.dat");
 }
 f.open("shoot.dat",ios::in);
while(f.read((char*)&uu,sizeof(uu)))
uu.display();
delay(1000);
clrscr();
gotoxy(27,12);
cout<<"Thanks for Playing";
f.close();
delay(1500);
}
void clender()
{
clrscr();
int  month,year,result,yea,mon,day,j=1;
char ch;
cout<<"which month year calender do you want to see\n";
cout<<"enter month (eg:march=3):";
cin>>j;
cout<<"enter year (eg:=2014):";
cin>>year;
do{
if(j>12)
 {j=1;
  year=year+1;
 }
 yea=years(year);
 month=j;
 mon=months(month,year);
 day=days();
 clrscr();
result=(yea+mon+day)%7;
int s;
switch(month)
{
case 1:s=31;break;
case 2:s=28;break;
case 3:s=31;break;
case 4:s=30;break;
case 5:s=31;break;
case 6:s=30;break;
case 7:s=31;break;
case 8:s=31;break;
case 9:s=30;break;
case 10:s=31;break;
case 11:s=30;break;
case 12:s=31;break;
}
if(year%100==0)
{
 if(year%400==0)
 {
  if(month==2)
  s=29;
 }
 else if(s==2)
 {
  s=28;
 }
}
else if(year%4!=0)
{if(month==2)
 s=28;
}
else
{if(month==2)
s=29;
}
int a,i;
a=result;
if(a==0)
{
a=7;
}
switch(month)
{
case 1:cout<<"\t\t\tJanuary|"<<year;break;
case 2:cout<<"\t\t\tFebruary|"<<year;break;
case 3:cout<<"\t\t\tMarch|"<<year;break;
case 4:cout<<"\t\t\tApril|"<<year;break;
case 5:cout<<"\t\t\tMay|"<<year;break;
case 6:cout<<"\t\t\tJune|"<<year;break;
case 7:cout<<"\t\t\tJuly|"<<year;break;
case 8:cout<<"\t\t\tAugust|"<<year;break;
case 9:cout<<"\t\t\tSeptember|"<<year;break;
case 10:cout<<"\t\t\tOctober|"<<year;break;
case 11:cout<<"\t\t\tNovember|"<<year;break;
case 12:cout<<"\t\t\tDecember|"<<year;break;
}
cout<<"\n \tmon\ttue\twed\tthu\tfri\tsat\tsun\n";
for(i=0;i<a;i++)
{
cout<<"\t";
}
for( i=1;i<=s;i++)
{
cout<<i<<"\t";
if(a==1)
 {
if(i%7==0)
  {
cout<<"\n\t";
  }
 }
else if(a==2)
 {
 if(i==6||i==13||i==20||i==27)
  {
  cout<<endl<<"\t";
  }
 }
if(a==3)
 {
 if(i==5||i==12||i==26||i==19)
  {cout<<endl<<"\t";}
 }
else if(a==4)
 {
 if(i==4||i==11||i==25||i==18)
 cout<<"\n\t";
 }
 if(a==5)
 {
 if(i==3||i==10||i==17||i==24)
 cout<<"\n\t";
 }
else if(a==6)
{
if(i==2||i==9||i==16||i==23||i==30)
cout<<"\n\t";
}
if(a==7)
{
if(i==1||i==8||i==15||i==22||i==29)
cout<<"\n\t";
}
}
cout<<"\n\n\twant to switch to next month(y/n)?";
cin>>ch;
j++;
}while(ch=='y'||ch=='Y');
cout<<"\n\t!!!!!!!!!!thanks!for using!!!!!!!!!!!";
getch();
}
int years(int year)
{ int f,n,c,d;
f=year-1;
  for(int i=0;i<10;i++)
  { if(f%400==0)
       {
       n=0;

       }
   else
   {
       if((400*i)>f)
	{
	c=f-400*(i-1);

	 break;
	}
   }
  }

    if(100<c)
     {
     d=c-100;
     n=5;
     }
 else if(200<c)
      {d=c-200;
      n=3;
      }
 if(300<c)
 {d=c-300;
  n=1;
  }
 else if(0<c<100)
  { d=c-0;
    n=0;
  }
int leap,odd,nor,odd_day;
 leap=d/4;
 odd=(leap*2)%7;
 nor=(d-leap)%7;
 odd_day=(n+odd+nor);
 return odd_day;
}
int months(int month,int year)
{
int a,b,x;
a=year;
b=month;

if(a%100==0)
{
if(a%400==0)
  {
switch(b-1)
     { case 0:x=0;break;
       case 1: x=3;break;
       case 2: x=4;break;
       case 3: x=4+3;break;
       case 4: x=7+2;break;
       case 5: x=12;break;
       case 6: x=14;break;
       case 7: x=17;break;
       case 8: x=20;break;
       case 9: x=22;break;
       case 10: x=25;break;
       case 11: x=27;break;
       default:cout<<"wrong month enterd";
      }
   }
   else

  { switch(b-1)
   { case 0:x=0;break;
     case 1:x=3;break;
     case 2:x=3;break;
     case 3:x=6;break;
     case 4:x=8;break;
     case 5:x=11;break;
     case 6:x=13;break;
     case 7:x=16;break;
     case 8:x=19;break;
     case 9:x=21;break;
     case 10:x=24;break;
     case 11:x=26;break;
     default:cout<<"wrong month entered";
   }

  }
}
else if(a%4==0)
   { switch(b-1)
     { case 0:x=0;break;
       case 1: x=3;break;
       case 2: x=4;break;
       case 3: x=4+3;break;
       case 4: x=7+2;break;
       case 5: x=12;break;
       case 6: x=14;break;
       case 7: x=17;break;
       case 8: x=20;break;
       case 9: x=22;break;
       case 10: x=25;break;
       case 11: x=27;break;
       default:cout<<"wrong month enterd";
      }
   }
  else
  { switch(b-1)
   { case 0:x=0;break;
     case 1:x=3;break;
     case 2:x=3;break;
     case 3:x=6;break;
     case 4:x=8;break;
     case 5:x=11;break;
     case 6:x=13;break;
     case 7:x=16;break;
     case 8:x=19;break;
     case 9:x=21;break;
     case 10:x=24;break;
     case 11:x=26;break;
     default:cout<<"wrong month entered";
   }
  }
return x;
}
int days()
{
 int res,day;
 day=1;
 res=day%7;
 return res;
}
int div(int b)
{ int d=0;
 for(int j=2;j<(b/2)+1;j++)
 {
  if(b%j==0)
   {d=1;
   return j;
   }
 }
 if(d!=1)
 return 0;
 return 0;
}
int heck(int b,int d)
{ int c=1,fl=0;
for(int i=1;i<=b;i++)
  {
  c=c*d;
   if(b==c)
   {
   fl=1;
   cout<<b<<"="<<d<<"^"<<i;
   return fl;
   }
   else
   {
   return div(d);
   }
  }
 return 0;
}
void find(int b,int d)
{int me=1,rem,e=0,m=0;
 while(m==0)
  {
  m=b%d;
  b=b/d;
  e=e+1;
  }
  e=e-1;
  rem=(b*d)+m;
  me=div(rem);
  if(e>1)
  {cout<<d<<"^"<<e<<"*";}
  else
  cout<<d<<"*";
  if(me!=0)
 {
  find(rem,me);
 }
 else
 cout<<rem;
}