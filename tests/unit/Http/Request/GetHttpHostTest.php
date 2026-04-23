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
use PHPUnit\Framework\Attributes\DataProvider;
use UnexpectedValueException;

final class GetHttpHostTest extends AbstractHttpBase
{
    /**
     * @return array[]
     */
    public static function getExamples(): array
    {
        return [
            [
                [
                    'HTTP_HOST'   => '',
                    'SERVER_NAME' => '',
                    'SERVER_ADDR' => '',
                ],
                [
                    '',
                ],
            ],
            [
                [
                    'HTTP_HOST'   => '',
                    'SERVER_NAME' => 'host@name',
                    'SERVER_ADDR' => '',
                ],
                [
                    'host@name',
                ],
            ],
            [
                [
                    'HTTPS'       => 'off',
                    'SERVER_NAME' => 'localhost',
                    'SERVER_PORT' => 80,
                ],
                [
                    'localhost',
                ],
            ],
            [
                [
                    'HTTPS'       => 'on',
                    'SERVER_NAME' => 'localhost',
                    'SERVER_PORT' => 80,
                ],
                [
                    'localhost',
                ],
            ],
            [
                [
                    'HTTPS'       => 'on',
                    'SERVER_NAME' => 'localhost',
                    'SERVER_PORT' => 443,
                ],
                [
                    'localhost',
                ],
            ],
            [
                [
                    'HTTP_HOST'   => '',
                    'SERVER_NAME' => '',
                    'SERVER_ADDR' => '8.8.8.8',
                ],
                [
                    '8.8.8.8',
                ],
            ],
            [
                [
                    'HTTP_HOST'   => '',
                    'SERVER_NAME' => 'some.domain',
                    'SERVER_ADDR' => '8.8.8.8',
                ],
                [
                    'some.domain',
                ],
            ],
            [
                [
                    'HTTP_HOST'   => 'example.com',
                    'SERVER_NAME' => 'some.domain',
                    'SERVER_ADDR' => '8.8.8.8',
                ],
                [
                    'example.com',
                ],
            ],
        ];
    }

    /**
     * @return array[]
     */
    public static function getExamplesInvalid(): array
    {
        return [
            ['foo±bar±baz'],
            ['foo~bar~baz'],
            ['<foo-bar-baz>'],
            ['foo=bar=baz'],
            ['foobar/baz'],
            ['foo@bar'],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-04
     */
    public function testHttpRequestHttpHost(array $server, array $data): void
    {
        $_SERVER = array_merge($_SERVER, $server);

        $request = new Request();

        foreach ($data as $expected) {
            $actual = $request->getHttpHost();
            $this->assertSame($expected, $actual);
        }
    }

    /**
     * @dataProvider getExamplesInvalid
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-06-26
     */
    public function testInvalidHttpRequestHttpHost(string $host): void
    {
        $_SERVER['HTTP_HOST'] = $host;

        $request = $this->getRequestObject();
        $request->setStrictHostCheck();

        $this->expectException(UnexpectedValueException::class);
        $this->expectExceptionMessage('Invalid host ' . $host);

        $request->getHttpHost();
    }
}
