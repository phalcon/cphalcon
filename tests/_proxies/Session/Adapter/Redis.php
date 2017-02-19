<?php

namespace Phalcon\Test\Proxy\Session\Adapter;

use Phalcon\Session\Adapter\Redis as PhRedis;

/**
 * \Phalcon\Test\Proxy\Session\Adapter\Redis
 * Redis session proxy class for \Phalcon\Session\Adapter\Redis
 *
 * @copyright (c) 2011-2017 Phalcon Team
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
class Redis extends PhRedis
{
    public function __construct(array $options = null)
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

    public function getRedis()
    {
        return parent::getRedis();
    }

    public function getLifetime()
    {
        return parent::getLifetime();
    }
}
