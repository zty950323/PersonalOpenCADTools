/**
 * Copyright (c) 2022, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description:
 */

#ifndef SOURCE_INCLUDE_DATASTRUCTURE_BASIC_RBTREE_H_
#define SOURCE_INCLUDE_DATASTRUCTURE_BASIC_RBTREE_H_

#include <iomanip>
#include <iostream>

namespace Basic {
enum RBTColor {
  RED,
  BLACK,
};

template <class T>
class TzBRTNode {
 public:
  T m_key;
  TzBRTNode* m_parent;
  TzBRTNode* m_left;
  TzBRTNode* m_right;
  RBTColor m_color;
  inline TzBRTNode()
      : m_key(0),
        m_parent(nullptr),
        m_left(nullptr),
        m_right(nullptr),
        m_color(RBTColor::RED) {}
  inline TzBRTNode(T value, RBTColor color, TzBRTNode* par, TzBRTNode* left,
                   TzBRTNode* right)
      : m_key(value), m_parent(par), m_left(left), m_right(right) {}
};

template <class T>
class TzRBTree {
 private:
  TzBRTNode<T>* m_root;

 public:
  inline TzRBTree() : m_root(nullptr) {}

  inline ~TzRBTree() {}

  // Preorder traversal of red black tree.
  inline void preOrder() const { preOrder(m_root); }

  // Ergodic middle order.
  inline void inOrder() const { inOrder(m_root); }

  // Postorder traversal.
  inline void postOrder() const { postOrder(m_root); }

  // search some certain node in red black tree.
  inline TzBRTNode<T>* search(T key) { search(m_root, key); }

  // insert one item into the red black tree.
  inline void insert(T key) {
    TzBRTNode<T>* node = nullptr;
    if (nullptr == (node = new TzBRTNode<T>(key, RBTColor::BLACK, nullptr,
                                            nullptr, nullptr))) {
      return;
    }
    insert(m_root, node);
  }

  // remove some certain node in red black tree.
  inline void remove(T key) {
    TzBRTNode<T>* node;
    if (nullptr != (node = search(m_root, key))) {
      remove(m_root, node);
    }
  }

  // destroy this tree.
  inline void destroy(void) {
    destroy(m_root);
    m_root = nullptr;
  }

  // print this tree.
  inline void print(void) {
    if (m_root) {
      print(m_root, m_root->m_key, 0);
    }
  }

 private:
  inline void preOrder(TzBRTNode<T>* root) const {
    if (nullptr == root) {
      return;
    }
    std::cout << "Node Color : " << root->m_color
              << "Node Key : " << root->m_key << std::endl;
    preOrder(root->m_left);
    preOrder(root->m_right);
  }

  inline void inOrder(TzBRTNode<T>* root) const {
    if (nullptr == root) {
      return;
    }
    preOrder(root->m_left);
    std::cout << "Node Color : " << root->m_color
              << "Node Key : " << root->m_key << std::endl;
    preOrder(root->m_right);
  }

  void postOrder(TzBRTNode<T>* root) const {
    if (nullptr == root) {
      return;
    }
    preOrder(root->m_left);
    preOrder(root->m_right);
    std::cout << "Node Color : " << root->m_color
              << "Node Key : " << root->m_key << std::endl;
  }

  // left rotate this tree
  void leftRotate(TzBRTNode<T>*& root, TzBRTNode<T>* x) {
    TzBRTNode<T>* y = x->m_right;
    y->m_parent = x->m_parent;
    x->m_right = y->m_left;
    if (nullptr != y->m_left) {
      y->m_left->m_parent = x;
    }
    if (nullptr != x->m_parent) {
      if (x == x->m_parent->m_left) {
        x->m_parent->m_left = y;
      } else {
        x->m_parent->m_right = y;
      }
    } else {
      root = y;
    }
    x->m_parent = y;
    y->m_left = x;
  }

  // right rotate this tree.
  void rightRotate(TzBRTNode<T>*& root, TzBRTNode<T>* x) {
    TzBRTNode<T>* y = x->m_left;
    y->m_parent = x->m_parent;
    x->m_left = y->m_right;

    if (nullptr != y->m_right) {
      if (x == x->m_parent->m_left) {
        x->m_parent->m_left = y;
      } else {
        x->m_parent->m_right = y;
      }
    } else {
      root = y;
    }
    x->m_parent = y;
    y->m_right = x;
  }

