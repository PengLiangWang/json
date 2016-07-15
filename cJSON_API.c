/*******************************
Author:  Alex.Wang
Description:  cJSON API 函数封装
*******************************/

#include "cJsonHead.h"

//读JSON文件，获取JSON结构体 
cJSON *FileToJsonObject(char *filename, cJSON *json)
{
    long len;
    char* pContent;
    int tmp;
    FILE* fp = fopen(filename, "rb+");
    if(!fp)
    {
        return NULL;
    }
    fseek(fp,0,SEEK_END);
    len=ftell(fp);
    if(0 == len)
    {
        return NULL;
    }

    fseek(fp,0,SEEK_SET);
    pContent = (char*) malloc (sizeof(char)*len);
    tmp = fread(pContent,1,len,fp);

    fclose(fp);
    json=cJSON_Parse(pContent);
    if (!json)
    {
        return NULL;
    }
    free(pContent);
    return json;
}

//JSON字符串转换为JSON结构体
static cJSON *StrToJsonObject(char *str)
{
    cJSON *json;

    if(str == NULL)
    {
        return NULL; 
    }
    json = cJSON_Parse(str);
    if (!json) {return NULL;}
    else
        return json;
}

/* 一层对象的json解析 */
int GetIntFromJson1(char *JsonStr, char *key, int *iNum)
{
    cJSON *root, *cJsonkey;

    root = StrToJsonObject(JsonStr);
    if(root == NULL)
        return JSON_ERROR;

    if(root)
    {
        cJsonkey = cJSON_GetObjectItem(root, key);
        if(NULL == cJsonkey)
        {
            cJSON_Delete(root);
            return KEY_ERROR;
        }
        if(cJsonkey->type == cJSON_Number)
            *iNum = cJsonkey->valueint;
        else{
            cJSON_Delete(root);
            return FORMAT_ERROR;
            }
    }
    else
    {
        return ROOT_ERROR;
    }

    cJSON_Delete(root);
    return 0;
}

int GetDoubleFromJson1(char *JsonStr, char *key, double *DouNum)
{
    cJSON *root, *cJsonkey;

    root = StrToJsonObject(JsonStr);
    if(root == NULL)
        return JSON_ERROR;

    if(root)
    {
        cJsonkey = cJSON_GetObjectItem(root, key);
        if(NULL == cJsonkey)
        {
            cJSON_Delete(root);
            return KEY_ERROR;
        }
        if(cJsonkey->type == cJSON_Number)
            *DouNum = cJsonkey->valuedouble;
        else{
            cJSON_Delete(root);
            return FORMAT_ERROR;
            }
    }
    else
    {
        return ROOT_ERROR;
    }

    cJSON_Delete(root);
    return 0;
}


int GetStrFromJson1(char *JsonStr, char *key, char *GetStr)
{
    cJSON *root, *cJsonkey;
    root = StrToJsonObject(JsonStr);
    if(root == NULL)
        return JSON_ERROR;

    if(root)
    {
        cJsonkey = cJSON_GetObjectItem(root, key);
        if(NULL == cJsonkey)
        {
            cJSON_Delete(root);
            return KEY_ERROR;
        }
        if(cJsonkey->type == cJSON_String)
        {
            strcpy(GetStr, cJsonkey->valuestring);
        }
        else{
            cJSON_Delete(root);
            return FORMAT_ERROR;
            }
    }
    else
    {
        return ROOT_ERROR;
    }
    cJSON_Delete(root);
    return 0;
}

int GetArrayStrFromJson1(char *JsonStr, char *key, char *array, int iNum)
{

    cJSON *root, *cJsonkey, *arrayItem;
    int i=0, size=0;
    root = StrToJsonObject(JsonStr);
    if(root == NULL)
        return JSON_ERROR;

    if(root)
    {
        cJsonkey = cJSON_GetObjectItem(root, key);
        if(NULL == cJsonkey)
        {
            cJSON_Delete(root);
            return KEY_ERROR;
        }
        if(cJsonkey)
        {
            size = cJSON_GetArraySize(cJsonkey);
            if(iNum < 0 || iNum > size)   
                return  ARRAY_ERROR;
            arrayItem = cJSON_GetArrayItem(cJsonkey, iNum);
            if(arrayItem)
            {
                strcpy(array,arrayItem->valuestring);
            }
        
        }

    }
    cJSON_Delete(root);
    return 0;
}

int GetArrayIntFromJson1(char *JsonStr, char *key, int *item, int iNum)
{

    cJSON *root, *cJsonkey, *arrayItem;
    int i=0, size=0;
    root = StrToJsonObject(JsonStr);
    if(root == NULL)
        return JSON_ERROR;

    if(root)
    {
        cJsonkey = cJSON_GetObjectItem(root, key);
        if(NULL == cJsonkey)
        {
            cJSON_Delete(root);
            return KEY_ERROR;
        }
        if(cJsonkey)
        {
            size = cJSON_GetArraySize(cJsonkey);
            if(iNum < 0 || iNum > size)   
                return  ARRAY_ERROR;
            arrayItem = cJSON_GetArrayItem(cJsonkey, iNum);
            if(arrayItem)
            {
                *item = arrayItem->valueint;
            }
        
        }

    }
    cJSON_Delete(root);
    return 0;
}

