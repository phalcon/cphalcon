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

namespace Phalcon\Tests\Cli\Cli\Console;

use CliTester;
use Phalcon\Cli\Console as CliConsole;
use Phalcon\Di\FactoryDefault\Cli as DiFactoryDefault;
use ReflectionClass;

/**
 * Class ConstructCest
 */
class ConstructCest
{
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

        $console   = new CliConsole();
        $reflect   = new ReflectionClass($console);
        $container = $reflect->getProperty('container');
        $container->setAccessible(true);
        $I->assertNull($container->getValue($console));

        $di      = new DiFactoryDefault();
        $console = new CliConsole($di);

        $I->assertEquals($di, $container->getValue($console));
    }
}
