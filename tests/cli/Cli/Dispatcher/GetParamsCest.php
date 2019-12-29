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

namespace Phalcon\Test\Cli\Cli\Dispatcher;

use CliTester;
use Phalcon\Cli\Dispatcher;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class GetParamsCest
{
    use DiTrait;

    public function _before(CliTester $I)
    {
        $this->setNewCliFactoryDefault();
    }

    public function testCliParameters(CliTester $I)
    {
        $dispatcher = new Dispatcher();

        $this->container->setShared('dispatcher', $dispatcher);

        $dispatcher->setDI(
            $this->container
        );

        // Test $this->dispatcher->getParams()
        $dispatcher->setNamespaceName('Phalcon\Test\Fixtures\Tasks');
        $dispatcher->setTaskName('params');
        $dispatcher->setActionName('params');

        $dispatcher->setParams(
            ['This', 'Is', 'An', 'Example']
        );

        $dispatcher->dispatch();

        $I->assertEquals(
            'Action params are the same as $this->dispatcher->getParams()',
            $dispatcher->getReturnedValue()
        );
    }
}
