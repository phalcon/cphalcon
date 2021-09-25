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

class GetParamCest
{
    use DiTrait;

    public function _before(CliTester $I)
    {
        $this->setNewCliFactoryDefault();
    }

    public function testCliParameters(CliTester $I)
    {
        $I->wantToTest('Cli\Dispatcher - getParam()');

        $dispatcher = new Dispatcher();

        $this->container->setShared('dispatcher', $dispatcher);

        $dispatcher->setDI(
            $this->container
        );

        // Test $this->dispatcher->getParam()
        $dispatcher->setNamespaceName('Phalcon\Tests\Fixtures\Tasks');
        $dispatcher->setTaskName('params');
        $dispatcher->setActionName('param');

        $dispatcher->setParams(
            ['This', 'Is', 'An', 'Example']
        );

        $dispatcher->dispatch();

        $I->assertEquals(
            '$param[0] is the same as $this->dispatcher->getParam(0)',
            $dispatcher->getReturnedValue()
        );
    }
}
