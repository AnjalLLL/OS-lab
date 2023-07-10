#include <stdio.h>
typedef struct
{
int ;
char name[25],address[25];
int roll[25],class[25];
}STD;
STD s;
void display(FILE *);
int search(FILE *,int);
void main()
{
int i,n,roll_key,opn;
FILE *fp;
printf(" How many Records ? \n");
scanf("%d",&n);
fp=fopen("stud.dat","w");
for(i=0;i<n;i++)
{
printf("Read the Info for Student: %d (Roll No,Name,Class,Address) \n",i+1);
scanf("%d%s%d%s",&s.roll,&s.name,&s.class,&s.address);
fwrite(&s,sizeof(s),1,fp);
}
fclose(fp);
fp=fopen("stud.dat","r");
do
{
printf("Press 1.Display\t 2.Search\t 3.Exit\t \nYour Option? >>");
scanf("%d",&opn);
switch(opn)
{
case 1: printf("\n Student Records in the File \n");
display(fp);
break;
case 2: printf(" Read the roll no of the student to be searched ?");
scanf("%d",&roll_key);
if(search(fp,roll_key))
{
printf("Success ! Record found in the file\n");
printf("%d\t%s\t%d\t%s\n",s.roll,s.name,s.class,s.address);
}
else
printf(" Failure!! Record with Roll No  %d not found\n",roll_key);
break;
case 3:  printf(" Exit!! Press a key . . .");
getch();
break;
default:  printf(" Invalid Option!!! Try again !!!\n");
break;
}
}while(opn != 3);
fclose(fp);
}   /* End of main() */
void display(FILE *fp)
{
rewind(fp);
while(fread(&s,sizeof(s),1,fp))
printf("%d\t%s\t%d\t%s\n",s.roll,s.name,s.class,s.address);
}
int search(FILE *fp, int roll_key)
{
rewind(fp);
while(fread(&s,sizeof(s),1,fp))
if( s.roll== roll_key) return 1;
return 0;
}
