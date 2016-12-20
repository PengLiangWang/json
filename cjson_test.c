#include "cJsonHead.h"
#include <iconv.h>

void GetObjectParse1(char *out)
{
    cJSON *root,*format,*name,*type,*width,*heig,*iner,*fra;   
  //  char *na = NULL,*ty = NULL,*in = NULL;

    //�ַ���ת��ΪJSON�ṹ��
    root = cJSON_Parse(out); 

    if(root)
    {
        name = cJSON_GetObjectItem(root, "name");  //��root�����У���ȡname����  
        if(name)
        {
            printf("name : %s\n", name->valuestring);
        }
        format = cJSON_GetObjectItem(root, "format");   //��root�����У���ȡformat����, ����У�����ִ��
        if(format)
        {
           type  = cJSON_GetObjectItem(format, "type"); 
           if(NULL == type)
           {
               printf("��ȡ type ʧ��");
           }
           printf("type : %s\n", type->valuestring);

           width  = cJSON_GetObjectItem(format, "width");
           printf("width : %d\n", width->valueint);

           heig = cJSON_GetObjectItem(format, "height");
           printf("height : %d\n", heig->valueint);

           //��ȡ��������
           iner = cJSON_GetObjectItem(format, "interlace");
           printf("interlace : %d\n", iner->valueint);             //false: 0   true: 1 

           
           fra = cJSON_GetObjectItem(format, "frame rate");
           printf("frame rate : %d\n", fra->valueint);

        }
    }
}

void GetObjectParse2(char *out)
{
    cJSON *root,*arrayItem,*item,*name,*path,*flag; 
    int i = 0, size = 0;
    char *pr=NULL;

    //���ַ���������json�ṹ��
    root = cJSON_Parse(out);
  
    //���ݽṹ���ȡ�����С
    size = cJSON_GetArraySize(root);

    for(i=0; i<size; i++)
    {
        //��ȡ��һ��������
        arrayItem = cJSON_GetArrayItem(root, i);

        if(arrayItem)
        {
            pr = cJSON_Print(arrayItem);
            printf("\narrayItem[%d] = %s\n\n",i+1 , pr);    //��ӡ�����е�ÿһ��Ԫ��
            item = cJSON_Parse(pr);

            name = cJSON_GetObjectItem(arrayItem, "name");  //ֱ����arrayItem�����Ҳ����
            printf("name : %s\n", name->valuestring);

            path = cJSON_GetObjectItem(item, "path");
            printf("path : %s\n", path->valuestring);

            flag = cJSON_GetObjectItem(item, "flag");
            printf("flag : %s\n", flag->valuestring);
        
        }
    
    }
    
}

void GetObjectParse3(char *out)
{
    cJSON *root, *Root, *name, *path, *flag, *Child, *arrayItem;      
    int i = 0, size = 0;

    root = cJSON_Parse(out);

    if(root)
    {
        Root = cJSON_GetObjectItem(root, "Root");

        if(Root)
        {
            name = cJSON_GetObjectItem(Root, "name");
            printf("name : %s\n", name->valuestring);

            path = cJSON_GetObjectItem(Root, "path");
            printf("path : %s\n", path->valuestring);

            flag = cJSON_GetObjectItem(Root, "flag");
            printf("flag : %s\n", flag->valuestring);
        
        }

        Child = cJSON_GetObjectItem(root, "Child");
        if(Child)
        {
            size = cJSON_GetArraySize(Child);

            printf("Child : \n");
            
            for(i=0; i<size; i++)
            {
                arrayItem = cJSON_GetArrayItem(Child, i);

                if(arrayItem)
                {
                    printf("type = %d\n", arrayItem->type);        //����
                    name = cJSON_GetObjectItem(arrayItem, "name");
                    printf("name : %s\n", name->valuestring);
                
                    
                    path = cJSON_GetObjectItem(arrayItem, "path");
                    printf("path : %s\n", path->valuestring);

                    flag = cJSON_GetObjectItem(arrayItem, "flag");
                    printf("flag : %s\n", flag->valuestring);
                
                }
            
            
            }
        
        }
    
    }

}

