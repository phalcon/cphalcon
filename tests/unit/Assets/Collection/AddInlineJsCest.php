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
use Phalcon\Assets\Inline\Js;
use UnitTester;

/**
 * Class AddInlineJsCest
 *
 * @package Phalcon\Tests\Unit\Assets\Collection
 */
class AddInlineJsCest
{
    /**
     * Tests Phalcon\Assets\Collection :: addInlineJs()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsCollectionAddInlineJs(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - addInlineJs()');

        $collection = new Collection();
        $collection->addInlineJs("alert('an amazing test');");

        $codes = $collection->getCodes();

        $I->assertCount(1, $collection->getCodes());
    }
}
