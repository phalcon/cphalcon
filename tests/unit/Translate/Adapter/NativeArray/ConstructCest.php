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

namespace Phalcon\Test\Unit\Translate\Adapter\NativeArray;

use ArrayAccess;
use Phalcon\Test\Fixtures\Traits\TranslateTrait;
use Phalcon\Translate\Adapter\NativeArray;
use Phalcon\Translate\AdapterInterface;
use Phalcon\Translate\Exception;
use UnitTester;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    use TranslateTrait;

    /**
     * Tests Phalcon\Translate\Adapter\NativeArray :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function translateAdapterNativeArrayConstruct(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\NativeArray - constructor');
        $language   = $this->getArrayConfig()['en'];
        $translator = new NativeArray(['content' => $language]);

        $class = ArrayAccess::class;
        $I->assertInstanceOf($class, $translator);

        $class = AdapterInterface::class;
        $I->assertInstanceOf($class, $translator);
    }

    /**
     * Tests Phalcon\Translate\Adapter\NativeArray :: __construct() - Exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function translateAdapterNativeArrayContentParamExist(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\NativeArray - constructor without content throws exception');
        $I->expectThrowable(
            new Exception("Translation content was not provided"),
            function () {
                new NativeArray([]);
            }
        );
    }
}