void GetObjectParse4(char *out)
{
    cJSON *root, *Root, *key, *value, *title, *url, *Child, *arrayItem, *nums;
    int i=0, size=0;

    root = cJSON_Parse(out);

    if(root)
    {
        Root = cJSON_GetObjectItem(root, "Root");
        if(Root)
        {
            key = cJSON_GetObjectItem(Root, "key");
            printf("key : %d\n", key->valueint);
        
            value = cJSON_GetObjectItem(Root, "value");
            printf("value : %d\n", value->valueint);

            title = cJSON_GetObjectItem(Root, "title");
            printf("title : %s\n", title->valuestring);
        }

        Child = cJSON_GetObjectItem(Root, "Child");
        if(Child)
        {
            key = cJSON_GetObjectItem(Child, "key");
            printf("key : %d\n", key->valueint);
        
            value = cJSON_GetObjectItem(Child, "value");
            printf("value : %s\n", value->valuestring);
        
            url = cJSON_GetObjectItem(Child, "Url");
            printf("title : %s\n", url->valuestring);
        
        }
       
        nums = cJSON_GetObjectItem(Root, "nums");
        if(nums)
        {
            size = cJSON_GetArraySize(nums);
            printf("size = %d\n", size);

            for(i=0; i<size; i++)
            {
               arrayItem = cJSON_GetArrayItem(nums, i);   //����json������ָ��λ�ö���
               if(arrayItem)
               {
                  printf("num[%d] = %d\n", i, arrayItem->valueint );    //��Ϊ�����в��ٰ����������󣬿�ֱ�ӻ�ȡ��ֵ 
                  printf("type = %d\n", arrayItem->type);   //����
               
               }

            }
        
        }
    
    }

}

void GetObjectParse5(char *out)
{
    cJSON *root, *arrayItem, *Root, *Root1;
    int i = 0, size = 0;

    root = cJSON_Parse(out);

    if(root)
    {
        Root = cJSON_GetObjectItem(root, "Root");
        if(Root)
        {
            size = cJSON_GetArraySize(Root);
            for(i=0; i<size; i++)
            {
                arrayItem = cJSON_GetArrayItem(Root, i);
                if(arrayItem)
                {
                    if(i == 2)
                    printf("Root[%d] = %s\n", i, arrayItem->valuestring);
                    else
                    printf("Root[%d] = %d\n", i, arrayItem->valueint);

                }

            }

        }
        Root1 = cJSON_GetObjectItem(root, "Root1");
        if(Root1)
        {
            size = cJSON_GetArraySize(Root1);
            for(i=0; i<size; i++)
            {
                arrayItem = cJSON_GetArrayItem(Root1, i);
                if(arrayItem)
                {
                    if(i >= 1)
                    printf("Root1[%d] = %s\n", i, arrayItem->valuestring);
                    else
                    printf("Root1[%d] = %d\n", i, arrayItem->valueint);

                }

            }
        
        }
    
    }

}


void Getout(char *text)
{
	char *out;cJSON *json;
	
	json=cJSON_Parse(text);
	if (!json) {printf("Error before: [%s]\n",cJSON_GetErrorPtr());}
	else
	{
		out=cJSON_Print(json);
		cJSON_Delete(json);
		printf("%s\n",out);
		free(out);
	}
}

void dofile(char *filename)
{
	FILE *f;long len;char *data;
	
	f=fopen(filename,"rb");
    fseek(f,0,SEEK_END);
    len=ftell(f);fseek(f,0,SEEK_SET);
	data=(char*)malloc(len+1);fread(data,1,len,f);fclose(f);
	Getout(data);
	free(data);
}

void create_object1()
{
	cJSON *root,*fmt;
    char *out;

	root=cJSON_CreateObject();   //�ȴ�����һ��json����	
	cJSON_AddItemToObject(root, "name", cJSON_CreateString("Jack"));    //�ڶ������洴��һ��json�ַ���
	cJSON_AddItemToObject(root, "format", fmt=cJSON_CreateObject());   //�ڶ���root�У������һ������fmt
	cJSON_AddStringToObject(fmt,"type",		"rect");   //����fmt�е�Ԫ��������ʾ
	cJSON_AddNumberToObject(fmt,"width",		1920);
	cJSON_AddNumberToObject(fmt,"height",		1080);
	cJSON_AddFalseToObject(fmt,"interlace");
	cJSON_AddTrueToObject(fmt,"interlace2");
	cJSON_AddNumberToObject(fmt,"frame rate",	24);
	
	out=cJSON_Print(root);	
    cJSON_Delete(root);	
    printf("%s\n",out);	
    free(out);

}

void create_object2()
{
     cJSON *root,*dir1,*dir2,*dir3;
     char *out;

     //����json�����ͽṹ��
     root = cJSON_CreateArray();
     
     //Ϊ������Ӷ���
     cJSON_AddItemToArray(root, dir1=cJSON_CreateObject());
     
     //Ϊ��������ַ�����ֵ��

     cJSON_AddStringToObject(dir1,"name",".");
     cJSON_AddStringToObject(dir1,"path","uploads/");
     cJSON_AddStringToObject(dir1,"flag","true");
     cJSON_AddItemToArray(root,dir2=cJSON_CreateObject());
     cJSON_AddStringToObject(dir2,"name","..");
     cJSON_AddStringToObject(dir2,"path","uploads");
     cJSON_AddStringToObject(dir2,"flag","true");
     cJSON_AddItemToArray(root,dir3=cJSON_CreateObject());
     cJSON_AddStringToObject(dir3,"name","wang.txt");
     cJSON_AddStringToObject(dir3,"path","uploads/wang.txt");
     cJSON_AddStringToObject(dir3,"flag","false");


     //��json�ṹ��ת��Ϊ�ַ���
     out = cJSON_Print(root);
     printf("\n\n %s\n", out);
     GetObjectParse2(out);
     cJSON_Delete(root);	
     free(out);

}

