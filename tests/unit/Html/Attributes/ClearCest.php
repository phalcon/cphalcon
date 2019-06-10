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

class ClearCest
{
    use DiTrait;

    /**
     * Unit Tests Phalcon\Html\Attributes :: clear()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-25
     */
    public function htmlAttributesClear(UnitTester $I)
    {
        $I->wantToTest('Html\Attributes - clear()');

        $expected = [
            'class' => 'form-control',
            'name'  => 'q',
            'value' => '',
        ];

        $attributes = new Attributes($expected);

        $actual = $attributes->toArray();

        $I->assertSame($expected, $actual);

        // clear
        $attributes->clear();

        $actual   = $attributes->toArray();
        $expected = [];

        $I->assertSame($expected, $actual);
    }
}
