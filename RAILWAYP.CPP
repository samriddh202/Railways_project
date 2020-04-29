	    #include<iostream.h>
	    #include<conio.h>
	    #include<ctype.h>
	    #include<fstream.h>
    #include<dos.h>
#include<string.h>
#include<iomanip.h>
#include<stdio.h>




class Date
{
 public:
 int dday,dmonth,dyear,day,month,year;
 void NDate(int,int,int);
 void current_Date();
};
void Date::NDate(int d,int m1, int y)
{
 dday=d;
 dmonth=m1;
 dyear=y;
 static int m[]={31,29,31,30,31,30,31,31,30,31,30,31};
 if((dday>m[dmonth-1])||(dyear%4==0&& dmonth==2&& dday>28))
 {
  dday=1;
  dmonth++;
 }
  if(dmonth>12)
 {
  dmonth=1;
  dyear++;
 }
 day=dday;
 month=dmonth;
 year=dyear;
}
void Date::current_Date()
{
 struct date d;
 getdate(&d);
 day=d.da_day;
 month=d.da_mon;
 year=d.da_year;
}


class train
{
 public:
 char train_no[5],train_name[20];
 void add_train(char [],char []);
 void train_list();
 void addition();
 int found_train(char []);
 void cancellation();
};

void train::add_train(char tno[5],char tname[20])
{
 fstream file;
 file.open("train.dat",ios::app);
 strcpy(train_no,tno);
 strcpy(train_name,tname);
 file.write((char*)this,sizeof(train));
 file.close();
}
void train::addition()
{
 fstream file;
 file.open("train.dat",ios::out);
 if (!file.fail())
 return;
 add_train("2021","RAJDHANI EXPRESS");
 add_train("2022","SHATABDI EXPRESS");
 add_train("2023","TAJ EXPRESS");
 add_train("2024","TAMIL NADU EXPRESS");
 add_train("2025","BHOBAL EXPRESS");
 add_train("2026","G.T EXPRESS");
 add_train("2027","KANPUR EXPRESS");
 add_train("2028","BOMBAY EXPRESS");
 file.close();
}

void train::train_list()
{
 clrscr();
 for(int z=1;z<=23;z++)
 {
  gotoxy(1,z);
  cout<<"||"<<endl;
 }
 for(int z1; z1<=23 ; z1++)
 {
  gotoxy(77,z1);
  cout<<"||"<<endl;
 }
 fstream file;
 file.open("train.dat",ios::in);
 gotoxy(30,1);
 cout<<"\n LIST OF TRAINS"<<endl;
 gotoxy(20,4);
 cout<<"TRAIN NO.       TRAIN NAME"<<endl;
 int row=7;
 while(file.read((char*)this,sizeof(train)))
 {
  gotoxy(23,row);
  cout<<train_no;
  gotoxy(39,row);
  cout<<train_name;
  row++;
 }
 file.close();
}


int train:: found_train(char tno[5])
{
 fstream file;
 file.open("train.dat",ios::in);
 int found=0;
 while(file.read((char*)this, sizeof(train)))
 {
  if(!strcmp(tno,train_no))
  {
   found=1;
   break;
  }
 }
 file.close();
 return found;
}


class ticket
{
 int pnr_no,kms,fare,age,dd,mm,yy;
 char name[30],sex,tr_no[5],from[30],to[30];
 public:
 void pass_info();
 void reservation();
 void cancellation();
 void waiting_list();
}t;

