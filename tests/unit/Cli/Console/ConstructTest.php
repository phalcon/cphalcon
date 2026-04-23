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
use ReflectionClass;

final class ConstructTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @author Nathan Edwards <https://github.com/npfedwards>
     * @since  2018-11-13
     * @since  2018-12-23
     */
    public function testCliConsoleConstruct(): void
    {
        $console   = new CliConsole();
        $reflect   = new ReflectionClass($console);
        $container = $reflect->getProperty('container');
        $container->setAccessible(true);
        $this->assertNull($container->getValue($console));

        $di      = new DiFactoryDefault();
        $console = new CliConsole($di);

        $this->assertSame($di, $container->getValue($console));
    }
}
