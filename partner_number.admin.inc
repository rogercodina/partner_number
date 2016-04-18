<?php

/**
 * @file
 * Administration page.
 */

/**
 * Configuration form.
 */
function partner_number_admin_settings($form, &$form_state) {

  $form['general'] = array(
    '#type' => 'fieldset',
    '#title' => t('General settings'),
    '#weight' => 5,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['general']['partner_number_alumni_bold'] = array(
    '#type' => 'textfield',
    '#title' => t('Alumni bold partner number: next number to be assigned.'),
    '#default_value' => variable_get('partner_number_alumni_bold', 30),
  );

  $form['general']['partner_number_enterprise'] = array(
    '#type' => 'textfield',
    '#title' => t('Enterprise partner number: next number to be assigned.'),
    '#default_value' => variable_get('partner_number_enterprise', 30),
  );

  return system_settings_form($form);
}
