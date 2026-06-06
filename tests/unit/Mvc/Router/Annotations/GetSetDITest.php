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

use Phalcon\Di\FactoryDefault;
use Phalcon\Mvc\Router\Annotations;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetSetDITest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcRouterAnnotationsGetSetDI(): void
    {
        $router = new Annotations(false);
        $di     = new FactoryDefault();

        $router->setDI($di);

        $this->assertSame($di, $router->getDI());
    }
}
