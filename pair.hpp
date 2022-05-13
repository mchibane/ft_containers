#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft
{
		/* PAIR CLASS */

	template<class T1, class T2>
	struct pair
	{
		typedef typename T1	first_type;
		typedef typename T2	second_type;

		first_type	first;
		second_type	second;

			/* CONSTRUCTORS */

		// DEFAULT
		pair(void) : first(T1()), second(T2()) {}

		// COPY
		template<class U, class V>
		pair(const pair<U, V> &pr) : first(pr.first), second(pr.second) {}

		// INIT
		pair(first_type const &a, second_type const &b) : first(a), second(b) {}


			/* COPY OPERATOR */

		pair &operator=(pair const &pr)
		{
			first = pr.first;
			second = pr.second;
			return (*this);


		}
	};


		/* RELATIONAL OPERATORS */

	template<class T1, class T2>
	bool	operator==(pair<T1, T2> const &lhs, pair<T1, T2> const &rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template<class T1, class T2>
	bool	operator<(pair<T1, T2> const &lhs, pair<T1, T2> const &rhs)
	{
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && (lhs.second < rhs.second)));
	}

	template<class T1, class T2>
	bool	operator!=(pair<T1, T2> const &lhs, pair<T1, T2> const &rhs) { return (!(lhs == rhs)); }

	template<class T1, class T2>
	bool	operator<=(pair<T1, T2> const &lhs, pair<T1, T2> const &rhs) { return (!(rhs < lhs)); }

	template<class T1, class T2>
	bool	operator>(pair<T1, T2> const &lhs, pair<T1, T2> const &rhs) { return (rhs < lhs); }

	template<class T1, class T2>
	bool	operator>=(pair<T1, T2> const &lhs, pair<T1, T2> const &rhs) { return (!(lhs < rhs)); }


		/* MAKE PAIR FUNCTION */

	template<class T1, class T2>
	pair<T1, T2>	make_pair(T1 x, T2 y)
	{
		return (pair<T1, T2>(x, y));
	}
};

#endif
