class SpecialStack {
	public:
		stack<int>st;
		stack<int>mst;
	
	SpecialStack() {
		// Define Stack
	
	}
	
	void push(int x) {
		// Add an element to the top of Stack
		
		st.push(x);
		
		if(mst.empty())
		{
		    mst.push(x);
		}
		else
		mst.push(min(mst.top(), x));
	}
	
	void pop() {
		// Remove the top element from the Stack
		
		if(st.empty())
		return;
		st.pop();
		mst.pop();
	}
	
	int peek() {
		// Returns top element of the Stack
		if(st.empty())
		return -1;
		return st.top();
		
	}
	
	bool isEmpty() {
		// Check if stack is empty
		return st.empty();
	}
	
	int getMin() {
		// Finds minimum element of Stack
			if(st.empty())
			return -1;
		return mst.top();
	}
};
