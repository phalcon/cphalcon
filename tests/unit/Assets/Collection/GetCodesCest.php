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
use Phalcon\Assets\Inline\Css;
use UnitTester;

/**
 * Class GetCodesCest
 *
 * @package Phalcon\Tests\Unit\Assets\Collection
 */
class GetCodesCest
{
    /**
     * Tests Phalcon\Assets\Collection :: getCodes()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsCollectionGetCodes(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - getCodes()');

        $collection = new Collection();
        $inline     = new Css(".test{color: #8fc6bc}");
        $collection->addInline($inline);

        $codes = $collection->getCodes();

        $I->assertCount(1, $collection->getCodes());
        $I->assertEquals(end($codes), $inline);
    }
}
