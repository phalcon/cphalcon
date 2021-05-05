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

class SendCest extends HttpBase
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
     * Tests Phalcon\Http\Response\Cookies :: send()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-06
     */
    public function httpResponseCookiesSend(UnitTester $I)
    {
        $I->wantToTest('Http\Response\Cookies - send()');

        $sName  = 'framework';
        $sValue = 'phalcon';

        $this->setDiService('crypt');
        $container = $this->getDi();

        $oCookie = new Cookies();
        $oCookie->setDI($container);
        $oCookie->set($sName, $sValue);

        $I->assertTrue($oCookie->send());
    }

    /**
     * Tests Phalcon\Http\Response\Cookies :: send() - twice
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-04-22
     * @issue  15334
     */
    public function httpResponseCookiesSendTwice(UnitTester $I)
    {
        $I->wantToTest('Http\Response\Cookies - send() - twice');

        $name  = 'framework';
        $value = 'phalcon';

        $this->setDiService('crypt');
        $container = $this->getDi();

        $cookie = new Cookies();
        $cookie->setDI($container);
        $cookie->set($name, $value);

        $actual = $cookie->isSent();
        $I->assertFalse($actual);

        $actual = $cookie->send();
        $I->assertTrue($actual);

        $actual = $cookie->isSent();
        $I->assertTrue($actual);

        $actual = $cookie->send();
        $I->assertFalse($actual);
    }
}
