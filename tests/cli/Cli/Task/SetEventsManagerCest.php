<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Cli\Cli\Task;

use CliTester;

class SetEventsManagerCest
{
    /**
     * Tests Phalcon\Cli\Task :: setEventsManager()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliTaskSetEventsManager(CliTester $I)
    {
        $I->wantToTest('Cli\Task - setEventsManager()');

        $I->skipTest('Need implementation');
    }
}
