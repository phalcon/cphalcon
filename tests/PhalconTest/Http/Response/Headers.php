<?php
/**
 * Headers.php
 * \PhalconTest\Http\Response\Headers
 *
 * Http Response Headers proxy class
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
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

namespace PhalconTest\Http\Response;

use Phalcon\Http\Response\Headers as PhHeaders;

class Headers extends PhHeaders
{
    public function set($name, $value)
    {
        parent::set($name, $value);
    }

    public function get($name)
    {
        parent::get($name);
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
        parent::send();
    }

    public function reset()
    {
        parent::reset();
    }

    public function toArray()
    {
        return parent::toArray();
    }

    public static function __set_state($data)
    {
        return parent::__set_state($data);
    }
}
