int (*cmp)(const void *q,const void *p);
qsort(s, n, sizeof(s[0]), cmp);
int cmp(const void *q,const void *p)
{
	return *(int*)q-*(int*)p;//由小到大
	//return *(int*)p-*(int*)q;由大到小
}
/*如果越界，换板子*/

int cmp(const void *q,const void *p)
{
	return *(int*)q>*(int*)p;
}

//for example
/*
#include<bits/stdc++.h>
using namespace std;

int cmp(const void *q,const void *p)
{
    return *(int*)q>*(int*)p;
}

int s[100014];

int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>s[i];
    qsort(s,n,sizeof(s[0]),cmp);
    for(int i=0;i<n;i++)
        cout<<s[i];
    return 0;
}
*/

//sort
//for example
/*
#include<bits/stdc++.h>
using namespace std;

int cmp(const int &q,const int &p)
{
    return q>p?1:0;
}

int s[100014];

int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>s[i];
    sort(s,s+n,cmp);
    for(int i=0;i<n;i++)
        cout<<s[i];
    return 0;
}
*/
//此处的sort默认排序为升序排序的，进行降序排序就要用cmp