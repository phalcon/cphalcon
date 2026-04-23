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

namespace Phalcon\Tests\Unit\Mvc\Router;

use Phalcon\Mvc\Router\Group;
use Phalcon\Mvc\RouterInterface;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Mvc\Fake\RouterTrait;

final class MountTest extends AbstractUnitTestCase
{
    use RouterTrait;

    /**
     * Tests Phalcon\Mvc\Router :: mount()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcRouterMount(): void
    {
        $router = $this->getRouter(false);
        $group  = new Group();
        $group->setPrefix('/api');
        $group->add('/users', ['controller' => 'users', 'action' => 'index']);
        $result = $router->mount($group);
        $this->assertInstanceOf(RouterInterface::class, $result);
        $this->assertNotEmpty($router->getRoutes());
    }
}
