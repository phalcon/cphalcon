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

use function file_get_contents;
use function file_put_contents;
use function json_decode;
use function parse_str;
use function stream_wrapper_register;
use function stream_wrapper_restore;
use function stream_wrapper_unregister;

class GetPutCest
{
    /**
     * Tests Phalcon\Http\Request :: getPut()
     *
     * @issue  @13418
     * @author Phalcon Team <team@phalcon.io>
     * @since  2017-06-03
     */
    public function httpRequestGetPut(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getPut()');

        stream_wrapper_unregister('php');
        stream_wrapper_register('php', PhpStream::class);

        file_put_contents('php://input', 'fruit=orange&quantity=4');

        $store   = $_SERVER ?? [];
        $time    = $_SERVER['REQUEST_TIME_FLOAT'];
        $_SERVER = [
            'REQUEST_TIME_FLOAT' => $time,
            'REQUEST_METHOD'     => 'PUT',
        ];

        $request = new Request();

        $I->assertTrue($request->hasPut('fruit'));
        $I->assertTrue($request->hasPut('quantity'));
        $I->assertFalse($request->hasPut('unknown'));

        $data = file_get_contents('php://input');

        $expected = [
            'fruit'    => 'orange',
            'quantity' => '4',
        ];

        parse_str($data, $actual);

        $I->assertEquals($expected, $actual);

        $I->assertEquals(
            $expected,
            $request->getPut()
        );

        stream_wrapper_restore('php');

        $_SERVER = $store;
    }

    /**
     * Tests Phalcon\Http\Request :: getPut() - json
     *
     * @issue  @13418
     * @author Phalcon Team <team@phalcon.io>
     * @since  2017-06-03
     */
    public function httpRequestGetPutJson(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getPut() - json');

        stream_wrapper_unregister('php');
        stream_wrapper_register('php', PhpStream::class);

        file_put_contents(
            'php://input',
            '{"fruit": "orange", "quantity": "4"}'
        );

        $store   = $_SERVER ?? [];
        $time    = $_SERVER['REQUEST_TIME_FLOAT'];
        $_SERVER = [
            'REQUEST_TIME_FLOAT' => $time,
            'REQUEST_METHOD'     => 'PUT',
            'CONTENT_TYPE'       => 'application/json',
        ];

        $request = new Request();

        $expected = [
            'fruit'    => 'orange',
            'quantity' => '4',
        ];

        $actual = json_decode(
            file_get_contents('php://input'),
            true
        );

        $I->assertEquals($expected, $actual);

        $I->assertEquals(
            $expected,
            $request->getPut()
        );

        stream_wrapper_restore('php');

        $_SERVER = $store;
    }
}
