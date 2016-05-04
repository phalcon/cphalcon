<?php

namespace Phalcon\Test\Proxy\Annotations\Adapter;

use Phalcon\Annotations\Adapter\Memory as PhMemory;
use Phalcon\Annotations\Reflection;

/**
 * \Phalcon\Test\Proxy\Annotations\Adapter\Memory
 * Role proxy class for \Phalcon\Annotations\Adapter\Memory
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Proxy\Annotations\Adapter
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
    public function read($key)
    {
        return parent::read($key);
    }

    public function write($key, Reflection $data)
    {
        return parent::write($key, $data);
    }
}
