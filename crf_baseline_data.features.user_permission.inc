<?php
/**
 * @file
 * crf_baseline_data.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function crf_baseline_data_user_default_permissions() {
  $permissions = array();

  // Exported permission: create baseline_data content.
  $permissions['create baseline_data content'] = array(
    'name' => 'create baseline_data content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
      2 => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any baseline_data content.
  $permissions['delete any baseline_data content'] = array(
    'name' => 'delete any baseline_data content',
    'roles' => array(
      0 => 'administrator',
      1 => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own baseline_data content.
  $permissions['delete own baseline_data content'] = array(
    'name' => 'delete own baseline_data content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
      2 => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any baseline_data content.
  $permissions['edit any baseline_data content'] = array(
    'name' => 'edit any baseline_data content',
    'roles' => array(
      0 => 'administrator',
      1 => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own baseline_data content.
  $permissions['edit own baseline_data content'] = array(
    'name' => 'edit own baseline_data content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
      2 => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: view any unpublished baseline_data content.
  $permissions['view any unpublished baseline_data content'] = array(
    'name' => 'view any unpublished baseline_data content',
    'roles' => array(
      0 => 'administrator',
      1 => 'manager',
    ),
    'module' => 'view_unpublished',
  );

  return $permissions;
}
