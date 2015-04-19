<?php
/**
 * Memcache.php
 * \PhalconTest\Session\Adapter\Memcache
 *
 * Memcache session proxy class
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2015 Phalcon Team
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

namespace PhalconTest\Session\Adapter;

use \Phalcon\Session\Adapter\Memcache as PhMemcache;
use \Phalcon\DiInterface as PhDIInterface;

class Memcache extends PhMemcache
{
    public function __construct($options = null)
    {
        return parent::__construct($options);
    }
    
    public function open($save_path, $session_name)
    {
        return parent::open($save_path, $session_name);
    }

    public function close()
    {
        return parent::close();
    }

    public function read($session_id)
    {
        return parent::read($session_id);
    }

    public function write($session_id, $session_data)
    {
        return parent::write($session_id, $session_data);
    }

    public function destroy($session_id = null)
    {
        return parent::destroy($session_id);
    }

    public function gc($maxlifetime)
    {
        return parent::gc($maxlifetime);
    }



    public function getMemcache()
    {
        return parent::getMemcache();
    }

    public function getLifetime()
    {
        return parent::getLifetime();
    }
}
