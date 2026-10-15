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

use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Mvc\Fake\RouterTrait;
use PHPUnit\Framework\Attributes\BackupGlobals;
use PHPUnit\Framework\Attributes\DataProvider;

#[BackupGlobals(true)]
final class StaticRouteFastPathTest extends AbstractUnitTestCase
{
    use RouterTrait;

    /**
     * @return array<string, array{0: string}>
     */
    public static function getAddMethods(): array
    {
        return [
            'add'    => ['add'],
            'addGet' => ['addGet'],
        ];
    }

    /**
     * A no-method ("*") regex attached after a method-specific static must
     * be detected as a shadow during rebuild - otherwise the static fast
     * path would incorrectly win for the GET request.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testCrossBucketShadowingByStarRegex(): void
    {
        $router = $this->getRouter(false);
        $router->addGet('/about', ['controller' => 'about']);
        $router->add('/{slug:[a-z]+}', ['controller' => 'catch_all']);

        $_SERVER['REQUEST_METHOD'] = 'GET';
        $router->handle('/about');

        $this->assertSame('catch_all', $router->getControllerName());
    }

    /**
     * Static attached first then a regex that would shadow it. Reverse
     * iteration semantics require the regex (last attached) to win.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testLaterAttachedRegexShadowsEarlierStatic(): void
    {
        $router = $this->getRouter(false);
        $router->add('/about', ['controller' => 'about']);
        $router->add('/{slug:[a-z]+}', ['controller' => 'catch_all']);

        $router->handle('/about');

        $this->assertSame('catch_all', $router->getControllerName());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testLiteralUriMatchesStaticRouteDirectly(): void
    {
        $router = $this->getRouter(false);
        $router->add('/about', ['controller' => 'about']);

        $router->handle('/about');

        $this->assertTrue($router->wasMatched());
        $this->assertSame('about', $router->getControllerName());
    }

    /**
     * A beforeMatch veto on the static fast path and a beforeMatch veto on
     * the combined-regex fast path in the same request. Each callback runs
     * one time.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-01
     */
    #[DataProvider('getAddMethods')]
    public function testStaticAndRegexVetoesRunEachCallbackOnce(string $addMethod): void
    {
        $calls  = ['regex' => 0, 'static' => 0];
        $router = $this->getRouter(false);
        $router->$addMethod('/items/{id:[0-9]+}', ['controller' => 'regex'])
            ->beforeMatch(
                static function () use (&$calls): bool {
                    $calls['regex']++;

                    return false;
                }
            );
        $router->$addMethod('/items/5', ['controller' => 'static'])
            ->beforeMatch(
                static function () use (&$calls): bool {
                    $calls['static']++;

                    return false;
                }
            );

        $_SERVER['REQUEST_METHOD'] = 'GET';
        $router->handle('/items/5');

        $this->assertFalse($router->wasMatched());
        $this->assertSame(['regex' => 1, 'static' => 1], $calls);
    }

    /**
     * Regex attached first, static attached second. Reverse iteration puts
     * the static first; it should win.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testStaticAttachedAfterRegexMatchesDirectly(): void
    {
        $router = $this->getRouter(false);
        $router->add('/{slug:[a-z]+}', ['controller' => 'catch_all']);
        $router->add('/about', ['controller' => 'about']);

        $router->handle('/about');

        $this->assertSame('about', $router->getControllerName());
    }

    /**
     * Static routes registered under different HTTP method buckets must
     * still respect the method constraint.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testStaticFastPathHonorsMethodConstraint(): void
    {
        $router = $this->getRouter(false);
        $router->addGet('/users', ['controller' => 'users', 'action' => 'index']);
        $router->addPost('/users', ['controller' => 'users', 'action' => 'create']);

        $_SERVER['REQUEST_METHOD'] = 'POST';
        $router->handle('/users');

        $this->assertSame('users', $router->getControllerName());
        $this->assertSame('create', $router->getActionName());
    }

    /**
     * A beforeMatch callback that returns false must veto the static fast
     * path the same way it vetoes the regular loop.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testStaticFastPathRespectsBeforeMatchVeto(): void
    {
        $router = $this->getRouter(false);
        $router->add('/admin', ['controller' => 'admin'])
            ->beforeMatch(static fn (): bool => false);

        $router->handle('/admin');

        $this->assertFalse($router->wasMatched());
    }

    /**
     * Hostname constraints must be honored even when the static fast path
     * fires.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testStaticFastPathRespectsHostName(): void
    {
        $router = $this->getRouter(false);
        $router->add('/api', ['controller' => 'api'])
            ->setHostname('api.example.com');

        $_SERVER['HTTP_HOST'] = 'www.example.com';
        $router->handle('/api');

        $this->assertFalse($router->wasMatched());
    }

    /**
     * A beforeMatch veto on the static fast path falls back to an
     * earlier-attached route that matches. The vetoing callback runs one
     * time.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-01
     */
    #[DataProvider('getAddMethods')]
    public function testStaticFastPathVetoFallsBackToEarlierRoute(string $addMethod): void
    {
        $calls  = 0;
        $router = $this->getRouter(false);
        $router->$addMethod('/{page:[a-z]+}', ['controller' => 'page']);
        $router->$addMethod('/about', ['controller' => 'about'])
            ->beforeMatch(
                static function () use (&$calls): bool {
                    $calls++;

                    return false;
                }
            );

        $_SERVER['REQUEST_METHOD'] = 'GET';
        $router->handle('/about');

        $this->assertTrue($router->wasMatched());
        $this->assertSame('page', $router->getControllerName());
        $this->assertSame(1, $calls);
    }

    /**
     * Two static routes for the same URI that both veto. Each callback runs
     * one time.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-01
     */
    #[DataProvider('getAddMethods')]
    public function testStaticFastPathVetoOfTwoRoutesRunsEachCallbackOnce(string $addMethod): void
    {
        $calls  = ['first' => 0, 'second' => 0];
        $router = $this->getRouter(false);
        $router->$addMethod('/about', ['controller' => 'first'])
            ->beforeMatch(
                static function () use (&$calls): bool {
                    $calls['first']++;

                    return false;
                }
            );
        $router->$addMethod('/about', ['controller' => 'second'])
            ->beforeMatch(
                static function () use (&$calls): bool {
                    $calls['second']++;

                    return false;
                }
            );

        $_SERVER['REQUEST_METHOD'] = 'GET';
        $router->handle('/about');

        $this->assertFalse($router->wasMatched());
        $this->assertSame(['first' => 1, 'second' => 1], $calls);
    }

    /**
     * A beforeMatch veto on the static fast path with no other match runs
     * the callback one time.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-01
     */
    #[DataProvider('getAddMethods')]
    public function testStaticFastPathVetoRunsCallbackOnce(string $addMethod): void
    {
        $calls  = 0;
        $router = $this->getRouter(false);
        $router->$addMethod('/about', ['controller' => 'about'])
            ->beforeMatch(
                static function () use (&$calls): bool {
                    $calls++;

                    return false;
                }
            );

        $_SERVER['REQUEST_METHOD'] = 'GET';
        $router->handle('/about');

        $this->assertFalse($router->wasMatched());
        $this->assertSame(1, $calls);
    }
}
