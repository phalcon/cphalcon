<?php
/**
 * Backend.php
 * Phalcon_Flash_Direct_Helper_Unit
 *
 * Helper for the \Phalcon\Cache\Backend\* components
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2013 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Test\Cache\Backend\Helper;

use \Phalcon\Test\UnitTestCase as PhTestUnitTestCase;
use \Phalcon\Cache\Frontend\Output as PhTestCacheFrontendOutput;

class Backend extends PhTestUnitTestCase
{
    private $cacheName = '';

    /**
     * Sets the custom classes for the tests
     * 
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2013-04-09
     */
    public function testOutputCacheStarted()
    {
        $cache = $this->createObject();

        $actual = $cache->isStarted();

        $this->assertFalse($actual, 'Cache has been started');
    }

    /**
     * Tests the creation of the file cache
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2013-04-09
     */
    public function testOutputCacheFileCreated()
    {
        $time     = date('H:i:s');
        $cache    = $this->createObject();
        $fileName = $this->getFileName();

        ob_start();

        // First time cache
        $content = $cache->start($fileName);

        $actual = $cache->isStarted();
        $this->assertTrue($actual, 'Cache has not been started');

        $actual = (bool) ($content === null);
        $this->assertFalse($actual, 'Cache content is not null on initialize');

        echo $time;
        $cache->save(null, null, null, true);

        $obContent = ob_get_contents();
        ob_end_clean();

        $this->assertEquals($time, $obContent. 'Cache data incorrect');

        $actual = file_exists(PATH_CACHE . '/' . $fileName);
        $this->assertTrue($actual, 'Cache file was not created correctly');

        $this->cleanFile(PATH_CACHE, $fileName);
    }

    /**
     * Sets the custom classes for the tests
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2013-04-09
     */
    public function testOutputCacheFileCorrectData()
    {
        $time     = date('H:i:s');
        $cache    = $this->createObject();
        $fileName = $this->getFileName();

        ob_start();

        // First time cache
        $content = $cache->start($fileName);

        $actual = $cache->isStarted();
        $this->assertTrue($actual, 'Cache has not been started');

        $actual = (bool) ($content === null);
        $this->assertFalse($actual, 'Cache content is not null on initialize');

        echo $time;
        $cache->save(null, null, null, true);

        $obContent = ob_get_contents();
        ob_end_clean();

        $this->assertEquals($time, $obContent. 'Cache data incorrect');

        $actual = file_exists(PATH_CACHE . '/' . $fileName);
        $this->assertTrue($actual, 'Cache file was not created correctly');
        //Same cache
        $content = $cache->start('testoutput');
        $this->assertTrue($cache->isStarted());

        if ($content === null) {
            $this->assertTrue(false);
        }

        $this->assertEquals($time, $obContent);

        //Refresh cache
        sleep(3);

        $time2 = date('H:i:s');

        ob_start();

        $content = $cache->start('testoutput');
        $this->assertTrue($cache->isStarted());

        if ($content !== null) {
            $this->assertTrue(false);
        }

        echo $time2;
        $cache->save(null, null, null, true);

        $obContent2 = ob_get_contents();
        ob_end_clean();

        $this->assertNotEquals($time, $obContent2);
        $this->assertEquals($time2, $obContent2);

        //Check keys
        $keys = $cache->queryKeys();
        $this->assertEquals($keys, array(
            0 => 'unittestoutput',
        ));

        //Exists?
        $this->assertTrue($cache->exists('testoutput'));

        //Delete cache
        $this->assertTrue($cache->delete('testoutput'));

    }

    private function createObject($prefix = '')
    {
        $options['cacheDir'] = PATH_CACHE;

        if ($prefix)
        {
            $options['prefix'] = $prefix;
        }

        $frontCache = new PhTestCacheFrontendOutput(
            array('lifetime' => 2)
        );

        $backend = '\Phalcon\Cache\Backend\\' . ucfirst($this->cacheName);

        $cache = new $backend($frontCache, $options);

        return $cache;
    }

}
