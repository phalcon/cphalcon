<?php

namespace Phalcon\Test\Listener;

use Phalcon\Events\Event;
use Phalcon\Http\Request;

/**
 * Phalcon\Test\Listener\CustomAuthorizationListener
 *
 * @copyright (c) 2011-2018 Phalcon Team
 * @link      https://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Listener
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class CustomAuthorizationListener
{
    public function beforeAuthorizationResolve(Event $event, Request $request, array $data)
    {
        return [
            'Fired-Before'=> $event->getType(),
        ];
    }

    public function afterAuthorizationResolve(Event $event, Request $request, array $data)
    {
        return [
            'Fired-After'=> $event->getType(),
        ];
    }
}
