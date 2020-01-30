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

namespace Phalcon\Test\Unit\Http;

use Codeception\Example;
use Phalcon\Di\DiInterface;
use Phalcon\Http\Request;
use Phalcon\Test\Fixtures\Http\PhpStream;
use Phalcon\Test\Unit\Http\Helper\HttpBase;
use UnitTester;

class RequestCest extends HttpBase
{
    /**
     * Tests the getDI
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-23
     */
    public function testHttpRequestGetDI(UnitTester $I)
    {
        $request   = $this->getRequestObject();
        $container = $request->getDI();

        $I->assertInstanceOf(
            DiInterface::class,
            $container
        );
    }

    /**
     * Tests the instance of the object
     */
    public function testHttpRequestInstanceOf(UnitTester $I)
    {
        $request = $this->getRequestObject();

        $I->assertInstanceOf(
            Request::class,
            $request
        );
    }

    /**
     * Tests POST functions
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-04
     */
    public function testHttpRequestInputPost(UnitTester $I)
    {
        $this->hasEmpty($I, 'hasPost');
        $this->hasNotEmpty($I, 'hasPost', 'setPostVar');

        $this->getEmpty($I, 'getPost');
        $this->getNotEmpty($I, 'getPost', 'setPostVar');

        $this->getSanitized($I, 'getPost', 'setPostVar');

        $this->getSanitizedArrayFilter($I, 'getPost', ['string'], 'setPostVar');
    }

    /**
     * Tests getPut with json content type.
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/13418
     * @author Phalcon Team <team@phalcon.io>
     * @since  2017-06-03
     */
    public function shouldGetDataReceivedByPutMethod(UnitTester $I)
    {
        stream_wrapper_unregister('php');
        stream_wrapper_register('php', PhpStream::class);

        file_put_contents('php://input', 'fruit=orange&quantity=4');

        $_SERVER['REQUEST_METHOD'] = 'PUT';

        $request = new Request();

        $data = file_get_contents('php://input');

        $expected = [
            'fruit'    => 'orange',
            'quantity' => '4',
        ];

        parse_str($data, $actual);

        $I->assertEquals($expected, $actual);

        $I->assertEquals(
            $expected,
            $request->getPut()
        );

        stream_wrapper_restore('php');
    }

    /**
     * Tests getPut with json content type.
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/13418
     * @author Phalcon Team <team@phalcon.io>
     * @since  2017-06-03
     */
    public function shouldGetDataReceivedByPutMethodAndJsonType(UnitTester $I)
    {
        stream_wrapper_unregister('php');
        stream_wrapper_register('php', PhpStream::class);

        file_put_contents(
            'php://input',
            '{"fruit": "orange", "quantity": "4"}'
        );

        $_SERVER['REQUEST_METHOD'] = 'PUT';
        $_SERVER['CONTENT_TYPE']   = 'application/json';

        $request = new Request();

        $expected = [
            'fruit'    => 'orange',
            'quantity' => '4',
        ];

        $actual = json_decode(
            file_get_contents('php://input'),
            true
        );

        $I->assertEquals($expected, $actual);

        $I->assertEquals(
            $expected,
            $request->getPut()
        );

        stream_wrapper_restore('php');
    }

    /**
     * Tests GET functions
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-04
     */
    public function testHttpRequestInputGet(UnitTester $I)
    {
        $this->hasEmpty($I, 'hasQuery');
        $this->hasNotEmpty($I, 'hasQuery', 'setGetVar');

        $this->getEmpty($I, 'getQuery');
        $this->getNotEmpty($I, 'getQuery', 'setGetVar');

        $this->getSanitized($I, 'getQuery', 'setGetVar');

        $this->getSanitizedArrayFilter($I, 'getQuery', ['string'], 'setGetVar');
    }

    /**
     * Tests REQUEST functions
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-04
     */
    public function testHttpRequestInputRequest(UnitTester $I)
    {
        $this->hasEmpty($I, 'has');
        $this->hasNotEmpty($I, 'has', 'setRequestVar');

        $this->getEmpty($I, 'get');
        $this->getNotEmpty($I, 'get', 'setRequestVar');

        $this->getSanitized($I, 'get', 'setRequestVar');

        $this->getSanitizedArrayFilter($I, 'get', ['string'], 'setRequestVar');
    }

