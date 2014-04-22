<?php
/**
 * @file
 * cern_ft_donateboxes.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function cern_ft_donateboxes_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'field_collection_item-field_donate_boxes-field_donation_amount_reference'
  $field_instances['field_collection_item-field_donate_boxes-field_donation_amount_reference'] = array(
    'bundle' => 'field_donate_boxes',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'String key to identify a donation amount.<br/>
This must be identical with a label of a donation amount in the CiviCRM contribution page.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'cern_ft_donateboxes',
        'settings' => array(),
        'type' => 'cern_ft_donateboxes_amount',
        'weight' => 1,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_donation_amount_reference',
    'label' => 'Donation amount reference',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_donate_boxes-field_image'
  $field_instances['field_collection_item-field_donate_boxes-field_image'] = array(
    'bundle' => 'field_donate_boxes',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_image',
    'label' => 'Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'imce_filefield_on' => 1,
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_donate_boxes-field_text'
  $field_instances['field_collection_item-field_donate_boxes-field_text'] = array(
    'bundle' => 'field_donate_boxes',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_text',
    'label' => 'Text',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-donation_amount_boxes-field_civicrm_contribution_page'
  $field_instances['node-donation_amount_boxes-field_civicrm_contribution_page'] = array(
    'bundle' => 'donation_amount_boxes',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'civicrm_reference_fields',
        'settings' => array(),
        'type' => 'civicrm_reference_fields_link',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_civicrm_contribution_page',
    'label' => 'CiviCRM Contribution page',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-donation_amount_boxes-field_donate_boxes'
  $field_instances['node-donation_amount_boxes-field_donate_boxes'] = array(
    'bundle' => 'donation_amount_boxes',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'cern_ft_donateboxes',
        'settings' => array(),
        'type' => 'cern_ft_donateboxes',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_donate_boxes',
    'label' => 'Donate boxes',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('CiviCRM Contribution page');
  t('Donate boxes');
  t('Donation amount reference');
  t('Image');
  t('String key to identify a donation amount.<br/>
This must be identical with a label of a donation amount in the CiviCRM contribution page.');
  t('Text');

  return $field_instances;
}
