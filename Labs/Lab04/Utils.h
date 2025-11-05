#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <string>
#include <sstream>
#include <initializer_list>
#include <stdexcept>

#define Parent(X) (((X) - 1) / 2)
#define Left(X) (2*(X) + 1)
#define Right(X) (2*(X) + 2)

namespace aa
{
	class Object 
	{
		public:
		virtual std::string toString() const = 0;

		friend std::ostream& operator<<(std::ostream& out,const Object& obj)
		{
			out << obj.toString();
			return out;
		}
	};

	template<class T>
	class Heap : public Object
	{
		private:
		T* data;
		size_t sizes[2];
		int view;
		
		public:
		Heap() : Heap(T(),20) {}
		
		Heap(size_t cp) : sizes{cp,0}, view(1)
		{
			if(sizes[0] == 0) {sizes[0] = 20;}
			data = new T[sizes[0]];

			for(size_t i = 0;i < sizes[0];i += 1)
			{
				data[i] = T();
			}
		}

		Heap(std::initializer_list<T> lt)
		{
			sizes[0] = lt.size();
			sizes[1] = 0;
			view = 1;
			
			if(sizes[0] == 0)
			{
				throw std::length_error("too small");
			}
			data = new T[sizes[0]];
			size_t i = 0;

			for(const T& x : lt)
			{	
				data[i] = x;
				i += 1;
			}
		}

		Heap(const Heap<T>& obj)
		{
			sizes[0] = obj.sizes[0];
			sizes[1] = obj.sizes[1];
			view = obj.view;
			data = new T[sizes[0]];

			for(size_t i = 0;i < sizes[0];i += 1)
			{
				data[i] = obj.data[i];
			}
		}

		Heap<T>& operator=(const Heap<T>& rhs)
		{
			if(this != &rhs)
			{
				sizes[0] = rhs.sizes[0];
				sizes[1] = rhs.sizes[1];
				view = rhs.view;
				delete[] data;
				data = new T[sizes[0]];

				for(size_t i = 0;i < sizes[0];i += 1)
				{
					data[i] = rhs.data[i];
				}
			}
			return *this;
		}

		Heap<T>& operator=(std::initializer_list<T> lt)
		{
			if(lt.size() != 0)
			{
				sizes[0] = lt.size();
				sizes[1] = 0;
				view = 1;
				size_t i = 0;
				delete[] data;
				data = new T[sizes[0]];

				for(const T& x : lt)
				{	
					data[i] = x;
					i += 1;
				}
			}
			return *this;
		}

		~Heap() {delete[] data;} 

		size_t size() const {return sizes[1];}

		size_t length() const {return sizes[0];}

		void heapView(bool value) 
		{
			view = (value)?(1):(0);
		}

		void size(size_t value) 
		{
			if(value <= sizes[0])
			{
				sizes[1] = value;
			}
		}	

		T& operator[](size_t idx)
		{
			if(idx >= sizes[view])
			{
				throw std::out_of_range("out of bound");
			}
			return data[idx];
		}
	
		const T& operator[](size_t idx) const
		{
			if(idx >= sizes[view])
			{
				throw std::out_of_range("out of bound");
			}
			return data[idx];
		}

		std::string toString() const override
		{
			std::stringstream out;

			out << "[";

			for(size_t i = 0;i < sizes[view];i += 1)
			{
				out << data[i];

				if((i + 1) < sizes[view]) 
				{
					out << ",";
				}
			}
			out << "]";
			return out.str();
		}
	};	
	
	template <class V>
	class Pair : public Object
	{
		private:
		size_t key;
		V value;
		
		public:
		Pair() : Pair(0,V()) {}

		Pair(size_t key,const V& value) : key(key), value(value) {}
		
		Pair(const Pair<V>& obj) 
		{
			key = obj.key;
			value = obj.value;
		}

		Pair<V>& operator=(const Pair<V>& rhs)
		{
			if(this != &rhs)
			{
				  key = rhs.key;
				  value = rhs.value;
			}
			return *this;
		}

		~Pair() {}

		size_t Key() const {return key;}

		size_t& Key() {return key;}

		const V& Value() const {return  value;}

		V& Value() {return value;}	

		std::string toString() const override
		{
			std::stringstream out;
			out << value;
			return out.str();
		}
	};
}

#endif
