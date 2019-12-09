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

namespace Phalcon\Test\Unit\Text;

use Phalcon\Text;
use UnitTester;

class IncrementCest
{
    /**
     * Tests Phalcon\Text :: increment() - string
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function textIncrementSimpleString(UnitTester $I)
    {
        $I->wantToTest('Text - increment() - string');

        $source = 'file';

        $I->assertEquals(
            'file_1',
            Text::increment($source)
        );
    }

    /**
     * Tests Phalcon\Text :: increment() - already incremented string
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function textIncrementAlreadyIncremented(UnitTester $I)
    {
        $I->wantToTest('Text - increment() - already incremented string');

        $source = 'file_1';

        $I->assertEquals(
            'file_2',
            Text::increment($source)
        );
    }

    /**
     * Tests Phalcon\Text :: increment() - already incremented string twice
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function textIncrementAlreadyIncrementedTwice(UnitTester $I)
    {
        $I->wantToTest('Text - increment() - already incremented string twice');

        $source = 'file_2';

        $I->assertEquals(
            'file_3',
            Text::increment($source)
        );
    }

    /**
     * Tests Phalcon\Text :: increment() - string with underscore
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function textIncrementStringWithUnderscore(UnitTester $I)
    {
        $I->wantToTest('Text - increment() - string with underscore');

        $source = 'file_';

        $I->assertEquals(
            'file_1',
            Text::increment($source)
        );
    }

    /**
     * Tests Phalcon\Text :: increment() - string with a space at the end
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function textIncrementStringWithSpace(UnitTester $I)
    {
        $I->wantToTest('Text - increment() - string with a space at the end');

        $source = 'file ';

        $I->assertEquals(
            'file _1',
            Text::increment($source)
        );
    }

    /**
     * Tests Phalcon\Text :: increment() - different separator
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function textIncrementStringWithDifferentSeparator(UnitTester $I)
    {
        $I->wantToTest('Text - increment() - string with different separator');

        $source = 'file';

        $I->assertEquals(
            'file-1',
            Text::increment($source, '-')
        );
    }
}
