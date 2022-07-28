#include "./IO.cpp"

void merger(vector<int> &input, vector<int> &temp, int start, int end)
{
    int mid = (start + end) / 2;

    int i = start, j = mid + 1;
    int k = start;

    while (i <= mid && j <= end)
    {
        if (input[i] < input[j])
        {
            temp[k++] = input[i++];
        }
        else
        {
            temp[k++] = input[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = input[i++];
    }

    while (j <= end)
    {
        temp[k++] = input[j++];
    }

    for (int i = start; i <= end; i++)
    {
        input[i] = temp[i];
    }
}

void mergeSort(vector<int> &input, vector<int> &temp, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;

        mergeSort(input, temp, start, mid);
        mergeSort(input, temp, mid + 1, end);
        merger(input, temp, start, end);
    }
}

int main()
{
    IO();
    int n;
    cin >> n;
    vector<int> input(n);
    for (int &x : input)
    {
        cin >> x;
    }
    int start = 0;
    int end = n - 1;
    vector<int> temp(n);

    mergeSort(input, temp, start, end);
    for (int x : input)
    {
        cout << x << " ";
    }
    cout << endl;
}