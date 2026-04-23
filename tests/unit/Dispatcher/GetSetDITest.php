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

namespace Phalcon\Tests\Unit\Dispatcher;

use Phalcon\Di\Di;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetSetDITest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-17
     */
    public function testDispatcherGetSetDI(): void
    {
        $container  = new Di();
        $dispatcher = new Dispatcher();

        $dispatcher->setDI($container);

        $actual   = $container;
        $expected = $dispatcher->getDI();
        $this->assertSame($expected, $actual);

        $class  = Di::class;
        $actual = $dispatcher->getDI();
        $this->assertInstanceOf($class, $actual);
    }
}
