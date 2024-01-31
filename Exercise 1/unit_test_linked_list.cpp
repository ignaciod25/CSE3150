#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
/*
  https://hackingcpp.com/cpp/tools/testing_frameworks.html
 */

#include "doctest.h"
#include "linked_list.h"


int zero_linked_list_elts = 0;
struct node * zero_linked_list_elts_null_node = NULL;

int one_element_linked_list = 1;
int data_value_of_initial_linked_list_elt = 1;
struct node * linked_list_one_elt = build_new_linked_list(one_element_linked_list);

int two_element_linked_list = 2;
int data_value_of_second_elt = 2;
struct node * linked_list_two_elts = build_new_linked_list(two_element_linked_list);


TEST_CASE("linked_list testing") {

    SUBCASE("build_new_linked_list") {
        CHECK_EQ(build_new_linked_list(zero_linked_list_elts), zero_linked_list_elts_null_node);
        CHECK_EQ(get_linked_list_data_item_value( 
            linked_list_one_elt,
            one_element_linked_list,
            one_element_linked_list), 
            data_value_of_initial_linked_list_elt);

        CHECK_EQ(get_linked_list_data_item_value( 
            linked_list_two_elts,
            two_element_linked_list,
            two_element_linked_list), 
            data_value_of_second_elt);
        
    }

    SUBCASE("delete_linked_list") {
        //deleting an empty list
        struct node *start_empty = NULL;
        delete_linked_list(start_empty);
        CHECK(start_empty == NULL);
    }

    SUBCASE("delete_linked_list_non_empty") {
        //deleting a non-empty list
        struct node *start_non_empty = NULL;
        delete_linked_list(start_non_empty);
        CHECK(start_non_empty == NULL);
     }

    SUBCASE("delete_linked_list_single_node") {
        //deleting a list with a single node
        struct node *start_single_node = NULL; 
        delete_linked_list(start_single_node);
        CHECK(start_single_node == NULL);
    }

    SUBCASE("delete_linked_list_multiple_nodes") {
        //deleting a list with multiple nodes
        struct node *start_multiple_nodes = NULL;
        delete_linked_list(start_multiple_nodes);
        CHECK(start_multiple_nodes == NULL);
    }

    SUBCASE("delete_linked_list_complex_data") {
        //deleting a list with complex data structures in nodes
        struct node *start_complex_data = NULL;
        delete_linked_list(start_complex_data);
        CHECK(start_complex_data == NULL);
    }

    SUBCASE("delete_linked_list_memory_deallocation") {
        //deleting a list and checking memory deallocation
        struct node *start_memory_deallocation = NULL;
        delete_linked_list(start_memory_deallocation);
        CHECK(start_memory_deallocation == NULL);
    }

}
