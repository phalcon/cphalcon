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

namespace Phalcon\Tests\Unit\Cli\Console;

use Phalcon\Cli\Console as CliConsole;
use Phalcon\Cli\Console\Exception;
use Phalcon\Di\FactoryDefault\Cli as DiFactoryDefault;
use Phalcon\Tests\Support\Modules\Backend\Module;
use Phalcon\Tests\Support\Modules\Frontend\Module as FrontendModule;
use Phalcon\Tests\AbstractUnitTestCase;

final class RegisterModulesTest extends AbstractUnitTestCase
{
    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-15
     */
    public function testRegisterModulesBadPathThrowsAnException(): void
    {
        $console = new CliConsole(new DiFactoryDefault());

        $console->registerModules(
            [
                'frontend' => [
                    'path'      => supportDir('not-a-real-file.php'),
                    'className' => Module::class,
                ],
            ]
        );

        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "Module definition path '"
            . supportDir('not-a-real-file.php')
            . "' does not exist"
        );

        $console->handle(
            [
                'module' => 'frontend',
                'task'   => 'echo',
            ]
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-11-13
     * @since  2018-26-12
     */
    public function testCliConsoleRegisterModules(): void
    {
        $console = new CliConsole(new DiFactoryDefault());

        $console->registerModules(
            [
                'frontend' => [
                    'className' => FrontendModule::class,
                    'path'      => supportDir('Modules/Frontend/Module.php'),
                ],
            ]
        );

        $this->assertCount(
            1,
            $console->getModules()
        );

        $this->assertArrayHasKey(
            'frontend',
            $console->getModules()
        );

        $console->registerModules(
            [
                'backend' => [
                    'className' => FrontendModule::class,
                    'path'      => supportDir('Modules/Backend/Module.php'),
                ],
            ]
        );

        $expected = 1;
        $actual   = $console->getModules();
        $this->assertCount($expected, $actual);

        $expected = 'backend';
        $actual   = $console->getModules();
        $this->assertArrayHasKey($expected, $actual);

        $console->registerModules(
            [
                'frontend' => [
                    'className' => FrontendModule::class,
                    'path'      => supportDir('Modules/Frontend/Module.php'),
                ],
            ],
            true
        );

        $expected = 2;
        $actual   = $console->getModules();
        $this->assertCount($expected, $actual);

        $expected = 'frontend';
        $actual   = $console->getModules();
        $this->assertArrayHasKey($expected, $actual);

        $expected = 'backend';
        $actual   = $console->getModules();
        $this->assertArrayHasKey($expected, $actual);
    }
}
