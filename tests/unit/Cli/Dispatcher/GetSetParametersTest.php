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

final class GetSetParametersTest extends AbstractUnitTestCase
{
    use DiTrait;

    public function testCliDispatcherGetSetParameters(): void
    {
        $this->setNewCliFactoryDefault();
        $dispatcher = new Dispatcher();

        $this->container->setShared('dispatcher', $dispatcher);
        $dispatcher->setDI($this->container);

        // Test $this->dispatcher->getParams()
        $dispatcher->setNamespaceName('Phalcon\Tests\Support\Tasks');
        $dispatcher->setTaskName('params');
        $dispatcher->setActionName('params');

        $dispatcher->setParameters(
            [
                'a' => 'This',
                'b' => 'Is',
                'c' => 'An',
                'd' => 'Example',
            ]
        );

        $dispatcher->dispatch();

        $expected = 'This';
        $actual   = $dispatcher->getParam('a');
        $this->assertSame($expected, $actual);

        $expected = 'Is';
        $actual   = $dispatcher->getParam('b');
        $this->assertSame($expected, $actual);

        $expected = 'An';
        $actual   = $dispatcher->getParam('c');
        $this->assertSame($expected, $actual);

        $expected = 'Example';
        $actual   = $dispatcher->getParam('d');
        $this->assertSame($expected, $actual);

        $expected = 'This';
        $actual   = $dispatcher->getParameter('a');
        $this->assertSame($expected, $actual);

        $expected = 'Is';
        $actual   = $dispatcher->getParameter('b');
        $this->assertSame($expected, $actual);

        $expected = 'An';
        $actual   = $dispatcher->getParameter('c');
        $this->assertSame($expected, $actual);

        $expected = 'Example';
        $actual   = $dispatcher->getParameter('d');
        $this->assertSame($expected, $actual);

        $dispatcher->setParam('e', 'one');

        $expected = 'one';
        $actual   = $dispatcher->getParam('e');
        $this->assertSame($expected, $actual);

        $dispatcher->setParameter('f', 'two');

        $expected = 'two';
        $actual   = $dispatcher->getParameter('f');
        $this->assertSame($expected, $actual);
    }
}
