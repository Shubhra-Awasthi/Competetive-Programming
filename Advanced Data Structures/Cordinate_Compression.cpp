void coordinateCompress(vector<int> &a)
{
    vector<int> temp = a;

    // 1. Sort
    sort(temp.begin(), temp.end());

    // 2. Remove duplicates
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    // 3. Replace values with compressed indices (1-based)
    for (int &x : a)
        x = lower_bound(temp.begin(), temp.end(), x) - temp.begin() + 1;
}