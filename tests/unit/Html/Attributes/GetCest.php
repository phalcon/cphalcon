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

class GetCest
{
    /**
     * Tests Phalcon\Html\Attributes :: get()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-02
     */
    public function htmlAttributesGet(UnitTester $I)
    {
        $I->wantToTest('Html\Attributes - get()');

        $data = [
            'type'  => 'text',
            'class' => 'form-control',
            'name'  => 'q',
            'value' => '',
        ];

        $attributes = new Attributes($data);

        $expected = 'form-control';

        $I->assertEquals(
            $expected,
            $attributes->get('class')
        );

        $I->assertEquals(
            $expected,
            $attributes->get('CLASS')
        );

        $I->assertEquals(
            $expected,
            $attributes->get('unknown', 'form-control')
        );
    }
}
