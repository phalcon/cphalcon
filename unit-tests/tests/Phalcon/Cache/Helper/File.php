<?php
/**
 * File.php
 * Cache_Helper_File
 *
 * Helper for \Phalcon\Cache
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

class Cache_Helper_File extends Phalcon_Test_UnitTestCase
{
    private $_backEnd         = '';
    private $_backEndOptions  = array();
    private $_frontEnd        = '';
    private $_frontEndOptions = array();

    protected $_cacheDir        = '';

    public function setUp()
    {
        parent::setUp();
        $this->_cacheDir = PATH_CACHE;
    }

    public function setFrontEnd($frontend, $options = array())
    {
        $this->_frontEnd        = $frontend;
        $this->_frontEndOptions = $options;
    }

    public function setBackEnd($backend, $options = array())
    {
        $this->_backEnd        = $backend;
        $this->_backEndOptions = $options;
    }

    public function createCache()
    {
        $frontEnd = $this->_frontEnd;
        $backEnd  = $this->_backEnd;

        $front = new $frontEnd($this->_frontEndOptions);
        $cache = new $backEnd(
            $front,
            $this->_backEndOptions
        );

        return $cache;
    }
}