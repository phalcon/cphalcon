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

namespace Phalcon\Test\Unit\Http\Response;

use Phalcon\Test\Unit\Http\Helper\HttpBase;
use UnitTester;

class RedirectCest extends HttpBase
{
    /**
     * Tests redirect locally
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-08
     */
    public function testHttpResponseRedirectLocalUrl(UnitTester $I)
    {
        $response = $this->getResponseObject();

        $response->resetHeaders();

        $response->redirect('some/local/uri');

        $actual = $response->getHeaders();
        $I->assertEquals('302 Found', $actual->get('Status'));
        $I->assertEquals('/some/local/uri', $actual->get('Location'));
        $I->assertEquals(null, $actual->get('HTTP/1.1 302 Found'));
    }

    /**
     * Tests redirect remotely 302
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-08
     */
    public function testHttpResponseRedirectRemoteUrl302(UnitTester $I)
    {
        $response = $this->getResponseObject();

        $response->resetHeaders();

        $response->redirect('http://google.com', true);

        $actual = $response->getHeaders();
        $I->assertEquals('302 Found', $actual->get('Status'));
        $I->assertEquals('http://google.com', $actual->get('Location'));
        $I->assertEquals(null, $actual->get('HTTP/1.1 302 Found'));
    }

    /**
     * Tests redirect local with non standard code
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/11324
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-01-19
     */
    public function testHttpResponseRedirectLocalUrlWithNonStandardCode(UnitTester $I)
    {
        $response = $this->getResponseObject();

        $response->resetHeaders();

        $response->redirect('new/place/', false, 309);

        $actual = $response->getHeaders();
        $I->assertEquals('302 Found', $actual->get('Status'));
        $I->assertEquals('/new/place/', $actual->get('Location'));
        $I->assertEquals(null, $actual->get('HTTP/1.1 302 Found'));
    }

    /**
     * Tests redirect remotely 301
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/1182
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-08
     */
    public function testHttpResponseRedirectRemoteUrl301(UnitTester $I)
    {
        $response = $this->getResponseObject();

        $response->resetHeaders();

        $response->redirect('http://google.com', true, 301);

        $actual = $response->getHeaders();
        $I->assertEquals('301 Moved Permanently', $actual->get('Status'));
        $I->assertEquals('http://google.com', $actual->get('Location'));
        $I->assertEquals(null, $actual->get('HTTP/1.1 302 Found'));
    }
}
