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

class ResetCest extends HttpBase
{
    use CookieTrait;

    /**
     * executed before each test
     */
    public function _before(UnitTester $I)
    {
        parent::_before($I);
        $this->setDiService('sessionStream');
        ;
    }

    /**
     * Tests Phalcon\Http\Response\Cookies :: reset()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-06
     */
    public function httpResponseCookiesReset(UnitTester $I)
    {
        $I->wantToTest('Http\Response\Cookies - reset()');

        $sName  = 'framework';
        $sValue = 'phalcon';

        $this->setDiService('crypt');
        $container = $this->getDi();

        $oCookie = new Cookies();
        $oCookie->setDI($container);
        $oCookie->set($sName, $sValue);

        $aCookies = $oCookie->getCookies();

        $I->assertTrue(array_key_exists($sName, $aCookies));

        $I->assertEquals($sValue, $aCookies[$sName]);

        $I->assertEquals(1, count($aCookies));

        $oCookie->reset();

        $I->assertEquals([], $oCookie->getCookies());
    }
}
