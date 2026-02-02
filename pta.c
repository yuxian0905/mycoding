//迭代

//最大公约数和最小公倍数
/*#include <stdio.h>
int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	int original_m = m;
	int original_n = n;
	while (n != 0) {
		int temp = n;//gcd算法求最大公约数 gcd(m,n)=gcd(n,m%n)
		n = m % n;
		m = temp;
	}
	int greatestCommonDivisor = m;
	int leastCommonMultiple = (original_m / greatestCommonDivisor) * original_n;
	printf("%d %d\n", greatestCommonDivisor, leastCommonMultiple);
	return 0;
}*/
//递归
int GCD(int a , int b ){
	if(a%b==0){
		return b;
	}else{
		return GCD(b,a%b);
	}

	return 0;
}

//圆的切分：在一个平面上有一个圆和n条直线，这些直线中每一条在圆内同其他直线相交，假设没有3条直线相交于一点，试问这些直线将圆分成多少区域。
/*
 #include <stdio.h>
int main (){
	int n;
	scanf("%d",&n);
	int fen;
	fen=(n*n+n+2)/2;
	printf("%d",fen);
	return 0;
}
*/

//进制转换(2转10）
/*#include <stdio.h>
int main() {
	int n, decimal = 0, base = 1,tail;
	scanf("%d", &n);
	while (n > 0) {
		tail = n % 10;
		decimal = decimal + tail * base;
		n /=10;
		base = base * 2;
	}

	printf("%d\n", decimal);

	return 0;
}*/
//2转10
long long decimalToBinaryNum(int decimal) {
	if (decimal == 0) {
		return 0;
	}
	long long binaryNum = 0;
	long long base = 1;
	while (decimal > 0) {
		int remainder = decimal % 2;
		binaryNum += remainder * base;
		base *= 10;
		decimal /= 2;
	}
	if (isNegative) {
		binaryNum = -binaryNum;
	}
	return binaryNum;
}




//穷举

//整数格式 （字符串如果有前导0，如0123，则不符合； +0，-0不符合，但+1和-1符合；科学记数法不符合）
/*
#include<stdio.h>
#define START 0//初始状态
#define SIGN 1//符号状态
#define DATA 2//数字状态
#define ZERO 4//首字符为0
#define ERR 9//错误状态
#define END 10//结束状态
int main(){
	char ch;
	int state,t;
	scanf("%d",&t);
	getchar();
	for (int i=0;i<t;i++){
		for(state=START,ch=getchar(); state!=END; ){
			switch(state){/*根据当前状态以及读入的字符决定状态的迁移*/
/*			case START://初始状态
				if(ch=='0')  state=ZERO;//0的状态
				else if (ch=='+' || ch=='-') state=SIGN;//符号状态
				else if (ch>='1' && ch<='9') state=DATA;//数字状态
				else state=ERR;//均不符合
				break;
            //进一步判断
			case SIGN:
				if (ch>='1' && ch<='9') state=DATA;
				else state=ERR;
				break;
			case DATA:
				if (ch=='\n')
				{
					printf("yes\n");state=END;
				}
				else if (ch<'0' || ch>'9') state=ERR;
				break;
			case ZERO:
				if (ch=='\n'){printf("yes\n");state=END;}
				else state=ERR;
				break;
			} /*switch*/
/*			if (state==ERR && ch=='\n'){
				printf("no\n");
				state=END;
			}
			if (state!=END) ch=getchar();//进一步循环
		}
	}
	return 0;
}
*/

//素数判断（子程序）
/*
bool isPrime(int num) {
	if (num <= 1) return false;
	if (num == 2) return true;
	if (num % 2 == 0) return false;

	for (int i = 3; i * i <= num; i += 2) {
		if (num % i == 0) return false;
	}
	return true;
}*/


