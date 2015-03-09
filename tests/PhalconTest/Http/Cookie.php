<?php
/**
 * Cookie.php
 * \PhalconTest\Http\Cookie
 *
 * Http Cookie proxy class
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

namespace PhalconTest\Http;

use \Phalcon\Http\Cookie as PhCookie;
use \Phalcon\DiInterface as PhDIInterface;

class Cookie extends PhCookie
{
    public function setDI(PhDIInterface $di)
    {
        parent::setDI($di);
    }

    public function getDI()
    {
        return parent::getDI();
    }

    public function setValue($value)
    {
        return parent::setValue($value);
    }

    public function getValue($filters = null, $defaultValue = null)
    {
        return parent::getValue($filters, $defaultValue);
    }

    public function send()
    {
        return parent::send();
    }

    public function restore()
    {
        return parent::restore();
    }

    public function delete()
    {
        parent::delete();
    }

    public function useEncryption($useEncryption)
    {
        return parent::useEncryption($useEncryption);
    }

    public function isUsingEncryption()
    {
        return parent::isUsingEncryption();
    }

    public function setExpiration($expire)
    {
        return parent::setExpiration($expire);
    }

    public function getExpiration()
    {
        return parent::getExpiration();
    }

    public function setPath($path)
    {
        return parent::setPath($path);
    }

    public function getPath()
    {
        parent::getPath();
    }

    public function setDomain($domain)
    {
        return parent::setDomain($domain);
    }

    public function getDomain()
    {
        parent::getDomain();
    }

    public function setSecure($secure)
    {
        return parent::setSecure($secure);
    }

    public function getSecure()
    {
        parent::getSource();
    }

    public function setHttpOnly($httpOnly)
    {
        return parent::setHttpOnly($httpOnly);
    }

    public function getHttpOnly()
    {
        parent::getHttpOnly();
    }

    public function __toString()
    {
        return parent::__toString();
    }
}
