<?php
/**
 * ApcTest.php
 * Phalcon_Cache_Output_ApcTest
 *
 * Tests the \Phalcon\Cache for an output-apc
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

class Cache_Output_ApcTest extends Cache_Helper_Unit
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
        $this->setBackend('\Phalcon\Cache\Backend\Apc');

        $this->checkExtension('apc');
    }

//    public function testOutputApcCache()
//    {
//
//        $ready = $this->_prepareApc();
//        if (!$ready) {
//            return false;
//        }
//
//        apc_delete('_PHCAtest-output');
//
//        $time = date('H:i:s');
//
//        $frontCache = new Phalcon\Cache\Frontend\Output(array(
//            'lifetime' => 2
//        ));
//
//        $cache = new Phalcon\Cache\Backend\Apc($frontCache);
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
//        $this->assertEquals($time, apc_fetch('_PHCAtest-output'));
//
//        //Expect same cache
//        $content = $cache->start('test-output');
//        if ($content === null) {
//            $this->assertTrue(false);
//        }
//
//        $this->assertEquals($content, $obContent);
//        $this->assertEquals($content, apc_fetch('_PHCAtest-output'));
//
//        //Query keys
//        $keys = $cache->queryKeys();
//        $this->assertEquals($keys, array(
//            0 => '_PHCAtest-output',
//        ));
//
//        //Delete entry from cache
//        $this->assertTrue($cache->delete('test-output'));
//
//    }
//
//    public function testDataApcCache()
//    {
//
//        $ready = $this->_prepareApc();
//        if (!$ready) {
//            return false;
//        }
//
//        apc_delete('_PHCAtest-data');
//
//        $frontCache = new Phalcon\Cache\Frontend\Data();
//
//        $cache = new Phalcon\Cache\Backend\Apc($frontCache);
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
//        $this->assertTrue($cache->delete('test-data'));
//
//    }
}
