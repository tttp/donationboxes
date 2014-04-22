<?php
use Drupal\cern_ft_donateboxes\StaticCache;

/**
 * Implements hook_field_formatter_info()
 */
function cern_ft_donateboxes_field_formatter_info() {
  return array(
    'cern_ft_donateboxes' => array(
      'label' => t('Contribution amounts'),
      'field types' => array('field_collection'),
    ),
    'cern_ft_donateboxes_amount' => array(
      'label' => t('Contribution amount from CiviCRM'),
      'field types' => array('text'),
    ),
  );
}

/**
 * Implements hook_field_formatter_info()
 */
function cern_ft_donateboxes_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {

  if (empty($items)) {
    return array();
  }

  switch ($display['type']) {
    case 'cern_ft_donateboxes':
      return _cern_ft_donateboxes_field_formatter_view__cern_ft_donateboxes($items);
    case 'cern_ft_donateboxes_amount':
      return _cern_ft_donateboxes_field_formatter_view__cern_ft_donateboxes_amount($items);
    default:
      return array();
  }
}

/**
 * @param array $items
 *
 * @return array
 */
function _cern_ft_donateboxes_field_formatter_view__cern_ft_donateboxes($items) {

  $element = array();

  $contribution_page_id = StaticCache::getContributionPageId();

  $n = 0;
  foreach ($items as $delta => $item) {
    /** @var FieldCollectionItemEntity $field_collection */
    if ($field_collection = field_collection_field_get_entity($item)) {
      if ($contribution_page_id) {
        $amount = _cern_ft_donateboxes_box_get_amount($field_collection);
        if (!isset($amount)) {
          continue;
        }
      }
      else {
        $amount = FALSE;
      }
      $element[$delta]['entity'] = $field_collection->view('full');
      $element[$delta]['#theme_wrappers'][] = 'cern_ft_donateboxes_box';
      $element[$delta]['#cern_ft_donateboxes_amount'] = $amount;
      # $element[$delta]['#attributes']['class'] = 'xyz';
      $element[$delta]['#attached']['css'][] = drupal_get_path('module', 'cern_ft_donateboxes') . '/css/cern_ft_donateboxes.css';
      $element[$delta]['#attached']['js'][] = drupal_get_path('module', 'cern_ft_donateboxes') . '/js/cern_ft_donateboxes.js';
      ++$n;
    }
  }

  $element['#theme_wrappers'][] = 'container';
  $element['#attributes'] = array('class' => "dqx-columns dqx-$n-columns cern-ft-donateboxes clearfix");

  return $element;
}

/**
 * Theme callback for theme('cern_ft_donateboxes_box')
 *
 * @param $variables
 *
 * @return string
 */
function theme_cern_ft_donateboxes_box($variables) {
  $element = $variables['element'];
  if (FALSE !== $element['#cern_ft_donateboxes_amount']) {
    $qfid = check_plain($element['#cern_ft_donateboxes_amount']['qfid']);
    $html = '<label for="' . $qfid . '">' . $element['#children'] . '</label>';
  }
  else {
    $html = '<label>' . $element['#children'] . '</label>';
  }
  return '<div class="dqx-column">' . $html . '</div>';
}

/**
 * @param array $items
 *
 * @return array
 */
function _cern_ft_donateboxes_field_formatter_view__cern_ft_donateboxes_amount($items) {

  $element = array();

  foreach ($items as $delta => $item) {
    $amount = StaticCache::getAmount($item['value']);
    if (empty($amount) || !isset($amount['amount'])) {
      $element[$delta]['#markup'] = '?? CHF';
    }
    else {
      $element[$delta]['#markup'] = check_plain($amount['amount']) . ' CHF';
    }
  }

  return $element;
}

/**
 * @param FieldCollectionItemEntity $fieldCollectionItem
 *
 * @return array|null
 */
function _cern_ft_donateboxes_box_get_amount($fieldCollectionItem) {

  $amount_reference_items = field_get_items('field_collection_item', $fieldCollectionItem, 'field_donation_amount_reference');

  if (!is_array($amount_reference_items) || empty($amount_reference_items)) {
    return NULL;
  }

  foreach ($amount_reference_items as $amount_reference_item) {
    $amount = StaticCache::getAmount($amount_reference_item['value']);
    if (isset($amount)) {
      return $amount;
    }
  }

  return NULL;
}
