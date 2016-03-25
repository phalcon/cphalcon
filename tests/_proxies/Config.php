<?php

namespace Phalcon\Test\Proxy;

use Phalcon\Config as PhConfig;

/**
 * \Phalcon\Test\Proxy\Config
 * Config proxy class for \Phalcon\Config
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Proxy
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Config extends PhConfig
{
    public function __construct($arrayConfig = null)
    {
        parent::__construct($arrayConfig);
    }

    public function offsetExists($index)
    {
        return parent::offsetExists($index);
    }

    public function get($index, $defaultValue = null)
    {
        return parent::get($index, $defaultValue);
    }

    public function offsetGet($index)
    {
        return parent::offsetGet($index);
    }

    public function offsetSet($index, $value)
    {
        parent::offsetSet($index, $value);
    }

    public function offsetUnset($index)
    {
        parent::offsetUnset($index);
    }

    public function merge(PhConfig $config)
    {
        return parent::merge($config);
    }

    public function toArray()
    {
        return parent::toArray();
    }

    public function count()
    {
        return parent::count();
    }

    public static function __set_state(array $data)
    {
        return parent::__set_state($data);
    }
}
