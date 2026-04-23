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

use Phalcon\Tests\Support\Listener\CustomAuthorizationListener;
use Phalcon\Tests\Support\Listener\NegotiateAuthorizationListener;
use Phalcon\Tests\Unit\Http\Helper\AbstractHttpBase;

final class AuthHeaderTest extends AbstractHttpBase
{
    /**
     * @return array[]
     */
    public static function authProvider(): array
    {
        return [
            [
                [
                    'PHP_AUTH_USER' => 'myleft',
                    'PHP_AUTH_PW'   => '123456',
                ],
                'getBasicAuth',
                [
                    'username' => 'myleft',
                    'password' => '123456',
                ],
            ],

            [
                [
                    'PHP_AUTH_DIGEST' => 'Digest username="myleft", ' .
                        'realm="myleft", qop="auth", algorithm="MD5", ' .
                        'uri="https://localhost:81/", nonce="nonce", nc=nc, ' .
                        'cnonce="cnonce", opaque="opaque", response="response"',
                ],
                'getDigestAuth',
                [
                    'username'  => 'myleft',
                    'realm'     => 'myleft',
                    'qop'       => 'auth',
                    'algorithm' => 'MD5',
                    'uri'       => 'https://localhost:81/',
                    'nonce'     => 'nonce',
                    'nc'        => 'nc',
                    'cnonce'    => 'cnonce',
                    'opaque'    => 'opaque',
                    'response'  => 'response',
                ],
            ],

            [
                [
                    'PHP_AUTH_DIGEST' => 'Digest username=myleft, realm=myleft, ' .
                        'qop=auth, algorithm=MD5, uri=https://localhost:81/, ' .
                        'nonce=nonce, nc=nc, cnonce=cnonce, opaque=opaque, response=response',
                ],
                'getDigestAuth',
                [
                    'username'  => 'myleft',
                    'realm'     => 'myleft',
                    'qop'       => 'auth',
                    'algorithm' => 'MD5',
                    'uri'       => 'https://localhost:81/',
                    'nonce'     => 'nonce',
                    'nc'        => 'nc',
                    'cnonce'    => 'cnonce',
                    'opaque'    => 'opaque',
                    'response'  => 'response',
                ],
            ],

            [
                [
                    'PHP_AUTH_DIGEST' => 'Digest username=myleft realm=myleft ' .
                        'qop=auth algorithm=MD5 uri=https://localhost:81/ ' .
                        'nonce=nonce nc=nc cnonce=cnonce opaque=opaque response=response',
                ],
                'getDigestAuth',
                [
                    'username'  => 'myleft',
                    'realm'     => 'myleft',
                    'qop'       => 'auth',
                    'algorithm' => 'MD5',
                    'uri'       => 'https://localhost:81/',
                    'nonce'     => 'nonce',
                    'nc'        => 'nc',
                    'cnonce'    => 'cnonce',
                    'opaque'    => 'opaque',
                    'response'  => 'response',
                ],
            ],
        ];
    }

    /**
     * @return array
     */
    public static function basicAuthProvider(): array
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
                    'PHP_AUTH_PW' => 'secret',
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
                    'HTTP_AUTHORIZATION' => 'Digest username="myleft", ' .
                        'realm="myleft", qop="auth", ' .
                        'algorithm="MD5", uri="https://localhost:81/", ' .
                        'nonce="nonce", nc=nc, cnonce="cnonce", ' .
                        'opaque="opaque", response="response"',
                ],
                [
                    'Authorization'   => 'Digest username="myleft", realm="myleft", ' .
                        'qop="auth", algorithm="MD5", uri="https://localhost:81/", ' .
                        'nonce="nonce", nc=nc, cnonce="cnonce", ' .
                        'opaque="opaque", response="response"',
                    'Php-Auth-Digest' => 'Digest username="myleft", realm="myleft", ' .
                        'qop="auth", algorithm="MD5", uri="https://localhost:81/", ' .
                        'nonce="nonce", nc=nc, cnonce="cnonce", ' .
                        'opaque="opaque", response="response"',
                ],
            ],

            // Digest Auth with REDIRECT_HTTP_AUTHORIZATION
            [
                [
                    'REDIRECT_HTTP_AUTHORIZATION' => 'Digest username="myleft", realm="myleft", ' .
                        'qop="auth", algorithm="MD5", uri="https://localhost:81/", ' .
                        'nonce="nonce", nc=nc, cnonce="cnonce", ' .
                        'opaque="opaque", response="response"',
                ],
                [
                    'Authorization'   => 'Digest username="myleft", realm="myleft", ' .
                        'qop="auth", algorithm="MD5", uri="https://localhost:81/", ' .
                        'nonce="nonce", nc=nc, cnonce="cnonce", ' .
                        'opaque="opaque", response="response"',
                    'Php-Auth-Digest' => 'Digest username="myleft", realm="myleft", ' .
                        'qop="auth", algorithm="MD5", uri="https://localhost:81/", ' .
                        'nonce="nonce", nc=nc, cnonce="cnonce", ' .
                        'opaque="opaque", response="response"',
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

    /**
     * @dataProvider basicAuthProvider
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/12480
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2016-12-18
     */
    public function testHttpRequestCorrectHandleAuth(
        array $server,
        array $expected
    ): void {
        $_SERVER = $server;

        $request = $this->getRequestObject();
        $actual  = $request->getHeaders();

        ksort($actual);
        ksort($expected);

        $this->assertSame($expected, $actual);
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/13327
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-03-25
     */
    public function testHttpRequestEnableCustomAuthorizationResolver(): void
    {
        $request       = $this->getRequestObject();
        $eventsManager = $this->container->getShared('eventsManager');

        $eventsManager->attach(
            'request',
            new NegotiateAuthorizationListener()
        );

        $_SERVER['CUSTOM_KERBEROS_AUTH'] = 'Negotiate a87421000492aa874209af8bc028';

        $expected = [
            'Authorization' => 'Negotiate a87421000492aa874209af8bc028',
        ];
        $actual   = $request->getHeaders();
        $this->assertSame($expected, $actual);
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/13327
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-03-25
     */
    public function testHttpRequestFireEventWhenResolveAuthorization(): void
    {
        $request       = $this->getRequestObject();
        $eventsManager = $this->container->getShared('eventsManager');

        $eventsManager->attach(
            'request',
            new CustomAuthorizationListener()
        );

        $_SERVER = [
            'HTTP_CUSTOM_KEY' => 'Custom-Value',
        ];

        $expected = [
            'Custom-Key'   => 'Custom-Value',
            'Fired-Before' => 'beforeAuthorizationResolve',
            'Fired-After'  => 'afterAuthorizationResolve',
        ];
        $actual   = $request->getHeaders();
        $this->assertSame($expected, $actual);
    }

    /**
     * @dataProvider authProvider
     *
     */
    public function testHttpRequestGetAuthFromHeaders(
        array $server,
        string $function,
        array $expected
    ): void {
        $request = $this->getRequestObject();

        $_SERVER = $server;

        $actual = $request->$function();
        $this->assertSame($expected, $actual);
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/13327
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-03-25
     */
    public function testHttpRequestResolveCustomAuthorizationHeaders(): void
    {
        $request = $this->getRequestObject();

        $_SERVER['HTTP_AUTHORIZATION'] = 'Enigma Secret';

        $expected = [
            'Authorization' => 'Enigma Secret',
        ];
        $actual   = $request->getHeaders();
        $this->assertSame($expected, $actual);
    }
}
