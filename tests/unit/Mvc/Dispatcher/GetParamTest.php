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

use Phalcon\Cli\Dispatcher as CliDispatcher;
use Phalcon\Cli\Dispatcher\Exception as CliDispatcherException;
use Phalcon\Dispatcher\Exception as DispatcherException;
use Phalcon\Tests\Unit\Mvc\Dispatcher\Helper\BaseDispatcher;

class GetParamTest extends BaseDispatcher
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcDispatcherGetParam(): void
    {
        $dispatcher = $this->getDispatcher();
        $dispatcher->setParams(['id' => 42]);
        $this->assertSame(42, $dispatcher->getParam('id'));
        $this->assertNull($dispatcher->getParam('nonexistent'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testDispatcherGetParameterNullContainerThrows(): void
    {
        $dispatcher = new CliDispatcher();
        // No DI container set
        $dispatcher->setParams(['key' => 'value']);

        $this->expectException(CliDispatcherException::class);
        $this->expectExceptionMessage(
            "A dependency injection container is required to access the 'filter' service"
        );
        $this->expectExceptionCode(DispatcherException::EXCEPTION_NO_DI);

        // Non-empty filters + null container → throwDispatchException at L943
        $dispatcher->getParameter('key', 'string');
    }
}
