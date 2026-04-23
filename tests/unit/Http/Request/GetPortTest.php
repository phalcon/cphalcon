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

final class GetPortTest extends AbstractHttpBase
{
    /**
     * @return array[]
     */
    public static function getExamples(): array
    {
        return [
            [
                'on',
                Http::TEST_DOMAIN,
                443,
            ],
            [
                'off',
                Http::TEST_DOMAIN,
                80,
            ],
            [
                'off',
                Http::TEST_DOMAIN . ':8080',
                8080,
            ],
            [
                'on',
                Http::TEST_DOMAIN . ':8081',
                8081,
            ],
            [
                'unset',
                Http::TEST_DOMAIN . ':8082',
                8082,
            ],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2016-06-26
     */
    public function testHttpRequestPort(
        string $https,
        string $host,
        int $expected
    ): void {
        $request = $this->getRequestObject();

        $_SERVER['HTTPS']     = $https;
        $_SERVER['HTTP_HOST'] = $host;

        if ('unset' === $https) {
            unset($_SERVER['https']);
        }

        $actual = $request->getPort();
        $this->assertSame($expected, $actual);
    }
}
