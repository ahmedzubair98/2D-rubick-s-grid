template <class T>
class que
{
public:
	que(int size);
	~que();
	bool enque(T item);
	bool deque(T &item);
	bool deque();
	bool empty();
	bool full();

private:
	T *arr;
	int front;
	int rear;
	int maxSize;
};

template <class T>
que<T>::que(int size)
{
	arr = new T[size];
	front = rear = -1;
	maxSize = size;
}
template <class T>
que<T>::~que()
{
	delete[] arr;
}
template <class T>
bool que<T>::full()
{
	if ((rear + 1 % maxSize == front))
		return true;
	return false;
}
template <class T>
bool que<T>::empty()
{
	if (rear == -1)
		return true;
	return false;
}
template <class T>
bool que<T>::enque(T item)
{
	bool flag = full();
	if (!flag)
	{
		if (empty())
			front = 0;
		rear = (rear + 1) % maxSize;
		arr[rear] = item;
	}
	return !flag;
}
template <class T>
bool que<T>::deque(T &item)
{
	bool flag = empty();
	if (!flag)
	{
		item = arr[front];
		if (front == rear)
			front = rear = -1;
		else
			front = (front + 1) % maxSize;
	}
	return !flag;
}
template <class T>
bool que<T>::deque()
{
	bool flag = empty();
	if (!flag)
	{
		if (front == rear)
			front = rear = -1;
		else
			front = (front + 1) % maxSize;
	}
	return !flag;
}