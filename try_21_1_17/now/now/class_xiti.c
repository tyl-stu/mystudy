

//单值二叉树！！！！！！！！！！！！！！！！！！！！！！！！！！！
bool _isUnivalTree(struct TreeNode *root, int val)
{
	if (root)//节点非空时  不会与NULL作比较，只是与值作比较
	{
		return root->val == val && _isUnivalTree(root->left, val) && _isUnivalTree(root->right, val);

	}
	return true;//节点空时
}
bool isUnivalTree(struct TreeNode *root)
{
	if (root == NULL)//空树也认为是单值二叉树
		return true;
	return _isUnivalTree(root, root->val);
}


//翻转二叉树！！！！！！！！！！！！！！！！！！！！！！！！！！！！
struct TreeNode *invertTree(struct TreeNode *root)
{
	if (root == NULL)
		return NULL;

	struct TreeNode * left = root->left;
	struct TreeNode * right = root->right;
	struct TreeNode * t;

	t = left;
	left = right;
	right = t;

	invertTree(left);//用递归，就不用想着用while来使二叉树到最后一个节点
	invertTree(right);

	return root;
}


//检查两个树是否相同！！！！！！！！！！！！！！！！！！！！！！！！！！1
/*按照相同的遍历顺序：保证遍历的每一个节点，位置都相同；
  若同时到达空节点：相同
  没有同时到达空节点：不相同*/
bool inSameTree(struct TreeNode *p, struct TreeNode *q)
{
	if (p == NULL && q == NULL)//两个为空
		return true;
	if (p == NULL || q == NULL)//没有同时到达NULL  一个为空，一个非空
		return false;
	
	return p->val == q->val && inSameTree(p->left, q->left) && inSameTree(p->right, q->right);
	
}


/*判断是否为子树  判断s的某一个结构和t是否相同！！！！！！！！！！！！！！！！！*/
//bool isSubtree(struct TreeNode *s, struct TreeNode *t)
//{
//	if (s == NULL && t == NULL)
//		return true;
//	if (s->left == t)
//		return s->ledft->val == t->val && isSubtree(s->left, t->left) && isSubtree(s->right,t->right);
//	if (s->right == t)
//		return s->right->val == t->val && isSubtree(s->left, t->left) && isSubtree(s->right, t->right);
//	return false;
//}
bool isSameTree(struct TreeNode *p, struct TreeNode *q)
{
	if (p == NULL && q == NULL)//两个为空
		return true;
	if (p == NULL || q == NULL)//没有同时到达NULL  一个为空，一个非空
		return false;

	return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

}
bool isSubtree(struct TreeNode *s, struct TreeNode *t)
{
	if (t == NULL)
		return true;
	if (s == NULL)
		return false;
	return isSameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
}


//判断树是否是镜像对称的！！！！！！！！！！！！！！！！！！！！！！！！！！
/* node1->left == node2->right
   node1->right == node2->left
*/
bool _isSym(struct TreeNode *left, struct TreeNode *right)
{
	if (left == NULL && right == NULL)
		return true;
	if (left == NULL || right == NULL)
		return false;
	return left->val == right->val && _isSym(left->left, right->right) && _isSym(left->right, right->left);
}
bool isSymmetric(TreeNode *root)
{
	if (root == NULL)
		return true;
	return _isSym(root->left, root->right);
}


//判断一个二叉树是否是高度平衡二叉树！！！！！！！！！！！！！！！！！！！！！！！！！
//高度平衡二叉树：一个二叉树每个节点的左右两个子例的高度差的绝对值不超过1
int getHeight(struct TreeNode *root)
{
	if (root)
	{
		int left = getHeight(root->left);
		int right = getHeight(root->right);
		return left > right ? left + 1 : right + 1;
	}
	return 0;
}
bool isBalance(struct TreeNode *t)
{
	if (root == NULL)
		return true;
	int left = getHeight(root->left);
	int right = getHeight(root->right);
	//当前节点左右子树高度差 < 2
	return abs(left - right) < 2 && isBalance(root->left) && isBalance(root->right);

}


//二叉树的前序遍历！！！！！！！！！！！！！！！！！！1111
int getSize(struct TreeNode *root)
{
	if (root)
	{
		return getSize(root->left) + getSize(root->right) + 1;
	}
	return 0;
}
//递归遍历
void preOrder(struct TreeNode * root,int *arr,int *idx)
{
	if (root)
	{
		arr[*idx] = root->val;
		(*idx)++;
		preOrder(root->left, arr, idx);
		preOrder(root->right, arr, idx);
	}
}
int *preOrderTraversal(struct TreeNode *root,int *returnSize)
{
	int sz = getSize(root);
	int *arr = (int *)malloc(sizeof(int)*sz);
	int idx = 0;
	preOrder(root, arr, &idx);
	*returnSize = idx;
	return arr;
}
//非递归二叉树前向遍历   利用栈
typedef struct TreeNode * STDataType;
//顺序结构实现：实现一个更简单的顺序表
typedef struct stack
{
	STDataType *_data;
	int _size;
	int _capacity;
}stack;

