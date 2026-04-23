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

final class IsTest extends AbstractHttpBase
{
    /**
     * @return array|array[]
     */
    public static function getExamples(): array
    {
        return [
            [
                [],
                false,
                'isAjax',
            ],
            [
                [
                    'HTTP_X_REQUESTED_WITH' => 'XMLHttpRequest',
                ],
                true,
                'isAjax',
            ],
            [
                [],
                false,
                'isConnect',
            ],
            [
                [
                    'REQUEST_METHOD' => 'CONNECT',
                ],
                true,
                'isConnect',
            ],
            [
                [],
                false,
                'isDelete',
            ],
            [
                [
                    'REQUEST_METHOD' => 'DELETE',
                ],
                true,
                'isDelete',
            ],
            [
                [],
                true,
                'isGet',
            ],
            [
                [
                    'REQUEST_METHOD' => 'GET',
                ],
                true,
                'isGet',
            ],
            [
                [],
                false,
                'isHead',
            ],
            [
                [
                    'REQUEST_METHOD' => 'HEAD',
                ],
                true,
                'isHead',
            ],
            [
                [],
                false,
                'isOptions',
            ],
            [
                [
                    'REQUEST_METHOD' => 'OPTIONS',
                ],
                true,
                'isOptions',
            ],
            [
                [],
                false,
                'isPatch',
            ],
            [
                [
                    'REQUEST_METHOD' => 'PATCH',
                ],
                true,
                'isPatch',
            ],
            [
                [],
                false,
                'isPost',
            ],
            [
                [
                    'REQUEST_METHOD' => 'POST',
                ],
                true,
                'isPost',
            ],
            [
                [],
                false,
                'isPut',
            ],
            [
                [
                    'REQUEST_METHOD' => 'PUT',
                ],
                true,
                'isPut',
            ],
            [
                [],
                false,
                'isPurge',
            ],
            [
                [
                    'REQUEST_METHOD' => 'PURGE',
                ],
                true,
                'isPurge',
            ],
            [
                [],
                false,
                'isSecure',
            ],
            [
                [
                    'HTTPS' => 'on',
                ],
                true,
                'isSecure',
            ],
            [
                [],
                false,
                'isSoap',
            ],
            [
                [
                    'CONTENT_TYPE' => 'application/soap+xml',
                ],
                true,
                'isSoap',
            ],
            [
                [
                    'CONTENT_TYPE' => 'application/json',
                ],
                true,
                'isJson',
            ],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-03-17
     */
    public function testHttpRequestIs(
        array $server,
        bool $expected,
        string $method
    ): void {
        $_SERVER = array_merge($_SERVER, $server);

        $request = $this->getRequestObject();
        $actual  = $request->$method();

        $this->assertSame($expected, $actual);
    }
}
