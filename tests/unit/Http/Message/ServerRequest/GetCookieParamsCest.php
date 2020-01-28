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

namespace Phalcon\Test\Unit\Http\Message\ServerRequest;

use Phalcon\Http\Message\ServerRequest;
use UnitTester;

class GetCookieParamsCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getCookieParams()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageServerRequestGetCookieParams(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getCookieParams()');
        $cookies = ['one' => 'two'];
        $request = new ServerRequest('GET', null, [], 'php://input', [], $cookies);

        $expected = $cookies;
        $actual   = $request->getCookieParams();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getCookieParams() - empty
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageServerRequestGetCookieParamsEmpty(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getCookieParams() - empty');
        $request = new ServerRequest();

        $actual = $request->getCookieParams();
        $I->assertEmpty($actual);
    }
}
