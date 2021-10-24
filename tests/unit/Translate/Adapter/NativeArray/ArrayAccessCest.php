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

namespace Phalcon\Tests\Unit\Translate\Adapter\NativeArray;

use Phalcon\Tests\Fixtures\Traits\TranslateNativeArrayTrait;
use Phalcon\Translate\Adapter\NativeArray;
use Phalcon\Translate\InterpolatorFactory;
use UnitTester;

/**
 * Class ArrayAccessCest
 *
 * @package Phalcon\Tests\Unit\Translate\Adapter\NativeArray
 */
class ArrayAccessCest
{
    use TranslateNativeArrayTrait;

    /**
     * Tests Phalcon\Translate\Adapter\NativeArray :: array access
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function translateAdapterNativeArrayWithArrayAccess(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\NativeArray - array access');

        $language = $this->getArrayConfig()['ru'];

        $translator = new NativeArray(
            new InterpolatorFactory(),
            [
                'content' => $language,
            ]
        );

        $actual = isset($translator['Hello!']);
        $I->assertTrue($actual);

        $actual = isset($translator['Hi there!']);
        $I->assertFalse($actual);

        $expected = $language['Hello!'];
        $actual   = $translator['Hello!'];
        $I->assertEquals($expected, $actual);
    }
}
