void print(int dist[][vert])
{
    for(int i=0; i<vert; i++)
    {
        for(int j=0; j<vert; j++)
        {
            if(dist[i][j]==INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

void floyd(int dist[][vert])
{
    for(int k=0; k<vert; k++)
    {
        for(int i=0; i<vert; i++)
        {
            for(int j=0; j<vert; j++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j] && dist[i][k]!=INF && dist[k][j]!=INF)
                    dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }
    print(dist);
}

void fw_5()
{
    int graph[vert][vert] = {{0,INF,3,INF},{2,0,INF,INF},{INF,7,0,1},{6,INF,INF,0}};
    cout << "All pair shortest path between shelters and disaster zone : \n";
    floyd(graph);
}
