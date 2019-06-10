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

namespace Phalcon\Test\Unit\Html\Attributes;

use Phalcon\Html\Attributes;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

class CountCest
{
    use DiTrait;

    /**
     * Unit Tests Phalcon\Html\Attributes :: count()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-25
     */
    public function htmlAttributesCount(UnitTester $I)
    {
        $I->wantToTest('Html\Attributes - count()');

        $attributes = new Attributes([
            'class' => 'form-control',
            'name'  => 'q',
            'value' => '',
        ]);

        $expected = 3;
        $actual   = $attributes->count();

        $I->assertSame($expected, $actual);

        $expected = 4;
        $attributes->set('other', 1234);
        $actual = $attributes->count();

        $I->assertSame($expected, $actual);

        $expected = 3;
        $attributes->remove('other');
        $actual = $attributes->count();

        $I->assertSame($expected, $actual);
    }
}
