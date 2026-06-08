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
use Phalcon\Mvc\Router\Route;
use Phalcon\Mvc\RouterInterface;
use Phalcon\Tests\AbstractUnitTestCase;

final class AttachTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcRouterAnnotationsAttach(): void
    {
        $router = new Annotations(false);
        $route  = new Route('/test');

        $result = $router->attach($route);

        $this->assertInstanceOf(RouterInterface::class, $result);
        $this->assertCount(1, $router->getRoutes());
        $this->assertSame($route, $router->getRoutes()[0]);
    }
}
