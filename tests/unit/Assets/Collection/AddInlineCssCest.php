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
 * Class AddInlineCssCest
 *
 * @package Phalcon\Tests\Unit\Assets\Collection
 */
class AddInlineCssCest
{
    /**
     * Tests Phalcon\Assets\Collection :: addInlineCss()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsCollectionAddInlineCss(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - addInlineCss()');

        $collection = new Collection();
        $collection->addInlineCss(".awesome{color: #8fc6bc}");

        $codes = $collection->getCodes();

        $I->assertCount(1, $collection->getCodes());
    }
}
