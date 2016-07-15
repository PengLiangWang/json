#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static const char *skip(const char *in) 
{
    while (in && *in && (unsigned char)*in <= 32)    //直到不符合条件的字符, 跳出循环返回(只验证 { 以前是否有不可见字符) 
    {
        in++; 
    }
    return in;
}

int main(int argc, char *argv[])
{

    const char *str;

    char *value="  \n {\n\"name\": \"Jack\", \n\"type\":       \"rect\", \n\"width\":      1, \n\"height\":     1080, \n\"interlace\":  true,\"frame     rate\": 24\n}";
    printf("value:%s\n", value);

    str=skip(value);   //跳过 { 之前的不可见字符(空格和\n)
    printf("str:%s\n", str);

    printf("\n**********************************\n");
    const char *ptr=str+1;
    const char *ptr2;
    printf("ptr:%s\n", ptr);
    ptr2=skip(ptr);   //跳过 \" 之前的不可见字符(\n)
    printf("ptr2:%s\n", ptr2);
    if(*ptr2 == '\"')
    {
        printf("*ptr2:%c\n", *ptr2);
    }
    printf("\n**********************************\n");
    const char *ptr3=ptr2+1;
    int len = 0;
    while(*ptr3 != '\"' && *ptr3 && ++len)
    {
        printf("*ptr3:%c\n", *ptr3);
        if(*ptr3++ == '\\')
        {
            ptr3++;
        }
    }
    printf("Len: %d\n", len);
    //跳出循环, ptr3指向name的最后一个字符 c

    printf("\n***********************************\n");
    char *out;
    char *ptr4;
    out = (char *)malloc(len+1);
    if(!out) printf("malloc 失败\n");
    ptr3 = ptr2 + 1;

    ptr4 = out;    //此时 ptr4 和 out 指向相同的内存空间
    printf("*out:%c\n", *out); //此时值为空
    printf("ptr3:%s\n", ptr3);
    while(*ptr3 != '\"' && *ptr3)
    {
         if(*ptr3 != '\\') 
         {
             printf("*ptr3:%c\n", *ptr3);
             *ptr4  ++ = *ptr3++;
             printf("*out:%c\n", *out);  //第一次ptr4赋值之后，相应out也有值了(指向n), 然后后面只对ptr4指针操作, 而out一直指向n
         }
    }
    ptr3++;
    *ptr4 = '\0';
    printf("\nout:%s\nptr3:%s\n", out, ptr3);
    free(out);
    return 0;
}
