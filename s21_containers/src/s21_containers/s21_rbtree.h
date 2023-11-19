#ifndef CPP2_S21_CONTAINERS_1_S21_CONTAINERS_S21_RBTREE_H_
#define CPP2_S21_CONTAINERS_1_S21_CONTAINERS_S21_RBTREE_H_

#include <limits>

namespace s21 {
template <typename Key, typename T, typename Compare>
class RBTree {
 public:
  // typedefs
  using key_type = Key;
  using value_type = T;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_t;

  // internal classes/structures
  enum Color : bool { BLACK = 1, RED = 0 };
  class Node {
    friend RBTree;

   public:
    Node(Node *parent, Node *left, Node *right, Color color,
         const key_type &key, const value_type &value)
        : parent_(parent),
          left_(left),
          right_(right),
          color_(color),
          key_(key),
          value_(value) {}
    void swap(Node *other) noexcept;

   public:
    Node *parent_, *left_, *right_;
    Color color_;

   private:
    key_type key_;
    value_type value_;
  };
  class iterator {
    friend RBTree;

   public:
    iterator();
    explicit iterator(Node *node);
    reference operator*() const noexcept;
    iterator &operator++() noexcept;
    iterator &operator--() noexcept;
    iterator operator++(int) noexcept;
    iterator operator--(int) noexcept;
    bool operator==(const iterator &other) const noexcept;
    bool operator!=(const iterator &other) const noexcept;

   private:
    Node *node_;
  };
  class const_iterator {
    friend RBTree;

   public:
    const_iterator();
    explicit const_iterator(Node *node);
    const_reference operator*() const noexcept;
    const_iterator &operator++() noexcept;
    const_iterator &operator--() noexcept;
    const_iterator operator++(int) noexcept;
    const_iterator operator--(int) noexcept;
    bool operator==(const const_iterator &other) const noexcept;
    bool operator!=(const const_iterator &other) const noexcept;

   private:
    Node *node_;
  };

  // constructors and assertion operators
  RBTree();
  RBTree(const RBTree &other) noexcept;
  RBTree(RBTree &&other) noexcept;
  RBTree &operator=(const RBTree &other) noexcept;
  RBTree &operator=(RBTree &&other) noexcept;

  // destructors
  ~RBTree();

  // functions
  void free_tree_memory(Node *n) noexcept;
  void delete_tree() noexcept;
  Node *grandparent(Node *x) const noexcept;
  Node *uncle(Node *x) const noexcept;
  Node *insert(key_type key, value_type value) noexcept;
  Node *insert_non_uniq(key_type key, value_type value) noexcept;
  void small_left_turn(Node *x) noexcept;
  void small_right_turn(Node *x) noexcept;
  void large_left_turn(Node *x) noexcept;
  void large_right_turn(Node *x) noexcept;
  Node *find(key_type key) const noexcept;
  void fix(Node *x) noexcept;
  static Node *min(Node *subtree);
  static Node *max(Node *subtree);
  void delete_node(Node *x) noexcept;
  void delete_node(iterator i) noexcept;
  void update_head() noexcept;
  void rebalance_right_subtree(Node *x) noexcept;
  void rebalance_left_subtree(Node *x) noexcept;
  static Node *next_node(Node *x);
  static Node *prev_node(Node *x);
  void merge(RBTree &other) noexcept;
  size_type size() const noexcept;
  void swap(RBTree &other) noexcept;
  size_type max_size() const noexcept;
  iterator begin() const noexcept;
  iterator end() const noexcept;

 private:
  // data
  Node *head_;
  Node *root_;
  size_type node_count_;
  Compare comp_;
};
}  // namespace s21
#include "s21_rbtree.inc"
#endif  // CPP2_S21_CONTAINERS_1_S21_CONTAINERS_S21_RBTREE_H_
