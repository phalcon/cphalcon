<?php

namespace Phalcon\Test\Proxy;

use Phalcon\Di as PhDi;
use Phalcon\DiInterface;
use Phalcon\Di\ServiceInterface;
use Phalcon\Events\ManagerInterface;

/**
 * \Phalcon\Test\Proxy\Di
 * Escaper proxy class for \Phalcon\Di
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Proxy
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Di extends PhDi
{
    public function __construct()
    {
        parent::__construct();
    }

    public function setInternalEventsManager(ManagerInterface $eventsManager)
    {
        parent::setInternalEventsManager($eventsManager);
    }

    public function getInternalEventsManager()
    {
        return parent::getInternalEventsManager();
    }

    public function set($name, $definition, $shared = false)
    {
        return parent::set($name, $definition, $shared);
    }

    public function setShared($name, $definition)
    {
        return parent::setShared($name, $definition);
    }

    public function remove($name)
    {
        parent::remove($name);
    }

    public function attempt($name, $definition, $shared = false)
    {
        return parent::attempt($name, $definition, $shared);
    }

    public function setRaw($name, ServiceInterface $rawDefinition)
    {
        return parent::setRaw($name, $rawDefinition);
    }

    public function getRaw($name)
    {
        return parent::getRaw($name);
    }

    public function getService($name)
    {
        return parent::getService($name);
    }

    public function get($name, $parameters = null)
    {
        return parent::get($name, $parameters);
    }

    public function getShared($name, $parameters = null)
    {
        return parent::getShared($name, $parameters);
    }

    public function has($name)
    {
        return parent::has($name);
    }

    public function wasFreshInstance()
    {
        return parent::wasFreshInstance();
    }

    public function getServices()
    {
        return parent::getServices();
    }

    public function offsetExists($name)
    {
        return parent::offsetExists($name);
    }

    public function offsetSet($name, $definition)
    {
        return parent::offsetSet($name, $definition);
    }

    public function offsetGet($name)
    {
        return parent::offsetGet($name);
    }

    public function offsetUnset($name)
    {
        return parent::offsetUnset($name);
    }

    public function __call($method, $arguments = null)
    {
        return parent::__call($method, $arguments);
    }

    public static function setDefault(DiInterface $dependencyInjector)
    {
        parent::setDefault($dependencyInjector);
    }

    public static function getDefault()
    {
        return parent::getDefault();
    }

    public static function reset()
    {
        parent::reset();
    }
}
