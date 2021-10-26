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

namespace Phalcon\Tests\Unit\Support\Helper\Str;

use Phalcon\Support\Helper\Str\ReduceSlashes;
use UnitTester;

/**
 * Class ReduceSlashesCest
 *
 * @package Phalcon\Tests\Unit\Support\Helper\Str
 */
class ReduceSlashesCest
{
    /**
     * Tests Phalcon\Support\Helper\Str :: reduceSlashes()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperStrReduceSlashes(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Str - reduceSlashes()');

        $object = new ReduceSlashes();

        $expected = 'app/controllers/IndexController';
        $actual   = $object('app/controllers//IndexController');
        $I->assertEquals($expected, $actual);

        $expected = 'http://foo/bar/baz/buz';
        $actual   = $object('http://foo//bar/baz/buz');
        $I->assertEquals($expected, $actual);

        $expected = 'php://memory';
        $actual   = $object('php://memory');
        $I->assertEquals($expected, $actual);

        $expected = 'http/https';
        $actual   = $object('http//https');
        $I->assertEquals($expected, $actual);
    }
}
