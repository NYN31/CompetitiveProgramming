    map<int,int>mpe;
    int arr[N];
    cin>>n;
    int cnt = 0;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        int x = arr[i];
        if(mpe.find(arr[i]) == mpe.end()){
            mpe[x]=cnt++;
        }
        x = mpe[x];
        arr[i]=x;
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";cout<<endl;
