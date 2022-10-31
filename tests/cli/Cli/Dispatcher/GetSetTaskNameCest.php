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

class GetSetTaskNameCest
{
    /**
     * Tests Phalcon\Cli\Dispatcher :: getTaskName()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliDispatcherGetTaskName(CliTester $I)
    {
        $I->wantToTest('Cli\Dispatcher - getTaskName()');
        $dispatcher = new Dispatcher();

        $expected = '';
        $actual   = $dispatcher->getTaskName();
        $I->assertSame($expected, $actual);

        $value = "Phalcon";
        $dispatcher->setTaskName($value);

        $expected = $value;
        $actual   = $dispatcher->getTaskName();
        $I->assertSame($expected, $actual);
    }
}
