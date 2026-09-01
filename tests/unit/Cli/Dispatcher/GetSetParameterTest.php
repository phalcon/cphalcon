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

namespace Phalcon\Tests\Unit\Cli\Dispatcher;

use Phalcon\Cli\Dispatcher;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

final class GetSetParameterTest extends AbstractUnitTestCase
{
    use DiTrait;

    public function testCliDispatcherGetSetParameter(): void
    {
        $this->setNewCliFactoryDefault();
        $dispatcher = new Dispatcher();

        $this->container->setShared('dispatcher', $dispatcher);
        $dispatcher->setDI($this->container);

        // Test $this->dispatcher->getParam()
        $dispatcher->setNamespaceName('Phalcon\Tests\Support\Tasks');
        $dispatcher->setTaskName('params');
        $dispatcher->setActionName('param');

        $dispatcher->setParams(
            ['This', 'Is', 'An', 'Example']
        );

        $dispatcher->dispatch();

        $expected = '$param[0] is the same as $this->dispatcher->getParam(0)';
        $actual   = $dispatcher->getReturnedValue();
        $this->assertSame($expected, $actual);
    }
}
