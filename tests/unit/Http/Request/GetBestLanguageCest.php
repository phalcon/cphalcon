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

namespace Phalcon\Test\Unit\Http\Request;

use Phalcon\Http\Request;
use UnitTester;

class GetBestLanguageCest
{
    /**
     * Tests Phalcon\Http\Request :: getBestLanguage()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function httpRequestGetBestLanguage(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getBestLanguage()');

        $store   = $_SERVER ?? [];
        $time    = $_SERVER['REQUEST_TIME_FLOAT'];
        $_SERVER = [
            'REQUEST_TIME_FLOAT'   => $time,
            'HTTP_ACCEPT_LANGUAGE' => 'es,es-ar;q=0.8,en;q=0.5,en-us;q=0.3,de-de; q=0.9',
        ];

        $request = new Request();

        $expected = 'es';
        $actual   = $request->getBestLanguage();
        $I->assertEquals($expected, $actual);

        $_SERVER = $store;
    }
}
