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

class Cookie
{
    private $cookie = null;
    
    public function __construct($name, $value = null, $expire = 0, $path = "/", $secure = null, $domain = null, $httpOnly = null)
    {
        $this->cookie = new PhCookie($name, $value, $expire, $path, $secure, $domain, $httpOnly);
    }

    public function __desctruct()
    {
        unset($this->cookie);
    }

	public function setDI($di)
	{
        $this->cookie->setDI($di);
	}

	public function getDI()
	{
        return $this->cookie->getDI();
	}

	public function setValue($value)
	{
        $this->cookie->setValue($value);
		return $this;
	}

	public function getValue($filters = null, $defaultValue = null)
    {
        return $this->cookie->getValue($filters, $defaultValue);
	}

	public function send()
	{
        $this->cookie->send();
		return $this;
	}

	public function restore()
	{
        $this->cookie->restore();
		return $this;
	}

	public function delete()
    {
        $this->cookie->delete();
	}

	public function useEncryption($useEncryption)
	{
        $this->cookie->useEncryption($useEncryption);
		return $this;
	}

	public function isUsingEncryption()
	{
        return $this->cookie->isUsingEncryption();
	}

	public function setExpiration($expire)
	{
        $this->cookie->setExpiration($expire);
		return $this;
	}

	public function getExpiration()
	{
        return $this->cookie->getExpiration();
	}

	public function setPath($path)
	{
        $this->cookie->setPath($path);
		return $this;
	}

	public function getPath()
	{
        $this->cookie->getPath();
	}

	public function setDomain($domain)
	{
        $this->cookie->setDomain($domain);
		return $this;
	}

	public function getDomain()
	{
        $this->cookie->getDomain();
	}

	public function setSecure($secure)
	{
        $this->cookie->setSecure($secure);
		return $this;
	}

	public function getSecure()
    {
        $this->cookie->getSource();
	}

	public function setHttpOnly($httpOnly)
	{
        $this->cookie->setHttpOnly($httpOnly);
		return $this;
	}

	public function getHttpOnly()
	{
        $this->cookie->getHttpOnly();
	}

	public function __toString()
    {
        return $this->cookie->__toString();
    }
}
