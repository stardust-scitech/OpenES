#include "user_http.h"

/**
  * @brief Http封包函数，对指定位置替换字符串
  * @param target 需要插入字符串的页面
  * @param flag 需要插入字符串索引
  * @param insert 需要插入的字符串指针
  * @return void
  */
void ICACHE_FLASH_ATTR
HttpPack(uint8 *target ,  uint8 *flag , uint8 *insert)
{
	u8 *TargetPre;
	int i;
	u8 FlagSize = strlen(flag);
	u8 InsertSize = strlen(insert);

	TargetPre = strstr(target, flag);

	for(i=0;i<InsertSize;i++)
	{
		TargetPre[FlagSize+i] = insert[i];
	}
}

/**
  * @brief Http数据解包函数
  * @param target 需要解包字符串的页面
  * @param flag_start 需要插入字符首串索引
  * @param flag_end 需要插入字符尾串索引
  * @param value 解析获得的值
  * @return void
  */
void ICACHE_FLASH_ATTR
HttpGet(u8 *target ,  u8 *flag_start , u8 *flag_end, u8 *value)
{
	u8 *target_pre, *target_current;
	u8 len, i;

	target_pre = strstr(target, flag_start);
	if(target_pre!=NULL)
	{
		target_pre += strlen(flag_start);
		target_current = strstr(target_pre, flag_end);
		len = target_current-target_pre;
		for(i=0;i<len;i++)
		{
			value[i]=target_pre[i];
		}
	}
}

/**
  * @brief 首次登录检测函数
  * @param pdata Http数据指针
  * @return 0/1 初次登录/非初次登录
  */
u8 ICACHE_FLASH_ATTR
Login_Check(char *pdata)
{
	char * name = NULL;
	char * pass = NULL;
	u8 username[36]={0};
	u8 password[36]={0};
	u8 SEC=126;
	u8 SEC_OFFSET = 0;

	HttpGet(pdata, "username=", "&", username);
	HttpGet(pdata, "password=", "&", password);

	if(username!=NULL && password!=NULL)
	{
		spi_flash_erase_sector(SEC);
		spi_flash_write(SEC*4*1024+SEC_OFFSET, (uint32 *)username, 36);
		SEC_OFFSET = 36;
		spi_flash_write(SEC*4*1024+SEC_OFFSET, (uint32 *)password, 36);
		return 0;
	}else
	{
		return 1;
	}
}
