<?php
/**
 * HttpResponseTest.php
 * \Phalcon\Http\Request\HttpResponseTest
 *
 * Tests the Phalcon\Http\Response component
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Tests\unit\Phalcon\Http;

use \Phalcon\Http\Response\Headers as PhResponseHeaders;

class HttpResponseTest extends Helper\HttpBase
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

                expect($response instanceof \PhalconTest\Http\Response)->true();
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

                $actual = $response->getHeaders();
                $expected = PhResponseHeaders::__set_state(
                    [
                        '_headers' => ['Content-Type' => 'text/html']
                    ]
                );
                expect($actual)->equals($expected);

                $response->setHeader('Content-Length', '1234');
                $actual = $response->getHeaders();
                $expected = PhResponseHeaders::__set_state(
                    [
                        '_headers' => [
                            'Content-Type'   => 'text/html',
                            'Content-Length' => '1234'
                        ]
                    ]
                );
                expect($actual)->equals($expected);
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

                $actual = $response->getHeaders();
                $expected = PhResponseHeaders::__set_state(
                    [
                        '_headers' => [
                            'HTTP/1.1 404 Not Found' => '',
                            'Status'                 => '404 Not Found'
                        ]
                    ]
                );
                expect($actual)->equals($expected);
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

                $actual   = $response->getHeaders();
                $expected = PhResponseHeaders::__set_state(
                    [
                        '_headers' => ['HTTP/1.1 404 Not Found' => '']
                    ]
                );
                expect($actual)->equals($expected);
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

                $actual = $response->getHeaders();
                $expected = PhResponseHeaders::__set_state(
                    [
                        '_headers' => ['Content-Type' => 'application/json']
                    ]
                );
                expect($actual)->equals($expected);
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

                $actual = $response->getHeaders();
                $expected = PhResponseHeaders::__set_state(
                    [
                        '_headers' => [
                            'Content-Type' => 'application/json; charset=utf-8'
                        ]
                    ]
                );
                expect($actual)->equals($expected);
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

                $actual = $response->getHeaders();
                $expected = PhResponseHeaders::__set_state(
                    [
                        '_headers' => [
                            'HTTP/1.1 304 Not modified' => false,
                            'Status'                    => '304 Not modified'
                        ]
                    ]
                );
                expect($actual)->equals($expected);
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

                $actual   = $response->getHeaders();
                $expected = PhResponseHeaders::__set_state(
                    [
                        '_headers' => [
                            'Status'                => '302 Found',
                            'Location'              => '/some/local/uri',
                            'HTTP/1.1 302 Found' => null,
                        ]
                    ]
                );
                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests redirect remotely 302
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-08
     */
    public function testHttpResponseRedirectRemoteLUrl302()
    {
        $this->specify(
            "redirect is not redirecting remote 302 properly",
            function () {

                $response = $this->getResponseObject();

                $response->resetHeaders();
                $response->redirect("http://google.com", true);

                $actual   = $response->getHeaders();
                $expected = PhResponseHeaders::__set_state(
                    [
                        '_headers' => [
                            'Status'             => '302 Found',
                            'Location'           => 'http://google.com',
                            'HTTP/1.1 302 Found' => null,
                        ]
                    ]
                );
                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests redirect remotely 301
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-08
     */
    public function testHttpResponseRedirectRemoteLUrl301()
    {
        $this->specify(
            "redirect is not redirecting remote 301 properly",
            function () {

                $response = $this->getResponseObject();

                $response->resetHeaders();
                $response->redirect("http://google.com", true, 301);

                $actual   = $response->getHeaders();
                $expected = PhResponseHeaders::__set_state(
                    [
                        '_headers' => [
                            'Status'                         => '301 Moved Permanently',
                            'Location'                       => 'http://google.com',
                            'HTTP/1.1 301 Moved Permanently' => null,
                        ]
                    ]
                );
                expect($actual)->equals($expected);
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

                $actual   = $response->getContent();
                $expected = '<h1>Hello';

                expect($actual)->equals($expected);
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

                $actual   = $response->getContent();
                $expected = '<h1>Hello</h1>';

                expect($actual)->equals($expected);
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
                $actual   = ob_get_clean();
                $expected = file_get_contents($filename);

                expect($actual)->equals($expected);
                expect($response->isSent())->true();
            }
        );
    }
}
