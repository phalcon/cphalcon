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

namespace Phalcon\Tests\Unit\Mvc\Router\Annotations;

use Phalcon\Mvc\Router\Annotations;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

final class GetRoutesTest extends AbstractUnitTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        parent::setUp();

        $this->newDi();
        $this->setDiService('request');
        $this->setDiService('annotations');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcRouterAnnotationsGetRoutes(): void
    {
        // Robots scope '/' + Products '/products' both match '/products'
        $router = new Annotations(false);
        $router->setDI($this->container);
        $router->setDefaultNamespace('Phalcon\Tests\Support\Controllers');
        $router->addResource('Robots', '/');
        $router->addResource('Products', '/products');
        $router->addResource('About', '/about');
        $router->handle('/products');

        $this->assertCount(6, $router->getRoutes());

        // Robots scope '/' + About '/about' match '/about'
        $router = new Annotations(false);
        $router->setDI($this->container);
        $router->setDefaultNamespace('Phalcon\Tests\Support\Controllers');
        $router->addResource('Robots', '/');
        $router->addResource('Products', '/products');
        $router->addResource('About', '/about');
        $router->handle('/about');

        $this->assertCount(5, $router->getRoutes());

        // No scope prefixes - every resource is processed
        $router = new Annotations(false);
        $router->setDI($this->container);
        $router->setDefaultNamespace('Phalcon\Tests\Support\Controllers');
        $router->addResource('Robots');
        $router->addResource('Products');
        $router->addResource('About');
        $router->addResource('Main');
        $router->handle('/');

        $this->assertCount(9, $router->getRoutes());
    }
}
