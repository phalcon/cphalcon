<?php
/**
 * MongoTest.php
 * Phalcon_Cache_Output_MongoTest
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

class Cache_Output_MongoTest extends Cache_Helper_Unit
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
        $this->setBackend('\Phalcon\Cache\Backend\Mongo');

        $this->checkExtension('mongo');
    }

//    public function testOutputMongoCache()
//    {
//
//        $ready = $this->_prepareMongo();
//        if (!$ready) {
//            return false;
//        }
//
//        //remove existing
//        $mongo = new Mongo();
//        $database = $mongo->phalcon_test;
//        $collection = $database->caches;
//        $collection->remove();
//
//        $time = date('H:i:s');
//
//        $frontCache = new Phalcon\Cache\Frontend\Output(array(
//            'lifetime' => 2
//        ));
//
//        $cache = new Phalcon\Cache\Backend\Mongo($frontCache, array(
//            'server' => 'mongodb://localhost',
//            'db' => 'phalcon_test',
//            'collection' => 'caches'
//        ));
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
//
//        $document = $collection->findOne(array('key' => 'test-output'));
//        $this->assertTrue(is_array($document));
//        $this->assertEquals($time, $document['data']);
//
//        //Expect same cache
//        $content = $cache->start('test-output');
//        if ($content === null) {
//            $this->assertTrue(false);
//        }
//
//        $document = $collection->findOne(array('key' => 'test-output'));
//        $this->assertTrue(is_array($document));
//        $this->assertEquals($time, $document['data']);
//
//        //Query keys
//        $keys = $cache->queryKeys();
//        $this->assertEquals($keys, array(
//            0 => 'test-output',
//        ));
//
//        //Exists
//        $this->assertTrue($cache->exists('test-output'));
//
//        //Delete entry from cache
//        $this->assertTrue($cache->delete('test-output'));
//
//    }
//
//    public function testDataMongoCache()
//    {
//
//        $ready = $this->_prepareMongo();
//        if (!$ready) {
//            return false;
//        }
//
//        //remove existing
//        $mongo = new Mongo();
//        $database = $mongo->phalcon_test;
//        $collection = $database->caches;
//        $collection->remove();
//
//        $frontCache = new Phalcon\Cache\Frontend\Data();
//
//        $cache = new Phalcon\Cache\Backend\Mongo($frontCache, array(
//            'mongo' => $mongo,
//            'db' => 'phalcon_test',
//            'collection' => 'caches'
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
//        //Exists
//        $this->assertTrue($cache->exists('test-data'));
//
//        $this->assertTrue($cache->delete('test-data'));
//
//    }
}
