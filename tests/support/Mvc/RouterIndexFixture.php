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

namespace Phalcon\Tests\Support\Mvc;

use Phalcon\Mvc\Router;

/**
 * A router with routes for each pass of the method index
 */
final class RouterIndexFixture
{
    /**
     * Returns the dispatcher dump of the router. A route id depends on the
     * routes that the process made before, so the dump uses the position of
     * the route in place of its id.
     *
     * @return array<string, mixed>
     */
    public static function dump(): array
    {
        $router = new Router(false);

        $router->add('/', ['controller' => 'index']);
        $router->addGet('/about', ['controller' => 'about']);
        $router->addPost('/about', ['controller' => 'about', 'action' => 'save']);
        $router->add('/users/{id:[0-9]+}', ['controller' => 'users']);
        $router->add('/products/{slug}', ['controller' => 'products'], ['GET', 'POST']);
        $router->add('/ping', ['controller' => 'ping'], 'HEAD');
        $router->addGet('/{page}', ['controller' => 'pages']);
        $router->addGet('/about', ['controller' => 'about', 'action' => 'again']);
        $router->addPut('/admin', ['controller' => 'admin'])->setHostname('admin.example.com');
        $router->addGet('/search', ['controller' => 'search'])->beforeMatch('is_string');

        for ($index = 1; $index <= 11; $index++) {
            $router->addPatch(
                '/items/' . $index . '/{id:[0-9]+}',
                ['controller' => 'items']
            );
        }

        $dump = $router->buildDispatcherDump();
        $ids  = [];

        foreach ($dump['routes'] as $position => $route) {
            $ids[$route['id']]               = $position;
            $dump['routes'][$position]['id'] = $position;
        }

        $routeMeta = [];
        foreach ($dump['routeMeta'] as $id => $meta) {
            $routeMeta[$ids[$id]] = $meta;
        }

        $dump['routeMeta'] = $routeMeta;

        return $dump;
    }
}
