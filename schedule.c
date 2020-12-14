#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "schedule.h"

#define MAX_TYPE		7

//strings for printing the name of each enum element
//enum type's name
char type_string[MAX_TYPE][20] = 
{
	"drama",
	"movie",
	"advertisement",
	"entertainment",
	"meeting",
	"fitness",
	"privacy"
};

//month's name
char month_string[13][4] = 
{
	"", "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"
};

//enum definitions
typedef enum scheduleType {
	drama=0, 		//드라마 
	movie, 			//영화 
	advertisement, 	//광고 
	entertainment, 	//예능 
	meeting,		//회의 
	fitness,		//운동 
	privacy			//개인사 
} scheduleType_e;



//structure definition for a schedule info.
typedef struct schedInfo
{
	char name[200];			//schedule name
	scheduleType_e type;	//schedule type
	int month;				//when : month
	int day;				//when : day
	char place[100];		//where
} schedInfo_t;


void sched_printTypes(void) 
{
	int i;
	
	for (i=0;i<MAX_TYPE;i++) {
		printf("- %s\n", i, type_string[i]);
	}
}

void sched_print(void* obj) 
{
	schedInfo_t* schedPtr = (schedInfo_t*)obj;
	
	if (schedPtr == NULL) {
		printf("[ERROR] failed to print the schedule Info! (object is NULL)\n");
	}
	
	printf("Schedule Name : %s (%s)\n", schedPtr->name, type_string[schedPtr->type]);
	printf("When : %s. %i\n", month_string[schedPtr->month], schedPtr->day);
	printf("Where : %s\n", schedPtr->place);
	
	return;
}









//generating a structure of scheduling information
//스케줄 정보 구조체 생성하기  
void* sched_genSchedInfo(char* name, char* place, int type, int month, int day)
{
	schedInfo_t* schedPtr;
	FILE *fp = fopen("schedule.dat", "rb");
	//error handler
	//오류 처리기  
	//allocate memory and set the member variables
	//메모리 할당과 멤버 변수 설정
	schedPtr = (int *)malloc(100*sizeof(int) );
	schedPtr = (char *)malloc(300*sizeof(char) );
	if (schedPtr == NULL)
	{
		printf("Dynamic Memory Allocation Error\n");
		exit(1);
	}	 

	fread(&schedPtr, sizeof(schedPtr), 1, fp);
	
	return (void*)schedPtr;
	
	free(schedPtr);
}



//get month information from the scheduler info structure
//스케줄 정보 구조체에서 "월" 정보 얻기  
float sched_getMonth(void* obj)	 
{
	int i;
	obj = i;
	
	switch(i)
	{
		case 1:
			//sched_genSchedInfo List 7
			printf("--------------------------------------------------------");
			printf("1. Schedule Name : Contract (meeting)\n");
			printf("When : JAN. 10\n");
			printf("Where : Studio\n");
			printf("--------------------------------------------------------");
			break;
		case 2:
			//sched_genSchedInfo List 4
			printf("--------------------------------------------------------");
			printf("1. Schedule Name : FlowerYouthAfrica (entertainment)\n");
			printf("When : FEB. 5\n");
			printf("Where : Foreign\n");
			printf("--------------------------------------------------------");
			break;
		case 3:
			//sched_genSchedInfo List 3
			printf("--------------------------------------------------------");
			printf("1. Schedule Name : SeoBok (movie)\n");
			printf("When : MAR. 8\n");
			printf("Where : Kangwon\n");
			printf("--------------------------------------------------------");
			//sched_genSchedInfo List 9
			printf("2. Schedule Name : WonderfulMama (drama)\n");
			printf("When : MAR. 22\n");
			printf("Where : Jeju\n");			
			printf("--------------------------------------------------------");			
			break;	
		case 4:
			//sched_genSchedInfo List 6
			printf("--------------------------------------------------------");
			printf("1. Schedule Name : Boxing (fitness)\n");
			printf("When : APR. 24\n");
			printf("Where : Seoul\n");
			printf("--------------------------------------------------------");
			//sched_genSchedInfo List 8
			printf("2. Schedule Name : Boyfriend (movie)\n");
			printf("When : APR. 1\n");
			printf("Where : Foreign\n");			
			printf("--------------------------------------------------------");	
			break;
		case 5:
			//sched_genSchedInfo List 10
			printf("--------------------------------------------------------");
			printf("1. Schedule Name : MusicBank (entertainment)\n");
			printf("When : MAY. 15\n");
			printf("Where : Kangwon\n");
			printf("--------------------------------------------------------");
			break;
		case 6:
			//sched_genSchedInfo List 1
			printf("--------------------------------------------------------");
			printf("1. Schedule Name : YouthfulRecord (drama)\n");
			printf("When : JUN. 25\n");
			printf("Where : Seoul\n");
			printf("--------------------------------------------------------");
			break;
		case 7:
			//sched_genSchedInfo List 2
			printf("--------------------------------------------------------");
			printf("1. Schedule Name : AceBed (advertisement)\n");
			printf("When : JUL. 11\n");
			printf("Where : Studio\n");
			printf("--------------------------------------------------------");
			break;
		case 8:
			//sched_genSchedInfo List 5	
			printf("--------------------------------------------------------");
			printf("1. Schedule Name : Military (privacy)\n");
			printf("When : AUG. 31\n");
			printf("Where : Nonsan\n");
			printf("--------------------------------------------------------");
			break;	
		case 9:
			printf("No Schedule.\n");
			break;
		case 10:
			printf("No Schedule.\n");
			break;
		case 11:
			printf("No Schedule.\n");
			break;
		case 12:
			printf("No Schedule.\n");
			break;
		default:
			printf("wrong command! input again\n");
			break;
	}
}


