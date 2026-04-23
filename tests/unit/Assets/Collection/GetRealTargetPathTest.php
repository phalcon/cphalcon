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
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Assets\Fake\FakeCollectionFileExists;

use function supportDir;

final class GetRealTargetPathTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testAssetsCollectionGetRealTargetPath(): void
    {
        $collection        = new Collection();
        $targetPath        = '/assets';
        $basePath          = supportDir('assets');
        $constructRealPath = realpath($basePath . $targetPath);

        $collection->setTargetPath($targetPath);
        $realBasePath = $collection->getRealTargetPath($basePath);

        $this->assertSame($constructRealPath, $realBasePath);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testAssetsCollectionGetRealTargetPathFileDoesNotExist(): void
    {
        if (PHP_OS_FAMILY === 'Windows') {
            $this->markTestSkipped('Need to fix Windows new lines...');
        }

        $collection        = new FakeCollectionFileExists();
        $targetPath        = '/assets';
        $basePath          = supportDir('assets');
        $constructRealPath = realpath($basePath . $targetPath);

        $collection->setTargetPath($targetPath);
        $realBasePath = $collection->getRealTargetPath($basePath);

        $this->assertSame($constructRealPath, $realBasePath);
    }
}
