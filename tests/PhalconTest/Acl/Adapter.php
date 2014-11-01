<?php
/**
 * Adapter.php
 * \PhalconTest\Acl\Adapter
 *
 * Acl Adapter proxy class
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

namespace PhalconTest\Acl;

use \Phalcon\Acl\Adapter as PhAdapter;

class Adapter extends PhAdapter
{
    public function setEventsManager($eventsManager)
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
}
