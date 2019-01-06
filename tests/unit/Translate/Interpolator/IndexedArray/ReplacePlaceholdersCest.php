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

namespace Phalcon\Test\Unit\Translate\Interpolator\IndexedArray;

use Phalcon\Translate\Interpolator\IndexedArray;
use UnitTester;

/**
 * Class ReplacePlaceholdersCest
 */
class ReplacePlaceholdersCest
{
    /**
     * Tests Phalcon\Translate\Interpolator\IndexedArray ::
     * replacePlaceholders()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function translateInterpolatorIndexedarrayReplacePlaceholders(UnitTester $I)
    {
        $I->wantToTest('Translate\Interpolator\IndexedArray - replacePlaceholders()');
        $interpolator = new IndexedArray();

        $expected = 'Hello, John D. Doe!';

        $stringFrom = 'Hello, %s %s %s!';
        $actual     = $interpolator->replacePlaceholders($stringFrom, ['John', 'D.', 'Doe']);


        $I->assertEquals($expected, $actual);
    }
}
