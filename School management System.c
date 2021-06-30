#include<stdio.h>
#include<string.h>

//function prototypes
void login(void);
void principle(void);
void staff_data(void);
void add_staff(void);
void remove_staff(void);
void student_data(void);
void add_student(void);
void remove_student(void);
void teacher_list(void);
void teacher_list1(int );
void mid_marks(int n);
void final_marks(int n);
void assignment_marks(int n);
void grades(int n);
char tocalculate(int s,int r,int f);
int editmarks(int k,int n);
void student2list(int n);
int prin_inf();
void admin_h();
void fees();
void complain();
//main

//structures
typedef struct data{
	char id[10];
	char position[30];
	char name[10];
	int salary;
}STAFF;
STAFF staff;
STAFF staff2[50];
typedef struct data1{
	char id[10];
	char name[10];
	char fname[10];
	char address[40];
	int midmarks;
	int finalmarks;
	int assignemt;
}STUDENT;
STUDENT students;
STUDENT student1[10];
STUDENT marks;
STUDENT marks2[10];
typedef struct data2{
	char name[20];
	int salary;
	int duration;
}PRINCIPLE;
PRINCIPLE prin;

//main function

int main(){
	login();
}

void login(){
	int i=0;
	char ch,ch1,prinptr[10],teachptr[10],adminptr[10],pass[10],id[20];
	FILE *ptr1,*ptr2,*ptr3;
	// file open
	
	ptr1=fopen("prin_pass.txt","r");
	ptr2=fopen("teach_pass.txt","r");
	ptr3=fopen("admin_pass.txt","r");
	fscanf(ptr1,"%s",prinptr);
	fscanf(ptr2,"%s",teachptr);
	fscanf(ptr3,"%s",adminptr);
	// file close
	fclose(ptr1);
	fclose(ptr2);
	fclose(ptr3);
	
while(1){
	//main menu
//	system("cls");
    fflush(stdin);
    printf("\t--------------------------\t\n");
    printf("\t SCHOOL MANAGEMNET SYSTEM\n\n");
    printf("\t--------------------------\t\n");
	printf("\tlogin as:\n\n\t1.ADMINISTRATOR\n\t2.PRINCIPLE\n\t3.TEACHER\n\n");
	printf("Enter your choice or enter 'b' to exit:  ");
	gets(id);
	
    if(id[0]=='b'){
    	break;
	}
	    
	printf("\nEnter password:");
   for(i=0;(ch=getch())!=13;i++)
    {
    pass[i] = ch;
    ch = '*' ;
    printf("%c",ch);
    }

    pass[i] = '\0';
	// for principle
	if(strcmp(id,"administrator")==0){
		if(strcmp(adminptr,pass)==0){
			admin_h();
			continue;
	}
	}
	// for teacher
	if(strcmp(id,"teacher")==0){
	    if(strcmp(teachptr,pass)==0){		
		teacher_list();
		continue;
	}
	}
	// for administrator
	if(strcmp(id,"principle")==0){
		if(strcmp(prinptr,pass)==0){	
				principle();
				continue;
		
	}
	}
	printf("\n\twrong password or id!!");
	getch();
	}
}
void principle(){
	int choice;
	while(1){
		
	system("cls");
    fflush(stdin);
    FILE *ptr;
    ptr=fopen("princ.txt","r");
    fread(&prin,sizeof(struct data2),1,ptr);
    if(prin.duration>5){
    	printf("\n\n\t\tYOUR TENURE IS EXPIRED!!!");
    	getch();
    	break;
	}
	else{
	printf("\n\tWELCOME PRINCIPLE\t\n\n");
	printf("\t1.STAFF DATA\t\n");
	printf("\t2.STUDENTS DATA\t\n");
	printf("\t3.LOGG OUT\t\n");	
	printf("\tEnter Your Choice: ");	
	scanf("%d",&choice);
	
	switch(choice){
		case 1:{
			staff_data();
			continue;
		}
		case 2:{
			student_data();
			continue;
		}
		case 3:{
			break;
		}
		default:
			{
				printf("\t\t\tenter correct option");
				getch();
				continue;
			}
	}
	break;
	
	}
}
}
void staff_data(){
	while(1){
	system("cls");
	fflush(stdin);
	char choice;
	int i=0;
	FILE *sptr;
	sptr=fopen("staff_list.txt","r");
	
	printf("\t\t\tSTAFF LIST\n\n");
	printf("\tID\t\tPOSITION\tNAME\t\tSALARY\n\n");
	
	while((fread(&staff,sizeof(struct data),1,sptr))){
		printf("\t%s\t\t%s\t\t%s\t\t\%d\n\n",staff.id,staff.position,staff.name,staff.salary);
	}
	printf("\nDo you want to Hire or Fire an staff?(h/f/n): ");
	scanf("%c",&choice);
					
		switch(choice)	{
				
		case 'h':{
		add_staff();
		continue;
		}
				
		case 'f':{
		remove_staff();				
		break;
		}
				
		case 'n':
		{
		break;
		}
		default:
			{
				printf("\t\t\tenter correct option");
				getch();
				continue;
			}
}
break;
}
}
void add_staff(){
	char choice;
	FILE *sptr;
	sptr=fopen("staff_list.txt","a+");
		while(1){
			
		system("cls");
		fflush(stdin);
		printf("STAFF ID(xx-xxxx)");
		scanf("%s",staff.id);
		printf("STAFF POSITION");
		scanf("%s",staff.position);
		printf("STAFF Name:");
		scanf("%s",staff.name);
		printf("Staff Salary:");
		scanf("%ld",&staff.salary);
		
		fwrite(&staff, sizeof(staff), 1, sptr);
		fflush(stdin);
		while(1){
			system("cls");
			fflush(stdin);
		printf("\nDo you want to hire more?(y/n): ");
		scanf("%c",&choice);
		switch(choice){
			case 'y':{
				break;
			}
			case 'n':{
				break;
			}
			default:
			{
				printf("\t\t\tenter correct option");
				getch();
				continue;
			}
		}
		break;
	}
		if(choice == 'y')
		continue;
		break;
	}
	fclose(sptr);
}
void remove_staff(void){
	char  choice;
	while(1){
		int i=0,j;
		FILE *ptr;
		char name[10];
		system("cls");
		fflush(stdin);
		
		printf("Enter staff id(XX-xxx)");
		scanf("%s",name);
		
		fflush(stdin);
		ptr=fopen("staff_list.txt","r");
		while(fread(&staff,sizeof(staff),1,ptr)){
				
				if(strcmp(name,staff.id)){
					strcpy(staff2[i].id,staff.id);
					strcpy(staff2[i].position,staff.position);
					strcpy(staff2[i].name,staff.name);
					staff2[i].salary=staff.salary;
					i++;
					}
		}
		fclose(ptr);
		ptr=fopen("staff_list.txt","w");
		fwrite(&staff2, sizeof(struct data), i, ptr);
		fclose(ptr);
			while(1){
			system("cls");
			fflush(stdin);
		printf("\nDo you want to fire more?(y/n): ");
		scanf("%c",&choice);
		switch(choice){
				case 'y':{
				break;
			}
			case 'n':{
				break;
			}
			default:
			{
				printf("\t\t\tenter correct option");
				getch();
				continue;
			}
		}
		break;
	}
		if(choice == 'y')
		continue;
		break;
	}
	}
