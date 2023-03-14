// Copyright 2021 NNTU-CS
void Sort(int arr[], int size)
{
    int k = 0;
    int i = 0;
    for (int j = 1; j < size; j++) {
        k = arr[j];
        i = j - 1;
        while (i >= 0 && arr[i] > k) {
            arr[i + 1] = arr[i];
            i = i - 1;
            arr[i + 1] = k;
        }
    }
}

int countPairs1(int* arr, int len, int value)
{
    Sort(arr, len);
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = len-1; j >= 0; --j) {
            if (arr[i] + arr[j] == value) {
                count += 1;
            }
            else if (arr[i] + arr[j] < value) {
                break;
            }
        }
        continue;
    }
    return count / 2;
}
int countPairs2(int* arr, int len, int value)
{
    Sort(arr, len);
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                count += 1;
            }
            else if (arr[i] + arr[j] > value) {
                break;
            }
        }
        continue;
    }
    return count / 2;
}
int countPairs3(int* arr, int len, int value)
{
    Sort(arr, len);
    int count = 0;
    for (int i = 0; i < len - 1; i++)
    {
        int l = i, r = len;

        while (1 < r - l)
        {
            int center = (l + r) / 2;
            if (arr[i] + arr[center] == value)
            {
                count++;
                int j = center + 1;
                while (arr[i] + arr[j] == value && j < r)
                {
                    count++;
                    j++;
                }
                j = center - 1;
                while (arr[i] + arr[j] == value && j > l)
                {
                    count++;
                    j--;
                }
                break;
            }
            if (arr[i] + arr[center] > value)
                r = center;
            else
                l = center;
        }

    }
    return count;
}
