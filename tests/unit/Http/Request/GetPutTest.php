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

use Phalcon\Tests\Support\Page\Http;
use Phalcon\Tests\Unit\Http\Helper\AbstractHttpBase;

use function file_get_contents;
use function file_put_contents;
use function json_decode;
use function parse_str;

final class GetPutTest extends AbstractHttpBase
{
    /**
     * @issue  @13418
     * @author Phalcon Team <team@phalcon.io>
     * @since  2017-06-03
     */
    public function testHttpRequestGetPut(): void
    {
        $this->registerStream();

        file_put_contents(Http::STREAM, 'fruit=orange&quantity=4');

        $_SERVER['REQUEST_METHOD'] = Http::METHOD_PUT;

        $request = $this->getRequestObject();

        $actual = $request->hasPut('fruit');
        $this->assertTrue($actual);

        $actual = $request->hasPut('quantity');
        $this->assertTrue($actual);

        $actual = $request->hasPut('unknown');
        $this->assertFalse($actual);

        $data = file_get_contents(Http::STREAM);

        $expected = [
            'fruit'    => 'orange',
            'quantity' => '4',
        ];

        $actual = [];
        parse_str($data, $actual);

        $this->assertSame($expected, $actual);

        $actual = $request->getPut();
        $this->assertSame($expected, $actual);

        $this->unregisterStream();
    }

    /**
     * @issue  @13418
     * @author Phalcon Team <team@phalcon.io>
     * @since  2017-06-03
     */
    public function testHttpRequestGetPutJson(): void
    {
        $this->registerStream();

        file_put_contents(
            Http::STREAM,
            '{"fruit": "orange", "quantity": "4"}'
        );

        $_SERVER['REQUEST_METHOD'] = Http::METHOD_PUT;
        $_SERVER['CONTENT_TYPE']   = Http::CONTENT_TYPE_JSON;

        $request = $this->getRequestObject();

        $expected = [
            'fruit'    => 'orange',
            'quantity' => '4',
        ];

        $actual = json_decode(
            file_get_contents(Http::STREAM),
            true
        );

        $this->assertSame($expected, $actual);

        $actual = $request->getPut();
        $this->assertSame($expected, $actual);

        $this->unregisterStream();
    }
}