void student_data(void){
	while(1){
	system("cls");
	fflush(stdin);
	char choice;
	int i=0;
	FILE *tptr;
	tptr=fopen("student_list.txt","r");
	
	printf("\t\t\tSTUDENT LIST\n\n");
	printf("\tID\t\tNAME\tFATHERNAME\t\tADDRESS\n\n");
	
	while((fread(&students,sizeof(struct data1),1,tptr))){
		printf("\t%s\t%s\t%s\t\t%s\n\n",students.id,students.name,students.fname,students.address);
	}
	fclose(tptr);
	printf("\nDo you want to add or remove student?(a/r/n): ");
	scanf("%c",&choice);
					
		switch(choice)	{
				
		case 'a':{
		add_student();
		continue;
		}
				
		case 'r':{
		remove_student();			
		continue;
		}
				
		case 'n':
		{
		break;
		}
		default:
			{
				printf("\t\t\tenter correct option");
				getch();
				continue;
		}
}
break;
}
}
void add_student(void){
	char choice;
	FILE *tptr;
	tptr=fopen("student_list.txt","a+");
		while(1){
			
		system("cls");
		fflush(stdin);
		printf("STUDENT ID(xxx-xxxx)");
		scanf("%s",students.id);
		printf("STUDENT NAME");
		scanf("%s",students.name);
		printf("STUDENT FATHER NAME");
		scanf("%s",students.fname);
		printf("STUDENT ADDRESS");
		scanf("%s",students.address);
		students.assignemt=0;
		students.midmarks=0;
		students.finalmarks=0;
		
		fwrite(&students, sizeof(struct data1), 1, tptr);
		fflush(stdin);
		while(1){
			system("cls");
			fflush(stdin);
		printf("\nDo you want to hire more?(y/n): ");
		scanf("%c",&choice);
			switch(choice){
				case 'y':{
				break;
			}
			case 'n':{
				break;
			}
			default:
			{
				printf("\t\t\tenter correct option");
				getch();
				continue;
			}
		}
		break;
	}
		if(choice == 'y')
		continue;
		break;
	}
	fclose(tptr);
}
void remove_student(void){
	char  choice;
	while(1){
		int i=0,j;
		FILE *ptr;
		char ids[10];
		system("cls");
		fflush(stdin);
		
		printf("Enter student id(XXX-xxx)");
		gets(ids);
		
		fflush(stdin);
		ptr=fopen("student_list.txt","r");
		while(fread(&students,sizeof(struct data1),1,ptr)){
				if(strcmp(ids,students.id)){
					strcpy(student1[i].id,students.id);
					strcpy(student1[i].name,students.name);
					strcpy(student1[i].fname,students.fname);
					strcpy(student1[i].address,students.address);
					i++;
					}
		}
		fclose(ptr);
		
		ptr=fopen("student_list.txt","w");
		fwrite(&student1, sizeof(struct data1), i, ptr);
		fclose(ptr);
		while(1){
			system("cls");
			fflush(stdin);
		printf("\nDo you want to remove students more?(y/n): ");
		scanf("%c",&choice);
			switch(choice){
				case 'y':{
				break;
			}
			case 'n':{
				break;
			}
			default:
			{
				printf("\t\t\tenter correct option");
				getch();
				continue;
			}
		}
		break;
	}
		if(choice == 'y')
		continue;
		break;
	}
}
void teacher_list(void){
	int choice;
	while(1){
	system("cls");
    fflush(stdin);
	printf("\n\tWELCOME TEACHER\t\n\n");
	printf("\t1.CLASS(1 OR 2)\t\n");
	printf("\t3.LOGG OUT\t\n");	
	printf("\tEnter Your Choice: ");	
	scanf("%d",&choice);
	
	switch(choice){
		case 1:{
			teacher_list1(1);
			continue;
		}
		case 2:{
			teacher_list1(2);
			continue;
		}
		case 3:{
			break;
		}
		default:
			{
				printf("\t\t\tenter correct option");
				getch();
				continue;
			}
	}
	break;
	}
}
void teacher_list1(int n){
	int choice;
	while(1){
	system("cls");
	fflush(stdin);
	
	printf("\n\tWELCOME CLASS TEACHER\t\n\n");
	printf("\t1.STUDENT DATA\t\n");
	printf("\t2.STUDENT GRADES\t\t\n");
	printf("\t3.MID MARKS\t\n");
	printf("\t4.ASSIGNMENT MARKS\t\t\n");
	printf("\t5.FINAL MARKS\t\n");
	printf("\t6.STUDENT COMPLAINS\t\n");
	printf("\t7.GO BACK\t\n");	
	printf("\tEnter Your Choice: ");	
	scanf("%d",&choice);
	
	switch(choice){
		case 1:{
		student2list(n);
		getch();
		continue;
		}
		case 2:{
	    grades(n);
	    continue;
		}
		case 3:{
			mid_marks(n);
			continue;
		}
		case 4:{
			assignment_marks(n);
			continue;
		}
		case 5:{
			final_marks(n);
			continue;
		}
		case 6:{
			complain();
			continue;
		}
		case 7:{
			break;
		}
		default:
			{
				printf("\t\t\tenter correct option");
				getch();
				continue;
			}
	}
	break;
	}
}
void mid_marks(int n){
	int ch;
	fflush(stdin);
	system("cls");
	
	printf("\tNAME\t\tMID MARKS\n\n");
	
	while(1){
	FILE *ptr;
	ptr=fopen("student_list.txt","r");
	if(n==1){
		while(fread(&marks,sizeof(struct data1),1,ptr)){
			if(marks.id[0]=='1'&&marks.id[1]=='8')
			printf("\t%s\t\t%d\n",marks.name,marks.midmarks);
		}
	}
	if(n==2){
		while(fread(&marks,sizeof(struct data1),1,ptr)){
			if(marks.id[0]=='1'&&marks.id[1]=='7')
			printf("\t%s\t\t%d\n",marks.name,marks.midmarks);
		}
	}
	
	printf("\n\t-----------------------");
	printf("\n\tYOU WANT TO ENTER MARKS(1 for yes and 0 for no)\n");
	scanf("%d",&ch);
	
	switch(ch){
		case 1:{
		editmarks(1,n);
		break;
		}
		case 0:{
			break;
		}
	}
	break;
}}
void final_marks(int n){
	int ch;
	fflush(stdin);
	system("cls");
	
	printf("\tNAME\t\tFINAL MARKS\n\n");
	
	while(1){
	FILE *ptr;
	ptr=fopen("student_list.txt","r");
	if(n==1){
		while(fread(&marks,sizeof(struct data1),1,ptr)){
			if(marks.id[0]=='1'&&marks.id[1]=='8')
			printf("\t%s\t\t%d\n",marks.name,marks.finalmarks);
		}
	}
	if(n==2){
		while(fread(&marks,sizeof(struct data1),1,ptr)){
			if(marks.id[0]=='1'&&marks.id[1]=='7')
			printf("\t%s\t\t%d\n",marks.name,marks.finalmarks);
		}
	}
	
	printf("\n\tYOU WANT TO ENTER MARKS(1 for yes and 0 for no)\n");
	scanf("%d",&ch);
	
	switch(ch){
		case 1:{
		editmarks(3,n);
		break;
		}
		case 0:{
			break;
		}
	}
	break;
}
}
void assignment_marks(int n){
	int ch;
	fflush(stdin);
	system("cls");
	
	while(1){
	printf("\tNAME\t\tASSIGNMENT MARKS\n\n");
	FILE *ptr;
	ptr=fopen("student_list.txt","r");
	if(n==1){
		while(fread(&marks,sizeof(struct data1),1,ptr)){
			if(marks.id[0]=='1'&&marks.id[1]=='8')
			printf("\t%s\t\t%d\n",marks.name,marks.assignemt);
		}
	}
	if(n==2){
		while(fread(&marks,sizeof(struct data1),1,ptr)){
			if(marks.id[0]=='1'&&marks.id[1]=='7')
			printf("\t%s\t\t%d\n",marks.name,marks.assignemt);
		}
	}
	
	printf("\n\tYOU WANT TO ENTER MARKS(1 for yes and 0 for no)\n");
	scanf("%d",&ch);
	
	switch(ch){
		case 1:{
		editmarks(2,n);
		break;
		}
		case 0:{
			break;
		}
	}
	break;
}
}
void grades(int n){
	char t;
	fflush(stdin);
	system("cls");
	while(1){
	
	printf("\tNAME\t\tGRADES\n\n");
	
	FILE *ptr;
	ptr=fopen("student_list.txt","r");
	if(n==1){
		while(fread(&marks,sizeof(struct data1),1,ptr)){
			if(marks.id[0]=='1'&&marks.id[1]=='8'){
			t=tocalculate(marks.midmarks,marks.finalmarks,marks.assignemt);
			printf("\t%s\t\t%c\n",marks.name,t);}
		}
	}
	if(n==2){
		while(fread(&marks,sizeof(struct data1),1,ptr)){
			if(marks.id[0]=='1'&&marks.id[1]=='7'){
			t=tocalculate(marks.midmarks,marks.finalmarks,marks.assignemt);
			printf("\t%s\t\t%c\n",marks.name,t);
				}
				}
	}
	break;
}
}
char tocalculate(int s,int r,int f){
	int k;
	k=s+r+f;
	if(k>=90&&k<100)
	return 'A';
	else if(k>=75&&k<90)
	return 'B';
	else if(k>=60&&k<75)
	return 'C';
	else if(k>=45&&k<60)
	return 'D';
	else
	return 'F';
}
int editmarks(int k,int n){
	fflush(stdin);
	system("cls");
	int i=0,m=0;
		FILE *ptr;
		ptr=fopen("student_list.txt","r");
		while(fread(&marks2[i],sizeof(struct data1),1,ptr)){
		
		if(marks2[i].id[0]!='0'){
		if(n==1){
		if(marks2[i].id[0]=='1'&&marks2[i].id[1]=='8'){
		printf("%s\n",marks2[i].name);
		printf("enter new marks  ");
		switch(k){
		case 1:{
			scanf("%d",&marks2[i].midmarks);
			break;	}
		case 2:{
		    scanf("%d",&marks2[i].assignemt);
			break;
			}
		case 3:{
			scanf("%d",&marks2[i].finalmarks);
			break;
			}
		default:
			{
				printf("\t\t\tenter correct option");
				getch();
				continue;
			}
				}
				}
				}
		else if(n==2){
				if(marks2[i].id[0]=='1'&&marks2[i].id[1]=='7'){
					printf("%s\n",marks2[i].name);
					printf("enter new marks");
					switch(k){
						case 1:{
						scanf("%d",&marks2[i].midmarks);
						break;
						}
						case 2:{
						scanf("%d",&marks2[i].assignemt);
							break;
						}
						case 3:{
						scanf("%d",&marks2[i].finalmarks);
							break;
						}
						default:
			{
				printf("\t\t\tenter correct option");
				getch();
				continue;
			}
					}}}}
					i++;}
			fclose(ptr);
			ptr=fopen("student_list.txt","w");
			while(marks2[m].midmarks!=0){
			fwrite(&marks2[m],sizeof(struct data1),1,ptr);
			m++;
		}
		fflush(stdin);
		getch();
		fclose(ptr);
}
void student2list(int n){
	system("cls");
	fflush(stdin);
	FILE *ptr;
	ptr=fopen("student_list.txt","r");
		printf("\t\t\tSTUDENT LIST\n\n");
	printf("\tID\t\tNAME\tFATHERNAME\t\tADDRESS\n\n");
	while(fread(&marks,sizeof(struct data1),1,ptr)){
	if(n==1){
	if(marks.id[0]=='1'&&marks.id[1]=='8'){
	printf("\t%s\t%s\t%s\t\t%s\n\n",marks.id,marks.name,marks.fname,marks.address);
	}
}
else if(n==2){
	if(marks.id[0]=='1'&&marks.id[1]=='7'){
	printf("\t%s\t%s\t%s\t\t%s\n\n",marks.id,marks.name,marks.fname,marks.address);
}
}
}
	fclose(ptr);
}
void admin_h(){
	int choice;
	while(1){
	system("cls");
    fflush(stdin);
	
	printf("\n\tWELCOME ADMINISTRATOR\t\n\n");
	printf("\t1.PRINCIPLE DATA\t\n");
	printf("\t2.STAFF DATA\t\n");
	printf("\t3.STUDENTS DATA\t\n");
	printf("\t4.STUDENT FEES\t\n");
	printf("\t5.LOGG OUT\t\n");	
	
	printf("\tEnter Your Choice: ");	
	scanf("%d",&choice);
	
	switch(choice){
		case 1:{
			prin_inf();
			getch();
			continue;
		}
		case 2:{
			staff_data();
			continue;
		}
		case 3:{
			student_data();
			continue;
		}
		case 4:{
			fees();
			getch();
			continue;
		}
		case 5:{
			break;
		}
	    default:
			{
				printf("\t\t\tenter correct option");
				getch();
				continue;
			}
	}
	break;
	}
}
int prin_inf(){
	char choice;
	while(1){
		system("cls");
		fflush(stdin);
    FILE *ptr;
	ptr=fopen("princ.txt","r");
    
	printf("\t\tPRINCIPLE INFORMATION\n\n");
	printf("\tNAME\t\tSALARY\t\tTIME DURATION(YEARS)\n\n");
    
	while(fread(&prin,sizeof( struct data2),1,ptr))
	printf("\t%s\t\t%d\t\t%d\n\n",prin.name,prin.salary,prin.duration);
	fclose(ptr);
	printf("YOU WANT TO CHANGE INFORMATION (Y FOR YES AND N FOR NO)\n");
	scanf("%c",&choice);
	
	switch(choice){
		case 'Y':{
			system("cls");
			fflush(stdin);
			printf("enter name  ");
			gets(prin.name);
			printf("enter salary  ");
			scanf("%d",&prin.salary);
			printf("enter time duration");
			scanf("%d",&prin.duration);
			ptr=fopen("princ.txt","w");
            fwrite(&prin,sizeof(struct data2),1,ptr);  
			fclose(ptr);
			continue;
		}
		case 'N':{
			break;
		}
	    default:
			{
				printf("\t\t\tenter correct option");
				getch();
				continue;
			}
	}
	break;
}
}
void fees(){
	system("cls");
	fflush(stdin);
	char choice;
	int fee;
	FILE *ptr;
	ptr=fopen("fees.txt","r");
	fscanf(ptr,"%d",&fee);
	fclose(ptr);
	
	printf("\n\n\t\tSTUDENT FEES : %d",fee);
	printf("\n\t Do you want to change fees  ");
	scanf("%c",&choice);
	
	fflush(stdin);
	switch(choice){
		case 'y':{
			system("cls");
			fflush(stdin);
			printf("\n\t\tenter student fees  ");
			scanf("%d",&fee);
	        ptr=fopen("fees.txt","w");
	        fprintf(ptr,"%d",fee);
			fclose(ptr);
			break;
		}
		case 'n':{
			break;
		}
		break;
	}
}
void complain(){
	system("cls");
	fflush(stdin);
	char choice;
	while(1){
	char com[20],ch;
	FILE *ptr;
	ptr=fopen("complain.txt","r");
	printf("\t\tCOMPLAIN BOXS\n\n\t ");
	while((ch=fgetc(ptr))!=EOF){
		if(ch=='\n')
		printf("\n\n\t ");
		else
		printf("%c",ch);
	}
	
	fclose(ptr);
	printf("\n\n");
	while(1){
	printf("DO YOU WANT TO ENTER MORE COMPLAINS('y'FOR YES AND 'n' FOR NO)");
	scanf("%c",&choice);
	switch(choice){
		case 'y':{
			system("cls");
			fflush(stdin);
			printf("\n\t\tenter complain");
			gets(com);
	        ptr=fopen("complain.txt","a");
	        fprintf(ptr,"%s \n",com);
			fclose(ptr);
			break;
		}
		case 'n':{
			break;
		}
		default:
			{
				printf("\t\t\tenter correct option");
				getch();
				continue;
			}
	}
	break;
}
	break;
	}
}



