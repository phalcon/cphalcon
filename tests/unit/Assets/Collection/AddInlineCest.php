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
use Phalcon\Assets\Inline;
use UnitTester;

/**
 * Class AddInlineCest
 *
 * @package Phalcon\Tests\Unit\Assets\Collection
 */
class AddInlineCest
{
    /**
     * Tests Phalcon\Assets\Collection :: addInline()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsCollectionAddInline(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - addInline()');

        $collection = new Collection();
        $inline     = new Inline('js', "alert('an amazing test');");
        $collection->addInline($inline);

        $codes = $collection->getCodes();

        $I->assertCount(1, $collection->getCodes());
        $I->assertEquals(end($codes), $inline);
    }
}
