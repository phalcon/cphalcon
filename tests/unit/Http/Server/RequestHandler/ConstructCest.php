<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Server\RequestHandler;

use Phalcon\Test\Fixtures\Http\Server\RequestHandlerFixture;
use Psr\Http\Server\RequestHandlerInterface;
use UnitTester;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Http\Server\RequestHandler :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
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
