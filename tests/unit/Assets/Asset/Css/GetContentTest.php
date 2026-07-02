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

namespace Phalcon\Tests\Unit\Assets\Asset\Css;

use Phalcon\Assets\Asset\Css;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use PHPUnit\Framework\Attributes\Test;

use function file_get_contents;

final class GetContentTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testAssetsAssetCssGetContent(): void
    {
        $asset = new Css('assets/assets/1198.css');

        $expected = file_get_contents(Talon::settings()->supportPath('assets/assets/1198.css'));
        $actual   = $asset->getContent(Talon::settings()->supportPath() . '/');
        $this->assertSame($expected, $actual);
    }
}
