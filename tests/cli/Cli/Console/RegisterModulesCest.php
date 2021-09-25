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
use Phalcon\Cli\Console\Exception;
use Phalcon\Di\FactoryDefault\Cli as DiFactoryDefault;
use Phalcon\Tests\Modules\Frontend\Module as FrontendModule;

class RegisterModulesCest
{
    /**
     * Tests Phalcon\Cli\Console :: registerModules()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     *
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-26-12
     */
    public function registerModules(CliTester $I)
    {
        $I->wantToTest("Cli\Console - registerModules()");

        $console = new CliConsole(new DiFactoryDefault());

        $console->registerModules(
            [
                'frontend' => [
                    'className' => FrontendModule::class,
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
                    'className' => FrontendModule::class,
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
                    'className' => FrontendModule::class,
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
     * Tests Phalcon\Cli\Console :: registerModules() - bad path throws
     * exception
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-15
     */
    public function registerModulesBadPathThrowsAnException(CliTester $I)
    {
        $I->wantToTest("Cli\Console - registerModules() - bad path throws exception");

        $console = new CliConsole(new DiFactoryDefault());

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
