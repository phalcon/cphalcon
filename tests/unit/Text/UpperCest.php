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
 * Class UpperCest
 */
class UpperCest
{
    /**
     * Tests Phalcon\Text :: upper()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function textUpper(UnitTester $I)
    {
        $I->wantToTest('Text - upper()');

        $I->assertEquals(
            'HELLO',
            Text::upper('hello')
        );

        $I->assertEquals(
            'HELLO',
            Text::upper('HELLO')
        );

        $I->assertEquals(
            '1234',
            Text::upper('1234')
        );
    }

    /**
     * Tests Phalcon\Text :: upper() - multi-bytes encoding
     *
     * @param UnitTester $I
     *
     * @author Stanislav Kiryukhin <korsar.zn@gmail.com>
     * @since  2015-05-06
     */
    public function textUpperMultiBytesEncoding(UnitTester $I)
    {
        $I->wantToTest('Text - upper() - multi byte encoding');

        $I->assertEquals(
            'ПРИВЕТ МИР!',
            Text::upper('ПРИВЕТ МИР!')
        );

        $I->assertEquals(
            'ПРИВЕТ МИР!',
            Text::upper('ПриВЕт Мир!')
        );

        $I->assertEquals(
            'ПРИВЕТ МИР!',
            Text::upper('привет мир!')
        );

        $I->assertEquals(
            'MÄNNER',
            Text::upper('MÄNNER')
        );

        $I->assertEquals(
            'MÄNNER',
            Text::upper('mÄnnER')
        );

        $I->assertEquals(
            'MÄNNER',
            Text::upper('männer')
        );
    }
}
