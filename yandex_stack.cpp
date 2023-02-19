#include <iostream>
#include <string_view>
#include <fstream>
#include <string>
#include <stack>

class Deque{
public:
    void push_numb_front(int numb){
        deq.push(numb);
        std::cout << "ok\n";
    }
    bool is_empty() noexcept{
        return deq.empty();
    }
    int back_numb(){
        return deq.top();
    }
    void pop_numb_front(){
        std::cout << back_numb() << '\n';
        deq.pop();
    }
    size_t get_size() const{
        return deq.size();
    }
    void clear(){
        while(get_size()){
            deq.pop();
        }
        std::cout<<"ok\n";
    }
private:
    std::stack<int> deq;
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
    Deque stack;
    std::string option;
//    stack.push_numb_front(number);
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
                    stack.push_numb_front(number);

                    break;
                case "pop"_sh:
                    if(stack.is_empty()){
                        std::cout<<"error\n";
                    }
                    else{
                        stack.pop_numb_front();
                    }
                    break;
                case "back"_sh:
                    if(stack.is_empty()){
                        std::cout<<"error\n";
                    }
                    else{
                        std::cout << stack.back_numb() << '\n';
                    }
                    break;
                case "size"_sh:
                    std::cout << stack.get_size() << '\n';
                    break;
                case "clear"_sh:
                    stack.clear();
                    break;
                case "exit"_sh:
                    std::cout << "bye\n";
                    return 0;
            }
        }
    }

}

