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
use Phalcon\Tests\Unit\Http\Helper\AbstractHttpBase;

use function uniqid;

final class GetHeaderTest extends AbstractHttpBase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-04
     */
    public function testHttpRequestHeaderGet(): void
    {
        $value                  = uniqid('val-');
        $_SERVER['HTTP_ABCDEF'] = $value;

        $request = new Request();

        $expected = $value;
        $actual   = $request->getHeader('ABCDEF');
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-04
     */
    public function testHttpRequestHeaderGetEmpty(): void
    {
        $request = new Request();

        $name   = uniqid('name-');
        $actual = $request->getHeader($name);
        $this->assertEmpty($actual);
    }
}
