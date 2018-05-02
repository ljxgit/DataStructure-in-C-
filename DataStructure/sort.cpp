#include <iostream>  
using namespace std;
void quickSort(int s[], int, int); //����
void bubbleSort(int arr[], int); //ð������

int main()
{
	int array[] = { 34,65,12,43,67,5,78,10,3,70 }, k;
	int len = sizeof(array) / sizeof(int);
	cout << "The orginal arrayare:" << endl;
	for (k = 0; k<len; k++)
		cout << array[k] << ",";
	cout << endl;
	//quickSort(array, 0, len - 1); // ��������
	bubbleSort(array, len); // ð������
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

void quickSort(int s[], int l, int r) // ��������
{
	if (l< r)
	{
		int i = l, j = r, x = s[l];
		while (i < j)
		{
			while (i < j && s[j] >= x) // ���������ҵ�һ��С��x����  
				j--;
			if (i < j)
				s[i++] = s[j];
			while (i < j && s[i]< x) // ���������ҵ�һ�����ڵ���x����  
				i++;
			if (i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		quickSort(s, l, i - 1); // �ݹ����  
		quickSort(s, i + 1, r); // �ݹ����
	}
}