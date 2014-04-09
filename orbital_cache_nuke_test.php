<?php
/**
 * @file
 * Automated Testing - Orbital Cache Nuke
 */

namespace OrbitalCacheNuke {
  require_once 'test/test_env_variables_bootstrap.inc';

  function db_query($sql) {
    error_log('Mock called: ' . $sql);
    return TRUE;
  }



  //include_once 'orbital_cache_nuke.inc';

  // TODO - Make all this work

  class OrbitalCacheNukeTest extends \PHPUnit_Framework_TestCase {

  /**
     * Ensure the opta id is saved in the mp7_opta_index reference table
     * when the opta id is created.
     */
    public function testOCN() {
      $stub = $this->getMock('DatabaseConnection');

      $stub->expects($this->once())
        ->method('db_query');

      $fake_node = (object)array('nid' => 1);
      //$test = new \OrbitalCacheNuke\QueueManager;
      \orbital_cache_nuke_node_update($fake_node);
    }

  }
}