//problem 21
//we use m_data to represent  main stack
//we use m_min  to represent  aided stack

template<typename T>
void StackWithMin<T>::push(const T& val)
{
	m_data.push(val);
	
	
	if(m_min.size()==0||val<m_min.top())
	{
		m_min.push(val);
	}
	else
	{
		m_min.push(m_min.top());
	}
	
	return ;
}

template<typename T>
T StackWithMin<T>::top()
{
	assert(m_data.size()>0);
	return m_data.top();
	
}

template<typename T>
void StackWithMin<T>::pop()
{
	assert(m_data.size()>0&&m_min.size()>0);
	m_data.pop();
	m_min.pop();
}

template<typename T>
T StackWithMin<T>::min()
{
	assert(m_data.size()>0&&m_min.size()>0);//notice here!
	T tmp= m_min.top();
	m_min.pop();
	
	return tmp;
}