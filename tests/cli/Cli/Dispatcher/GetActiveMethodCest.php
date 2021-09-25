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

/**
 * Class GetActiveMethodCest
 */
class GetActiveMethodCest
{
    /**
     * Tests Phalcon\Cli\Dispatcher :: getActiveMethod()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliDispatcherGetActiveMethod(CliTester $I)
    {
        $I->wantToTest('Cli\Dispatcher - getActiveMethod()');
        $dispatcher = new Dispatcher();

        $dispatcher->setActionName("phalcon");

        $I->assertEquals(
            "phalconAction",
            $dispatcher->getActiveMethod()
        );
    }
}
