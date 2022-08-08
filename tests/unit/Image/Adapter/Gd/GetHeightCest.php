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

use Codeception\Example;
use Phalcon\Image\Adapter\Gd;
use Phalcon\Tests\Fixtures\Traits\GdTrait;
use UnitTester;

use function dataDir;

class GetHeightCest
{
    use GdTrait;

    /**
     * Tests Phalcon\Image\Adapter\Gd :: getHeight()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @return void
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    public function imageAdapterGdGetHeight(UnitTester $I, Example $example)
    {
        $I->wantToTest('Image\Adapter\Gd - getHeight() - ' . $example['label']);

        $this->checkJpegSupport($I);

        $source   = $example['source'];
        $expected = $example['expected'];

        $gd = new Gd($source);

        $actual = $gd->getHeight();
        $I->assertSame($expected, $actual);
    }

    /**
     * @return array[]
     */
    private function getExamples(): array
    {
        return [
            [
                'label'    => 'gif',
                'source'   => dataDir('assets/images/example-gif.gif'),
                'expected' => 640,
            ],
            [
                'label'    => 'jpg',
                'source'   => dataDir('assets/images/example-jpg.jpg'),
                'expected' => 694,
            ],
            [
                'label'    => 'png',
                'source'   => dataDir('assets/images/example-png.png'),
                'expected' => 82,
            ],
            [
                'label'    => 'wbmp',
                'source'   => dataDir('assets/images/example-wbmp.wbmp'),
                'expected' => 426,
            ],
            [
                'label'    => 'webp',
                'source'   => dataDir('assets/images/example-webp.webp'),
                'expected' => 1024,
            ],
            [
                'label'    => 'xbm',
                'source'   => dataDir('assets/images/example-xbm.xbm'),
                'expected' => 187,
            ],
        ];
    }
}
