#include "dlx_algorithm.h"

/*
* add tetromino on board, according to given coords
*/


/*
* input: tetromino element name, tetromino element coords
* action: rewrite coordinates while possible add x_nodes on board
* output: none
*/

/*
* Function to create new empty x_node structure
*/
x_node  *create_x_node(col_obj input_C, int input_row_num, int letter_num)
{
    x_node  *new_node;

    new_node = (x_node *)malloc(sizeof(x_node));
    new_node->right = NULL;
    new_node->left = NULL;
    new_node->up = NULL;
    new_node->down = NULL;
    new_node->C = input_C;
    new_node->row_num = input_row_num;
    new_node->letter = letter_num;
    return (new_node);
}

/*
* Function to create new empty col_obj structure
*/
col_obj *create_col_obj(x_node *obj, int x, int y)
{
    col_obj *new_co;

    new_co = (col_obj *)malloc(sizeof(col_obj));
    new_co->size = 0;
    new_co->list_header = obj;
    new_co->x = x;
    new_co->y = y;
    obj->C = &new_co;
    return (new_co);
}

/*
 * add x_node to list of x_nodes, to the rightmost position
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


x_node     *create_xnode_list(int size, int letter)
{
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
 * create right & left linked list of x_nodes for headers list
 */
x_node  *create_xnode_list(int size, int letter)
{
  int   square;

  square = size * size + 1;
  root_xnode = create_x_node(NULL, letter);
  while(square-- >= 0)
  {
    if (square == 0)
        ft_xnode_add_toend(root_xnode, create_x_node(root_xnode, letter));
    ft_xnode_add_toend(root_xnode, create_x_node(NULL, letter));
  }
  return(root_xnode);
}

/*
 * create list of headers aka column objects according to the number of square board size + root element
 */
void    create_headers_list(x_node *root, int size)
{
  int     x;
  int     y;
  x_node  *next_xnode;

  next_xnode = root->right;
  y = 0;
  x = 0;
  while (next_xnode->right != root)
  {
    if (x > size)
      {
        x = 0;
        y++;
      }
    create_col_obj(next_xnode, x, y);
    next_xnode = next_xnode->right;
    x++;
  }
}
