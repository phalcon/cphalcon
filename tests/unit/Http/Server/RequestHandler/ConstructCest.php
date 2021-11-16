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

namespace Phalcon\Tests\Unit\Http\Server\RequestHandler;

use Phalcon\Tests\Fixtures\Http\Server\RequestHandlerFixture;
use Psr\Http\Server\RequestHandlerInterface;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Http\Server\RequestHandler :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpServerRequestHandlerHandle(UnitTester $I)
    {
        $I->wantToTest('Http\Server\RequestHandler - __construct()');
        $handler = new RequestHandlerFixture();
        $class   = RequestHandlerInterface::class;
        $I->assertInstanceOf($class, $handler);
    }
}
