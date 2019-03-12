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

namespace Phalcon\Test\Unit\Http\Message\Request;

use Phalcon\Http\Message\Request;
use UnitTester;

/**
 * Class GetHeadersCest
 */
class GetHeadersCest
{
    /**
     * Tests Phalcon\Http\Message\Request :: getHeaders()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageRequestGetHeaders(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Request - getHeaders()');
        $data    = [
            'Cache-Control' => ['max-age=0'],
            'Accept'        => ['text/html'],
        ];
        $request = new Request('GET', null, 'php://memory', $data);

        $expected = [
            'Accept'        => ['text/html'],
            'Cache-Control' => ['max-age=0'],
        ];
        $actual   = $request->getHeaders();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\Request :: getHeaders() - empty
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageRequestGetHeadersEmpty(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Request - getHeaders() - empty');
        $request = new Request();

        $expected = [];
        $actual   = $request->getHeaders();
        $I->assertEquals($expected, $actual);
    }
}
