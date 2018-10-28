template <class Type>
class Stack{
public:
    Stack() {
        head = nullptr;
    }
 
    void push(const Type& value) {
        ++size;
        StackNode *temp = new StackNode(value, head);
        head = temp;
    }
 
    Type top() const {
        return head->value;
    }
 
    void pop() {
        --size;
        StackNode *temp = head;
        head = head->next;
        delete temp;
    }
 
    int size_s() const {
        return (size);
    }
 
    bool empty() {
        return (!size_s);
    }
 
    ~Stack() {
        StackNode *temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }
 
private:
    struct StackNode {
        Type value;
        StackNode *next;
        StackNode(const Type& value, StackNode *next) : value(value), next(next) { }
    } *head;
    int size;
};