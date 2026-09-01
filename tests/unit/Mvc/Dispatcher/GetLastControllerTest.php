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

namespace Phalcon\Tests\Unit\Mvc\Dispatcher;

use Phalcon\Tests\Unit\Mvc\Dispatcher\Helper\BaseDispatcher;
use Phalcon\Tests\Unit\Mvc\Dispatcher\Helper\DispatcherTestDefaultController;
use Phalcon\Tests\Unit\Mvc\Dispatcher\Helper\DispatcherTestDefaultTwoController;

class GetLastControllerTest extends BaseDispatcher
{
    /**
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testLastHandlerForward(): void
    {
        $dispatcher = $this->getDispatcher();

        $dispatcher->setActionName('forwardExternal');

        $dispatcher->dispatch();

        $this->assertInstanceOf(
            DispatcherTestDefaultTwoController::class,
            $dispatcher->getLastController()
        );
    }

    /**
     * @author Mark Johnson <https://github.com/virgofx>
     * @since  2017-10-07
     */
    public function testMvcDispatcherGetLastController(): void
    {
        $dispatcher = $this->getDispatcher();

        $dispatcher->dispatch();

        $this->assertInstanceOf(
            DispatcherTestDefaultController::class,
            $dispatcher->getLastController()
        );
    }
}
