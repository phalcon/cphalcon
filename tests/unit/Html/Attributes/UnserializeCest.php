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

class UnserializeCest
{
    /**
     * Tests Phalcon\Html\Attributes :: unserialize()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-02
     */
    public function htmlAttributesUnserialize(UnitTester $I)
    {
        $I->wantToTest('Html\Attributes - unserialize()');

        $data = [
            'type'  => 'text',
            'class' => 'form-control',
            'name'  => 'q',
            'value' => '',
        ];

        $serialized = serialize($data);

        $attributes = new Attributes();

        $attributes->unserialize($serialized);

        $I->assertEquals(
            $data,
            $attributes->toArray()
        );
    }
}
