#include <iostream>
//#include <stdlib>
using namespace std;

int main() {

int cl;
cout << "1.start" << '\n'<<"2.option"<<"\n"<<"3.help"<<"\n"<<"4.exit"<<"\n";
cin >> cl;

if(cl==1){

//      stdlib::clrsrc();
  //    cout << "*";
      for(int x=1;x<=40;x++){
          cout<<" *";
      }
  //    cout<<"\n";
  //    cout << "*";
      for(int i=1;i<=1;i++){
          for(int i=1;i<=10;i++){
              for(int j=1;j<=3;j++){
                  for(int y=1;y<=10;y++){
                      cout<<"       *";
                  }
  //                cout<<"\n";
  //                cout << "*";
              }

          for(int x=1;x<=40;x++){
              cout<<" *";
          }
          cout<<"\n";
  //        cout << "*";
          }
      }

}

cin.get();
  return 0;
}
