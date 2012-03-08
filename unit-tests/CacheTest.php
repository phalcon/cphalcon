<?php

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

class CacheTest extends PHPUnit_Framework_TestCase {

  public function testCache(){

    $frontendOptions = array(
      'lifetime' => 4
    );

    $backendOptions = array(
      'cacheDir' => 'unit-tests/cache/'
    );

    @unlink('unit-tests/cache/test');

    $time = date('H:i:s');

    $cache = Phalcon_Cache::factory('File', $frontendOptions, $backendOptions);
    $this->assertInstanceOf('Phalcon_Cache_Adapter_File', $cache);

    ob_start();

    //First time cache
    $content = $cache->start('test');
    if($content!==null){
      $this->assertTrue(false); 
    }
    echo $time;
    $cache->save(true);
    
    $obContent = ob_get_contents();
    ob_end_clean();    

    $this->assertEquals($time, $obContent);

    //Same cache
    $content = $cache->start('test');
    if($content===null){
      $this->assertTrue(false);
    }

    $this->assertEquals($time, $obContent);

    //Refresh cache
    sleep(6);

    $time2 = date('H:i:s');

    ob_start();

    $content = $cache->start('test');
    if($content!==null){
      $this->assertTrue(false); 
    }
    echo $time2;
    $cache->save(true);

    $obContent2 = ob_get_contents();
    ob_end_clean();    

    $this->assertNotEquals($time, $obContent2);
    $this->assertEquals($time2, $obContent2);

  }

}