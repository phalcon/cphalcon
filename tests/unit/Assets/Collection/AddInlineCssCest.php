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
use Phalcon\Assets\Inline\Css;
use UnitTester;

class AddInlineCssCest
{
    /**
     * Tests Phalcon\Assets\Collection :: addInlineCss()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-02-06
     */
    public function assetsCollectionAddInlineCss(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - addInlineCss()');

        $collection = new Collection();

        $inline = new Css(".awesome{color: #8fc6bc}");

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
