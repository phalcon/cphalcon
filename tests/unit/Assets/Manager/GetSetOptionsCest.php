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

namespace Phalcon\Test\Unit\Assets\Manager;

use Codeception\Example;
use Phalcon\Assets\Manager;
use UnitTester;

class GetSetOptionsCest
{
    /**
     * Tests Phalcon\Assets\Manager :: getOptions()/setOptions()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-19
     *
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     */
    public function assetsManagerGetSetOptions(
        UnitTester $I,
        Example $example
    ) {
        $I->wantToTest(
            'Assets\Manager - getOptions()/setOptions() - ' . $example['label']
        );

        $options = $example['options'];
        $assets = new Manager($options);

        if (!empty($example['set'])) {
            $assets->setOptions($example['set']);
        }

        $expected = $example['expected'];
        $actual   = $assets->getOptions();
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return array
     */
    private function getExamples(): array
    {
        return [
            [
                'label'    => 'empty',
                'options'  => [],
                'expected' => [],
                'set'      => [],
            ],
            [
                'label'    => 'constructor',
                'options'  => [
                    'one'   => 'two',
                    'three' => 'four',
                ],
                'expected' => [
                    'one'   => 'two',
                    'three' => 'four',
                ],
                'set'      => [],
            ],
            [
                'label'    => 'setOptions',
                'options'  => [],
                'expected' => [
                    'one'   => 'two',
                    'three' => 'four',
                ],
                'set'      => [
                    'one'   => 'two',
                    'three' => 'four',
                ],
            ],
        ];
    }
}
