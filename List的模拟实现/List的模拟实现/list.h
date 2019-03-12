#pragma
#include<iostream>
using namespace std;
template<class T>
struct _ListNode
{
	T _data;
	_ListNode<T>* _prev;
	_ListNode<T>* _next;

	_ListNode(const T& x=T())
		:_data(x)
		,_next(nullptr)
		, _prev(nullptr)
	{}
};

template<class T,class Ref,class Ptr>
struct _ListIterator
{
	typdef _ListNode<T> Node;
	typedef _ListIterator<T,Ref,Ptr> Self;
	Node* _node;

	_ListIterator(Node* node)
		:_node(node)
	{}

	Ref operator*()
	{
		return _node->data;
	}

	Ptr operator->()
	{
		return &_node->_data;
	}
	//++it;->it.operator++(&it)
	Self& operator++()//Ç°ÖÃ++
	{
		_node = node->_next;
		return *this;
	}

	Self operator++()//ºóÖÃ++
	{
		Self tmp(*this);
		_node = _node->_next;
		return tmp;
	}

	Self& operator--()
	{
		_node = _node->prev;
		return *this;
	}

	Self operator--()
	{
		Self tmp(*this);
		_node = _node->prev;
		return tmp;
	}
	bool operator !=(const Slef& s)
	{
		return _node != s._node;
	}
	 
	bool operator==(const Self& s)
	{
		return _node == s._node;
	}
};

template<class T>
class List
{
	typedef _ListNode<T> Node;
public:
	typedef _ListIterator<T,T&,T*> iterator;
	typedef _ListIterator<T,const T&,const T*> const_iterator;
	iterator begin()
	{
		return iterator(_head->_next);
	}

	iterator end()//×ó±ÕÓÒ¿ª
	{
		return iterator(_head);
	}

	const_iterator begin() const
	{
		return iterator(_head->_next);
	}

	const_iterator end() const
	{
		return iterator(_head);
	}
	List()
	{
		_head = new Node;
		_head->_prev = _head;
		_head->_next = _head;
	}
	List(const List<T>& l)
	{
		_head = new Node;
		_head->_data = _head;
		_head->_prev = _head;
		
		const_itreator it = l.begin();
		while (it != l.end())
		{
			PushBack(*it);
			++it;
		}
	}
	List<T>& operator=(const List<T>& l)
	{
		swap(_head, l._head);
		return *this;
	}

	~List()
	{
		Clear();
		_head = nullptr;
	};
	size_t Size()
	{
		size_t size = 0;
		for (const auto& e : *this)
		{
			++size;
		}
		return size;
	}

	bool Empty()
	{
		return _head->_next == _head->_prev;//begin()==end()

	}
	void Clear()
	{
		Node* cur = _head->_next;
		while (cur != _head)
		{
			Node* next = cur->_next;
			delete cur;
			cur = next;
		}
		_head->_next = _head;
		_head->_prev = _head;
	}

	void PushBack(const T& x)
	{
		
	/*	Node* newnode = new Node(x);
		Node* tail = _head->_prev;
		tail->_next = newnode;
		newnode->_prev = tail;
		newnode->_next = _head; 
		_head->_prev = newnode;*/
		Insert(end(), x);
	}
	void PopBack(const T& x)
	{
		Erase(--end);
	}
	void PopFront(const T& x)
	{
		Erase(begin());
	}
	void PushFront(const T& x)
	{
		Insert(begin(), x);
	}
	void Insert(iterator pos, const T& x)
	{
		Node* newnode = new Node(x);
		Node* cur = pos._node;
		Node* prev = cur->_prev;
		prev->_next = newnode;
		newnode->_prev = prev;
		newnode->_next = cur;
		cur->_prev = newnode;
	}
	void Erase(iterator pos)
	{
		Node* cur = pos._node;
		Node* prev = cur->_prev;
		Node* next = cur->_next;
		prev->_next = next;
		next->_prev = prev;

	}

private:
	Node* _head;
	 
};