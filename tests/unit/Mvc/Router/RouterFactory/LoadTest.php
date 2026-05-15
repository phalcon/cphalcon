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

use Phalcon\Config\Config;
use Phalcon\Mvc\Router;
use Phalcon\Mvc\Router\Exception;
use Phalcon\Mvc\Router\RouterFactory;
use Phalcon\Tests\AbstractUnitTestCase;

final class LoadTest extends AbstractUnitTestCase
{
    public function testLoadFromArrayWithoutDefaultRoutes(): void
    {
        $router = (new RouterFactory())->load([
            'defaultRoutes' => false,
            'routes'        => [
                ['method' => 'get', 'pattern' => '/about', 'paths' => 'About::index'],
            ],
        ]);

        $this->assertInstanceOf(Router::class, $router);
        $this->assertCount(1, $router->getRoutes());
        $this->assertSame('/about', $router->getRoutes()[0]->getPattern());
    }

    public function testLoadFromArrayDefaultsToDefaultRoutesTrue(): void
    {
        $router = (new RouterFactory())->load([
            'routes' => [
                ['method' => 'get', 'pattern' => '/x', 'paths' => 'X::y'],
            ],
        ]);

        $this->assertCount(3, $router->getRoutes());
    }

    public function testLoadAcceptsConfigObject(): void
    {
        $config = new Config([
            'defaultRoutes' => false,
            'routes'        => [
                ['method' => 'get', 'pattern' => '/about', 'paths' => 'About::index'],
            ],
        ]);

        $router = (new RouterFactory())->load($config);
        $this->assertCount(1, $router->getRoutes());
    }

    public function testLoadRejectsNonArrayNonConfig(): void
    {
        $this->expectException(Exception::class);
        (new RouterFactory())->load('whatever');
    }
}