void create_object3()
{
     cJSON *root,*dir,*subdir,*dir1,*dir2,*dir3;
     char *out;

     //����cjson����
     root=cJSON_CreateObject();

     cJSON_AddItemToObject(root, "Root", dir=cJSON_CreateObject());
     cJSON_AddStringToObject(dir, "name", "/");
     cJSON_AddStringToObject(dir, "path", "/");
     cJSON_AddStringToObject(dir, "flag", "true");


     cJSON_AddItemToObject(root, "Child", subdir=cJSON_CreateArray());
     cJSON_AddItemToObject(subdir, "dira", dir1=cJSON_CreateObject());
     cJSON_AddStringToObject(dir1, "name", "/");
     cJSON_AddStringToObject(dir1,"path","/./");
     cJSON_AddStringToObject(dir1,"flag","true");
     cJSON_AddItemToObject(subdir,"dira",dir2=cJSON_CreateObject());
     cJSON_AddStringToObject(dir2,"name","..");
     cJSON_AddStringToObject(dir2,"path","/../");
     cJSON_AddStringToObject(dir2,"flag","true");
     cJSON_AddItemToObject(subdir,"dira",dir3=cJSON_CreateObject());
     cJSON_AddStringToObject(dir3,"name","uploads");
     cJSON_AddStringToObject(dir3,"path","/uploads/");
     cJSON_AddStringToObject(dir3,"flag","true");

     //��json�ṹ��ת��Ϊ�ַ���
     out = cJSON_Print(root);
     printf("\n\n %s\n", out);
     GetObjectParse3(out);
     cJSON_Delete(root);	
     free(out);
     
}

void create_object4()
{
    cJSON *root,*img,*thm;
    char *out;
    int nums[4]={100,200,300,400};
    root=cJSON_CreateObject();
    cJSON_AddItemToObject(root, "Root", img=cJSON_CreateObject());
    cJSON_AddNumberToObject(img,"key",800);
    cJSON_AddNumberToObject(img,"value",600);
    cJSON_AddStringToObject(img,"Title","Sugon");
    cJSON_AddItemToObject(img,"child",thm=cJSON_CreateObject());
    cJSON_AddNumberToObject(thm,"key",125);
    cJSON_AddStringToObject(thm,"value","100");
    cJSON_AddStringToObject(thm,"Url","www.sugon.com");

    cJSON_AddItemToObject(img,"nums", cJSON_CreateIntArray(nums,4)); //������������json����

     //��json�ṹ��ת��Ϊ�ַ���
     out = cJSON_Print(root);
     printf("\n\n %s\n", out);
     GetObjectParse4(out);
     cJSON_Delete(root);	
     free(out);
}

void create_object5()
{
    cJSON *root,*dir1,*dir2;
    char *out;
    const char *ro = "Root";
    root=cJSON_CreateObject();
    cJSON_AddItemToObject(root,ro,dir1=cJSON_CreateArray());
    cJSON_AddNumberToObject(dir1,"key",800);
    cJSON_AddNumberToObject(dir1,"value",600);
    cJSON_AddStringToObject(dir1,"Title","key and value");
    cJSON_AddItemToObject(root,"Root1",dir2=cJSON_CreateArray());
    cJSON_AddNumberToObject(dir2,"value",125);
    cJSON_AddStringToObject(dir2,"key","100");
    cJSON_AddStringToObject(dir2,"Title","value and key");


     //��json�ṹ��ת��Ϊ�ַ���
     out = cJSON_Print(root);
     printf("\n\n %s\n", out);
     GetObjectParse5(out);
     cJSON_Delete(root);	
     free(out);
}

