<?php
/**
 * OutputFile.php
 * Cache_Helper_OutputFile
 *
 * Tests the \Phalcon\Cache component
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

class Cache_Helper_OutputFile extends Cache_Helper_BaseFile
{
    protected $_prefix = '';

    public function setPrefix($prefix)
    {
        $this->_prefix = $prefix;
    }

    public function setUp()
    {
        parent::setUp();

        $options = array('lifetime' => 2);
        $this->setFrontEnd('\Phalcon\Cache\Frontend\Output', $options);

        $options = array(
            'cacheDir' => $this->_cacheDir,
            'prefix'   => $this->_prefix,
        );
        $this->setBackEnd('\Phalcon\Cache\Backend\File', $options);
    }

    public function testCacheStartedWithNoOutput()
    {
        $cache = $this->createCache();

        $actual = $cache->isStarted();

        $this->assertFalse($actual, 'Cache has been started');
    }

    public function testCacheStartedWithOutput()
    {
        $cache = $this->createCache();

        ob_start();
        $content = $cache->start('test-output');

        $actual = $cache->isStarted();

        $this->assertTrue($actual, 'Cache has not been started');
    }

    public function testCacheStartedWithOutputContentNull()
    {
        $cache = $this->createCache();

        ob_start();
        $expected = null;
        $actual   = $cache->start('test-output');

        $this->assertEquals($expected, $actual, 'Content is not null');
    }

    public function testCacheStartedWithOutputCorrectContentFileExists()
    {
        $cache = $this->createCache();
        $time  = date('H:i:s');

        ob_start();
        $cache->start('test-output');

        echo $time;
        $cache->save(null, null, null, true);

        $actual = ob_get_contents();
        ob_end_clean();

        $exists = file_exists($this->_cacheDir . $this->_prefix . 'testoutput');

        $this->cleanFile($this->_cacheDir, $this->_prefix . 'testoutput');

        $this->assertTrue($exists, 'Cache file was not created');
    }

    public function testCacheStartedWithOutputCorrectContent()
    {
        $cache = $this->createCache();
        $time  = date('H:i:s');

        ob_start();
        $cache->start('test-output');

        echo $time;
        $cache->save(null, null, null, true);

        $actual = ob_get_contents();
        ob_end_clean();

        $this->cleanFile($this->_cacheDir, $this->_prefix . 'testoutput');

        $expected = $time;
        $this->assertEquals($expected, $actual, 'Content is not the same');
    }

    public function testCacheStartedExistingCache()
    {
        $cache = $this->createCache();
        $time  = date('H:i:s');

        ob_start();
        $cache->start('test-output');

        echo $time;
        $cache->save(null, null, null, true);
        ob_end_clean();

        // Start it again
        $content = $cache->start('test-output');

        $actual = $cache->isStarted();

        $this->cleanFile($this->_cacheDir, $this->_prefix . 'testoutput');

        $this->assertTrue($actual, 'Cache has not been started (not first time cache)');
    }

    public function testCacheStartedExistingCacheContents()
    {
        $cache = $this->createCache();
        $time  = date('H:i:s');

        ob_start();
        $cache->start('test-output');

        echo $time;
        $cache->save(null, null, null, true);
        ob_end_clean();

        // Start it again
        $actual   = $cache->start('test-output');

        $this->cleanFile($this->_cacheDir, $this->_prefix . 'testoutput');

        $expected = $time;
        $this->assertEquals($expected, $actual, 'Content is not the same (not first time cache)');
    }

    public function testCacheStartedExistingCacheContentsTimeout()
    {
        $cache = $this->createCache();
        $time  = date('H:i:s');

        ob_start();
        $cache->start('test-output');

        echo $time;
        $cache->save(null, null, null, true);
        $content_one = ob_get_contents();
        ob_end_clean();

        // Start it again
        $actual   = $cache->start('test-output');

        // Sleep 3 seconds for the timeout
        sleep(3);

        $time_two = date('H:i:s');

        ob_start();
        $cache->start('test-output');

        echo $time_two;
        $cache->save(null, null, null, true);
        $content_two = ob_get_contents();
        ob_end_clean();

        $this->cleanFile($this->_cacheDir, $this->_prefix . 'testoutput');

        $this->assertEquals(
            $content_one,
            $time,
            'Content has the old data'
        );

        $this->assertEquals(
            $content_two,
            $time_two,
            'Content does not have the correct data'
        );
    }

    public function testCacheQueryKeys()
    {
        $cache = $this->createCache();
        $time  = date('H:i:s');

        ob_start();
        $cache->start('test-output');

        echo $time;
        $cache->save(null, null, null, true);
        $content_one = ob_get_contents();
        ob_end_clean();

        //Check keys
        $actual   = $cache->queryKeys();

        $this->assertEquals(count($actual), 2, 'Key count not correct');

        $exists = in_array('dummy.txt', $actual);
        $this->assertTrue($exists, 'Dummy.txt does not exist in the keys');

        $exists = in_array($this->_prefix . 'testoutput', $actual);
        $this->assertTrue($exists, 'unittestoutput does not exist in the keys');

        $this->cleanFile($this->_cacheDir, $this->_prefix . 'testoutput');
    }

    public function testCacheKeyExists()
    {
        $cache = $this->createCache();
        $time  = date('H:i:s');

        ob_start();
        $cache->start('test-output');

        echo $time;
        $cache->save(null, null, null, true);
        $content_one = ob_get_contents();
        ob_end_clean();

        // Check key
        $actual = $cache->exists('testoutput');

        $this->cleanFile($this->_cacheDir, $this->_prefix . 'testoutput');

        $this->assertTrue($actual, 'Key does not exist');
    }

    public function testCacheDeleteKey()
    {
        $cache = $this->createCache();
        $time  = date('H:i:s');

        ob_start();
        $cache->start('test-output');

        echo $time;
        $cache->save(null, null, null, true);
        $content_one = ob_get_contents();
        ob_end_clean();

        //Check keys
        $actual   = $cache->delete('testoutput');

        // Check key
        $actual = $cache->exists('testoutput');

        $this->cleanFile($this->_cacheDir, $this->_prefix . 'testoutput');

        $this->assertFalse($actual, 'Key exists after delete');
    }
}