 // Code
    set<int> lights;
    multiset<int> passageLength, maxValue;

    lights.insert(0);
    lights.insert(n);

    passageLength.insert(n); // n * (whole array sum)

    for(int times = 1; times <= n - 1; times++) {
        int pos;
        cin >> pos;

        // find the nearest lights in both directions
        auto it = lights.lower_bound(pos);
        int right = *it;
        int left = *prev(it);

        // update passageLength
        passageLength.erase(passageLength.find(right - left)); // (right - left) * (subarray sum [left, right])
        passageLength.insert(pos - left); // (pos - left) * (subarray sum [left, pos])
        passageLength.insert(right - pos); // (right - pos) * (subrray sum [pos, right])

        // update lights
        lights.insert(pos);

        // find max gap
        cout << *passageLength.rbegin() << " ";
    }
