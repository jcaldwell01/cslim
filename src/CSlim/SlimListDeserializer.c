#include "SlimList.h"
#include <stdlib.h>
#include <string.h>

#define SKIP(a) \
if (*current != (a))\
{\
	SlimList_destroy(list); \
	return 0;\
}\
current++;

int readLength(char** readPtr)
{
	int length = atoi(*readPtr);
	*readPtr += 6;	
	return length;
}

SlimList* SlimList_deserialize(char* serializedList)
{
	int listLength;
	SlimList * list = 0;
	char* current = 0;
	
	if(serializedList == 0 || strlen(serializedList) == 0)
		return 0;
	
	current = serializedList;
	list = SlimList_create();

	SKIP('[')
	
	listLength = readLength(&current);
	
	SKIP(':')
	
	while (listLength--)
	{
		int elementLength = readLength(&current);
		SKIP(':')
		SlimList_addBuffer(list, current, elementLength);
		current += elementLength;
		SKIP(':')
	}

	SKIP(']')
	return list;
}
