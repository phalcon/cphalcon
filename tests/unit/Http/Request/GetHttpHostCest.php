<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Request;

use Codeception\Example;
use Phalcon\Test\Unit\Http\Helper\HttpBase;
use UnexpectedValueException;
use UnitTester;

class GetHttpHostCest extends HttpBase
{
    /**
     * Tests getHttpHost
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-04
     */
    public function testHttpRequestHttpHost(UnitTester $I)
    {
        $this->setServerVar('HTTP_HOST', '');
        $this->setServerVar('SERVER_NAME', '');
        $this->setServerVar('SERVER_ADDR', '');

        $request = $this->getRequestObject();

        $I->assertInternalType(
            'string',
            $request->getHttpHost()
        );

        $I->assertEquals(
            '',
            $request->getHttpHost()
        );


        $request = $this->getRequestObject();

        unset(
            $_SERVER['HTTP_HOST'],
            $_SERVER['SERVER_NAME'],
            $_SERVER['SERVER_ADDR']
        );

        $I->assertEquals(
            '',
            $request->getHttpHost()
        );

        $this->setServerVar('SERVER_NAME', 'host@name');

        $request = $this->getRequestObject();

        $I->assertEquals(
            'host@name',
            $request->getHttpHost()
        );


        $this->setServerVar('HTTPS', 'off');
        $this->setServerVar('SERVER_NAME', 'localhost');
        $this->setServerVar('SERVER_PORT', 80);

        $request = $this->getRequestObject();

        $I->assertEquals(
            'localhost',
            $request->getHttpHost()
        );


        $this->setServerVar('HTTPS', 'on');
        $this->setServerVar('SERVER_NAME', 'localhost');
        $this->setServerVar('SERVER_PORT', 80);

        $request = $this->getRequestObject();

        $I->assertEquals(
            'localhost',
            $request->getHttpHost()
        );


        $this->setServerVar('HTTPS', 'on');
        $this->setServerVar('SERVER_NAME', 'localhost');
        $this->setServerVar('SERVER_PORT', 443);

        $request = $this->getRequestObject();

        $I->assertEquals(
            'localhost',
            $request->getHttpHost()
        );


        $this->setServerVar('HTTP_HOST', '');
        $this->setServerVar('SERVER_NAME', '');
        $this->setServerVar('SERVER_ADDR', '8.8.8.8');

        $request = $this->getRequestObject();

        $I->assertEquals(
            '8.8.8.8',
            $request->getHttpHost()
        );

        $this->setServerVar('HTTP_HOST', '');
        $this->setServerVar('SERVER_NAME', 'some.domain');
        $this->setServerVar('SERVER_ADDR', '8.8.8.8');

        $request = $this->getRequestObject();

        $I->assertEquals(
            'some.domain',
            $request->getHttpHost()
        );

        $this->setServerVar('HTTP_HOST', 'example.com');
        $this->setServerVar('SERVER_NAME', 'some.domain');
        $this->setServerVar('SERVER_ADDR', '8.8.8.8');

        $request = $this->getRequestObject();

        $I->assertEquals(
            'example.com',
            $request->getHttpHost()
        );
    }

    /**
     * Tests getHttpHost by using invalid host
     *
     * @author       Phalcon Team <team@phalconphp.com>
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
