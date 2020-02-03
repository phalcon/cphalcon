<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Response;

use Codeception\Example;
use Phalcon\Events\Event;
use Phalcon\Http\Response\Headers;
use Phalcon\Test\Unit\Http\Helper\HttpBase;
use UnitTester;

class HeadersCest extends HttpBase
{
    /**
     * Tests the instance of the object
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-05
     */
    public function testHttpResponseHeadersInstanceOf(UnitTester $I)
    {
        $headers = new Headers();

        $I->assertInstanceOf(
            Headers::class,
            $headers
        );
    }

    /**
     * Tests the get and set of the response headers
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-05
     */
    public function testHttpResponseHeadersGetSet(UnitTester $I)
    {
        $headers = new Headers();

        $headers->set('Content-Type', 'text/html');

        $I->assertEquals(
            'text/html',
            $headers->get('Content-Type')
        );
    }

    /**
     * Tests the has of the response headers
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-02
     */
    public function testHttpResponseHeadersHas(UnitTester $I)
    {
        $headers = new Headers();

        $headers->set('Content-Type', 'text/html');

        $I->assertTrue(
            $headers->has('Content-Type')
        );

        $I->assertFalse(
            $headers->has('unknown-header')
        );
    }

    /**
     * Tests the set of the response status headers
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/12895
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-06-17
     *
     * @dataProvider statusHeaderProvider
     */
    public function shouldSetResponseStatusHeader(UnitTester $I, Example $example)
    {
        $headers = new Headers();

        $headers->set(
            'Status',
            $example['code']
        );

        $headers = $I->getProtectedProperty($headers, 'headers');

        $I->assertCount(
            1,
            $headers
        );

        $I->assertTrue(
            isset(
                $headers['Status']
            )
        );

        $I->assertEquals(
            $example['code'],
            $headers['Status']
        );
    }

    /**
     * Tests the get of the response status headers
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/12895
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-06-17
     *
     * @dataProvider statusHeaderProvider
     */
    public function shouldGetResponseStatusHeader(UnitTester $I, Example $example)
    {
        $headers = new Headers();

        $I->setProtectedProperty(
            $headers,
            'headers',
            [
                'Status' => $example['code'],
            ]
        );

        $I->assertEquals(
            $example['code'],
            $headers->get('Status')
        );
    }

    /**
     * Tests resetting the response headers
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-05
     */
    public function testHttpResponseHeadersReset(UnitTester $I)
    {
        $headers = new Headers();

        $headers->set('Content-Type', 'text/html');

        $headers->reset();

        $I->assertEmpty(
            $headers->get('Content-Type')
        );
    }

    /**
     * Tests removing a response header
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-05
     */
    public function testHttpResponseHeadersRemove(UnitTester $I)
    {
        $headers = new Headers();

        $headers->set('Content-Type', 'text/html');

        $headers->remove('Content-Type');

        $I->assertEmpty(
            $headers->get('Content-Type')
        );
    }

    /**
     * Tests setting a raw response header
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-05
     */
    public function testHttpResponseHeadersRaw(UnitTester $I)
    {
        $headers = new Headers();

        $headers->setRaw('Content-Type: text/html');

        $I->assertEmpty(
            $headers->get('Content-Type: text/html')
        );
    }

    /**
     * Tests toArray in response headers
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-05
     */
    public function testHttpResponseHeadersToArray(UnitTester $I)
    {
        $headers = new Headers();

        $headers->set('Content-Type', 'text/html');

        $expected = [
            'Content-Type' => 'text/html',
        ];

        $I->assertEquals(
            $expected,
            $headers->toArray()
        );
    }

    /**
     * Test the event response:beforeSendHeaders
     *
     * @author Cameron Hall <me@chall.id.au>
     * @since  2018-11-28
     */
    public function testEventBeforeSendHeaders(UnitTester $I)
    {
        $this->setNewFactoryDefault();

        $eventsManager = $this->getDI()->getShared('eventsManager');

        $eventsManager->attach(
            'response:beforeSendHeaders',
            function (Event $event, $response) {
                return false;
            }
        );

        $response = $this->getResponseObject();

        $response->setEventsManager($eventsManager);

        $I->assertFalse(
            $response->sendHeaders()
        );
    }

    /**
     * Test the event response:beforeSendHeaders
     *
     * @author Cameron Hall <me@chall.id.au>
     * @since  2018-11-28
     */
    public function testEventAfterSendHeaders(UnitTester $I)
    {
        $eventsManager = $this->getDI()->getShared('eventsManager');

        $eventsManager->attach(
            'response:afterSendHeaders',
            function (Event $event, $response) {
                echo 'some content';
            }
        );

        $response = $this->getResponseObject();

        ob_start();

        $response->setEventsManager($eventsManager);

        $response->sendHeaders();

        $actual = ob_get_clean();

        $I->assertEquals('some content', $actual);
    }

    private function statusHeaderProvider(): array
    {
        return [
            [
                'message' => 'Unprocessable Entity',
                'code'    => 422,
            ],

            [
                'message' => 'Moved Permanently',
                'code'    => 301,
            ],

            [
                'message' => 'OK',
                'code'    => 200,
            ],

            [
                'message' => 'Service Unavailable',
                'code'    => 503,
            ],

            [
                'message' => 'Not Found',
                'code'    => 404,
            ],

            [
                'message' => 'Created',
                'code'    => 201,
            ],

            [
                'message' => 'Continue',
                'code'    => 100,
            ],
        ];
    }
}
