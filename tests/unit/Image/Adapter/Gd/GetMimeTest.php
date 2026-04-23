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
                supportDir('assets/images/example-gif.gif'),
                'image/gif',
            ],
            [
                supportDir('assets/images/example-jpg.jpg'),
                'image/jpeg',
            ],
            [
                supportDir('assets/images/example-png.png'),
                'image/png',
            ],
            [
                supportDir('assets/images/example-wbmp.wbmp'),
                'image/vnd.wap.wbmp',
            ],
            [
                supportDir('assets/images/example-webp.webp'),
                'image/webp',
            ],
            [
                supportDir('assets/images/example-xbm.xbm'),
                'image/xbm',
            ],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
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
