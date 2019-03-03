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
 * Class GetHeadersCest
 */
class GetHeadersCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getHeaders()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageServerRequestGetHeaders(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getHeaders()');
        $data    = [
            'Cache-Control' => ['max-age=0'],
            'Accept'        => ['text/html'],
        ];
        $request = new ServerRequest('GET', null, [], 'php://input', $data);

        $expected = [
            'cache-control' => [
                'name'  => 'Cache-Control',
                'value' => ['max-age=0'],
            ],
            'accept'        => [
                'name'  => 'Accept',
                'value' => ['text/html'],
            ],
        ];
        $actual   = $request->getHeaders();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getHeaders() - empty
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageServerRequestGetHeadersEmpty(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getHeaders() - empty');
        $request = new ServerRequest();

        $expected = [];
        $actual   = $request->getHeaders();
        $I->assertEquals($expected, $actual);
    }
}
