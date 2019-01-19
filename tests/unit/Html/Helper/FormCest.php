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
use Phalcon\Html\Helper\Form;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

/**
 * Class FormCest
 */
class FormCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Html\Helper\Form :: __construct()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2019-01-19
     */
    public function htmlHelperFormConstruct(UnitTester $I, Example $example)
    {
        $I->wantToTest('Html\Helper\Form - __construct()');
        $escaper = $this->newEscaper();
        $helper  = new Form($escaper);

        $expected = $example[0];
        $actual   = $helper($example[1]);
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return array
     */
    private function getExamples(): array
    {
        return [
            [
                '<form method="post" enctype="multipart/form-data">',
                [],
            ],
            [
                '<form method="post" enctype="multipart/form-data" id="my-id" name="my-name">',
                [
                    'id'   => 'my-id',
                    'name' => 'my-name',
                ],
            ],
            [
                '<form method="post" enctype="multipart/form-data" id="my-id" name="my-name" class="my-class">',
                [
                    'class' => 'my-class',
                    'name'  => 'my-name',
                    'id'    => 'my-id',
                ],
            ],
        ];
    }
}
