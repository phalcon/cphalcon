<?php

namespace Phalcon\Test\Proxy\Session\Adapter;

use Phalcon\Session\Adapter\Memcache as PhMemcache;

/**
 * \Phalcon\Test\Proxy\Session\Adapter\Memcache
 * Memcache session proxy class for \Phalcon\Session\Adapter\Memcache
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Proxy\Session\Adapter
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Memcache extends PhMemcache
{
    public function __construct($options = null)
    {
        return parent::__construct($options);
    }

    public function open()
    {
        return parent::open();
    }

    public function close()
    {
        return parent::close();
    }

    public function read($sessionId)
    {
        return parent::read($sessionId);
    }

    public function write($sessionId, $data)
    {
        return parent::write($sessionId, $data);
    }

    public function destroy($sessionId = null)
    {
        return parent::destroy($sessionId);
    }

    public function gc()
    {
        return parent::gc();
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
