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

class ConstructCest
{
    /**
     * Tests Phalcon\Http\Response :: __construct()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2019-12-08
    */
    public function httpResponseConstruct(UnitTester $I)
    {
        $I->wantToTest('Http\Response - __construct()');

        $oResponse = new Response();

        $I->assertInstanceOf(
            Response::class,
            $oResponse
        );
    }

    /**
     * Tests Phalcon\Http\Response :: __construct(content = null)
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2019-12-08
    */
    public function httpResponseConstructWithContent(UnitTester $I)
    {
        $I->wantToTest('Http\Response - __construct(content = null)');

        $aData = [
            'user' => 'jeremy'
        ];

        $oResponse = new Response($aData);

        $I->assertSame(
            $aData,
            $oResponse->getContent()
        );
    }

    /**
     * Tests Phalcon\Http\Response :: __construct(content = null, code = null)
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2019-12-08
    */
    public function httpResponseConstructWithContentCode(UnitTester $I)
    {
        $I->wantToTest('Http\Response - __construct(content = null, code = null)');

        $aData = [
            'user' => 'jeremy'
        ];

        $nCodeSuccess = 200;

        $oResponse = new Response($aData, $nCodeSuccess);

        $I->assertSame(
            $aData,
            $oResponse->getContent()
        );

        $I->assertSame(
            $nCodeSuccess,
            $oResponse->getStatusCode()
        );

        //Check Status message
        $I->assertSame(
            '200 OK',
            $oResponse->getHeaders()->get('Status')
        );
    }

    /**
     * Tests Phalcon\Http\Response :: __construct(content = null, code = null, status = null)
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2019-12-08
    */
    public function httpResponseConstructWithContentCodeStatus(UnitTester $I)
    {
        $I->wantToTest('Http\Response - __construct(content = null, code = null, status = null)');

        $aData = [
            'user' => 'jeremy'
        ];

        $nCodeSuccess = 200;

        $oResponse = new Response($aData, $nCodeSuccess, 'Success');

        $I->assertSame(
            $aData,
            $oResponse->getContent()
        );

        $I->assertSame(
            $nCodeSuccess,
            $oResponse->getStatusCode()
        );

        //Check Status message
        $I->assertSame(
            '200 Success',
            $oResponse->getHeaders()->get('Status')
        );
    }
}
