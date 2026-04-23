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

final class GetHTTPRefererTest extends AbstractHttpBase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function testHttpRequestGetHTTPRefererEmpty(): void
    {
        $request = new Request();

        $this->assertEmpty($request->getHTTPReferer());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function testHttpRequestGetHTTPRefererValid(): void
    {
        $_SERVER['HTTP_REFERER'] = 'Phalcon Referrer';

        $request = new Request();

        $expected = 'Phalcon Referrer';
        $actual   = $request->getHTTPReferer();
        $this->assertSame($expected, $actual);
    }
}
