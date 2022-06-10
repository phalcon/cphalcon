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

class GetMimeCest
{
    use GdTrait;

    /**
     * Tests Phalcon\Image\Adapter\Gd :: getMime()
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
    public function imageAdapterGdGetMime(UnitTester $I, Example $example)
    {
        $I->wantToTest('Image\Adapter\Gd - getMime() - ' . $example['label']);

        $this->checkJpegSupport($I);

        $source   = $example['source'];
        $expected = $example['expected'];

        $gd = new Gd($source);

        $actual = $gd->getMime();
        $I->assertSame($expected, $actual);
    }

    /**
     * @return array[]
     */
    private function getExamples(): array
    {
        return [
            [
                'label'    => 'JPEG',
                'source'   => dataDir('assets/images/phalconphp.jpg'),
                'expected' => 'image/jpeg',
            ],
            [
                'label'    => 'PNG',
                'source'   => dataDir('assets/images/logo.png'),
                'expected' => 'image/png',
            ],
            [
                'label'    => 'WEBP',
                'source'   => dataDir('assets/images/house.webp'),
                'expected' => 'image/webp',
            ],
        ];
    }
}
