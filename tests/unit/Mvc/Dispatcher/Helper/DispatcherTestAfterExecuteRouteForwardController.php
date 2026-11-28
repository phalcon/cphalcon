<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Mvc\Dispatcher\Helper;

use Phalcon\Mvc\Controller;

/**
 * @author        Andres Gutierrez <andres@phalcon.io>
 * @author        Nikolaos Dimopoulos <nikos@phalcon.io>
 */
class DispatcherTestAfterExecuteRouteForwardController extends Controller
{
    public function afterExecuteRoute()
    {
        $this->trace('afterExecuteRoute-method');

        $di = $this->getDI();

        $dispatcher = $di->getShared('dispatcher');

        $dispatcher->forward(
            [
                'controller' => 'dispatcher-test-default',
                'action'     => 'index',
            ]
        );
    }

    public function beforeExecuteRoute()
    {
        $this->trace('beforeExecuteRoute-method');
    }

    public function indexAction()
    {
        $this->trace('indexAction');
    }

    public function initialize()
    {
        $this->trace('initialize-method');
    }

    /**
     * Add tracing information into the current dispatch tracer
     */
    protected function trace($text)
    {
        $this->getDI()->getShared('dispatcherListener')->trace($text);
    }
}
