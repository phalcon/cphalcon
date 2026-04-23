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

namespace Phalcon\Tests\Unit\Cli\Router\Route;

use Phalcon\Cli\Router;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetSetDescriptionTest extends AbstractUnitTestCase
{
    /**
     * @since  2020-01-05
     */
    public function testCliRouterRouteGetSetDescription(): void
    {
        $routes = $this->getExampleRoutes();

        $router = new Router(false);

        foreach ($routes as $pattern => $description) {
            $router->add($pattern)
                   ->setDescription($description)
            ;
        }

        foreach ($router->getRoutes() as $route) {
            $expected = $routes[$route->getPattern()];
            $actual   = $route->getDescription();
            $this->assertSame($expected, $actual);
        }
    }

    /**
     * @return array
     */
    private function getExampleRoutes(): array
    {
        return [
            'test'  => 'test description',
            'test1' => 'test description1',
            'test2' => 'test description2',
        ];
    }
}
