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

namespace Phalcon\Test\Unit\Translate\Adapter\NativeArray;

use Phalcon\Test\Fixtures\Traits\TranslateArrayTrait;
use Phalcon\Translate\Adapter\NativeArray;
use Phalcon\Translate\InterpolatorFactory;
use UnitTester;

class ArrayAccessCest
{
    use TranslateArrayTrait;

    /**
     * Tests Phalcon\Translate\Adapter\NativeArray :: array access
     *
     * @author Nikos Dimopoulos <nikos@phalcon.io>
     * @since  2014-09-12
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

        $I->assertTrue(
            isset(
                $translator['Hello!']
            )
        );

        $I->assertFalse(
            isset(
                $translator['Hi there!']
            )
        );

        $I->assertEquals(
            $language['Hello!'],
            $translator['Hello!']
        );
    }
}
