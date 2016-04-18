<?php

/**
 * @file
 * Entity related functions for partner_number module.
 */

/**
 * Implements hook_entity_presave().
 *
 * This is where all users get their partner ID.
 */
function partner_number_entity_presave($entity, $entity_type) {

  if ($entity_type == 'user' && empty($entity->partner_num_ab) && empty($entity->partner_num_e)) {
	$role_ids = array_keys($entity->roles);
	if (in_array(9, $role_ids)) {
	  // Alumni bold.
	  $entity->partner_num_ab = partner_number_generate_number_ab();
	}
	else if (in_array(13, $role_ids)) {
	  // Enterprise.
	  $entity->partner_num_e = partner_number_generate_number_e();
	}
  }
}

/**
 * Implements hook_entity_property_info_alter().
 */
function partner_number_entity_property_info_alter(&$info) {
  $info['user']['properties']['partner_num_ab'] = array(
    'label' => t('Alumni bold partner number.'),
    'description' => t('Alumni bold partner number.'),
    'getter callback' => 'entity_metadata_user_get_properties',
    'setter callback' => 'entity_metadata_user_set_properties',
    'required' => FALSE,
    'access callback' => 'entity_metadata_user_properties_access',
    'schema field' => 'partner_num_ab',
  );

  $info['user']['properties']['partner_num_e'] = array(
    'label' => t('Enterprise partner number.'),
    'description' => t('Enterprise partner number.'),
    'getter callback' => 'entity_metadata_user_get_properties',
    'setter callback' => 'entity_metadata_user_set_properties',
    'required' => FALSE,
    'access callback' => 'entity_metadata_user_properties_access',
    'schema field' => 'partner_num_e',
  );
}
