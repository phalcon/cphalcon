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

class ToStringCest
{
    use DiTrait;

    /**
     * Unit Tests Phalcon\Html\Attributes :: __toString()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-25
     */
    public function htmlAttributesToString(UnitTester $I)
    {
        $I->wantToTest('Html\Attributes - __toString()');

        $attributes = new Attributes(
            [
                'class' => 'form-control',
                'name'  => 'q',
                'value' => '',
            ]
        );

        // __toString
        $expected = ' name="q" value="" class="form-control"';
        $actual   = $attributes->__toString();

        $I->assertSame($expected, $actual);

        // (string)
        $actual = (string) $attributes;

        $I->assertSame($expected, $actual);
    }
}
