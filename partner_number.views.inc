<?php
/**
 * @file
 * Views Implementation for partner_number.
 */

/**
 * Implements hook_views_data_alter().
 */
function partner_number_views_data_alter(&$data) {
  // Field
  $data['users']['partner_num_ab'] = array(
    'title' => t('Alumni bold partner number.'),
    'help' => t('Alumni bold partner number.'),
    'field' => array(
      'handler' => 'views_handler_field', 
      'click sortable' => TRUE,
    ), 
    'sort' => array(
      'handler' => 'views_handler_sort',
    ), 
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ), 
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  // Field
  $data['users']['partner_num_e'] = array(
    'title' => t('Enterprise partner number.'),
    'help' => t('Enterprise partner number.'),
    'field' => array(
      'handler' => 'views_handler_field', 
      'click sortable' => TRUE,
    ), 
    'sort' => array(
      'handler' => 'views_handler_sort',
    ), 
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ), 
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
}
