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

final class GetMimeTest extends AbstractUnitTestCase
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
                'image/gif',
            ],
            [
                Talon::settings()->supportPath('assets/images/example-jpg.jpg'),
                'image/jpeg',
            ],
            [
                Talon::settings()->supportPath('assets/images/example-png.png'),
                'image/png',
            ],
            [
                Talon::settings()->supportPath('assets/images/example-wbmp.wbmp'),
                'image/vnd.wap.wbmp',
            ],
            [
                Talon::settings()->supportPath('assets/images/example-webp.webp'),
                'image/webp',
            ],
            [
                Talon::settings()->supportPath('assets/images/example-xbm.xbm'),
                'image/xbm',
            ],
        ];
    }

    /**
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    #[DataProvider('getExamples')]
    public function testImageAdapterGdGetMime(
        string $source,
        string $expected
    ): void {
        $this->checkJpegSupport();

        $gd = new Gd($source);

        $actual = $gd->getMime();
        $this->assertSame($expected, $actual);
    }
}
