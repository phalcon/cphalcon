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
 * Class GetSetTargetPathCest
 *
 * @package Phalcon\Tests\Unit\Assets\Collection
 */
class GetSetTargetPathCest
{
    /**
     * Tests Phalcon\Assets\Collection :: getTargetPath() / setTargetPath()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsCollectionGetSetTargetPath(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - getTargetPath() / setTargetPath()');

        $collection = new Collection();
        $targetPath = '/assets';
        $collection->setTargetPath($targetPath);

        $I->assertEquals($targetPath, $collection->getTargetPath());
    }
}