//输出寻找的数组（输出满足条件的的3位数，要求从小到大，每行6个整数，整数间以空格分隔，但行末不能有多余空格）
/*#include <stdio.h>
int main() {
	int A;
	scanf("%d", &A);//给定不超过6的正整数A，考虑从A开始的连续4个数字，输出所有由它们组成的无重复数字的3位数
	int count = 0;  // 计数器，控制每行输出6个
	// 三重循环遍历百位、十位、个位（均取自A到A+3的连续4个数）
	for (int h = A; h <= A + 3; h++) {
		for (int t = A; t <= A + 3; t++) {
			if (t == h) continue;             // 十位不能等于百位
			for (int u = A; u <= A + 3; u++) {
				if (u == h || u == t) continue;

				// 生成三位数并按格式输出
				int num = h * 100 + t * 10 + u;
				if (count % 6 == 0) {
					printf("%d", num);        // 行首直接输出数字
				} else {
					printf(" %d", num);       // 非行首先输出空格再输出数字
				}
				count++;

				if (count % 6 == 0) {
					printf("\n");             // 每6个数字换行
				}
			}
		}
	}
	return 0;
}
*/

//状态机

//过滤注释
/*
#include<stdio.h>
#define Z1 1  // 正常状态（非注释）
#define Z2 2  // 已读 '/'，等待下一个字符判断是否为注释
#define Z3 3  // /* 块注释中
#define Z4 4  // // 行注释中
#define Z5 5  // 块注释中遇到 '*'，等待 '/' 结束
int main() {
	char ch;
	char prev_ch = '\0';//前一个字符
	int state = Z1;
	while (1) {
		ch = getchar();
		if (ch == '$') break;
		switch (state) {
		case Z1:
			if (ch == '/') {
				prev_ch = ch;
				state = Z2;
			} else {
				putchar(ch);
			}
			break;
		case Z2:
			if (ch == '/') {
				state = Z4;
			} else if (ch == '*') {
				state = Z3;
			} else {
				putchar(prev_ch);
				putchar(ch);
				state = Z1;
			}
			break;
		case Z3:
			if (ch == '*') {
				state = Z5;
			}
			break;
		case Z4:
			if (ch == '\n') {
				putchar(ch);
				state = Z1;
			}
			break;
		case Z5:
			if (ch == '/') {
				state = Z1;
			} else if (ch != '*') {
				state = Z3;
			}
			break;
		}
	}
	return 0;
}
*/


//龟兔赛跑
/*乌龟每分钟可以前进3米，兔子每分钟前进9米；兔子嫌乌龟跑得慢，觉得肯定能跑赢乌龟。
 *于是，每跑10分钟回头看一下乌龟，若发现自己超过乌龟，就在路边休息，每次休息30分钟，
 *否则继续跑10分钟；而乌龟非常努力，一直跑，不休息。*/
/*#include <stdio.h>
int main() {
	int T;
	scanf("%d", &T);
	int turtle = 3 * T;
	int rabbit = 0;
	int time_used = 0;//用过的时间
	int state = 0;
	while (time_used < T) {
		if (state == 0) {
			int run_time = (T - time_used >= 10) ? 10 : (T - time_used);
			rabbit += 9 * run_time;
			time_used += run_time;
			if (time_used < T) {
				if (rabbit > 3 * time_used) {
					state = 1;
				} else {
					state = 0;
				}
			}
		} else {
			int rest_time = (T - time_used >= 30) ? 30 : (T - time_used);//兔子休息
			time_used += rest_time;
			state = 0;
		}
	}
	if (rabbit > turtle) {
		printf("^_^ %d\n", rabbit);
	} else if (rabbit < turtle) {
		printf("@_@ %d\n", turtle);
	} else {
		printf("-_- %d\n", rabbit);
	}
	return 0;
}
*/


//英语老师小助手
/*规则：
 *1、如果写了某个大写字母，下一个就必须写同个字母的小写，或者写字母表中前一个字母的大写；
 *2、如果写了某个小写字母，下一个就必须写同个字母的大写，或者写字母表中下一个字母的小写。
 */

