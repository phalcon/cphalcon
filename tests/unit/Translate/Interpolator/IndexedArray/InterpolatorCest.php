<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Translate\Interpolator;

use Phalcon\Translate\Adapter\NativeArray;
use Phalcon\Translate\Interpolator\IndexedArray;
use UnitTester;

class InterpolatorCest
{
    /**
     * Tests Phalcon\Translate\Interpolator\IndexedArray :: objects
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function translateInterpolatorIndexedArrayInterpolator(UnitTester $I)
    {
        $I->wantToTest('Translate\Interpolator\IndexedArray - interpolator');
        $language   = [
            'Hello!'          => 'Привет!',
            'Hello %s %s %s!' => 'Привет, %s %s %s!',
        ];
        $params     = ['content' => $language, 'interpolator' => new IndexedArray()];
        $translator = new NativeArray($params);

        $expected = 'Привет, John D. Doe!';
        $actual   = $translator->_(
            'Hello %s %s %s!',
            [
                'John',
                'D.',
                'Doe',
            ]
        );

        $I->assertEquals($expected, $actual);
    }
}
