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

class HasCest
{
    /**
     * Tests Phalcon\Html\Attributes :: has()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-02
     */
    public function htmlAttributesHas(UnitTester $I)
    {
        $I->wantToTest('Html\Attributes - has()');

        $data = [
            'type'  => 'text',
            'class' => 'form-control',
            'name'  => 'q',
            'value' => '',
        ];

        $attributes = new Attributes($data);

        $I->assertTrue(
            $attributes->has('class')
        );

        $I->assertTrue(
            $attributes->has('CLASS')
        );

        $I->assertFalse(
            $attributes->has('unknown')
        );
    }

    /**
     * Tests Phalcon\Html\Attributes :: has() - case sensitive
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-02
     */
    public function htmlAttributesHasCaseSensitive(UnitTester $I)
    {
        $I->wantToTest('Html\Attributes - has() - case sensitive');

        $data = [
            'type'  => 'text',
            'class' => 'form-control',
            'name'  => 'q',
            'value' => '',
        ];

        $attributes = new Attributes($data, false);

        $I->assertTrue(
            $attributes->has('class')
        );

        $I->assertFalse(
            $attributes->has('CLASS')
        );
    }
}
