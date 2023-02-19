#include <iostream>
#include <string_view>
#include <fstream>
#include <string>
#include <queue>

class Que{
public:
    void push_numb(int numb){
        que_in.push(numb);
        std::cout << "ok\n";
    }
    bool is_empty() noexcept{
        return que_in.empty();
    }
    int front_numb(){
        return que_in.front();
    }
    void pop_numb(){
        std::cout<<front_numb()<<'\n';
        que_in.pop();
    }
    size_t get_size() const{
        return que_in.size();
    }
    void clear(){
        while(get_size()){
            que_in.pop();
        }
        std::cout<<"ok\n";
    }
private:
    std::queue<int> que_in;
};


constexpr auto hash_djb2a(const std::string_view sv) {
    unsigned long hash{ 5381 };
    for (unsigned char c : sv) {
        hash = ((hash << 5) + hash) ^ c;
    }
    return hash;
}

constexpr auto operator"" _sh(const char *str, size_t len) {
    return hash_djb2a(std::string_view{ str, len });
}


int main() {
    std::ifstream file;
    Que que;
    std::string option;
//    que.push_numb_front(number);
    file.open("input.txt", std::ifstream::in);
    if(file){
        for (;;) {
            file >> option;
            if(option.empty()){
                return 0;
            }
            switch(hash_djb2a(option)) {
                case "push"_sh:
                    int number;
                    file>>number;
                    que.push_numb(number);

                    break;
                case "pop"_sh:
                    if(que.is_empty()){
                        std::cout<<"error\n";
                    }
                    else{
                        que.pop_numb();
                    }
                    break;
                case "front"_sh:
                    if(que.is_empty()){
                        std::cout<<"error\n";
                    }
                    else{
                        std::cout<<que.front_numb()<<'\n';
                    }
                    break;
                case "size"_sh:
                    std::cout<<que.get_size()<<'\n';
                    break;
                case "clear"_sh:
                    que.clear();
                    break;
                case "exit"_sh:
                    std::cout << "bye\n";
                    return 0;
            }
        }
    }

}
