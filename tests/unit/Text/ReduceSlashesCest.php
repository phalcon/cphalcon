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

namespace Phalcon\Test\Unit\Text;

use Phalcon\Text;
use UnitTester;

/**
 * Class ReduceSlashesCest
 */
class ReduceSlashesCest
{
    /**
     * Tests Phalcon\Text :: reduceSlashes()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function textReduceSlashes(UnitTester $I)
    {
        $I->wantToTest('Text - reduceSlashes()');
        $expected = 'app/controllers/IndexController';
        $actual   = Text::reduceSlashes('app/controllers//IndexController');
        $I->assertEquals($expected, $actual);

        $expected = 'http://foo/bar/baz/buz';
        $actual   = Text::reduceSlashes('http://foo//bar/baz/buz');
        $I->assertEquals($expected, $actual);

        $expected = 'php://memory';
        $actual   = Text::reduceSlashes('php://memory');
        $I->assertEquals($expected, $actual);

        $expected = 'http/https';
        $actual   = Text::reduceSlashes('http//https');
        $I->assertEquals($expected, $actual);
    }
}
