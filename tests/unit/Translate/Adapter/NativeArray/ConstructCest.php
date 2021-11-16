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

use ArrayAccess;
use Phalcon\Tests\Fixtures\Traits\TranslateNativeArrayTrait;
use Phalcon\Translate\Adapter\AdapterInterface;
use Phalcon\Translate\Adapter\NativeArray;
use Phalcon\Translate\Exception;
use Phalcon\Translate\InterpolatorFactory;
use UnitTester;

/**
 * Class ConstructCest
 *
 * @package Phalcon\Tests\Unit\Translate\Adapter\NativeArray
 */
class ConstructCest
{
    use TranslateNativeArrayTrait;

    /**
     * Tests Phalcon\Translate\Adapter\NativeArray :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
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
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function translateAdapterNativeArrayContentParamExist(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\NativeArray - constructor without content throws exception');

        $I->expectThrowable(
            new Exception('Translation content was not provided'),
            function () {
                new NativeArray(new InterpolatorFactory(), []);
            }
        );
    }

    /**
     * Tests Phalcon\Translate\Adapter\NativeArray :: __construct() - Exception
     * content not array
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function translateAdapterNativeArrayContentNotArray(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\NativeArray - constructor with content not array throws exception');

        $I->expectThrowable(
            new Exception('Translation data must be an array'),
            function () {
                new NativeArray(
                    new InterpolatorFactory(),
                    [
                        'content' => 1234,
                    ]
                );
            }
        );
    }
}
