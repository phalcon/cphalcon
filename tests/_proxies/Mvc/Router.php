<?php

namespace Phalcon\Test\Proxy\Mvc;

use Phalcon\DiInterface;
use Phalcon\Events\ManagerInterface;
use Phalcon\Mvc\Router as PhRouter;
use Phalcon\Mvc\Router\GroupInterface;

/**
 * \Phalcon\Test\Proxy\Mvc\Router
 * Router proxy class for \Phalcon\Mvc\Router
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Proxy\Mvc
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Router extends PhRouter
{
    public function __construct($defaultRoutes = true)
    {
        parent::__construct($defaultRoutes);
    }

    public function setDI(DiInterface $dependencyInjector)
    {
        parent::setDI($dependencyInjector);
    }

    public function getDI()
    {
        return parent::getDI();
    }

    public function setEventsManager(ManagerInterface $eventsManager)
    {
        parent::setEventsManager($eventsManager);
    }

    public function getEventsManager()
    {
        return parent::getEventsManager();
    }

    public function getRewriteUri()
    {
        return parent::getRewriteUri();
    }

    public function setUriSource($uriSource)
    {
        return parent::setUriSource($uriSource);
    }

    public function removeExtraSlashes($remove)
    {
        return parent::removeExtraSlashes($remove);
    }

    public function setDefaultNamespace($namespaceName)
    {
        return parent::setDefaultNamespace($namespaceName);
    }

    public function setDefaultModule($moduleName)
    {
        return parent::setDefaultModule($moduleName);
    }

    public function setDefaultController($controllerName)
    {
        return parent::setDefaultController($controllerName);
    }

    public function setDefaultAction($actionName)
    {
        return parent::setDefaultAction($actionName);
    }

    public function setDefaults(array $defaults)
    {
        return parent::setDefaults($defaults);
    }

    public function getDefaults()
    {
        return parent::getDefaults();
    }

    public function handle($uri = null)
    {
        return parent::handle($uri);
    }

    public function add($pattern, $paths = null, $httpMethods = null, $position = Router::POSITION_LAST)
    {
        return parent::add($pattern, $paths, $httpMethods, $position);
    }

    public function addGet($pattern, $paths = null, $position = Router::POSITION_LAST)
    {
        return parent::addGet($pattern, $paths, $position);
    }

    public function addPost($pattern, $paths = null, $position = Router::POSITION_LAST)
    {
        return parent::addPost($pattern, $paths, $position);
    }

    public function addPut($pattern, $paths = null, $position = Router::POSITION_LAST)
    {
        return parent::addPut($pattern, $paths, $position);
    }

    public function addPatch($pattern, $paths = null, $position = Router::POSITION_LAST)
    {
        return parent::addPatch($pattern, $paths, $position);
    }

    public function addDelete($pattern, $paths = null, $position = Router::POSITION_LAST)
    {
        return parent::addDelete($pattern, $paths, $position);
    }

    public function addOptions($pattern, $paths = null, $position = Router::POSITION_LAST)
    {
        return parent::addOptions($pattern, $paths, $position);
    }

    public function addHead($pattern, $paths = null, $position = Router::POSITION_LAST)
    {
        return parent::addHead($pattern, $paths, $position);
    }

    public function addPurge($pattern, $paths = null, $position = Router::POSITION_LAST)
    {
        return parent::addPurge($pattern, $paths, $position);
    }

    public function addTrace($pattern, $paths = null, $position = Router::POSITION_LAST)
    {
        return parent::addTrace($pattern, $paths, $position);
    }

    public function addConnect($pattern, $paths = null, $position = Router::POSITION_LAST)
    {
        return parent::addConnect($pattern, $paths, $position);
    }

    public function mount(GroupInterface $group)
    {
        return parent::mount($group);
    }

    public function notFound($paths)
    {
        return parent::notFound($paths);
    }

    public function clear()
    {
        parent::clear();
    }

    public function getNamespaceName()
    {
        return parent::getNamespaceName();
    }

    public function getModuleName()
    {
        return parent::getModuleName();
    }

    public function getControllerName()
    {
        return parent::getControllerName();
    }

    public function getActionName()
    {
        return parent::getActionName();
    }

    public function getParams()
    {
        return parent::getParams();
    }

    public function getMatchedRoute()
    {
        return parent::getMatchedRoute();
    }

    public function getMatches()
    {
        return parent::getMatches();
    }

    public function wasMatched()
    {
        return parent::wasMatched();
    }

    public function getRoutes()
    {
        return parent::getRoutes();
    }

    public function getRouteById($id)
    {
        return parent::getRouteById($id);
    }

    public function getRouteByName($name)
    {
        return parent::getRouteByName($name);
    }

    public function isExactControllerName()
    {
        return parent::isExactControllerName();
    }
}
