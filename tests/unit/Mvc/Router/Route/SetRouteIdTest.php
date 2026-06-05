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

namespace Phalcon\Tests\Unit\Mvc\Router\Route;

use Phalcon\Mvc\Router\Route;
use Phalcon\Tests\AbstractUnitTestCase;

final class SetRouteIdTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testSetRouteIdOverridesConstructorId(): void
    {
        $route = new Route('/x');
        $route->setRouteId('cached-42');

        $this->assertSame('cached-42', $route->getRouteId());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testSetRouteIdReturnsSelfForChaining(): void
    {
        $route  = new Route('/x');
        $result = $route->setRouteId('foo');

        $this->assertSame($route, $result);
    }
}
