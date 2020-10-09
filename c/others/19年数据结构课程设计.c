#include<stdio.h>
#include<time.h>//产生随机函数跟测量时间的头文件
#include<stdlib.h>//产生随机函数的头文件
#include<math.h>

#define _COUNT 30000 //因为rand()的返回值的范围只有0~(2^15)-1内,因此可以产生30000个随机数

unsigned int idex = 0;
unsigned int array[_COUNT], array1[_COUNT], array2[_COUNT], array3[_COUNT], array4[_COUNT], array5[_COUNT], array6[_COUNT], array7[_COUNT];//全局变量
clock_t start[8], stop[8];//clock_t是clock()函数返回的类型
double duration[8];//全局变量,记录每种排序的时间

void initArray();//函数声明,生成30000个随机数
void Creatrandnum();//函数声明,调用作用
void saveArray();//保存随机数
void Select(int number);//起选择哪种排序作用
int contains(unsigned int num);//检查某个数是否已经在数组里面
unsigned int CopyArray(unsigned int arrayn[]);//临时存放随机数的数组
void saveArray1(unsigned int array1[]);//插入排序数的保存地址
void saveArray2(unsigned int array2[]);//希尔排序数的保存地址
void saveArray3(unsigned int array3[]);//冒泡排序数的保存地址
void saveArray4(unsigned int array4[]);//快速排序数的保存地址
void saveArray5(unsigned int array5[]);//选择排序数的保存地址
void saveArray6(unsigned int array6[]);//堆排序数的保存地址
void saveArray7(unsigned int array7[]);//归并排序数的保存地址
void InserSort(unsigned int array1[]);//直接插入
void BubbleSort(unsigned int array2[]);//冒泡排序
void Shellsort(unsigned int array3[]);//希尔排序
void quicksort(unsigned int array4[], int low, int high);//快速排序
int split(unsigned int array4[], int low, int high);//快速排序
void SelectSort(unsigned int array5[]);//选择排序
void HeapSort(unsigned int array6[]);//堆排序
void Swap(unsigned int* num_a, unsigned int* num_b);//堆排序
void HeapAdjust(unsigned int array6[], int i, int nLength);//堆排序
void MergeSort(unsigned int array7[], int start, int end);//归并排序
void Merge(unsigned int array7[], int left, int m, int right);//归并排序

int main()
{
	int number;
	printf("                                      欢迎来到第五十二题排序研究系统                   \n\n");
	Creatrandnum();
	for (number = 1; number <= 7; number++) //判断是不是要结束测试,目的是一次性测量出这几个排序的时间,避免一个一个的测量
	{
		Select(number);
		if (number == 7)
		{
			printf("\n");
			printf("------------------------------------------------------------------\n");
			printf("|直接排序|希尔排序|冒泡排序|快速排排序|选择排序| 堆排序 |归并排序|\n");
			printf("------------------------------------------------------------------\n");
			printf("|%lf|%lf|%lf| %lf |%lf|%lf|%lf|\n", duration[1], duration[2], duration[3], duration[4], duration[5], duration[6], duration[7]);
			printf("------------------------------------------------------------------\n");
		}
	}
	system("pause");
	return 0;
}

