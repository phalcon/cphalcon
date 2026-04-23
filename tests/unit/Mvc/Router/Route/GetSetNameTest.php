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

use Phalcon\Mvc\Router\Route;
use Phalcon\Tests\AbstractUnitTestCase;

use function uniqid;

final class GetSetNameTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-01-27
     */
    public function testMvcRouterRouteGetSetName(): void
    {
        $route = new Route('test');

        $actual = $route->getName();
        $this->assertNull($actual);

        $name = uniqid();
        $route->setName($name);

        $expected = $name;
        $actual   = $route->getName();
        $this->assertSame($expected, $actual);
    }
}
