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

namespace Phalcon\Test\Unit\Html\Helper;

use Codeception\Example;
use Phalcon\Escaper;
use Phalcon\Html\Exception;
use Phalcon\Html\Helper\Img;
use Phalcon\Html\TagFactory;
use UnitTester;

class ImgCest
{
    /**
     * Tests Phalcon\Html\Helper\Img :: __construct()
     *
     * @dataProvider getExamples
     *
     * @throws Exception
     */
    public function htmlHelperImgConstruct(UnitTester $I, Example $example)
    {
        $I->wantToTest('Html\Helper\Img - __construct()');
        $escaper = new Escaper();
        $helper  = new Img($escaper);

        $expected = $example[0];
        $actual   = $helper('/my-url', $example[1]);
        $I->assertEquals($expected, $actual);

        $factory  = new TagFactory($escaper);
        $locator  = $factory->newInstance('img');
        $expected = $example[0];
        $actual   = $locator('/my-url', $example[1]);
        $I->assertEquals($expected, $actual);
    }

    private function getExamples(): array
    {
        return [
            [
                '<img src="/my-url"/>',
                [],
            ],
            [
                '<img src="/my-url" id="my-id" name="my-name"/>',
                [
                    'id'   => 'my-id',
                    'name' => 'my-name',
                ],
            ],
            [
                '<img src="/my-url" id="my-id" name="my-name" class="my-class"/>',
                [
                    'src'   => '/other-url',
                    'class' => 'my-class',
                    'name'  => 'my-name',
                    'id'    => 'my-id',
                ],
            ],
        ];
    }
}
