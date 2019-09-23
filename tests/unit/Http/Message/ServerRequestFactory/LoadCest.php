<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Message\ServerRequestFactory;

use Codeception\Example;
use Phalcon\Http\Message\Exception\InvalidArgumentException;
use Phalcon\Http\Message\ServerRequestFactory;
use Phalcon\Http\Message\UploadedFile;
use Phalcon\Test\Fixtures\Http\Message\ServerRequestFactoryFixture;
use Psr\Http\Message\ServerRequestInterface;
use UnitTester;

class LoadCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequestFactory :: load()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-09
     */
    public function httpMessageServerRequestFactoryLoad(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequestFactory - load()');

        $factory = new ServerRequestFactory();

        $request = $factory->load();

        $I->assertInstanceOf(
            ServerRequestInterface::class,
            $request
        );
    }

    /**
     * Tests Phalcon\Http\Message\ServerRequestFactory :: load() - header host
     * prefixed
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-09
     */
    public function httpMessageServerRequestFactoryLoadHeaderCookie(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequestFactory - load() - header cookie');

        $server = [
            'HTTP_COOKIE' => 'TESTSESS=face28e8-daae-10e0-a774-00000abbdf6c:3447789008; ' .
                'expires=Sun, 08-Nov-2020 00:00:00 UTC; ' .
                'Max-Age=63071999; ' .
                'path=/; ' .
                'domain=.phalcon.ld; ' .
                'secure; httponly',
        ];

        $factory = new ServerRequestFactory();

        $request = $factory->load($server);

        $expected = [
            'TESTSESS' => 'face28e8-daae-10e0-a774-00000abbdf6c:3447789008',
            'expires'  => 'Sun, 08-Nov-2020 00:00:00 UTC',
            'Max-Age'  => '63071999',
            'path'     => '/',
            'domain'   => '.phalcon.ld',
            'secure'   => '',
            'httponly' => '',
        ];

        $I->assertEquals(
            $expected,
            $request->getCookieParams()
        );
    }

    /**
     * Tests Phalcon\Http\Message\ServerRequestFactory :: load() - header host
     * prefixed
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-09
     */
    public function httpMessageServerRequestFactoryLoadHeaderHost(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequestFactory - load() - header host');

        $server = [
            'HTTP_HOST' => 'dev.phalcon.ld:8080',
        ];

        $factory = new ServerRequestFactory();
        $request = $factory->load($server);
        $uri     = $request->getUri();

        $I->assertEquals(
            'dev.phalcon.ld',
            $uri->getHost()
        );

        $I->assertEquals(
            8080,
            $uri->getPort()
        );

        $I->assertEquals(
            '/',
            $uri->getPath()
        );

        $I->assertEquals(
            '',
            $uri->getQuery()
        );

        $I->assertEquals(
            '',
            $uri->getFragment()
        );
    }

    /**
     * Tests Phalcon\Http\Message\ServerRequestFactory :: load() - header host
     * array prefixed
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-09
     */
    public function httpMessageServerRequestFactoryLoadHeaderHostArray(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequestFactory - load() - header host array');

        $server = [
            'HTTP_HOST' => [
                'dev.phalcon.ld',
                'test.phalcon.ld',
            ],
        ];

        $factory = new ServerRequestFactory();
        $request = $factory->load($server);
        $uri     = $request->getUri();

        $I->assertEquals(
            'dev.phalcon.ld,test.phalcon.ld',
            $uri->getHost()
        );
    }

    /**
     * Tests Phalcon\Http\Message\ServerRequestFactory :: load() - IIS path
     * name/port prefixed
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-02-09
     */
    public function httpMessageServerRequestFactoryLoadIisPath(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequestFactory - load() - IIS path');

        $server = [
            'IIS_WasUrlRewritten' => '1',
            'UNENCODED_URL'       => '/action/reaction',
        ];

        $factory = new ServerRequestFactory();
        $request = $factory->load($server);
        $uri     = $request->getUri();

        $I->assertEquals(
            '/action/reaction',
            $uri->getPath()
        );
    }

    /**
     * Tests Phalcon\Http\Message\ServerRequestFactory :: load() - original
     * path info name/port prefixed
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-02-09
     */
    public function httpMessageServerRequestFactoryLoadOriginalPathInfo(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequestFactory - load() - original path info');

        $server = [
            'ORIG_PATH_INFO' => '/action/reaction',
        ];

        $factory = new ServerRequestFactory();
        $request = $factory->load($server);
        $uri     = $request->getUri();

        $I->assertEquals(
            '/action/reaction',
            $uri->getPath()
        );
    }

    /**
     * Tests Phalcon\Http\Message\ServerRequestFactory :: load() - server header
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-02-09
     */
    public function httpMessageServerRequestFactoryLoadServerHeader(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequestFactory - load() - server header');

        $server = [
            'HTTP_HOST' => 'test.phalcon.ld',
        ];

        $factory = new ServerRequestFactoryFixture();
        $request = $factory->load($server);

        $expected = [
            'host'          => ['test.phalcon.ld'],
            'authorization' => ['Bearer'],
        ];

        $I->assertEquals(
            $expected,
            $request->getHeaders()
        );
    }

    /**
     * Tests Phalcon\Http\Message\ServerRequestFactory :: load() - server
     * name/port prefixed
     *
     * @dataProvider getServerNameExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-02-09
     */
    public function httpMessageServerRequestFactoryLoadServerNamePort(UnitTester $I, Example $example)
    {
        $I->wantToTest('Http\Message\ServerRequestFactory - load() - server name/port ' . $example[0]);

        $server = [
            'REQUEST_URI'  => $example[1],
            'QUERY_STRING' => $example[2],
            'SERVER_NAME'  => $example[3],
            'SERVER_PORT'  => $example[4],
        ];

        $factory = new ServerRequestFactory();
        $request = $factory->load($server);
        $uri     = $request->getUri();

        $I->assertEquals(
            $example[5],
            $uri->getHost()
        );

        $I->assertEquals(
            $example[6],
            $uri->getPort()
        );

        $I->assertEquals(
            $example[7],
            $uri->getPath()
        );

        $I->assertEquals(
            $example[8],
            $uri->getQuery()
        );

        $I->assertEquals(
            $example[9],
            $uri->getFragment()
        );
    }

    /**
     * Tests Phalcon\Http\Message\ServerRequestFactory :: load() - server
     * prefixed
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-09
     */
    public function httpMessageServerRequestFactoryLoadServerPrefixed(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequestFactory - load() - server prefixed');

        $server = [
            'SIMPLE'               => 'Some Cookie',
            'NO_OVERRIDE'          => 'auth-token',
            'REDIRECT_NO_OVERRIDE' => 'token-auth',
            'REDIRECT_OVERRIDE'    => 'override',
            'HTTP_AUTH'            => 'letmein',
            'CONTENT_LENGTH'       => 'UNSPECIFIED',
        ];

        $expected = [
            'auth'           => ['letmein'],
            'content-length' => ['UNSPECIFIED'],
        ];

        $factory = new ServerRequestFactory();
        $request = $factory->load($server);

        $I->assertEquals(
            $expected,
            $request->getHeaders()
        );
    }

    /**
     * Tests Phalcon\Http\Message\ServerRequestFactory :: load() - files
     * prefixed
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-09
     */
    public function httpMessageServerRequestFactoryLoadFiles(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequestFactory - load() - files');

        $uploadObject = new UploadedFile(
            'php://temp',
            0,
            0,
            'test2',
            'text/plain'
        );

        $files = [
            [
                'tmp_name' => 'php://temp',
                'size'     => 0,
                'error'    => 0,
                'name'     => 'test1',
                'type'     => 'text/plain',
            ],
            $uploadObject,
            [
                [
                    'tmp_name' => 'php://temp',
                    'size'     => 0,
                    'error'    => 0,
                    'name'     => 'test3',
                    'type'     => 'text/plain',
                ],
            ],
        ];

        $factory = new ServerRequestFactory();
        $request = $factory->load(null, null, null, null, $files);

        $actual = $request->getUploadedFiles();

        /** @var UploadedFile $element */
        $element = $actual[0];
        $I->assertInstanceOf(UploadedFile::class, $element);
        $I->assertEquals('test1', $element->getClientFilename());
        $I->assertEquals('text/plain', $element->getClientMediaType());

        /** @var UploadedFile $element */
        $element = $actual[1];
        $I->assertInstanceOf(UploadedFile::class, $element);
        $I->assertEquals($uploadObject, $element);

        /** @var UploadedFile $element */
        $element = $actual[2][0];
        $I->assertInstanceOf(UploadedFile::class, $element);
        $I->assertEquals('test3', $element->getClientFilename());
        $I->assertEquals('text/plain', $element->getClientMediaType());
    }

    /**
     * Tests Phalcon\Http\Message\ServerRequestFactory :: load() - files
     * exception prefixed
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-09
     */
    public function httpMessageServerRequestFactoryLoadFilesException(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequestFactory - load() - files exception');

        $I->expectThrowable(
            new InvalidArgumentException(
                'The file array must contain tmp_name, size and error; ' .
                'one or more are missing'
            ),
            function () {
                $files = [
                    [
                        'tmp_name' => 'php://temp',
                        'size'     => 0,
                        'name'     => 'test1',
                        'type'     => 'text/plain',
                    ],
                ];

                $factory = new ServerRequestFactory();
                $request = $factory->load(null, null, null, null, $files);
            }
        );
    }

    /**
     * Tests Phalcon\Http\Message\ServerRequestFactory :: load() - scheme https
     * prefixed
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-09
     */
    public function httpMessageServerRequestFactoryLoadSchemeHttps(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequestFactory - load() - scheme https');

        $factory = new ServerRequestFactory();
        $server  = [
            'HTTPS' => 'on',
        ];

        $request = $factory->load($server);
        $uri     = $request->getUri();
        $I->assertEquals('https', $uri->getScheme());

        $server = [
            'HTTPS' => 'off',
        ];

        $request = $factory->load($server);
        $uri     = $request->getUri();
        $I->assertEquals('http', $uri->getScheme());
    }


    private function getServerNameExamples(): array
    {
        return [
            [
                'host',
                'http://dev.phalcon.ld',
                '',
                'dev.phalcon.ld',
                null,
                'dev.phalcon.ld',
                null,
                '',
                '',
                '',
            ],
            [
                'host',
                'http://dev.phalcon.ld',
                '',
                'dev.phalcon.ld',
                8080,
                'dev.phalcon.ld',
                8080,
                '',
                '',
                '',
            ],
            [
                'host',
                'http://dev.phalcon.ld/action/reaction',
                '',
                'dev.phalcon.ld',
                8080,
                'dev.phalcon.ld',
                8080,
                '/action/reaction',
                '',
                '',
            ],
            [
                'host',
                'http://dev.phalcon.ld/action/reaction?one=two',
                'one=two',
                'dev.phalcon.ld',
                8080,
                'dev.phalcon.ld',
                8080,
                '/action/reaction',
                'one=two',
                '',
            ],
            [
                'host',
                'http://dev.phalcon.ld/action/reaction?one=two#fragment',
                'one=two',
                'dev.phalcon.ld',
                8080,
                'dev.phalcon.ld',
                8080,
                '/action/reaction',
                'one=two',
                'fragment',
            ],
        ];
    }
}
