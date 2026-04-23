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

use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Mvc\Fake\RouterTrait;

final class GetMatchesTest extends AbstractUnitTestCase
{
    use RouterTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcRouterGetMatches(): void
    {
        $route = '/users/edit/100/';

        $router = $this->getRouter();
        $router->handle($route);

        $actual = $router->wasMatched();
        $this->assertTrue($actual);

        $expected = [
            0 => '/users/edit/100/',
            1 => 'users',
            2 => 'edit',
            3 => '/100/',
        ];
        $actual   = $router->getMatches();
        $this->assertSame($expected, $actual);
    }
}
