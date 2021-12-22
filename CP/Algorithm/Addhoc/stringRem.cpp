        int len = strlen(a);
        for(i=0;i<len;i++)
        {
            if(a[i] == '-') continue;
            sum=rem*10+(a[i]-'0');
            rem=sum%b;
        }
