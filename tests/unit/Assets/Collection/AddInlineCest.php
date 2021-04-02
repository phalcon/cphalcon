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
use Phalcon\Assets\Inline;
use UnitTester;

class AddInlineCest
{
    /**
     * Tests Phalcon\Assets\Collection :: addInline()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-02-06
     */
    public function assetsCollectionAddInline(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - addInline()');

        $collection = new Collection();

        $inline = new Inline("js", "alert('an amazing test');");

        $collection->addInline(
            $inline
        );

        $codes = $collection->getCodes();

        $I->assertCount(1, $collection->getCodes());

        $I->assertEquals(
            end($codes),
            $inline
        );
    }
}
