#include <stdio.h>

// 从文件自动读取输入数据，不用每次都在小黑框输入测试，写程序快多啦！

int main(void)
{
	int a,b,c;

	// 正式提交时记得！
	// 1,，删掉下面这段！
		FILE *fp=fopen("input.txt","r");//读取txt文件
	if (fp==NULL) {//若打开文件失败则退出
		puts("不能打开文件！");
		return 0;
	}
	//2，fscanf这句换成scanf这句
	while(fscanf(fp,"%d%d%d", &a,&b,&c)!=EOF){
	//while(scanf(%d%d%d", &a,&b,&c)!=EOF){
		// do something, like:
		printf("%d %d %d\n", a,b,c);
	}
	
	getchar();  //小黑框一闪而过时可以加上这句, VS是要的，codeblocks删掉
	return 0;
}