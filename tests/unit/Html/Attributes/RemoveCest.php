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

namespace Phalcon\Tests\Unit\Html\Attributes;

use Phalcon\Html\Attributes;
use UnitTester;

class RemoveCest
{
    /**
     * Tests Phalcon\Html\Attributes :: remove()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-02
     */
    public function htmlAttributesRemove(UnitTester $I)
    {
        $I->wantToTest('Html\Attributes - remove()');

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


        $attributes->remove('class');

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
