 // Problem --------------------
    // Maintain median
    // We are getting operations
    // 1. add new integer
    // 2. remove integer
    // 3. find median
    // Median - middle element of the sorted array


    // Find kth smallest element
    






















    struct Median {
        void balance() {
            while(left.size() < right.size()) { // left.size() < k
                left.insert(*right.begin());
                right.erase(right.begin());
            }

            while(left.size() > right.size()) { // left.size() > k
                right.insert(*left.rbegin());
                left.erase(left.find(*left.rbegin())); // OR left.erase(prev(left.end()));
            }

        }

        void insert(int x) {
            if(x < *left.rbegin()) left.insert(x);
            else right.insert(x);

            balance();
        }

        void erase(int x) {
            auto it = right.find(x);
            if(it != right.end()) right.erase(it);
            else left.erase(left.find(x)); // Why deleting like this? Why not directly left.erase(x) ?

            balance();
        }

        int getMedian() {
            // check for 0 size
            if(left.size() == right.size()) {
                return (*left.rbegin() + *right.begin()) / 2;
            }
            return *left.rbegin();
        }

        multiset<int> left, right;
    };
