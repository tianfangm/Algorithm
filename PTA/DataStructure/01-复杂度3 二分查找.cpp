Position BinarySearch( List L, ElementType X )
{
    int left = 1,right = L->Last;
    while(left<=right)
    {
        int mid = (left+right)>>1;
        int num = L->Data[mid];
        if(num==X)
        {
            return mid;
        }
        else if(num>X)
        {
            right = mid -1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return NotFound;
}
