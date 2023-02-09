#include <iostream>
#include <cmath>


using std::cin;
using std::cout;

// Олимпиадная задача на кондиционер
int16_t mode(const int16_t& t_room,const int16_t& t_cond,const std::string& str){
    if (str == "fan") return t_room;
    if (str == "freeze"){
        return std::min(t_room,t_cond);
    }
    else if (str == "heat"){
        return std::max(t_room,t_cond);
    }
    return t_cond;
}

// Олимпиадная задача на веревки
int girl_cut(){
    cout<<"H";
    int N;
    cin>>N;
    cout<<N;
    int max=0;
    int sum = 0;
    int cur_numb = 0;
    for (int i = 0;i<N;++i){
        cin>>cur_numb;
        if (max<cur_numb){
            max = cur_numb;
        }

        sum+=cur_numb;
    }
    if (sum-max<max){
        cout<<2*max-sum;
    }
    else cout<<sum;
}

//Задачка кольцевое метро для работы в яндекс
void ring(){
    int N,i,j;

    cin>>N>>i>>j;
    if (i>j) {
        int buf = i;
        i = j;
        j = buf;//swap классический
    }
    int station_left= abs(j-i)-1;
    int station_right = abs(j-(i+N))-1;
    if (station_left<=station_right){
        cout<<station_left;
    }
    else{
        cout<<station_right;
    }
}




int main() {
//    int16_t t_room,t_cond;
//    std::string str;
//    cin>>t_room>>t_cond>>str;
//    cout<<mode(t_room,t_cond,str);


    return 0;
}
