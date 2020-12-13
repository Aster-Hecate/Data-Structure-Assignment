#define THIS_IS_REQUISITORIES 1

template<class DATA>
struct unit{            //The basic unit of List
        unit* prev = nullptr;
        DATA data;
        unit* next = nullptr;
};

template<class DATA> class List{               //Double-direction Linked List
    public:
    
    //length of list
    int len = 0;
    //head and tail node, not included in the counting of length
    unit<DATA> *head;
    unit<DATA> *tail;
    //cursor, used for searchin certain node
    unit<DATA> *cursor;

    
    List();
    ~List();

    DATA &operator[](int);
    int search(DATA);
    
    int insert(DATA, int);
    int insertAtBack(DATA, int);
    int insertAtFront(DATA, int);
    void append(DATA);
    void deleteThisNode(int);
    DATA pop();
    void push(DATA);
};

template<class DATA> class Stack : public List<DATA>{};

template<class DATA> List<DATA>::List(){
    head = new unit<DATA>;
    tail = new unit<DATA>;
    cursor = head;
    head->next = tail;
    tail->prev = head;
}

template<class DATA> List<DATA>::~List(){
    for(int i = 0; i < len; i++){
        deleteThisNode(i);
    }
    delete head;
    delete tail;
}

template <class DATA> DATA &List<DATA>::operator[](int SN) {
    DATA temp;
    for(int i = 0; i <= SN; i++){
        cursor = cursor->next;
    }
    //there is no usage of pointers so the memory is safe.
    temp = cursor->data;
    cursor = head;
    DATA& out = temp;
    return out;
}

template <class DATA> int List<DATA>::insert(DATA dataToInsert, int placeToInsert){
    if(placeToInsert < 0 || placeToInsert > len)  
    //Because this is the method to insert the first valid node, placeToInsert is the place where the 
    //newly inserted node should be, instead of the place where the cursor is.
        return -1;
    //creating a unit struct
    unit<DATA>* temp = new unit<DATA>;
    temp->data = dataToInsert;
    //move cursor to disignated position
    for(int i = 0; i < placeToInsert; i++){
        cursor = cursor->next;
    }
    //re-establish link
    temp->prev = cursor;
    temp->next = cursor->next;
    cursor->next = temp;
    temp->next->prev = temp;
    //update length
    len++;
    //reset cursor
    cursor = head;
    return 0;
}

template <class DATA> int List<DATA>::insertAtBack(DATA dataToInsert, int placeToInsert){
    if(placeToInsert < 0 || placeToInsert > len)  
    //yep, this time the cursor should be at list[placeToInsert]
        return -1;
    //creating a unit struct
    unit<DATA>* temp = new unit<DATA>;
    temp->data = dataToInsert;
    //move cursor to disignated position
    for(int i = 0; i < placeToInsert; i++){
        cursor = cursor->next;
    }
    //re-establish link
    temp->prev = cursor;
    temp->next = cursor->next;
    cursor->next = temp;
    temp->next->prev = temp;
    //update length
    len++;
    //reset cursor
    cursor = head;
    return 0;
}

template <class DATA> int List<DATA>::insertAtFront(DATA dataToInsert, int placeToInsert){
    if(placeToInsert < 0 || placeToInsert > len)  
    //well, I tend not to use it
        return -1;
    //creating a unit struct
    unit<DATA>* temp = new unit<DATA>;
    temp->data = dataToInsert;
    //move cursor to disignated position
    for(int i = 0; i <= placeToInsert; i++){
        cursor = cursor->next;
    }
    //re-establish link
    temp->next = cursor;
    temp->prev = cursor->prev;
    cursor->prev = temp;
    temp->prev->next = temp;
    //update length
    len++;
    //reset cursor
    cursor = head;
    return 0;
}

template <class DATA> void List<DATA>::deleteThisNode(int placeToDelete){
    unit<DATA>* temp;
    // search for the designated node
    cursor = head;
    for(int i = 0; i <= placeToDelete; i++){
        cursor = cursor->next;
    }
    //deleting process
    temp = cursor;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    //update length
    len--;
    //reset cursor
    cursor = head;
}

template <class DATA> DATA List<DATA>::pop() {
  DATA temp = (DATA)0;
  if(len <= 0) return temp;
  temp = tail->prev->data;
  cursor = tail;
  tail->prev = tail->prev->prev;
  deleteThisNode(len - 1);
  cursor = head;
  return temp;
}

template <class DATA> void List<DATA>::push(DATA dataToPush) {
  insertAtBack(dataToPush, len);
}