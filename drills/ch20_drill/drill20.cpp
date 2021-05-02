#include <vector>
#include <iostream>
#include <list>
#include <array>
#include <algorithm>


template<typename T>
void incr(T& val, int x)
{
	for(auto& p:val)
	{
		p+=x;
	}
}

template<typename Type>
void where(Type con, int x)
{
	auto p = std::find(con.begin(),con.end(),x);
	if(p!=con.end())
	{
		std::cout<<"Keresett elem a  " << std::distance(con.begin(),p)+1
			<< ". helyen van\n";
	}
	else std::cout<< "nincs benne\n";
}

template<typename Iter1, typename Iter2> 
Iter2 ccopy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	while(f1!=e1){
		*f2 = *f1;
		++f2;
		++f1;
	}
	return f2;
}

int main()
{
	std::array<int,10> a {0,1,2,3,4,5,6,7,8,9};
	std::vector<int> v {0,1,2,3,4,5,6,7,8,9};
	std::list<int> l {0,1,2,3,4,5,6,7,8,9};

	std::array<int,10> a2 = a;
	std::vector<int> v2 = v;
	std::list<int> l2 = l;

	incr(a2,2);
	incr(v2,3);
	incr(l2,5);

	ccopy(a2.begin(),a2.end(),v2.begin());
	ccopy(l2.begin(),l2.end(),a2.begin());

	where(v2,3);
	where(l2,27);
	
	return 0;
}