<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Html\Helper;

use Codeception\Example;
use Phalcon\Html\Exception;
use Phalcon\Html\Helper\Label;
use Phalcon\Html\TagFactory;
use UnitTester;

class LabelCest
{
    /**
     * Tests Phalcon\Html\Helper\Label :: __construct()
     *
     * @dataProvider getExamples
     *
     * @throws Exception
     */
    public function htmlHelperLabelConstruct(UnitTester $I, Example $example)
    {
        $I->wantToTest('Html\Helper\Label - __construct()');
        $escaper = new Escaper();
        $helper  = new Label($escaper);

        $expected = $example[0];
        $actual   = $helper($example[1]);
        $I->assertEquals($expected, $actual);

        $factory  = new TagFactory($escaper);
        $locator  = $factory->newInstance('label');
        $expected = $example[0];
        $actual   = $locator($example[1]);
        $I->assertEquals($expected, $actual);
    }

    private function getExamples(): array
    {
        return [
            [
                '<label>',
                [],
            ],
            [
                '<label for="my-name" id="my-id">',
                [
                    'id'  => 'my-id',
                    'for' => 'my-name',
                ],
            ],
            [
                '<label for="my-name" id="my-id" class="my-class">',
                [
                    'class' => 'my-class',
                    'for'   => 'my-name',
                    'id'    => 'my-id',
                ],
            ],
        ];
    }
}
