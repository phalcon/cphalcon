<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper\Label;

use Codeception\Example;
use Phalcon\Html\Escaper;
use Phalcon\Html\Exception;
use Phalcon\Html\Helper\Label;
use Phalcon\Html\TagFactory;
use UnitTester;

use function uniqid;

/**
 * Class UnderscoreInvokeCest
 *
 * @package Phalcon\Tests\Unit\Html\Helper\Label
 */
class UnderscoreInvokeCest
{
    /**
     * Tests Phalcon\Html\Helper\Label :: __invoke()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @throws Exception
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function htmlHelperLabelUnderscoreInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Html\Helper\Label - __invoke() - ' . $example[0]);
        $escaper = new Escaper();
        $helper  = new Label($escaper);

        $expected = $example[1];
        $actual   = $helper($example[2], $example[3], $example[4]);
        $I->assertEquals($expected, $actual);

        $factory  = new TagFactory($escaper);
        $locator  = $factory->newInstance('label');
        $expected = $example[1];
        $actual   = $locator($example[2], $example[3], $example[4]);
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return array
     */
    private function getExamples(): array
    {
        $text = uniqid();
        return [
            [
                'empty',
                '<label></label>',
                '',
                [],
                false,
            ],
            [
                'standard',
                '<label for="my-name" id="my-id">' . $text . '&amp;' . $text . '</label>',
                $text . '&' . $text,
                [
                    'id'  => 'my-id',
                    'for' => 'my-name',
                ],
                false,
            ],
            [
                'with id',
                '<label for="my-name" id="my-id" class="my-class">' . $text . '&amp;' . $text . '</label>',
                $text . '&' . $text,
                [
                    'class' => 'my-class',
                    'for'   => 'my-name',
                    'id'    => 'my-id',
                ],
                false,
            ],
            [
                'raw',
                '<label for="my-name" id="my-id">raw & text</label>',
                'raw & text',
                [
                    'id'  => 'my-id',
                    'for' => 'my-name',
                ],
                true,
            ],
        ];
    }
}
