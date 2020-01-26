#include "dlx_algorithm.h"
#include "dlx_algorithm.c"

/*
* find int square root
*/
int sqrt_root(int number)
{
  int   root;
  int   result;

  root = 1;
  result = 1;
  if (number == 0 || number == 1)
  return number;
  while (result <= number)
  {
    root++;
    result = root * root;
  }
  return root - 1;
}

/*
* find size of the board
*/
int find_field_size(int tetro_num)
{
    int     size;

    size = sqrt_root(num * 4);
    return size;
}

/*
 * add x_node to list of x_nodes
 */
void	ft_xnode_add_toend(x_node** head_ref, x_node *new_node)
{
    x_list* last = *head_ref;

    new_node->right = NULL;

    if (*head_ref == NULL) {
        new_node->left = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->right != NULL)
        last = last->right;

    last->right = new_node;
    new_node->left = last;
    return;
}

/*
 * create right & left linked list of x_nodes for headers list
 */
x_node     *create_xnode_list(int size, int letter)
{
    /*
     * TODO: think how count numerics
     */
    int     x;
    int     y;
    x_node  *root_xnode;
    x_node  *next_xnode;

    root_xnode = create_x_node(NULL, letter);
    root_colobj = create_col_obj(, x, y);
    y = -1;
    while (y++ < size)
    {
        if (x == size && y == size)
            ft_xnode_add_toend(root_xnode, create_x_node(root_xnode, letter));
        x = -1;
        while (x++ < size)
            ft_xnode_add_toend(root_xnode, create_x_node(NULL, letter));
    }
      return (root_xnode);
}

/*
 * create list of headers aka column objects according to the number of square board size + root element
 */
void    create_headers_list(x_node *root)
{
    // TODO: add x & y like in previous func
    x_node  *next_xnode;

    next_xnode = root->right;
    while (next_xnode->right != root)
    {
        create_col_obj(next_xnode)
        next_xnode = next_xnode->right;
    }


}