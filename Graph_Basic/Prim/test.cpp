#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Edge{
    int src;
    int dest;
    int cost;
};
bool compare(const Edge& e1, const Edge& e2)
{
    return e1.cost < e2.cost;
}

int main()
{
    Edge e1 = {1, 2, 6}, e2 = {4, 5, 3}, e3 = {1, 3, 2};
    vector<Edge> ve;
    cout << ve.empty() << endl;
    ve.push_back(e1);
    ve.push_back(e2);
    ve.push_back(e3);
    sort(ve.begin(), ve.end(), compare);
    cout << ve[0].cost << ' ' << ve[1].cost << ' ' << ve[2].cost << endl;
    cout << "size : " << ve.size() << endl;
    ve.pop_back();
    cout << "size : " << ve.size() << endl;

    for(auto iter = ve.begin(); iter != ve.end(); iter++)
        cout << (*iter).cost << ' ';
    cout << endl;
    ve.pop_back();
    ve.pop_back();
    cout << ve.empty() << endl;


}