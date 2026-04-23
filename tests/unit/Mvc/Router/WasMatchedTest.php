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

final class WasMatchedTest extends AbstractUnitTestCase
{
    use RouterTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcRouterWasMatched(): void
    {
        $router = $this->getRouter(false);
        $this->assertFalse($router->wasMatched());
        $router->add('/test', ['controller' => 'test', 'action' => 'index']);
        $router->handle('/test');
        $this->assertTrue($router->wasMatched());
    }
}
