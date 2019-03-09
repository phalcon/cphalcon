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

namespace Phalcon\Test\Unit\Http\Message\RequestFactory;

use Phalcon\Http\Message\RequestFactory;
use Psr\Http\Message\RequestInterface;
use UnitTester;

/**
 * Class CreateRequestCest
 */
class CreateRequestCest
{
    /**
     * Tests Phalcon\Http\Message\RequestFactory :: createRequest()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageRequestFactoryCreateRequest(UnitTester $I)
    {
        $I->wantToTest('Http\Message\RequestFactory - createRequest()');
        $factory = new RequestFactory();
        $request = $factory->createRequest('GET', 'https://dev.phalcon.ld');
        $class   = RequestInterface::class;
        $I->assertInstanceOf($class, $request);
    }
}
