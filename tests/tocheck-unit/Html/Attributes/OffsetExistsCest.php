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

class OffsetExistsCest
{
    /**
     * Tests Phalcon\Html\Attributes :: offsetExists()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-02
     */
    public function htmlAttributesOffsetExists(UnitTester $I)
    {
        $I->wantToTest('Html\Attributes - offsetExists()');

        $data = [
            'type'  => 'text',
            'class' => 'form-control',
            'name'  => 'q',
            'value' => '',
        ];

        $attributes = new Attributes($data);

        $I->assertTrue(
            isset($attributes['class'])
        );

        $I->assertFalse(
            isset($attributes['unknown'])
        );

        $I->assertTrue(
            $attributes->offsetExists('class')
        );

        $I->assertFalse(
            $attributes->offsetExists('unknown')
        );
    }
}
