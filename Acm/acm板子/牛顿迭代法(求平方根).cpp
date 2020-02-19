int sqrt(double x) { 
    if(x == 0) return 0; 
    double result = x; 
    double xhalf = 0.5*result; 
    int i = *(int*)&result; 
    i = 0x5f375a86- (i>>1); // what the fuck? 
    result = *(float*)&i; 
    result = result*(1.5-xhalf*result*result); // Newton step, repeating increases accuracy 
    result = result*(1.5-xhalf*result*result); 
    return 1.0/result; 
}//this is copy,and there is a story


int sqrt(int x)
{
	if(x<=0)
		return 0;
	if(x==1)
		return 1;
	int left=1,right=x/2;
	long long mid,tot=0;
	while(left<=right)
	{
		mid=(left+roght)/2;
		tot=mid*mid;
		if(tot==x)
			return mid;
		else if(tot>x)
			right=mid-1;
		else
			left=mid+1;
	}
	return right;
}//二分法，只适合整型

double NewtonMethod(double y)
{
	double x = 1.0;
	while(abs(x*x-y) > 1e-5)
	{
		x = (x+y/x)/2;
	}
	return x;
}