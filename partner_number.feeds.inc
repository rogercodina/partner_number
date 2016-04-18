<?php

/**
 * @file
 * Feeds target for partner numbers.
 */

/**
 * Implementation of hook_feeds_node_processor_targets_alter().
 */
function partner_number_feeds_processor_targets_alter(&$targets, $entity_type, $bundle_name) {
  if ($entity_type == 'user') {
    $targets['partner_num_ab'] = array(
      'name' => t('Alumni bold partner number.'),
      'description' => t('Alumni bold partner number.'),
      'callback' => 'partner_number_set_target',
    );

    $targets['partner_num_e'] = array(
      'name' => t('Enterprise partner number.'),
      'description' => t('Enterprise partner number.'),
      'callback' => 'partner_number_set_target',
    );
  }
}

/**
 * Callback for mapping.
 */
function partner_number_set_target($source, $entity, $target, $value) {
  if (is_array($value)) {
    $value = $value[0];
  }
  $entity->$target = $value;
}
