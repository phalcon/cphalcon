<?php

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

class ReplacePlaceholdersCest
{
    /**
     * Tests Phalcon\Translate\Interpolator\IndexedArray :: replacePlaceholders()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testReplacePlaceholders(UnitTester $I)
    {
        $interpolator = new IndexedArray();

        $expected = 'Hello, John D. Doe!';

        $stringFrom = 'Hello, %s %s %s!';
        $actual     = $interpolator->replacePlaceholders($stringFrom, ['John', 'D.', 'Doe']);


        $I->assertEquals($expected, $actual);
    }
}
