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

final class GetPatchTest extends AbstractHttpBase
{
    /**
     * @issue  16188
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-11-01
     */
    public function testHttpRequestGetPatch(): void
    {
        $this->registerStream();

        file_put_contents(Http::STREAM, 'fruit=orange&quantity=4');

        $_SERVER['REQUEST_METHOD'] = Http::METHOD_PATCH;

        $request = $this->getRequestObject();

        $actual = $request->hasPatch('fruit');
        $this->assertTrue($actual);
        $actual = $request->hasPatch('quantity');
        $this->assertTrue($actual);
        $actual = $request->hasPatch('unknown');
        $this->assertFalse($actual);

        $data = file_get_contents(Http::STREAM);

        $actual = [];
        parse_str($data, $actual);

        $expected = [
            'fruit'    => 'orange',
            'quantity' => '4',
        ];
        $this->assertSame($expected, $actual);

        $actual = $request->getPatch();
        $this->assertSame($expected, $actual);

        $this->unregisterStream();
    }

    /**
     * @issue  16188
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-11-01
     */
    public function testHttpRequestGetPatchJson(): void
    {
        $this->registerStream();

        file_put_contents(
            Http::STREAM,
            '{"fruit": "orange", "quantity": "4"}'
        );

        $_SERVER['REQUEST_METHOD'] = Http::METHOD_PATCH;
        $_SERVER['CONTENT_TYPE']   = Http::CONTENT_TYPE_JSON;

        $request = $this->getRequestObject();

        $expected = [
            'fruit'    => 'orange',
            'quantity' => '4',
        ];
        $actual   = json_decode(
            file_get_contents(Http::STREAM),
            true
        );
        $this->assertSame($expected, $actual);

        $actual = $request->getPatch();
        $this->assertSame($expected, $actual);

        $this->unregisterStream();
    }
}
