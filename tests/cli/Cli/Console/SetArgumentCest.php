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
use Phalcon\Cli\Console;
use Phalcon\Cli\Router;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class SetArgumentCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Cli\Console :: setArgument()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     *
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-12-26
     */
    public function cliConsoleSetArgument(CliTester $I)
    {
        require_once dataDir('fixtures/tasks/MainTask.php');

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

        $dispatcher = $this->container->getShared('dispatcher');
        $console->setArgument([
            'php',
            '--foo=bar',
            '-bar',
            'main',
            'hello',
            'a',
            'B',
        ])->handle()
        ;

        $I->assertEquals(
            'main',
            $dispatcher->getTaskName()
        );

        $I->assertEquals(
            'hello',
            $dispatcher->getActionName()
        );

        $I->assertEquals(
            ['a', 'B'],
            $dispatcher->getParams()
        );

        $I->assertEquals(
            [
                'foo' => 'bar',
                'bar' => true,
            ],
            $dispatcher->getOptions()
        );
    }

    public function testArgumentArray(CliTester $I)
    {
        /**
         * @todo Check the loader why those are not being autoloaded
         */
        require_once dataDir('fixtures/tasks/EchoTask.php');
        require_once dataDir('fixtures/tasks/MainTask.php');

        $console = new Console();

        $console->setDI(
            $this->container
        );

        $dispatcher = $console->getDI()->getShared('dispatcher');

        $console->setArgument(
            [
                'php',
            ],
            false
        )->handle()
        ;

        $I->assertEquals(
            'main',
            $dispatcher->getTaskName()
        );

        $I->assertEquals(
            'main',
            $dispatcher->getActionName()
        );

        $I->assertEquals(
            [],
            $dispatcher->getParams()
        );

        $I->assertEquals(
            'mainAction',
            $dispatcher->getReturnedValue()
        );

        $console->setArgument(
            [
                'php',
                'echo',
            ],
            false
        )->handle()
        ;

        $I->assertEquals(
            'echo',
            $dispatcher->getTaskName()
        );

        $I->assertEquals(
            'main',
            $dispatcher->getActionName()
        );

        $I->assertEquals(
            [],
            $dispatcher->getParams()
        );

        $I->assertEquals(
            'echoMainAction',
            $dispatcher->getReturnedValue()
        );

        $console->setArgument(
            [
                'php',
                'main',
                'hello',
            ],
            false
        )->handle()
        ;

        $I->assertEquals(
            'main',
            $dispatcher->getTaskName()
        );

        $I->assertEquals(
            'hello',
            $dispatcher->getActionName()
        );

        $I->assertEquals(
            [],
            $dispatcher->getParams()
        );

        $I->assertEquals(
            'Hello !',
            $dispatcher->getReturnedValue()
        );

        $console->setArgument(
            [
                'php',
                'main',
                'hello',
                'World',
                '######',
            ],
            false
        )->handle()
        ;

        $I->assertEquals(
            'main',
            $dispatcher->getTaskName()
        );

        $I->assertEquals(
            'hello',
            $dispatcher->getActionName()
        );

        $I->assertEquals(
            ['World', '######'],
            $dispatcher->getParams()
        );

        $I->assertEquals(
            'Hello World######',
            $dispatcher->getReturnedValue()
        );
    }

    public function testArgumentNoShift(CliTester $I)
    {
        $console = new Console();

        $console->setDI(
            $this->container
        );

        $dispatcher = $console->getDI()->getShared('dispatcher');

        $console->setArgument(
            [],
            false,
            false
        )->handle()
        ;

        $I->assertEquals(
            'main',
            $dispatcher->getTaskName()
        );

        $I->assertEquals(
            'main',
            $dispatcher->getActionName()
        );

        $I->assertEquals(
            [],
            $dispatcher->getParams()
        );

        $I->assertEquals(
            'mainAction',
            $dispatcher->getReturnedValue()
        );

        $console->setArgument(
            [
                'echo',
            ],
            false,
            false
        )->handle()
        ;

        $I->assertEquals(
            'echo',
            $dispatcher->getTaskName()
        );

        $I->assertEquals(
            'main',
            $dispatcher->getActionName()
        );

        $I->assertEquals(
            [],
            $dispatcher->getParams()
        );

        $I->assertEquals(
            'echoMainAction',
            $dispatcher->getReturnedValue()
        );

        $console->setArgument([
            'main',
            'hello',
        ], false, false)->handle()
        ;

        $I->assertEquals(
            'main',
            $dispatcher->getTaskName()
        );

        $I->assertEquals(
            'hello',
            $dispatcher->getActionName()
        );

        $I->assertEquals(
            [],
            $dispatcher->getParams()
        );

        $I->assertEquals(
            'Hello !',
            $dispatcher->getReturnedValue()
        );

        $console->setArgument(
            [
                'main',
                'hello',
                'World',
                '######',
            ],
            false,
            false
        )->handle()
        ;

        $I->assertEquals(
            'main',
            $dispatcher->getTaskName()
        );

        $I->assertEquals(
            'hello',
            $dispatcher->getActionName()
        );

        $I->assertEquals(
            ['World', '######'],
            $dispatcher->getParams()
        );

        $I->assertEquals(
            'Hello World######',
            $dispatcher->getReturnedValue()
        );
    }

    public function testArgumentRouter(CliTester $I)
    {
        $this->container->setShared(
            'router',
            function () {
                $router = new Router(true);

                return $router;
            }
        );

        $console = new Console();

        $console->setDI($this->container);

        $dispatcher = $console->getDI()->getShared('dispatcher');


        $console->setArgument(
            [
                'php',
            ]
        )->handle()
        ;

        $I->assertEquals(
            'main',
            $dispatcher->getTaskName()
        );

        $I->assertEquals(
            'main',
            $dispatcher->getActionName()
        );

        $I->assertEquals(
            [],
            $dispatcher->getParams()
        );

        $I->assertEquals(
            'mainAction',
            $dispatcher->getReturnedValue()
        );


        $console->setArgument(
            [
                'php',
                'echo',
            ]
        )->handle()
        ;

        $I->assertEquals(
            'echo',
            $dispatcher->getTaskName()
        );

        $I->assertEquals(
            'main',
            $dispatcher->getActionName()
        );

        $I->assertEquals(
            [],
            $dispatcher->getParams()
        );

        $I->assertEquals(
            'echoMainAction',
            $dispatcher->getReturnedValue()
        );


        $console->setArgument(
            [
                'php',
                'main',
                'hello',
            ]
        )->handle()
        ;

        $I->assertEquals(
            'main',
            $dispatcher->getTaskName()
        );

        $I->assertEquals(
            'hello',
            $dispatcher->getActionName()
        );

        $I->assertEquals(
            [],
            $dispatcher->getParams()
        );

        $I->assertEquals(
            'Hello !',
            $dispatcher->getReturnedValue()
        );


        $console->setArgument(
            [
                'php',
                'main',
                'hello',
                'World',
                '######',
            ]
        )->handle()
        ;

        $I->assertEquals(
            'main',
            $dispatcher->getTaskName()
        );

        $I->assertEquals(
            'hello',
            $dispatcher->getActionName()
        );

        $I->assertEquals(
            ['World', '######'],
            $dispatcher->getParams()
        );

        $I->assertEquals(
            'Hello World######',
            $dispatcher->getReturnedValue()
        );
    }
}
