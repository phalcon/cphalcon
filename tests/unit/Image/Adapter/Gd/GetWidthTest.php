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
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Image\Fake\GdTrait;

use function supportDir;

final class GetWidthTest extends AbstractUnitTestCase
{
    use GdTrait;

    /**
     * @return array[]
     */
    public static function getExamples(): array
    {
        return [
            [
                supportDir('assets/images/example-gif.gif'),
                960,
            ],
            [
                supportDir('assets/images/example-jpg.jpg'),
                1820,
            ],
            [
                supportDir('assets/images/example-png.png'),
                82,
            ],
            [
                supportDir('assets/images/example-wbmp.wbmp'),
                640,
            ],
            [
                supportDir('assets/images/example-webp.webp'),
                1536,
            ],
            [
                supportDir('assets/images/example-xbm.xbm'),
                206,
            ],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    public function testImageAdapterGdGetWidth(
        string $source,
        int $expected
    ): void {
        $this->checkJpegSupport();

        $gd = new Gd($source);

        $actual = $gd->getWidth();
        $this->assertSame($expected, $actual);
    }
}