    public function testHttpRequestMethod(UnitTester $I)
    {
        $request = $this->getRequestObject();


        $_SERVER['REQUEST_METHOD'] = 'POST';

        $I->assertEquals(
            'POST',
            $request->getMethod()
        );

        $I->assertTrue(
            $request->isPost()
        );

        $I->assertFalse(
            $request->isGet()
        );


        $_SERVER['REQUEST_METHOD'] = 'GET';

        $I->assertEquals(
            'GET',
            $request->getMethod()
        );

        $I->assertTrue(
            $request->isGet()
        );

        $I->assertFalse(
            $request->isPost()
        );


        $_SERVER['REQUEST_METHOD'] = 'PUT';

        $I->assertEquals(
            'PUT',
            $request->getMethod()
        );

        $I->assertTrue(
            $request->isPut()
        );


        $_SERVER['REQUEST_METHOD'] = 'DELETE';

        $I->assertEquals(
            'DELETE',
            $request->getMethod()
        );

        $I->assertTrue(
            $request->isDelete()
        );


        $_SERVER['REQUEST_METHOD'] = 'OPTIONS';

        $I->assertEquals(
            'OPTIONS',
            $request->getMethod()
        );

        $I->assertTrue(
            $request->isOptions()
        );


        $_SERVER['REQUEST_METHOD'] = 'POST';

        $I->assertTrue(
            $request->isMethod('POST')
        );

        $I->assertTrue(
            $request->isMethod(['GET', 'POST'])
        );


        $_SERVER['REQUEST_METHOD'] = 'GET';

        $I->assertTrue(
            $request->isMethod('GET')
        );

        $I->assertTrue(
            $request->isMethod(
                [
                    'GET',
                    'POST',
                ]
            )
        );


        $_SERVER['REQUEST_METHOD'] = 'CONNECT';

        $I->assertEquals(
            'CONNECT',
            $request->getMethod()
        );

        $I->assertTrue(
            $request->isConnect()
        );

        $I->assertFalse(
            $request->isGet()
        );


        $_SERVER['REQUEST_METHOD'] = 'TRACE';

        $I->assertEquals(
            'TRACE',
            $request->getMethod()
        );

        $I->assertTrue(
            $request->isTrace()
        );

        $I->assertFalse(
            $request->isGet()
        );


        $_SERVER['REQUEST_METHOD'] = 'PURGE';

        $I->assertEquals(
            'PURGE',
            $request->getMethod()
        );

        $I->assertTrue(
            $request->isPurge()
        );

        $I->assertFalse(
            $request->isGet()
        );
    }

    /**
     * Tests the ability to override the HTTP method
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/12478
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2016-12-18
     *
     * @dataProvider overridenMethodProvider
     */
    public function shouldOverrideHttpRequestMethod(UnitTester $I, Example $example)
    {
        $header   = $example[0];
        $method   = $example[1];
        $expected = $example[2];


        $_SERVER['REQUEST_METHOD'] = 'POST';

        $request = $this->getRequestObject();


        $_SERVER[$header] = $method;

        $I->assertEquals(
            $expected,
            $request->getMethod()
        );


        $_SERVER[$header] = strtolower($method);

        $I->assertEquals(
            $expected,
            $request->getMethod()
        );


        $_SERVER[strtolower($header)] = $method;

        $I->assertEquals(
            $expected,
            $request->getMethod()
        );
    }

    public function testHttpRequestAcceptableContent(UnitTester $I)
    {
        $request = $this->getRequestObject();

        $_SERVER['HTTP_ACCEPT'] = 'text/html,application/xhtml+xml,application/xml;'
            . 'q=0.9,*/*;q=0.8,application/json; level=2; q=0.7';

        $accept = $request->getAcceptableContent();

        $I->assertCount(5, $accept);


        $firstAccept = $accept[0];

        $I->assertEquals(
            'text/html',
            $firstAccept['accept']
        );

        $I->assertEquals(
            1,
            $firstAccept['quality']
        );


        $fourthAccept = $accept[3];

        $I->assertEquals(
            '*/*',
            $fourthAccept['accept']
        );

        $I->assertEquals(
            0.8,
            $fourthAccept['quality']
        );


        $lastAccept = $accept[4];

        $I->assertEquals(
            'application/json',
            $lastAccept['accept']
        );

        $I->assertEquals(
            0.7,
            $lastAccept['quality']
        );

        $I->assertEquals(
            2,
            $lastAccept['level']
        );

        $I->assertEquals(
            'text/html',
            $request->getBestAccept()
        );
    }

    public function testHttpRequestAcceptableCharsets(UnitTester $I)
    {
        $request = $this->getRequestObject();

        $_SERVER['HTTP_ACCEPT_CHARSET'] = 'iso-8859-5,unicode-1-1;q=0.8';


        $accept = $request->getClientCharsets();

        $I->assertCount(2, $accept);


        $firstAccept = $accept[0];

        $I->assertEquals(
            'iso-8859-5',
            $firstAccept['charset']
        );

        $I->assertEquals(
            1,
            $firstAccept['quality']
        );


        $lastAccept = $accept[1];

        $I->assertEquals(
            'unicode-1-1',
            $lastAccept['charset']
        );

        $I->assertEquals(
            0.8,
            $lastAccept['quality']
        );

        $I->assertEquals(
            'iso-8859-5',
            $request->getBestCharset()
        );
    }

