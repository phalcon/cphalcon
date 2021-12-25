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

class HasCest
{
    use TranslateNativeArrayTrait;

    /**
     * Tests Phalcon\Translate\Adapter\NativeArray :: has()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function translateAdapterNativeArrayHas(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\NativeArray - has()');

        $language = $this->getArrayConfig()['en'];

        $translator = new NativeArray(
            new InterpolatorFactory(),
            [
                'content' => $language,
            ]
        );

        $expected = $translator->exists('hi');
        $I->assertTrue($expected);
        $expected = $translator->has('hi');
        $I->assertTrue($expected);
    }
}