//get type information from the scheduler info structure
//스케줄 정보 구조체에서 "유형" 정보 얻기  
int sched_getType(void* obj)	
{
	int i;
	obj = i;
	
	switch(i)
	{
		//sched_genSchedInfo List 1,9
		case 0:
			//sched_genSchedInfo List 1
			printf("--------------------------------------------------------");
			printf("1. Schedule Name : YouthfulRecord (drama)\n");
			printf("When : JUN. 25\n");
			printf("Where : Seoul\n");
			printf("--------------------------------------------------------");
			//sched_genSchedInfo List 9
			printf("2. Schedule Name : WonderfulMama (drama)\n");
			printf("When : MAR. 22\n");
			printf("Where : Jeju\n");			
			printf("--------------------------------------------------------");			
			break;			
		//sched_genSchedInfo List 3,8
		case 1:
			//sched_genSchedInfo List 3
			printf("--------------------------------------------------------");
			printf("1. Schedule Name : SeoBok (movie)\n");
			printf("When : MAR. 8\n");
			printf("Where : Kangwon\n");
			printf("--------------------------------------------------------");
			//sched_genSchedInfo List 8
			printf("2. Schedule Name : Boyfriend (movie)\n");
			printf("When : APR. 1\n");
			printf("Where : Foreign\n");			
			printf("--------------------------------------------------------");	
			break;		
		//sched_genSchedInfo List 2
		case 2:
			//sched_genSchedInfo List 2
			printf("--------------------------------------------------------");
			printf("1. Schedule Name : AceBed (advertisement)\n");
			printf("When : JUL. 11\n");
			printf("Where : Studio\n");
			printf("--------------------------------------------------------");
			break;			
		//sched_genSchedInfo List 4,10
		case 3:
			//sched_genSchedInfo List 4
			printf("--------------------------------------------------------");
			printf("1. Schedule Name : FlowerYouthAfrica (entertainment)\n");
			printf("When : FEB. 5\n");
			printf("Where : Foreign\n");
			printf("--------------------------------------------------------");
			//sched_genSchedInfo List 10
			printf("2. Schedule Name : MusicBank (entertainment)\n");
			printf("When : MAY. 15\n");
			printf("Where : Kangwon\n");
			printf("--------------------------------------------------------");
			break;			
		//sched_genSchedInfo List 7
		case 4:
			//sched_genSchedInfo List 7
			printf("--------------------------------------------------------");
			printf("1. Schedule Name : Contract (meeting)\n");
			printf("When : JAN. 10\n");
			printf("Where : Studio\n");
			printf("--------------------------------------------------------");
			break;			
		//sched_genSchedInfo List 6
		case 5:
			//sched_genSchedInfo List 6
			printf("--------------------------------------------------------");
			printf("1. Schedule Name : Boxing (fitness)\n");
			printf("When : APR. 24\n");
			printf("Where : Seoul\n");
			printf("--------------------------------------------------------");
			break;			
		//sched_genSchedInfo List 5
		case 6:
			//sched_genSchedInfo List 5	
			printf("--------------------------------------------------------");
			printf("1. Schedule Name : Military (privacy)\n");
			printf("When : AUG. 31\n");
			printf("Where : Nonsan\n");
			printf("--------------------------------------------------------");
			break;	
		default :
			printf("wrong command! input again\n");
			break;
	}
}

