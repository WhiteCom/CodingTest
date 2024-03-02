#include <stdio.h>

int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int arr[10] = {0,};
	
	int inp;
	scanf("%d",&inp);
	
	char ch[8];
	sprintf(ch,"%d",inp);
	
	for(int i=0;ch[i];i++)
	{
		int idx = ch[i]-48;
		arr[idx]++;
	}
	
	int sum = arr[6] + arr[9];
	if(sum % 2 == 0)
		arr[6] = arr[9] = sum/2;
	else if(sum%2==1)
		arr[6] = arr[9] = sum/2 + 1;
	
	int cnt=0;
	for(int i=0;i<10;i++)
	{
		if(arr[i])
			cnt = max(cnt,arr[i]);
	}
	printf("%d\n",cnt);
	
	return 0;
}
