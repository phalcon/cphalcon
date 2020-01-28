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

class GetQueryParamsCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getQueryParams()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-03
     */
    public function httpMessageServerRequestGetQueryParams(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getQueryParams()');
        $params  = ['one' => 'two'];
        $request = new ServerRequest('GET', null, [], 'php://input', [], [], $params);

        $expected = $params;
        $actual   = $request->getQueryParams();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getQueryParams() - empty
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-03
     */
    public function httpMessageServerRequestGetQueryParamsEmpty(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getQueryParams() - empty');
        $request = new ServerRequest();

        $actual = $request->getQueryParams();
        $I->assertEmpty($actual);
    }
}
