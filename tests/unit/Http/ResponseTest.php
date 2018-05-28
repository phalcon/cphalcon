<?php

namespace Phalcon\Test\Unit\Http;

use Phalcon\Test\Unit\Http\Helper\HttpBase;
use Phalcon\Http\Response;
use Phalcon\Http\Response\Headers;

/**
 * \Phalcon\Test\Unit\Http\ResponseTest
 * Tests the \Phalcon\Http\Response component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @author    Zamrony P. Juhara <zamronypj@yahoo.com>
 * @package   Phalcon\Test\Unit\Http
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class ResponseTest extends HttpBase
{
    /**
     * Tests the instance of the object
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-05
     */
    public function testHttpResponseInstanceOf()
    {
        $this->specify(
            "The new object is not the correct class",
            function () {
                $response = $this->getResponseObject();

                expect($response instanceof Response)->true();
            }
        );
    }

    /**
     * Tests the setHeader
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-08
     */
    public function testHttpResponseSetHeader()
    {
        $this->specify(
            "setHeader is not setting the headers properly",
            function () {
                $response = $this->getResponseObject();
                $response->resetHeaders();
                $response->setHeader('Content-Type', 'text/html');
                $expected = Headers::__set_state(
                    [
                        '_headers' => ['Content-Type' => 'text/html']
                    ]
                );
                expect($response->getHeaders())->equals($expected);

                $response->setHeader('Content-Length', '1234');
                $expected = Headers::__set_state(
                    [
                        '_headers' => [
                            'Content-Type'   => 'text/html',
                            'Content-Length' => '1234'
                        ]
                    ]
                );
                expect($response->getHeaders())->equals($expected);
            }
        );
    }

    /**
     * Tests the setStatusCode
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-08
     */
    public function testHttpResponseSetStatusCode()
    {
        $this->specify(
            "setStatusCode is not setting the header status properly",
            function () {
                $response = $this->getResponseObject();
                $response->resetHeaders();
                $response->setStatusCode(404, "Not Found");

                $expected = Headers::__set_state(
                    [
                        '_headers' => [
                            'HTTP/1.1 404 Not Found' => '',
                            'Status'                 => '404 Not Found'
                        ]
                    ]
                );
                expect($response->getHeaders())->equals($expected);
            }
        );
    }

    /**
     * Tests the Multiple Status Codes
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/1892
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testMultipleHttpHeaders()
    {
        $this->specify(
            "setStatusCode is not setting the header status properly",
            function () {
                $response = $this->getResponseObject();
                $response->resetHeaders();
                $response->setStatusCode(200, 'OK');
                $response->setStatusCode(404, 'Not Found');
                $response->setStatusCode(409, 'Conflict');

                $expected = Headers::__set_state(
                    [
                        '_headers' => [
                            'HTTP/1.1 409 Conflict' => '',
                            'Status'                 => '409 Conflict'
                        ]
                    ]
                );

                expect($response->getHeaders())->equals($expected);
            }
        );
    }

    public function testSetStatusCodeDefaultMessage()
    {
        $this->specify(
            "setStatusCode is not setting the header status properly",
            function () {
                $response = $this->getResponseObject();
                $response->resetHeaders();

                $response->setStatusCode(103);
                $expected = Headers::__set_state(
                    [
                        '_headers' => [
                            'HTTP/1.1 103 Early Hints' => '',
                            'Status'                   => '103 Early Hints'
                        ]
                    ]
                );

                expect($response->getHeaders())->equals($expected);

                $response->setStatusCode(200);
                $expected = Headers::__set_state(
                    [
                        '_headers' => [
                            'HTTP/1.1 200 OK' => '',
                            'Status'          => '200 OK'
                        ]
                    ]
                );

                expect($response->getHeaders())->equals($expected);

                $response->setStatusCode(418);
                $expected = Headers::__set_state(
                    [
                        '_headers' => [
                            "HTTP/1.1 418 I'm a teapot" => '',
                            'Status'                    => "418 I'm a teapot"
                        ]
                    ]
                );

                expect($response->getHeaders())->equals($expected);

                $response->setStatusCode(418, 'My own message');
                $expected = Headers::__set_state(
                    [
                        '_headers' => [
                            "HTTP/1.1 418 My own message" => '',
                            'Status'                      => "418 My own message"
                        ]
                    ]
                );

                expect($response->getHeaders())->equals($expected);
            }
        );
    }

    /**
     * Tests the setRawHeader
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-08
     */
    public function testHttpResponseSetRawHeader()
    {
        $this->specify(
            "setRawHeader is not setting the raw header properly",
            function () {
                $response = $this->getResponseObject();
                $response->resetHeaders();
                $response->setRawHeader("HTTP/1.1 404 Not Found");

                $expected = Headers::__set_state(
                    [
                        '_headers' => ['HTTP/1.1 404 Not Found' => '']
                    ]
                );
                expect($response->getHeaders())->equals($expected);
            }
        );
    }

    /**
     * Tests the setHeader
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-08
     */
    public function testHttpResponseSetHeaderContentType()
    {
        $this->specify(
            "setRawHeader is not setting the raw header properly",
            function () {
                $response = $this->getResponseObject();
                $response->resetHeaders();
                $response->setHeader('Content-Type', 'text/html');
                $response->setHeader('Content-Length', '1234');
                $headers = $response->getHeaders()->toArray();

                $this->assertArrayHasKey('Content-Type', $headers);
                $this->assertArrayHasKey('Content-Length', $headers);

                expect($headers['Content-Type'])->equals('text/html');
                expect($headers['Content-Length'])->equals('1234');
            }
        );
    }

    /**
     * Tests the setContentType
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-08
     */
    public function testHttpResponseSetContentType()
    {
        $this->specify(
            "setContentType is not setting the header properly",
            function () {
                $response = $this->getResponseObject();
                $response->resetHeaders();
                $response->setContentType('application/json');

                $expected = Headers::__set_state(
                    [
                        '_headers' => ['Content-Type' => 'application/json']
                    ]
                );
                expect($response->getHeaders())->equals($expected);
            }
        );
    }

    /**
     * Tests the setContentLength
     *
     * @author Zamrony P. Juhara <zamronypj@yahoo.com>
     * @since  2016-07-18
     */
    public function testHttpResponseSetContentLength()
    {
        $this->specify(
            "setContentLength is not setting the header properly",
            function () {
                $response = $this->getResponseObject();
                $response->resetHeaders();
                $response->setContentLength(100);

                $expected = Headers::__set_state(
                    [
                        '_headers' => ['Content-Length' => 100]
                    ]
                );
                expect($response->getHeaders())->equals($expected);
            }
        );
    }

    /**
     * Tests the setContentType with charset
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-08
     */
    public function testHttpResponseSetContentTypeWithCharset()
    {
        $this->specify(
            "setContentType with charset is not setting the header properly",
            function () {
                $response = $this->getResponseObject();
                $response->resetHeaders();
                $response->setContentType('application/json', 'utf-8');

                $expected = Headers::__set_state(
                    [
                        '_headers' => [
                            'Content-Type' => 'application/json; charset=utf-8'
                        ]
                    ]
                );
                expect($response->getHeaders())->equals($expected);
            }
        );
    }

    /**
     * Tests setNotModified
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-08
     */
    public function testHttpResponseSetNotModified()
    {
        $this->specify(
            "setNotModified is not setting the header properly",
            function () {
                $response = $this->getResponseObject();
                $response->resetHeaders();
                $response->setNotModified();

                $expected = Headers::__set_state(
                    [
                        '_headers' => [
                            'HTTP/1.1 304 Not modified' => false,
                            'Status'                    => '304 Not modified'
                        ]
                    ]
                );
                expect($response->getHeaders())->equals($expected);
            }
        );
    }

    /**
     * Tests redirect locally
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-08
     */
    public function testHttpResponseRedirectLocalUrl()
    {
        $this->specify(
            "redirect is not redirecting local properly",
            function () {
                $response = $this->getResponseObject();
                $response->resetHeaders();
                $response->redirect("some/local/uri");

                $expected = Headers::__set_state(
                    [
                        '_headers' => [
                            'Status'                => '302 Found',
                            'Location'              => '/some/local/uri',
                            'HTTP/1.1 302 Found' => null,
                        ]
                    ]
                );
                expect($response->getHeaders())->equals($expected);
            }
        );
    }

    /**
     * Tests redirect remotely 302
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-08
     */
    public function testHttpResponseRedirectRemoteUrl302()
    {
        $this->specify(
            "redirect is not redirecting remote 302 properly",
            function () {
                $response = $this->getResponseObject();
                $response->resetHeaders();
                $response->redirect("http://google.com", true);

                $expected = Headers::__set_state(
                    [
                        '_headers' => [
                            'Status'             => '302 Found',
                            'Location'           => 'http://google.com',
                            'HTTP/1.1 302 Found' => null,
                        ]
                    ]
                );
                expect($response->getHeaders())->equals($expected);
            }
        );
    }

    /**
     * Tests redirect local with non standard code
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/11324
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-19
     */
    public function testHttpResponseRedirectLocalUrlWithNonStandardCode()
    {
        $this->specify(
            "redirect is not redirecting local with non standard code properly",
            function () {
                $response = $this->getResponseObject();
                $response->resetHeaders();
                $response->redirect('new/place/', false, 309);

                $expected = Headers::__set_state(
                    [
                        '_headers' => [
                            'Status'             => '302 Found',
                            'Location'           => '/new/place/',
                            'HTTP/1.1 302 Found' => null,
                        ]
                    ]
                );
                expect($response->getHeaders())->equals($expected);
            }
        );
    }

    /**
     * Tests redirect remotely 301
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/1182
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-08
     */
    public function testHttpResponseRedirectRemoteUrl301()
    {
        $this->specify(
            "redirect is not redirecting remote 301 properly",
            function () {
                $response = $this->getResponseObject();
                $response->resetHeaders();
                $response->redirect("http://google.com", true, 301);

                $expected = Headers::__set_state(
                    [
                        '_headers' => [
                            'Status'                         => '301 Moved Permanently',
                            'Location'                       => 'http://google.com',
                            'HTTP/1.1 301 Moved Permanently' => null,
                        ]
                    ]
                );
                expect($response->getHeaders())->equals($expected);
            }
        );
    }

    /**
     * Tests setContent
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-08
     */
    public function testHttpResponseSetContent()
    {
        $this->specify(
            "setContent is not producing the correct results",
            function () {
                $response = $this->getResponseObject();
                $response->setContent('<h1>Hello');

                expect($response->getContent())->equals('<h1>Hello');
            }
        );
    }

    /**
     * Tests appendContent
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-08
     */
    public function testHttpResponseAppendContent()
    {
        $this->specify(
            "appendContent is not producing the correct results",
            function () {
                $response = $this->getResponseObject();
                $response->setContent('<h1>Hello');
                $response->appendContent('</h1>');

                expect($response->getContent())->equals('<h1>Hello</h1>');
            }
        );
    }

    /**
     * Tests setFileToSend
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-08
     */
    public function testHttpResponseSetFileToSend()
    {
        $this->specify(
            "setFileToSend is not producing the correct results",
            function () {
                $response = $this->getResponseObject();

                $filename = __FILE__;
                $response->setFileToSend($filename);

                ob_start();
                $response->send();
                $actual = ob_get_clean();

                expect($actual)->equals(file_get_contents($filename));
                expect($response->isSent())->true();
            }
        );
    }

    /**
     * Tests setCache
     *
     * @author Sid Roberts <sid@sidroberts.co.uk>
     * @since  2015-07-14
     */
    public function testHttpResponseSetCache()
    {
        $this->specify(
            "setCache is not producing the correct results",
            function () {
                $response = $this->getResponseObject();

                $expiry = new \DateTime();
                $expiry->setTimezone(new \DateTimeZone("UTC"));
                $expiry->modify("+60 minutes");

                $response->setCache(60);

                $expected = Headers::__set_state(
                    [
                        '_headers' => [
                            "Expires"       => $expiry->format("D, d M Y H:i:s") . " GMT",
                            "Cache-Control" => "max-age=3600"
                        ]
                    ]
                );
                expect($response->getHeaders())->equals($expected);
            }
        );
    }

    /**
     * Test the removeHeader
     *
     * @author Mohamad Rostami <mb.rostami.h@gmail.com>
     */
    public function testHttpResponseRemoveHeaderContentType()
    {
        $this->specify(
            "removeHeader is not removing the header properly",
            function () {
                $response = $this->getResponseObject();
                $response->resetHeaders();
                $response->setHeader('Content-Type', 'text/html');
                $headers = $response->getHeaders()->toArray();

                $this->assertArrayHasKey('Content-Type', $headers);
                expect($headers['Content-Type'])->equals('text/html');

                $response->removeHeader('Content-Type');

                $headers = $response->getHeaders()->toArray();
                $this->assertArrayNotHasKey('Content-Type', $headers);
            }
        );
    }
}
