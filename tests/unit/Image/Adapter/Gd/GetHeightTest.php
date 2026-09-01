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

namespace Phalcon\Tests\Unit\Image\Adapter\Gd;

use Phalcon\Image\Adapter\Gd;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use Phalcon\Tests\Unit\Image\Fake\GdTrait;
use PHPUnit\Framework\Attributes\DataProvider;

final class GetHeightTest extends AbstractUnitTestCase
{
    use GdTrait;

    /**
     * @return array[]
     */
    public static function getExamples(): array
    {
        return [
            [
                Talon::settings()->supportPath('assets/images/example-gif.gif'),
                640,
            ],
            [
                Talon::settings()->supportPath('assets/images/example-jpg.jpg'),
                694,
            ],
            [
                Talon::settings()->supportPath('assets/images/example-png.png'),
                82,
            ],
            [
                Talon::settings()->supportPath('assets/images/example-wbmp.wbmp'),
                426,
            ],
            [
                Talon::settings()->supportPath('assets/images/example-webp.webp'),
                1024,
            ],
            [
                Talon::settings()->supportPath('assets/images/example-xbm.xbm'),
                187,
            ],
        ];
    }

    /**
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    #[DataProvider('getExamples')]
    public function testImageAdapterGdGetHeight(
        string $source,
        int $expected
    ): void {
        $this->checkJpegSupport();

        $gd = new Gd($source);

        $actual = $gd->getHeight();
        $this->assertSame($expected, $actual);
    }
}
