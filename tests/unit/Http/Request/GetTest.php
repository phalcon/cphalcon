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

use Phalcon\Tests\Unit\Http\Helper\AbstractHttpBase;

use function uniqid;

final class GetTest extends AbstractHttpBase
{
    /**
     * @issue https://github.com/phalcon/cphalcon/issues/1265
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-04
     */
    public function testHttpRequestGet(): void
    {
        $key   = uniqid('key-');
        $value = uniqid('val-');

        $_REQUEST = [
            'id'         => 1,
            'num'        => 'a1a',
            'age'        => 'aa',
            'phone'      => '',
            'string-key' => 'hello',
            'array-key'  => ['string' => 'world'],
        ];

        $request = $this->getRequestObject();

        $actual = $request->has($key);
        $this->assertFalse($actual);

        $_REQUEST[$key] = $value;

        $actual = $request->has($key);
        $this->assertTrue($actual);

        $expected = $value;
        $actual   = $request->get($key);
        $this->assertSame($expected, $actual);

        /**
         * Get - different methods
         */
        $expected = 'hello';
        $actual   = $request->get('string-key', 'string');
        $this->assertSame($expected, $actual);

        $expected = 'hello';
        $actual   = $request->get(
            'string-key',
            'string',
            null,
            true,
            true
        );
        $this->assertSame($expected, $actual);

        $expected = ['string' => 'world'];
        $actual   = $request->get('array-key', 'string');
        $this->assertSame($expected, $actual);

        $expected = ['string' => 'world'];
        $actual   = $request->get(
            'array-key',
            'string',
            null,
            true,
            false
        );
        $this->assertSame($expected, $actual);

        $expected = 1;
        $actual   = $request->get('id', 'int', 100);
        $this->assertSame($expected, $actual);

        $expected = 1;
        $actual   = $request->get('num', 'int', 100);
        $this->assertSame($expected, $actual);

        $actual = $request->get('age', 'int', 100);
        $this->assertEmpty($actual);

        $actual = $request->get('phone', 'int', 100);
        $this->assertEmpty($actual);

        $expected = 100;
        $actual   = $request->get('phone', 'int', 100, true);
        $this->assertSame($expected, $actual);
    }
}
