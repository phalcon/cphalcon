<?php

namespace Phalcon\Test\Unit\Http\Request;

use Phalcon\Di;
use Phalcon\Filter;
use Phalcon\Http\Request;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Http\Request\AuthHeaderTest
 * Tests the \Phalcon\Http\Request component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Http\Request
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class AuthHeaderTest extends UnitTest
{
    /**
     * @var Request
     */
    protected $request;

    /**
     * executed before each test
     */
    public function _before()
    {
        $di = new Di();

        $di->set('filter', function () {
            return new Filter();
        });

        $this->request = new Request();
        $this->request->setDI($di);
    }

    /**
     * Tests basic auth headers
     *
     * @test
     * @issue  12480
     * @author Serghei Iakovelv <serghei@phalconphp.com>
     * @since  2016-12-18
     */
    public function shouldCorrectHandleAuth()
    {
        $this->specify(
            'The request object handles auth headers incorrectly',
            function ($server, $expected) {
                $_SERVER = $server;

                $headers = $this->request->getHeaders();

                ksort($headers);
                ksort($expected);

                expect($headers)->equals($expected);
            },
            ['examples' => $this->basicAuthProvider()]
        );
    }

    /** @test */
    public function shouldGetAuthFromHeaders()
    {
        $this->specify(
            "Request does not handle auth correctly",
            function ($server, $function, $expected) {
                $_SERVER = $server;

                expect($this->request->$function())->equals($expected);
            },
            ['examples' => $this->authProvider()]
        );
    }

    protected function basicAuthProvider()
    {
        return [
            // Basic Auth
            [
                [
                    'PHP_AUTH_USER' => 'phalcon',
                    'PHP_AUTH_PW'   => 'secret',
                ],
                [
                    'Php-Auth-User' => 'phalcon',
                    'Php-Auth-Pw'   => 'secret',
                    'Authorization' => 'Basic cGhhbGNvbjpzZWNyZXQ=',
                ],
            ],
            // Basic Auth without name
            [
                [
                    'PHP_AUTH_PW'   => 'secret',
                ],
                [
                ],
            ],
            // Basic Auth without password
            [
                [
                    'PHP_AUTH_USER' => 'phalcon',
                ],
                [
                ],
            ],
            // Workaround for missing Authorization header under CGI/FastCGI Apache (.htaccess):
            // RewriteEngine on
            // RewriteRule .* - [env=HTTP_AUTHORIZATION:%{HTTP:Authorization},last]
            [
                [
                    'HTTP_AUTHORIZATION' => 'Basic cGhhbGNvbjpzZWNyZXQ=',
                ],
                [
                    'Php-Auth-User' => 'phalcon',
                    'Php-Auth-Pw'   => 'secret',
                    'Authorization' => 'Basic cGhhbGNvbjpzZWNyZXQ=',
                ],
            ],
            // Invalid Basic Auth by using CGI/FastCGI
            [
                [
                    'HTTP_AUTHORIZATION' => 'Basic 12345678',
                ],
                [
                    'Authorization' => 'Basic 12345678',
                ],
            ],
            // Digest Auth
            [
                [
                    'HTTP_AUTHORIZATION' => 'Digest username="myleft", realm="myleft", qop="auth", algorithm="MD5", uri="http://localhost:81/", nonce="nonce", nc=nc, cnonce="cnonce", opaque="opaque", response="response"',
                ],
                [
                    'Authorization' => 'Digest username="myleft", realm="myleft", qop="auth", algorithm="MD5", uri="http://localhost:81/", nonce="nonce", nc=nc, cnonce="cnonce", opaque="opaque", response="response"',
                    'Php-Auth-Digest' => 'Digest username="myleft", realm="myleft", qop="auth", algorithm="MD5", uri="http://localhost:81/", nonce="nonce", nc=nc, cnonce="cnonce", opaque="opaque", response="response"',
                ],
            ],
            // Digest Auth with REDIRECT_HTTP_AUTHORIZATION
            [
                [
                    'REDIRECT_HTTP_AUTHORIZATION' => 'Digest username="myleft", realm="myleft", qop="auth", algorithm="MD5", uri="http://localhost:81/", nonce="nonce", nc=nc, cnonce="cnonce", opaque="opaque", response="response"',
                ],
                [
                    'Authorization' => 'Digest username="myleft", realm="myleft", qop="auth", algorithm="MD5", uri="http://localhost:81/", nonce="nonce", nc=nc, cnonce="cnonce", opaque="opaque", response="response"',
                    'Php-Auth-Digest' => 'Digest username="myleft", realm="myleft", qop="auth", algorithm="MD5", uri="http://localhost:81/", nonce="nonce", nc=nc, cnonce="cnonce", opaque="opaque", response="response"',
                ],
            ],
            // Bearer Auth
            [
                [
                    'HTTP_AUTHORIZATION' => 'Bearer some-secret-token-here',
                ],
                [
                    'Authorization' => 'Bearer some-secret-token-here',
                ],
            ],
            // Bearer Auth with REDIRECT_HTTP_AUTHORIZATION
            [
                [
                    'REDIRECT_HTTP_AUTHORIZATION' => 'Bearer some-secret-token-here',
                ],
                [
                    'Authorization' => 'Bearer some-secret-token-here',
                ],
            ],
        ];
    }

    protected function authProvider()
    {
        return [
            [
                [
                    'PHP_AUTH_USER' => 'myleft',
                    'PHP_AUTH_PW'   => '123456'
                ],
                'getBasicAuth',
                [
                    'username' => 'myleft', 'password' => '123456'
                ]
            ],
            [
                [
                    'PHP_AUTH_DIGEST' => 'Digest username="myleft", realm="myleft", qop="auth", algorithm="MD5", uri="http://localhost:81/", nonce="nonce", nc=nc, cnonce="cnonce", opaque="opaque", response="response"'
                ],
                'getDigestAuth',
                [
                    'username'  => 'myleft',
                    'realm'     => 'myleft',
                    'qop'       => 'auth',
                    'algorithm' => 'MD5',
                    'uri'       => 'http://localhost:81/',
                    'nonce'     => 'nonce',
                    'nc'        => 'nc',
                    'cnonce'    => 'cnonce',
                    'opaque'    => 'opaque',
                    'response'  => 'response',
                ]
            ],
            [
                [
                    'PHP_AUTH_DIGEST' => 'Digest username=myleft, realm=myleft, qop=auth, algorithm=MD5, uri=http://localhost:81/, nonce=nonce, nc=nc, cnonce=cnonce, opaque=opaque, response=response'
                ],
                'getDigestAuth',
                [
                    'username'  => 'myleft',
                    'realm'     => 'myleft',
                    'qop'       => 'auth',
                    'algorithm' => 'MD5',
                    'uri'       => 'http://localhost:81/',
                    'nonce'     => 'nonce',
                    'nc'        => 'nc',
                    'cnonce'    => 'cnonce',
                    'opaque'    => 'opaque',
                    'response'  => 'response',
                ]
            ],
            [
                [
                    'PHP_AUTH_DIGEST' => 'Digest username=myleft realm=myleft qop=auth algorithm=MD5 uri=http://localhost:81/ nonce=nonce nc=nc cnonce=cnonce opaque=opaque response=response'
                ],
                'getDigestAuth',
                [
                    'username'  => 'myleft',
                    'realm'     => 'myleft',
                    'qop'       => 'auth',
                    'algorithm' => 'MD5',
                    'uri'       => 'http://localhost:81/',
                    'nonce'     => 'nonce',
                    'nc'        => 'nc',
                    'cnonce'    => 'cnonce',
                    'opaque'    => 'opaque',
                    'response'  => 'response',
                ]
            ],
        ];
    }
}
