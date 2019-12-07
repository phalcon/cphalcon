<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Response;

use Phalcon\Http\Response;
use UnitTester;

class SetJsonContentCest
{
    /**
     * Tests Phalcon\Http\Response :: setJsonContent()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2019-12-07
    */
    public function httpResponseSetJsonContent(UnitTester $I)
    {
        $I->wantToTest('Http\Response - setJsonContent()');

        $aData = [
            'sentence'  => 'it\'s a "city"',
            'word'      => '<h1>city</h1>'
        ];

        $oResponse = new Response();
        $oResponse->setJsonContent($aData);

        //Check content
        $I->assertSame(
            $oResponse->getContent(),
            json_encode($aData)
        );

        //Check Header
        $I->assertSame(
            $oResponse->getHeaders()->get('Content-Type'),
            "application/json; charset=UTF-8"
        );

        //With option
        $oResponse2 = new Response();
        $oResponse2->setJsonContent($aData, JSON_HEX_TAG);

        $I->assertSame(
            $oResponse2->getContent(),
            json_encode($aData, JSON_HEX_TAG)
        );
    }
}
