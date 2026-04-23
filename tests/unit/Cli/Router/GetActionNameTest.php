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

namespace Phalcon\Tests\Unit\Cli\Router;

use Phalcon\Cli\Router;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetActionNameTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testCliRouterGetActionName(): void
    {
        $router = new Router();

        $expected = '';
        $actual   = $router->getActionName();
        $this->assertSame($expected, $actual);

        $router->handle(
            [
                'action' => 'test',
            ]
        );

        $expected = "test";
        $actual   = $router->getActionName();
        $this->assertSame($expected, $actual);
    }
}
