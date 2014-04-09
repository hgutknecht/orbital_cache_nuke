<?php
/**
 * @file
 * Common settings for all Orbital Cache Nuke settings. Contact: justin.slattery@mlssoccer.com
 */

namespace OrbitalCacheNuke;

class QueueManager {
  /**
   * Inserts a new row into the cache queue table
   */
  public function queue_remote_node_cache_flush_command($node) {
    // Delete any previous queued requests for this nid so we don't queue up redundant flush requests
    db_query('delete from {orbital_cache_nuke_queue} where nid = :nid', array(':nid' => $node->nid));

    db_query('insert into {orbital_cache_nuke_queue} (nid) values (:nid)', array(':nid' => $node->nid));
  }

  public function queue_remote_global_cache_flush_command() {
    // If we are doing a global flush, clear out any previous queued requests; they are redundant
    db_query('delete from {orbital_cache_nuke_queue}');

    // A nid of -1 will trigger a global flush
    db_query('insert into {orbital_cache_nuke_queue} (nid) values (-1)');
  }

  public function queue_remote_cron_cache_flush_command() {
    // Delete any previous queued cron flush requests; they are redundant
    db_query('delete from {orbital_cache_nuke_queue} where nid = 0');

    // A nid of 0 will trigger a cron flush
    db_query('insert into {orbital_cache_nuke_queue} (nid) values (0)');
  }
}