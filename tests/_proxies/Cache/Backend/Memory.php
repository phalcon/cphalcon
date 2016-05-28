<?php

namespace Phalcon\Test\Proxy\Cache\Backend;

use Phalcon\Cache\Backend\Memory as PhMemory;

/**
 * \Phalcon\Test\Proxy\Cache\Backend\Memory
 * Memory proxy class for \Phalcon\Cache\Backend\Memory
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Proxy\Cache\Backend
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Memory extends PhMemory
{
    public function get($keyName, $lifetime = null)
    {
        return parent::get($keyName, $lifetime);
    }

    public function save($keyName = null, $content = null, $lifetime = null, $stopBuffer = true)
    {
        return parent::save($keyName, $content, $lifetime, $stopBuffer);
    }

    public function delete($keyName)
    {
        return parent::delete($keyName);
    }

    public function queryKeys($prefix = null)
    {
        return parent::queryKeys($prefix);
    }

    public function exists($keyName = null, $lifetime = null)
    {
        return parent::exists($keyName, $lifetime);
    }

    public function increment($keyName = null, $value = null)
    {
        return parent::increment($keyName, $value);
    }

    public function decrement($keyName = null, $value = null)
    {
        return parent::decrement($keyName, $value);
    }

    public function flush()
    {
        return parent::flush();
    }

    public function serialize()
    {
        return parent::serialize();
    }

    public function unserialize($data)
    {
        return parent::unserialize($data);
    }
}
