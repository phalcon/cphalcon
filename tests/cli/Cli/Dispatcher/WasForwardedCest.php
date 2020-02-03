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
use Phalcon\Di\FactoryDefault\Cli as DiFactoryDefault;

class WasForwardedCest
{
    /**
     * Tests Phalcon\Cli\Dispatcher :: wasForwarded()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliDispatcherWasForwarded(CliTester $I)
    {
        $I->wantToTest('Cli\Dispatcher - wasForwarded()');

        $dispatcher = new Dispatcher();
        $dispatcher->setDefaultNamespace('Phalcon\Test\Fixtures\Tasks');
        $dispatcher->setDI(
            new DiFactoryDefault()
        );
        $I->assertFalse($dispatcher->wasForwarded());
        $dispatcher->forward(
            [
                'task'   => 'echo',
                'action' => 'main',
            ]
        );
        $dispatcher->dispatch();
        $I->assertTrue($dispatcher->wasForwarded());
    }
}
