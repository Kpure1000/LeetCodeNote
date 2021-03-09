#include <vector>
#include <map>

template <class T>
class UFS
{
public:
    UFS() {}
    void Union(const T &k, const T &v);
    bool Find(const T &k, const T &v);

private:
    std::pair<int, int> Project(const T &k, const T &v);
    int FindRoot(const T &k);
    std::map<T, int> m_Map;
    std::vector<int> m_Set;
};