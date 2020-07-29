template<typename T>

class Vector {
    T *arr; 
    int current_size, max_size;

    public:
        Vector()
        {
            current_size = 0;
            max_size = 1;
            arr = new T[max_size];
        }
        void push_back(T d){
            if(current_size == max_size)
            {
                // Array is fully occupied
                T *oldArr = arr;
                max_size *= 2;
                arr = new T[max_size];
                // Copy from old array
                for (int i = 0; i < current_size; i++)
                    arr[i] = oldArr[i];
                // clear and delete the old memory
                delete [] oldArr; 
            }
            arr[current_size] = d;
            current_size++;
        }
        void pop_back()
        {
            current_size--;
        }

        T front() const
        {
            return arr[0];
        }
        
        T back() const
        {
            return arr[current_size-1];
        }

        bool empty() const
        {
            return current_size == 0;
        }

        int capacity() const
        {
            return max_size;
        }

        T at(const int i)
        {
            return arr[i];
        }

        int size() const {
            return current_size;
        }

        // operating overlaoding
        T operator[](const int i)
        {
            return arr[i];
        }


};