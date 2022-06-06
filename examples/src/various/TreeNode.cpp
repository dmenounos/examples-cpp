#include <iostream>
#include <memory>
#include <queue>

template<typename T>
class TreeNode {

public:
	TreeNode(
		const T& n, 
		std::unique_ptr<TreeNode> left = nullptr, 
		std::unique_ptr<TreeNode> right = nullptr
	) : 
	_value(n), 
	_left(std::move(left)), 
	_right(std::move(right)) {
	}

	const T& getValue() const {
		return _value;
	}

	TreeNode* left() const {
		return _left.get();
	}

	TreeNode* right() const {
		return _right.get();
	}

	void preorderTraverse() const {
		std::cout << " " << getValue();
		if (_left)  { _left->preorderTraverse(); }
		if (_right) { _right->preorderTraverse(); }
	}

	void postorderTraverse() const {
		if (_left)  { _left->postorderTraverse(); }
		if (_right) { _right->postorderTraverse(); }
		std::cout << " " << getValue();
	}

	void levelorderTraverse() const {
		std::queue<const TreeNode*> q;
		q.push(this);
 
		while (!q.empty()) {
			const TreeNode* n = q.front();
			q.pop();

			std::cout << " " << n->getValue();
 
			if (n->left())  { q.push(n->left()); }
			if (n->right()) { q.push(n->right()); }
		}
	}

protected:
	T _value;
	std::unique_ptr<TreeNode> _left;
	std::unique_ptr<TreeNode> _right;

private:
	TreeNode();
};

int main() {
	auto root = 
	std::make_unique<TreeNode<int>>(1,
		std::make_unique<TreeNode<int>>(2,
			std::make_unique<TreeNode<int>>(4,
				std::make_unique<TreeNode<int>>(7)
			),
			std::make_unique<TreeNode<int>>(5)
		),
		std::make_unique<TreeNode<int>>(3,
			std::make_unique<TreeNode<int>>(6,
				std::make_unique<TreeNode<int>>(8),
				std::make_unique<TreeNode<int>>(9)
			)
		)
	);

	std::cout << "preorder    : ";
	root->preorderTraverse();
	std::cout << std::endl;

	std::cout << "postorder   : ";
	root->postorderTraverse();
	std::cout << std::endl;

	std::cout << "level-order : ";
	root->levelorderTraverse();
	std::cout << std::endl;

	return 0;
}
