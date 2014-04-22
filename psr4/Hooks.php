<?php

namespace Drupal\cern_ft_donateboxes;

class Hooks {

  /**
   * @param string $formName
   * @param object $form
   */
  static function hook_civicrm_buildForm($formName, &$form) {

    if (!$form instanceof \CRM_Contribute_Form_Contribution_Main) {
      return;
    }

    $amounts = self::extractAmounts($form);

    if (empty($amounts)) {
      return;
    }

    StaticCache::init($form->getVar('_id'), $amounts);
  }

  private static function extractAmounts(\CRM_Contribute_Form_Contribution_Main $form) {

    $fee = self::findAmountsInfo($form);
    if (empty($fee)) {
      return NULL;
    }
    if (empty($fee['options'])) {
      return NULL;
    }
    if (empty($fee['id'])) {
      return NULL;
    }
    $id = 'price_' . $fee['id'];

    $element = $form->getElement($id);
    if (!$element instanceof \HTML_QuickForm_group) {
      return NULL;
    }

    $amountsById = $fee['options'];
    $amounts = array();
    foreach ($element->getElements() as $element) {
      if (!$element instanceof \HTML_QuickForm_radio) {
        continue;
      }
      $value = $element->getAttribute('value');
      if (empty($amountsById[$value])) {
        continue;
      }
      $amount = $amountsById[$value];
      $amount['qfid'] = $element->getAttribute('id');
      $amounts[$amount['label']] = $amount;
    }
    return $amounts;
  }

  /**
   * Finds the field index of the donation amount radios.
   *
   * @param \CRM_Contribute_Form_Contribution_Main $form
   *
   * @return int|null|string
   */
  private static function findAmountsInfo(\CRM_Contribute_Form_Contribution_Main $form) {

    $values = $form->getVar('_values');
    foreach ($values['fee'] as $fee) {
      if ('contribution_amount' === $fee['name']) {
        return $fee;
      }
    }

    return NULL;
  }
}
