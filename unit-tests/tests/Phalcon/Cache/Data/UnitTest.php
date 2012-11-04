<?php
/**
 * FileTest.php
 * Phalcon_Cache_Data_FileTest
 *
 * Tests the \Phalcon\Cache for an data-file
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

class Cache_Data_FileTest extends Phalcon_Test_UnitTestCase
{
    /**
     * Initialization of variables etc.
     *
     * @return Phalcon\DI|void
     */
    public function setUp()
    {
        parent::setUp();

//        $this->setFrontend('\Phalcon\Cache\Frontend\Output');
//        $this->setBackend('\Phalcon\Cache\Backend\File');
    }

    public function testDataFileCache()
    {

        $frontCache = new \Phalcon\Cache\Frontend\Data();

        $cache = new Phalcon\Cache\Backend\File(
            $frontCache,
            array('cacheDir' => PATH_CACHE)
        );

        $this->assertFalse($cache->isStarted());

        //Save
        $cache->save('test-data', "nothing interesting");

        $this->assertTrue(file_exists(PATH_CACHE . 'testdata'));

        //Get
        $cachedContent = $cache->get('test-data');
        $this->assertEquals($cachedContent, "nothing interesting");

        //Save
        $cache->save('test-data', "sure, nothing interesting");

        //Get
        $cachedContent = $cache->get('test-data');
        $this->assertEquals($cachedContent, "sure, nothing interesting");

        //Exists
        $this->assertTrue($cache->exists('test-data'));

        //Delete
        $this->assertTrue($cache->delete('test-data'));

    }

}
