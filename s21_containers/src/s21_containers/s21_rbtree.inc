namespace s21 {

// Node
template <typename Key, typename T, typename Compare>
void RBTree<Key, T, Compare>::Node::swap(Node *other) noexcept {
  if (parent_) {
    if (parent_->left_ == this) {
      parent_->left_ = other;
    } else {
      parent_->right_ = other;
    }
  }
  if (other->parent_) {
    if (other->parent_->left_ == other) {
      other->parent_->left_ = this;
    } else {
      other->parent_->right_ = this;
    }
  }
  std::swap(color_, other->color_);
  std::swap(left_, other->left_);
  std::swap(right_, other->right_);
  std::swap(parent_, other->parent_);
  if (left_) left_->parent_ = this;
  if (right_) right_->parent_ = this;
  if (other->left_) other->left_->parent_ = other;
  if (other->right_) other->right_->parent_ = other;
}

// RBTree
template <typename Key, typename T, typename Compare>
RBTree<Key, T, Compare>::RBTree() : root_(nullptr), node_count_(0) {
  head_ = new Node(nullptr, nullptr, nullptr, BLACK, key_type(), value_type());
}

template <typename Key, typename T, typename Compare>
RBTree<Key, T, Compare>::RBTree(const RBTree &other) noexcept
    : root_(nullptr), node_count_(0) {
  head_ = new Node(nullptr, nullptr, nullptr, BLACK, key_type(), value_type());
  for (auto i = other.begin(); i != other.end(); ++i) {
    fix(insert_non_uniq(i.node_.key_, i.node_.value_));
  }
}

template <typename Key, typename T, typename Compare>
RBTree<Key, T, Compare>::RBTree(RBTree &&other) noexcept
    : root_(nullptr), node_count_(0) {
  head_ = new Node(nullptr, nullptr, nullptr, BLACK, key_type(), value_type());
  std::swap(head_, other.head_);
  std::swap(root_, other.root_);
  std::swap(node_count_, other.node_count_);
  root_->parent_ = head_;
}

template <typename Key, typename T, typename Compare>
RBTree<Key, T, Compare> &RBTree<Key, T, Compare>::operator=(
    const RBTree &other) noexcept {
  for (auto i = other.begin(); i != other.end(); ++i) {
    fix(insert_non_uniq(i.node_.key_, i.node_.value_));
  }
  return *this;
}

template <typename Key, typename T, typename Compare>
RBTree<Key, T, Compare> &RBTree<Key, T, Compare>::operator=(
    RBTree &&other) noexcept {
  delete_tree();
  std::swap(head_, other.head_);
  std::swap(root_, other.root_);
  std::swap(node_count_, other.node_count_);
  root_->parent_ = head_;
  return *this;
}

template <typename Key, typename T, typename Compare>
RBTree<Key, T, Compare>::~RBTree() {
  delete_tree();
  delete head_;
}

template <typename Key, typename T, typename Compare>
void RBTree<Key, T, Compare>::free_tree_memory(Node *n) noexcept {
  if (!n) return;
  free_tree_memory(n->left_);
  free_tree_memory(n->right_);
  --node_count_;
  delete n;
}

template <typename Key, typename T, typename Compare>
void RBTree<Key, T, Compare>::delete_tree() noexcept {
  free_tree_memory(root_);
  root_ = nullptr;
  update_head();
}

template <typename Key, typename T, typename Compare>
auto RBTree<Key, T, Compare>::grandparent(Node *x) const noexcept -> Node * {
  return x->parent_ ? x->parent_->parent_ : nullptr;
}

template <typename Key, typename T, typename Compare>
auto RBTree<Key, T, Compare>::uncle(Node *x) const noexcept -> Node * {
  Node *g = grandparent(x);
  if (!g) return nullptr;
  return g->left_ == x->parent_ ? g->right_ : g->left_;
}

template <typename Key, typename T, typename Compare>
auto RBTree<Key, T, Compare>::insert(key_type key, value_type value) noexcept
    -> Node * {
  Node new_node(nullptr, nullptr, nullptr, RED, key, value);
  if (!root_) {
    new_node.color_ = BLACK;
    root_ = new Node(new_node);
    node_count_ = 1;
    return root_;
  }
  Node *prev = root_;
  for (Node *i = root_; i;
       prev = i, i = (comp_(key, i->key_) ? i->left_ : i->right_)) {
  }

  new_node.parent_ = prev;
  if (comp_(key, prev->key_)) {
    prev->left_ = new Node(new_node);
    ++node_count_;
    return prev->left_;
  } else if (comp_(prev->key_, key)) {
    prev->right_ = new Node(new_node);
    ++node_count_;
    return prev->right_;
  }
  return nullptr;
}

template <typename Key, typename T, typename Compare>
auto RBTree<Key, T, Compare>::insert_non_uniq(key_type key,
                                              value_type value) noexcept
    -> Node * {
  Node new_node(nullptr, nullptr, nullptr, RED, key, value);
  if (!root_) {
    new_node.color_ = BLACK;
    root_ = new Node(new_node);
    node_count_ = 1;
    return root_;
  }
  Node *prev = root_;
  for (Node *i = root_; i;
       prev = i, i = (comp_(key, i->key_) ? i->left_ : i->right_)) {
  }

  new_node.parent_ = prev;
  if (comp_(key, prev->key_)) {
    prev->left_ = new Node(new_node);
    ++node_count_;
    return prev->left_;
  } else {
    prev->right_ = new Node(new_node);
    ++node_count_;
    return prev->right_;
  }
}

template <typename Key, typename T, typename Compare>
void RBTree<Key, T, Compare>::small_left_turn(Node *x) noexcept {
  Node *g = grandparent(x);
  Node *p = x->parent_;
  if (g) {
    g->left_ = x;
    x->parent_ = g;
    p->right_ = x->left_;
    x->left_ = p;
    p->parent_ = x;
  }
}

template <typename Key, typename T, typename Compare>
void RBTree<Key, T, Compare>::small_right_turn(Node *x) noexcept {
  Node *g = grandparent(x);
  Node *p = x->parent_;
  if (g) {
    g->right_ = x;
    x->parent_ = g;
    p->left_ = x->right_;
    x->right_ = p;
    p->parent_ = x;
  }
}

template <typename Key, typename T, typename Compare>
void RBTree<Key, T, Compare>::large_left_turn(Node *x) noexcept {
  Node *g = grandparent(x);
  Node *p = x->parent_;
  if (!g) return;
  if (g->parent_) {
    if (g->parent_->left_ == g)
      g->parent_->left_ = p;
    else
      g->parent_->right_ = p;
  }
  p->parent_ = g->parent_;
  g->parent_ = p;
  g->right_ = p->left_;
  if (g->right_) g->right_->parent_ = g;
  p->left_ = g;
  if (root_ == g) root_ = p;
}

template <typename Key, typename T, typename Compare>
void RBTree<Key, T, Compare>::large_right_turn(Node *x) noexcept {
  Node *g = grandparent(x);
  Node *p = x->parent_;
  if (!g) return;
  if (g->parent_) {
    if (g->parent_->left_ == g)
      g->parent_->left_ = p;
    else
      g->parent_->right_ = p;
  }
  p->parent_ = g->parent_;
  g->parent_ = p;
  g->left_ = p->right_;
  if (g->left_) g->left_->parent_ = g;
  p->right_ = g;
  if (root_ == g) root_ = p;
}

template <typename Key, typename T, typename Compare>
auto RBTree<Key, T, Compare>::find(key_type key) const noexcept -> Node * {
  for (Node *i = root_; i; i = (comp_(key, i->key_) ? i->left_ : i->right_))
    if (!comp_(key, i->key_) && !comp_(i->key_, key)) return i;
  return head_;
}

template <typename Key, typename T, typename Compare>
void RBTree<Key, T, Compare>::fix(Node *x) noexcept {
  root_->parent_ = nullptr;
  Node *g = grandparent(x);
  if (uncle(x) && uncle(x)->color_ == RED) {
    // red uncle case
    x->parent_->color_ = BLACK;
    uncle(x)->color_ = BLACK;
    g->color_ = RED;
    fix(g);
  } else if (g && (uncle(x) == nullptr || uncle(x)->color_ == BLACK) &&
             x->parent_ && x->parent_->color_ == RED) {
    // black uncle case
    if (g->left_ == x->parent_ && x->parent_->right_ == x) {
      // LR case
      small_left_turn(x);
      x->parent_->color_ = RED;
      x->color_ = BLACK;
      large_right_turn(x->left_);
    } else if (g->right_ == x->parent_ && x->parent_->left_ == x) {
      // RL case
      small_right_turn(x);
      x->parent_->color_ = RED;
      x->color_ = BLACK;
      large_left_turn(x->right_);
    } else if (g->left_ == x->parent_ && x->parent_->left_ == x) {
      // LL case
      x->parent_->parent_->color_ = RED;
      x->parent_->color_ = BLACK;
      large_right_turn(x);
    } else if (g->right_ == x->parent_ && x->parent_->right_ == x) {
      // RR case
      x->parent_->parent_->color_ = RED;
      x->parent_->color_ = BLACK;
      large_left_turn(x);
    }
  }
  root_->color_ = BLACK;
  update_head();
}

template <typename Key, typename T, typename Compare>
auto RBTree<Key, T, Compare>::min(Node *subtree) -> Node * {
  for (; subtree->left_; subtree = subtree->left_) {
  }
  return subtree;
}

template <typename Key, typename T, typename Compare>
auto RBTree<Key, T, Compare>::max(Node *subtree) -> Node * {
  for (; subtree->right_; subtree = subtree->right_) {
  }
  return subtree;
}

template <typename Key, typename T, typename Compare>
void RBTree<Key, T, Compare>::delete_node(iterator i) noexcept {
  delete_node(i.node_);
}

template <typename Key, typename T, typename Compare>
void RBTree<Key, T, Compare>::delete_node(Node *x) noexcept {
  root_->parent_ = nullptr;
  // red node with 0 children
  if (x->color_ == RED && !x->left_ && !x->right_) {
    if (x->parent_->left_ == x) {
      x->parent_->left_ = nullptr;
    } else {
      x->parent_->right_ = nullptr;
    }
    delete x;
    --node_count_;
    update_head();
    return;
  }
  // any color node with 2 children
  if (x->left_ && x->right_) {
    Node *replace_node = max(x->left_);
    x->swap(replace_node);
    delete_node(x);
    update_head();
    return;
  }
  // black node with 1 child
  if (x->color_ == BLACK &&
      ((x->left_ && !x->right_) || (!x->left_ && x->right_))) {
    Node *child = x->left_ ? x->left_ : x->right_;
    x->swap(child);
    delete_node(x);
    update_head();
    return;
  }
  // black node with 0 children
  if (x->color_ == BLACK && !x->left_ && !x->right_) {
    if (x->parent_) {
      if (x->parent_->left_ == x) {
        x->parent_->left_ = nullptr;
        rebalance_right_subtree(x);
      } else {
        x->parent_->right_ = nullptr;
        rebalance_left_subtree(x);
      }
    } else {
      root_ = nullptr;
    }
    delete x;
    --node_count_;
    update_head();
    return;
  }
}

template <typename Key, typename T, typename Compare>
void RBTree<Key, T, Compare>::update_head() noexcept {
  if (!root_) {
    head_->left_ = nullptr;
    head_->right_ = nullptr;
    return;
  }
  head_->left_ = min(root_);
  head_->right_ = max(root_);
  root_->parent_ = head_;
}

template <typename Key, typename T, typename Compare>
void RBTree<Key, T, Compare>::rebalance_right_subtree(Node *x) noexcept {
  if (!x || !x->parent_) return;
  Node *sibling = x->parent_->right_;
  if (sibling->color_ == BLACK) {
    // case sibling is black
    if ((sibling->left_ && sibling->left_->color_ == RED) ||
        (sibling->right_ && sibling->right_->color_ == RED)) {
      // case at least 1 child is red
      if (sibling->right_ && sibling->right_->color_ == RED) {
        // case right_ child is red, left_ is any
        sibling->color_ = sibling->parent_->color_;
        sibling->parent_->color_ = BLACK;
        sibling->right_->color_ = BLACK;
        large_left_turn(sibling->right_);
        return;
      }
      if (sibling->left_ && sibling->left_->color_ == RED &&
          (!sibling->right_ || sibling->right_->color_ == BLACK)) {
        // case left_ child is red, right_ is black
        sibling->left_->color_ = BLACK;
        sibling->color_ = RED;
        small_right_turn(sibling->left_);
        rebalance_right_subtree(x);
        return;
      }
    }
    if ((!sibling->left_ || sibling->left_->color_ == BLACK) &&
        (!sibling->right_ || sibling->right_->color_ == BLACK)) {
      // case both children are black
      sibling->color_ = RED;
      Color prev_color = sibling->parent_->color_;
      sibling->parent_->color_ = BLACK;
      if (prev_color == BLACK) rebalance_right_subtree(sibling->parent_);
    }
  } else {
    // case sibling is red
    sibling->parent_->color_ = RED;
    sibling->color_ = BLACK;
    large_left_turn(sibling->right_);
    rebalance_right_subtree(x);
  }
}

template <typename Key, typename T, typename Compare>
void RBTree<Key, T, Compare>::rebalance_left_subtree(Node *x) noexcept {
  if (!x || !x->parent_) return;
  Node *sibling = x->parent_->left_;
  if (sibling->color_ == BLACK) {
    // case sibling is black
    if ((sibling->right_ && sibling->right_->color_ == RED) ||
        (sibling->left_ && sibling->left_->color_ == RED)) {
      // case at least 1 child is red
      if (sibling->left_ && sibling->left_->color_ == RED) {
        // case left_ child is red, right_ is any
        sibling->color_ = sibling->parent_->color_;
        sibling->parent_->color_ = BLACK;
        sibling->left_->color_ = BLACK;
        large_right_turn(sibling->left_);
        return;
      }
      if (sibling->right_ && sibling->right_->color_ == RED &&
          (!sibling->left_ || sibling->left_->color_ == BLACK)) {
        // case right_ child is red, left_ is black
        sibling->right_->color_ = BLACK;
        sibling->color_ = RED;
        small_left_turn(sibling->right_);
        rebalance_left_subtree(x);
        return;
      }
    }
    if ((!sibling->right_ || sibling->right_->color_ == BLACK) &&
        (!sibling->left_ || sibling->left_->color_ == BLACK)) {
      // case both children are black
      sibling->color_ = RED;
      Color prev_color = sibling->parent_->color_;
      sibling->parent_->color_ = BLACK;
      if (prev_color == BLACK) rebalance_left_subtree(sibling->parent_);
    }
  } else {
    // case sibling is red
    sibling->parent_->color_ = RED;
    sibling->color_ = BLACK;
    large_right_turn(sibling->left_);
    rebalance_left_subtree(x);
  }
}

template <typename Key, typename T, typename Compare>
auto RBTree<Key, T, Compare>::next_node(Node *x) -> Node * {
  if (x->right_) {
    x = min(x->right_);
    return x;
  }
  if (x->parent_->left_ == x) {
    x = x->parent_;
    return x;
  }
  Node *nextNode = x;
  for (; nextNode && max(nextNode) == x; nextNode = nextNode->parent_) {
  }
  if (!nextNode) {
    for (nextNode = x; nextNode->parent_; nextNode = nextNode->parent_) {
    }
  }
  x = nextNode;
  return x;
}

template <typename Key, typename T, typename Compare>
auto RBTree<Key, T, Compare>::prev_node(Node *x) -> Node * {
  if (!x->parent_) return x->right_;
  if (x->left_) {
    x = max(x->left_);
    return x;
  }
  if (x->parent_->right_ == x) {
    x = x->parent_;
    return x;
  }
  Node *prevNode = x;
  for (; prevNode && min(prevNode) == x; prevNode = prevNode->parent_) {
  }
  if (!prevNode) {
    for (prevNode = x; prevNode->parent_; prevNode = prevNode->parent_) {
    }
  }
  x = prevNode;
  return x;
}

template <typename Key, typename T, typename Compare>
void RBTree<Key, T, Compare>::merge(RBTree &other) noexcept {
  for (auto i = other.begin(); i != other.end(); ++i) {
    insert(i.node_->key_, i.node_->value_);
  }
  other.delete_tree();
}

template <typename Key, typename T, typename Compare>
void RBTree<Key, T, Compare>::swap(RBTree &other) noexcept {
  std::swap(head_, other.head_);
  std::swap(root_, other.root_);
  std::swap(node_count_, other.node_count_);
}

template <typename Key, typename T, typename Compare>
auto RBTree<Key, T, Compare>::size() const noexcept -> size_type {
  return node_count_;
}

template <typename Key, typename T, typename Compare>
auto RBTree<Key, T, Compare>::max_size() const noexcept -> size_type {
  return std::numeric_limits<size_type>::max() / sizeof(Node) / 2;
}

/* iterators stuff */
// iterator
template <typename Key, typename T, typename Compare>
RBTree<Key, T, Compare>::iterator::iterator() : node_(nullptr) {}

template <typename Key, typename T, typename Compare>
RBTree<Key, T, Compare>::iterator::iterator(Node *node) : node_(node) {}

template <typename Key, typename T, typename Compare>
auto RBTree<Key, T, Compare>::iterator::operator*() const noexcept
    -> reference {
  return node_->value_;
}

template <typename Key, typename T, typename Compare>
auto RBTree<Key, T, Compare>::iterator::operator++() noexcept -> iterator & {
  node_ = next_node(node_);
  return *this;
}

template <typename Key, typename T, typename Compare>
auto RBTree<Key, T, Compare>::iterator::operator--() noexcept -> iterator & {
  node_ = prev_node(node_);
  return *this;
}

template <typename Key, typename T, typename Compare>
auto RBTree<Key, T, Compare>::iterator::operator++(int) noexcept -> iterator {
  iterator tmp = *this;
  node_ = next_node(node_);
  return tmp;
}

template <typename Key, typename T, typename Compare>
auto RBTree<Key, T, Compare>::iterator::operator--(int) noexcept -> iterator {
  iterator tmp = *this;
  node_ = prev_node(node_);
  return tmp;
}

template <typename Key, typename T, typename Compare>
bool RBTree<Key, T, Compare>::iterator::operator==(
    const iterator &other) const noexcept {
  return node_ == other.node_;
}

template <typename Key, typename T, typename Compare>
bool RBTree<Key, T, Compare>::iterator::operator!=(
    const iterator &other) const noexcept {
  return node_ != other.node_;
}

// const_iterator
template <typename Key, typename T, typename Compare>
RBTree<Key, T, Compare>::const_iterator::const_iterator() : node_(nullptr) {}

template <typename Key, typename T, typename Compare>
RBTree<Key, T, Compare>::const_iterator::const_iterator(Node *node)
    : node_(node) {}

template <typename Key, typename T, typename Compare>
auto RBTree<Key, T, Compare>::const_iterator::operator*() const noexcept
    -> const_reference {
  return node_->value_;
}

template <typename Key, typename T, typename Compare>
auto RBTree<Key, T, Compare>::const_iterator::operator++() noexcept
    -> const_iterator & {
  node_ = next_node(node_);
  return *this;
}

template <typename Key, typename T, typename Compare>
auto RBTree<Key, T, Compare>::const_iterator::operator--() noexcept
    -> const_iterator & {
  node_ = prev_node(node_);
  return *this;
}

template <typename Key, typename T, typename Compare>
auto RBTree<Key, T, Compare>::const_iterator::operator++(int) noexcept
    -> const_iterator {
  const_iterator tmp = *this;
  node_ = next_node(node_);
  return tmp;
}

template <typename Key, typename T, typename Compare>
auto RBTree<Key, T, Compare>::const_iterator::operator--(int) noexcept
    -> const_iterator {
  const_iterator tmp = *this;
  node_ = prev_node(node_);
  return tmp;
}

template <typename Key, typename T, typename Compare>
bool RBTree<Key, T, Compare>::const_iterator::operator==(
    const const_iterator &other) const noexcept {
  return node_ == other.node_;
}

template <typename Key, typename T, typename Compare>
bool RBTree<Key, T, Compare>::const_iterator::operator!=(
    const const_iterator &other) const noexcept {
  return node_ != other.node_;
}

template <typename Key, typename T, typename Compare>
auto RBTree<Key, T, Compare>::begin() const noexcept -> iterator {
  return iterator(min(head_));
}

template <typename Key, typename T, typename Compare>
auto RBTree<Key, T, Compare>::end() const noexcept -> iterator {
  return iterator(head_);
}

}  // namespace s21
