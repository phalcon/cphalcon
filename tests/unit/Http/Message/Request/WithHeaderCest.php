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

class WithHeaderCest
{
    /**
     * Tests Phalcon\Http\Message\Request :: withHeader()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageRequestWithHeader(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Request - withHeader()');

        $data = [
            'Accept' => ['text/html'],
        ];

        $request = new Request('GET', null, 'php://memory', $data);

        $newInstance = $request->withHeader(
            'Cache-Control',
            [
                'max-age=0',
            ]
        );

        $I->assertNotEquals($request, $newInstance);



        $expected = [
            'Accept' => ['text/html'],
        ];

        $I->assertEquals(
            $expected,
            $request->getHeaders()
        );



        $expected = [
            'Accept'        => ['text/html'],
            'Cache-Control' => ['max-age=0'],
        ];

        $I->assertEquals(
            $expected,
            $newInstance->getHeaders()
        );
    }
}
