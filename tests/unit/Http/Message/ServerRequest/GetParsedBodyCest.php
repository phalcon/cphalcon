<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Message\ServerRequest;

use Phalcon\Http\Message\ServerRequest;
use UnitTester;

class GetParsedBodyCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getParsedBody()
     *
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
