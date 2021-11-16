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

namespace Phalcon\Tests\Unit\Http\Request;

use Phalcon\Http\Request;
use UnitTester;

class GetContentTypeCest
{
    /**
     * Tests Phalcon\Http\Request :: getContentType()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function httpRequestGetContentType(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getContentType()');

        $store   = $_SERVER ?? [];
        $time    = $_SERVER['REQUEST_TIME_FLOAT'];
        $_SERVER = [
            'REQUEST_TIME_FLOAT' => $time,
            'CONTENT_TYPE'       => 'application/xhtml+xml',
        ];

        $request = new Request();

        $expected = 'application/xhtml+xml';
        $actual   = $request->getContentType();
        $I->assertEquals($expected, $actual);

        $_SERVER = $store;
    }
}
