void bfs(int m[10][10],int v,int source)
{
    int queue[10],front=0,rear=0,visited[10];
    for(int i=0; i<v; i++)
        visited[i]=0;
    visited[source]=1;
    queue[rear]=source;

    while(front<=rear)
    {
        int u=queue[front];
        front++;
        cout << u << " ";
        for(int i=0; i<v; i++)
        {
            if(m[u][i]==1 && visited[i]==0)
            {
                visited[i]=1;
                rear++;
                queue[rear]=i;
            }
        }
    }
}
void bfs_9()
{
    cout << "Connectivity of the road, thus allowing water flow in the following path (considering root source of flood is 0):\n ";
    int source = 0;
    bfs(m,v,source);
}
