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

final class GetServerTest extends AbstractHttpBase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function testHttpRequestGetServer(): void
    {
        $key           = uniqid('key-');
        $value         = uniqid('val-');
        $unknown       = uniqid('unk-');
        $_SERVER[$key] = $value;

        $request = $this->getRequestObject();

        $actual = $request->hasServer($key);
        $this->assertTrue($actual);

        $actual = $request->hasServer($unknown);
        $this->assertFalse($actual);

        $expected = $value;
        $actual   = $request->getServer($key);
        $this->assertSame($expected, $actual);
    }
}
