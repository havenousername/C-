#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct offer
{
    int company, product, price;
};
int main()
{
    int n, m, o;
    cin>>n>>m>>o;
    vector<offer>offers(o);
    for (int i=0; i<o; i++)
    {
        cin>>offers[i].company>>offers[i].product>>offers[i].price;
    }

    //1, subtask
    cout<<"#\n";
    int maxi=0;
    for (int i=1; i<o; i++)
    {
        //the identifier of the most expensive product, if the prices are the same we output the one with the smallest identifier
        if (offers[i].price>offers[maxi].price || offers[i].price==offers[maxi].price && offers[i].product < offers[maxi].product)
        {
            maxi=i;
        }
    }
    cout<<offers[maxi].product<<endl;

    //2.subtask
    cout<<"#\n";
    int max_count=-1;
    int max_company=-1;
    for (int company=1; company<=n; company++)
    {
        int cnt=0;
        for (offer o :offers)
        {
            //going through each company and counting how many times it appears throughout the offers
            if (o.company==company)
            {
                cnt++;
            }
        }
        if (cnt>max_count)
        {
            max_count=cnt;
            max_company=company;
        }
    }
    cout<<max_company<<endl;

    cout<<"#\n";
    //3.subtask
    vector<int>comp_cnt(m+1);
    for (offer o : offers)
    {
        comp_cnt[o.product]++; //counting the companies for all the products
    }
    vector<int>one_comp_products;
    for (int p=1; p<=m; p++)
    {
        if (comp_cnt[p]==1)
            one_comp_products.push_back(p);
    }
    cout<<one_comp_products.size()<<endl;
    if (one_comp_products.size()>0)
    {
        for (int p : one_comp_products)
            cout<<p<<" ";
        cout<<endl;
    }
    cout<<"#\n";
    //4.subtask
    vector<vector<int>>products(n+1);
    //for each company make a list of products
    for (int i=0; i<o; i++)
    {
        products[offers[i].company].push_back(offers[i].product);
    }
    for (int c=1; c<=n; c++)
    {
        sort(products[c].begin(), products[c].end());
        for (int i=0; i<products[c].size(); i++)
        {
            cerr<<products[c][i];
        }
        cerr<<endl;
    }
    for (int c1=1; c1<=n; c1++)
    {
        for (int c2=c1+1; c2<=n; c2++)
        {
            if (products[c1] == products[c2])
            {
                cout<<c1<<" "<<c2<<endl;
                return 0;
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}
