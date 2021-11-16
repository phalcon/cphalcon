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

namespace Phalcon\Tests\Unit\Assets\Collection;

use Phalcon\Assets\Collection;
use UnitTester;

/**
 * Class GetSetAttributesCest
 *
 * @package Phalcon\Tests\Unit\Assets\Collection
 */
class GetSetAttributesCest
{
    /**
     * Tests Phalcon\Assets\Collection :: getAttributes() / setAttributes()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsCollectionGetSetAttributes(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - getAttributes() / setAttributes');

        $collection = new Collection();
        $attributes = [
            'data-name' => 'phalcon',
            'data-type' => 'book',
        ];

        $I->assertEquals([], $collection->getAttributes());
        $collection->setAttributes($attributes);

        $I->assertEquals($attributes, $collection->getAttributes());
    }
}
