<?php
/**
 * @file
 * cern_ft_donateboxes.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function cern_ft_donateboxes_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|donation_amount_boxes|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'donation_amount_boxes';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_donate_boxes' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['node|donation_amount_boxes|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function cern_ft_donateboxes_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_donate_boxes|default';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_donate_boxes';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'image_with_link',
        1 => 'field_donation_amount_reference',
        2 => 'field_text',
      ),
    ),
    'fields' => array(
      'image_with_link' => 'ds_content',
      'field_donation_amount_reference' => 'ds_content',
      'field_text' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
  );
  $export['field_collection_item|field_donate_boxes|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|donation_amount_boxes|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'donation_amount_boxes';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'regions' => array(
      'ds_content' => array(
        0 => 'field_donate_boxes',
      ),
    ),
    'fields' => array(
      'field_donate_boxes' => 'ds_content',
    ),
  );
  $export['node|donation_amount_boxes|default'] = $ds_layout;

  return $export;
}
