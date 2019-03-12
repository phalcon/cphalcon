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

namespace Phalcon\Test\Unit\Http\Message\ServerRequestFactory;

use Phalcon\Http\Message\ServerRequestFactory;
use Psr\Http\Message\ServerRequestInterface;
use UnitTester;

/**
 * Class CreateServerRequestCest
 */
class CreateServerRequestCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequestFactory :: createServerRequest()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-09
     */
    public function httpMessageServerRequestFactoryCreateServerRequest(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequestFactory - createServerRequest()');

        $factory = new ServerRequestFactory();
        $request = $factory->createServerRequest("GET", "");
        $class   = ServerRequestInterface::class;
        $I->assertInstanceOf($class, $request);
    }
}
