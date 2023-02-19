#include <iostream>
#include <string_view>
#include <fstream>
#include <string>
#include <deque>

class Deque{
public:
    void push_numb_front(int numb){
        deq.push_front(numb);
        std::cout << "ok\n";
    }
    void push_numb_back(int numb){
        deq.push_back(numb);
        std::cout << "ok\n";
    }
    bool is_empty() noexcept{
        return deq.empty();
    }
    int back_numb(){
        return deq.back();
    }
    int front_numb(){
        return deq.front();
    }
    void pop_numb_front(){
        std::cout << front_numb() << '\n';
        deq.pop_front();
    }
    void pop_numb_back(){
        std::cout << back_numb() << '\n';
        deq.pop_back();
    }
    size_t get_size() const{
        return deq.size();
    }
    void clear(){
        while(get_size()){
            deq.pop_front();
        }
        std::cout<<"ok\n";
    }
private:
    std::deque<int> deq;
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
    Deque deq;
    std::string option;
    int number;
//    deq.push_numb_front(number);
    file.open("input.txt", std::ifstream::in);
    if(file){
        for (;;) {
            file >> option;
            if(option.empty()){
                return 0;
            }
            switch(hash_djb2a(option)) {
                case "push_front"_sh:
                    file>>number;
                    deq.push_numb_front(number);
                    break;
                case "push_back"_sh:

                    file>>number;
                    deq.push_numb_back(number);

                    break;
                case "pop_front"_sh:
                    if(deq.is_empty()){
                        std::cout<<"error\n";
                    }
                    else{
                        deq.pop_numb_front();
                    }
                    break;
                case "pop_back"_sh:
                    if(deq.is_empty()){
                        std::cout<<"error\n";
                    }
                    else{
                        deq.pop_numb_back();
                    }
                    break;

                case "back"_sh:
                    if(deq.is_empty()){
                        std::cout<<"error\n";
                    }
                    else{
                        std::cout << deq.back_numb() << '\n';
                    }
                    break;
                case "front"_sh:
                    if(deq.is_empty()){
                        std::cout<<"error\n";
                    }
                    else{
                        std::cout << deq.front_numb() << '\n';
                    }
                    break;
                case "size"_sh:
                    std::cout << deq.get_size() << '\n';
                    break;
                case "clear"_sh:
                    deq.clear();
                    break;
                case "exit"_sh:
                    std::cout << "bye\n";
                    return 0;
            }
        }
    }

}