int GetBoolFromJson1(char *JsonStr, char *key, int *GetBool)
{
    cJSON *root, *cJsonkey;

    root = StrToJsonObject(JsonStr);
    if(root == NULL)
        return JSON_ERROR;

    if(root)
    {
        cJsonkey = cJSON_GetObjectItem(root, key);
        if(NULL == cJsonkey)
        {
            cJSON_Delete(root);
            return KEY_ERROR;
        }
        if(cJsonkey->type == cJSON_False || cJsonkey->type == cJSON_True)
            *GetBool = cJsonkey->valueint;
        else{
            cJSON_Delete(root);
            return FORMAT_ERROR;
            }
    }
    else
    {
        return ROOT_ERROR;
    }

    cJSON_Delete(root);
    return 0;

}

/*两层对象的json解析*/
int GetIntFromJson2(char *JsonStr, char *ObjectItem, char *key, int *iNum)
{
    cJSON *root, *cJsonItem, *cJsonkey;

    root = StrToJsonObject(JsonStr);
    if(root == NULL)
        return JSON_ERROR;

    if(root)
    {
        cJsonItem = cJSON_GetObjectItem(root, ObjectItem);
        if(cJsonItem)
        {
            cJsonkey = cJSON_GetObjectItem(cJsonItem, key);
            if(NULL == cJsonkey)
            {
                cJSON_Delete(root);
                return KEY_ERROR;
            }
            if(cJsonkey->type == cJSON_Number)
                *iNum = cJsonkey->valueint;
            else{
                cJSON_Delete(root);
                return FORMAT_ERROR;
            }
        }
        else
        {
           cJSON_Delete(root);
           return OBJECT_ERROR;
        }

    }
    else
    {
        return ROOT_ERROR;
    }

    cJSON_Delete(root);
    return 0;
}

int GetDoubleFromJson2(char *JsonStr, char *ObjectItem, char *key, double *DouNum)
{
    cJSON *root, *cJsonItem, *cJsonkey;

    root = StrToJsonObject(JsonStr);
    if(root == NULL)
        return JSON_ERROR;

    if(root)
    {
        cJsonItem = cJSON_GetObjectItem(root, ObjectItem);
        if(cJsonItem)
        {
            cJsonkey = cJSON_GetObjectItem(cJsonItem, key);
            if(NULL == cJsonkey)
            {
                cJSON_Delete(root);
                return KEY_ERROR;
            }
            if(cJsonkey->type == cJSON_Number)
                *DouNum = cJsonkey->valuedouble;
            else{
                cJSON_Delete(root);
                return FORMAT_ERROR;
            }
        }
        else
        {
           cJSON_Delete(root);
           return OBJECT_ERROR;
        }
    }
    else
    {
        return ROOT_ERROR;
    }

    cJSON_Delete(root);
    return 0;
}

int GetStrFromJson2(char *JsonStr, char *ObjectItem, char *key, char *GetStr)
{
    cJSON *root, *cJsonItem, *cJsonkey;

    root = StrToJsonObject(JsonStr);
    if(root == NULL)
        return JSON_ERROR;

    if(root)
    {
        cJsonItem = cJSON_GetObjectItem(root, ObjectItem);
        if(cJsonItem)
        {
            cJsonkey = cJSON_GetObjectItem(cJsonItem, key);
            if(NULL == cJsonkey)
            {
                cJSON_Delete(root);
                return KEY_ERROR;
            }
            if(cJsonkey->type == cJSON_String)
                strcpy(GetStr, cJsonkey->valuestring);
            else{
                cJSON_Delete(root);
                return FORMAT_ERROR;
            }
        }
        else
        {
           cJSON_Delete(root);
           return OBJECT_ERROR;
        }

    }
    else
    {
        return ROOT_ERROR;
    }

    cJSON_Delete(root);
    return 0;
}


int GetBoolFromJson2(char *JsonStr, char *ObjectItem, char *key, int *GetBool)
{
    cJSON *root, *cJsonItem, *cJsonkey;

    root = StrToJsonObject(JsonStr);
    if(root == NULL)
        return JSON_ERROR;

    if(root)
    {
        cJsonItem = cJSON_GetObjectItem(root, ObjectItem);
        if(cJsonItem)
        {
            cJsonkey = cJSON_GetObjectItem(cJsonItem, key);
            if(NULL == cJsonkey)
            {
                cJSON_Delete(root);
                return KEY_ERROR;
            }
            if(cJsonkey->type == cJSON_False || cJsonkey->type == cJSON_True)
                *GetBool = cJsonkey->valueint;
            else{
                cJSON_Delete(root);
                return FORMAT_ERROR;
            }
        }
        else
        {
           cJSON_Delete(root);
           return OBJECT_ERROR;
        }

    }
    else
    {
        return ROOT_ERROR;
    }
    cJSON_Delete(root);
    return 0;
}
