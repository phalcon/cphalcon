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
 * Class UnderscoreCest
 */
class UnderscoreCest
{
    /**
     * Tests Phalcon\Text :: underscore()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function textUnderscore(UnitTester $I)
    {
        $I->wantToTest('Text - underscore()');

        $I->assertEquals(
            'start_a_horse',
            Text::underscore('start a horse')
        );

        $I->assertEquals(
            'five_cats',
            Text::underscore("five\tcats")
        );

        $I->assertEquals(
            'look_behind',
            Text::underscore(' look behind ')
        );

        $I->assertEquals(
            'Awesome_Phalcon',
            Text::underscore(" \t Awesome \t  \t Phalcon ")
        );
    }
}
