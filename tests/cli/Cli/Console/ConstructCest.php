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

namespace Phalcon\Test\Cli\Cli\Console;

use CliTester;
use Phalcon\Cli\Console as CliConsole;
use Phalcon\Cli\Dispatcher;
use Phalcon\Test\Fixtures\Traits\DiTrait;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Cli\Console :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     *
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-12-23
     */
    public function cliConsoleConstruct(CliTester $I)
    {
        $I->wantToTest("Cli\Console - __construct()");

        // Make sure the Default DI has no services.
        $this->newDi();

        $container = $this->newCliFactoryDefault();

        $console = $this->newCliConsole();

        $I->assertFalse(
            $console->getDI()->has('dispatcher')
        );

        $console = new CliConsole($container);

        $I->assertInstanceOf(
            Dispatcher::class,
            $console->getDI()->getShared('dispatcher')
        );
    }
}
