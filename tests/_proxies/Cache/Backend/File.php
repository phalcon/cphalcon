<?php

namespace Phalcon\Test\Proxy\Cache\Backend;

use Phalcon\Cache\FrontendInterface;
use Phalcon\Cache\Backend\File as PhFile;

/**
 * \Phalcon\Test\Proxy\Cache\Backend\File
 * File proxy class for \Phalcon\Cache\Backend\File
 *
 * @copyright (c) 2011-2017 Phalcon Team
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
class File extends PhFile
{
    public function __construct(FrontendInterface $frontend, array $options)
    {
        parent::__construct($frontend, $options);
    }

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

    public function increment($keyName = null, $value = 1)
    {
        return parent::increment($keyName, $value);
    }

    public function decrement($keyName = null, $value = 1)
    {
        return parent::decrement($keyName, $value);
    }

    public function flush()
    {
        return parent::flush();
    }

    public function getKey($key)
    {
        return parent::getKey($key);
    }

    public function useSafeKey($useSafeKey)
    {
        return parent::useSafeKey($useSafeKey);
    }
}
