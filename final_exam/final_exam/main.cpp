/*%% This solution was submitted and prepared by %% <Cristea Andrei, W61RAB> %% for the Final Coding Test of the Programming course.%% I declare that this solution is my own work.%% I have not copied or used third party solutions.%% I have not passed my solution to my classmates, neither  made it public.%% Students' regulation of Eotvos Lorand University %% (ELTE Regulations Vol. II. 74/C. § ) %% states that as long as a student presents another student's work%% - or at least the significant part of it - as their own%% performance, it will count as a disciplinary fault. %% The most serious consequence of a disciplinary fault %% can be dismissal of the student from the University.*/

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

struct offer {
    int id_company, id_product, price;
};

int main(int argc, const char * argv[]) {
    int N = 0, M = 0, O = 0;
    cin >> N >> M >> O;
    vector<offer> Offers(O);
    for (int i = 0; i < Offers.size(); i++) {
        cin >> Offers[i].id_company >> Offers[i].id_product >> Offers[i].price;
    }
    // First subtask
    int maxi = 0;
    for (int i = 0; i < O; i++) {
        if (Offers[i].price > Offers[maxi].price && Offers[i].id_product < Offers[maxi].id_product) {
            maxi = i;
        }
    }
    cout << "#\n";
    cout << Offers[maxi].id_product << endl;
    // Second subtask
    cout << "#\n";
    int max_cnt = -1;
    int max_company = -1;
    for (int company = 1; company < N; company++)
    {
        int cnt = 0;
        for(offer o: Offers){
            if(o.id_company == company) cnt++;
        }
        if(cnt > max_cnt){
            max_cnt = cnt;
            max_company = company;
        }
    }
    cout << max_company << endl;
    cout << "#\n";
    vector<int> comp_cnt(m+1);
    for(auto o : Offers){
        comp_cnt[o.id_product]++;
    }
    
    cout << "#\n";
    return 0;
}
