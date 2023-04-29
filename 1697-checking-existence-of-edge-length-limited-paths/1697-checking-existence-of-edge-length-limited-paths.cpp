class UnionFind {
 public:
  UnionFind(int n) : id(n), rank(n) {
    iota(begin(id), end(id), 0);
  }

  void unionByRank(int u, int v) {
    const int i = find(u);
    const int j = find(v);
    if (i == j)
      return;
    if (rank[i] < rank[j]) {
      id[i] = id[j];
    } else if (rank[i] > rank[j]) {
      id[j] = id[i];
    } else {
      id[i] = id[j];
      ++rank[j];
    }
  }

  int find(int u) {
    return id[u] == u ? u : id[u] = find(id[u]);
  }

 private:
  vector<int> id;
  vector<int> rank;
};

class Solution {
 public:
  vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList,
                                         vector<vector<int>>& queries) {
    vector<bool> ans(queries.size());
    UnionFind uf(n);

    for (int i = 0; i < queries.size(); ++i)
      queries[i].push_back(i);

    sort(begin(queries), end(queries),
         [](const auto& a, const auto& b) { return a[2] < b[2]; });
    sort(begin(edgeList), end(edgeList),
         [](const auto& a, const auto& b) { return a[2] < b[2]; });

    int i = 0;  // i := edgeList's index
    for (const vector<int>& query : queries) {
      // Union edges whose distances < limit (query[2])
      while (i < edgeList.size() && edgeList[i][2] < query[2])
        uf.unionByRank(edgeList[i][0], edgeList[i++][1]);
      if (uf.find(query[0]) == uf.find(query[1]))
        ans[query.back()] = true;
    }

    return ans;
  }
};