  // inner insert function.
  void insert(TzBRTNode<T>*& root, TzBRTNode<T>* node) {
    TzBRTNode<T>* y = nullptr;
    TzBRTNode<T>* x = root;
    while (nullptr != x) {
      y = x;
      if (node->m_key < x->m_key) {
        x = x->m_left;
      } else {
        x = x->m_right;
      }
    }
    node->m_parent = y;
    if (nullptr != y) {
      if (node->m_key < y->m_key) {
        y->m_left = node;
      } else {
        y->m_right = node;
      }
    } else {
      root = node;
    }
    node->m_color = RBTColor::RED;
    insertFixUp(root, node);
  }

  // inner remove function
  void remove(TzBRTNode<T>*& root, TzBRTNode<T>* node) {
    TzBRTNode<T>*child, *parent;
    RBTColor color;
    if (nullptr != node->m_left && nullptr != node->m_right) {
      TzBRTNode<T>* replace = node;
      replace = replace->m_right;
      while (nullptr != replace->m_left) {
        replace = replace->m_left;
      }
      node->m_key = replace->m_key;
      child = replace->m_right;
      parent = replace->m_parent;
      color = replace->m_color;
      if (node == parent->m_left) {
        parent->m_left = child;
      } else {
        parent->m_parent = parent;
      }
      if (child) {
        child->m_parent = parent;
      }
      if (color == RBTColor::BLACK) {
        removeFixUp(root, child, parent);
      }
      delete replace;
      replace = nullptr;
      return;
    }
    if (nullptr != node->m_left) {
      child = node->m_left;
    } else {
      child = node->m_right;
    }
    parent = node->m_parent;
    color = node->m_color;
    if (child) {
      child->m_parent = parent;
    }

    if (parent) {
      if (node == parent->m_left) {
        parent->m_left = child;
      } else {
        parent->m_right = child;
      }
    } else {
      root = child;
    }
    if (RBTColor::BLACK == color) {
      removeFixUp(root, child, parent);
    }
    delete node;
    node = nullptr;
  }

  // the inner insert fix up function.
  void insertFixUp(TzBRTNode<T>*& root, TzBRTNode<T>* node) {
    TzBRTNode<T>*parent, *grdparent, *uncle;
    while ((nullptr != node->m_parent) &&
           (RBTColor::RED == node->m_parent->m_color)) {
      parent = node->m_parent;
      grdparent = parent->m_parent;
      auto dealNodes = [&parent, &grdparent, &uncle]() {
        if (nullptr != uncle && RBTColor::RED == uncle->m_color) {
          // case 1 : the uncle node is red, in this moment
          // need move the red attribute in parent
          // and uncle node up to grdparent.
          // the result of dealing will move into the grdparent.
          uncle->m_color = RBTColor::BLACK;
          parent->m_color = RBTColor::BLACK;
          grdparent->m_color = RBTColor::RED;
          node = grdparent;
          continue;
        } else if (node == parent->m_right) {
          // Case2: when the uncle node is black and the pending
          // node is close to the uncle node,
          // the pending node is transformed
          // into the parent node and rotated left to the parent node
          // In this way, the problem handling situation
          // can be transformed into case 3
          node = node->m_parent;
          leftRotate(root, node);
        } else if (node == parent->m_left) {
          // Case3: when the uncle node is black and the node to be
          // processed is far away from the uncle node,
          // the parent node is converted
          // to black and the grandfather node is converted to red,
          // And right rotate the grandfather node
          // (at this time, it is equivalent to giving a red
          // attribute on the processing
          // node branch to the brother branch),
          // and the red black tree repair is completed.
          parent->m_color = RBTColor::BLACK;
          grdparent->m_color = RBTColor::RED;
          rightRotate(root, grdparent);
        }
      };
      if (parent == grdparent->m_left) {
        uncle = grdparent->m_right;
      } else {
        uncle = grdparent->m_left;
      }
      dealNodes();
      root->m_color = RBTColor::BLACK;
    }
  }

