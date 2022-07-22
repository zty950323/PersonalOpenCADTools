
///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <array>
#include <iostream>
#include <map>
#include <stack>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

using std::array;
using std::cout;
using std::endl;
using std::map;
using std::stack;
using std::string;
using std::vector;

template <typename T>
void printStack(std::stack<T>* s) {
  std::cout << s->size() << " elements on stack\n";
  std::cout << "Top element: " << s->top()  // Leaves element on stack
            << "\n";
  std::cout << s->size() << " elements on stack\n";
  s->pop();
  std::cout << s->size() << " elements on stack\n";
  std::cout << "Top element: " << s->top() << "\n";
  for (decltype(s->size()) i = 0; i < s->size(); ++i) {
    s->pop();
    std::cout << s->top();
  }
}

template <typename Stack>
void print(Stack stack /* pass by value */, int id) {
  std::cout << "s" << id << " [" << stack.size() << "]: ";
  for (; !stack.empty(); stack.pop()) std::cout << stack.top() << ' ';
  std::cout << (id > 1 ? "\n\n" : "\n");
}

class BrainHackInterpreter {
  std::map<unsigned, unsigned> open_brackets, close_brackets;
  unsigned program_pos_{0};
  std::array<std::uint8_t, 32768> data_;
  int data_pos_{0};
  void collect_brackets_positions(const std::string_view program) {
    std::stack<unsigned> brackets_stack;
    for (auto pos{0U}; pos != program.length(); ++pos) {
      const char c{program[pos]};
      if ('[' == c) {
        brackets_stack.push(pos);
      } else if (']' == c) {
        if (brackets_stack.empty()) {
          throw std::runtime_error("brackets [] do not match!");
        } else {
          open_brackets[brackets_stack.top()] = pos;
          close_brackets[pos] = brackets_stack.top();
          brackets_stack.pop();
        }
      }
    }
    if (!brackets_stack.empty())
      throw std::runtime_error("brackets [] do not match!");
  }
  void check_data_pos(int pos) {
    if (pos < 0 or pos >= static_cast<int>(data_.size()))
      throw std::out_of_range{"data pointer out of bound"};
  }

 public:
  explicit BrainHackInterpreter(const std::string_view program) {
    collect_brackets_positions(program);
    data_.fill(0);
    for (; program_pos_ < program.length(); ++program_pos_) {
      switch (program[program_pos_]) {
        case '<':
          check_data_pos(--data_pos_);
          break;
        case '>':
          check_data_pos(++data_pos_);
          break;
        case '-':
          --data_[data_pos_];
          break;
        case '+':
          ++data_[data_pos_];
          break;
        case '.':
          std::cout << data_[data_pos_];
          break;
        case ',':
          std::cin >> data_[data_pos_];
          break;
        case '[':
          if (data_[data_pos_] == 0) program_pos_ = open_brackets[program_pos_];
          break;
        case ']':
          if (data_[data_pos_] != 0)
            program_pos_ = close_brackets[program_pos_];
          break;
      }
    }
  }
};

void TzModifiersCase01() {
  BrainHackInterpreter testInter{
      "++++++++[>++>>++>++++>++++<<<<<-]>[<+++>>+++<-]>[<+"
      "+>>>+<<-]<[>+>+<<-]>>>--------.<<+++++++++.<<----.>"
      ">>>>.<<<------.>..++.<++.+.-.>.<.>----.<--.++.>>>+."};
}

void TzModifiersCase02() {
  std::vector<std::string> v1{"1", "2", "3", "4"}, v2{"Ɐ", "B", "Ɔ", "D", "Ǝ"};
  std::stack s1{std::move(v1)};
  std::stack s2{std::move(v2)};
  print(s1, 1);
  print(s2, 2);
  s1.swap(s2);
  print(s1, 1);
  print(s2, 2);
}

int main(int argc, char* argv[]) {
  TzModifiersCase01();
  TzModifiersCase02();
  system("pause");
  return 0;
}