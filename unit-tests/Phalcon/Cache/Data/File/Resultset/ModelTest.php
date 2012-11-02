<?php
/**
 * MysqlTest.php
 * \Phalcon\Cache\Data\File\Resultset\ModelTest
 *
 * Tests the \Phalcon\Cache for a Resultset
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

use \Phalcon\Cache\Frontend\Data as CacheFrontend;
use \Phalcon\Cache\Backend\File as CacheBackend;

class Cache_Data_File_Resultset_ModelTest extends PhalconModelTestCase
{
    private $_cachePath = '';

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

	public function testFileCreation()
	{
        $fileName = $this->getFileName('cache', 'cache');

        $frontEnd = new CacheFrontend();
        $cache    = new CacheBackend(
            $frontEnd,
            array('cacheDir' => $this->_cachePath)
        );

        $data = Robots::find(array('order' => 'id'));

        $cache->save('test-resultset', $data);

        $actual = file_exists($this->_cachePath . $fileName);
        $this->cleanFile($this->_cachePath, $fileName);

        $this->assertTrue($actual, 'File was not correctly created');
    }

	public function testGetObjectType()
	{
        $fileName = $this->getFileName('cache', 'cache');

        $frontEnd = new CacheFrontend();
        $cache    = new CacheBackend(
            $frontEnd,
            array('cacheDir' => $this->_cachePath)
        );

        $data = Robots::find(array('order' => 'id'));

        $cache->save('test-resultset', $data);

        $robots = $cache->get('test-resultset');

        $this->cleanFile($this->_cachePath, $fileName);

        $expected = 'Phalcon\Mvc\Model\Resultset\Simple';
        $actual   = get_class($robots);

        $this->assertEquals(
            $expected,
            $actual,
            'Cache does not return correct object back'
        );
    }

	public function testGetObjectCount()
	{
        $fileName = $this->getFileName('cache', 'cache');

        $frontEnd = new CacheFrontend();
        $cache    = new CacheBackend(
            $frontEnd,
            array('cacheDir' => $this->_cachePath)
        );

        $data = Robots::find(array('order' => 'id'));

        $cache->save('test-resultset', $data);

        $robots = $cache->get('test-resultset');

        $this->cleanFile($this->_cachePath, $fileName);

        $expected = 3;
        $actual   = count($robots);

        $this->assertEquals(
            $expected,
            $actual,
            'Cache get does not return correct number of objects back'
        );
    }

	public function testGetObjectRecordCount()
	{
        $fileName = $this->getFileName('cache', 'cache');

        $frontEnd = new CacheFrontend();
        $cache    = new CacheBackend(
            $frontEnd,
            array('cacheDir' => $this->_cachePath)
        );

        $data = Robots::find(array('order' => 'id'));

        $cache->save('test-resultset', $data);

        $robots = $cache->get('test-resultset');

        $this->cleanFile($this->_cachePath, $fileName);

        $expected = 3;
        $actual   = $robots->count();

        $this->assertEquals(
            $expected,
            $actual,
            'Cache get does not return correct object count back'
        );
    }
}
