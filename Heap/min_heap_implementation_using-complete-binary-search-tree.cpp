class minHeap {
  private:
    int* arr;
    int capacity;
    int heap_size; // Renamed to avoid collision with size() method

    // Internal Helper: Returns parent index
    int parent(int i) { return (i - 1) / 2; }
    
    // Internal Helper: Returns left child index
    int left(int i) { return 2 * i + 1; }
    
    // Internal Helper: Returns right child index
    int right(int i) { return 2 * i + 2; }

    // Internal Helper: Standard swap function
    void swap(int* x, int* y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

    // Internal Helper: Restores the min-heap property downwards
    void Heapify(int ind) {
        int li = left(ind);
        int ri = right(ind);
        int smallest = ind;
        
        if (li < heap_size && arr[li] < arr[smallest]) {
            smallest = li;
        }
        if (ri < heap_size && arr[ri] < arr[smallest]) {
            smallest = ri;
        }
        
        if (smallest != ind) {
            swap(&arr[smallest], &arr[ind]);
            Heapify(smallest);
        }
    }

  public:
    // Correct Constructor: Matches class name and initializes dynamically
    minHeap() {
        capacity = 2005; // Set a safe capacity based on constraints (q <= 1000)
        heap_size = 0;
        arr = new int[capacity];
    }
    
    // Destructor to free up allocated memory
    ~minHeap() {
        delete[] arr;
    }

    // 1 x : Push element x into the heap
    void push(int x) {
        if (heap_size == capacity) return;
        
        // Insert the new key at the end
        arr[heap_size] = x;
        int k = heap_size;
        heap_size++;
        
        // Fix the min heap property upwards
        while (k != 0 && arr[parent(k)] > arr[k]) {
            swap(&arr[parent(k)], &arr[k]);
            k = parent(k);
        }
    }

    // 2: Remove the top (minimum) element
    void pop() {
        if (heap_size <= 0) return;
        
        if (heap_size == 1) {
            heap_size--;
            return;
        }
        
        // Replace root with the last element and heapify down
        arr[0] = arr[heap_size - 1];
        heap_size--;
        Heapify(0);
    }

    // 3: Return the top element, or -1 if empty
    int peek() {
        if (heap_size <= 0) {
            return -1;
        }
        return arr[0];
    }

    // 4: Return the number of elements currently in the heap
    int size() {
        return heap_size;
    }
};
