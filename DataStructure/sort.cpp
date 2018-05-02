#include <iostream>  
using namespace std;
void quickSort(int s[], int, int); //快排
void bubbleSort(int arr[], int); //冒泡排序

int main()
{
	int array[] = { 34,65,12,43,67,5,78,10,3,70 }, k;
	int len = sizeof(array) / sizeof(int);
	cout << "The orginal arrayare:" << endl;
	for (k = 0; k<len; k++)
		cout << array[k] << ",";
	cout << endl;
	//quickSort(array, 0, len - 1); // 快速排序
	bubbleSort(array, len); // 冒泡排序
	cout << "The sorted arrayare:" << endl;
	for (k = 0; k<len; k++)
		cout << array[k] << ",";
	cout << endl;
	system("pause"); 
	return 0;
}

void bubbleSort(int arr[],int length) // 冒泡排序
{
	for (int i = 0; i < (length-1); ++i) // 固定第一个游标
	{
		for (int j = i + 1; j < length; ++j) // 移动第二个游标，每次和i比较，如果小于i，就交换
		{
			if (arr[j] < arr[i])
			{
				swap(arr[i],arr[j]);
			}		
		}
	}
}

void quickSort(int s[], int l, int r) // 快速排序
{
	if (l< r)
	{
		int i = l, j = r, x = s[l];
		while (i < j)
		{
			while (i < j && s[j] >= x) // 从右向左找第一个小于x的数  
				j--;
			if (i < j)
				s[i++] = s[j];
			while (i < j && s[i]< x) // 从左向右找第一个大于等于x的数  
				i++;
			if (i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		quickSort(s, l, i - 1); // 递归调用  
		quickSort(s, i + 1, r); // 递归调用
	}
}