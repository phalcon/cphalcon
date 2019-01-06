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
use Phalcon\Test\Fixtures\Traits\DiTrait;

/**
 * Class RegisterModulesCest
 */
class RegisterModulesCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Cli\Console :: registerModules()
     *
     * @param CliTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     *
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since 2018-26-12
     */
    public function cliConsoleRegisterModules(CliTester $I)
    {
        $I->wantToTest("Cli\Console - registerModules()");

        $console = $this->newCliConsole();
        $console->registerModules(
            [
                "frontend" => [
                    "className" => "Phalcon\\Test\\Modules\\Frontend\\Module",
                    "path" => __DIR__ . "/../../../_data/modules/frontend/Module.php",
                ]
            ]
        );
        $I->assertCount(1, $console->getModules());
        $I->assertArrayHasKey("frontend", $console->getModules());

        $console->registerModules(
            [
                "backend" => [
                    "className" => "Phalcon\\Test\\Modules\\Backend\\Module",
                    "path" => __DIR__ . "/../../../_data/modules/backend/Module.php",
                ]
            ]
        );
        $I->assertCount(1, $console->getModules());
        $I->assertArrayHasKey("backend", $console->getModules());

        $console->registerModules(
            [
                "frontend" => [
                    "className" => "Phalcon\\Test\\Modules\\Frontend\\Module",
                    "path" => __DIR__ . "/../../../_data/modules/frontend/Module.php",
                ]
            ],
            $merge = true
        );
        $I->assertCount(2, $console->getModules());
        $I->assertArrayHasKey("frontend", $console->getModules());
        $I->assertArrayHasKey("backend", $console->getModules());
    }
}
