#include <ctype.h>
#include <stdio.h>

#include "../clue/clue.h"
#include "../utils/utils.h"
#include "room.h"

/* -------------------------
   Exploration (interactive)
   -------------------------*/

void explore_rooms(Room* start, BSTNode** bst_root,
                   SuspectCount** suspect_counts, HashEntry** hash_table) {
  if (!start) return;

  Room* current = start;
  char option_buffer[64];

  printf("Você está na mansão. Iniciando em: %s\n", current->name_pt);

  while (current) {
    printf("\nSala atual: %s\n", current->name_pt);
    current->visited = 1;

    if (current->clue) {
      printf("Você encontrou uma pista!\n");
      printf("Pista: %s\n", current->clue->name);
      collect_clue(current, bst_root, suspect_counts, hash_table);
    } else {
      printf("Nenhuma pista nesta sala.\n");
    }

    /* If leaf node, end navigation automatically (no children) */
    if (!current->left && !current->right) {
      printf("Você atingiu o fim do caminho.\n");
      break;
    }

    printf("Escolha uma direção: (e = esquerda, d = direita, s = sair)\n> ");
    if (!fgets(option_buffer, sizeof(option_buffer), stdin)) break;

    trim_newline_and_spaces(option_buffer);
    if (option_buffer[0] == '\0') {
      printf("Opção inválida. Use 'e', 'd' ou 's'.\n");
      continue;
    }

    char c = (char)tolower((unsigned char)option_buffer[0]);
    if (c == 's') {
      printf("Saindo da exploração...\n");
      break;
    }

    else if (c == 'e') {
      if (current->left)
        current = current->left;
      else
        printf("Não há caminho à esquerda. Tente outra opção.\n");
    }

    else if (c == 'd') {
      if (current->right)
        current = current->right;
      else
        printf("Não há caminho à direita. Tente outra opção.\n");
    }

    else {
      printf("Opção inválida. Use 'e', 'd' ou 's'.\n");
    }
  }

  printf("\nExploração encerrada.\n");
}
