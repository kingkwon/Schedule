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
	
}


//get type information from the scheduler info structure
//스케줄 정보 구조체에서 "유형" 정보 얻기  
int sched_getType(void* obj)
{
	
}



//get place string information from the scheduler info structure
//스케줄 정보 구조체에서 "장소" 정보 얻기  
char* sched_getPlace(void* obj)
{

}

//convert the name of the type into the enum(integer) value
int sched_convertType(char* typeName)
{
	
}

