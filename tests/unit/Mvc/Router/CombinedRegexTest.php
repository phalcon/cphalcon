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
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Mvc\Fake\RouterTrait;

final class CombinedRegexTest extends AbstractUnitTestCase
{
    use RouterTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testMatchesFirstRoute(): void
    {
        $router = $this->getRouter(false);
        $router->add('/products/{slug:[a-z-]+}', ['controller' => 'products']);
        $router->add('/users/{id:[0-9]+}', ['controller' => 'users']);

        $router->handle('/users/42');

        $this->assertTrue($router->wasMatched());
        $this->assertSame('users', $router->getControllerName());
    }

    /**
     * Two regex routes that both match the same URI; the later-attached
     * one must win (reverse-iteration semantics preserved by the combined
     * regex via alternative-order reversal).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testLaterAttachedDynamicRouteWins(): void
    {
        $router = $this->getRouter(false);
        $router->add('/{anything:[a-z]+}', ['controller' => 'first']);
        $router->add('/{anythingElse:[a-z]+}', ['controller' => 'second']);

        $router->handle('/about');

        $this->assertSame('second', $router->getControllerName());
    }

    /**
     * Named-group captures must reach the matched route's paths map even
     * after group renumbering through (?|...) branch reset.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testNamedCapturesReachPaths(): void
    {
        $router = $this->getRouter(false);
        $router->add('/products/{slug:[a-z-]+}', ['controller' => 'products', 'slug' => 1]);

        $router->handle('/products/widget');

        $params = $router->getParams();
        $this->assertSame('widget', $params['slug']);
    }

    /**
     * Converters must run on a combined-regex hit.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testConverterRunsAfterCombinedRegexMatch(): void
    {
        $router = $this->getRouter(false);
        $router->add('/users/{id:[0-9]+}', ['controller' => 'users', 'id' => 1])
            ->convert('id', static fn(string $v): int => (int) $v);

        $router->handle('/users/42');

        $params = $router->getParams();
        $this->assertSame(42, $params['id']);
    }

    /**
     * beforeMatch returning false on a combined-regex hit vetoes the
     * match.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testBeforeMatchVetoOnCombinedRegexHit(): void
    {
        $router = $this->getRouter(false);
        $router->add('/users/{id:[0-9]+}', ['controller' => 'users'])
            ->beforeMatch(static fn(): bool => false);

        $router->handle('/users/42');

        $this->assertFalse($router->wasMatched());
    }

    /**
     * The presence of a hostname-constrained route in the bucket disables
     * combined regex for that bucket - reverse-attach order with the
     * hostname route is preserved by falling back to the per-route loop.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testHostnameRouteDisablesCombinedRegex(): void
    {
        $router = $this->getRouter(false);
        $router->add('/{anything:[a-z]+}', ['controller' => 'catchAll']);
        $router->add('/about', ['controller' => 'about'])
            ->setHostname('admin.example.com');

        $_SERVER['HTTP_HOST'] = 'www.example.com';
        $router->handle('/about');

        // about route's hostname does not match; catchAll wins.
        $this->assertSame('catchAll', $router->getControllerName());
    }

    /**
     * When an events manager is attached, the combined regex must be
     * bypassed so per-route events continue to fire.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testEventsManagerDisablesCombinedRegex(): void
    {
        $router  = $this->getRouter(false);
        $fired   = [];
        $manager = new EventsManager();
        $manager->attach('router', static function ($event) use (&$fired) {
            $fired[] = $event->getType();
        });
        $router->setEventsManager($manager);

        $router->add('/users/{id:[0-9]+}', ['controller' => 'users']);
        $router->add('/products/{slug:[a-z-]+}', ['controller' => 'products']);

        $router->handle('/users/42');

        $this->assertContains('beforeCheckRoute', $fired);
        $this->assertContains('matchedRoute', $fired);
    }

    /**
     * 25 dynamic routes (above the 10-per-chunk threshold). A route in the
     * second chunk must still match, and a route in the third chunk must
     * still match.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testChunkingBoundary(): void
    {
        $router = $this->getRouter(false);
        for ($i = 0; $i < 25; $i++) {
            $router->add(
                "/r{$i}/{slug:[a-z]+}",
                ['controller' => 'route_' . $i]
            );
        }

        // /r22 was attached as index 22. After reversing the alternatives,
        // the latest 10 attached (24..15) form chunk 0; r22 is in chunk 0.
        $router->handle('/r22/widget');
        $this->assertSame('route_22', $router->getControllerName());

        // /r2 was attached as index 2. After reversing, it lands in chunk
        // 2 (positions 20..24 of the reversed list).
        $router->handle('/r2/widget');
        $this->assertSame('route_2', $router->getControllerName());
    }

    /**
     * With 25 catch-all routes attached, the latest-attached one wins
     * regardless of which chunk it lives in (chunk 0 is tried first by
     * design).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testChunkingPreservesReverseAttachOrder(): void
    {
        $router = $this->getRouter(false);
        for ($i = 0; $i < 25; $i++) {
            $router->add('/{anything' . $i . ':[a-z]+}', ['controller' => 'route_' . $i]);
        }

        $router->handle('/about');

        $this->assertSame('route_24', $router->getControllerName());
    }
}
