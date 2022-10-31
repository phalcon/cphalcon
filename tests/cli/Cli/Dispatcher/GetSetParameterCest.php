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

class GetSetParameterCest
{
    use DiTrait;

    public function _before(CliTester $I)
    {
        $this->setNewCliFactoryDefault();
    }

    public function cliDispatcherGetSetParameter(CliTester $I)
    {
        $I->wantToTest('Cli\Dispatcher - getParameter()/setParameter()');

        $dispatcher = new Dispatcher();

        $this->container->setShared('dispatcher', $dispatcher);
        $dispatcher->setDI($this->container);

        // Test $this->dispatcher->getParam()
        $dispatcher->setNamespaceName('Phalcon\Tests\Fixtures\Tasks');
        $dispatcher->setTaskName('params');
        $dispatcher->setActionName('param');

        $dispatcher->setParams(
            ['This', 'Is', 'An', 'Example']
        );

        $dispatcher->dispatch();

        $expected = '$param[0] is the same as $this->dispatcher->getParam(0)';
        $actual   = $dispatcher->getReturnedValue();
        $I->assertSame($expected, $actual);
    }
}
