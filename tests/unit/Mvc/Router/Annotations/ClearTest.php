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

final class ClearTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcRouterAnnotationsClear(): void
    {
        $router = new Annotations(false);

        $router->addGet(
            '/docs/index',
            [
                'controller' => 'documentation',
                'action'     => 'index',
            ]
        );

        $this->assertCount(1, $router->getRoutes());

        $router->clear();

        $this->assertCount(0, $router->getRoutes());
    }
}
