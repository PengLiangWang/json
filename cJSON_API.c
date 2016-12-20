/*******************************
Author:  Alex.Wang
Description:  cJSON API 函数封装
*******************************/
//可以将字符串转JSON也分装一下， 这样每次get的时候就不用每次就转换一下了

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
cJSON *StrToJsonObject(char *str)
{
    cJSON *json;

    if(str == NULL)
    {
        return NULL; 
    }
#if 0
    /*GBK 转化为 UTF-8*/
    int inlen = strlen(str);
    iconv_t cd = iconv_open("UTF-8", "GBK");
    char *outbuf=(char *)malloc(inlen*4);
    bzero(outbuf, inlen*4);
    char *in= str;
    char *out=outbuf;

    size_t outlen = inlen*4;
    iconv(cd,&in,(size_t*)&inlen,&out,&outlen);
    outlen=strlen(outbuf);
    ELOG(INFO, "str:%s\n",outbuf);
    free(outbuf);
    iconv_close(cd);
#endif
    json = cJSON_Parse(str);
    if (!json) {return NULL;}
    else
        return json;
}


int GetStrFromJson(cJSON *root, char *key, char *GetStr)
{
    cJSON *cJsonkey;

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

int GetIntFromJson(cJSON *root, char *key, int *iNum)
{
    cJSON *cJsonkey;

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

int GetDoubleFromJson(cJSON *root, char *key, double *DouNum)
{
    cJSON *cJsonkey;

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
    ELOG(INFO, "解析 key: %s", key);
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
