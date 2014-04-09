<?php
/**
 * @file
 * Settings for all Orbital Cache Nuke settings. Contact: justin.slattery@mlssoccer.com
 *
 */

function orbital_cache_nuke_settings() {
  $form['orbital_cache_nuke_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Orbital Cache Nuke'),
    '#description' => t('Enable remote cache flush.'),
    '#default_value' => variable_get('orbital_cache_nuke_enabled', FALSE),
  );
  $form['orbital_cache_nuke_flush_remote_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Endpoint base URL'),
    '#description' => t('The remote endpoint base url for flushing. Include trailing slash'),
    '#default_value' => variable_get('orbital_cache_nuke_flush_remote_url'),
    '#required' => TRUE,
  );
  $form['orbital_cache_nuke_flush_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Endpoint flush Path'),
    '#description' => t('The relative path for flush requests'),
    '#default_value' => variable_get('orbital_cache_nuke_flush_path'),
    '#required' => TRUE,
  );
  return system_settings_form($form);
}