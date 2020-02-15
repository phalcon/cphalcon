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

use function dataDir;

class GetRealTargetPathCest
{
    /**
     * Tests Phalcon\Assets\Collection :: getRealTargetPath()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-02-15
     */
    public function assetsCollectionGetRealTargetPath(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - getRealTargetPath()');

        $collection = new Collection();

        $targetPath = '/assets';

        $basePath = dataDir('assets');

        $constructRealPath = realpath($basePath . $targetPath);

        $collection->setTargetPath($targetPath);

        $realBasePath = $collection->getRealTargetPath($basePath);

        $I->assertEquals($constructRealPath, $realBasePath);
    }
}
