class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {}

    void push(int x) {
        if(q1.empty())
            q2.push(x);
        else
            q1.push(x);
    }

    int pop() {
        if(q1.empty() && q2.empty())
            return -1;

        if(q1.empty()) {

            while(q2.size() > 1) {
                q1.push(q2.front());
                q2.pop();
            }

            int elem = q2.front();
            q2.pop();

            return elem;
        }

        else {

            while(q1.size() > 1) {
                q2.push(q1.front());
                q1.pop();
            }

            int elem = q1.front();
            q1.pop();

            return elem;
        }
    }

    int top() {
        if(q1.empty() && q2.empty())
            return -1;

        int elem = pop();
        push(elem);

        return elem;
    }

    bool empty() {
        return q1.empty() && q2.empty();
    }
};