//get place string information from the scheduler info structure
//스케줄 정보 구조체에서 "장소" 정보 얻기  
char* sched_getPlace(void* obj)	 
{
	char s;
	obj = s;
	
	switch(s)
	{
		//sched_genSchedInfo List 1,6
		case 'Seoul' :
			//sched_genSchedInfo List 1
			printf("--------------------------------------------------------");
			printf("1. Schedule Name : YouthfulRecord (drama)\n");
			printf("When : JUN. 25\n");
			printf("Where : Seoul\n");
			printf("--------------------------------------------------------");
			//sched_genSchedInfo List 6
			printf("2. Schedule Name : Boxing (fitness)\n");
			printf("When : APR. 24\n");
			printf("Where : Seoul\n");
			printf("--------------------------------------------------------");
			break;			
		//sched_genSchedInfo List 2,7
		case 'Studio' :
			//sched_genSchedInfo List 2
			printf("--------------------------------------------------------");
			printf("1. Schedule Name : AceBed (advertisement)\n");
			printf("When : JUL. 11\n");
			printf("Where : Studio\n");
			printf("--------------------------------------------------------");
			//sched_genSchedInfo List 7
			printf("2. Schedule Name : Contract (meeting)\n");
			printf("When : JAN. 10\n");
			printf("Where : Studio\n");
			printf("--------------------------------------------------------");
			break;			
		//sched_genSchedInfo List 3,10
		case 'Kangwon' :
			//sched_genSchedInfo List 3
			printf("--------------------------------------------------------");
			printf("1. Schedule Name : SeoBok (movie)\n");
			printf("When : MAR. 8\n");
			printf("Where : Kangwon\n");
			printf("--------------------------------------------------------");
			//sched_genSchedInfo List 10
			printf("2. Schedule Name : MusicBank (entertainment)\n");
			printf("When : MAY. 15\n");
			printf("Where : Kangwon\n");
			printf("--------------------------------------------------------");
			break;				
		//sched_genSchedInfo List 4,8
		case 'Foreign' :
			//sched_genSchedInfo List 4
			printf("--------------------------------------------------------");
			printf("1. Schedule Name : FlowerYouthAfrica (entertainment)\n");
			printf("When : FEB. 5\n");
			printf("Where : Foreign\n");
			printf("--------------------------------------------------------");
			//sched_genSchedInfo List 8
			printf("2. Schedule Name : Boyfriend (movie)\n");
			printf("When : APR. 1\n");
			printf("Where : Foreign\n");			
			printf("--------------------------------------------------------");	
			break;			
		//sched_genSchedInfo List 5
		case 'Nonsan' :
			//sched_genSchedInfo List 5	
			printf("--------------------------------------------------------");
			printf("1. Schedule Name : Military (privacy)\n");
			printf("When : AUG. 31\n");
			printf("Where : Nonsan\n");
			printf("--------------------------------------------------------");
			break;			
		//sched_genSchedInfo List 9
		case 'Jeju' :
			//sched_genSchedInfo List 9
			printf("--------------------------------------------------------");	
			printf("1. Schedule Name : WonderfulMama (drama)\n");
			printf("When : MAR. 22\n");
			printf("Where : Jeju\n");			
			printf("--------------------------------------------------------");			
			break;				
		default :
			printf("wrong command! input again\n");
			break;			
	}
}

//convert the name of the type into the enum(integer) value
int sched_convertType(char* typeName)	
{
	char s;
	typeName = s;
	
	switch(s)
	{
		//sched_genSchedInfo List 1,9
		case 'drama':
			return 0;
			break;			
		//sched_genSchedInfo List 3,8
		case 'movie':
			return 1;
			break;		
		//sched_genSchedInfo List 2
		case 'advertisement':
			return 2;
			break;			
		//sched_genSchedInfo List 4,10
		case 'entertainment':
			return 3;
			break;			
		//sched_genSchedInfo List 7
		case 'meeting':
			return 4;
			break;			
		//sched_genSchedInfo List 6
		case 'fitness':
			return 5;
			break;			
		//sched_genSchedInfo List 5
		case 'privacy':
			return 6;
			break;	
		default :
			break;
	}
}