/*#include<stdio.h>
#include<ctype.h>//检查大小写
#define START 0
#define UP 1 //大写
#define LOW 2//小写
#define END 9
int main() {
	char curr, prev;
	int state = START;
	int is_error = 0;

	while (state != END) {//根据状态进行循环
		curr = getchar();//当前字符

		if (!isalpha(curr)) {//非英文字符
			state = END;
			break;
		}

		switch (state) {
		case START://初字符
			prev = curr;
			state = islower(curr) ? LOW : UP;//判别大小写
			break;

		case UP:
			char allowed_upper = (prev - 'A' + 25) % 26 + 'A';//计算前一个字符
			char allowed_lower = prev + ('a' - 'A');//小写字符数值大
			if (curr != allowed_upper && curr != allowed_lower) {
				is_error = 1;
				state = END;
			} else {
				prev = curr;
				state = islower(curr) ? LOW : UP;
			}
			break;

		case LOW:
			char allowed_upper_low = prev - ('a' - 'A');
			char allowed_lower_low = (prev - 'a' + 1) % 26 + 'a';
			if (curr != allowed_upper_low && curr != allowed_lower_low) {
				is_error = 1;
				state = END;
			} else {
				prev = curr;
				state = isupper(curr) ? UP : LOW;
			}
			break;
		}
	}

	printf("%c\n", is_error ? 'N' : 'Y');//判断输出
	return 0;
}
*/



//24级期中考
/*函数题
 *数制：现给定十进制正整数，和一个进制的基数（10进制表示），请你写一个函数将这个正整数变为该进制的数码与基数的幂次的乘积之和。
函数接口定义：
void    printBasePower( int number , int base ) ;
其中 number 和 base 都是用户传入的参数。number 代表待处理10进制正整数； base 是进制的基数。函数没有返回值，但要按要求输出结果。


void    printBasePower( int number , int base ){
	int digit,power;
	for (power=1; number!=0; power*=base){
		digit = number%base;
		if (digit!=0)
			printf("%d %d\n", digit,power);
		number = number/base;
	}
}

*回文数二

输入:121 3
输出:
1 1
2 2
Yes
输入:1234 4
输出:
1 4
No

#include <stdio.h>
#define BASE 10
int main(){
	int num,len,digit1,digit2;
	scanf("%d%d",&num,&len);
	int power=1;
	for (int i=1; i<len; i++)
		power*=BASE;
	int half = (len%2==0)? len/2 : (len+1)/2;
	int flag=1;
	for (int i=1; i<=half && flag; i++){
		digit1 = num/power;
		digit2 = num%10;
		printf("%d %d\n",digit1,digit2);
		num = (num%power)/10;
		power /= BASE*BASE;
		if (digit1 != digit2)
			flag = 0;
	}
	if (flag)
		printf("Yes\n");
	else  printf("No\n");
}

7-2 第十届黄龙士杯世界女子围棋赛
现在我们假设共有6人（A、B、C、D、E和F，也就是说共5轮比赛）参加比赛，比赛中没有出现和棋，且她们每人的获胜盘数都不相同。其中A获胜局数为X，B获胜局数为Y，请写一段程序输出所有可能的名次。
输入格式:只有一行，为两个用空格分隔的整数。依次代表X和Y。测试用例保证合法。
输出格式:
若干行，每行均为6个用空格分隔的整数，依次代表A的名次，B的名次，C的名次，D的名次，E的名次，F的名次。每种可能的名次输出时首先按照A名次从小到大输出；当A名次相同时，按照B名次从小到大输出；依此类推，后边排序的优先顺序依次为C、D、E、F。具体可参考输出样例。

#include <stdio.h>
int main(){
	int x,y,a,b,c,d,e,f;
	scanf("%d%d",&x,&y);

	for (a=1; a<=6; a++){
		for (b=1; b<=6; b++)
			if (b!=a)
				for (c=1; c<=6; c++)
					if (c!=a && c!=b)
						for (d=1; d<=6 ; d++)
							if (d!=a && d!=b && d!=c)
								for (e=1; e<=6; e++)
									if (e!=a && e!=b && e!=c && e!=d){
										f = 21 - (a+b+c+d+e);
										if (x == 6-a && y == 6-b)//判断不符合的
											printf("%d %d %d %d %d %d\n",a,b,c,d,e,f);
									}
	}

	return 0;
}

7-3 乘车
火车从始发站（称为第1站）开出，在始发站上车的人数为 departureStation ，然后到达第2站，在第2站有人上、下车，但上、下车的人数相同，
从第3站起（包括第3站）上车的人数都是前两站上车人数之和，而下车人数等于上一站上车人数，一直到终点站的前一站（第 n -1站），都满足此规律。
现给出的条件是共有 n 个车站，始发站上车的人数为 departureStation ，最后一站下车的人数是 m （全部下车）。请你写一段程序算出第2站上车的人数。


#include <stdio.h>
int main(){
	int n,st,m;
	scanf("%d%d%d",&n,&st,&m);

	int x,up1,up2,left,find=0,tmp;
	for (x=1; !find; x++){ //穷举第二站上车人数x
		up1 = st;	up2 = x;	left=st;
		for(int i=3; i<n; i++){
			left += up1+up2-up2;
			tmp = up2;
			up2 = up1 + up2;
			up1 = tmp;
		}
		if (left == m)
			find = 1;
	}
	printf("%d\n",x-1);

	return 0;
}

7-4 账单

输入样例:
ebook17papertowels18headphones179laptopbag49wirelesscharger75
输出样例:
338

#include <stdio.h>
#define LETTER 0
#define DIGIT 1
int main(){
	char ch;
	int data,sum=0;
	int state=LETTER;

	while ((ch=getchar())!='\n'){
		switch(state){
			case LETTER:
				if (ch>='0' && ch<='9'){
					data = ch-'0';
					state = DIGIT;
				}
				break;
			case DIGIT:
				if (ch>='0' && ch<='9'){
					data = data*10 + (ch-'0');
				} else {
					sum += data;
					state = LETTER;
				}
				break;
		}
	}
	if (state==DIGIT){ //done string end with digits.
		sum += data;
	}
	printf("%d\n",sum);

	return 0;
}


7-5 贴邮票一
现在有两种面值的邮票，一种为8角，一种为6角。你要付n角的邮资（不能多付也不能少付），请给出邮票张数最少的方案。如果没有正好的方案则输出-1。

#include <stdio.h>
int main(){
	int n,i,j,find;
	scanf("%d",&n);
	while (n!=-1){
		find = 0;
		for (i=n/8; i>=0 && !find; i--){//张数最小即i最大，i-8角邮票数
			for (j=0; j<=n/6 && !find; j++){//j-6角邮票数
				if (i*8+j*6 == n){
					find = 1;
					printf("%d %d\n",i,j);
				}
			}
		}
		if (!find)
			printf("-1\n");
		scanf("%d",&n);
	}

	return 0;
}


 */



