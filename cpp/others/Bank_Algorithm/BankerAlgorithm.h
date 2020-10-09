/*
 * > 银行家避免死锁算法
 * > Author:incipe
 * > Language:h
 * > File Name:Banker_Algorithm.h
 * > Created Time:Mon Nov 4 21:33:04 2019
 * > Email:chaoh7461@gmail.com
 */

#ifndef _BankerAlgorithm_
#define _BankerAlgorithm_

class BA {
public:
	void Init();
	bool Safe();
	void Banker();
	void Show();
};

#endif //_BankerAlgorithm_