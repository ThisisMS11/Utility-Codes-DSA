//  INSE
int f(vector<int>& arr) {
 
        int n = arr.size();
        stack<int> st;
        vector<int> lse(n), rse(n);

        /* for finding the immediate left smaller element index */
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (st.empty())
                lse[i] = -1;
            else
                lse[i] = st.top();
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        /* for finding the immediate right smaller element index */
        for (int i = n-1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (st.empty())
                rse[i] = n;
            else
                rse[i] = st.top();
            st.push(i);
        }

        int answer = 0;
        for (int i = 0; i < n; ++i) {
            int width = rse[i] - lse[i] - 1;
            answer = max(answer, width * arr[i]);
        }

        cout<<endl;

        return answer;
    }


// INGE