void initStack(stack *st)
{
	//空栈
	if (st == NULL)
		return;
	st->_data = NULL;
	st->_size = st->_capacity = 0;
}

void checkCapacity(stack *st)
{
	if (st->_size == st->_capacity)
	{
		int newCap = st->_capacity == 0 ? 1 : 2 * st->_capacity;
		st->_data = (STDataType*)realloc(st->_data, sizeof(STDataType)*newCap);
		st->_capacity = newCap;
	}
}

void stackPush(stack *st, STDataType val)
{
	//尾插
	if (st == NULL)
		return;
	checkCapacity(st);
	st->_data[st->_size++] = val;
}

void stackPop(stack *st)
{
	//尾删
	if (st == NULL || st->_size == 0)
		return;
	--st->_size;
}

int stackSize(stack *st)
{
	if (st == NULL)
		return 0;
	return st->_size;
}

int stackEmpty(stack* st)
{
	if (st == NULL || st->_size == 0)
		return 1;//返回1为空
	else
		return 0;
	//return st->_size;
}

STDataType stackTop(stack *st)
{
	return st->_data[st->_size - 1];//栈顶元素
}

int *preOrderTraversal(struct TreeNode *root, int *returnSize)
{
	int sz = getSize(root);
	int *arr = (int *)malloc(sizeof(int)*sz);
	stack st;
	initStack(&st);
	int idx = 0;
	//当前遍历的节点不为空，或者栈不为空
	while (root || stackEmpty(&st))
	{
		//1、访问最左路径
		while (root)
		{
			arr[idx++] = root->val;
			//当前节点入栈
			stackPush(&st, root);
			root = root->left;
		}
		//2、获取栈顶元素，访问右子树
		root = stackTop(&st);
		stackPop(&st);
		root = root->right;

	}
	*returnSize = idx;
	return arr;
}


//二叉树的中序遍历！！！！！！！！！！！！！！！！！！！！！！！！！！！！
//递归遍历
void inOrder(struct TreeNode * root, int *arr, int *idx)
{
	if (root)
	{
		preOrder(root->left, arr, idx);
		arr[*idx] = root->val;
		(*idx)++;
		preOrder(root->right, arr, idx);
	}
}
int *inOrderTraversal(struct TreeNode *root, int *returnSize)
{
	int sz = getSize(root);
	int *arr = (int *)malloc(sizeof(int)*sz);
	int idx = 0;
	preOrder(root, arr, &idx);
	*returnSize = idx;
	return arr;
}
//非递归中序遍历 利用栈
int *inOrderTraversal(struct TreeNode *root, int *returnSize)
{
	int sz = getSize(root);
	int *arr = (int *)malloc(sizeof(int)*sz);
	stack st;
	initStack(&st);
	int idx = 0;
	//当前遍历的节点不为空，或者栈不为空
	while (root || stackEmpty(&st))
	{
		//1、访问最左路径
		while (root)
		{
			//arr[idx++] = root->val;
			//当前节点入栈
			stackPush(&st, root);
			root = root->left;
		}
		//2、获取栈顶元素，访问右子树
		root = stackTop(&st);
		stackPop(&st);
		arr[idx++] = root->val;//数组存入元素
		root = root->right;

	}
	*returnSize = idx;
	return arr;
}


//二叉树的后序遍历！！！！！！！！！！！！！！！！！！！！！！！！！1111
//递归遍历
void postOrder(struct TreeNode * root, int *arr, int *idx)
{
	if (root)
	{
		preOrder(root->left, arr, idx);
		preOrder(root->right, arr, idx);
		arr[*idx] = root->val;
		(*idx)++;
	}
}
int *postOrderTraversal(struct TreeNode *root, int *returnSize)
{
	int sz = getSize(root);
	int *arr = (int *)malloc(sizeof(int)*sz);
	int idx = 0;
	preOrder(root, arr, &idx);
	*returnSize = idx;
	return arr;
}
//非递归后序遍历  利用栈
int *postOrderTraversal(struct TreeNode *root, int *returnSize)
{
	int sz = getSize(root);
	int *arr = (int *)malloc(sizeof(int)*sz);
	stack st;
	initStack(&st);
	int idx = 0;
	//prev : 上一次访问的节点
	struct TreeNode *prev = NULL;
	//当前遍历的节点不为空，或者栈不为空
	while (root || stackEmpty(&st))
	{
		//1、访问最左路径
		while (root)
		{
			//当前节点入栈
			stackPush(&st, root);
			root = root->left;
		}
		//top:栈顶节点
		struct TreeNode *top = stackTop(&st);
		//判断栈顶元素是否可以访问
		//可以访问：栈顶元素没有右子树 或 右子树访问完成
		//右子树访问：上一次访问的节点为右子树的根节点
		if (top->right == NULL || top->right == prev)
		{
			//可以访问当前栈顶元素
			arr[idx++] = top->val;//数组存入元素
			stackPop(&st);
			//更新prev
			prev = top;
		}
		else
			//右子树没有访问，首先访问右子树
			root = top->right;
	}
	*returnSize = idx;
	return arr;
}
