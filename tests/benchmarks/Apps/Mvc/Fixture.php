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

namespace Phalcon\Tests\Benchmarks\Apps\Mvc;

use Phalcon\Di\DiInterface;
use Phalcon\Mvc\Router;
use Phalcon\Mvc\View;
use Phalcon\Mvc\View\Engine\Volt;

/**
 * Shared setup of the MVC reference app: routes, view, view variables.
 *
 * The methods are not static: the view binds the engine closure to an object, and a closure
 * that is created in a static method cannot be bound.
 */
final class Fixture
{
    /**
     * The folder for the compiled Volt files. It is created if it is missing.
     */
    public function compiledPath(): string
    {
        $path = dirname(__DIR__, 4) . '/.local/bench/fixtures/mvc/volt/';
        if (!is_dir($path)) {
            mkdir($path, 0777, true);
        }

        return $path;
    }

    /**
     * The view variables of the product page.
     */
    public function productVars(string $id): array
    {
        $items = [];
        for ($index = 1; $index <= 10; $index++) {
            $items[] = [
                'name'  => 'Item <' . $index . '> & "more"',
                'price' => $index * 10,
            ];
        }

        return [
            'id'    => (int) $id,
            'items' => $items,
            'name'  => 'Product <b>' . $id . '</b> & "friends"',
            'title' => 'Product ' . $id,
        ];
    }

    /**
     * 50 routes. Routes are tried from the last added to the first added,
     * so the route that matches is added first.
     */
    public function router(): Router
    {
        $router = new Router(false);
        $router->setDefaultNamespace(__NAMESPACE__ . '\\Controllers');
        $router->add(
            '/products/show/{id:[0-9]+}',
            [
                'controller' => 'products',
                'action'     => 'show',
            ]
        );
        for ($index = 1; $index < 50; $index++) {
            $router->add(
                '/section' . $index . '/{slug}',
                [
                    'controller' => 'section' . $index,
                    'action'     => 'index',
                ]
            );
        }

        return $router;
    }

    /**
     * A view with the Volt engine and the compiled files in <compiledPath>.
     */
    public function view(DiInterface $container, string $compiledPath): View
    {
        $view = new View();
        $view->setViewsDir(__DIR__ . '/views/');
        $view->registerEngines(
            [
                '.volt' => function (View $view) use ($compiledPath, $container): Volt {
                    $volt = new Volt($view, $container);
                    $volt->setOptions(
                        [
                            'path'      => $compiledPath,
                            'separator' => '_',
                        ]
                    );

                    return $volt;
                },
            ]
        );

        return $view;
    }
}