void ticket:: pass_info()
{
 clrscr();
 char tno[5];
 train tt;
 tt.train_list();
 gotoxy(20,18);
 cout<<"\n enter the train number"<<endl;
 cin>>tno;
 if(!tt.found_train(tno))
 {
  gotoxy(20,22);
  cout<<"\n train no is invalid"<<endl;
  getch();
  return;
 }
 clrscr();
 int d1,d2,d3,d4,m1,m2,m3,m4,y1,y2,y3,y4;
 int d,m,y;
 Date dt;
 dt.current_Date();
 d1=dt.day;
 m1=dt.month;
 y1=dt.year;
 cout<<"1:"<<d1<<"/"<<m1<<"/"<<y1 ;
 dt.NDate(d1,m1,y1);
 d2=dt.day;
 m2=dt.month;
 y2=dt.year;
 cout<<"\t2:"<<d2<<"/"<<m2<<"/"<<y2 ;
 dt.NDate(d2,m2,y2);
 d3=dt.day;
 m3=dt.month;
 y3=dt.year;
 cout<<"\t3:"<<d3<<"/"<<m3<<"/"<<y3 ;
 dt.NDate(d3,m3,y3);
 d4=dt.day;
 m4=dt.month;
 y4=dt.year;
 cout<<"\t4:"<<d4<<"/"<<m4<<"/"<<y4 ;
 int sno=0;
 cout<<"\n enter sno. of the Date for passenger information-";
 cin>>sno;
 if(sno<1||sno>4)
 {
  cout<<"\n INVALID DATA"<<endl;
  getch();
  return;
 }
 switch(sno)
 {
  case 1:
  d=d1;
  m=m1;
  y=y1;
  break;
  case 2:
  d=d2;
  m=m2;
  y=y2;
  break;
  case 3:
  d=d3;
  m=m3;
  y=y3;
  break;
  case 4:
  d=d4;
  m=m4;
  y=y4;
  break;
  default:
  break;
 }
 int pnr=0,found=0;
 cout<<"\n enter PNR NUMBER of the ticket:";
 cin>>pnr;
 fstream file("ticket.dat",ios::in);
 while(file.read((char*)this,sizeof(ticket)))
 {
  if((dd==d&&mm==m&&yy==y)&&!strcmp(tr_no,tno)&&pnr==pnr_no)
  {
   found=1;
   clrscr();
   gotoxy(32,7);
   cout<<"NORTHERN RAILWAYS";
   gotoxy(10,9);
   cout<<"PNR NUMBER"<<pnr_no<<"\t\t\t\tDate:"<<dd<<"/"<<mm<<"/"<<yy;
   gotoxy(10,10);
   cout<<"train number:"<<tr_no;
   gotoxy(35,12);
   cout<<"FROM"<<from<<"\t TO :"<<to;
   gotoxy(35,13);
   cout<<"KILOMETRES"<<kms;
   gotoxy(10,15);
   cout<<"passenger name :"<<name;
   gotoxy(10,16);
   cout<<"passenger age:"<<age<<"\t\tsex"<<sex;
   gotoxy(10,18);
   cout<<"total fare: "<<fare;
   gotoxy(1,25);
   cout<<"press any key to continue.....";
   getch();
   break;
  }
 }
 file.close();
 if(!found)
 {
  cout<<"\n TICKET NOT FOUND";
  getch();
 }
}
void ticket::reservation()
{
 clrscr();
 char tno[5];
 train tt;
 tt.train_list();
 gotoxy(20,18);
 cout<<"\n enter the train number"<<endl;
 cin>>tno;
 if(!tt.found_train(tno))
 {
  gotoxy(20,22);
  cout<<"\n train no is invalid"<<endl;
  getch();
  return;
 }
 clrscr();
 int d1,d2,d3,d4,m1,m2,m3,m4,y1,y2,y3,y4;
 int d,m,y;
 Date dt;
 dt.current_Date();
 d1=dt.day;
 m1=dt.month;
 y1=dt.year;
 cout<<"1:"<<d1<<"/"<<m1<<"/"<<y1 ;
 dt.NDate(d1,m1,y1);
 d2=dt.day;
 m2=dt.month;
 y2=dt.year;
 cout<<"\t2:"<<d2<<"/"<<m2<<"/"<<y2 ;
 dt.NDate(d2,m2,y2);
 d3=dt.day;
 m3=dt.month;
 y3=dt.year;
 cout<<"\t3:"<<d3<<"/"<<m3<<"/"<<y3 ;
 dt.NDate(d3,m3,y3);
 d4=dt.day;
 m4=dt.month;
 y4=dt.year;
 cout<<"\t4:"<<d4<<"/"<<m4<<"/"<<y4 ;
 int sno=0;
 cout<<"\n enter sno. of the Date for passenger information-";
 cin>>sno;
 if(sno<1||sno>4)
 {
  cout<<"\n INVALID DATA"<<endl;
  getch();
  return;
 }
 switch(sno)
 {
  case 1:
  d=d1;
  m=m1;
  y=y1;
  break;
  case 2:
  d=d2;
  m=m2;
  y=y2;
  break;
  case 3:
  d=d3;
  m=m3;
  y=y3;
  break;
  case 4:
  d=d4;
  m=m4;
  y=y4;
  break;
  default:
  break;
 }
 int pnr=0;
 fstream file;
 file.open("ticket.dat",ios::in);
 while(file.read((char*)this,sizeof(ticket)))
 {
  if((dd==d&&mm==m&&yy==y)&&!strcmp(tr_no,tno))
  {
   pnr=pnr_no;
  }
 file.close();
 pnr++;
 char pname[30],psex,pfrom[15],pto[15],ch;
 int pkms,pfare,page;
 clrscr();             //to check name
 do
 {
  cout<<"\n enter the name of passenger: ";
  gets(pname);
 }while(!(toupper(pname[0])>=65&&toupper(pname[0])<=90));
 char cq;
 int flag=0;
 do
 {
  if(flag==1)
  {
   cout<<"\n NO TICKRET IS REQUIRE FOR AGE 5"<<endl;
   delay(700);
   cin.get(cq);
   return ;
  }
  cout<<"\n Enter the age:";
  cin>>page;
  flag=1;
 }while(page<=5);

 do
 {
  cout<<"\n Enter Sex:(M/F)"<<endl;
  cin>>psex;
 }while(toupper(psex)!='M'&& toupper(psex) !='F');

 do
 {
  cout<<"\n TRAVELLING FORM"<<endl;
  cin>>pfrom;
 }while(!toupper(pfrom[0])>65&& toupper(pfrom[0])<=90);

 do
 {
  cout<<"\n TO"<<endl;
  cin>>pto;
 }while(!toupper(pto[0])>65&& toupper(pto[0])<=90);

 cout<<"\n enter kilometre :";
 cin>>pkms;
 pfare=pkms*0.75;
 clrscr();
 gotoxy(32,7);
 cout<<"\n NORTHERN RAILWAYS";
 gotoxy(10,9);
 cout<<"PNR NUMBER "<<pnr<<"\t\t Date : "<<d<<"/"<<m<<"/"<<y;
 gotoxy(10,10);
 cout<<"train number: "<<tno;
 gotoxy(35,12);
 cout<<" FROM :"<<pfrom<<"\t TO:"<<pto;
 gotoxy(35,13);
 cout<<"KILOMETRES"<<pkms;
 gotoxy(10,15);
 cout<<"passenger NAME:"<<pname;
 gotoxy(10,16);
 cout<<"PASSENGER AGE: "<<page<<"\tsex :" <<psex;
 gotoxy(10,18);
 cout<<"TOTAL FARE : "<<pfare;
 cout<<"\n\n\n";
 do
 {
  cout<<"Do you want to save the ticket(y/n)";
  cin>>ch;
 }while(toupper(ch)!='Y'&&toupper(ch)!='N');
 if(toupper(ch)=='N')
 {
  return;
 }
 ticket t;
 file.open("ticket.dat",ios::app);
 t.pnr_no=pnr;
 t.kms=pkms;
 strcmp(t.name,pname);
 strcmp(t.tr_no,tno);
 strcmp(t.from,pfrom);
 strcmp(t.to,pto);
 t.sex=psex;
 t.age=age;
 t.fare=pfare;
 t.dd=d;
 t.mm=m;
 t.yy=y;
 file.write((char*)&t,sizeof(ticket));
 file.close();
}

void train::cancellation()
{
 clrscr();
 char tno[5];
 train tt;
 tt.train_list();
 gotoxy(20,18);
 cout<<"\n enter the train number"<<endl;
 cin>>tno;
 if(!tt.found_train(tno))
 {
  goto(20,22);
  cout<<"\n train no is invalid"<<endl;
  getch();
  return;
 }
 clrscr();
 int d1,d2,d3,d4,m1,m2,m3,m4,y1,y2,y3,y4;
 int d,m,y;
 Date dt;
 dt.current_Date();
 d1=dt.day;
 m1=dt.month;
 y1=dt.year;
 cout<<"1:"<<d1<<"/"<<m1<<"/"<<y1 ;
 dt.Date(d1,m1,y1);
 d2=dt.day;
 m2=dt.month;
 y2=dt.year;
 cout<<"\t2:"<<d2<<"/"<<m2<<"/"<<y2 ;
 dt.Date(d2,m2,y2);
 d3=dt.day;
 m3=dt.month;
 y3=dt.year;
 cout<<"\t3:"<<d3<<"/"<<m3<<"/"<<y3 ;
 dt.Date(d3,m3,y3);
 d4=dt.day;
 m4=dt.month;
 y4=dt.year;
 cout<<"\t4:"<<d4<<"/"<<m4<<"/"<<y4 ;
 int sno=0;
 cout<<"\n enter sno. of the Date for passenger information-"
 cin>>sno;
 if(sno<1||sno>4)
 {
  cout<<"\n INVALID DATA"<<endl;
  getch();
  return;
 }
 switch(sno)
 {
  case 1:
  d=d1;
  m=m1;
  y=y1;
  break;
  case 2:
  d=d2;
  m=m2;
  y=y2;
  break;
  case 3:
  d=d3;
  m=m3;
  y=y3;
  break;
  case 4:
  d=d4;
  m=m4;
  y=y4;
  break;
  default:
  break;
 }
 int pnr=0,found=0;
 char ch;
 cout<<"\n enter the PNR NUMBER of the ticket to be cancelled: ";
 cin>>pnr;
 fstream file,temp;
 file.open("ticket.dat",ios::in);
 temp.opem("temp.dat",ios::out);
 while(file.read((char *) this , size of (ticket)))
 {
  if((dd=d&&mm=m&&yy=y)&&!strcmp(tr_no,tno)&&pnr==pnr_no)
  {
   found=1;
   clrscr();
   gotoxy(32,7);
   cout<<"NORTHERN RAILWAYS"<<endl;
   gotoxy(10,9);
   cout<<"PNR NUMBER "<<pnr_no<<"\t\tDate :"<<dd<<"/"<<mm<<"/"<<yy;
   gotoxy(10,10);
   cout<<"TRAIN NUMBER : "<<tr_no;
   gotoxy(35,12);
   cout<<" FROM :"<<from<<"\t TO":<<to;
   gotoxy(35,13);
   cout<<"KILOMETRES"<<kms;
   gotoxy(10,15);
   cout<<"passenger NMAE:"<<name;
   gotoxy(10,16);
   cout<<"PASSENGER AGE: "<<page<<"\tsex :" <<psex;
   gotoxy(10,18);
   cout<<"TOTAL FARE : "<<pfare;
   do
   {
    gotoxy(1,25);
    clrreol();
    cout<<"\n Do you want to cancel ticket(y/n)";
    cin>>ch;
    }while(toupper(ch) !='Y'&& toupper(ch) !='N');
   }
   else
   {
    temp.write((char *)this,sizeof(ticket));
   }
  }
  file.close();
  temp.close();
  if(!found)
  {
   cout<<"\n\n TICKET NOT FOUND"<<endl;
   getch();
   return;
  if(toupper(ch)=='N')
  {
   return;
  }
  file.open("ticket.dat",ios::out);
  temp.open("temp.dat",ios::in);
  while(temp.read((char*)this,sizeof(ticket)))
  {
   file.write((char*)this,sizeof(ticket));
  }
  file.close();
  temp.close();
 }
}

void ticket:: waiting_list()
{
 clrscr();
 char tno[5];
 train tt;
 tt.train_list();
 gotoxy(20,18);
 cout<<"\n enter the train number"<<endl;
 cin>>tno;
 if(!tt.found_train(tno))
 {
  goto(20,22);
  cout<<"\n train no is invalid"<<endl;
  getch();
  return;
 }
 clrscr();
 int d1,d2,d3,d4,m1,m2,m3,m4,y1,y2,y3,y4;
 int d,m,y;
 Date dt;
 dt.current_Date();
 d1=dt.day;
 m1=dt.month;
 y1=dt.year;
 cout<<"1:"<<d1<<"/"<<m1<<"/"<<y1 ;
 dt.Date(d1,m1,y1);
 d2=dt.day;
 m2=dt.month;
 y2=dt.year;
 cout<<"\t2:"<<d2<<"/"<<m2<<"/"<<y2 ;
 dt.Date(d2,m2,y2);
 d3=dt.day;
 m3=dt.month;
 y3=dt.year;
 cout<<"\t3:"<<d3<<"/"<<m3<<"/"<<y3 ;
 dt.Date(d3,m3,y3);
 d4=dt.day;
 m4=dt.month;
 y4=dt.year;
 cout<<"\t4:"<<d4<<"/"<<m4<<"/"<<y4 ;
 int sno=0;
 cout<<"\n enter sno. of the Date for passenger information-"
 cin>>sno;
 if(sno<1||sno>4)
 {
  cout<<"\n INVALID DATA"<<endl;
  getch();
  return;
 }
 switch(sno)
 {
  case 1:
  d=d1;
  m=m1;
  y=y1;
  break;
  case 2:
  d=d2;
  m=m2;
  y=y2;
  break;
  case 3:
  d=d3;
  m=m3;
  y=y3;
  break;
  case 4:
  d=d4;
   m=m4;
   y=y4;
   break;
   default:
   break;
  }
  clrscr();
  fstream file;
  file.open("ticket.dat",ios::in);
  gotoxy(25,1);
  cout<<"LIST OF THE PASSENGERS"<<endl;
  cout<<"\n TRAIN NUMBER :"<<tno<<"\t\t\Date :"<<d<<"/"<<m<<"/"<<y;
  gotoxy(2,5);
  cout<<"PNR NUMBER     PASSENGER NAME     FROM      TO ";
  int row=8,found=0;
  while(file.read((char*)this,sizeof(ticket)))
  {
   if((dd=d&&mm=m&&yy=y)&&!strcmp(tr_no,tno))
   {
    found=1;
    gotoxy(4,row);
    cout<<pnr_no;
    gotoxy(14,row);
    cout<<name;
    gotoxy(41,row);
    cout<<from;
    gotoxy(63,row);
    cout<<to;
    row++;
    if(row==25)
    {
     getch();
     for(int i=8;i<=24;i++)
     {
      gotoxy(1,i);
      clreol();
     }
     row=8;
    }
   }
  }
  file.close();
  if(!found)
  {
   cout<<"\n\n\n\n NO RESERVATION"<<endl;
   getch();
   return;
  }
  cout<<"\n\n Press any key to continue......"<<endl;
  getch();
}



void main
{
 clrscr();
 ticket tc;
 train tt;
 tt.addition();
 char ch,a=15,a1=16;
 while(1)
 {
  clrscr();
  cout<<endl;
  for(int i=1,i<=15;i++)
  {
   if(i%2)
   {
    cout<<"  "<<a;
   }
   else
   {
    cout<<"  "<<a1;
   }
  }
  }
  char w;
  cout<<"WELCOME TO RAILWAY RESERVATION"<<endl;
  cout<<"\n 1) TRAIN LIST"<<endl;
  cout<<"\n 2) RESERVATION"<<endl;
  cout<<"\n 3) CANCELLATION"<<endl;
  cout<<"\n 4) WAITING LIST"<<endl;
  cout<<"\n 5) PASSENGER INFORMATION"<<endl;
  cout<<"\n 6) QUIT"<<endl;
  cout<<"\n Enter your choice(1-6)"<<endl;
  switch(w)
  {
   case 1:
   tt.train_list();
   gotoxy(1,25);
   cout<<"\n PRESS ANY KEY TO CONTINUE....."<<endl;
   getch();
   break;

   case 2:
   tc.reservation();
   break;

   case 3:
   tc.cancellation();
   break;

   case 4:
   tc.waiting_list();
   break;

   case 5:
   tc.pass_info();
   break;

   case 6:
   cout<<"please come soon......"<<endl;
   break;

   default:
   cout<<"INVALID ENTRY"<<endl;
   break;
  }
 }
 getch();
}
