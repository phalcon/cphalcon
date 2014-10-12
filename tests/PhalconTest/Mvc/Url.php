<?php
/**
 * Url.php
 * \PhalconTest\Mvc\Url
 *
 * Url proxy class
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

namespace PhalconTest\Mvc;

use Phalcon\Mvc\Url as PhUrl;

class Url
{
    private $url = null;
    
    public function __construct()
    {
        $this->url = new PhUrl();
    }

    public function __desctruct()
    {
        unset($this->url);
    }

    public function setDI($di)
	{
		$this->url->setDI($di);
	}

    public function getDI()
	{
        return $this->url->getDI();
	}

	public function setBaseUri($baseUri)
	{
        $this->url->setBaseUri($baseUri);
        return $this;
	}

	public function setStaticBaseUri($staticBaseUri)
	{
        $this->url->setStaticBaseUri($staticBaseUri);
        return $this;
	}

	public function getBaseUri()
	{
        return $this->url->getBaseUri();
	}

	public function getStaticBaseUri()
	{
        return $this->url->getStaticBaseUri();
	}

	public function setBasePath($basePath)
	{
        $this->url->setBasePath($basePath);
        return $this;
	}

	public function getBasePath()
	{
        return $this->url->getBasePath();
	}

	public function get($uri = null, $args = null, $local = null)
	{
        return $this->url->get($uri, $args, $local);
	}

	public function getStatic($uri = null)
	{
        return $this->url->getStatic($uri);
	}

	public function path($path = null)
	{
        return $this->url->path($path);
	}
}
