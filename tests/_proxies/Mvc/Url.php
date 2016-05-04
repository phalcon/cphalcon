<?php

namespace Phalcon\Test\Proxy\Mvc;

use Phalcon\Mvc\Url as PhUrl;
use Phalcon\DiInterface;

/**
 * \Phalcon\Test\Proxy\Mvc\Url
 * Url proxy class for \Phalcon\Mvc\Url
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Proxy\Mvc
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Url extends PhUrl
{
    public function setDI(DiInterface $di)
    {
        parent::setDI($di);
    }

    public function getDI()
    {
        parent::getDI();
    }

    public function setBaseUri($baseUri)
    {
        return parent::setBaseUri($baseUri);
    }

    public function setStaticBaseUri($staticBaseUri)
    {
        return parent::setStaticBaseUri($staticBaseUri);
    }

    public function getBaseUri()
    {
        return parent::getBaseUri();
    }

    public function getStaticBaseUri()
    {
        return parent::getStaticBaseUri();
    }

    public function setBasePath($basePath)
    {
        return parent::setBasePath($basePath);
    }

    public function getBasePath()
    {
        return parent::getBasePath();
    }

    public function get($uri = null, $args = null, $local = null)
    {
        return parent::get($uri, $args, $local);
    }

    public function getStatic($uri = null)
    {
        return parent::getStatic($uri);
    }

    public function path($path = null)
    {
        return parent::path($path);
    }
}
