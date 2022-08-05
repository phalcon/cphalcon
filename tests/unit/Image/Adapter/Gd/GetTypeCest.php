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

use const IMAGETYPE_GIF;
use const IMAGETYPE_JPEG;
use const IMAGETYPE_PNG;
use const IMAGETYPE_WBMP;
use const IMAGETYPE_WEBP;
use const IMAGETYPE_XBM;

class GetTypeCest
{
    use GdTrait;

    /**
     * Tests Phalcon\Image\Adapter\Gd :: getType()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @return void
     * @since        2022-07-19
     *
     * @author       Phalcon Team <team@phalcon.io>
     */
    public function imageAdapterGdGetType(UnitTester $I, Example $example)
    {
        $I->wantToTest('Image\Adapter\Gd - getType() - ' . $example['label']);

        $this->checkJpegSupport($I);
        $source   = $example['source'];
        $expected = $example['expected'];

        $gd = new Gd($source);

        $actual = $gd->getType();
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
                'expected' => IMAGETYPE_GIF,
            ],
            [
                'label'    => 'jpg',
                'source'   => dataDir('assets/images/example-jpg.jpg'),
                'expected' => IMAGETYPE_JPEG,
            ],
            [
                'label'    => 'png',
                'source'   => dataDir('assets/images/example-png.png'),
                'expected' => IMAGETYPE_PNG,
            ],
            [
                'label'    => 'wbmp',
                'source'   => dataDir('assets/images/example-wbmp.wbmp'),
                'expected' => IMAGETYPE_WBMP,
            ],
            [
                'label'    => 'webp',
                'source'   => dataDir('assets/images/example-webp.webp'),
                'expected' => IMAGETYPE_WEBP,
            ],
            [
                'label'    => 'xbm',
                'source'   => dataDir('assets/images/example-xbm.xbm'),
                'expected' => IMAGETYPE_XBM,
            ],
        ];
    }
}
