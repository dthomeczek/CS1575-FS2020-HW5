/* Define all your MyList-related functions here, including the get_identity
    function
 * You do not need to include MyList.h in this hpp header file. It includes
    this file at the bottom.
 */

// The usual identity function
void get_identity(string &my_id)
{
   my_id = "djtpfr";
}

template <typename T>
MyList<T>::MyList()
{
   m_size = 0;
   m_sentinel = new Node<T>(nullptr, nullptr);
   m_sentinel -> m_prev = m_sentinel;
   m_sentinel -> m_next = m_sentinel;

   return;
}

template <typename T> 
MyList<T>::MyList(const MyList<T> &source)
{
   *this = source;

   return;
}

template <typename T>
MyList<T>::~MyList()
{
  if(m_size > 0)
  {
    Node<T> *curr = m_sentinel->m_next, *temp = nullptr;

    while(curr != m_sentinel)
    {
      temp = curr;
      curr = curr->m_next;
      delete temp;
    }
  }
  delete m_sentinel;
  m_sentinel = nullptr;
}

template <typename T> 
MyList<T> &MyList<T>::operator=(const MyList<T> &source)
{
   this -> ~MyList();
   Node<T> *temp = new Node<T>(nullptr, nullptr);
   temp = source.m_sentinel -> m_next;
   m_sentinel = new Node<T>(nullptr, nullptr);
   m_sentinel -> m_next = m_sentinel;
   m_sentinel -> m_prev = m_sentinel;
   
   for (int i=0; i<source.m_size; i++)
   {
      this -> push_back(temp -> m_element);
      temp = temp -> m_next;
   }
   
   return *this;
}

// Returns the head of the list
template <typename T> 
T &MyList<T>::front()
{ 
   return m_sentinel -> m_next -> m_element;
}

// Returns the tail of the list
template <typename T> 
T &MyList<T>::back()
{  
   return m_sentinel -> m_prev -> m_element;
}

template <typename T> 
void MyList<T>::assign(int count, const T &value)
{  // Deletes all values in the list
   while (m_size)
   {
      this -> pop_back();
   }

   // Sets up the list for the new values
   for (int i = 0; i < count; i++)
   {
      this -> push_back(value);
   }

   // Setting the size to the value of count
   m_size = count;

   return;
}

// Clears the nodes
template <typename T>
void MyList<T>::clear()
{
  if(m_size > 0)
  {
    Node<T> *temp = m_sentinel;
    Node<T> *next = nullptr;

    while(temp != nullptr)
    {
      next = temp -> m_next;
      delete temp;

      temp = next;
    }
  }
  m_sentinel = nullptr;
  m_size = 0;

  return;
}

template <typename T> 
void MyList<T>::push_front(const T &x)
{
   Node<T> *temp = new Node<T>(x, m_sentinel, m_sentinel->m_next);
   m_sentinel -> m_next -> m_prev = temp;
   m_sentinel -> m_next = temp;

   m_size++;
   
   return;
}

template <typename T> 
void MyList<T>::push_back(const T &x)
{
   Node<T> *temp = new Node<T>(x, m_sentinel->m_prev, m_sentinel);
   m_sentinel -> m_prev = temp;
   temp -> m_prev -> m_next = temp;

   m_size++;
   
   return;
}

// Utilizes an if statement to remove the last value of the list only if it exists.
template <typename T>
void MyList<T>::pop_back()
{
   if (m_size != 0)
   {
      m_sentinel -> m_prev = m_sentinel -> m_prev -> m_prev;
      m_sentinel -> m_prev -> m_next = m_sentinel;

      m_size--;
   }

   return;
}

// Utilizes an if statement to remove the last value of the list only if it exists.
template <typename T> 
void MyList<T>::pop_front()
{   
   if (m_size != 0)
   {
      m_sentinel -> m_next = m_sentinel -> m_next -> m_next;
      delete m_sentinel -> m_next -> m_prev;
      m_sentinel -> m_next -> m_prev = nullptr;
      m_sentinel -> m_next -> m_prev = m_sentinel;

      m_size--;
   }

   return;
}

template <typename T>
void MyList<T>::insert(int i, const T &x)
{
   if(i >= 0)
   {
      Node<T> *temp = m_sentinel;

      for(int j = 0; j <= i; j++)
      {
         temp = temp->m_next;
      }

      Node<T> *newNode = new Node <T>(x, temp -> m_prev, temp);
      temp -> m_prev = newNode;
      newNode -> m_prev -> m_next = newNode;

      m_size++;
   }

   return;
}

template <typename T> 
void MyList<T>::remove(T value)
{
   Node<T> *current = m_sentinel -> m_next;
   Node<T> *temp = current -> m_next;
   int count = m_size;

   // For loop to search within all the values
   for (int i = 0; i < count; i++)
   {   
      // Whenever the value is found, it is removed
      if (current -> m_element == value)
      {
         current -> m_prev -> m_next = current -> m_next;
         current -> m_next -> m_prev = current -> m_prev;

         temp = current -> m_next;

         // Decrease size by 1.
         m_size--;
            
         // Everything becomes nullptr.
         delete current;
         current = nullptr;

         current = temp;
      }
      else
      {
         current = current -> m_next;
      }
   }

   return;
}

template <typename T> 
void MyList<T>::erase(int i)
{   
   if (i >= 0 && i < m_size)
   {
      Node<T> *current = m_sentinel -> m_next;

      for (int j = 0; j < i; j++)
      {
         current = current -> m_next;
      }

      // Everything becomes nullptr.
      current -> m_prev -> m_next = current -> m_next;
      current -> m_next -> m_prev = current -> m_prev;
      delete current;
      current = nullptr;
        
      // Decrease size by 1.
      m_size--;
   }
   
   return;
}

template <typename T>
void MyList<T>::reverse()
{
   Node<T> *curr = m_sentinel;
   Node<T> *next = m_sentinel->m_next;
   Node<T> *prev = m_sentinel->m_prev;

   for(int i = 0; i < m_size; i++)
   {
      curr->m_next = prev;
      curr->m_prev = next;
      prev = curr;
      curr = next;
      next = next->m_next;
   }

  return;
}

template <typename T> 
bool MyList<T>::empty()
{
   return (m_size == 0 ? true : false);
}

template <typename T>
int MyList<T>::size()
{
   return m_size;
}