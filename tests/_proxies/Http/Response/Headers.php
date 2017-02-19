<?php

namespace Phalcon\Test\Proxy\Http\Response;

use Phalcon\Http\Response\Headers as PhHeaders;

/**
 * \Phalcon\Test\Proxy\Http\Response\Headers
 * Http Response Headers proxy class for \Phalcon\Http\Response\Headers
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Proxy\Http\Response
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Headers extends PhHeaders
{
    public function set($name, $value)
    {
        parent::set($name, $value);
    }

    public function get($name)
    {
        return parent::get($name);
    }

    public function setRaw($header)
    {
        parent::setRaw($header);
    }

    public function remove($header)
    {
        parent::remove($header);
    }

    public function send()
    {
        return parent::send();
    }

    public function reset()
    {
        parent::reset();
    }

    public function toArray()
    {
        return parent::toArray();
    }

    public static function __set_state(array $data)
    {
        return parent::__set_state($data);
    }
}
