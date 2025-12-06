#include <stdio.h>
#include <stdlib.h>

#include "../clue/clue.h"
#include "../utils/utils.h"
#include "room.h"

Room* room_create(const char* name_pt, Clue* clue) {
  Room* room_ptr = malloc(sizeof(Room));
  if (!room_ptr) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }

  room_ptr->name_pt = string_duplicate_safe(name_pt);
  room_ptr->clue = clue; /* may be NULL or pointer to shared Clue */
  room_ptr->visited = 0;
  room_ptr->found_clue_name = NULL;
  room_ptr->left = room_ptr->right = NULL;
  return room_ptr;
}
