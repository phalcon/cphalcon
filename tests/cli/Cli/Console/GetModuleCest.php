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

namespace Phalcon\Test\Cli\Cli\Console;

use CliTester;
use Phalcon\Application\Exception;
use Phalcon\Cli\Console as CliConsole;
use Phalcon\Di\FactoryDefault\Cli as DiFactoryDefault;
use Phalcon\Test\Modules\Backend\Module as BackendModule;
use Phalcon\Test\Modules\Frontend\Module as FrontendModule;

class GetModuleCest
{
    /**
     * Tests Phalcon\Cli\Console :: getModule()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     *
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-12-26
     */
    public function cliConsoleGetModule(CliTester $I)
    {
        $I->wantToTest("Cli\Console - getModule()");

        $console = new CliConsole(new DiFactoryDefault());

        $definition = [
            'frontend' => [
                'className' => FrontendModule::class,
                'path'      => dataDir('fixtures/modules/frontend/Module.php'),
            ],
            'backend'  => [
                'className' => BackendModule::class,
                'path'      => dataDir('fixtures/modules/backend/Module.php'),
            ],
        ];

        $console->registerModules($definition);

        $I->assertEquals(
            $definition['frontend'],
            $console->getModule('frontend')
        );

        $I->assertEquals(
            $definition['backend'],
            $console->getModule('backend')
        );
    }

    /**
     * Tests Phalcon\Cli\Console :: getModule() - non-existent
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     *
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-12-26
     */
    public function cliConsoleGetModuleNonExistent(CliTester $I)
    {
        $I->wantToTest("Cli\Console - getModule() - non-existent");

        $console = new CliConsole(new DiFactoryDefault());

        $I->expectThrowable(
            new Exception(
                "Module 'foo' isn't registered in the application container"
            ),
            function () use ($console) {
                $console->getModule('foo');
            }
        );
    }
}
