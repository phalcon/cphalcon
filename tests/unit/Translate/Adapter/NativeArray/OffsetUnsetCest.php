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
use Phalcon\Translate\Exception;
use Phalcon\Translate\InterpolatorFactory;
use UnitTester;

class OffsetUnsetCest
{
    use TranslateArrayTrait;

    /**
     * Tests Phalcon\Translate\Adapter\NativeArray :: offsetUnset()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function translateAdapterNativeArrayOffsetUnset(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\NativeArray - offsetUnset() throws exception');

        $I->expectThrowable(
            new Exception('Translate is an immutable ArrayAccess object'),
            function () {
                $language = $this->getArrayConfig()['en'];

                $translator = new NativeArray(
                    new InterpolatorFactory(),
                    [
                        'content' => $language,
                    ]
                );

                $translator->offsetUnset('hi');
            }
        );
    }
}
