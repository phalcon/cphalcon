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

namespace Phalcon\Tests\Cli\Cli\Dispatcher;

use CliTester;
use Phalcon\Cli\Dispatcher;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

class GetSetParametersCest
{
    use DiTrait;

    public function _before(CliTester $I)
    {
        $this->setNewCliFactoryDefault();
    }

    public function cliDispatcherGetSetParameters(CliTester $I)
    {
        $I->wantToTest('Cli\Dispatcher - getParameter()/setParameter()');

        $dispatcher = new Dispatcher();

        $this->container->setShared('dispatcher', $dispatcher);
        $dispatcher->setDI($this->container);

        // Test $this->dispatcher->getParams()
        $dispatcher->setNamespaceName('Phalcon\Tests\Fixtures\Tasks');
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
        $I->assertSame($expected, $actual);

        $expected = 'Is';
        $actual   = $dispatcher->getParam('b');
        $I->assertSame($expected, $actual);

        $expected = 'An';
        $actual   = $dispatcher->getParam('c');
        $I->assertSame($expected, $actual);

        $expected = 'Example';
        $actual   = $dispatcher->getParam('d');
        $I->assertSame($expected, $actual);

        $expected = 'This';
        $actual   = $dispatcher->getParameter('a');
        $I->assertSame($expected, $actual);

        $expected = 'Is';
        $actual   = $dispatcher->getParameter('b');
        $I->assertSame($expected, $actual);

        $expected = 'An';
        $actual   = $dispatcher->getParameter('c');
        $I->assertSame($expected, $actual);

        $expected = 'Example';
        $actual   = $dispatcher->getParameter('d');
        $I->assertSame($expected, $actual);

        $dispatcher->setParam('e', 'one');

        $expected = 'one';
        $actual   = $dispatcher->getParam('e');
        $I->assertSame($expected, $actual);

        $dispatcher->setParameter('f', 'two');

        $expected = 'two';
        $actual   = $dispatcher->getParameter('f');
        $I->assertSame($expected, $actual);
    }
}
