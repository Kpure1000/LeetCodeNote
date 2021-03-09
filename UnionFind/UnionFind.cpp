#include "UnionFind.h"

using std::map;
using std::vector;

template <class T>
void UFS<T>::Union(const T &k, const T &v)
{
    std::pair<int, int> k_v = Project(k, v);
    int ik = k_v.first, iv = k_v.second;
    int rk = ik, rv = iv;
    while (rk != m_Set[rk])
        rk = m_Set[rk];
    while (rv != m_Set[rv])
        rv = m_Set[rv];
    
}

template <class T>
bool UFS<T>::Find(const T &k, const T &v)
{
    int reK = FindRoot(k);
    int reV = FindRoot(v);
    if (reK == reV && reK != -1)
    {
        // Union(k, v);
    }
    return reK == reV;
}

template <class T>
std::pair<int, int> UFS<T>::Project(const T &k, const T &v)
{
    if (m_Map.find(k) == m_Map.end())
    {
        m_Map[k] = m_Set.size();
        m_Set.push_back(m_Set.size());
    }
    if (m_Map.find(v) == m_Map.end())
    {
        m_Map[v] = m_Set.size();
        m_Set.push_back(m_Set.size());
    }
    return {m_Map[k], m_Map[v]};
}

template <class T>
int UFS<T>::FindRoot(const T &k)
{
    if (m_Map.find(k) == m_Map.end())
        // don't find
        return -1;
    int re = m_Map[k];
    while (re != m_Set[re])
        re = m_Set[re];
    return re;
}