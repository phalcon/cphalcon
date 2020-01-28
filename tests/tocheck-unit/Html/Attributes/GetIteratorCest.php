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

class GetIteratorCest
{
    /**
     * Tests Phalcon\Html\Attributes :: getIterator()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-02
     */
    public function htmlAttributesGetIterator(UnitTester $I)
    {
        $I->wantToTest('Html\Attributes - getIterator()');

        $data = [
            'type'  => 'text',
            'class' => 'form-control',
            'name'  => 'q',
            'value' => '',
        ];

        $attributes = new Attributes($data);

        foreach ($attributes as $key => $value) {
            $I->assertEquals(
                $data[$key],
                $attributes[$key]
            );
        }
    }
}
