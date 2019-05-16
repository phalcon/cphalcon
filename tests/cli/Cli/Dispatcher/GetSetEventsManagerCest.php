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

namespace Phalcon\Test\Cli\Cli\Dispatcher;

use CliTester;
use Phalcon\Cli\Console;
use Phalcon\Events\Manager;

class GetSetEventsManagerCest
{
    /**
     * Tests Phalcon\Cli\Dispatcher :: getEventsManager()/setEventsManager()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cliDispatcherGetSetEventsManager(CliTester $I)
    {
        $I->wantToTest('Cli\Dispatcher - getEventsManager()/setEventsManager()');

        $console = new Console();
        $manager = new Manager();

        $console->setEventsManager($manager);

        $actual = $console->getEventsManager();
        $I->assertEquals($manager, $actual);
    }
}
