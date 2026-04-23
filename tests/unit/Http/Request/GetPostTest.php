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

use Phalcon\Storage\Exception;
use Phalcon\Tests\Support\Page\Http;
use Phalcon\Tests\Unit\Http\Helper\AbstractHttpBase;

use function strtolower;
use function uniqid;

final class GetPostTest extends AbstractHttpBase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-01
     */
    public function testHttpRequestGetPost(): void
    {
        $key     = uniqid('key-');
        $value   = uniqid('val-');
        $unknown = uniqid('unknown-');

        $_POST[$key] = $value;

        $request = $this->getRequestObject();

        $actual = $request->hasPost($key);
        $this->assertTrue($actual);

        $actual = $request->hasPost($unknown);
        $this->assertFalse($actual);

        $expected = $value;
        $actual   = $request->getPost($key);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2025-07-22
     */
    public function testHttpRequestGetPostJson(): void
    {
        $this->registerStream();

        file_put_contents(
            Http::STREAM,
            '{"fruit": "orange", "quantity": "4"}'
        );

        $_SERVER['REQUEST_METHOD'] = Http::METHOD_POST;
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

        $actual = $request->getPost();
        $this->assertSame($expected, $actual);

        $this->unregisterStream();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-01
     */
    public function testHttpRequestGetPostAllowNoEmpty(): void
    {
        $key   = uniqid('key-');
        $value = '0';

        $_POST[$key] = '  ' . $value . '  ';

        $request = $this->getRequestObject();

        $expected = $value;
        $actual   = $request->getPost(
            $key,
            'trim',
            'zero value',
            true
        );
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-01
     */
    public function testHttpRequestGetPostDefault(): void
    {
        $unknown = uniqid('unknown-');
        $default = uniqid('def-');

        $request = $this->getRequestObject();

        $expected = $default;
        $actual   = $request->getPost($unknown, null, $default);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-01
     */
    public function testHttpRequestGetPostFilter(): void
    {
        $key   = uniqid('key-');
        $value = uniqid('VAL-');

        $_POST[$key] = '  ' . $value . '  ';

        $request = $this->getRequestObject();

        $expected = $value;
        $actual   = $request->getPost($key, 'trim');
        $this->assertSame($expected, $actual);

        $expected = strtolower($value);
        $actual   = $request->getPost($key, ['trim', 'lower']);
        $this->assertSame($expected, $actual);
    }
}