//2025期中

//时钟格式
/*#include<stdio.h>
#define ST 0
#define H1 1
#define H2 2
#define M1 3
#define M2 4
#define ERR 7
#define OK 8
#define END 9
int main(){
	int t,state,i,hour1;
	char ch;
	scanf("%d",&t); getchar();
	for (i=1;i<=t;i++){
		state=ST;
		while (state!=END){
			ch=getchar();
			if (ch=='\n'){
				if (state==OK) printf("yes\n");
				else printf("no\n");
				state=END;
			}switch(state){
			case ST:
				if (ch>='0' && ch<='2'){
					state=H1;
					hour1=ch-'0';						}
				else state=ERR;	break;
			case H1:
				if ((hour1==2 && ch>='0' && ch<='3')||(hour1<2 && isdigit(ch)))
					state=H2;
				else state=ERR;	break;
			case H2:
				if (ch==':')
					state=M1;
				else state=ERR;	break;
			case M1:
				if (ch>='0' && ch<='5')
					state=M2;
				else state=ERR;	break;
			case M2:
				if (ch>='0' && ch<='9')
					state=OK;
				else state=ERR;	break;
			case OK:
				if (ch!='\n')
					state=ERR;	break;
			}
		}
	}
	return 0;
}
*/


//字符串
//字母统计
/*#include<stdio.h>
int main() {
    char str[101];
    int count[52] = {0};
    scanf("%s", str);
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (ch >= 'A' && ch <= 'Z') {
            count[ch - 'A']++;
        }
        else if (ch >= 'a' && ch <= 'z') {
            count[26 + (ch - 'a')]++;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            printf("The character %c has presented %d times.\n", 'A' + i, count[i]);
        }
    }
    for (int i = 0; i < 26; i++) {
        if (count[26 + i] > 0) {
            printf("The character %c has presented %d times.\n", 'a' + i, count[26 + i]);
        }
    }
    return 0;
}*/

