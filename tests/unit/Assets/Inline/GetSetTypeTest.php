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

namespace Phalcon\Tests\Unit\Assets\Inline;

use Phalcon\Assets\Inline;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Assets\Fake\AssetsTrait;
use PHPUnit\Framework\Attributes\DataProvider;

final class GetSetTypeTest extends AbstractUnitTestCase
{
    use AssetsTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    #[DataProvider('providerInlineCssJsType')]
    public function testAssetsInlineGetSetType(
        string $type,
        string $content,
        string $newType
    ): void {
        $asset = new Inline($type, $content);
        $asset->setType($newType);

        $expected = $newType;
        $actual   = $asset->getType();
        $this->assertSame($expected, $actual);
    }
}
