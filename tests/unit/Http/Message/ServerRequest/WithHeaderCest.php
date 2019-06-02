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

class WithHeaderCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: withHeader()
     *
     * @since  2019-02-10
     */
    public function httpMessageServerRequestWithHeader(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - withHeader()');
        $data        = [
            'Accept' => ['text/html'],
        ];
        $request     = new ServerRequest('GET', null, [], 'php://input', $data);
        $newInstance = $request->withHeader('Cache-Control', ['max-age=0']);

        $I->assertNotEquals($request, $newInstance);

        $expected = [
            'Accept' => ['text/html'],
        ];
        $actual   = $request->getHeaders();
        $I->assertEquals($expected, $actual);

        $expected = [
            'Accept'        => ['text/html'],
            'Cache-Control' => ['max-age=0'],
        ];
        $actual   = $newInstance->getHeaders();
        $I->assertEquals($expected, $actual);
    }
}
