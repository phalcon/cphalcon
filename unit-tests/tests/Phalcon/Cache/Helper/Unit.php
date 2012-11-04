<?php
/**
 * Unit.php
 * Phalcon_Cache_Helper_Unit
 *
 * Helper class to run tests for the Output frontend cache
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

class Cache_Helper_Unit extends Phalcon_Test_UnitTestCase
{
    private $_cachePath = '';
    private $_frontEnd  = '';
    private $_backEnd   = '';

    /**
     * Initialization of variables etc.
     *
     * @return Phalcon\DI|void
     */
    public function setUp()
    {
        parent::setUp();

        $this->_cachePath = ROOT_PATH . '/app/var/cache/';
    }

    public function setFrontend($frontEnd)
    {
        $this->_frontEnd = $frontEnd;
    }

    public function setBackend($backEnd)
    {
        $this->_backEnd = $backEnd;
    }


    public function testInitiateObjectDoesNotCreateCacheEntry()
    {
        $frontEndClass = $this->_frontEnd;
        $backEndClass  = $this->_backEnd;

        $prefix    = 'unit_';
        $options   = array('lifetime' => 5);
        $frontEnd  = new $frontEndClass($options);
        $cache     = new $backEndClass(
            $frontEnd,
            array(
                'cacheDir' => $this->_cachePath,
                'prefix'   => $prefix,
            )
        );

        $this->assertFalse($cache->isStarted(), 'Cache has been initialized');
    }

    public function testStartingCacheCreatesCacheEntry()
    {
        $frontEndClass = $this->_frontEnd;
        $backEndClass  = $this->_backEnd;

        $prefix    = 'unit_';
        $cacheName = 'test_output';
        $options   = array('lifetime' => 5);
        $frontEnd  = new $frontEndClass($options);
        $cache     = new $backEndClass(
            $frontEnd,
            array(
                'cacheDir' => $this->_cachePath,
                'prefix'   => $prefix,
            )
        );

        ob_start();

        $content= $cache->start($cacheName);

        ob_end_clean();

        $this->assertTrue($cache->isStarted(), 'Cache has not been initialized');
    }

    public function testCacheContentIsNullIfNoOutput()
    {
        $frontEndClass = $this->_frontEnd;
        $backEndClass  = $this->_backEnd;

        $prefix    = 'unit_';
        $cacheName = 'test_output';
        $options  = array('lifetime' => 5);
        $frontEnd = new $frontEndClass($options);
        $cache    = new $backEndClass(
            $frontEnd,
            array(
                'cacheDir' => $this->_cachePath,
                'prefix'   => $prefix,
            )
        );

        ob_start();

        $content= $cache->start($cacheName);

        ob_end_clean();

        $this->assertEquals($content, null, 'Content is not null');
    }

    public function testCacheContentFileCreation()
    {
        $frontEndClass = $this->_frontEnd;
        $backEndClass  = $this->_backEnd;

        $prefix    = 'unit_';
        $cacheName = 'test_output';
        $options   = array('lifetime' => 5);
        $frontEnd  = new $frontEndClass($options);
        $cache     = new $backEndClass(
            $frontEnd,
            array(
                'cacheDir' => $this->_cachePath,
                'prefix'   => $prefix,
            )
        );

        $time = date('H:i:s');
        ob_start();

        $content= $cache->start($cacheName);

        echo $time;

        $cache->save(null, null, null, true);

        ob_end_clean();

        $exists = file_exists($this->_cachePath . $prefix . $cacheName);
        $this->cleanFile($this->_cachePath, $prefix . $cacheName);

        $this->assertTrue($exists, 'Cache file was not created');
    }

    public function testCacheContent()
    {
        $frontEndClass = $this->_frontEnd;
        $backEndClass  = $this->_backEnd;

        $prefix    = 'unit_';
        $cacheName = 'test_output';
        $options   = array('lifetime' => 5);
        $frontEnd  = new $frontEndClass($options);
        $cache     = new $backEndClass(
            $frontEnd,
            array(
                'cacheDir' => $this->_cachePath,
                'prefix'   => $prefix,
            )
        );

        $time = date('H:i:s');
        ob_start();

        $content= $cache->start($cacheName);

        echo $time;

        $cache->save(null, null, null, true);

        $expected = $time;
        $actual   = ob_get_contents();
        ob_end_clean();

        $this->assertEquals($expected, $actual, 'Cache data are not the same');
    }
//
////    public function testOutputFileCache()
////    {
////
////        //Same cache
////        $content = $cache->start('testoutput');
////        $this->assertTrue($cache->isStarted());
////
////        if ($content === null) {
////            $this->assertTrue(false);
////        }
////
////        $this->assertEquals($time, $obContent);
////
////        //Refresh cache
////        sleep(3);
////
////        $time2 = date('H:i:s');
////
////        ob_start();
////
////        $content = $cache->start('testoutput');
////        $this->assertTrue($cache->isStarted());
////
////        if ($content !== null) {
////            $this->assertTrue(false);
////        }
////
////        echo $time2;
////        $cache->save(null, null, null, true);
////
////        $obContent2 = ob_get_contents();
////        ob_end_clean();
////
////        $this->assertNotEquals($time, $obContent2);
////        $this->assertEquals($time2, $obContent2);
////
////        //Check keys
////        $keys = $cache->queryKeys();
////        $this->assertEquals($keys, array(
////            0 => 'unittestoutput',
////        ));
////
////        //Exists?
////        $this->assertTrue($cache->exists('testoutput'));
////
////        //Delete cache
////        $this->assertTrue($cache->delete('testoutput'));
////
////    }
//
}
