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

namespace Phalcon\Tests\Integration\Mvc\Router;

use IntegrationTester;
use Phalcon\Di\FactoryDefault;
use Phalcon\Tests\Fixtures\Mvc\Router;

class ExtractRealUriCest
{
    /**
     * Tests Phalcon\Mvc\Router :: extractRealUri()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2025-04-11
     * @issue        16749
     */
    public function testExtractRealUri(IntegrationTester $I): void
    {
        $router = new Router(false);
        $router->setDI(new FactoryDefault());

        $realUri = $router->protectedExtractRealUri(
            '/admin/private/businesses/list/my/123?query=string'
        );
        $I->assertSame('/admin/private/businesses/list/my/123', $realUri);

        $realUri = $router->protectedExtractRealUri(
            '/admin/private/businesses/list/my/123'
        );
        $I->assertSame('/admin/private/businesses/list/my/123', $realUri);
    }
}
