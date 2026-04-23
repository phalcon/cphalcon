<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Unit\Cli\Console;

use Phalcon\Cli\Console as CliConsole;
use Phalcon\Di\FactoryDefault\Cli as DiFactoryDefault;
use Phalcon\Events\Manager as EventsManager;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetSetEventsManagerTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-11-13
     * @since  2018-12-26
     */
    public function testCliConsoleGetSetEventsManager(): void
    {
        $console = new CliConsole(new DiFactoryDefault());

        $eventsManager = new EventsManager();

        $console->setEventsManager($eventsManager);

        $expected = $eventsManager;
        $actual   = $console->getEventsManager();
        $this->assertSame($expected, $actual);
    }
}
