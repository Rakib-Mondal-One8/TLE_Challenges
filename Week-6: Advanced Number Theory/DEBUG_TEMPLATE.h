// Fix: Ensure all operator<< overloads take const references
template<class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    os << "{" << p.first << ", " << p.second << "} ";
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[ ";
    for (const auto& elem : v) os << elem << " ";
    os << "]";
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const deque<T>& v) {
    os << "[ ";
    for (const auto& elem : v) os << elem << " ";
    os << "]";
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const set<T>& v) {
    os << "[ ";
    for (const auto& elem : v) os << elem << " ";
    os << "]";
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const multiset<T>& v) {
    os << "[ ";
    for (const auto& elem : v) os << elem << " ";
    os << "]";
    return os;
}

template <class T1, class T2>
ostream& operator<<(ostream& os, const map<T1, T2>& v) {
    for (const auto& elem : v) {
        os << "Key: " << elem.first << ", Value: " << elem.second << endl;
    }
    return os;
}

template <class T1, class T2>
ostream& operator<<(ostream& os, const unordered_map<T1, T2>& v) {
    for (const auto& elem : v) {
        os << "Key: " << elem.first << ", Value: " << elem.second << endl;
    }
    return os;
}

// Debug function (must be after operator<< definitions)
void err(istream_iterator<string> it) {
    cout << endl;
}

template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cout << *it << " = " << a << " ";
    err(++it, args...);
}
#define HERE cout<<"here - "<<__LINE__<<"\n";
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

//__int128

//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int >,rb_tree_tag,tree_order_statistics_node_update>indexed_set;

//order_of_key
//find_by_order

//this memsets by 2e9
//memset(x,127,sizeof x);

//this memsets by 1e9
//memset(x,63,sizeof x);

