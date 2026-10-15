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
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

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

    /**
     * getMatches() has only the matches of the last request: it is empty
     * after a static-route match and after no match.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-02
     */
    public function testCliRouterGetMatchesIsResetForEachRequest(): void
    {
        $router = new Router(false);
        $router->add('users {id:[0-9]+}', ['task' => 'users']);
        $router->add('about', ['task' => 'about']);

        $router->handle('users 42');
        $this->assertSame([0 => 'users 42', 1 => '42'], $router->getMatches());

        $router->handle('about');
        $this->assertSame('about', $router->getTaskName());
        $this->assertSame([], $router->getMatches());

        $router->handle('none');
        $this->assertFalse($router->wasMatched());
        $this->assertSame([], $router->getMatches());
    }
}