//删除重复字符并排序
/*#include<stdio.h>
#include<string.h>
void bubbleSort(char arr[], int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            if (arr[j] > arr[j+1]) {
                char temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main() {
    char input[80];
    char unique[80] = {0};
    int exist[128] = {0};
    int unique_len = 0;
    fgets(input, 80, stdin);
    int input_len = strlen(input);
    if (input[input_len - 1] == '\n') {
        input[input_len - 1] = '\0';
        input_len--;
    }
    for (int i = 0; i < input_len; i++) {
        char ch = input[i];
        if (!exist[(int)ch]) {
            exist[(int)ch] = 1;
            unique[unique_len++] = ch;
        }
    }
    bubbleSort(unique, unique_len);
    for (int i = 0; i < unique_len; i++) {
        printf("%c", unique[i]);
    }
    printf("\n");
    return 0;
}*/

//删除字符串中的子串
/*#include <stdio.h>
#include <string.h>
int main() {
    char s1[82], s2[82];
    char result[82];
    fgets(s1, 82, stdin);
    fgets(s2, 82, stdin);
    int len1 = (int)strlen(s1);
    int len2 = (int)strlen(s2);
    if (s1[len1 - 1] == '\n') s1[--len1] = '\0';
    if (s2[len2 - 1] == '\n') s2[--len2] = '\0';
    if (len2 == 0) {
        printf("%s\n", s1);
        return 0;
    }
    if (len2 > len1) {
        printf("%s\n", s1);
        return 0;
    }
    int i = 0, j = 0;
    int found;
    do {
        found = 0;
        i = 0;
        j = 0;
        while (i < len1) {
            int match = 1;
            for (int k = 0; k < len2; k++) {
                if (i + k >= len1 || s1[i + k] != s2[k]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                i += len2;
                found = 1;
            } else {
                result[j++] = s1[i++];
            }
        }
        result[j] = '\0';
        strcpy(s1, result);
        len1 = j;
    } while (found);
    printf("%s\n", s1);
    return 0;
}*/

//A-B
/*#include<stdio.h>
int main() {
    char A[10001] = {0}, B[10001] = {0};
    int exist[128] = {0};
    int lenA = 0, lenB = 0;
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF && lenA < 10000) {
        A[lenA++] = ch;
    }
    while ((ch = getchar()) != '\n' && ch != EOF && lenB < 10000) {
        B[lenB++] = ch;
    }
    for (int i = 0; i < lenB; i++) {//标记B中的字符
        exist[(unsigned char)B[i]] = 1;
    }
    for (int i = 0; i < lenA; i++) {
        if (!exist[(unsigned char)A[i]]) {
            putchar(A[i]);
        }
    }
    putchar('\n');
    return 0;
}*/

//说反话
/*#include<stdio.h>
void reverse(char *start, char *end) {//反转数组
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}
int main() {
    char buf[500001] = {0};
    int len = 0;
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF && len < 500000) {
        buf[len++] = ch;
    }
    reverse(buf, buf + len - 1);
    int i = 0, j = 0;
    while (i < len) {
        while (i < len && buf[i] == ' ') i++;
        j = i;
        while (j < len && buf[j] != ' ') j++;
        if (i < len) {
            reverse(buf + i, buf + j - 1);
            i = j;
        }
    }
    int pos = 0;
    for (i = 0; i < len; i++) {
        if (buf[i] != ' ') {
            buf[pos++] = buf[i];
            if (i + 1 < len && buf[i + 1] == ' ') {
                buf[pos++] = ' ';
            }
        }
    }
    if (pos > 0 && buf[pos - 1] == ' ') pos--;
    buf[pos] = '\0';
    printf("%s\n", buf);
    return 0;
}
*/

