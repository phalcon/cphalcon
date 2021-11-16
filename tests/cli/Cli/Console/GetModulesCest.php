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
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Modules\Backend\Module as BackendModule;
use Phalcon\Tests\Modules\Frontend\Module as FrontendModule;

class GetModulesCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Cli\Console :: getModules() - empty
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     *
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-12-26
     */
    public function cliConsoleGetModulesEmpty(CliTester $I)
    {
        $I->wantToTest("Cli\Console - getModules() - empty");

        $console = new CliConsole(new DiFactoryDefault());

        $I->assertEquals(
            [],
            $console->getModules()
        );
    }

    /**
     * Tests Phalcon\Cli\Console :: getModules()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     *
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-12-26
     */
    public function cliConsoleGetModules(CliTester $I)
    {
        $I->wantToTest("Cli\Console - getModules()");

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
            $definition,
            $console->getModules()
        );
    }
}
