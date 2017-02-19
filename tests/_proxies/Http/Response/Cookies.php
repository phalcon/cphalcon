<?php

namespace Phalcon\Test\Proxy\Http\Response;

use Phalcon\Http\Response\Cookies as PhCookies;
use Phalcon\DiInterface;

/**
 * \Phalcon\Test\Proxy\Http\Response\Cookies
 * Http Response Cookies proxy class for \Phalcon\Http\Response\Cookies
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
class Cookies extends PhCookies
{
    public function setDI(DiInterface $di)
    {
        parent::setDI($di);
    }

    public function getDI()
    {
        return parent::getDI();
    }

    public function useEncryption($useEncryption)
    {
        return parent::useEncryption($useEncryption);
    }

    public function isUsingEncryption()
    {
        return parent::isUsingEncryption();
    }

    public function set($name, $value = null, $expire = 0, $path = "/", $secure = null, $domain = null, $httpOnly = null)
    {
        return parent::set($name, $value, $expire, $path, $secure, $domain, $httpOnly);
    }

    public function get($name)
    {
        return parent::get($name);
    }

    public function has($name)
    {
        return parent::has($name);
    }

    public function delete($name)
    {
        return parent::delete($name);
    }

    public function send()
    {
        return parent::send();
    }

    public function reset()
    {
        return parent::reset();
    }
}
