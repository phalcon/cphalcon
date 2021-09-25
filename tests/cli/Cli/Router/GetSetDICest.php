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

namespace Phalcon\Tests\Cli\Cli\Router;

use CliTester;
use Phalcon\Cli\Router;
use Phalcon\Di;

class GetSetDICest
{
    /**
     * Tests Phalcon\Cli\Router :: getDI()/setDI()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-29
     */
    public function cliRouterGetSetDI(CliTester $I)
    {
        $I->wantToTest('Cli\Router - getDI()/setDI()');

        $router = new Router();

        $container = new Di();

        $router->setDI($container);

        $actual = $router->getDI();

        $I->assertInstanceOf(
            Di::class,
            $actual
        );

        $I->assertSame($container, $actual);
    }
}
