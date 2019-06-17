#include<stdio.h>
#include<time.h> 
#include<stdlib.h>
#include<string.h>
void test(char *num)               //define a pointer which point the outside time and ID
{
	FILE *inFile = fopen("record.txt","a");  //record the result in a file
	int CoAn[10],UrAn[10],fo[10],la[10],score=0,answer,a,b,c,i;   //define two array to record the answer
	int time1=time(NULL);
	char k[10];
	for(i=0;i<10;i++)
	{
		srand((unsigned)time(NULL));
		switch(rand()%4)      //generates the algrithm randomly
		{
			case 0:srand((unsigned)time(NULL));
				   do{
                   fo[i]=rand()%100;
                   la[i]=rand()%100;
                   c=fo[i]+la[i];
                     }while(c>=100);
                   printf("%d+%d=",fo[i],la[i]);
                   k[i]='+';
                   break;
            case 1:srand((unsigned)time(NULL));
			       do{
                   c=rand()%100;
                   la[i]=rand()%100;
                   fo[i]=c+la[i];
                     }while(fo[i]>=100);
				   printf("%d-%d=",fo[i],la[i]);
				   k[i]='-';
				   break;	        
            case 2:srand((unsigned)time(NULL)); 
			       do{
                   fo[i]=rand()%100;
                   la[i]=rand()%100;
                   c=fo[i]*la[i];
                     }while(c>=100);
				   printf("%d*%d=",fo[i],la[i]);
				   k[i]='*';
				   break;
			case 3:srand((unsigned)time(NULL)); 
			       do{
                   c=rand()%100;
                   la[i]=rand()%99+1;
                   fo[i]=c*la[i];
                     }while(fo[i]>=100);
				   printf("%d/%d=",fo[i],la[i]);
				   k[i]='/';	   	      				     
		}		    
			while(scanf("%d",&answer)==0)                   //this circle aims to determine the number the user enter is correct
			{
			char abosbtion[100];
			printf("Please enter the correct number");
			scanf("%s",abosbtion);
			}		    
            if(answer==c)
            score+=10;
            CoAn[i]=c;
            UrAn[i]=answer;
	}
	int time2=time(NULL);
	int time=time2-time1;   //record the time the user used
	fprintf(inFile,"%s %d %d\n",num,score,time);
	fclose(inFile);
	printf("Prob. | Correct Answ | Ur Answ\n");  //print the results of each problem
	for(i=0;i<10;i++)
	{
		printf(" %d%c%d\t\t%d\t%d\n",fo[i],k[i],la[i],CoAn[i],UrAn[i]);
	}
	}
void check(char *num)
{
	FILE *inFile = fopen("record.txt","r"); //read the following results in files
	char fnum[7];     //a string which reads the students number in files
	int score,time;
	printf("Your previous records are:\n"); 
	start:
	do{						                          
		if(fscanf(inFile,"%s %d %d",fnum,&score,&time)==EOF)
		return;
		
	}while(strcmp(num,fnum));  //compare the users ID with ID which is in the file
	
	printf("%s  %d  %dseconds\n",fnum,score,time);
	goto start;  //return searching for the results
}
int judge(char *p)
{
	int i;
	if(p[6]!='\0')             //make sure the ID is 6 figures 
	{
		printf("PLease enter the right ID number");
		return 1;			
		}		
	for(i=0;i<2;i++)
	{
		if(*(p+i)<'A'||*(p+i)>'Z')
		{
		printf("PLease enter the right ID number");  
		return 1;			
		}		 		
	}
	for(i=2;i<6;i++)
	{
		if(*(p+i)<'0'||*(p+i)>'9')
		{
		printf("PLease enter the right ID number");  
		return 1;			
		}		
	}
	return 0;
}
int main()
{
	char student_number[7];
	printf("Please input your two capital letters and four digit ID no:");
	do{scanf("%s",student_number);     //limit the entering byte is 6 
	}while(judge(student_number));         //a function to judge the ID number
	start:
	printf("(1)Start a test\n(2)Check scores\n(3)Exit\n");
	int a,score;	
	     while(scanf("%d",&a)==0)                           //this circle aims to determine the number the user enter is correct
			{
			char abosbtion[100];
			printf("Please enter the correct number");
			scanf("%s",abosbtion);
			}
	switch(a)
	{
		case 1:test(student_number);
		       goto start; //return to where has choices
		case 2:check(student_number);
               goto start;
        case 3:return 0;    //end the whole program
		default: goto start;      //if users enters the wrong thing then back to the beginning
	}
} 