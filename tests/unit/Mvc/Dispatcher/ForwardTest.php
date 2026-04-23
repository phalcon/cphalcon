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

class ForwardTest extends BaseDispatcher
{
    /**
     * Tests Phalcon\Mvc\Dispatcher :: forward()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcDispatcherForward(): void
    {
        $dispatcher = $this->getDispatcher();
        $dispatcher->dispatch();
        $dispatcher->forward([
            'controller' => 'dispatcher-test-default-two',
            'action'     => 'index',
        ]);
        $this->assertSame('dispatcher-test-default-two', $dispatcher->getControllerName());
        $this->assertSame('index', $dispatcher->getActionName());
    }
}
