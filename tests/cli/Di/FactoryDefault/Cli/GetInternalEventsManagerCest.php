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

namespace Phalcon\Tests\Cli\Di\FactoryDefault\Cli;

use CliTester;
use Phalcon\Di\FactoryDefault\Cli as Di;
use Phalcon\Events\Manager;
use Phalcon\Events\ManagerInterface;

class GetInternalEventsManagerCest
{
    /**
     * Tests Phalcon\Di\FactoryDefault\Cli :: getInternalEventsManager()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function diFactorydefaultCliGetInternalEventsManager(CliTester $I)
    {
        $I->wantToTest('Di\FactoryDefault\Cli - getInternalEventsManager()');

        $di = new Di();

        $actual = $di->getInternalEventsManager();
        $I->assertNull($actual);

        $di->setInternalEventsManager(new Manager());

        $class = ManagerInterface::class;
        $actual = $di->getInternalEventsManager();
        $I->assertInstanceOf($class, $actual);
    }
}
