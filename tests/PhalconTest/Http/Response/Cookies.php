<?php
/**
 * Cookies.php
 * \PhalconTest\Http\Response\Cookies
 *
 * Http Response Cookies proxy class
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

use Phalcon\Http\Response\Cookies as PhCookies;

class Cookies
{
    private $cookies = null;
    
    public function __construct($content = null, $code = null, $status = null)
    {
        $this->cookies = new PhCookies($content, $code, $status);
    }

    public function __desctruct()
    {
        unset($this->cookies);
    }

    public function setDI($di)
	{
        $this->cookies->setDI($di);
	}

    public function getDI()
	{
        return $this->cookies->getDI();
	}

	public function useEncryption($useEncryption)
	{
        $this->cookies->useEncryption($useEncryption);
		return $this;
	}

	public function isUsingEncryption()
	{
        return $this->cookies->isUsingEncryption();
	}

	public function set($name, $value = null, $expire = 0, $path = "/", $secure = null, $domain = null, $httpOnly = null)
	{
        $this->cookies->set($name, $value, $expire, $path, $secure, $domain, $httpOnly);
		return $this;
	}

	public function get($name)
	{
        return $this->cookies->get($name);
    }

	public function has($name)
	{
        return $this->cookies->has($name);
	}

	public function delete($name)
	{
        return $this->cookies->delete($name);
	}

	public function send()
	{
        return $this->cookies->send();
	}

	public function reset()
	{
        $this->cookies->reset();
		return $this;
	}
}
