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

namespace Phalcon\Test\Unit\Http\Message\ServerRequest;

use Phalcon\Http\Message\ServerRequest;
use UnitTester;

/**
 * Class GetCookieParamsCest
 */
class GetCookieParamsCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getCookieParams()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
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
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
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
