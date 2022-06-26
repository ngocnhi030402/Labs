template<class T>
int Heap<T>::size(){
    return count;
}

template<class T>
bool Heap<T>::isEmpty(){
    if(count == 0) return true;
    else return false;
}

template<class T>
T Heap<T>::peek(){
    if(count == 0) return -1;
    else return elements[0];
}

template<class T>
bool Heap<T>::contains(T item){
    if(count == 0) return false;
    for(int i = 0; i < count; i++){
        if(elements[i] == item) return true;
    }
    return false;
}

template<class T>
bool Heap<T>::pop(){
    if(count == 0) return 0;
    else{
    elements[0] = elements[count - 1];
    count--;
    reheapDown(0);
    }
    return 1;
    
}


template<class T>
void Heap<T>::push(T item){
    elements[count] = item;
    count++;
    reheapUp(count - 1);
}

template<class T>
void Heap<T>::ensureCapacity(int minCapacity){
    
    T* arr = new T [minCapacity];
    for(int i = 0; i < count; i++){
        arr[i] = elements[i];
    }
    capacity += minCapacity;
    if(minCapacity >= capacity){
        capacity += minCapacity;
        
    }
}

template<class T>
void Heap<T>::reheapUp(int position){
    if(position < 0 || position >= count || count == 0) return;
    int parent = (position - 1)/2;
    if(elements[parent] < elements[position]){
        swap(elements[parent], elements[position]);
        reheapUp(parent);
    }
}

void reheapDown(int maxHeap[], int numberOfElements, int index)
{
    if(index < 0 || index >= numberOfElements || numberOfElements == 0){
        return;
    }
    else{
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        int largest = 0;
        if(left <= numberOfElements && right <= numberOfElements){
        if(right <= numberOfElements && maxHeap[right] > maxHeap[left]) largest = right;
        else largest = left;
            
        if(maxHeap[largest] > maxHeap[index]){
            swap(maxHeap[largest], maxHeap[index]);
            reheapDown(maxHeap, numberOfElements, largest);
        }
        }
        
        
    }
}

void reheapUp(int maxHeap[], int numberOfElements, int index)
{
    if(index < 0 || index >= numberOfElements || numberOfElements == 0){
        return;
    }
    else{
        int max = (index - 1)/2;
        if(maxHeap[max] < maxHeap[index]){
            swap(maxHeap[max], maxHeap[index]);
            reheapUp(maxHeap, numberOfElements, max);
        }
    }
    
}


template<class T>
int Heap<T>::getItem(T item) {
    // TODO: return the index of item in heap
    for(int i = 0; i < count; i++){
        if(elements[i] == item){
            return i;
        }
    }
    return -1;
}

template<class T>
void Heap<T>::remove(T item) {
    // TODO: remove the element with value equal to item
    if(count == 0) return;
    int index = 0;
    for(int i = 0; i < count; i++){
        if(elements[i] == item){
            index = i;
        }
    }
    elements[index] = elements[count - 1];
    count--;
    reheapUp(index);
    reheapDown(index);
}

template<class T>
void Heap<T>::clear() {
    // TODO: delete all elements in heap
    delete[] elements;
    elements = new T[capacity];
    capacity = 10;
    count = 0;
    
}