//24第三次机考
/*void output( int n ) {
    if (n == 0) {
        return;
    }
    output(n - 1);
    print_line(n, 1);
    printf("\n");
}
void print_line(int k, int cnt) {
    if (cnt > k) {
        return;
    }
    if (cnt == 1) {
        printf("%d", k);
    } else {
        printf(" %d", k);
    }
    print_line(k, cnt + 1);
}*/

//抽奖
/*#include<stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int num[100000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    int m;
    scanf("%d", &m);
    int jiang[50];
    for (int i = 0; i < m; i++) {
        scanf("%d", &jiang[i]);
    }
    for (int i = 0; i < m; i++) {
        int target = jiang[i];
        int left = 0, right = n - 1;//双指针
        while (left < right) {
            int sum = num[left] + num[right];
            if (sum == target) {
                printf("%d = %d + %d\n", target, num[left], num[right]);
                break;
            } else if (sum < target) {
                left++;//jiang[]有序
            } else {
                right--;
            }
        }
    }
    return 0;
}*/


//句子排序
/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void sort(char** strArray, int size);
int main() {
    int n;
    scanf("%d", &n);
    getchar();
    char* str_buf = (char*)calloc(100000, sizeof(char));
    if (str_buf == NULL) return 1;
    char** str_ptr = (char**)calloc(n, sizeof(char*));
    if (str_ptr == NULL) {
        free(str_buf);
        return 1;
    }
    char* p = str_buf;
    for (int i = 0; i < n; i++) {
        str_ptr[i] = p;
        fgets(p, 100000-(p-str_buf), stdin);
        int len = strlen(p);
        if (len > 0 && p[len - 1] == '\n') {
            p[len - 1] = '\0';
        }
        p += len;
    }
    sort(str_ptr, n);
    for (int i = 0; i < n; i++) {
        puts(str_ptr[i]);
    }
    free(str_ptr);
    free(str_buf);
    return 0;
}
void sort(char** strArray, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (strcmp(strArray[j], strArray[j+1]) > 0) {
                char* temp = strArray[j];
                strArray[j] = strArray[j+1];
                strArray[j+1] = temp;
            }
        }
    }
}*/

//回文单词（先删除多余字符）
/*int isPalindrome(char word[]) {
    char new[100];
    int count = 0;
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        if (word[i] >= 'a' && word[i] <= 'z') {
            new[count] = word[i];
            count++;
        }
    }
    for (int c = 0; c < count; c++) {
        word[c] = new[c];
    }
    word[count] = '\0';
    if (count == 0) {
        return 0;
    }
    for (int p = 0; p < count / 2; p++) {
        if (word[p] != word[count - 1 - p]) {
            return 0;
        }
    }
    return 1;
}*/

//遇到空格换行输出
/*int getString( char * source , char *strPtr[] ) {
    int count = 0;
    while (*source == ' ') {
        source++;
    }
    while (*source != '\0') {
        strPtr[count] = source;
        while (*source != ' ' && *source != '\0') {
            source++;
        }
        if (*source == ' ') {
            *source = '\0';
            source++;
            while (*source == ' ') {
                source++;
            }
        }
        count++;
        if (*source == '\0') {
            break;
        }
    }
    return count;
}*/

