<?php

namespace Phalcon\Test\Unit\Http\Response;

use Phalcon\Test\Unit\Http\Helper\HttpBase;
use Phalcon\Test\Proxy\Http\Response\Headers;

/**
 * \Phalcon\Test\Unit\Http\Response\Http\HeadersTest
 * Tests the \Phalcon\Http\Response\Headers component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Http\Response
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class HeadersTest extends HttpBase
{
    /**
     * Tests the instance of the object
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-05
     */
    public function testHttpResponseHeadersInstanceOf()
    {
        $this->specify(
            "The new object is not the correct class",
            function () {
                $responseHeaders = new Headers();

                expect($responseHeaders instanceof Headers)->true();
            }
        );
    }

    /**
     * Tests the get and set of the response headers
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-05
     */
    public function testHttpResponseHeadersGetSet()
    {
        $this->specify(
            "Setting and Getting Response Headers is not correct",
            function () {
                $responseHeaders = new Headers();
                $responseHeaders->set('Content-Type', 'text/html');

                $expected = 'text/html';
                $actual   = $responseHeaders->get('Content-Type');

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests resetting the response headers
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-05
     */
    public function testHttpResponseHeadersReset()
    {
        $this->specify(
            "Resetting Response Headers is not correct",
            function () {
                $responseHeaders = new Headers();
                $responseHeaders->set('Content-Type', 'text/html');

                $responseHeaders->reset();

                $actual = $responseHeaders->get('Content-Type');

                expect($actual)->isEmpty();
            }
        );
    }

    /**
     * Tests removing a response header
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-05
     */
    public function testHttpResponseHeadersRemove()
    {
        $this->specify(
            "Removing Response Header is not correct",
            function () {
                $responseHeaders = new Headers();
                $responseHeaders->set('Content-Type', 'text/html');

                $responseHeaders->remove('Content-Type');

                $actual = $responseHeaders->get('Content-Type');

                expect($actual)->isEmpty();
            }
        );
    }

    /**
     * Tests setting a raw response header
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-05
     */
    public function testHttpResponseHeadersRaw()
    {
        $this->specify(
            "Setting a raw Response Header is not correct",
            function () {
                $responseHeaders = new Headers();
                $responseHeaders->setRaw('Content-Type: text/html');

                $actual = $responseHeaders->get('Content-Type: text/html');

                expect($actual)->isEmpty();
            }
        );
    }

    /**
     * Tests toArray in response headers
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-05
     */
    public function testHttpResponseHeadersToArray()
    {
        $this->specify(
            "toArray in Response Headers is not correct",
            function () {
                $responseHeaders = new Headers();
                $responseHeaders->set('Content-Type', 'text/html');

                $expected = $responseHeaders->toArray();
                $actual   = ['Content-Type' => 'text/html'];

                expect($actual)->equals($expected);
            }
        );
    }
}
