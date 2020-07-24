
#include <iostream>
#include <list>
using namespace std;

void sortCocktailStyle(list<int>& dl)
{
	bool swapped = true;

	list<int>::iterator begin = dl.begin();
	list<int>::iterator end = dl.end();

	while (swapped)
	{
		swapped = false;
		for (list<int>::iterator it = begin; it != end; ++it)
		{
			list<int>::iterator next(it);
			++next;

			if (next == end) break;
			if (*it > * next)
			{
				swap(*it, *next);
				swapped = true;
			}
		}
		if (!swapped)
			break;
		swapped = false;

		--end;
		for (list<int>::iterator it = begin; it != end; ++it)
		{
			list<int>::iterator prev(it);
			--prev;
			if (*prev > * it)
			{
				swap(*it, *prev);
				swapped = true;
			}
		}
		++begin;
	}
}
template <typename T>
void SelectionSort(T array[], unsigned size)
{
    for(int i = 0; i < size; i++)
    {
        int min = i;
        for(int j = i; j < size; j++)
        {
            if(array[min] > array[j])
            {
                min = j;
            }
        }
        swap(array[min], array[i]);
    }
}
int partition(int arr[], int low, int high)
{
   int pivot = arr[high];
   int i = (low - 1);
   for(int j = low; j <= high - 1; ++j)
   {
       if(arr[j] < pivot)
       {
           i++;
           swap(arr[i],arr[j]);
       }
   }
   swap(arr[i+1], arr[high]);
   return (i+1);
}
void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
int main(int argc, char const* argv[])
{
	/*list<int> dl;
	dl.push_back(5);
	dl.push_back(12);
	dl.push_back(-3);
	dl.push_back(2);
	dl.push_back(75);
	dl.push_back(120);


	 sortCocktailStyle(dl);
	 for (list<int>::iterator it = dl.begin(); it != dl.end(); ++it)
	 {
		 cout << *it << ' ';
	 }
	 cout << endl;*/

	 int arr[] = {1, 2,5 ,3 ,4 ,5, 6, 2 ,78,12};
	 ///SelectionSort(arr, 10);
	 int n = sizeof(arr) / sizeof(arr[0]);
	 quickSort(arr, 0, n-1);

    printArray(arr, n);
}
