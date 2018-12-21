<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http;

use Phalcon\Http\Response;
use Phalcon\Http\Response\Headers;
use Phalcon\Test\Unit\Http\Helper\HttpBase;
use UnitTester;

class ResponseCest extends HttpBase
{
    /**
     * Tests the instance of the object
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-05
     */
    public function testHttpResponseInstanceOf(UnitTester $I)
    {
        $response = $this->getResponseObject();

        $class = Response::class;
        $I->assertInstanceOf($class, $response);
    }

    /**
     * Tests the setHeader
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-08
     */
    public function testHttpResponseSetHeader(UnitTester $I)
    {
        $response = $this->getResponseObject();
        $response->resetHeaders();
        $response->setHeader('Content-Type', 'text/html');
        $expected = Headers::__set_state(
            [
                '_headers' => ['Content-Type' => 'text/html'],
            ]
        );
        $actual   = $response->getHeaders();
        $I->assertEquals($expected, $actual);

        $response->setHeader('Content-Length', '1234');
        $expected = Headers::__set_state(
            [
                '_headers' => [
                    'Content-Type'   => 'text/html',
                    'Content-Length' => '1234',
                ],
            ]
        );
        $actual   = $response->getHeaders();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests the hasHeader
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-08
     */
    public function testHttpResponseHasHeader(UnitTester $I)
    {
        $response = $this->getResponseObject();
        $response->resetHeaders();
        $response->setHeader('Content-Type', 'text/html');

        $actual = $response->hasHeader('Content-Type');
        $I->assertTrue($actual);

        $actual = $response->hasHeader('some-unknown-header');
        $I->assertFalse($actual);
    }

    /**
     * Tests the setStatusCode
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-08
     */
    public function testHttpResponseSetStatusCode(UnitTester $I)
    {
        $response = $this->getResponseObject();
        $response->resetHeaders();
        $response->setStatusCode(404, "Not Found");
        $expected = Headers::__set_state(
            [
                '_headers' => [
                    'HTTP/1.1 404 Not Found' => '',
                    'Status'                 => '404 Not Found',
                ],
            ]
        );
        $actual   = $response->getHeaders();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests the Multiple Status Codes
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/1892
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testMultipleHttpHeaders(UnitTester $I)
    {
        $response = $this->getResponseObject();
        $response->resetHeaders();
        $response->setStatusCode(200, 'OK');
        $response->setStatusCode(404, 'Not Found');
        $response->setStatusCode(409, 'Conflict');

        $expected = Headers::__set_state(
            [
                '_headers' => [
                    'HTTP/1.1 409 Conflict' => '',
                    'Status'                => '409 Conflict',
                ],
            ]
        );
        $actual   = $response->getHeaders();
        $I->assertEquals($expected, $actual);
    }

    public function testSetStatusCodeDefaultMessage(UnitTester $I)
    {
        $response = $this->getResponseObject();
        $response->resetHeaders();

        $response->setStatusCode(103);
        $expected = Headers::__set_state(
            [
                '_headers' => [
                    'HTTP/1.1 103 Early Hints' => '',
                    'Status'                   => '103 Early Hints',
                ],
            ]
        );
        $actual   = $response->getHeaders();
        $I->assertEquals($expected, $actual);

        $response->setStatusCode(200);
        $expected = Headers::__set_state(
            [
                '_headers' => [
                    'HTTP/1.1 200 OK' => '',
                    'Status'          => '200 OK',
                ],
            ]
        );
        $actual   = $response->getHeaders();
        $I->assertEquals($expected, $actual);

        $response->setStatusCode(418);
        $expected = Headers::__set_state(
            [
                '_headers' => [
                    "HTTP/1.1 418 I'm a teapot" => '',
                    'Status'                    => "418 I'm a teapot",
                ],
            ]
        );
        $actual   = $response->getHeaders();
        $I->assertEquals($expected, $actual);

        $response->setStatusCode(418, 'My own message');
        $expected = Headers::__set_state(
            [
                '_headers' => [
                    "HTTP/1.1 418 My own message" => '',
                    'Status'                      => "418 My own message",
                ],
            ]
        );
        $actual   = $response->getHeaders();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests the setRawHeader
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-08
     */
    public function testHttpResponseSetRawHeader(UnitTester $I)
    {
        $response = $this->getResponseObject();
        $response->resetHeaders();
        $response->setRawHeader("HTTP/1.1 404 Not Found");

        $expected = Headers::__set_state(
            [
                '_headers' => ['HTTP/1.1 404 Not Found' => ''],
            ]
        );
        $actual   = $response->getHeaders();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests the setHeader
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-08
     */
    public function testHttpResponseSetHeaderContentType(UnitTester $I)
    {
        $response = $this->getResponseObject();
        $response->resetHeaders();
        $response->setHeader('Content-Type', 'text/html');
        $response->setHeader('Content-Length', '1234');
        $headers = $response->getHeaders()->toArray();

        $I->assertArrayHasKey('Content-Type', $headers);
        $I->assertArrayHasKey('Content-Length', $headers);

        $expected = 'text/html';
        $actual   = $headers['Content-Type'];
        $I->assertEquals($expected, $actual);

        $expected = '1234';
        $actual   = $headers['Content-Length'];
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests the setContentType
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-08
     */
    public function testHttpResponseSetContentType(UnitTester $I)
    {
        $response = $this->getResponseObject();
        $response->resetHeaders();
        $response->setContentType('application/json');

        $expected = Headers::__set_state(
            [
                '_headers' => ['Content-Type' => 'application/json'],
            ]
        );
        $actual   = $response->getHeaders();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests the setContentLength
     *
     * @author Zamrony P. Juhara <zamronypj@yahoo.com>
     * @since  2016-07-18
     */
    public function testHttpResponseSetContentLength(UnitTester $I)
    {
        $response = $this->getResponseObject();
        $response->resetHeaders();
        $response->setContentLength(100);

        $expected = Headers::__set_state(
            [
                '_headers' => ['Content-Length' => 100],
            ]
        );
        $actual   = $response->getHeaders();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests the setContentType with charset
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-08
     */
    public function testHttpResponseSetContentTypeWithCharset(UnitTester $I)
    {
        $response = $this->getResponseObject();
        $response->resetHeaders();
        $response->setContentType('application/json', 'utf-8');

        $expected = Headers::__set_state(
            [
                '_headers' => [
                    'Content-Type' => 'application/json; charset=utf-8',
                ],
            ]
        );
        $actual   = $response->getHeaders();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests setNotModified
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-08
     */
    public function testHttpResponseSetNotModified(UnitTester $I)
    {
        $response = $this->getResponseObject();
        $response->resetHeaders();
        $response->setNotModified();

        $expected = Headers::__set_state(
            [
                '_headers' => [
                    'HTTP/1.1 304 Not modified' => false,
                    'Status'                    => '304 Not modified',
                ],
            ]
        );
        $actual   = $response->getHeaders();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests redirect locally
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-08
     */
    public function testHttpResponseRedirectLocalUrl(UnitTester $I)
    {
        $response = $this->getResponseObject();
        $response->resetHeaders();
        $response->redirect("some/local/uri");

        $expected = Headers::__set_state(
            [
                '_headers' => [
                    'Status'             => '302 Found',
                    'Location'           => '/some/local/uri',
                    'HTTP/1.1 302 Found' => null,
                ],
            ]
        );
        $actual   = $response->getHeaders();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests redirect remotely 302
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-08
     */
    public function testHttpResponseRedirectRemoteUrl302(UnitTester $I)
    {
        $response = $this->getResponseObject();
        $response->resetHeaders();
        $response->redirect("http://google.com", true);

        $expected = Headers::__set_state(
            [
                '_headers' => [
                    'Status'             => '302 Found',
                    'Location'           => 'http://google.com',
                    'HTTP/1.1 302 Found' => null,
                ],
            ]
        );
        $actual   = $response->getHeaders();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests redirect local with non standard code
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/11324
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-19
     */
    public function testHttpResponseRedirectLocalUrlWithNonStandardCode(UnitTester $I)
    {
        $response = $this->getResponseObject();
        $response->resetHeaders();
        $response->redirect('new/place/', false, 309);

        $expected = Headers::__set_state(
            [
                '_headers' => [
                    'Status'             => '302 Found',
                    'Location'           => '/new/place/',
                    'HTTP/1.1 302 Found' => null,
                ],
            ]
        );
        $actual   = $response->getHeaders();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests redirect remotely 301
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/1182
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-08
     */
    public function testHttpResponseRedirectRemoteUrl301(UnitTester $I)
    {
        $response = $this->getResponseObject();
        $response->resetHeaders();
        $response->redirect("http://google.com", true, 301);

        $expected = Headers::__set_state(
            [
                '_headers' => [
                    'Status'                         => '301 Moved Permanently',
                    'Location'                       => 'http://google.com',
                    'HTTP/1.1 301 Moved Permanently' => null,
                ],
            ]
        );
        $actual   = $response->getHeaders();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests setContent
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-08
     */
    public function testHttpResponseSetContent(UnitTester $I)
    {
        $response = $this->getResponseObject();
        $response->setContent('<h1>Hello');

        $expected = '<h1>Hello';
        $actual   = $response->getContent();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests appendContent
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-08
     */
    public function testHttpResponseAppendContent(UnitTester $I)
    {
        $response = $this->getResponseObject();
        $response->setContent('<h1>Hello');
        $response->appendContent('</h1>');

        $expected = '<h1>Hello</h1>';
        $actual   = $response->getContent();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests setFileToSend
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-08
     */
    public function testHttpResponseSetFileToSend(UnitTester $I)
    {
        $response = $this->getResponseObject();

        $filename = __FILE__;
        $response->setFileToSend($filename);

        ob_start();
        $response->send();

        $expected = file_get_contents($filename);
        $actual   = ob_get_clean();
        $I->assertEquals($expected, $actual);

        $actual = $response->isSent();
        $I->assertTrue($actual);
    }

    /**
     * Tests setCache
     *
     * @author Sid Roberts <sid@sidroberts.co.uk>
     * @since  2015-07-14
     */
    public function testHttpResponseSetCache(UnitTester $I)
    {
        $response = $this->getResponseObject();

        $expiry = new \DateTime();
        $expiry->setTimezone(new \DateTimeZone("UTC"));
        $expiry->modify("+60 minutes");

        $response->setCache(60);

        $expected = Headers::__set_state(
            [
                '_headers' => [
                    "Expires"       => $expiry->format("D, d M Y H:i:s") . " GMT",
                    "Cache-Control" => "max-age=3600",
                ],
            ]
        );
        $actual   = $response->getHeaders();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Test the removeHeader
     *
     * @author Mohamad Rostami <mb.rostami.h@gmail.com>
     */
    public function testHttpResponseRemoveHeaderContentType(UnitTester $I)
    {
        $response = $this->getResponseObject();
        $response->resetHeaders();
        $response->setHeader('Content-Type', 'text/html');
        $headers = $response->getHeaders()->toArray();

        $I->assertArrayHasKey('Content-Type', $headers);

        $expected = 'text/html';
        $actual   = $headers['Content-Type'];
        $I->assertEquals($expected, $actual);

        $response->removeHeader('Content-Type');

        $headers = $response->getHeaders()->toArray();
        $I->assertArrayNotHasKey('Content-Type', $headers);
    }
}
