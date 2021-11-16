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

namespace Phalcon\Tests\Unit\Http\Message\ServerRequest;

use Phalcon\Http\Message\ServerRequest;
use UnitTester;

class WithHeaderCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: withHeader()
     *
     * @author Phalcon Team <team@phalcon.io>
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
