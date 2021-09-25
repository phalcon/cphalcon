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

namespace Phalcon\Tests\Unit\Http\Request;

use Phalcon\Http\Request;
use Phalcon\Tests\Fixtures\Http\PhpStream;
use UnitTester;

use function file_put_contents;
use function json_encode;
use function stream_wrapper_register;
use function stream_wrapper_restore;
use function stream_wrapper_unregister;

class GetJsonRawBodyCest
{
    /**
     * Tests Phalcon\Http\Request :: getJsonRawBody()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function httpRequestGetJsonRawBody(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getJsonRawBody()');


        // Empty
        $request = new Request();
        $I->assertEmpty($request->getRawBody());

        // Valid
        stream_wrapper_unregister('php');
        stream_wrapper_register('php', PhpStream::class);

        $input = json_encode(
            [
                'fruit'    => 'orange',
                'quantity' => '4',
            ]
        );

        file_put_contents('php://input', $input);

        $request = new Request();

        $expected = json_decode($input, true);
        $actual   = $request->getJsonRawBody(true);
        $I->assertEquals($expected, $actual);

        stream_wrapper_restore('php');
    }
}
