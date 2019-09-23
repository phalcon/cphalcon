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
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Modules\Frontend\Module;

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

        $console = $this->newCliConsole();

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

        $console = $this->newCliConsole();

        $definition = [
            'frontend' => [
                'className' => Module::class,
                'path'      => dataDir('fixtures/modules/frontend/Module.php'),
            ],
            'backend'  => [
                'className' => \Phalcon\Test\Modules\Backend\Module::class,
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
