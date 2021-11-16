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

namespace Phalcon\Tests\Unit\Assets\Manager;

use Codeception\Example;
use Phalcon\Assets\Manager;
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use UnitTester;

class GetSetOptionsCest
{
    /**
     * Tests Phalcon\Assets\Manager :: getOptions()/setOptions()
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-03-19
     *
     *
     * @dataProvider getExamples
     */
    public function assetsManagerGetSetOptions(
        UnitTester $I,
        Example $example
    ) {
        $I->wantToTest(
            'Assets\Manager - getOptions()/setOptions() - ' . $example['label']
        );

        $options = $example['options'];
        $manager = new Manager(new TagFactory(new Escaper()), $options);

        if (!empty($example['set'])) {
            $manager->setOptions($example['set']);
        }

        $expected = $example['expected'];
        $actual   = $manager->getOptions();
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
