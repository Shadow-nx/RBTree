#include <fstream>
#include <iostream>
#include <vector>

namespace BSTree {
	enum {RED, BLACK};
	struct Node {
		int data;
		Node *left;
		Node *right;
		Node *parent;
		short color;
	};
	class Tree {
		private:
			Node* root;
			auto insert_fixup(Node *value) -> void;
			auto insert(Node *&value) -> void;
			auto show_tree(Node* root,int stage)->void;
			auto delete_tree(Node *&node) -> void;
			auto left_rotate(Node*) -> void;
			auto right_rotate(Node*) -> void;
			auto rb_transplant(Node* ,Node*) -> void;
			auto rb_delete(Node* z) -> void;
			auto tree_minimum(Node* x) -> Node*;
			auto rb_delete_fixup(Node* z) -> void;
		public:
			Tree();
			auto show_tree(int stage) -> void;
			auto show(Node* root, std::ostream& os, int stage) const -> void;
			auto friend operator<<(std::ostream& os, const Tree& tr) -> std::ostream&;
			auto insert(int value) -> void;
			~Tree();
	};
}