  // the inner remove fix up function.
  void removeFixUp(TzBRTNode<T>*& root, TzBRTNode<T>* node,
                   TzBRTNode<T>* parent) {
    TzBRTNode<T>* brother;
    auto dealNodes = [&brother, &parent, &root]() {
      if (brother->m_color == RBTColor::RED) {
        // Case1: when the color of the sibling node is red,
        // exchange the position of the sibling node
        // and the parent node, and rotate the parent node to the left,
        // so that the correction node can obtain a black sibling node.
        // After this treatment, the problem will
        // be transferred to case 2, 3 and 4.
        brother->m_color = RBTColor::BLACK;
        parent->m_color = RBTColor::RED;
        leftRotate(root, parent);
        brother = parent->m_right;
      } else if ((!brother->left || brother->left->color == RBTColor::BLACK) &&
                 (!brother->right ||
                  brother->right->color == RBTColor::BLACK)) {
        // Case2: when the sibling node is
        // black and has two black child nodes,
        // move a black attribute of the
        // processing node and the sibling node
        // up to the parent node at the same time.
        // Add one to the black attribute of the parent node,
        // and then turn the processing node into the parent node.
        // The problem is turned into case1,3,4
        brother->m_color = RBTColor::RED;
        node = parent;
        parent = node->m_parent;
      } else {
        if (!brother->m_right || RBTColor::BLACK == brother->m_right->m_color) {
          // Case3: when the brother node is black and the near
          // nephew node is red, set the brother node to red
          // and the near nephew node to black.
          // The sibling nodes are rotated right to
          // turn the problem into Case4
          brother->m_left->m_color = RBTColor::BLACK;
          brother->m_color = RBTColor::RED;
          rightRotate(root, brother);
          brother->m_parent->m_right;
        }
        // Case4: when the brother node is black and the
        // far nephew node is red, the far nephew node inherits
        // the brother node black and the brother node
        // inherits the parent node color,
        // The parent node gets black, the parent node is left-handed,
        // and the red black tree is balanced
        brother->m_color = parent->m_color;
        parent->m_color = RBTColor::BLACK;
        brother->m_right->m_color = RBTColor::BLACK;
        leftRotate(root, parent);
        node = root;  // break the loop;
      }
    };

    while ((!node || node->m_color == RBTColor::BLACK) && node != m_root) {
      if (node == parent->m_left) {
        brother = parent->m_right;
      } else {
        brother = parent->m_left;
      }
      dealNodes();
    }
    if (nullptr != node) {
      node->m_color = RBTColor::BLACK;
    }
  }

  // the inner search function.
  inline TzBRTNode<T>* search(TzBRTNode<T>* root, T key) const {
    if (nullptr == root || key == root->m_key) {
      return root;
    }
    if (key < root->m_key) {
      return search(root->m_left, key);
    } else {
      return search(root->m_right, key);
    }
  }

  // destroy the red black tree.
  inline void destroy(TzBRTNode<T>*& tree) {
    if (nullptr == tree) {
      return;
    }
    if (nullptr != tree->m_left) {
      return destroy(tree->m_left);
    }
    if (nullptr != tree->m_right) {
      return destroy(tree->m_right);
    }
    delete tree;
    tree = nullptr;
  }

  // print the tree.
  inline void print(TzBRTNode<T>* tree, T key, int direction) {
    if (nullptr != tree) {
      if (0 == direction) {
        std::cout << std::setw(2) << tree->m_key << "(B) is root" << std::endl;
      } else {
        std::cout << std::setw(2) << tree->m_key
                  << ((tree->m_color == RBTColor::RED) ? "(R)" : "(B)")
                  << " is " << std::setw(2) << key << "'s " << std::setw(12)
                  << (direction == 1 ? "right child" : "left child")
                  << std::endl;
      }
      print(tree->left, tree->key, -1);
      print(tree->right, tree->key, 1);
    }
  }
};
}  // namespace Basic

#endif  // SOURCE_INCLUDE_DATASTRUCTURE_BASIC_RBTREE_H_
