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

namespace Phalcon\Test\Unit\Assets\Collection;

use Phalcon\Assets\Collection;
use UnitTester;

class GetSetAttributesCest
{
    /**
     * Tests Phalcon\Assets\Collection :: getAttributes() / setAttributes()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-02-15
     */
    public function assetsCollectionGetSetAttributes(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - getAttributes() / setAttributes');

        $collection = new Collection();

        $attributes = [
            'data-name' => 'phalon',
            'data-type' => 'book'
        ];

        $I->assertEquals([], $collection->getAttributes());

        $collection->setAttributes($attributes);

        $I->assertEquals($attributes, $collection->getAttributes());
    }
}
