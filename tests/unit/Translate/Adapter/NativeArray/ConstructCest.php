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

use ArrayAccess;
use Phalcon\Test\Fixtures\Traits\TranslateArrayTrait;
use Phalcon\Translate\Adapter\AdapterInterface;
use Phalcon\Translate\Adapter\NativeArray;
use Phalcon\Translate\Exception;
use Phalcon\Translate\InterpolatorFactory;
use UnitTester;

class ConstructCest
{
    use TranslateArrayTrait;

    /**
     * Tests Phalcon\Translate\Adapter\NativeArray :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function translateAdapterNativeArrayConstruct(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\NativeArray - constructor');

        $language = $this->getArrayConfig()['en'];

        $translator = new NativeArray(
            new InterpolatorFactory(),
            [
                'content' => $language,
            ]
        );

        $I->assertInstanceOf(
            ArrayAccess::class,
            $translator
        );

        $I->assertInstanceOf(
            AdapterInterface::class,
            $translator
        );
    }

    /**
     * Tests Phalcon\Translate\Adapter\NativeArray :: __construct() - Exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function translateAdapterNativeArrayContentParamExist(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\NativeArray - constructor without content throws exception');

        $I->expectThrowable(
            new Exception('Translation content was not provided'),
            function () {
                new NativeArray(
                    new InterpolatorFactory(),
                    []
                );
            }
        );
    }
}
