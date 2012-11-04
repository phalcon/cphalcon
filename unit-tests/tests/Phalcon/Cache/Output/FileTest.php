<?php
/**
 * FileTest.php
 * Phalcon_Cache_Output_FileTest
 *
 * Tests the \Phalcon\Cache for an output-file
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

class Cache_Output_FileTest extends Cache_Helper_Unit
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
        $this->setBackend('\Phalcon\Cache\Backend\File');
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

}
