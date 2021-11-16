<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Http\Response;

use Phalcon\Http\Response;
use UnitTester;

class GetSetContentCest
{
    /**
     * Tests Phalcon\Http\Response :: getContent() / setContent()
     *
     * @param  UnitTester $I
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2019-12-08
     */
    public function httpResponseGetSetContent(UnitTester $I)
    {
        $I->wantToTest('Http\Response - getContent() / setContent()');

        $sData = '<h1>Phalcon book 2020</h1>';

        $oResponse = new Response();
        $I->assertEquals('', $oResponse->getContent());

        $oResponse->setContent($sData);
        $I->assertSame(
            $sData,
            $oResponse->getContent()
        );
    }
}
