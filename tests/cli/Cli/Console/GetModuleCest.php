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
use Phalcon\Application\Exception;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Modules\Frontend\Module;

class GetModuleCest
{
    use DiTrait;

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

        $console = $this->newCliConsole();

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