    public function testHttpRequestAcceptableLanguage(UnitTester $I)
    {
        $request = $this->getRequestObject();

        $_SERVER['HTTP_ACCEPT_LANGUAGE'] = 'es,es-ar;q=0.8,en;q=0.5,en-us;q=0.3,de-de; q=0.9';

        $accept = $request->getLanguages();

        $I->assertCount(5, $accept);


        $firstAccept = $accept[0];

        $I->assertEquals(
            'es',
            $firstAccept['language']
        );

        $I->assertEquals(
            1,
            $firstAccept['quality']
        );


        $fourthAccept = $accept[3];

        $I->assertEquals(
            'en-us',
            $fourthAccept['language']
        );

        $I->assertEquals(
            0.3,
            $fourthAccept['quality']
        );


        $lastAccept = $accept[4];

        $I->assertEquals(
            'de-de',
            $lastAccept['language']
        );

        $I->assertEquals(
            0.9,
            $lastAccept['quality']
        );

        $I->assertEquals($request->getBestLanguage(), 'es');
    }

    public function testHttpRequestClientAddress(UnitTester $I)
    {
        $request = $this->getRequestObject();


        $_SERVER['REMOTE_ADDR']          = '192.168.0.1';
        $_SERVER['HTTP_X_FORWARDED_FOR'] = '192.168.7.21';

        $I->assertEquals(
            '192.168.0.1',
            $request->getClientAddress()
        );

        $I->assertEquals(
            '192.168.7.21',
            $request->getClientAddress(true)
        );


        $_SERVER['REMOTE_ADDR'] = '86.45.89.47, 214.55.34.56';

        $I->assertEquals(
            '86.45.89.47',
            $request->getClientAddress()
        );
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/1265
     */
    public function testRequestGetValueByUsingSeveralMethods(UnitTester $I)
    {
        $request = $this->getRequestObject();

        $_REQUEST = $_GET = $_POST = [
            'string' => 'hello',
            'array'  => ['string' => 'world'],
        ];

        // get
        $I->assertEquals('hello', $request->get('string', 'string'));
        $I->assertEquals('hello', $request->get('string', 'string', null, true, true));

        $I->assertEquals(['string' => 'world'], $request->get('array', 'string'));
        $I->assertEquals(null, $request->get('array', 'string', null, true, true));

        // getQuery
        $I->assertEquals('hello', $request->getQuery('string', 'string'));
        $I->assertEquals('hello', $request->getQuery('string', 'string', null, true, true));

        $I->assertEquals(['string' => 'world'], $request->getQuery('array', 'string'));
        $I->assertEquals(null, $request->getQuery('array', 'string', null, true, true));

        // getPost
        $I->assertEquals('hello', $request->getPost('string', 'string'));
        $I->assertEquals('hello', $request->getPost('string', 'string', null, true, true));

        $I->assertEquals(['string' => 'world'], $request->getPost('array', 'string'));
        $I->assertEquals(null, $request->getPost('array', 'string', null, true, true));
    }

    public function testRequestGetQuery(UnitTester $I)
    {
        $_REQUEST = $_GET = $_POST = [
            'id'    => 1,
            'num'   => 'a1a',
            'age'   => 'aa',
            'phone' => '',
        ];

        $functions = ['get', 'getQuery', 'getPost'];

        foreach ($functions as $function) {
            $request = $this->getRequestObject();

            $I->assertEquals(
                1,
                $request->$function('id', 'int', 100)
            );

            $I->assertEquals(
                1,
                $request->$function('num', 'int', 100)
            );

            $I->assertEmpty(
                $request->$function('age', 'int', 100)
            );

            $I->assertEmpty(
                $request->$function('phone', 'int', 100)
            );

            $I->assertEquals(
                100,
                $request->$function('phone', 'int', 100, true)
            );
        }
    }

    /**
     * Tests uploaded files
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-01-31
     */
    public function testGetUploadedFiles(UnitTester $I)
    {
        $request = $this->getRequestObject();
        $_FILES  = [
            'photo' => [
                'name'     => ['f0', 'f1', ['f2', 'f3'], [[[['f4']]]]],
                'type'     => [
                    'text/plain',
                    'text/csv',
                    ['image/png', 'image/gif'],
                    [[[['application/octet-stream']]]],
                ],
                'tmp_name' => ['t0', 't1', ['t2', 't3'], [[[['t4']]]]],
                'error'    => [0, 0, [0, 0], [[[[8]]]]],
                'size'     => [10, 20, [30, 40], [[[[50]]]]],
            ],
        ];

        $all        = $request->getUploadedFiles(false);
        $successful = $request->getUploadedFiles(true);

        $I->assertCount(5, $all);
        $I->assertCount(4, $successful);

        for ($i = 0; $i <= 4; ++$i) {
            $I->assertFalse(
                $all[$i]->isUploadedFile()
            );
        }

        $data = [
            'photo.0',
            'photo.1',
            'photo.2.0',
            'photo.2.1',
            'photo.3.0.0.0.0',
        ];

        for ($i = 0; $i <= 4; ++$i) {
            $I->assertEquals(
                $data[$i],
                $all[$i]->getKey()
            );
        }


        $I->assertEquals(
            'f0',
            $all[0]->getName()
        );

        $I->assertEquals(
            'f1',
            $all[1]->getName()
        );

        $I->assertEquals(
            'f2',
            $all[2]->getName()
        );

        $I->assertEquals(
            'f3',
            $all[3]->getName()
        );

        $I->assertEquals(
            'f4',
            $all[4]->getName()
        );


        $I->assertEquals(
            't0',
            $all[0]->getTempName()
        );

        $I->assertEquals(
            't1',
            $all[1]->getTempName()
        );

        $I->assertEquals(
            't2',
            $all[2]->getTempName()
        );

        $I->assertEquals(
            't3',
            $all[3]->getTempName()
        );

        $I->assertEquals(
            't4',
            $all[4]->getTempName()
        );


        $I->assertEquals(
            'f0',
            $successful[0]->getName()
        );

        $I->assertEquals(
            'f1',
            $successful[1]->getName()
        );

        $I->assertEquals(
            'f2',
            $successful[2]->getName()
        );

        $I->assertEquals(
            'f3',
            $successful[3]->getName()
        );


        $I->assertEquals(
            't0',
            $successful[0]->getTempName()
        );

        $I->assertEquals(
            't1',
            $successful[1]->getTempName()
        );

        $I->assertEquals(
            't2',
            $successful[2]->getTempName()
        );

        $I->assertEquals(
            't3',
            $successful[3]->getTempName()
        );
    }

    private function overridenMethodProvider(): array
    {
        return [
            [
                'HTTP_X_HTTP_METHOD_OVERRIDE',
                'PUT',
                'PUT',
            ],

            [
                'HTTP_X_HTTP_METHOD_OVERRIDE',
                'PAT',
                'GET',
            ],

            [
                'HTTP_X_HTTP_METHOD_OVERRIDE',
                'GET',
                'GET',
            ],

            [
                'HTTP_X_HTTP_METHOD_OVERRIDE',
                'GOT',
                'GET',
            ],

            [
                'HTTP_X_HTTP_METHOD_OVERRIDE',
                'HEAD',
                'HEAD',
            ],

            [
                'HTTP_X_HTTP_METHOD_OVERRIDE',
                'HED',
                'GET',
            ],

            [
                'HTTP_X_HTTP_METHOD_OVERRIDE',
                'POST',
                'POST',
            ],

            [
                'HTTP_X_HTTP_METHOD_OVERRIDE',
                'PAST',
                'GET',
            ],

            [
                'HTTP_X_HTTP_METHOD_OVERRIDE',
                'DELETE',
                'DELETE',
            ],

            [
                'HTTP_X_HTTP_METHOD_OVERRIDE',
                'DILETE',
                'GET',
            ],

            [
                'HTTP_X_HTTP_METHOD_OVERRIDE',
                'OPTIONS',
                'OPTIONS',
            ],

            [
                'HTTP_X_HTTP_METHOD_OVERRIDE',
                'OPTION',
                'GET',
            ],

            [
                'HTTP_X_HTTP_METHOD_OVERRIDE',
                'PATCH',
                'PATCH',
            ],

            [
                'HTTP_X_HTTP_METHOD_OVERRIDE',
                'PUTCH',
                'GET',
            ],

            [
                'HTTP_X_HTTP_METHOD_OVERRIDE',
                'PURGE',
                'PURGE',
            ],

            [
                'HTTP_X_HTTP_METHOD_OVERRIDE',
                'PURG',
                'GET',
            ],

            [
                'HTTP_X_HTTP_METHOD_OVERRIDE',
                'TRACE',
                'TRACE',
            ],

            [
                'HTTP_X_HTTP_METHOD_OVERRIDE',
                'RACE',
                'GET',
            ],

            [
                'HTTP_X_HTTP_METHOD_OVERRIDE',
                'CONNECT',
                'CONNECT',
            ],

            [
                'HTTP_X_HTTP_METHOD_OVERRIDE',
                'CONECT',
                'GET',
            ],
        ];
    }
}