//动态数组排序
/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void sort(char** strArray, int size);
int main() {
    int n;
    scanf("%d", &n);
    getchar();
    char* str_buf = (char*)calloc(100000, sizeof(char));
    if (str_buf == NULL) return 1;
    char** str_ptr = (char**)calloc(n, sizeof(char*));
    if (str_ptr == NULL) {
        free(str_buf);
        return 1;
    }
    char* p = str_buf;
    for (int i = 0; i < n; i++) {
        str_ptr[i] = p;
        fgets(p, 100000-(p-str_buf), stdin);
        int len = strlen(p);
        if (len > 0 && p[len - 1] == '\n') {
            p[len - 1] = '\0';
        }
        p += len;
    }
    sort(str_ptr, n);
    for (int i = 0; i < n; i++) {
        puts(str_ptr[i]);
    }
    free(str_ptr);
    free(str_buf);
    return 0;
}
void sort(char** strArray, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (strcmp(strArray[j], strArray[j+1]) > 0) {
                char* temp = strArray[j];
                strArray[j] = strArray[j+1];
                strArray[j+1] = temp;
            }
        }
    }
}*/

//结构体
typedef struct
{
    char names[22];
    char xuehao[22];
    int score[5];
    double average;
    int total;
}STUDENT;

//旋风单词（双指针）
int isCycloneWord(char *word) {
    int len = 0;
    while (word[len] != '\0') {
        len++;
    }
    int left = 0;
    int right = len - 1;
    int prev = word[left];
    left++;
    while (left <= right) {
        if (word[right] < prev) {
            return 0;
        }
        prev = word[right];
        right--;
        if (left <= right) {
            if (word[left] < prev) {
                return 0;
            }
            prev = word[left];
            left++;
        }
    }
    return 1;
}

//年度之星
/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    char *origin;
    char excellent[11];
} Student;
void swap(Student *a, Student *b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}
int main() {
    int n;
    scanf("%d", &n);
    Student *stu = (Student*)malloc(n * sizeof(Student));
    if (stu == NULL) {
        return 1;
    }
    char temp[10001];
    for (int i = 0; i < n; i++) {
        scanf("%s", temp);
        int len_ori = strlen(temp);
        stu[i].origin = (char*)malloc(len_ori + 1);
        if (stu[i].origin == NULL) {
            return 1;
        }
        strcpy(stu[i].origin, temp);
        int idx_ex = 0;
        for (int k = 0; temp[k] != '\0' && idx_ex < 10; k++) {
            if (temp[k] >= 'A' && temp[k] <= 'E') {
                stu[i].excellent[idx_ex++] = temp[k];
            }
        }
        stu[i].excellent[idx_ex] = '\0';
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            int cmp_ex = strcmp(stu[j].excellent, stu[j+1].excellent);
            if (cmp_ex < 0) {
                swap(&stu[j], &stu[j+1]);
            } else if (cmp_ex == 0) {
                int cmp_ori = strcmp(stu[j].origin, stu[j+1].origin);
                if (cmp_ori < 0) {
                    swap(&stu[j], &stu[j+1]);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%s\n", stu[i].origin);
    }
    for (int i = 0; i < n; i++) {
        free(stu[i].origin);
    }
    free(stu);
    return 0;
}*/
/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(char s1[],char s2[])
{
	char a1[15],a2[15];
	int cnt=0;
	for(int i=0;s1[i]!='\0';i++) if(s1[i]<='E'&&s1[i]>='A') a1[cnt++]=s1[i];
	a1[cnt]='\0';
	cnt=0;
	for(int i=0;s2[i]!='\0';i++) if(s2[i]<='E'&&s2[i]>='A') a2[cnt++]=s2[i];
	a2[cnt]='\0';
	if(strcmp(a1,a2)<0) return 1;
	else if(strcmp(a1,a2)>0) return 0;
	else
	{
		if(strcmp(s1,s2)<0) return 1;
		else return 0;
	}
	return 0;
}
int main()
{
	int n;
	scanf("%d",&n);
	char **a=(char **)malloc(sizeof(char *)*n);
	for(int i=0;i<n;i++)
	{
		char s[10010];
		scanf("%s",s);
		int cnt=0;
		for(int j=0;s[j]!='\0';j++) cnt++;
		a[i]=(char *)malloc(sizeof(char)*cnt);
		strcpy(a[i],s);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(cmp(a[j],a[j+1]))
			{
				char *temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	for(int i=0;i<n;i++) printf("%s\n",a[i]);
	return 0;
}*/

