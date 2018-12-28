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

use Phalcon\Test\Fixtures\Traits\TranslateTrait;
use Phalcon\Translate\Adapter\NativeArray;
use UnitTester;

/**
 * Class ArrayAccessCest
 */
class ArrayAccessCest
{
    use TranslateTrait;

    /**
     * Tests Phalcon\Translate\Adapter\NativeArray :: array access
     *
     * @param UnitTester $I
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-12
     */
    public function translateAdapterNativeArrayWithArrayAccess(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\NativeArray - array access');
        $language   = $this->getArrayConfig()['ru'];
        $translator = new NativeArray(['content' => $language]);

        $actual = isset($translator['Hello!']);
        $I->assertTrue($actual);

        $actual = isset($translator['Hi there!']);
        $I->assertFalse($actual);

        $expected = $language['Hello!'];
        $actual   = $translator['Hello!'];
        $I->assertEquals($expected, $actual);
    }
}
