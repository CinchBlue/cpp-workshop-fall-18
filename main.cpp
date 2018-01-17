#include <iostream>
#include <vector>
#include <cctype>
#include <functional>

// Parse in a S-expression-like list of objects.
// After, parsing, you can turn it into a tree.
//
// Text -> Tree -> Evaluate
//
//

struct ASTNode {
  enum class Type : int {
    ADD,
    SUB,
    MUL,
    DIV,
    NUM
  };
  virtual ~ASTNode() {}
};

struct OperatorNode : public ASTNode {
  virtual ~OperatorNode() {}
  ASTNode::Type type;
  ASTNode* left;
  ASTNode* right;
};

struct NumberNode : public ASTNode {
  virtual ~NumberNode() {}
  int number;
};

ASTNode* parse(std::istream& in) {
  char c = in.peek();

  while (std::isspace(c)) { in.get(); c = in.peek(); }
  if (std::isdigit(c)) {
    std::string s;
    while (std::isdigit(c)) {
      s += in.get();
      c = in.peek();
    }
    int i = std::stoi(s);
    NumberNode* node = new NumberNode();
    node->number = i;
    return node;
  } else if (c == '+') {
    in.get();
    OperatorNode* node = new OperatorNode();
    node->type = ASTNode::Type::ADD;
    node->left = parse(in);
    node->right = parse(in);
    return node;
  } else if (c == '-') {
    in.get();
    OperatorNode* node = new OperatorNode();
    node->type = ASTNode::Type::SUB;
    node->left = parse(in);
    node->right = parse(in);
    return node;
  } else if (c == '*') {
    in.get();
    OperatorNode* node = new OperatorNode();
    node->type = ASTNode::Type::MUL;
    node->left = parse(in);
    node->right = parse(in);
    return node;
  } else if (c == '/') {
    in.get();
    OperatorNode* node = new OperatorNode();
    node->type = ASTNode::Type::DIV;
    node->left = parse(in);
    node->right = parse(in);
    return node;
  } else {
    std::string s = "Error: character \'";
    s += in.peek() + "\' is invalid.";
    throw std::runtime_error(s);
  }
}

int main() {
  std::function<void(ASTNode*)> print_tree;
  print_tree = [&](ASTNode* root) {
    if (root) {
      if (auto* op = dynamic_cast<OperatorNode*>(root)) {
        if (op->type == ASTNode::Type::ADD) {
          std::cout << "(+ ";
        } else if (op->type == ASTNode::Type::SUB) {
          std::cout << "(- ";
        } else if (op->type == ASTNode::Type::MUL) {
          std::cout << "(* ";
        } else if (op->type == ASTNode::Type::DIV) {
          std::cout << "(/ ";
        } else {
          throw std::runtime_error("Error: How the heck can an operator not "
                                       "be an operator?");
        }
        print_tree(op->left);
        std::cout << " ";
        print_tree(op->right);
        std::cout << ")";
      } else if (auto* num = dynamic_cast<NumberNode*>(root)){
        std::cout << num->number;
        return;
      } else {
        throw std::runtime_error("Error: What the heck is this node?");
      }
    } else {
      throw std::runtime_error("Error: Cannot print a null tree.");
    }
  };
  std::function<int(ASTNode*)> calculate_tree;
  calculate_tree = [&](ASTNode* root) {
    if (!root) {
      throw std::runtime_error("Error: Cannot calculate null expression.");
    }
    if (auto* op = dynamic_cast<OperatorNode*>(root)) {
      int lhs = calculate_tree(op->left);
      int rhs = calculate_tree(op->right);
      if (op->type == ASTNode::Type::ADD) {
        return lhs + rhs;
      } else if (op->type == ASTNode::Type::SUB) {
        return lhs - rhs;
      } else if (op->type == ASTNode::Type::MUL) {
        return lhs * rhs;
      } else if (op->type == ASTNode::Type::DIV) {
        return lhs / rhs;
      }
    } else if (auto* num = dynamic_cast<NumberNode*>(root)) {
      return num->number;
    } else {
      throw std::runtime_error("Error: Really, what the heck is this node?");
    }
  };

  ASTNode* expr = parse(std::cin);
  print_tree(expr);
  std::cout << std::endl;
  std::cout << "Result: " << calculate_tree(expr) << std::endl;
  return 0;
}