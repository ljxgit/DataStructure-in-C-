#include <iostream>  
#include <vector>
using namespace std;
void quickSort(int s[], int, int); //快排
void bubbleSort(int arr[], int); //冒泡排序
void merge(int arr[], int start, int end, int result[]);
void mergeSort(int arr[], int start, int end, int result[]);


int main()
{
	int array[] = { 34,65,12,43,67,5,78,10,3,70 }, k;
	const int len = sizeof(array) / sizeof(int);
	cout << "The orginal arrayare:" << endl;
	for (k = 0; k<len; k++)
		cout << array[k] << ",";
	cout << endl;
	//quickSort(array, 0, len - 1); // 快速排序
	//bubbleSort(array, len); // 冒泡排序
	int result[len];
	mergeSort(array, 0, len - 1, result); // 归并排序
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

void quickSort(int arr[], int l, int r) // 快速排序
{
	if (l< r)
	{
		int i = l, j = r, x = arr[l];
		while (i < j)
		{
			while (i < j && arr[j] >= x) // 从右向左找第一个小于x的数  
				j--;
			if (i < j)
				arr[i++] = arr[j];
			while (i < j && arr[i]< x) // 从左向右找第一个大于等于x的数  
				i++;
			if (i < j)
				arr[j--] = arr[i];
		}
		arr[i] = x;
		quickSort(arr, l, i - 1); // 递归调用  
		quickSort(arr, i + 1, r); // 递归调用
	}
}

void merge(int arr[], int start, int end, int result[])
{
	// 把左右两部分有序序列合并为一个有序序列
	int mid = (end - start + 1) / 2 + 1;
	int left_idx = start;
	int right_idx = start + mid;
	int result_idx = start;
	while (left_idx < start + mid && right_idx < end + 1)
	{
		if (arr[left_idx] < arr[right_idx])
			result[result_idx++] = arr[left_idx++];
		else
			result[result_idx++] = arr[right_idx++];
	}
	while (left_idx < start + mid)
		result[result_idx++] = arr[left_idx++];
	while (right_idx < end + 1)
		result[result_idx] = arr[right_idx++];
}

void mergeSort(int arr[], int start, int end, int result[]) 
// 归并排序，合并两个有序列表，因为没有Python的切片功能，只能在一个内存数组上操作，所以采用指针，把start、end作为参数传入
{
	if (start == end) // 只有一个元素，直接返回，不修改
		return;
	else // 把数组的左、右部分继续划分，直到只有一个元素
	{
		mergeSort(arr, start, (end - start + 1) / 2 + start-1, result); // 划分到只剩一个元素
		mergeSort(arr, (end - start + 1) / 2 + start , end, result);
		merge(arr,start,end,result); // 开始合并
		for (int i = start; i <= end; ++i)
			arr[i] = result[i];
	}
}