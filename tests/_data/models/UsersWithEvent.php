<?php

namespace Phalcon\Test\Models;

use Phalcon\Events\Event;
use Phalcon\Events\Manager;

/**
 * \Phalcon\Test\Models\Users
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Models
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class UsersWithEvent extends Users
{
    public function getSource()
    {
        return 'users';
    }

    public function initialize()
    {
        $eventsManager = new Manager();

        $eventsManager->attach(
            "model:beforeSave",
            function (Event $event, UsersWithEvent $user) {
                $user->name = 'test user after event';
                return true;
            }
        );

        $this->setEventsManager($eventsManager);
    }
}
