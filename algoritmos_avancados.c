#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bst/bst.h"
#include "clue/clue.h"
#include "globals.h"
#include "hash/hash.h"
#include "room/room.h"
#include "suspect/suspect.h"
#include "utils/utils.h"

/* -------------------------
   Types / "Objects"
   -------------------------*/
HashEntry* hash_table[HASH_SIZE];
static SuspectCount* suspect_counts = NULL;
static BSTNode* bst_root = NULL;
static Room* mansion_global = NULL;

/* -------------------------
   Mansion construction (example)
   -------------------------*/

static Room* build_mansion(void) {
  /* create Clue objects (shared pointers) */
  Clue* c_note = clue_create("nota_enigmatica", "Sr. Oliveira");
  Clue* c_foot = clue_create("pegada", "Sra. Pereira");
  Clue* c_glass = clue_create("taca_quebrada", "Chef Gomes");
  Clue* c_blood = clue_create("fio_de_sangue", "Cozinheiro Alves");
  Clue* c_fiber = clue_create("fibra_de_tecido", "Srta. Lima");

  /* rooms */
  Room* hall = room_create("Hall de Entrada", NULL);
  Room* library = room_create("Biblioteca", c_note);
  Room* study = room_create("Escritório", c_foot);
  Room* conservatory = room_create("Conservatório", NULL);
  Room* dining = room_create("Sala de Jantar", c_glass);
  Room* kitchen = room_create("Cozinha", c_blood);
  Room* pantry = room_create("Despensa", NULL);
  Room* balcony = room_create("Varanda", c_fiber);
  Room* garden = room_create("Jardim", NULL);

  /* assemble binary tree */
  hall->left = library;
  hall->right = dining;

  library->left = study;
  library->right = conservatory;

  dining->left = kitchen;
  dining->right = pantry;

  study->left = balcony;
  study->right = garden;

  /* store global pointer for visualization */
  mansion_global = hall;

  return hall;
}

/* -------------------------
   ASCII Tree Visualization
   - prints rotated tree: right subtree first (top), root, left subtree (bottom)
   - shows [V] if visited and which clue was found there (if any)
   -------------------------*/
static void print_tree_ascii(Room* root, int level) {
  if (!root) return;

  print_tree_ascii(root->right, level + 1);
  for (int i = 0; i < level; ++i) printf("       ");
  printf("%s %s", root->visited ? "[V]" : "[ ]", root->name_pt);
  if (root->found_clue_name) {
    printf("  -> pista: %s", root->found_clue_name);
  }

  printf("\n");

  print_tree_ascii(root->left, level + 1);
}

/* -------------------------
   Final Report
   -------------------------*/

static void show_report(void) {
  printf("\n===== Relatório da Investigação =====\n");

  printf("\nPistas coletadas (ordem alfabética):\n");
  if (!bst_root) {
    printf("Nenhuma pista cadastrada.\n");
  } else {
    bst_inorder_print(bst_root);
  }

  printf("\nAssociações (pista -> suspeito):\n");
  hash_print_all(hash_table);

  printf("\nContagem por suspeito:\n");
  if (!suspect_counts) {
    printf("Nenhum suspeito associado.\n");
  } else {
    suspect_counts_print(suspect_counts);
    char* most = suspect_most_cited(suspect_counts);
    if (most) {
      printf("\nSuspeito mais citado: %s\n", most);
    }
  }

  printf("\n=========== Mapa da Mansão ===========\n");
  printf("Legenda: [V] visitado | [ ] não visitado\n\n");
  print_tree_ascii(mansion_global, 0);

  printf("\n=====================================\n");
}

/* -------------------------
   Cleanup
   -------------------------*/

/* The cleanup function frees all dynamically allocated memory:
   - BST, hash table, and suspect counts are freed directly.
   - Clue objects are freed by traversing the mansion tree
   (free_clues_from_mansion), ensuring each clue is freed once, rather than
   individually.
   - The room tree itself is then freed. */
static void cleanup(Room* mansion) {
  /* free BST, hash, suspect counts */
  bst_free(bst_root);
  hash_free_all(hash_table);
  suspect_counts_free(&suspect_counts);

  /* free clue objects via mansion tree traversal */
  free_clues_from_mansion(mansion);

  /* free room tree */
  room_free_recursive(mansion);
}

/* -------------------------
   main
   -------------------------*/

int main(void) {
  /* initialize hash table */
  for (int i = 0; i < HASH_SIZE; ++i) hash_table[i] = NULL;

  /* build mansion graph and clues */
  Room* mansion = build_mansion();
  if (!mansion) {
    fprintf(stderr, "Erro ao construir a mansão.\n");
    return EXIT_FAILURE;
  }

  printf("=== Detective Quest: Mestre ===\n");
  printf(
      "Comandos durante a exploração: e (esquerda), d (direita), s (sair)\n");

  explore_rooms(mansion, &bst_root, &suspect_counts, hash_table);

  show_report();

  cleanup(mansion);

  return 0;
}
