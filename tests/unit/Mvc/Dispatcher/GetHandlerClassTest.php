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

class GetHandlerClassTest extends BaseDispatcher
{
    /**
     * Tests Phalcon\Mvc\Dispatcher :: getHandlerClass()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcDispatcherGetHandlerClass(): void
    {
        $dispatcher = $this->getDispatcher();
        $this->assertSame(
            DispatcherTestDefaultController::class,
            $dispatcher->getHandlerClass()
        );
    }
}
