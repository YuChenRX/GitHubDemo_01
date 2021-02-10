#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

int Count=0;
void PrintIntArray(int *PrintArray,int Begine,int ArrayLen);
void MyRand(int Min, int Max, int *RandNumber, int NumberLen);		//�����
void BubbleSort(int *SortArray, int Number);						//ð������
void Swap(int *a, int *b);											//������ֵ
int QuickSort(int *SortArray,int Len);	//!
void FindSort(int *SortArray, int Number);							//��������
int TwoSearchingMethod(int *SortArray, int Number, int FindNumber); //���ֲ���
void RotateArray(int *Array, int Number);							//�����ͷ;//�ַ������ܵ�ͷ
/*************�޷�������**************************************/
int BinHexOct(int InputNumber, int AnySystem, int *Save, int SaveWide); //10ת-������־Ϊ-1
int CountSort(int *SortArry, int MaxLen);//ing
//int Sort[]={2,4,3,4};//!!!
//int Sort[]={53 ,26, 72, 16, 44, 55, 76, 84, 53, 18};
//int Sort[]={4,1,3};
//int Sort[]={55 ,76 ,84 ,53 ,72};
//int Sort[]={16,26,72};
//int Sort[]={5 ,7, 1, 7, 8};
//int Sort[]={2,1};
//int Sort[]={53,72, 16, 76, 84, 53};
int Sort[]={9,8,7,6,5,4,3,2,1,0};
int *p=Sort;
int SortLen=sizeof(Sort)/sizeof(Sort[0]);
#if (1)
int main()
{
	srand((unsigned)time(NULL));
//	MyRand(0, 110, Sort,sizeof(Sort)/sizeof(int));
	FindSort(Sort,sizeof(Sort)/sizeof(Sort[0])); 
//	QuickSort(Sort,sizeof(Sort)/sizeof(Sort[0])); 
//	FindSort(Sort,sizeof(Sort)/sizeof(int));
	PrintIntArray(Sort,0,sizeof(Sort)/sizeof(int));
	printf("\n�ܴ�����%d\n",Count);
//	printf("--%d\n",Count);
	//system("pause");
	return 0;
}
#endif

void MyRand(int Min, int Max, int *RandNumber, int NumberLen)
{
	for (int i = 0; i < NumberLen; i++)
	{
		*(RandNumber + i) = rand() % (Max - Min) + Min;
	}
}

void Swap(int *a, int *b)
{
	int c=0;
	c = *a ;
	*a = *b;
	*b = c;
}

void BubbleSort(int *SortArray, int Number)
{
	int End = Number;
	while (End != 0)
	{
		for (int i = 0; i < Number; i++)
		{
			if (i+1<=Number&&SortArray[i] < SortArray[i + 1])
			{
				Swap(&SortArray[i], &SortArray[i + 1]);
				End = i;
			}
		}
		End--;
	}
}

int QuickSort(int *SortArray,int Len)
{	
//	int* Sort=SortArray;
//	int RightIndex=Len-1;
//	int Run=1;
//	int LeftIndex=0;
//	int Base=*SortArray;
//	
//	while(LeftIndex!=RightIndex)
//	{
//		if(*(Sort+LeftIndex)>=Base&&Run==-1)
//		{
//			*(Sort+RightIndex)=*(Sort+LeftIndex);
//			Run=1;			
//		}
//		if(*(Sort+RightIndex)<Base&&Run==1)
//		{
//			*(Sort+LeftIndex)=*(Sort+RightIndex);
//			Run=-1;
//		}
//		if(Run==1)RightIndex--;
//		if(Run==-1)LeftIndex++;
//	}
//	*(Sort+LeftIndex)=Base;
//	printf("L-%d R-%d Len%d\n",LeftIndex,RightIndex,Len);
//	PrintIntArray(Sort,0,Len);
//	if(LeftIndex>=2) QuickSort(Sort+1,LeftIndex-1);
//	if(Len-RightIndex>2) QuickSort((Sort+RightIndex+1),Len-RightIndex-1);
//	return 0;
    int *Array=SortArray;
    int Left=0;
    int Right=Len-1;
    int P=*SortArray;
    int Run=1;
    while(Left!=Right)
    {
    	printf("Left:%d Right:%d P:%d\t",Left,Right,P);
    	PrintIntArray(Sort,0,SortLen);
        if(*(Array+Left)>=P&&Run==-1)
        {
        	*(Array+Right)=*(Array+Left);
            Run=1;
            PrintIntArray(Sort,0,SortLen);
            continue;
        }
        if(Run==1)Right--;
        if(Run==-1)Left++;
        if(*(Array+Right)<P&&Run==1)
        {
            *(Array+Left)=*(Array+Right);
            Run=-1;
            PrintIntArray(Sort,0,SortLen);
            continue;
        }
    }
    *(Array+Left)=P;
    if(Left>=2) QuickSort (Array,Left-1);
    if(Len-Right>2) QuickSort (Array,Len-1);
    return 0;
}

