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

use function strtolower;
use function uniqid;

final class GetQueryTest extends AbstractHttpBase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-01
     */
    public function testHttpRequestGetQuery(): void
    {
        $key        = uniqid('key-');
        $value      = uniqid('val-');
        $unknown    = uniqid('unk-');
        $_GET[$key] = $value;

        $request = $this->getRequestObject();

        $actual = $request->hasQuery($key);
        $this->assertTrue($actual);

        $actual = $request->hasQuery($unknown);
        $this->assertFalse($actual);

        $expected = $value;
        $actual   = $request->getQuery($key);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-01
     */
    public function testHttpRequestGetQueryAllowNoEmpty(): void
    {
        $key = uniqid('key-');

        $_GET[$key] = ' 0 ';

        $request = $this->getRequestObject();

        $expected = '0';
        $actual   = $request->getQuery($key, 'trim', 'zero value', true);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-01
     */
    public function testHttpRequestGetQueryDefault(): void
    {
        $key     = uniqid('key-');
        $request = $this->getRequestObject();

        $expected = 'default';
        $actual   = $request->getQuery($key, null, 'default');
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-01
     */
    public function testHttpRequestGetQueryFilter(): void
    {
        $key        = uniqid('key-');
        $value      = uniqid('VAL-');
        $_GET[$key] = '  ' . $value . '  ';

        $request = $this->getRequestObject();

        $expected = $value;
        $actual   = $request->getQuery($key, 'trim');
        $this->assertSame($expected, $actual);

        $expected = strtolower($value);
        $actual   = $request->getQuery($key, ['trim', 'lower']);
        $this->assertSame($expected, $actual);
    }
}
