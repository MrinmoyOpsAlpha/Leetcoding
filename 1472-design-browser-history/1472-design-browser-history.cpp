class Node {
public:
  Node* prev = nullptr;
  Node* next = nullptr;
  string url;

  Node(string url) {
    this->url = url;
  }
};

class BrowserHistory {
private:
  Node* curr = nullptr;

public:
  BrowserHistory(string homepage) {
    curr = new Node(homepage);
  }

  void visit(string url) {
    Node* new_node = new Node(url);
    curr->next = new_node;
    new_node->prev = curr;
    curr = new_node;
  }

  string back(int steps) {
    while (curr->prev && steps-- > 0) {
      curr = curr->prev;
    }
    return curr->url;
  }

  string forward(int steps) {
    while (curr->next && steps-- > 0) {
      curr = curr->next;
    }
    return curr->url;
  }
};
