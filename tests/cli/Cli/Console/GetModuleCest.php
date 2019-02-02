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
use Phalcon\Application\Exception;
use Phalcon\Test\Fixtures\Traits\DiTrait;

/**
 * Class GetModuleCest
 */
class GetModuleCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Cli\Console :: getModule()
     *
     * @param CliTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     *
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since 2018-12-26
     */
    public function cliConsoleGetModule(CliTester $I)
    {
        $I->wantToTest("Cli\Console - getModule()");
        $console = $this->newCliConsole();

        $console->registerModules(
            [
                "frontend" => [
                    "className" => "Phalcon\\Test\\Modules\\Frontend\\Module",
                    "path" => __DIR__ . "/../../../_data/modules/frontend/Module.php",
                ],
                "backend" => [
                    "className" => "Phalcon\\Test\\Modules\\Backend\\Module",
                    "path" => __DIR__ . "/../../../_data/modules/backend/Module.php",
                ]
            ]
        );
        $expected = [
            "className" => "Phalcon\\Test\\Modules\\Frontend\\Module",
            "path" => __DIR__ . "/../../../_data/modules/frontend/Module.php",
        ];
        $actual = $console->getModule("frontend");
        $I->assertEquals($expected, $actual);

        $I->expectThrowable(
            new Exception("Module 'foo' isn't registered in the application container"),
            function () use ($console) {
                $console->getModule("foo");
            }
        );
    }
}
