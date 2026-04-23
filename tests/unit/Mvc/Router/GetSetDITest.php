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

use Phalcon\Di\FactoryDefault;
use Phalcon\Mvc\Router;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

final class GetSetDITest extends AbstractUnitTestCase
{
    use DiTrait;

    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-22
     */
    public function testMvcRouterGetSetDI(): void
    {
        $router = new Router();

        $di = new FactoryDefault();

        $router->setDI($di);

        $this->assertSame(
            $di,
            $router->getDI()
        );
    }
}
