int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    vector<int> lse(n), rse(n);

    /* for finding the left smallest element */
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        if (st.empty())
            lse[i] = -1;
        else
            lse[i] = st.top();
        st.push(i);
    }

    while (!st.empty())
        st.pop();

    /* for finding the right smallest element */
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        if (st.empty())
            rse[i] = n;
        else
            rse[i] = st.top();
        st.push(i);
    }

    int answer = INT_MIN;
    for (int i = 0; i < n; ++i) {
        int area = heights[i] * (rse[i] - lse[i] - 1);
        answer = max(answer, area);
    }
    return answer;
}
