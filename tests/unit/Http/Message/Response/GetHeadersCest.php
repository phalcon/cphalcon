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

namespace Phalcon\Test\Unit\Http\Message\Response;

use Phalcon\Http\Message\Response;
use UnitTester;

/**
 * Class GetHeadersCest
 */
class GetHeadersCest
{
    /**
     * Tests Phalcon\Http\Message\Response :: getHeaders()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-09
     */
    public function httpMessageResponseGetHeaders(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - getHeaders()');
        $data    = [
            'Cache-Control' => ['max-age=0'],
            'Accept'        => ['text/html'],
        ];
        $request = new Response('php://memory', 200, $data);

        $expected = [
            'Accept'        => ['text/html'],
            'Cache-Control' => ['max-age=0'],
        ];
        $actual   = $request->getHeaders();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\Response :: getHeaders() - empty
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-09
     */
    public function httpMessageResponseGetHeadersEmpty(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - getHeaders() - empty');
        $request = new Response();

        $expected = [];
        $actual   = $request->getHeaders();
        $I->assertEquals($expected, $actual);
    }
}
