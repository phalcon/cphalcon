<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Cli\Cli\Task;

use CliTester;

/**
 * Class GetEventsManagerCest
 */
class GetEventsManagerCest
{
    /**
     * Tests Phalcon\Cli\Task :: getEventsManager()
     *
     * @param CliTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cliTaskGetEventsManager(CliTester $I)
    {
        $I->wantToTest('Cli\Task - getEventsManager()');
        $I->skipTest('Need implementation');
    }
}
