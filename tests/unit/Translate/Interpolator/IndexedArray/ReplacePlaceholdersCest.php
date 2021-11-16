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

namespace Phalcon\Tests\Unit\Translate\Interpolator\IndexedArray;

use Phalcon\Translate\Interpolator\IndexedArray;
use UnitTester;

/**
 * Class ReplacePlaceholdersCest
 *
 * @package Phalcon\Tests\Unit\Translate\Interpolator\IndexedArray
 */
class ReplacePlaceholdersCest
{
    /**
     * Tests Phalcon\Translate\Interpolator\IndexedArray ::
     * replacePlaceholders()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function translateInterpolatorIndexedarrayReplacePlaceholders(UnitTester $I)
    {
        $I->wantToTest('Translate\Interpolator\IndexedArray - replacePlaceholders()');

        $interpolator = new IndexedArray();

        $actual = $interpolator->replacePlaceholders(
            'Hello, %s %s %s!',
            [
                'John',
                'D.',
                'Doe',
            ]
        );

        $I->assertEquals(
            'Hello, John D. Doe!',
            $actual
        );
    }

    /**
     * Tests Phalcon\Translate\Interpolator\IndexedArray ::
     * replacePlaceholders() with no placeholders
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function translateInterpolatorIndexedarrayReplacePlaceholdersWithNoPlaceholders(UnitTester $I)
    {
        $I->wantToTest('Translate\Interpolator\IndexedArray - replacePlaceholders() - with no placeholders');

        $interpolator = new IndexedArray();

        $source   = 'Hello, %s %s %s!';
        $expected = $source;
        $actual   = $interpolator->replacePlaceholders('Hello, %s %s %s!', []);
        $I->assertEquals($expected, $actual);
    }
}
