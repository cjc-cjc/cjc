#include <stdio.h>
struct Student
{
	int id;
	char name[15];
	float score1;
	float score2;
	float score3;
	float aver;
	float sum;
};
struct Student student[5];
void input();
float average(int n);
int max();
int main(void)
{
	input();
	printf("��һ�ſε���ƽ����average1=%.1f\n",average(1));
	printf("�ڶ��ſε���ƽ����average2=%.1f\n",average(2));
	printf("�����ſε���ƽ����average3=%.1f\n",average(3));
	printf("��߷��ǵ�%dλͬѧ:\n",max()+1);
	
	printf("���֣�%s\n:\n",student[max()].name);
	printf("�ܷ�Ϊ��%.1f\n",student[max()].sum);
	printf("score1=%.1f\nscore2=%.1f\nscore3=%.1f\n",student[max()].score1,student[max()].score2,student[max()].score3);
	printf("average=%.1f\n",student[max()].aver);

	return 0;
}

void input()
{
	int i;
	printf("��Ϊ���ѧ������ɼ���\n");
	for(i=0;i<5;i++)
	{
		printf("�������%dѧ����ѧ�ţ�\n",i+1);
		scanf("%d",&student[i].id);
		printf("�������%d��ѧ����������\n",i+1);
		scanf("%s",student[i].name);
		printf("��%d��ѧ���ĳɼ�(���Ÿ���)��\n",i+1);
		scanf("%f,%f,%f",&student[i].score1,&student[i].score2,&student[i].score3);
	}
}

float average(int n)
{
	float sum1=0;
	float average=0;
	int i;

	if(n<1||n>3)
		printf("�������ݴ���������1~3");
	else if(n==1)
	{
		for(i=0;i<5;i++)
		sum1 += student[i].score1;
		average = sum1/5;
	}

	else if(n==2)
	{
		for(i=0;i<5;i++)
		sum1 += student[i].score2;
		average = sum1/5;
	}

	else
	{
		for(i=0;i<5;i++)
		sum1 += student[i].score3;
		average = sum1/5;
	}
	return average;
}

int max()
{
	int i;
	int j;
	for(i=0;i<5;i++)
		student[i].sum = student[i].score1+student[i].score2+student[i].score3;
	j = 0;
	for(i=1;i<5;i++)
	{
		if(student[j].sum<student[i].sum)
			j = i;
	}
	for(i=0;i<5;i++)
	{
		student[i].sum = student[i].score1+student[i].score2+student[i].score3;
		student[i].aver = student[i].sum / 3;
	}
	return j;
}