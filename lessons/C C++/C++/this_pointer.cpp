#include <iostream>
#include <conio.h>
/* this pointer ile class içinde private olarak tanımlanan degiskenlerin fonksiyonlardaki degisken isimleri
ile aynı olmasında kullanılır. this-> diyerek aslında private olan degiskeni göstermis oluruz. */

using namespace std;

class student{
    private:
        string name,departman_name;
        int age,class_num;

    public:
        void setStudent(string name,int age, int class_num,string departman_name){
            this->age = age;
            this->name = name;
            this->departman_name = departman_name;
            this->class_num = class_num;
            /* burada private olarak tanımlanan degisken ile fonksiyonun aldıgı degisken aynı isimde
            oldugu icin this ile private alanındaki degiskene atamayı belirttik.Aksi halde error */
        }

        void getStudent(){
            cout<<"student name: "<<name<<endl;
            cout<<"studen age: "<<age<<endl;
            cout<<"studen class number: "<<class_num<<endl;
            cout<<"student departman name: "<<departman_name<<endl;

        }


};


int main(){

    student st;
    st.setStudent("Taha",25,1254,"computer engineer");
    st.getStudent();

   


    getch();
    return 0;
}