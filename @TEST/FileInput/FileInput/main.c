#include <stdio.h>

// ���ļ��Զ���ȡ�������ݣ�����ÿ�ζ���С�ڿ�������ԣ�д����������

int main(void)
{
	int a,b,c;

	// ��ʽ�ύʱ�ǵã�
	// 1,��ɾ��������Σ�
		FILE *fp=fopen("input.txt","r");//��ȡtxt�ļ�
	if (fp==NULL) {//�����ļ�ʧ�����˳�
		puts("���ܴ��ļ���");
		return 0;
	}
	//2��fscanf��任��scanf���
	while(fscanf(fp,"%d%d%d", &a,&b,&c)!=EOF){
	//while(scanf(%d%d%d", &a,&b,&c)!=EOF){
		// do something, like:
		printf("%d %d %d\n", a,b,c);
	}
	
	getchar();  //С�ڿ�һ������ʱ���Լ������, VS��Ҫ�ģ�codeblocksɾ��
	return 0;
}