<?php

namespace Drupal\cern_ft_donateboxes;

class StaticCache {

  /**
   * @var int|null
   */
  private static $contributionPageId;

  /**
   * @var array|null
   */
  private static $amounts;

  /**
   * @param int $contributionPageId
   * @param array $amounts
   */
  static function init($contributionPageId, $amounts) {
    self::$contributionPageId = $contributionPageId;
    self::$amounts = $amounts;
  }

  /**
   * @return int|null
   */
  static function getContributionPageId() {
    return self::$contributionPageId;
  }

  /**
   * @param string $name
   *
   * @return string|null
   */
  static function getAmount($name) {
    return isset(self::$amounts[$name])
      ? self::$amounts[$name]
      : NULL;
  }

  /**
   * @return bool
   */
  public static function hasAmounts() {
    return !empty(self::$amounts);
  }
}