void FindSort(int *SortArray, int Number)
{
	int Index=0;
	for(int i=0;i<Number;i++)
	{
		for(int j=Index+1;j<Number;j++)
		{
			if(*(SortArray+Index)>*(SortArray+j))
			{
				Swap(SortArray+Index,SortArray+j);
			}	
		} 
		Index++;
	}
}

int TwoSearchingMethod(int *FindArray, int Number, int FindNumber)
{
	int Begin = 0;				 //����ߵ�ֵ
	int End = Number;			 //���ұߵ�ֵ
	int Mid = (Begin + End) / 2; //ȷ�����м�ֵ���±�
	while (1)
	{
		if (FindArray[Mid] > FindNumber)
		{
			End = Mid - 1;
			Mid = (Begin + End) / 2;
		}
		if (FindArray[Mid] < FindNumber)
		{
			Begin = Mid + 1;
			Mid = (Begin + End) / 2;
		}
		if (FindArray[Mid] == FindNumber)
		{
			return Mid;
		}
		if (Begin > End)
		{
			//���ش���ֵ
			return -1;
		}
	}
	return -1; 
}

void RotateArray(int *Array, int Number)
{
	//�м�ֵ���Դ�Ϊ��׼���߽��н�����
	Number--;
	int Begin = 0; //��ͷ��
	for (int i = 0; i < Number / 2; i++)
	{
		Swap(&Array[Begin + i], &Array[Number - i]); //��ͷ��
	}
}

int BinHexOct(int InputNumber, int AnySystem, int *Save, int SaveWide)
{
	//�������϶�ȡŶw
	int i = 0;
	while (InputNumber >= AnySystem)
	{
		//һֱ����ȥ��
		if (i <= SaveWide && i + 1 < SaveWide)
		{
			//����쳣��飻
			Save[i] = InputNumber % AnySystem;
			InputNumber = InputNumber / AnySystem;
			i++; //������б��棻
		}
		else
		{

			return -1;
		}
	}
	Save[i] = InputNumber;
	i++;
	Save[i] = -1;
	i = 0;
	while (Save[i] != -1)
	{
		i++;
	}
	RotateArray(Save, i);
	return i;
}

int CountSort(int *SortArry, int MaxLen)
{
	int Max = SortArry[0], Min = SortArry[0];
	/*************��ȡ��Сֵ********************/
	for (int i = 0; i < MaxLen; i++)
	{
		if (SortArry[i] > Max)
		{
			Max = SortArry[i];
		}
		else if (SortArry[i] < Min)
		{
			Min = SortArry[i];
		}
	}

	int *ArrayTemp = (int *)malloc((Max - Min) * sizeof(int)); //���ٿռ�Max-Min
	for (int i = 0; i < Max - Min; i++)
	{
		ArrayTemp[i] = 0; //��ʼ��
	}

	for (int i = 0; i <= MaxLen; i++)
	{
		ArrayTemp[(SortArry[i] - Min)]++;
		printf("SortArry[i] - Min:%d\n", SortArry[i] - Min);
		if (SortArry[i] - Min > 10)
		{
			printf("___________________________\n\n%d\n\n", i);
			exit(0);
		}
		printf("ArrayTemp[SortArry[i] - Min]:%d\n", ArrayTemp[SortArry[i] - Min]);
	}
	return 0;
}

void PrintIntArray(int *PrintArray,int Begine,int ArrayLen)
{
	for (int i = Begine; i < ArrayLen; i++)
	{
		printf("%d ", PrintArray[i]);
	}
	printf("\n");
}
