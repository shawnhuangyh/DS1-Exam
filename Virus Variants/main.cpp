#include "DisjointSet.h"
#include "Graph.h"

int main() {
    int n, m, p, q;
    char c;
    cin >> n >> m;
    DisjointSet<int> ds(n);
    Graph<int> g(n);
    for (int i = 0; i < m; i++) {
        cin >> c >> p >> q;
        switch (c) {
            case 'S':
                ds.Union(p, q);
                break;
            case 'H':
                g.AddArc(p, q);
                g.FindArc(p, q, ds);
                g.FindArc(q, p, ds);
                break;
            default:
                cout << "Invalid Input!" << endl;
                i--;
                break;
        }
    }
    cout << ds.GetCount() << endl;
    return 0;
}
