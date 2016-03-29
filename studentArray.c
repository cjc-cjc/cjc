#include <stdio.h>
typedef struct Student
{
	int num;
	char name[15];
	float score[3];
}Stu,*Pstu;

Stu student[5];

int main(void)
{
	void print(Pstu pstu);
	int i;
	int j;

	printf("请输入5个学生信息：\n");
	for(i=0;i<5;i++)
	{
		printf("Input num:",i+1);
		scanf("%d",&student[i].num);
		printf("Input name:");
		scanf("%s",&student[i].name);
		printf("Input score:");
		for(j=0;j<3;j++)
			scanf("%f",&student[i].score[j]);
		printf("\n");
	}
	print(student);

	return 0;
}

void print(Pstu pstu)
{
	int i;
	for(i=0;i<5;i++)
	{
		printf("num = %d\n",pstu[i].num);
		printf("name: %s\n",pstu[i].name);
		printf("score:%15f%15f%15f\n",pstu[i].score[0],pstu[i].score[1],pstu[i].score[2]);
		printf("\n");
	}
}