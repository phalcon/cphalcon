<?php
/**
 * MemcacheTest.php
 * Phalcon_Cache_Output_MemcacheTest
 *
 * Tests the \Phalcon\Cache for an output-mongo
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2012 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Eduar Carvajal <eduar@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@niden.net>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

class Cache_Output_MemcacheTest extends Cache_Helper_Unit
{
    /**
     * Initialization of variables etc.
     *
     * @return Phalcon\DI|void
     */
    public function setUp()
    {
        parent::setUp();

        $this->setFrontend('\Phalcon\Cache\Frontend\Output');
        $this->setBackend('\Phalcon\Cache\Backend\Memcache');

        $this->checkExtension('memcache');
    }

//    public function testOutputMemcacheCache()
//    {
//
//        $memcache = $this->_prepareMemcached();
//        if (!$memcache) {
//            return false;
//        }
//
//        $memcache->delete('test-output');
//
//        $time = date('H:i:s');
//
//        $frontCache = new Phalcon\Cache\Frontend\Output(array(
//            'lifetime' => 2
//        ));
//
//        $cache = new Phalcon\Cache\Backend\Memcache($frontCache);
//
//        ob_start();
//
//        //First time cache
//        $content = $cache->start('test-output');
//        if ($content !== null) {
//            $this->assertTrue(false);
//        }
//
//        echo $time;
//
//        $cache->save(null, null, null, true);
//
//        $obContent = ob_get_contents();
//        ob_end_clean();
//
//        $this->assertEquals($time, $obContent);
//        $this->assertEquals($time, $memcache->get('test-output'));
//
//        //Expect same cache
//        $content = $cache->start('test-output');
//        if ($content === null) {
//            $this->assertTrue(false);
//        }
//
//        $this->assertEquals($time, $obContent);
//
//        //Refresh cache
//        sleep(3);
//
//        $time2 = date('H:i:s');
//
//        ob_start();
//
//        $content = $cache->start('test-output');
//        if($content!==null){
//            $this->assertTrue(false);
//        }
//        echo $time2;
//        $cache->save(null, null, null, true);
//
//        $obContent2 = ob_get_contents();
//        ob_end_clean();
//
//        $this->assertNotEquals($time, $obContent2);
//        $this->assertEquals($time2, $obContent2);
//        $this->assertEquals($time2, $memcache->get('test-output'));
//
//        //Check if exists
//        $this->assertTrue($cache->exists('test-output'));
//
//        //Delete entry from cache
//        $this->assertTrue($cache->delete('test-output'));
//
//        $memcache->close();
//
//    }
//
//    public function testDataMemcachedCache()
//    {
//
//        $memcache = $this->_prepareMemcached();
//        if (!$memcache) {
//            return false;
//        }
//
//        $memcache->delete('test-data');
//
//        $frontCache = new Phalcon\Cache\Frontend\Data();
//
//        $cache = new Phalcon\Cache\Backend\Memcache($frontCache, array(
//            'host' => '127.0.0.1',
//            'port' => '11211'
//        ));
//
//        $data = array(1, 2, 3, 4, 5);
//
//        $cache->save('test-data', $data);
//
//        $cachedContent = $cache->get('test-data');
//        $this->assertEquals($cachedContent, $data);
//
//        $cache->save('test-data', "sure, nothing interesting");
//
//        $cachedContent = $cache->get('test-data');
//        $this->assertEquals($cachedContent, "sure, nothing interesting");
//
//        $this->assertEquals($cache->queryKeys(), array(
//            0 => 'test-data',
//        ));
//
//        //Check if exists
//        $this->assertTrue($cache->exists('test-data'));
//
//        //Delete
//        $this->assertTrue($cache->delete('test-data'));
//
//    }
}
