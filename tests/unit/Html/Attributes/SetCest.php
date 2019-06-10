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

class SetCest
{
    use DiTrait;

    /**
     * Unit Tests Phalcon\Html\Attributes :: set()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-25
     */
    public function htmlAttributesSet(UnitTester $I)
    {
        $I->wantToTest('Html\Attributes - set()');

        $attributes = new Attributes([
            'class' => 'form-control',
            'name'  => 'q',
            'value' => '',
        ]);

        // overwrite name
        $expected = 'other name';
        $attributes->set('name', $expected);

        $actual = $attributes->offsetGet('name');
        $I->assertSame($expected, $actual);

        // set new
        $expected = 'other value';
        $attributes->set('other-attr', $expected);

        $actual = $attributes->offsetGet('other-attr');
        $I->assertSame($expected, $actual);
    }
}
