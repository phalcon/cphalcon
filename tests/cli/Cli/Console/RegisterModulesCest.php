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
use Phalcon\Cli\Console\Exception;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Modules\Frontend\Module;

class RegisterModulesCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Cli\Console :: registerModules()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     *
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-26-12
     */
    public function cliConsoleRegisterModules(CliTester $I)
    {
        $I->wantToTest("Cli\Console - registerModules()");

        $console = $this->newCliConsole();

        $console->registerModules(
            [
                'frontend' => [
                    'className' => Module::class,
                    'path'      => dataDir('fixtures/modules/frontend/Module.php'),
                ],
            ]
        );

        $I->assertCount(
            1,
            $console->getModules()
        );

        $I->assertArrayHasKey(
            'frontend',
            $console->getModules()
        );

        $console->registerModules(
            [
                'backend' => [
                    'className' => \Phalcon\Test\Modules\Backend\Module::class,
                    'path'      => dataDir('fixtures/modules/backend/Module.php'),
                ],
            ]
        );

        $I->assertCount(
            1,
            $console->getModules()
        );

        $I->assertArrayHasKey(
            'backend',
            $console->getModules()
        );

        $console->registerModules(
            [
                'frontend' => [
                    'className' => Module::class,
                    'path'      => dataDir('fixtures/modules/frontend/Module.php'),
                ],
            ],
            $merge = true
        );

        $I->assertCount(
            2,
            $console->getModules()
        );

        $I->assertArrayHasKey(
            'frontend',
            $console->getModules()
        );

        $I->assertArrayHasKey(
            'backend',
            $console->getModules()
        );
    }

    /**
     * Tests Phalcon\Cli\Console :: registerModules() - bad path throws exception
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-15
     */
    public function cliConsoleRegisterModulesBadPathThrowsAnException(CliTester $I)
    {
        $I->wantToTest("Cli\Console - registerModules() - bad path throws exception");

        $container = $this->newCliFactoryDefault();

        $console = $this->newCliConsole();

        $console->setDI($container);

        $console->registerModules(
            [
                'frontend' => [
                    'path'      => dataDir('not-a-real-file.php'),
                    'className' => Module::class,
                ],
            ]
        );

        $I->expectThrowable(
            new Exception(
                "Module definition path '" . dataDir('not-a-real-file.php') . "' doesn't exist"
            ),
            function () use ($console) {
                $console->handle(
                    [
                        'module' => 'frontend',
                        'task'   => 'echo',
                    ]
                );
            }
        );
    }
}
