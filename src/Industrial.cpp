#include "Industrial.h"

#include <cstdlib>

#include "Constants.h"
#include "Status_grid.h"

using std::vector;
using std::map;

void Industrial::update_state(const vector<vector<Cell*> >& grid, map<int, Status_grid*>& status_grids)
{
  if ((status_grids[ROAD_ADJACENCY]->get_grid())[y][x] == 1)
  {
    if (state == UNDEVELOPED && rand()%100 < 75)
    {
      state = DEVELOPED;
    }
    else if (state == DEVELOPED && rand()%100 < 25)
    {
      state = UNDEVELOPED; 
    }
  }
  else
  {
    state = UNDEVELOPED; 
  }
}

unsigned char Industrial::draw(const vector<vector<Cell*> >& grid, int& color_pair)
{
  color_pair = YELLOW;

  if (state == DEVELOPED)
  {
    return '#';
  }

  return '.';
}
