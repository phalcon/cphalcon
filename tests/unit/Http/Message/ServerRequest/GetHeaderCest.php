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
 * Class GetHeaderCest
 */
class GetHeaderCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getHeader() - empty headers
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageServerRequestGetHeader(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getHeader()');
        $data    = [
            'Cache-Control' => ['max-age=0'],
            'Accept'        => ['text/html'],
        ];
        $request = new ServerRequest('GET', null, [], 'php://input', $data);

        $expected = ['text/html'];
        $actual   = $request->getHeader('accept');
        $I->assertEquals($expected, $actual);

        $actual   = $request->getHeader('aCCepT');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getHeader() - empty headers
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageServerRequestGetHeaderEmptyHeaders(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getHeader() - empty headers');
        $request = new ServerRequest();

        $expected = [];
        $actual   = $request->getHeader('empty');
        $I->assertEquals($expected, $actual);
    }
}
