#include <iostream>
#include <string>

using namespace std;
void contoh (){
    cout<<"Ini hanya contoh"<< endl;
}
void lagi (string name) {
    cout<<"Haii..."<<name<< endl;
}
int main()
{
    contoh();
    lagi("Satrya");
    cout << "Hello world!" << endl;
    cout << "Haii" << endl;
    cout << "Press any key to close";
    cin.get();
    // perkaliann

    int perkalian, n, batas;
    cout << "Perkalian : ";
    cin>>perkalian;
    cout<<"SampaiDengan : ";
    cin>>batas;
    cout<<endl;
    for(n=1; n<=batas; n++)
        cout<<perkalian<<"x"<<n<<"="<<perkalian*n<<endl;
    return 0;
}
