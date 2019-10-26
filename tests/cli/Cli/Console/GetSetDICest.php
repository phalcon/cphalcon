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
use Phalcon\Cli\Dispatcher;
use Phalcon\Di\FactoryDefault\Cli as DiFactoryDefault;
use Phalcon\Cli\Console as CliConsole;

class GetSetDICest
{
    /**
     * Tests Phalcon\Cli\Console :: getDI()/setDI()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliConsoleGetSetDI(CliTester $I)
    {
        $I->wantToTest('Cli\Console - getDI() / setDI()');

        $console = new CliConsole();

        $container = new DiFactoryDefault();
        $console->setDI($container);

        $I->assertInstanceOf(
            Dispatcher::class,
            $console->getDI()->getShared('dispatcher')
        );
    }
}
