<?php
/**
 * @file
 * cern_ft_donateboxes.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function cern_ft_donateboxes_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_civicrm_contribution_page'
  $field_bases['field_civicrm_contribution_page'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_civicrm_contribution_page',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'civicrm_reference_fields',
    'settings' => array(
      'allowed_end_date' => '',
      'allowed_start_date' => '',
    ),
    'translatable' => 0,
    'type' => 'civicrm_reference_fields_contribution',
  );

  // Exported field_base: 'field_donate_boxes'
  $field_bases['field_donate_boxes'] = array(
    'active' => 1,
    'cardinality' => 4,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_donate_boxes',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'field_collection',
    'settings' => array(
      'hide_blank_items' => 0,
      'path' => '',
    ),
    'translatable' => 0,
    'type' => 'field_collection',
  );

  // Exported field_base: 'field_donation_amount_reference'
  $field_bases['field_donation_amount_reference'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_donation_amount_reference',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
