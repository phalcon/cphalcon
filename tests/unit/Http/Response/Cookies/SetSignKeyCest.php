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

class SetSignKeyCest extends HttpBase
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
     * Tests Phalcon\Http\Response\Cookies :: setSignKey()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-06
     */
    public function httpResponseCookiesSetSignKey(UnitTester $I)
    {
        $I->wantToTest('Http\Response\Cookies - setSignKey()');

        $sName  = 'framework';
        $sValue = 'phalcon';

        $this->setDiService('crypt');
        $container = $this->getDi();

        $oCookie = new Cookies();
        $oCookie->setDI($container);

        $oCookie->setSignKey("#1dj8$=dp?.ak//j1V$~%*0XaK\xb1\x8d\xa9\x98\x054t7w!z%C*F-Jk\x98\x05\\\x5c");

        $oCookieSign = new Cookies(true, "#1dj8$=dp?.ak//j1V$~%*0XaK\xb1\x8d\xa9\x98\x054t7w!z%C*F-Jk\x98\x05\\\x5c");
        $oCookieSign->setDI($container);

        $I->assertEquals($oCookie, $oCookieSign);
    }
}
