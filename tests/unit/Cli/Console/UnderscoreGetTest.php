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
use Phalcon\Cli\Dispatcher;
use Phalcon\Di\FactoryDefault\Cli as DiFactoryDefault;
use Phalcon\Tests\AbstractUnitTestCase;

final class UnderscoreGetTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-11-13
     * @since  2018-12-28
     */
    public function testCliConsoleUnderscoreGet(): void
    {
        $container = new DiFactoryDefault();
        $console   = new CliConsole($container);

        $class  = Dispatcher::class;
        $actual = $console->dispatcher;
        $this->assertInstanceOf($class, $actual);

        $actual = $console->di;
        $this->assertSame($container, $actual);
    }
}
