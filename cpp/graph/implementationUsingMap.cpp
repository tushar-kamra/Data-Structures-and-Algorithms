#include<bits/stdc++.h>
using namespace std;

class edge{
    public: int data;
            int weight;
    edge(int u,int w)
    {
        data=u;
        weight=w;
    }
};

class graph
{
    private: unordered_map<int,vector<edge>> grph;
             unordered_map<int,vector<edge>>::iterator it;
    public:
    void addedge(int u,int v,int weight)
    {   edge x(u,weight);
        grph[v].push_back(x);
        edge y(v,weight);
        grph[u].push_back(y);
    }

    void display()
    {
        for(it=grph.begin();it!=grph.end();it++)
        {
                cout<<it->first <<" -> ";
                vector<edge> arr =it->second;

                for(int i=0;i<arr.size();i++)
                    cout<<arr[i].data<<"/"<<arr[i].weight<<", ";
            cout<<"\n";


        }
    }

    void path(int u,int v,string ans,int w,vector<bool> &check)
    {   
        if(v==u)
        {
            cout<<ans<<v<<"  @"<<w<<endl;
          //  cout<<"base";
            return;

        }
        //cout<<"called";
        vector<edge> arr=grph[u];
        for(int i=0;i<arr.size();i++)
        {
        if(check[arr[i].data])
        {
            check[arr[i].data]=false;
            path(arr[i].data,v,ans+to_string(u)+ "->", arr[i].weight+w,check);
            check[arr[i].data]=true;
        }

        }


    }
    string myans="";
    string minpath(int u,int v,string ans,vector<bool> check,int w)
    {   static int mx=INT32_MAX;
        if(v==u)
        {
            ans+=to_string(v) +" @"+to_string(w);
            if(mx>w)
            {
                mx=w;
                myans=ans;
            } else if(myans=="")
                myans=ans;
            return myans;
          
        }

        vector<edge> arr=grph[u];



        for(int i=0;i<arr.size();i++)
        {
            if(check[arr[i].data])
            {
                    check[arr[i].data]=false;
                    minpath(arr[i].data,v,ans+to_string(u)+"- >",check,arr[i].weight+w);
            }
        }
        return myans;
    }
    
};

int main()
{
    graph obj;
    vector<bool> check(10000,true);
    obj.addedge(0,3,10);
    obj.addedge(0,1,10);
    obj.addedge(1,2,10);
    obj.addedge(2,3,40);
    obj.addedge(3,4,2);
    obj.addedge(4,5,2);
    obj.addedge(4,6,8);
    obj.addedge(5,6,3);
    obj.display();
    check[0]=false;
    obj.path(0,6,"",0,check);
    cout<<obj.minpath(0,6,"",check,0);
    obj.addedge(0,6,1);
    cout<<endl<<obj.minpath(0,6,"",check,0);
    //obj.path(0,6,"",0,check);
    
}