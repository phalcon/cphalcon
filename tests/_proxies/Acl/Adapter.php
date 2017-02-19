<?php

namespace Phalcon\Test\Proxy\Acl;

use Phalcon\Acl\Adapter as PhAdapter;
use Phalcon\Events\ManagerInterface;

/**
 * \Phalcon\Test\Proxy\Acl\Adapter
 * Acl Adapter proxy class for \Phalcon\Acl\Adapter
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Proxy\Acl
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
abstract class Adapter extends PhAdapter
{
    public function setEventsManager(ManagerInterface $eventsManager)
    {
        parent::setEventsManager($eventsManager);
    }

    public function getEventsManager()
    {
        return parent::getEventsManager();
    }

    public function setDefaultAction($defaultAccess)
    {
        parent::setDefaultAction($defaultAccess);
    }

    public function getDefaultAction()
    {
        return parent::getDefaultAction();
    }

    public function getActiveRole()
    {
        return parent::getActiveRole();
    }

    public function getActiveResource()
    {
        return parent::getActiveResource();
    }

    public function getActiveAccess()
    {
        return parent::getActiveAccess();
    }
}
