class RideSharingSystem {
public:
    queue<int> r, d;
    set<int> st;
    RideSharingSystem() {}

    void addRider(int riderId) {
        r.push(riderId);
        st.insert(riderId);
    }

    void addDriver(int driverId) { d.push(driverId); }

    vector<int> matchDriverWithRider() {
        while (!r.empty() && st.find(r.front()) == st.end())
            r.pop();

        if (r.empty() || d.empty())
            return {-1, -1};

        int dId = d.front();
        d.pop();
        int rId = r.front();
        r.pop();

        st.erase(rId);

        return {dId, rId};
    }

    void cancelRider(int riderId) { st.erase(riderId); }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */