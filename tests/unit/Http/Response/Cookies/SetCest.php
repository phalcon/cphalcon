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

namespace Phalcon\Test\Unit\Http\Response\Cookies;

use Phalcon\Http\Response\Cookies;
use Phalcon\Test\Fixtures\Traits\CookieTrait;
use Phalcon\Test\Unit\Http\Helper\HttpBase;
use UnitTester;

class SetCest extends HttpBase
{
    use CookieTrait;

    /**
     * executed before each test
     */
    public function _before(UnitTester $I)
    {
        parent::_before($I);
        $this->setDiSessionFiles();
    }

    /**
     * Tests Phalcon\Http\Response\Cookies :: set()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function httpResponseCookiesSet(UnitTester $I)
    {
        $I->wantToTest('Http\Response\Cookies - set()');
        $I->skipTest('Need implementation');
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

        $this->setDiCrypt();
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

        $I->assertRegexp('/HttpOnly$/', $cookieOne);
        $I->assertNotRegexp('/HttpOnly$/', $cookieTwo);
        $I->assertNotRegexp('/HttpOnly$/', $cookieThree);
    }
}
