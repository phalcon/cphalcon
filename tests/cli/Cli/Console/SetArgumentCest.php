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

namespace Phalcon\Test\Cli\Cli\Console;

use CliTester;
use Phalcon\Cli\Router;
use Phalcon\Test\Fixtures\Traits\DiTrait;

/**
 * Class SetArgumentCest
 */
class SetArgumentCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Cli\Console :: setArgument()
     *
     * @param CliTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     *
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since 2018-12-26
     */
    public function cliConsoleSetArgument(CliTester $I)
    {
        require_once dataFolder('fixtures/tasks/MainTask.php');
        $I->wantToTest("Cli\Console - setArgument()");
        $this->setNewCliFactoryDefault();

        $this->container->setShared(
            'router',
            function () {
                $router = new Router(true);

                return $router;
            }
        );

        $console = $this->newCliConsole();
        $console->setDI($this->container);

        $dispatcher = $this->container->getShared("dispatcher");
        $console->setArgument([
            "php",
            "--foo=bar",
            "-bar",
            "main",
            "hello",
            "a",
            "B"
        ])->handle();
        $I->assertEquals("main", $dispatcher->getTaskName());
        $I->assertEquals("hello", $dispatcher->getActionName());
        $I->assertEquals(["a", "B"], $dispatcher->getParams());
        $I->assertEquals(["foo" => "bar", "bar" => true], $dispatcher->getOptions());
    }
}
