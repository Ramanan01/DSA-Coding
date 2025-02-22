class SmallestInfiniteSet {
public:
    set<int> s;
    int last;

    SmallestInfiniteSet() {
        last = 1;
    }
    
    int popSmallest() {
        if (s.empty()) {
            return last++;
        } else {
            int smallest = *s.begin();
            s.erase(smallest);
            return smallest;
        }
    }
    
    void addBack(int num) {
        if (num < last) {
            s.insert(num);
        }
    }
};