void Select(int number)
{
	switch (number)
	{
	case 1:
	{
		CopyArray(array1);
		printf("\n1.插入排序\n");
		start[1] = clock();//不在测试范围内的准备工作写在clock()后面
		InserSort(array1);
		stop[1] = clock();//直接插入排序结束
		saveArray1(array1);
		printf("直接插入排序的%d个排序数据已经保存\n\n", _COUNT);
		duration[1] = ((double)(stop[1] - start[1])) / CLK_TCK;//CLK_TCK是常数,每个电脑都不同
		printf("%d个随机数用直接插入排序所耗费的时间为的ticks为:%lf\n", _COUNT, (double)(stop[1] - start[1]));
		printf("%d个随机数用直接插入排序所耗费的时间为的duration为:%lf\n", _COUNT, duration[1]);//duration的单位是秒
		break;
	}
	case 2:
	{
		CopyArray(array2);
		printf("\n2.希尔排序\n");
		start[2] = clock();//不在测试范围内的准备工作写在clock()后面
		Shellsort(array2);
		stop[2] = clock();
		printf("希尔排序的%d个排序数据已经保存\n\n", _COUNT);
		saveArray2(array2);
		duration[2] = ((double)(stop[2] - start[2])) / CLK_TCK;
		printf("%d个随机数用希尔插入排序所耗费的时间为的ticks为:%lf\n", _COUNT, (double)(stop[2] - start[2]));
		printf("%d个随机数用希尔排序所耗费的时间为:%lf\n", _COUNT, duration[2]);
		break;
	}
	case 3:
	{
		CopyArray(array3);
		printf("\n3.冒泡排序\n");
		start[3] = clock();//不在测试范围内的准备工作写在clock()后面
		BubbleSort(array3);
		stop[3] = clock();
		printf("冒泡排序的%d个排序数据已经保存\n\n", _COUNT);
		saveArray3(array3);
		duration[3] = ((double)(stop[3] - start[3])) / CLK_TCK;
		printf("%d个随机数用冒泡插入排序所耗费的时间为的ticks为:%lf\n", _COUNT, (double)(stop[3] - start[3]));
		printf("%d个随机数用冒泡排序所耗费的时间为:%lf\n", _COUNT, duration[3]);
		break;
	}
	case 4:
	{
		CopyArray(array4);
		printf("\n4.快速排序\n");
		start[4] = clock();//不在测试范围内的准备工作写在clock()后面
		quicksort(array4, 0, _COUNT - 1);
		stop[4] = clock();
		printf("直接插入排序的%d个排序数据已经保存\n\n", _COUNT);
		saveArray4(array4);
		duration[4] = ((double)(stop[4] - start[4])) / CLK_TCK;
		printf("%d个随机数用快速排序所耗费的时间为的ticks为:%lf\n", _COUNT, (double)(stop[4] - start[4]));
		printf("%d个随机数用快速排序所耗费的时间为:%lf\n", _COUNT, duration[4]);
		break;
	}
	case 5:
	{
		CopyArray(array5);
		printf("\n5.选择排序\n");
		start[5] = clock();//不在测试范围内的准备工作写在clock()后面
		SelectSort(array5);
		stop[5] = clock();
		printf("选择排序的%d个排序结果已经保存\n\n", _COUNT);
		saveArray5(array5);
		duration[5] = ((double)(stop[5] - start[5])) / CLK_TCK;
		printf("%d个随机数用选择排序所耗费的时间为的ticks为:%lf\n", _COUNT, (double)(stop[5] - start[5]));
		printf("%d个随机数用选择排序所耗费的时间为:%lf\n", _COUNT, duration[5]);
		break;
	}
	case 6:
	{
		CopyArray(array6);
		printf("\n6.堆排序\n");
		start[6] = clock();//不在测试范围内的准备工作写在clock()后面
		HeapSort(array6);
		stop[6] = clock();
		printf("堆排序的%d个排序结果已经保存\n\n", _COUNT);
		saveArray6(array6);
		duration[6] = ((double)(stop[6] - start[6])) / CLK_TCK;
		printf("%d个随机数用堆排序所耗费的时间为的ticks为:%lf\n", _COUNT, (double)(stop[6] - start[6]));
		printf("%d个随机数用堆排序所耗费的时间为:%lf\n", _COUNT, duration[6]);
		break;
	}
	case 7:
	{
		CopyArray(array7);
		printf("\n7.归并排序\n");
		start[7] = clock();//不在测试范围内的准备工作写在clock()后面
		MergeSort(array7, 0, _COUNT - 1);
		stop[7] = clock();
		printf("归并排序的%d个排序结果已经保存\n\n", _COUNT);
		saveArray7(array7);
		duration[7] = ((double)(stop[7] - start[7])) / CLK_TCK;
		printf("%d个随机数用归并排序所耗费的时间为的ticks为:%lf\n", _COUNT, (double)(stop[7] - start[7]));
		printf("%d个随机数用归并排序所耗费的时间为:%lf\n", _COUNT, duration[7]);
		break;
	}
	}
}
void Creatrandnum()
{
	initArray();
	printf("\n%d个随机数已经产生\n", _COUNT);
	saveArray();
}
int contains(unsigned int num)//检查某个数是否已经存在数组
{
	for (unsigned int i = 0; i <= idex; i++)
	{
		if (num == array[i])
			return 1;
	}
	return 0;
}
void initArray()
{
	srand(time(NULL));
	while (idex != _COUNT)
	{
		unsigned int t = rand() % 32768;//产生随机数
		if (!contains(t))
		{
			array[idex++] = t;
		}
	}
}
unsigned int CopyArray(unsigned int arrayn[])
{
	int i;
	for (i = 0; i < _COUNT; i++)
		arrayn[i] = array[i];//保存随机数到每个排序数组
	return *arrayn;//返回
}
void saveArray()//将数据打印到文件系统
{
	FILE* fp = fopen("E:\\generates\\randnum30000.txt", "wt");//不出错的前提是目录必须存在
	if (fp)
	{
		for (unsigned int i = 0; i < _COUNT; i++)
		{
			fprintf(fp, "%d\n", array[i]);
		}
		fclose(fp);
	}
}
void saveArray1(unsigned int array1[])//将数据打印到文件系统
{
	FILE* fp = fopen("E:\\generates\\InserSort30000.txt", "wt");
	if (fp)
	{
		for (unsigned int i = 0; i < _COUNT; i++)
		{
			fprintf(fp, "%d\n", array1[i]);
		}
		fclose(fp);
	}
}
void saveArray2(unsigned int array2[])//将数据打印到文件系统
{
	FILE* fp = fopen("E:\\generates\\ShellSort30000.txt", "wt");
	if (fp)
	{
		for (unsigned int i = 0; i < _COUNT; i++)
		{
			fprintf(fp, "%d\n", array2[i]);
		}
		fclose(fp);
	}
}
void saveArray3(unsigned int array3[])//将数据打印到文件系统
{
	FILE* fp = fopen("E:\\generates\\BubbleSort30000.txt", "wt");
	if (fp)
	{
		for (unsigned int i = 0; i < _COUNT; i++)
		{
			fprintf(fp, "%d\n", array3[i]);
		}
		fclose(fp);
	}
}
void saveArray4(unsigned int array4[])//将数据打印到文件系统
{
	FILE* fp = fopen("E:\\generates\\quickSort30000.txt", "wt");
	if (fp)
	{
		for (unsigned int i = 0; i < _COUNT; i++)
		{
			fprintf(fp, "%d\n", array4[i]);
		}
		fclose(fp);
	}
}
void saveArray5(unsigned int array5[])//将数据打印到文件系统
{
	FILE* fp = fopen("E:\\generates\\SelectSort30000.txt", "wt");
	if (fp)
	{
		for (unsigned int i = 0; i < _COUNT; i++)
		{
			fprintf(fp, "%d\n", array5[i]);
		}
		fclose(fp);
	}
}
void saveArray6(unsigned int array6[])//将数据打印到文件系统
{
	FILE* fp = fopen("E:\\generates\\HeapSort30000.txt", "wt");
	if (fp)
	{
		for (unsigned int i = 0; i < _COUNT; i++)
		{
			fprintf(fp, "%d\n", array6[i]);
		}
		fclose(fp);
	}
}
void saveArray7(unsigned int array7[])//将数据打印到文件系统
{
	FILE* fp = fopen("E:\\generates\\MSort30000.txt", "wt");
	if (fp)
	{
		for (unsigned int i = 0; i < _COUNT; i++)
		{
			fprintf(fp, "%d\n", array7[i]);
		}
		fclose(fp);
	}
}
void InserSort(unsigned int array1[])//对array1做插入处理
{
	int j, i;
	for (i = 1; i < _COUNT; ++i)
		if (array1[i] < array1[i - 1])
		{
			array1[_COUNT] = array1[i];//监视哨array[-COUNT]
			array1[i] = array1[i - 1];
			for (j = i - 1; array1[_COUNT] < array1[j]; --j)//从后往前寻找插入位置
				array1[j + 1] = array1[j];//逐个后移,直到找到插入位置
			array1[j + 1] = array1[_COUNT];//还原,插入到正确位置
		}
}
void BubbleSort(unsigned int array2[])
{
	//冒泡法排序实现从小到大排序
	for (int i = 0; i < _COUNT; i++) //进行10次循环
	{
		for (int j = i + 1; j < _COUNT; j++) //循环比较剩余的变量
		{
			if (array2[i] > array2[j]) //如果前面一个数比后面数大，交换两个数的值
			{
				array2[i] ^= array2[j];
				array2[j] ^= array2[i];
				array2[i] ^= array2[j];//位运算,不用临时变量,刚学的.
			}
		}
	}
}
void Shellsort(unsigned int array3[])
{
	int j, dk;
	for (dk = _COUNT / 2; dk > 0; dk /= 2)
		for (j = dk; j < _COUNT; j++)//从数组第dk个元素开始
			if (array3[j] < array3[j - dk])//每个元素与自己组内的数据进行直接插入排序
			{
				int temp = array3[j];
				int k = j - dk;
				while (k >= 0 && array3[k] > temp)
				{
					array3[k + dk] = array3[k];//记录后移,直到找到插入位置
					k -= dk;
				}
				array3[k + dk] = temp;//还原
			}
}
void quicksort(unsigned int array4[], int low, int high)
{
	int middle;
	if (low >= high)
		return;//low>high就结束了
	middle = split(array4, low, high);//
	quicksort(array4, low, middle - 1);
	quicksort(array4, middle + 1, high);//递归调用
}
int split(unsigned int array4[], int low, int high)
{
	int part_element = array4[low];//保存array4[low]
	for (;;)
	{
		while (low < high && part_element <= array4[high])
			high--;//比该元素array4[high]大的,high就减1
		if (low >= high)
			break;//low大于等于high,说明该数组已经全部访问完了
		array4[low++] = array4[high];//排序

		while (low < high && array4[low] <= part_element)
			low++;//比该元素array4[high]小的,low就加1
		if (low >= high)
			break;
		array4[high--] = array4[low];//排序
	}
	array4[high] = part_element;//复原
	return high;
}
void SelectSort(unsigned int array5[])
{
	int i, j;
	for (i = 0; i < _COUNT - 1; i++)
	{
		int k = i;
		for (j = i + 1; j <= _COUNT - 1; ++j)//在数组里找最小关键字
			if (array5[j] < array5[k])
				k = j;//k记录
		if (k != i)
		{
			array5[i] ^= array5[k];
			array5[k] ^= array5[i];
			array5[i] ^= array5[k];//位运算,交换数值
		}
	}
}
void Swap(unsigned int* num_a, unsigned int* num_b)
{
	*num_a ^= *num_b;
	*num_b ^= *num_a;
	*num_a ^= *num_b;//保证建立的是大根堆
}

