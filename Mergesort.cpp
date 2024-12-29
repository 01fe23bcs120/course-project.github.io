void merge(vector<pair<int,int>> &b,vector<pair<int,int>> &c,vector<pair<int,int>> &a)
{
    int i=0,j=0,k=0,p=b.size(),q=c.size();
    while(i<p && j<q)
    {
        if(b[i].second>=c[j].second)
        {
            a[k] = b[i];
            i++;
        }
        else
        {
            a[k] = c[j];
            j++;
        }
        k++;
    }

    while(i<p)
    {
        a[k]=b[i];
        i++;
        k++;
    }
    while(j<q)
    {
        a[k]=c[j];
        j++;
        k++;
    }
}

void mergesort(vector<pair<int,int>> &a)
{
    if(a.size()>1)
    {
        int half = a.size()/2;
        vector<pair<int,int>> b(a.begin(),a.begin()+half);
        vector<pair<int,int>> c(a.begin()+half,a.end());
        mergesort(b);
        mergesort(c);
        merge(b,c,a);
    }
}

void mergesort_8()
{
    vector<pair<int,int>> tasks = {{1,34},{2,0},{3,45},{4,6},{5,5}};
    cout << "Task number and their priority level : \n\nTask\tPriority\n\n";
    for(auto &pair:tasks)
    {
        cout << pair.first << " \t " << pair.second << endl;
    }
    cout << "\nOn sorting the tasks based on priority level : \n\nTask\tPriority\n\n";
    mergesort(tasks);
    for(auto &pair:tasks)
    {
        cout << pair.first << " \t " << pair.second << endl;
    }
}
