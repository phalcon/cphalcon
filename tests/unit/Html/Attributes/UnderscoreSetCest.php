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

class UnderscoreSetCest
{
    use DiTrait;

    /**
     * Unit Tests Phalcon\Html\Attributes :: __set()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-25
     */
    public function htmlAttributesUnderscoreSet(UnitTester $I)
    {
        $I->wantToTest('Html\Attributes - __set()');

        $attributes = new Attributes([
            'class' => 'form-control',
            'name'  => 'q',
            'value' => '',
        ]);

        // overwrite name
        $expected = 'other name';
        $attributes->__set('name', $expected);

        $actual = $attributes->__get('name');
        $I->assertSame($expected, $actual);

        // set new
        $expected = 'other value';
        $attributes->__set('other-attr', $expected);

        $actual = $attributes->__get('other-attr');
        $I->assertSame($expected, $actual);
    }
}
