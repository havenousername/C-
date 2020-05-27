// My Code(Marija)
#include <iostream>
using namespace std;

struct person {
  string name;
  int points;
};

person read_person() {
  string line;
  getline(cin, line);
  long pos = line.find(';');
  return person{line.substr(0, pos), stoi(line.substr(pos + 1))};
}

int main() {
    int n, p;
    do{
        cerr<<"Type in num of participants and total points!"<<endl;
  cin >> n >> p;
  if(n<1 || n>100 ) cerr<<"The num of participants should be between 1 and 100(including those numbers)"<<endl;
  if(p<1 || p>100 ) cerr<<"The num of total points should be between 1 and 100(including those numbers)"<<endl;

  }while (n<1 || n>100 ||p<1 || p>100);

cerr<<"Great!"<<endl<<"Now please enter the names and the points of the students seaprated by semicolon:"<<endl;
  cin.ignore(1, '\n');
  person someone[n];
  for (int i = 0; i < n; i++) {
    someone[i] = read_person();
   // cout << someone.name << endl << someone.points << endl;;
  }
  int cntFirstPlace=0;
  string firstPlaceNames[n];
  int cntSecondPlace=0;
  string secondPlaceNames[n];
  int cntThirdPlace=0;
  string thirdPlaceNames[n];
  int cntNoAward=0;
  string noAward[n];

  for (int i=0; i < n; i++)
  {
      if (someone[i].points <= p && someone[i].points >= int(p*0.9))
      {
         firstPlaceNames[cntFirstPlace]=someone[i].name;
         cntFirstPlace++;
      }

     else if (someone[i].points < int(p*0.9) && someone[i].points >= int(p*0.8))
      {
        secondPlaceNames[cntSecondPlace]=someone[i].name;
         cntSecondPlace++;
      }

      else if (someone[i].points < int(p*0.8) && someone[i].points >= int(p*0.7))
      {
          thirdPlaceNames[cntThirdPlace]=someone[i].name;
         cntThirdPlace++;
      }
      else{
         noAward[cntNoAward]=someone[i].name;
         cntNoAward++;
      }

  }

    cout<<cntFirstPlace<<";";
    int counter = 0;
    for (int i=0;i<cntFirstPlace;i++)
    {
        counter++;
        if (counter == cntFirstPlace) {
            cout<<firstPlaceNames[i];
        }else{
            cout<<firstPlaceNames[i]<<";";
        }
    }
    cout<<endl;
  
    cout<<cntSecondPlace<<";";
    for (int i=0;i<cntSecondPlace;i++){
        counter++;
        if (counter == cntSecondPlace) {
            cout<<secondPlaceNames[i];
        }else{
            cout<<secondPlaceNames[i]<<";";
        }
    }
    cout<<endl;
    cout<<cntThirdPlace<<";";
    
    for (int i=0;i<cntThirdPlace;i++){
        counter++;
        if (counter == cntThirdPlace) {
            cout<<thirdPlaceNames[i];
        }else{
            cout<<thirdPlaceNames[i]<<";";
        }
    }
      cout<<endl;
       cout<<cntNoAward<<";";
    for (int i=0;i<cntNoAward;i++){
        counter++;
        if (counter == cntNoAward) {
            cout<<noAward[i];
        }else{
            cout<<noAward[i]<<";";
        }
    }
      cout<<endl;
      return 0;
  }


