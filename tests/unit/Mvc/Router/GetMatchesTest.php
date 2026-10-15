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

namespace Phalcon\Tests\Unit\Mvc\Router;

use Phalcon\Events\Manager as EventsManager;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Mvc\Fake\RouterTrait;
use PHPUnit\Framework\Attributes\DataProvider;

final class GetMatchesTest extends AbstractUnitTestCase
{
    use RouterTrait;

    /**
     * @return array<string, array{0: bool}>
     */
    public static function getEventsModes(): array
    {
        return [
            'fast paths'     => [false],
            'per-route loop' => [true],
        ];
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcRouterGetMatches(): void
    {
        $route = '/users/edit/100/';

        $router = $this->getRouter();
        $router->handle($route);

        $actual = $router->wasMatched();
        $this->assertTrue($actual);

        $expected = [
            0 => '/users/edit/100/',
            1 => 'users',
            2 => 'edit',
            3 => '/100/',
        ];
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
    #[DataProvider('getEventsModes')]
    public function testMvcRouterGetMatchesIsResetForEachRequest(bool $withEvents): void
    {
        $router = $this->getRouter(false);
        if ($withEvents) {
            $router->setEventsManager(new EventsManager());
        }

        $router->add('/users/{id:[0-9]+}', ['controller' => 'users']);
        $router->add('/about', ['controller' => 'about']);

        $router->handle('/users/42');
        $this->assertSame([0 => '/users/42', 1 => '42'], $router->getMatches());

        $router->handle('/about');
        $this->assertSame('about', $router->getControllerName());
        $this->assertSame([], $router->getMatches());

        $router->handle('/none');
        $this->assertFalse($router->wasMatched());
        $this->assertSame([], $router->getMatches());
    }
}
