void dfs(int here) {
    visit[here] = true;
    for (vector<int>::iterator iter = graph[here].begin(); iter != graph[here].end(); ++iter) {
        int there = *iter;
        if (!visit[there])
            dfs(there);
    }
}
