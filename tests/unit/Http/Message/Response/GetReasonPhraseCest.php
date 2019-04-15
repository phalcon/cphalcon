<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Message\Response;

use Phalcon\Http\Message\Response;
use UnitTester;

/**
 * Class GetReasonPhraseCest
 */
class GetReasonPhraseCest
{
    /**
     * Tests Phalcon\Http\Message\Response :: getReasonPhrase()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-09
     */
    public function httpMessageResponseGetReasonPhrase(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - getReasonPhrase()');
        $response = new Response();

        $expected = "OK";
        $actual   = $response->getReasonPhrase();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\Response :: getReasonPhrase() - other port
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-09
     */
    public function httpMessageResponseGetReasonPhraseOtherPort(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - getReasonPhrase() - other port');
        $response = new Response("php://memory", 420);

        $expected = "Enhance Your Calm";
        $actual   = $response->getReasonPhrase();
        $I->assertEquals($expected, $actual);
    }
}
