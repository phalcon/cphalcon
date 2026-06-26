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

namespace Phalcon\Tests\Unit\Assets\Asset\Js;

use Phalcon\Assets\Asset\Js;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Assets\Fake\AssetsTrait;
use PHPUnit\Framework\Attributes\DataProvider;

final class GetSetFilterTest extends AbstractUnitTestCase
{
    use AssetsTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    #[DataProvider('providerJs')]
    public function testAssetsAssetJsGetSetFilter(
        string $path,
        bool $local
    ): void {
        $asset  = new Js($path, $local);
        $actual = $asset->getFilter();
        $this->assertTrue($actual);

        $asset->setFilter(false);

        $actual = $asset->getFilter();
        $this->assertFalse($actual);
    }
}
