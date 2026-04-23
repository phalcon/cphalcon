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

namespace Phalcon\Tests\Unit\Cli\Router;

use Phalcon\Cli\Router;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetMatchesTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testCliRouterGetMatches(): void
    {
        $router = new Router();

        $router->add(
            'route1',
            [
                'module' => 'devtools',
                'task'   => 'main',
                'action' => 'hello',
            ]
        );

        $router->add(
            'route2',
            [
                'module' => 'devtools2',
                'task'   => 'main2',
                'action' => 'hello2',
            ]
        );
        $router->handle('route');

        $expected = ["route", "route"];
        $actual   = $router->getMatches();
        $this->assertSame($expected, $actual);
    }
}
