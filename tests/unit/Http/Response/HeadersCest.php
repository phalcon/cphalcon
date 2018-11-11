<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Response;

use Phalcon\Http\Response\Headers;
use UnitTester;

class HeadersCest
{
    /**
     * Tests the instance of the object
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-05
     */
    public function testHttpResponseHeadersInstanceOf(UnitTester $I)
    {
        $headers = new Headers();
        $class   = Headers::class;
        $I->assertInstanceOf($class, $headers);
    }

    /**
     * Tests the get and set of the response headers
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-05
     */
    public function testHttpResponseHeadersGetSet(UnitTester $I)
    {
        $headers = new Headers();
        $headers->set('Content-Type', 'text/html');

        $expected = 'text/html';
        $actual   = $headers->get('Content-Type');

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests the has of the response headers
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2018-11-02
     */
    public function testHttpResponseHeadersHas(UnitTester $I)
    {
        $headers = new Headers();
        $headers->set('Content-Type', 'text/html');

        $actual = $headers->has('Content-Type');
        $I->assertTrue($actual);

        $actual = $headers->has('unknown-header');
        $I->assertFalse($actual);
    }

    /**
     * Tests the set of the response status headers
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/12895
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-06-17
     */
    public function shouldSetResponseStatusHeader(UnitTester $I)
    {
        $examples = [
            'Unprocessable Entity' => 422,
            'Moved Permanently'    => 301,
            'OK'                   => 200,
            'Service Unavailable'  => 503,
            'Not Found'            => 404,
            'Created'              => 201,
            'Continue'             => 100,
        ];

        foreach ($examples as $message => $code) {
            $headers = new Headers();
            $headers->set('Status', $code);

            $headers = $I->getProtectedProperty($headers, '_headers');

            $expected = 1;
            $actual   = count($headers);
            $I->assertEquals($expected, $actual);

            $actual = isset($headers['Status']);
            $I->assertTrue($actual);

            $expected = $code;
            $actual   = $headers['Status'];
            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests the get of the response status headers
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/12895
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-06-17
     */
    public function shouldGetResponseStatusHeader(UnitTester $I)
    {
        $examples = [
            'Unprocessable Entity' => 422,
            'Moved Permanently'    => 301,
            'OK'                   => 200,
            'Service Unavailable'  => 503,
            'Not Found'            => 404,
            'Created'              => 201,
            'Continue'             => 100,
        ];

        foreach ($examples as $message => $code) {
            $headers = new Headers();
            $I->setProtectedProperty($headers, '_headers', ['Status' => $code]);

            $expected = $code;
            $actual   = $headers->get('Status');
            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests resetting the response headers
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-05
     */
    public function testHttpResponseHeadersReset(UnitTester $I)
    {
        $headers = new Headers();
        $headers->set('Content-Type', 'text/html');
        $headers->reset();

        $actual = $headers->get('Content-Type');

        $I->assertEmpty($actual);
    }

    /**
     * Tests removing a response header
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-05
     */
    public function testHttpResponseHeadersRemove(UnitTester $I)
    {
        $headers = new Headers();
        $headers->set('Content-Type', 'text/html');
        $headers->remove('Content-Type');

        $actual = $headers->get('Content-Type');

        $I->assertEmpty($actual);
    }

    /**
     * Tests setting a raw response header
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-05
     */
    public function testHttpResponseHeadersRaw(UnitTester $I)
    {
        $headers = new Headers();
        $headers->setRaw('Content-Type: text/html');

        $actual = $headers->get('Content-Type: text/html');

        $I->assertEmpty($actual);
    }

    /**
     * Tests toArray in response headers
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-05
     */
    public function testHttpResponseHeadersToArray(UnitTester $I)
    {
        $headers = new Headers();
        $headers->set('Content-Type', 'text/html');

        $expected = $headers->toArray();
        $actual   = ['Content-Type' => 'text/html'];
        $I->assertEquals($expected, $actual);
    }
}
