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
use Phalcon\Assets\Inline\Js;
use UnitTester;

class AddInlineJsCest
{
    /**
     * Tests Phalcon\Assets\Collection :: addInlineJs()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-02-06
     */
    public function assetsCollectionAddInlineJs(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - addInlineJs()');

        $collection = new Collection();

        $inline = new Js("alert('an amazing test');");

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
