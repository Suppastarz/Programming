#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <class Nim>
class Range
{
private:
	Nim start, end, step;
	std::vector<Nim> value;
public:
	Range(Nim s = 1, Nim e = 1, Nim step = 1) : start(s), end(e), step(step)
	{
		Nim sum = start;
		if (step > 0)
		{
			//while (sum < (end - step))
			while (sum < end)
			{
				if ((sum + step) > end)
					break;
				value.push_back(sum);
				sum += step;
			}
		}
		if (step < 0)
		{
			
			while (sum > end)
			{
				if ((sum + step) < end)
					break;
				value.push_back(sum);
				sum += step;
			}

		}
		value.push_back(sum);
	}

	int length()
	{
		int count = 0;
		for (Nim n : values())
			count++;
		return count;
	}

	Nim sum()
	{
		Nim sum = 0;
		for (Nim n : value)
			sum += n;
		/*double sum = start;
		if (step > 0)
		{
			while (sum < double(end - step))
			{
				sum += step;
			}
		}
		else if (step < 0)
		{
			while (sum > double(end + step))
			{
				sum += step;
			}

		}*/
		return sum;
	};

	Nim average()
	{
		return double(sum() / length());
	}

	Nim min()
	{
		Nim a;
		int count = 0;
		Nim lowest = start;
		for (Nim n : values())
		{
			if (count == 0)
				a = n;
			if (n < a)
				lowest = n;
			count++;
		}
		return lowest;
	}
	Nim max()
	{
		Nim a;
		int count = 0;
		Nim highest = start;
		for (Nim n : values())
		{
			if (count == 0)
				a = n;
			if (n > a)
				highest = n;
			count++;
		}
		return highest;
	}

	std::vector<Nim> values()
	{
		/*std::vector<Nim> value;
		for (Range<Nim> i : values)
		{
			value.push_back(i);
		}*/
		return value;
	}
	/*
	vector<double> value()
	{
		return values;
		
		return r;
	}
	*/
	friend std::ostream& operator<<(ostream& out, Range& me)
	{

		//out << me.value();
		for (Nim n: me.values())
		{
			out << n << " ";
		}
		
		return out;
	}
};
