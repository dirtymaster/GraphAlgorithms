

#ifndef A2_SIMPLENAVIGATOR_V1_0_0_MASTER_ABSTRACTLIST_H
#define A2_SIMPLENAVIGATOR_V1_0_0_MASTER_ABSTRACTLIST_H


namespace s21 {

class AbstractList {

 public:

    struct node {
        int value;
        node *next;
    };

    virtual ~AbstractList() {}
    virtual void push(int value) = 0;
    virtual int pop() = 0;
    virtual int peek() const = 0;
    virtual bool empty() const = 0;

 protected:
    node* head_;
    node *create(int value, node* next) {
        node* result = new node;
        result->value = value;
        result->next = next;
        return result;
    }
};

}



#endif //A2_SIMPLENAVIGATOR_V1_0_0_MASTER_ABSTRACTLIST_H
