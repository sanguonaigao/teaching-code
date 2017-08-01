/*************************************************************************
    > File Name: json.h
    > Author: peter
    > Mail: zpengwei@yeah.net 
    > Created Time: 四  9/22 13:46:37 2016
 ************************************************************************/

#ifndef __JSON_H__
#define __JSON_H__

//json的数据类型
typedef enum 
	{ 
		JSON_NULL,
		JSON_FALSE, 
		JSON_TRUE, 
		JOSN_NUMBER, 
		JOSN_STRING, 
		JOSN_ARRAY, 
		JOSN_OBJECT 
	} json_type;


//解析返回值
enum {
	    PARSE_OK = 0,
		PARSE_EXPECT_VALUE,
		PARSE_INVALID_VALUE，
		PARSE_ROOT_NOT_SINGULA
};


//json对象值
typedef struct 
{
	json_type type;
}json_value;

//解析字符串为json对象
int json_parse(json_value *v, const char* json);
json_type get_type(json_value* v);

//
//
//




#endif //__JSON_H__

