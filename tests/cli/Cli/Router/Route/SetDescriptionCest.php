<?php declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Cli\Cli\Router\Route;

use CliTester;

class SetDescriptionCest
{
    /**
     * Tests Phalcon\Cli\Router\Route :: setDescription()
     *
     * @param CliTester $I
     *
     * @since 2019-04-02
     */
    public function cliRouterRouteSetDescription(CliTester $I)
    {
        $I->wantToTest('Phalcon\Cli\Router\Route - setDescription()');

        $routes = $this->getExampleRoutes();

        $router = new \Phalcon\Cli\Router(false);

        foreach ($routes as $pattern => $description) {
            $router->add($pattern)->setDescription($description);
        }

        foreach ($router->getRoutes() as $route) {
            $I->assertEquals(
                $routes[$route->getPattern()],
                $route->getDescription()
            );
        }
    }

    private function getExampleRoutes(): array
    {
        return [
            'test'  => 'test description',
            'test1' => 'test description1',
            'test2' => 'test description2',
        ];
    }
}
