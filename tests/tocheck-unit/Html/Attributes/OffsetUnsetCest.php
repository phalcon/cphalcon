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

namespace Phalcon\Test\Unit\Html\Attributes;

use Phalcon\Html\Attributes;
use UnitTester;

class OffsetUnsetCest
{
    /**
     * Tests Phalcon\Html\Attributes :: offsetUnset()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-02
     */
    public function htmlAttributesOffsetUnset(UnitTester $I)
    {
        $I->wantToTest('Html\Attributes - offsetUnset()');

        $data = [
            'type'  => 'text',
            'class' => 'form-control',
            'name'  => 'q',
            'value' => '',
        ];

        $attributes = new Attributes($data);

        $I->assertEquals(
            $data,
            $attributes->toArray()
        );


        unset($attributes['class']);

        $expected = [
            'type'  => 'text',
            'name'  => 'q',
            'value' => '',
        ];

        $I->assertEquals(
            $expected,
            $attributes->toArray()
        );
    }
}
