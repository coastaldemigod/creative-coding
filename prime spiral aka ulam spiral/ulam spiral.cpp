#include<bits/stdc++.h>
using namespace std;

vector<bool> pr(1000000000,1);
void sieve(int n){
    pr[1]=0;
    for(int i=2;i<=n;i++)
    {
        if(pr[i]==1)
        {
            for(int j=i*i;j<=n;j+=i)
            {
                if(j%i==0)
                    pr[j]=0;
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    
    vector<vector<int>> a(n,vector<int> (n,0));
    vector<vector<char>> b(n,vector<char> (n,0));
    sieve(n*n);
    int i,j,dir;
    if(n%2==0)
    {   
        dir=0; // 0 -> right  |  1 -> left | 2 -> down | 3 -> up
        i=0;
        j=0;
    }
    else
    {
        dir=1;
        i=n-1;
        j=n-1;
    }
    int c=n*n;
    while(c>0)
    {
        a[i][j]=c;
        c--;

        if(dir==0)
        {
            if(j==n-1 || a[i][j+1]!=0)
            {
                i++;
                dir=2;
            }
            else 
                j++;
        }
        else if(dir==1)
        {
            if(j==0 || a[i][j-1]!=0)
            {
                i--;
                dir=3;
            }
            else
                j--;
        }
        else if(dir==2)
        {
            if(i==n-1 || a[i+1][j]!=0)
            {
                j--;
                dir=1;
            }
            else
                i++;
        }
        else if(dir==3)
        {
            if(i==0 || a[i-1][j]!=0)
            {
                j++;
                dir=0;
            }
            else
                i--;
        }

    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {   
            // cout<<"+ ";
            // cout<<a[i][j]<<" ";
            if(pr[a[i][j]]==1)
            {
                // b[i][j]='+';
                // cout<<"+ ";
                printf("\033[3;47;35m  \033[0m");
            }
            else
            {
                printf("  ");
                // printf("\x1B[36m+ \033[0m");
                // cout<<"- ";
            }
        }
        cout<<"\n";
    }
    return 0;
}


// Reference

// For coloring on the terminal
// https://stackoverflow.com/a/54062826/13023828
// https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c

// Idea by The coding challenge 
// https://www.youtube.com/watch?v=a35KWEjRvc0