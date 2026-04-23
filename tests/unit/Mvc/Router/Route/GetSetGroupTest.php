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

namespace Phalcon\Tests\Unit\Mvc\Router\Route;

use Phalcon\Mvc\Router\Group;
use Phalcon\Mvc\Router\Route;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetSetGroupTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-01-27
     */
    public function testMvcRouterRouteGetSetGroup(): void
    {
        $route = new Route('test');

        $actual = $route->getGroup();
        $this->assertNull($actual);

        $group = new Group();
        $route->setGroup($group);

        $expected = $group;
        $actual   = $route->getGroup();
        $this->assertSame($expected, $actual);
    }
}
