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

namespace Phalcon\Tests\Unit\Text;

use Phalcon\Text;
use UnitTester;

class LowerCest
{
    /**
     * Tests Phalcon\Text :: lower()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function textLower(UnitTester $I)
    {
        $I->wantToTest('Text - lower()');

        $I->assertEquals(
            'hello',
            Text::lower('hello')
        );

        $I->assertEquals(
            'hello',
            Text::lower('HELLO')
        );

        $I->assertEquals(
            '1234',
            Text::lower('1234')
        );
    }

    /**
     * Tests Phalcon\Text :: lower() - multi-bytes encoding
     *
     * @author Stanislav Kiryukhin <korsar.zn@gmail.com>
     * @since  2015-05-06
     */
    public function textLowerMultiBytesEncoding(UnitTester $I)
    {
        $I->wantToTest('Text - lower() - multi byte encoding');

        $I->assertEquals(
            'привет мир!',
            Text::lower('привет мир!')
        );

        $I->assertEquals(
            'привет мир!',
            Text::lower('ПриВЕт Мир!')
        );

        $I->assertEquals(
            'привет мир!',
            Text::lower('ПРИВЕТ МИР!')
        );

        $I->assertEquals(
            'männer',
            Text::lower('männer')
        );

        $I->assertEquals(
            'männer',
            Text::lower('mÄnnER')
        );

        $I->assertEquals(
            'männer',
            Text::lower('MÄNNER')
        );
    }
}
