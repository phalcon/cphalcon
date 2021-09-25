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

namespace Phalcon\Tests\Unit\Http\Response\Cookies;

use Phalcon\Http\Response\Cookies;
use Phalcon\Tests\Fixtures\Traits\CookieTrait;
use Phalcon\Tests\Unit\Http\Helper\HttpBase;
use UnitTester;

class GetSetCest extends HttpBase
{
    use CookieTrait;

    /**
     * executed before each test
     */
    public function _before(UnitTester $I)
    {
        parent::_before($I);
        $this->setDiService('sessionStream');
    }

    /**
     * Tests Phalcon\Http\Response\Cookies :: get / set()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-06
     */
    public function httpResponseCookiesGetSet(UnitTester $I)
    {
        $I->wantToTest('Http\Response\Cookies - get / set()');
        $sName  = 'framework';
        $sValue = 'phalcon';

        $this->setDiService('crypt');
        $container = $this->getDi();

        $oCookie = new Cookies();
        $oCookie->setDI($container);
        $oCookie->set($sName, $sValue);

        $I->assertEquals($sValue, $oCookie->get($sName));
    }

    /**
     * Tests Issue #13464
     *
     * @author Cameron Hall <me@chall.id.au>
     * @since  2019-01-20
     * @issue https://github.com/phalcon/cphalcon/issues/13464
     */
    public function httpCookieSetHttpOnly(UnitTester $I)
    {
        $I->wantToTest('Issue #13464');
        $I->checkExtensionIsLoaded('xdebug');

        $this->setDiService('crypt');
        $container = $this->getDi();

        $cookie = new Cookies();
        $cookie->setDI($container);
        $cookie->useEncryption(false);
        $cookie->set('cookie-1', 'potato', time() + 86400, '/', false, 'localhost', true);
        $cookie->set('cookie-2', 'potato', time() + 86400, '/', false, 'localhost', false);
        $cookie->set('cookie-3', 'potato', time() + 86400, '/', false, 'localhost');
        $cookie->send();

        $cookieOne   = $this->getCookie('cookie-1');
        $cookieTwo   = $this->getCookie('cookie-2');
        $cookieThree = $this->getCookie('cookie-3');

        $I->assertStringContainsString('HttpOnly', $cookieOne);
        $I->assertStringNotContainsString('HttpOnly', $cookieTwo);
        $I->assertStringNotContainsString('HttpOnly', $cookieThree);
    }

    /**
     * Test Http\Response\Cookies - set() options parameter
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-10
     * @issue https://github.com/phalcon/cphalcon/issues/15129
     */
    public function httpCookieSetOptions(UnitTester $I)
    {
        $I->wantToTest('Http\Response\Cookies - set() options parameter');

        $I->checkExtensionIsLoaded('xdebug');

        $this->setDiService('crypt');
        $container = $this->getDi();

        $cookie = new Cookies();
        $cookie->setDI($container);
        $cookie->useEncryption(false);

        $cookie->set(
            'samesite-cookie-1',
            'potato',
            time() + 86400,
            '/',
            false,
            'localhost',
            false,
            [
                'samesite' => 'None'
            ]
        );

        $cookie->set(
            'samesite-cookie-2',
            'potato',
            time() + 86400,
            '/',
            false,
            'localhost',
            false,
            [
                'samesite' => 'Lax'
            ]
        );

        $cookie->set(
            'samesite-cookie-3',
            'potato',
            time() + 86400,
            '/',
            false,
            'localhost',
            false,
            [
                'samesite' => 'Strict'
            ]
        );

        $cookie->set(
            'samesite-cookie-4',
            'potato',
            time() + 86400,
            '/',
            false,
            'localhost',
            false
        );

        $cookie->send();

        $cookieOne   = $this->getCookie('samesite-cookie-1');
        $cookieTwo   = $this->getCookie('samesite-cookie-2');
        $cookieThree = $this->getCookie('samesite-cookie-3');
        $cookieFour  = $this->getCookie('samesite-cookie-4');

        $I->assertStringContainsString('SameSite=None', $cookieOne);
        $I->assertStringContainsString('SameSite=Lax', $cookieTwo);
        $I->assertStringContainsString('SameSite=Strict', $cookieThree);
        $I->assertStringNotContainsString('SameSite', $cookieFour);
    }
}
