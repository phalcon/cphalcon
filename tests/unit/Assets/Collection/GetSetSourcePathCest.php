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

class GetSetSourcePathCest
{
    /**
     * Tests Phalcon\Assets\Collection :: getSourcePath() / setSourcePath()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-02-15
     */
    public function assetsCollectionGetSetSourcePath(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - getSourcePath() / setSourcePath()');

        $collection = new Collection();

        $sourcePath = dataDir('assets');

        $collection->setSourcePath($sourcePath);

        $I->assertEquals($sourcePath, $collection->getSourcePath());
    }
}
