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

use Phalcon\Di\Di;
use Phalcon\Di\FactoryDefault;
use Phalcon\Events\Manager;
use Phalcon\Mvc\Application;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Mvc\Router;
use Phalcon\Mvc\Url;
use Phalcon\Mvc\View;
use Phalcon\Mvc\View\Engine\Volt;
use PhpBench\Attributes\BeforeMethods;
use PhpBench\Attributes\Revs;
use RuntimeException;

/**
 * Reference app: MVC with Volt. Each call is one request.
 */
#[BeforeMethods('setUp')]
#[Revs(100)]
final class MvcBench
{
    private const EXPECTED_SHA1 = '097b4cff39daf3b03773bc354ea2cbd828a8b4d5';

    private const URI           = '/products/show/7';

    private string $compiledPath = '';

    public function setUp(): void
    {
        $_SERVER['REQUEST_METHOD'] = 'GET';
        $_SERVER['REQUEST_URI']    = self::URI;

        $this->compiledPath = dirname(__DIR__, 4) . '/.local/bench/fixtures/mvc/volt/';
        if (!is_dir($this->compiledPath)) {
            mkdir($this->compiledPath, 0777, true);
        }
    }

    public function benchPage(): void
    {
        /**
         * A new request: php-fpm clears the default container at the end of each request.
         */
        Di::reset();

        $container = new FactoryDefault();

        /**
         * 50 routes. Routes are tried from the last added to the first added,
         * so the route that matches is added first.
         */
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
        $container->setShared('router', $router);

        $eventsManager = new Manager();
        $eventsManager->attach(
            'dispatch:beforeExecuteRoute',
            function (): bool {
                return true;
            }
        );
        $dispatcher = new Dispatcher();
        $dispatcher->setEventsManager($eventsManager);
        $container->setShared('dispatcher', $dispatcher);

        $url = new Url();
        $url->setBaseUri('/');
        $container->setShared('url', $url);

        $compiledPath = $this->compiledPath;
        $view         = new View();
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
        $container->setShared('view', $view);

        $application = new Application($container);

        ob_start();
        $application->handle(self::URI)->send();
        $body = ob_get_clean();

        $actual = sha1($body);
        if (self::EXPECTED_SHA1 !== $actual) {
            throw new RuntimeException(sprintf('Unexpected body (sha1 %s): %s', $actual, $body));
        }
    }
}
