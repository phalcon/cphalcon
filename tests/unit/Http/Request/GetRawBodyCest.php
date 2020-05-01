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

namespace Phalcon\Test\Unit\Http\Request;

use Phalcon\Http\Request;
use Phalcon\Test\Fixtures\Http\PhpStream;
use UnitTester;

use function file_put_contents;
use function parse_str;
use function stream_wrapper_register;
use function stream_wrapper_restore;
use function stream_wrapper_unregister;

class GetRawBodyCest
{
    /**
     * Tests Phalcon\Http\Request :: getRawBody()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function httpRequestGetRawBody(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getRawBody()');

        // Empty
        $request = new Request();
        $I->assertEmpty($request->getRawBody());

        // Valid
        stream_wrapper_unregister('php');
        stream_wrapper_register('php', PhpStream::class);

        file_put_contents('php://input', 'fruit=orange&quantity=4');

        $request = new Request();

        $expected = [
            'fruit'    => 'orange',
            'quantity' => '4',
        ];

        $data = $request->getRawBody();
        parse_str($data, $actual);

        $I->assertEquals($expected, $actual);

        stream_wrapper_restore('php');
    }
}