int main (int argc, const char * argv[]) {

	char text1[]="{\n\"name\": \"����\",\n\"type\":       \"rect\", \n\"width\":      1, \n\"height\":     1080, \n\"interlace\":  true,\"frame rate\": 24\n}";	
	char text2[]="{\n\"format\": {\"type\":       \"rect\", \n\"width\":      1920, \n\"height\":     1080, \n\"interlace\":  true,\"frame rate\": 24\n}\n}";	
//	char text3[]="{\n\"name\": \"Jack\", \n\"format\": {\"type\":       \"rect\", \n\"width\":      1920, \n\"height\":     1080, \n\"interlace\":  true,\"frame rate\": 24\n}\n}";	

    char text4[]="{\"MSG_CODE\":\"0000\",\"MSG_TEXT\":\"�����ɹ�\",\"RESULTPARAM\":{\"Result\":\"1\",\"PayManagerFee\":0,\"ActualManagerFee\":0,\"ActualPounDateFee\":200,\"ActualPayFee\":0,\"PayFee\":500000,\"SettleFlag\":\"2\",\"PayPounDateFee\":1875}}";

    char text5[]="{\"BRANCHID\":\"00800075\",\"PARENTCUS\":\"A000014676\",\"PARENTMOB\":\"13651999517\",\"TYPE\":\"3\",\"CUSTOMERID\":\"A000244877\",\"USERID\":\"13162328493\"}";
    int res = 0;

    /*�ַ���GBKת��ΪUTF-8*/
    /*
    int inlen = strlen(text1);
    iconv_t cd = iconv_open("UTF-8", "GBK");
     
    char *outbuf=(char *)malloc(inlen*4);
    bzero(outbuf, inlen*4);
    char *in= text1;
    char *out=outbuf;

    size_t outlen = inlen*4;
    iconv(cd,&in,(size_t*)&inlen,&out,&outlen);
    outlen=strlen(outbuf);
    printf("%s\n",outbuf);
    free(outbuf);
    iconv_close(cd);


    ELOG(INFO,"\n************* һ��json���� ***********\n");
//	Getout(text1);
    char name[100] = {0};
    char *namekey = "name";
    int res = 0;
   
    printf("text1: %s\n", text1);
    res = GetStrFromJson1(outbuf, namekey, name);
    if(res)
    {
       ELOG(ERROR, "��ȡkey %s ʧ��. ERR: %d\n", namekey, res);    //��ӡ��־��log��
       return -1;
    }
    ELOG(INFO, "%s: %s\n",namekey,  name);
*/
    char typevalue[3] = {0};
    res = GetStrFromJson1(text5, "TYPE", typevalue);
    if(res)
    {
       ELOG(ERROR, "��ȡkey %s ʧ��. ERR: %d\n", "TYPE", res);    //��ӡ��־��log��
       return -1;
    }
    ELOG(INFO, "%s: %s\n", "TYPE" ,typevalue);


#if 0
    int cwidth = 0;
    char *cwidthkey = "width";

    res = GetIntFromJson1(text1, cwidthkey, &cwidth);
    if(res)
    {
        ELOG(ERROR,"��ȡkey %s ʧ��.<%d>", cwidthkey, res);
        return -1;
    }
    ELOG(INFO,"width = %d\n\n\n", cwidth);



    ELOG(INFO,"\n************* ����json���� ***********\n");
    int width = 0;
    char *ObjectItem = "format";
    char *widthkey = "width";
    
    char type[20] = {0};
    char *typekey= "type";
    
    int   inter;
    char  *interkey = "interlace";

    
    res = GetIntFromJson2(text4,"RESULTPARAM", "PayManagerFee", &width);
    if(res)
    {
        ELOG(ERROR,"��ȡkey %s ʧ��.", "PayManagerFee");
    }
    ELOG(INFO, "PayManagerFee: %d\n\n", width);
    
//	Getout(text2);
    res = GetIntFromJson2(text2, ObjectItem, widthkey, &width);  //��ȡint����double����,����bool����(0,1)
    if(res)
    {
        ELOG(ERROR,"��ȡkey %s ʧ��.", widthkey);
    }
    ELOG(INFO,"width = %d\n\n\n", width);


    res = GetStrFromJson2(text2, ObjectItem, typekey, type);  //��ȡ�ַ���
    if(res)
    {
        ELOG(ERROR,"��ȡkey %s ʧ��.", typekey);
    }
    ELOG(INFO,"type : %s\n\n\n", type);


    res = GetBoolFromJson2(text2, ObjectItem, interkey, &inter);  //��ȡbool����(0,1)
    if(res)
    {
        ELOG(ERROR,"��ȡkey %s ʧ��.", interkey);
    }
    ELOG(INFO,"interlace :  %d\n\n\n", inter);
#endif

#if 0
    printf("\n*************cjson 1***********\n");
	Getout(text3);
	create_object1();

    printf("\n*************cjson 2***********\n");
    create_object2();

    printf("\n*************cjson 3***********\n");
    create_object3();
  
    printf("\n*************cjson 4***********\n");
    create_object4();
     
    printf("\n*************cjson 5***********\n");
    create_object5();
     
	dofile("./tests/test5");
#endif	
	return 0;
}
