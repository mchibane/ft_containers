#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

#include <cstddef>
#include "iteratorTags.hpp"

namespace ft
{
	template<class Iterator>
	class iteratorTraits
	{
	public:
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template<class T>
	class iteratorTraits<T*>
	{
	public:
		typedef ptrdiff_t					difference_type;
		typedef T							value_type;
		typedef T*							pointer;
		typedef T&							reference;
		typedef random_access_iterator_tag	iterator_category;
	};

	template<class T>
	class iteratorTraits<const T*>
	{
	public:
		typedef ptrdiff_t					difference_type;
		typedef T							value_type;
		typedef const T*					pointer;
		typedef const T&					reference;
		typedef random_access_iterator_tag	iterator_category;
	};

};

#endif
