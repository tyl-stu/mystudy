

//��ֵ������������������������������������������������������������
bool _isUnivalTree(struct TreeNode *root, int val)
{
	if (root)//�ڵ�ǿ�ʱ  ������NULL���Ƚϣ�ֻ����ֵ���Ƚ�
	{
		return root->val == val && _isUnivalTree(root->left, val) && _isUnivalTree(root->right, val);

	}
	return true;//�ڵ��ʱ
}
bool isUnivalTree(struct TreeNode *root)
{
	if (root == NULL)//����Ҳ��Ϊ�ǵ�ֵ������
		return true;
	return _isUnivalTree(root, root->val);
}


//��ת��������������������������������������������������������������
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

	invertTree(left);//�õݹ飬�Ͳ���������while��ʹ�����������һ���ڵ�
	invertTree(right);

	return root;
}


//����������Ƿ���ͬ����������������������������������������������������1
/*������ͬ�ı���˳�򣺱�֤������ÿһ���ڵ㣬λ�ö���ͬ��
  ��ͬʱ����սڵ㣺��ͬ
  û��ͬʱ����սڵ㣺����ͬ*/
bool inSameTree(struct TreeNode *p, struct TreeNode *q)
{
	if (p == NULL && q == NULL)//����Ϊ��
		return true;
	if (p == NULL || q == NULL)//û��ͬʱ����NULL  һ��Ϊ�գ�һ���ǿ�
		return false;
	
	return p->val == q->val && inSameTree(p->left, q->left) && inSameTree(p->right, q->right);
	
}


/*�ж��Ƿ�Ϊ����  �ж�s��ĳһ���ṹ��t�Ƿ���ͬ����������������������������������*/
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
	if (p == NULL && q == NULL)//����Ϊ��
		return true;
	if (p == NULL || q == NULL)//û��ͬʱ����NULL  һ��Ϊ�գ�һ���ǿ�
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


//�ж����Ƿ��Ǿ���ԳƵģ���������������������������������������������������
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


//�ж�һ���������Ƿ��Ǹ߶�ƽ���������������������������������������������������������
//�߶�ƽ���������һ��������ÿ���ڵ���������������ĸ߶Ȳ�ľ���ֵ������1
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
	//��ǰ�ڵ����������߶Ȳ� < 2
	return abs(left - right) < 2 && isBalance(root->left) && isBalance(root->right);

}


//��������ǰ�����������������������������������������1111
int getSize(struct TreeNode *root)
{
	if (root)
	{
		return getSize(root->left) + getSize(root->right) + 1;
	}
	return 0;
}
//�ݹ����
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
//�ǵݹ������ǰ�����   ����ջ
typedef struct TreeNode * STDataType;
//˳��ṹʵ�֣�ʵ��һ�����򵥵�˳���
typedef struct stack
{
	STDataType *_data;
	int _size;
	int _capacity;
}stack;

void initStack(stack *st)
{
	//��ջ
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
	//β��
	if (st == NULL)
		return;
	checkCapacity(st);
	st->_data[st->_size++] = val;
}

void stackPop(stack *st)
{
	//βɾ
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
		return 1;//����1Ϊ��
	else
		return 0;
	//return st->_size;
}

STDataType stackTop(stack *st)
{
	return st->_data[st->_size - 1];//ջ��Ԫ��
}

int *preOrderTraversal(struct TreeNode *root, int *returnSize)
{
	int sz = getSize(root);
	int *arr = (int *)malloc(sizeof(int)*sz);
	stack st;
	initStack(&st);
	int idx = 0;
	//��ǰ�����Ľڵ㲻Ϊ�գ�����ջ��Ϊ��
	while (root || stackEmpty(&st))
	{
		//1����������·��
		while (root)
		{
			arr[idx++] = root->val;
			//��ǰ�ڵ���ջ
			stackPush(&st, root);
			root = root->left;
		}
		//2����ȡջ��Ԫ�أ�����������
		root = stackTop(&st);
		stackPop(&st);
		root = root->right;

	}
	*returnSize = idx;
	return arr;
}


//�����������������������������������������������������������������������
//�ݹ����
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
//�ǵݹ�������� ����ջ
int *inOrderTraversal(struct TreeNode *root, int *returnSize)
{
	int sz = getSize(root);
	int *arr = (int *)malloc(sizeof(int)*sz);
	stack st;
	initStack(&st);
	int idx = 0;
	//��ǰ�����Ľڵ㲻Ϊ�գ�����ջ��Ϊ��
	while (root || stackEmpty(&st))
	{
		//1����������·��
		while (root)
		{
			//arr[idx++] = root->val;
			//��ǰ�ڵ���ջ
			stackPush(&st, root);
			root = root->left;
		}
		//2����ȡջ��Ԫ�أ�����������
		root = stackTop(&st);
		stackPop(&st);
		arr[idx++] = root->val;//�������Ԫ��
		root = root->right;

	}
	*returnSize = idx;
	return arr;
}


//�������ĺ��������������������������������������������������������1111
//�ݹ����
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
//�ǵݹ�������  ����ջ
int *postOrderTraversal(struct TreeNode *root, int *returnSize)
{
	int sz = getSize(root);
	int *arr = (int *)malloc(sizeof(int)*sz);
	stack st;
	initStack(&st);
	int idx = 0;
	//prev : ��һ�η��ʵĽڵ�
	struct TreeNode *prev = NULL;
	//��ǰ�����Ľڵ㲻Ϊ�գ�����ջ��Ϊ��
	while (root || stackEmpty(&st))
	{
		//1����������·��
		while (root)
		{
			//��ǰ�ڵ���ջ
			stackPush(&st, root);
			root = root->left;
		}
		//top:ջ���ڵ�
		struct TreeNode *top = stackTop(&st);
		//�ж�ջ��Ԫ���Ƿ���Է���
		//���Է��ʣ�ջ��Ԫ��û�������� �� �������������
		//���������ʣ���һ�η��ʵĽڵ�Ϊ�������ĸ��ڵ�
		if (top->right == NULL || top->right == prev)
		{
			//���Է��ʵ�ǰջ��Ԫ��
			arr[idx++] = top->val;//�������Ԫ��
			stackPop(&st);
			//����prev
			prev = top;
		}
		else
			//������û�з��ʣ����ȷ���������
			root = top->right;
	}
	*returnSize = idx;
	return arr;
}
