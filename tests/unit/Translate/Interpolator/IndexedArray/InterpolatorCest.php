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

use Phalcon\Translate\Adapter\NativeArray;
use Phalcon\Translate\InterpolatorFactory;
use UnitTester;

/**
 * Class InterpolatorCest
 *
 * @package Phalcon\Tests\Unit\Translate\Interpolator\IndexedArray
 */
class InterpolatorCest
{
    /**
     * Tests Phalcon\Translate\Interpolator\IndexedArray :: objects
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function translateInterpolatorIndexedArrayInterpolator(UnitTester $I)
    {
        $I->wantToTest('Translate\Interpolator\IndexedArray - interpolator');

        $language = [
            'Hello!'          => 'Привет!',
            'Hello %s %s %s!' => 'Привет, %s %s %s!',
        ];

        $params = [
            'content'             => $language,
            'defaultInterpolator' => 'indexedArray',
        ];

        $translator = new NativeArray(
            new InterpolatorFactory(),
            $params
        );

        $actual = $translator->_(
            'Hello %s %s %s!',
            [
                'John',
                'D.',
                'Doe',
            ]
        );

        $I->assertEquals(
            'Привет, John D. Doe!',
            $actual
        );
    }
}
