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

namespace Phalcon\Tests\Unit\Helper\Str;

use Phalcon\Helper\Str;
use UnitTester;

class ReduceSlashesCest
{
    /**
     * Tests Phalcon\Helper\Str :: reduceSlashes()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-06
     */
    public function helperStrReduceSlashes(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - reduceSlashes()');
        $expected = 'app/controllers/IndexController';
        $actual   = Str::reduceSlashes('app/controllers//IndexController');
        $I->assertEquals($expected, $actual);

        $expected = 'http://foo/bar/baz/buz';
        $actual   = Str::reduceSlashes('http://foo//bar/baz/buz');
        $I->assertEquals($expected, $actual);

        $expected = 'php://memory';
        $actual   = Str::reduceSlashes('php://memory');
        $I->assertEquals($expected, $actual);

        $expected = 'http/https';
        $actual   = Str::reduceSlashes('http//https');
        $I->assertEquals($expected, $actual);
    }
}
