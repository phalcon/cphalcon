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

use function file_get_contents;
use function file_put_contents;
use function json_decode;
use function parse_str;
use function stream_wrapper_register;
use function stream_wrapper_restore;
use function stream_wrapper_unregister;

class GetPatchCest
{
    /**
     * Tests Phalcon\Http\Request :: getPatch()
     *
     * @issue  16188
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-11-01
     */
    public function httpRequestGetPatch(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getPatch()');

        stream_wrapper_unregister('php');
        stream_wrapper_register('php', PhpStream::class);

        file_put_contents('php://input', 'fruit=orange&quantity=4');

        $store   = $_SERVER ?? [];
        $time    = $_SERVER['REQUEST_TIME_FLOAT'];
        $_SERVER = [
            'REQUEST_TIME_FLOAT' => $time,
            'REQUEST_METHOD'     => 'PATCH',
        ];

        $request = new Request();

        $actual = $request->hasPatch('fruit');
        $I->assertTrue($actual);
        $actual = $request->hasPatch('quantity');
        $I->assertTrue($actual);
        $actual = $request->hasPatch('unknown');
        $I->assertFalse($actual);

        $data = file_get_contents('php://input');

        $expected = [
            'fruit'    => 'orange',
            'quantity' => '4',
        ];

        parse_str($data, $actual);

        $I->assertSame($expected, $actual);

        $actual = $request->getPatch();
        $I->assertSame($expected, $actual);

        stream_wrapper_restore('php');

        $_SERVER = $store;
    }

    /**
     * Tests Phalcon\Http\Request :: getPatch() - json
     *
     * @issue  16188
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-11-01
     */
    public function httpRequestGetPatchJson(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getPatch() - json');

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
            'REQUEST_METHOD'     => 'PATCH',
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

        $I->assertSame($expected, $actual);

        $actual = $request->getPatch();
        $I->assertSame($expected, $actual);

        stream_wrapper_restore('php');

        $_SERVER = $store;
    }
}
