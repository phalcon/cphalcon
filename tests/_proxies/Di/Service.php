<?php

namespace Phalcon\Test\Proxy\Di;

use Phalcon\Di\Service as PhService;
use Phalcon\DiInterface;

/**
 * \Phalcon\Test\Proxy\Di\Service
 * Escaper proxy class for \Phalcon\Di\Service
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Proxy\Di
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Service extends PhService
{
    public function getName()
    {
        return parent::getName();
    }

    public function setShared($shared)
    {
        parent::setShared($shared);
    }

    public function isShared()
    {
        return parent::isShared();
    }

    public function setSharedInstance($sharedInstance)
    {
        parent::setSharedInstance($sharedInstance);
    }

    public function setDefinition($definition)
    {
        parent::setDefinition($definition);
    }

    public function getDefinition()
    {
        return parent::getDefinition();
    }

    public function resolve($parameters = null, DiInterface $dependencyInjector = null)
    {
        return parent::resolve($parameters, $dependencyInjector);
    }

    public function setParameter($position, array $parameter)
    {
        return parent::setParameter($position, $parameter);
    }

    public function getParameter($position)
    {
        return parent::getParameter($position);
    }

    public function isResolved()
    {
        return parent::isResolved();
    }

    public static function __set_state(array $attributes)
    {
        return parent::__set_state($attributes);
    }
}
