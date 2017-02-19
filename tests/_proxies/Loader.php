<?php

namespace Phalcon\Test\Proxy;

use Phalcon\Loader as PhLoader;
use Phalcon\Events\ManagerInterface;

/**
 * \Phalcon\Test\Proxy\Loader
 * Filter proxy class for \Phalcon\Loader
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Proxy
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Loader extends PhLoader
{
    public function setEventsManager(ManagerInterface $eventsManager)
    {
        parent::setEventsManager($eventsManager);
    }

    public function getEventsManager()
    {
        return parent::getEventsManager();
    }

    public function setExtensions(array $extensions)
    {
        return parent::setExtensions($extensions);
    }

    public function getExtensions()
    {
        return parent::getExtensions();
    }

    public function registerNamespaces(array $namespaces, $merge = false)
    {
        return parent::registerNamespaces($namespaces, $merge);
    }

    public function getNamespaces()
    {
        return parent::getNamespaces();
    }

    public function registerDirs(array $directories, $merge = false)
    {
        return parent::registerDirs($directories, $merge);
    }

    public function getDirs()
    {
        return parent::getDirs();
    }

    public function registerFiles(array $files, $merge = false)
    {
        return parent::registerFiles($files, $merge);
    }

    protected function prepareNamespace(array $namespace)
    {
        return parent::prepareNamespace($namespace);
    }

    public function getFiles()
    {
        return parent::getFiles();
    }

    public function registerClasses(array $classes, $merge = false)
    {
        return parent::registerClasses($classes, $merge);
    }

    public function getClasses()
    {
        return parent::getClasses();
    }

    public function register()
    {
        return parent::register();
    }

    public function unregister()
    {
        return parent::unregister();
    }

    public function autoLoad($className)
    {
        return parent::autoLoad($className);
    }

    public function getFoundPath()
    {
        return parent::getFoundPath();
    }

    public function getCheckedPath()
    {
        return parent::getCheckedPath();
    }
}