// array是待调整的堆数组,i是待调整的数组元素的位置,nlength是数组的长度
void HeapAdjust(unsigned int array6[], int i, int nLength)
{
	int nChild, nTemp;
	for (nTemp = array6[i]; 2 * i + 1 < nLength; i = nChild)
	{
		// nChild:左子结点的位置是 父结点位置*2+1
		nChild = 2 * i + 1;
		// 得到子结点中较大的结点
		if (nChild != nLength - 1 && array6[nChild + 1] > array6[nChild])
			++nChild;
		// 如果较大的子结点大于父结点那么把较大的子结点往上移动,替换它的父结点
		if (nTemp < array6[nChild])
		{
			array6[i] = array6[nChild];
		}
		else  // 否则退出循环
		{
			break;
		}
	}
	// 最后把需要调整的元素值放到合适的位置
	array6[i] = nTemp;
}
// 堆排序算法
void HeapSort(unsigned int array6[])
{
	// 调整序列的前半部分元素,（即每个有孩子的节点）调整完之后是一个大顶堆，第一个元素是序列的最大的元素
	for (int i = _COUNT / 2 - 1; i >= 0; --i)
	{
		HeapAdjust(array6, i, _COUNT);
	}
	// 从最后一个元素开始对序列进行调整,不断的缩小调整的范围直到第一个元素
	for (int i = _COUNT - 1; i > 0; --i)
	{
		// 把第一个元素和当前的最后一个元素交换,
		// 保证当前的最后一个位置的元素都是在现在的这个序列之中最大的
		Swap(&array6[0], &array6[i]);
		// 不断缩小调整heap的范围,每一次调整完毕保证第一个元素是当前序列的最大值
		HeapAdjust(array6, 0, i);
	}
}
// 归并排序中的合并算法
void Merge(unsigned int array7[], int left, int m, int right)
{
	int aux[_COUNT] = { 0 }; // 临时数组,若不使用临时数组，将两个有序数组合并为一个有序数组比较麻烦
	int i; //第一个数组索引
	int j; //第二个数组索引
	int k; //临时数组索引

	for (i = left, j = m + 1, k = 0; k <= right - left; k++) // 分别将 i, j, k 指向各自数组的首部
	{
		//若 i 到达第一个数组的尾部，将第二个数组余下元素复制到 临时数组中
		if (i == m + 1)
		{
			aux[k] = array7[j++];
			continue;
		}
		//若 j 到达第二个数组的尾部，将第一个数组余下元素复制到 临时数组中
		if (j == right + 1)
		{
			aux[k] = array7[i++];
			continue;
		}
		//如果第一个数组的当前元素 比 第二个数组的当前元素小，将 第一个数组的当前元素复制到 临时数组中
		if (array7[i] < array7[j])
		{
			aux[k] = array7[i++];
		}
		//如果第二个数组的当前元素 比 第一个数组的当前元素小，将 第二个数组的当前元素复制到 临时数组中
		else
		{
			aux[k] = array7[j++];
		}
	}
	//将有序的临时数组 元素 刷回 被排序的数组 array 中，
	//i = left , 被排序的数组array 的起始位置
	//j = 0， 临时数组的起始位置
	for (i = left, j = 0; i <= right; i++, j++)
	{
		array7[i] = aux[j];
	}
}
// 归并排序
void MergeSort(unsigned int array7[], int low, int high)
{
	if (low < high)
	{
		int i;
		i = (high + low) / 2;
		// 对前半部分进行排序
		MergeSort(array7, low, i);
		// 对后半部分进行排序
		MergeSort(array7, i + 1, high);
		// 合并前后两部分
		Merge(array7, low, i, high);
	}
}
