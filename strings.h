
/**
 * @file strings.h
 * @brief �����ַ�������
 * @author tomszhou
 * @version 1.1
 * @date 2008-3-9
 * @date 2011-6-15
 */


#ifndef _TTSYS_STRINGS_H_
#define _TTSYS_STRINGS_H_

#include "ttdef.h"
#include "memory.h"

__BEGIN_DECLS


/**
 * @defgroup TTSYS_STRING �����ַ�������
 * @ingroup TTSYS
 * @{
 */


/** �ж��ַ������Ƿ���'\\r' '\\n' '#' ' ' '\\t' ���ַ�
 *  @param line  �ַ���
 *  @return ����0��ʾ����������ֵ���������ַ���
 */

int isspaceline(char *line);


/** �����ַ�����
 *  @param pool ������ڴ�ء�
 *  @param s Դ�ַ���
 *  @return �ɹ������ַ����ĵ�ַ�� ʧ�ܷ��ؿ� ��
 */
char * m_strdup(TMemPool *pool, const char *s);

/** ���ݳ��ȿ����ַ�����
 *  @param pool ������ڴ�ء�
 *  @param s Դ�ַ���
 *  @param n ��������
 *  @return �ɹ������ַ����ĵ�ַ�� ʧ�ܷ��ؿ� ��
 */
char * m_strndup(TMemPool *pool, const char *s, int n);

/** ƴ���ַ�����
 *  @param pool ������ڴ�ء�
 *  @return �ɹ������ַ����ĵ�ַ�� ʧ�ܷ��ؿ� ��
 */
char * m_strcat( TMemPool *pool,...);


/** ����������ת�����ַ�����
 *  @param pool ������ڴ�ء�
 *  @param n ��������
 *  @return �ɹ������ַ����ĵ�ַ�� ʧ�ܷ��ؿ� ��
 */
char * m_itoa(TMemPool *pool, int n);

/** ������������ת�����ַ�����
 *  @param pool ������ڴ�ء�
 *  @param n ��������
 *  @return �ɹ������ַ����ĵ�ַ�� ʧ�ܷ��ؿ� ��
 */
char * m_ltoa(TMemPool *pool, long n);


/** ��ʽ�������ַ���
 *  @param pool �ڴ��
 *  @param format �ַ�����ʽ
 *  @return �ɹ������ַ����ĵ�ַ��ʧ�ܷ��ؿ�
 */
char * m_sprintf(TMemPool *pool, const char *format, ...);

/** ����Ŀ���С�����ַ���
 *  @param dst Ŀ���ַ���
 *  @param src Դ�ַ���
 *  @param dst_size Ŀ���ַ�����С
 *  @return �ɹ������ַ����ĵ�ַ�� ʧ�ܷ��ؿ� ��
 */
char * m_cpystrn(char *dst, const char *src, uint32 dst_size);

/** �Ƚ��ַ���
 *  @param a �ַ���a
 *  @param b �ַ���b
 *  @return ���ַ�����ͬʱ����0�����򷵻ط�0ֵ
 */
int m_strcmp(char *a,char *b);

/** �����ض����ַ����ָ��ַ���
 *  @param str Դ�ַ���
 *  @param sep �ָ��ַ���
 *  @param last ��ŷָ����ַ�
 *  @return ���طָ����ַ�
 */
char *m_strtok(char *str, const char *sep, char **last);


/** ȥ���������ߵĿո������ַ�('\\r','\\n',' ','\\t')
 *  @param src Ŀ���ַ���
 *  @return ���ش������ַ���
 */
char * m_trim(char* src);

/** ���ַ���ת����16�����ַ���
 *  @param a  �������ڴ��
 *  @param bin �ַ���
 *  @param len �ַ�������
 *  @return ����16�����ַ���
 */

char *Bin2Str( TMemPool * a , const char *bin , int len );

/** ��16�����ַ���ת�����ַ���
 *  @param a  �������ڴ��
 *  @param str 16�����ַ���
 *  @param len �ַ�������
 *  @return �����ַ���
 */
char *Str2Bin( TMemPool * a , const char *str , int len );

/** ������������ת����16�����ַ���
 *  @param bin ����������
 *  @param str 16��������
 *  @param len ���������ݳ���
 */
void binToStr(const char *bin,char *str,int len);

/** ��16����������ת���ɶ����ƴ�
 *  @param str 16��������
 *  @param bin ����������
 *  @param len ���������ݳ���
 */
void strToBin( const char *str , char *bin,int len );

/** ��16����������ת����ASC��
 *  @param Hex 16��������
 *  @param Asc ASC����
 *  @param AscLen 16�������ݳ���/2
 */
int HexToAsc(char *Hex, char *Asc, int AscLen);

/** ��ASC����ת����16����������
 *  @param Asc ASC����
 *  @param Hex 16��������
 *  @param AscLen ASC���ݳ���
 */
int AscToHex(char *Asc, char *Hex, int AscLen);

/** ��BCDת����ASC
 *  @param Bcd BCD����
 *  @param Asc Asc����
 *  @param BcdLen BCD���ݳ���
 */
int BcdToAscL(char *Bcd, char *Asc, int BcdLen);

/** ��BCDת����ASC
 *  @param Bcd BCD����
 *  @param Asc Asc����
 *  @param BcdLen BCD���ݳ���
 */
int BcdToAscR(char *Bcd, char *Asc, int BcdLen);

/** ASCת������BCD
 *  @param Asc Asc����
 *  @param Bcd BCD����
 *  @param AscLen Asc���ݳ���
 */
int AscToBcdL(char *Asc, char *Bcd, int AscLen);

/** ASCת������BCD
 *  @param Asc Asc����
 *  @param Bcd BCD����
 *  @param AscLen Asc���ݳ���
 */
int AscToBcdR(char *Asc, char *Bcd, int AscLen);

/** ASCת���ɸ��ָ�ʽ����
 *  @param Asc Asc����
 *  @param Nnn ��ʽ��������
 *  @param AscLen Asc���ݳ���
 *  @param Type ��������(A,L,R,H)
 */
int AscToNnn(char *Asc,char **Nnn,int AscLen,char Type);

/** ���ָ�ʽ����ת����ASC
 *  @param Nnn ��ʽ��������
 *  @param Asc Asc����
 *  @param AscLen Asc���ݳ���
 *  @param Type ��������(A,L,R,H)
 */
int NnnToAsc(char **Nnn,char *Asc,int AscLen,char Type);

/** @} */

__END_DECLS

#endif

