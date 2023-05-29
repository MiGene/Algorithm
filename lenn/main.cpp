#include <iostream>

using namespace std;

void sim(){
    string vic, sus;
    cin >> vic >> sus;
    int summ=0;
    for (int i=0; i<vic.size(); i++){
        if (vic[i]==sus[i]) summ+=1;
    }

    double percent = summ/(double)vic.size() *100.0;

    cout << percent;

}

void sim2(){
    string vic, sus;
    cin >> vic >> sus;
    double summ=0;
    for (int i=0; i<800; i++){
        if (vic[i]==sus[i]) summ+=1;
    }
    double percent = summ/800 *100.0;
    cout << percent << " ";

     summ=0;
    for (int i=800; i<1600; i++){
        if (vic[i]==sus[i]) summ+=1;
    }
    percent = summ/800 *100.0;
    cout << percent << " ";

     summ=0;
    for (int i=1600; i<2400; i++){
        if (vic[i]==sus[i]) summ+=1;
    }
    percent = summ/800 *100.0;
    cout << percent << " ";

    summ=0;
    for (int i=2400; i<3200; i++){
        if (vic[i]==sus[i]) summ+=1;
    }
    percent = summ/800 *100.0;
    cout << percent << " ";

    summ=0;
    for (int i=3200; i<4000; i++){
        if (vic[i]==sus[i]) summ+=1;
    }
     percent = summ/800 *100.0;
    cout << percent << " ";

    summ=0;
    for (int i=4000; i<4094; i++){
        if (vic[i]==sus[i]) summ+=1;
    }
     percent = summ/94 *100.0;
    cout << percent << " ";

}

void len(){
    string a;
    cin >> a;
    cout << a.size();
}
int main()
{
    char m;
    cin >> m;
    if (m=='l') len();
    else if (m=='s')sim();
    else sim2();
}
