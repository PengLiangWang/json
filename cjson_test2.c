#include    "cJsonHead.h"


int main(int argc, char *argv[])
{
    char JsonStr[1024]="{\"BRANCHID\":\"00800075\",\"PARENTCUS\":\"A000014676\",\"PARENTMOB\":\"13651999517\",\"TYPE\":\"3\",\"CUSTOMERID\":\"A000244877\",\"USERID\":\"13162328493\"}";
    cJSON *json;
    int res;
    char branchId[12]={'\0'};

    json = StrToJsonObject(JsonStr);
    if( json == NULL )
    {
        printf("Str 转换 Json失败. ERR: %d", res);
        return -1;
    }

    res = GetStrFromJson(json, "BRANCHID", branchId);
    if( res )
    {
        printf("获取 key[BRANCHID] 失败, ERR: %d", res);
        return -1;
    }

    printf("branchId: %s\n", branchId);

    return 0;

}

