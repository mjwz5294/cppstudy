#include <stdio.h>
#include <float.h>

extern char testExtern;

void printtheSize();
void printDifType();

int main(int argc, char const *argv[])
{
	printf("%s\n",testExtern);
	printf("%s\n","hello" );
	printtheSize();
	printDifType();

	return 0;
}


/*编译运行流程：
1、gcc 1206.c
2、./a.out	得到打印
*/

/*数据类型
1、各种类型的大小与系统有关，可以通过sizeof获取
2、需要注意一些长度可能变化的类型，如字符串、数组、结构。下面打印显示，数组容器就是 元素大小*数量

*/
void printtheSize(){
	printf("%s\n","固定长度类型大小---------------------" );
	printf("char 存储大小 : %lu \n", sizeof(char));
	printf("short 存储大小 : %lu \n", sizeof(short));
	printf("int 存储大小 : %lu \n", sizeof(int));
	printf("long 存储大小 : %lu \n", sizeof(long));
	printf("float 存储大小 : %lu \n", sizeof(float));
	printf("double 存储大小 : %lu \n", sizeof(double));
	printf("long double 存储大小 : %lu \n", sizeof(long double));


	printf("%s\n","具体变量大小---------------------" );
	printf("1 存储大小 : %lu \n", sizeof(1));
	printf("1.1 存储大小 : %lu \n", sizeof(1.1));//默认双精度
	printf("1.1f 存储大小 : %lu \n", sizeof(1.1f));

	printf("%s\n","可变长度变量大小---------------------" );
	printf("字符'a' 存储大小 : %lu \n", sizeof('a'));//4
	printf("字符串'a' 存储大小 : %lu \n", sizeof("a"));//2
	printf("aqqqqqqqq 存储大小 : %lu \n", sizeof("a1234"));//2+4 = 6
	printf("数组char[0] 存储大小 : %lu \n", sizeof(char[0]));
	printf("数组char[1] 存储大小 : %lu \n", sizeof(char[1]));
	printf("数组char[2] 存储大小 : %lu \n", sizeof(char[2]));
	printf("数组char[3] 存储大小 : %lu \n", sizeof(char[3]));
	printf("数组char[4] 存储大小 : %lu \n", sizeof(char[4]));//打印结果让我怀疑字符串就是字符组成的数组
	printf("数组short[4] 存储大小 : %lu \n", sizeof(short[4]));
	printf("数组int[4] 存储大小 : %lu \n", sizeof(int[4]));
	printf("数组long[4] 存储大小 : %lu \n", sizeof(long[4]));


	//这三个宏是定义在float.h中的
	printf("float 最小值: %E\n", FLT_MIN );
	printf("float 最大值: %E\n", FLT_MAX );
    printf("精度值: %d\n", FLT_DIG );


}


/*打印类型：
转换说明及作为结果的打印输出％a 浮点数、十六进制数字和p-记数法（C99）
%A    浮点数、十六进制数字和p-记法（C99）
%c    一个字符 
%d    有符号十进制整数 
%e    浮点数、e-记数法
%E    浮点数、E-记数法
%f    浮点数、十进制记数法  
%g    根据数值不同自动选择％f或％e．
%G    根据数值不同自动选择％f或％e.
%i 有符号十进制数（与％d相同）
%o    无符号八进制整数
%p    指针    
%s    字符串
%u    无符号十进制整数
%x    使用十六进制数字0f的无符号十六进制整数 
%X    使用十六进制数字0f的无符号十六进制整数
*/

/*
1、c语言中只有数据类型，没有类，对于一个特定的变量，你可以当作多种数据类型打印出来，当然结果也是不同的。
	就是说在c语言中，做类型判断是没用的，或者你可以根据变量的长度做点简单的判断。
2、打印类型不对应，可能报错
*/

void printDifType(){
	printf("%s\n","同样的值当作不同类型来使用---------------------" );
	printf("a 当作字符串打印 : %s \n", "a");
	printf("a 当作字符打印 : %c \n", 'a');
	char testa = 'a';
	char * testb = "b";
	/*这里注意字符与字符串区别
	1、引号的区别
	2、字符串的双引号中可以有多个字符，字符的话则只能有一个
	*/
	printf("a 当作十进制打印 : %u \n", 'a');
	printf("a 当作八进制打印 : %o \n", 'a');
	printf("a 当作指针打印 : %p \n", "a");
	// printf("a 当作浮点数打印 : %f \n", 'a');
}



/*变量
1、变量在定义的时候就被其数据类型限定了大小和布局，他们都存储在内存中。当然，字符串、数组等大小可变。
2、变量的声明有两种情况：
（1）需要建立存储空间的，如：int a；在声明的同时也做了定义（建立存储空间）；
（2）不需要建立存储空间的，可通过使用extern关键字声明变量名而不定义它，如：extern int a。此时这里的变量a就未
定义，不能直接使用，例如上面的testExtern变量。
（3）这里补充一下extern与static：https://www.cnblogs.com/dolphin0520/archive/2011/04/20/2022701.html
*/












