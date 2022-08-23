#include <iostream>
#include <conio.h>

using namespace std;

class student{
    private:
        string name,departman_name;
        int age,class_num;

    public:
    //constructorlar class adı ile aynı olmak zorunda ve hiç bir deger döndürmezler ve başına hiç bir şey yazılmaz.
        student(string name ,string departman_name,int age,int class_num){
            this->name = name;
            this->age = age;
            this->class_num = class_num;
            this->departman_name = departman_name;
            // degisken isimleri aynı olduğu için this pointerini kullandık

        };
        
        void getStudent(){
            cout<<"student name: "<<name<<endl;
            cout<<"studen age: "<<age<<endl;
            cout<<"studen class number: "<<class_num<<endl;
            cout<<"student departman name: "<<departman_name<<endl;

        }


};

int main(){
    student st("taha","computer engineer",25,2541);
    // nesne olusut olusmaz degerleri verebiliriz ve atamalarını yapabiliriz. Ayrı olarka set metodlarını kullanmaya gerek yoktur.
    st.getStudent();// atanan degerleri yazdırdık.


    getch();
    return 0;   
}