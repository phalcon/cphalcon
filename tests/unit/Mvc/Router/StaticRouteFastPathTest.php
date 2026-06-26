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

use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Mvc\Fake\RouterTrait;
use PHPUnit\Framework\Attributes\BackupGlobals;

#[BackupGlobals(true)]
final class StaticRouteFastPathTest extends AbstractUnitTestCase
{
    use RouterTrait;

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
            ->beforeMatch(static fn(): bool => false);

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
}
