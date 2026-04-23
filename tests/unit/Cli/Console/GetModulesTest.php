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
use Phalcon\Di\FactoryDefault\Cli as DiFactoryDefault;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Modules\Backend\Module as BackendModule;
use Phalcon\Tests\Support\Modules\Frontend\Module as FrontendModule;
use Phalcon\Tests\Support\Traits\DiTrait;

final class GetModulesTest extends AbstractUnitTestCase
{
    use DiTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-11-13
     * @since  2018-12-26
     */
    public function testCliConsoleGetModules(): void
    {
        $console = new CliConsole(new DiFactoryDefault());

        $definition = [
            'frontend' => [
                'className' => FrontendModule::class,
                'path'      => supportDir('Modules/Frontend/Module.php'),
            ],
            'backend'  => [
                'className' => BackendModule::class,
                'path'      => supportDir('Modules/Backend/Module.php'),
            ],
        ];

        $console->registerModules($definition);

        $expected = $definition;
        $actual   = $console->getModules();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-11-13
     * @since  2018-12-26
     */
    public function testCliConsoleGetModulesEmpty(): void
    {
        $console = new CliConsole(new DiFactoryDefault());

        $expected = [];
        $actual   = $console->getModules();
        $this->assertSame($expected, $actual);
    }
}
