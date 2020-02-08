#include "dlx_algorithm.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "fillit.h"

/*
* Function to create new empty x_node structure
*/
x_node  *create_x_node(int letter_num)
{
    x_node  *new_node;
    printf("%s\n","ENTERED dlx_structures_routine.c/create_x_node :12");

    new_node = (x_node *)malloc(sizeof(x_node));
    new_node->right = NULL;
    new_node->left = NULL;
    new_node->up = NULL;
    new_node->down = NULL;
    new_node->C = NULL;
    new_node->letter = letter_num;
    printf("%d\n", letter_num);
    return (new_node);
}

/*
* Function to create new empty col_obj structure
*/
col_obj *create_col_obj(x_node *obj, int x, int y)
{
    col_obj *new_co;
    printf("%s\n","ENTERED dlx_structures_routine.c/create_col_obj :29");

    new_co = (col_obj *)malloc(sizeof(col_obj));
    new_co->size = 0;
    new_co->x = x;
    new_co->y = y;
    obj->C = new_co;
    return (new_co);
}

/*
 * function to connect x_nodes vertically, while adding to a board
 */
void    connect_vertical(x_node *x_new, x_node *column)
{
  x_node  *x_last;
  printf("%s\n","ENTERED dlx_structures_routine.c/connect_vertical :45");

  int counter = 0;
  x_last = column->down;
  printf("%s\n", ":50");
  while(x_last->down != column)
  {
      printf("%d %s\n", counter, "times no segs :54");
      x_last = x_last->down;
      counter++;
  }
  printf("%s\n", ":53");
  x_last->down = x_new;
  x_new->down = column;
  column->up = x_new;
  x_new->up = x_last;
}

/*
 * add tetromino on board, according to given coords
 * 1. run through col_obj, while not found needed pair of coords
 * 2. in that exact spot, where coords are the same - create x_node (also save
 * its pointer, also link it to col_obj, also link it to the higher x_nodes, if they exist)
*/
void    add_to_board(int name, int x[4], int y[4], x_node *root)
{
    int     num;
    x_node  *x_next;
    x_node  *x_start;
    x_node  *x_last;
    //x_node  *x_fixed;
    printf("%s\n","ENTERED dlx_structures_routine.c/add_to_board :69");

    num = 0;
    x_next = root;
    //x_fixed = root->right;
    while (num < 4)
    {
        // TODO: when x_next->letter == 24, loop turns infinite
        printf("%s %d\n", "num", num);
        x_next = x_next->right;
        while (x_next != root)
        {
            printf("%s %d\n", "letter ", x_next->letter);
            if (x_next->C->x == x[num] && x_next->C->y == y[num])
            {
                if(num == 0)
                {
                  printf("%s\n", "create_node_ :88");
                  x_start = create_x_node(name);
                  connect_vertical(x_start, x_next);
                }
                else
                {
                  printf("%s\n", "create_node_ :94");
                  x_last = create_x_node(name);
                  connect_vertical(x_last, x_next);
                }
                ft_xnode_add_toend(x_start, x_last);
                x_next = x_next->right;
            }
        }
        num++;
    }
}

// TODO:
/*
* input: tetromino element name, tetromino element coords
* action: rewrite coordinates while possible add x_nodes on board
* output: none
*/
void add_all_tetromino_positions(d_list *tetro, x_node *root, int square_size)
{
  d_list *tnext;
  printf("%s\n","ENTERED dlx_structures_routine.c/create_col_obj :29");

  tnext = tetro;
  while(tnext->next != tetro)
  {
    add_to_board(tnext->content_size, tnext->x_coords, tnext->y_coords, root);
    while((move_tetromino_once(square_size, tnext->x_coords, tnext->y_coords)))
      add_to_board(tnext->content_size + 64, tnext->x_coords, tnext->y_coords, root);
    tnext = tnext->next;
  }
}

/*
 * add x_node to list of x_nodes, to the rightmost position
 */
void	ft_xnode_add_toend(x_node* head_ref, x_node *new_node)
{
    x_node* last;
    printf("%s\n","ENTERED dlx_structures_routine.c/ft_xnode_add_toend :126");

    last = head_ref;

    new_node->right = NULL;

    if (head_ref == NULL) {
        new_node->left = new_node;
        new_node->right = new_node;
        head_ref = new_node;
        return;
    }

    while (last->right != head_ref)
        last = last->right;

    last->right = new_node;
    new_node->left = last;
    new_node->right = head_ref;
    return;
}

/*
 * create right & left linked list of x_nodes for headers list
 */
x_node  *create_xnode_list(int size, int letter)
{
  int   square;
  x_node    *root_xnode;
  //x_node    *other_xnode;
  printf("%s\n","ENTERED dlx_structures_routine.c/create_xnode_list :153");

  printf("%s\n %d\n", "IT IS SIZE ", size);
  square = size * size + 1;
  root_xnode = create_x_node(letter);
  while(square-- >= 0)
  {
      ft_xnode_add_toend(root_xnode, create_x_node(square));
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
  int     counter;
  printf("%d\n %s\n", size, "ENTERED dlx_structures_routine.c/create_headers_list :174");


  next_xnode = root->right;
  y = 0;
  x = 0;
  counter = 0;
  while (counter++ < (size * size))
  {
    if (x >= size)
      {
        x = 0;
        y++;
      }
    create_col_obj(next_xnode, x, y);
    printf("%d %d %d\n", x, y, counter);
    next_xnode = next_xnode->right;
    x++;
  }
}
