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
use Phalcon\Tests\Support\Page\Http;
use Phalcon\Tests\Unit\Http\Helper\AbstractHttpBase;

final class GetAcceptableContentTest extends AbstractHttpBase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function testHttpRequestGetAcceptableContent(): void
    {
        $_SERVER['HTTP_ACCEPT'] = 'text/html,'
            . 'application/xhtml+xml,application/xml;q=0.9,'
            . 'image/webp,image/apng,'
            . '*/*;q=0.8';

        $request  = new Request();
        $expected = [
            [
                'accept'  => Http::CONTENT_TYPE_HTML,
                'quality' => 1.0,
            ],
            [
                'accept'  => 'application/xhtml+xml',
                'quality' => 1.0,
            ],
            [
                'accept'  => 'application/xml',
                'quality' => 0.9,
            ],
            [
                'accept'  => 'image/webp',
                'quality' => 1.0,
            ],
            [
                'accept'  => 'image/apng',
                'quality' => 1.0,
            ],
            [
                'accept'  => '*/*',
                'quality' => 0.8,
            ],
        ];
        $actual   = $request->getAcceptableContent();
        $this->assertSame($expected, $actual);
    }
}
