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

namespace Phalcon\Test\Unit\Http\Message\RequestFactory;

use Phalcon\Http\Message\RequestFactory;
use Psr\Http\Message\RequestInterface;
use UnitTester;

class CreateRequestCest
{
    /**
     * Tests Phalcon\Http\Message\RequestFactory :: createRequest()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageRequestFactoryCreateRequest(UnitTester $I)
    {
        $I->wantToTest('Http\Message\RequestFactory - createRequest()');

        $factory = new RequestFactory();

        $request = $factory->createRequest('GET', 'https://dev.phalcon.ld');

        $I->assertInstanceOf(
            RequestInterface::class,
            $request
        );
    }
}
