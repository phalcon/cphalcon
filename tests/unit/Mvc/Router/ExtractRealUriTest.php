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
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Mvc\Fake\FakeRouter;
use Phalcon\Tests\Unit\Mvc\Fake\RouterTrait;

final class ExtractRealUriTest extends AbstractUnitTestCase
{
    use RouterTrait;

    /**
     * @issue        16749
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2025-04-11
     */
    public function testExtractRealUri(): void
    {
        $router = new FakeRouter(false);
        $router->setDI(new FactoryDefault());

        $expected = '/admin/private/businesses/list/my/123';
        $actual   = $router->protectedExtractRealUri(
            '/admin/private/businesses/list/my/123?query=string'
        );
        $this->assertSame($expected, $actual);

        $expected = '/admin/private/businesses/list/my/123';
        $actual = $router->protectedExtractRealUri(
            '/admin/private/businesses/list/my/123'
        );
        $this->assertSame($expected, $actual);
    }
}
