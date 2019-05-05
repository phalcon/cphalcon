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

class ReduceSlashesCest
{
    /**
     * Tests Phalcon\Text :: reduceSlashes()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function textReduceSlashes(UnitTester $I)
    {
        $I->wantToTest('Text - reduceSlashes()');

        $I->assertEquals(
            'app/controllers/IndexController',
            Text::reduceSlashes('app/controllers//IndexController')
        );

        $I->assertEquals(
            'http://foo/bar/baz/buz',
            Text::reduceSlashes('http://foo//bar/baz/buz')
        );

        $I->assertEquals(
            'php://memory',
            Text::reduceSlashes('php://memory')
        );

        $I->assertEquals(
            'http/https',
            Text::reduceSlashes('http//https')
        );
    }
}
