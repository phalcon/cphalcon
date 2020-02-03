<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Html\Helper\Label;

use Codeception\Example;
use Phalcon\Escaper;
use Phalcon\Factory\Exception as ExceptionAlias;
use Phalcon\Html\Exception;
use Phalcon\Html\Helper\Label;
use Phalcon\Html\TagFactory;
use UnitTester;

class UnderscoreInvokeCest
{
    /**
     * Tests Phalcon\Html\Helper\Label :: __invoke()
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @throws Exception
     * @throws ExceptionAlias
     * @dataProvider getExamples
     * @since        2020-01-05
     *
     */
    public function htmlHelperLabelUnderscoreInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Html\Helper\Label - __invoke()');
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

    /**
     * @return array
     */
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
