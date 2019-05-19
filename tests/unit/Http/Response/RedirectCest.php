<?php
declare(strict_types=1);

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
use Phalcon\Test\Unit\Http\Helper\HttpBase;
use UnitTester;

class RedirectCest extends HttpBase
{
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

        $response->redirect('some/local/uri');

        $expected = Headers::__set_state(
            [
                'headers' => [
                    'Status'             => '302 Found',
                    'Location'           => '/some/local/uri',
                    'HTTP/1.1 302 Found' => null,
                ],
            ]
        );

        $I->assertEquals(
            $expected,
            $response->getHeaders()
        );
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

        $response->redirect('http://google.com', true);

        $expected = Headers::__set_state(
            [
                'headers' => [
                    'Status'             => '302 Found',
                    'Location'           => 'http://google.com',
                    'HTTP/1.1 302 Found' => null,
                ],
            ]
        );

        $I->assertEquals(
            $expected,
            $response->getHeaders()
        );
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
                'headers' => [
                    'Status'             => '302 Found',
                    'Location'           => '/new/place/',
                    'HTTP/1.1 302 Found' => null,
                ],
            ]
        );

        $I->assertEquals(
            $expected,
            $response->getHeaders()
        );
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

        $response->redirect('http://google.com', true, 301);

        $expected = Headers::__set_state(
            [
                'headers' => [
                    'Status'                         => '301 Moved Permanently',
                    'Location'                       => 'http://google.com',
                    'HTTP/1.1 301 Moved Permanently' => null,
                ],
            ]
        );

        $I->assertEquals(
            $expected,
            $response->getHeaders()
        );
    }
}
