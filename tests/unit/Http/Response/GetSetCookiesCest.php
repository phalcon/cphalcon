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

namespace Phalcon\Tests\Unit\Http\Response;

use Phalcon\Http\Response;
use Phalcon\Http\Response\Cookies;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use UnitTester;

class GetSetCookiesCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Http\Response :: getCookies() / setCookies()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2019-12-08
     */
    public function httpResponseGetSetCookies(UnitTester $I)
    {
        $I->wantToTest('Http\Response - getCookies() / setCookies');

        $this->setNewFactoryDefault();

        $oCookies = new Cookies();
        $oCookies->setDI($this->container);
        $oCookies->set('firstname', 'jeremy');

        $oResponse = new Response();
        $oResponse->setCookies($oCookies);

        $I->assertSame(
            $oCookies,
            $oResponse->getCookies()
        );
    }
}
