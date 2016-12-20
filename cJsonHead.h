#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include "ttsys.h"
#include "cJSON.h"


#define FORMAT_ERROR  9600              /*��ȡ��ʽ�ʹ�ŵĸ�ʽ��һ��*/
#define KEY_ERROR     9601              /*��ȡkeyֵʧ��*/
#define ROOT_ERROR    9602              /*��ȡjson rootʧ��*/
#define OBJECT_ERROR  9603              /*��ȡ����ʧ��*/
#define JSON_ERROR    9604              /*json��ʽ����*/


extern cJSON *StrToJsonObject(char *str);

extern int GetStrFromJson(cJSON *root, char *key, char *GetStr);

extern int GetIntFromJson1(char *JsonStr, char *key, int *iNum);

extern int GetStrFromJson1(char *JsonStr, char *key, char *GetStr);

extern int GetBoolFromJson1(char *JsonStr, char *key, int *GetBool);

extern int GetDoubleFromJson1(char *JsonStr, char *key, double *DouNum);

extern int GetIntFromJson2(char *JsonStr, char *ObjectItem, char *key, int *iNum);

extern int GetStrFromJson2(char *JsonStr, char *ObjectItem, char *key, char *GetStr);

extern int GetBoolFromJson2(char *JsonStr, char *ObjectItem, char *key, int *GetBool);

extern int GetDoubleFromJson2(char *JsonStr, char *ObjectItem, char *key, double *DouNum);
