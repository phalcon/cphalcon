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

use Codeception\Stub;
use Phalcon\Assets\Collection;
use UnitTester;

use function dataDir;

/**
 * Class GetRealTargetPathCest
 *
 * @package Phalcon\Tests\Unit\Assets\Collection
 */
class GetRealTargetPathCest
{
    /**
     * Tests Phalcon\Assets\Collection :: getRealTargetPath()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsCollectionGetRealTargetPath(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - getRealTargetPath()');

        $collection        = new Collection();
        $targetPath        = '/assets';
        $basePath          = dataDir('assets');
        $constructRealPath = realpath($basePath . $targetPath);

        $collection->setTargetPath($targetPath);
        $realBasePath = $collection->getRealTargetPath($basePath);

        $I->assertEquals($constructRealPath, $realBasePath);
    }

    /**
     * Tests Phalcon\Assets\Collection :: getRealTargetPath() - file does not exist
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsCollectionGetRealTargetPathFileDoesNotExist(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - getRealTargetPath() - file does not exist');

        if (PHP_OS_FAMILY === 'Windows') {
            $I->markTestSkipped('Need to fix Windows new lines...');
        }

        $collection        = Stub::make(
            Collection::class,
            [
                'phpFileExists' => false,
            ]
        );
        $targetPath        = '/assets';
        $basePath          = dataDir('assets');
        $constructRealPath = realpath($basePath . $targetPath);

        $collection->setTargetPath($targetPath);
        $realBasePath = $collection->getRealTargetPath($basePath);

        $I->assertEquals($constructRealPath, $realBasePath);
    }
}
