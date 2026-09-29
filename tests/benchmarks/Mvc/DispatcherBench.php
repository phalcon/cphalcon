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

namespace Phalcon\Tests\Benchmarks\Mvc;

use Phalcon\Di\Di;
use Phalcon\Di\FactoryDefault;
use Phalcon\Events\Manager;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Mvc\View;
use PhpBench\Attributes\BeforeMethods;
use RuntimeException;

#[BeforeMethods('setUp')]
final class DispatcherBench
{
    private Dispatcher $dispatcher;

    private View $view;

    public function setUp(): void
    {
        Di::reset();
        $container = new FactoryDefault();

        $this->view = new View();
        $container->setShared('view', $this->view);

        $eventsManager = new Manager();
        $eventsManager->attach(
            'dispatch:beforeExecuteRoute',
            function (): bool {
                return true;
            }
        );

        $this->dispatcher = new Dispatcher();
        $this->dispatcher->setDI($container);
        $this->dispatcher->setEventsManager($eventsManager);
        $this->dispatcher->setDefaultNamespace('Phalcon\\Tests\\Benchmarks\\Apps\\Mvc\\Controllers');
        $container->setShared('dispatcher', $this->dispatcher);
    }

    /**
     * Controller and action of the MVC app, with 1 event listener.
     */
    public function benchDispatch(): void
    {
        $this->view->setVars([], false);

        $this->dispatcher->setControllerName('products');
        $this->dispatcher->setActionName('show');
        $this->dispatcher->setParams(['id' => '7']);
        $this->dispatcher->dispatch();

        if (7 !== $this->view->getVar('id')) {
            throw new RuntimeException('The action did not set the view variables');
        }
    }
}
