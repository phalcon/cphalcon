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

namespace Phalcon\Tests\Unit\Cli\Router\Route;

use Phalcon\Cli\Router\Route;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetSetNameTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-05
     */
    public function testCliRouterRouteGetSetName(): void
    {
        Route::reset();
        Route::delimiter('/');
        $route = new Route('test');

        $expected = '';
        $actual   = $route->getName();
        $this->assertSame($expected, $actual);

        $route->setName('otherRoute');

        $expected = 'otherRoute';
        $actual   = $route->getName();
        $this->assertSame($expected, $actual);
    }
}
