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

class GetParsedBodyCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getParsedBody()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-05
     */
    public function httpMessageServerRequestGetParsedBody(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getParsedBody()');
        $request = new ServerRequest(
            'GET',
            null,
            [],
            'php://input',
            [],
            [],
            [],
            [],
            'something'
        );

        $expected = 'something';
        $actual   = $request->getParsedBody();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getParsedBody() - empty
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-05
     */
    public function httpMessageServerRequestGetParsedBodyEmpty(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getParsedBody() - empty');
        $request = new ServerRequest();

        $expected = '';
        $actual   = $request->getParsedBody();
        $I->assertEquals($expected, $actual);
    }
}
