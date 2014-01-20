#import <Foundation/Foundation.h>
#import "SlimList.h"

char* NSStringToCString(NSString* string);
NSString* CStringToNSString(char const* cString);

NSString* SlimList_GetNSStringAt(SlimList* self, int index);
NSArray* SlimList_ToNSArray(SlimList* self);



NSString * SerializeNSStringFromNSArray(NSArray* array);
BOOL isBOOLObject(id object);
NSString * stringForBOOLObject(NSNumber * boolNumber);