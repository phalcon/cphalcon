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

namespace Phalcon\Test\Unit\Http\Request;

use Codeception\Example;
use Phalcon\Http\Request;
use Phalcon\Test\Unit\Http\Helper\HttpBase;
use UnexpectedValueException;
use UnitTester;

class GetHttpHostCest extends HttpBase
{
    /**
     * Tests getHttpHost
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2014-10-04
     *
     * @dataProvider getExamples
     */
    public function testHttpRequestHttpHost(UnitTester $I, Example $example)
    {
        $I->wantToTest('Http\Request - getHttpHost()');

        $store   = $_SERVER ?? [];
        $_SERVER = $example[0];

        $request = new Request();

        foreach ($example[1] as $expected) {
            $I->assertEquals($expected, $request->getHttpHost());
        }

        $_SERVER = $store;
    }

    /**
     * Tests getHttpHost by using invalid host
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2016-06-26
     *
     * @dataProvider testInvalidHttpRequestHttpHostProvider
     */
    public function testInvalidHttpRequestHttpHost(UnitTester $I, Example $example)
    {
        $host = $example[0];

        $request = $this->getRequestObject();

        $request->setStrictHostCheck(true);

        $this->setServerVar('HTTP_HOST', $host);

        $I->expectThrowable(
            new UnexpectedValueException('Invalid host ' . $host),
            function () use ($request) {
                $request->getHttpHost();
            }
        );
    }

    private function getExamples(): array
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
     * @return array|string[]
     */
    private function testInvalidHttpRequestHttpHostProvider(): array
    {
        return [
            [
                'foo±bar±baz',
            ],

            [
                'foo~bar~baz',
            ],

            [
                '<foo-bar-baz>',
            ],

            [
                'foo=bar=baz',
            ],

            [
                'foobar/baz',
            ],

            [
                'foo@bar',
            ],
        ];
    }
}
