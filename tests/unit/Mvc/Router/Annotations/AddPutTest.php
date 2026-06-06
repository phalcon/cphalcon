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

final class AddPutTest extends AbstractUnitTestCase
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
    public function testMvcRouterAnnotationsAddPut(): void
    {
        $router = new Annotations(false);
        $router->setDI($this->container);

        $router->addPut(
            '/docs/index',
            [
                'controller' => 'documentation',
                'action'     => 'index',
            ]
        );

        $_SERVER['REQUEST_METHOD'] = 'PUT';
        $router->handle('/docs/index');

        $this->assertSame('documentation', $router->getControllerName());
        $this->assertSame('index', $router->getActionName());
        $this->assertSame([], $router->getParams());
    }
}
