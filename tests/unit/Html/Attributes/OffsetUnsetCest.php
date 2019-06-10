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

class OffsetUnsetCest
{
    use DiTrait;

    /**
     * Unit Tests Phalcon\Html\Attributes :: offsetUnset()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-25
     */
    public function htmlAttributesOffsetUnset(UnitTester $I)
    {
        $I->wantToTest('Html\Attributes - offsetUnset()');

        $attributes = new Attributes([
            'class' => 'form-control',
            'name'  => 'q',
            'value' => '',
        ]);

        // name attribute exists
        $actual = $attributes->has('name');

        $I->assertTrue($actual);

        // unset attribute name
        $attributes->offsetUnset('name');
        $actual = $attributes->has('name');

        $I->assertFalse($actual);
    }
}
