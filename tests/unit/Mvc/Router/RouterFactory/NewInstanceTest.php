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

namespace Phalcon\Tests\Unit\Mvc\Router\RouterFactory;

use Phalcon\Mvc\Router;
use Phalcon\Mvc\Router\RouterFactory;
use Phalcon\Tests\AbstractUnitTestCase;

final class NewInstanceTest extends AbstractUnitTestCase
{
    public function testNewInstanceReturnsRouterWithDefaultRoutesByDefault(): void
    {
        $router = (new RouterFactory())->newInstance();
        $this->assertInstanceOf(Router::class, $router);
        $this->assertCount(2, $router->getRoutes());
    }

    public function testNewInstanceCanDisableDefaultRoutes(): void
    {
        $router = (new RouterFactory())->newInstance(false);
        $this->assertCount(0, $router->getRoutes());
    }
}
