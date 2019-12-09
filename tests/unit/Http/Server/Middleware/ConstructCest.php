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

namespace Phalcon\Test\Unit\Http\Server\Middleware;

use Phalcon\Test\Fixtures\Http\Server\MiddlewareFixture;
use Psr\Http\Server\MiddlewareInterface;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Http\Server\Middleware :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpServerMiddlewareProcess(UnitTester $I)
    {
        $I->wantToTest('Http\Server\Middleware - __construct()');
        $handler = new MiddlewareFixture();
        $class   = MiddlewareInterface::class;
        $I->assertInstanceOf($class, $handler);
    }
}
