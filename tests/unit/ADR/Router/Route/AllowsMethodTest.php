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

namespace Phalcon\Tests\Unit\ADR\Router\Route;

use Phalcon\ADR\Router\Route;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class AllowsMethodTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\Router\Route :: allowsMethod()
     */
    public function testAdrRouterRouteAllowsMethod(): void
    {
        $route = new Route('/posts', 'ListAction', ['GET']);
        $this->assertTrue($route->allowsMethod('GET'));
        $this->assertFalse($route->allowsMethod('POST'));

        // empty method list allows any verb
        $any = new Route('/posts', 'ListAction');
        $this->assertTrue($any->allowsMethod('DELETE'));
    }
}
