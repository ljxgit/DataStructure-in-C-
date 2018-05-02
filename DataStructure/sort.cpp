#include <iostream>  
#include <vector>
using namespace std;
void quickSort(int s[], int, int); //����
void bubbleSort(int arr[], int); //ð������
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
	//quickSort(array, 0, len - 1); // ��������
	//bubbleSort(array, len); // ð������
	int result[len];
	mergeSort(array, 0, len - 1, result); // �鲢����
	cout << "The sorted arrayare:" << endl;
	for (k = 0; k<len; k++)
		cout << array[k] << ",";
	cout << endl;
	system("pause"); 
	return 0;
}

void bubbleSort(int arr[],int length) // ð������
{
	for (int i = 0; i < (length-1); ++i) // �̶���һ���α�
	{
		for (int j = i + 1; j < length; ++j) // �ƶ��ڶ����α꣬ÿ�κ�i�Ƚϣ����С��i���ͽ���
		{
			if (arr[j] < arr[i])
			{
				swap(arr[i],arr[j]);
			}		
		}
	}
}

void quickSort(int arr[], int l, int r) // ��������
{
	if (l< r)
	{
		int i = l, j = r, x = arr[l];
		while (i < j)
		{
			while (i < j && arr[j] >= x) // ���������ҵ�һ��С��x����  
				j--;
			if (i < j)
				arr[i++] = arr[j];
			while (i < j && arr[i]< x) // ���������ҵ�һ�����ڵ���x����  
				i++;
			if (i < j)
				arr[j--] = arr[i];
		}
		arr[i] = x;
		quickSort(arr, l, i - 1); // �ݹ����  
		quickSort(arr, i + 1, r); // �ݹ����
	}
}

void merge(int arr[], int start, int end, int result[])
{
	// �������������������кϲ�Ϊһ����������
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
// �鲢���򣬺ϲ����������б���Ϊû��Python����Ƭ���ܣ�ֻ����һ���ڴ������ϲ��������Բ���ָ�룬��start��end��Ϊ��������
{
	if (start == end) // ֻ��һ��Ԫ�أ�ֱ�ӷ��أ����޸�
		return;
	else // ����������Ҳ��ּ������֣�ֱ��ֻ��һ��Ԫ��
	{
		mergeSort(arr, start, (end - start + 1) / 2 + start-1, result); // ���ֵ�ֻʣһ��Ԫ��
		mergeSort(arr, (end - start + 1) / 2 + start , end, result);
		merge(arr,start,end,result); // ��ʼ�ϲ�
		for (int i = start; i <= end; ++i)
			arr[i] = result[i];
	}
}