<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Mvc\Dispatcher\Helper;

use Phalcon\Events\Manager as EventsManager;
use Phalcon\Mvc\Controller;

/**
 * Controller that attaches an events manager to the dispatcher inside
 * initialize(), simulating the use-case from issue #16440.
 */
class DispatcherTestInitializeSetEventsManagerController extends Controller
{
    public function indexAction()
    {
        $this->trace('indexAction');
    }

    public function initialize()
    {
        $this->trace('initialize-method');

        $di         = $this->getDI();
        $dispatcher = $di->getShared('dispatcher');

        $eventsManager = new EventsManager();
        $eventsManager->attach(
            'dispatch',
            $di->getShared('dispatcherListener'),
            200
        );

        $dispatcher->setEventsManager($eventsManager);
    }

    protected function trace($text)
    {
        $this->getDI()->getShared('dispatcherListener')->trace($text);
    }
}
