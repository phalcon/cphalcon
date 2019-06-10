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

class OffsetGetCest
{
    use DiTrait;

    /**
     * Unit Tests Phalcon\Html\Attributes :: offsetGet()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-25
     */
    public function htmlAttributesOffsetGet(UnitTester $I)
    {
        $I->wantToTest('Html\Attributes - offsetGet()');

        $attributes = new Attributes([
            'class' => 'form-control',
            'name'  => 'q',
            'value' => '',
        ]);

        $expected = 'q';
        $actual   = $attributes->offsetGet('name');
        $I->assertSame($expected, $actual);

        $expected = null;
        $actual   = $attributes->offsetGet('non-exists');
        $I->assertSame($expected, $actual);

        $expected = 'q';
        $actual   = $attributes['name'];
        $I->assertSame($expected, $actual);

        $expected = null;
        $actual   = $attributes['non-exists'];
        $I->assertSame($expected, $actual);
    }
}
