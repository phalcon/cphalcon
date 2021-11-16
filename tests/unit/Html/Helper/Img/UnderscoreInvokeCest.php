<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper\Img;

use Codeception\Example;
use Phalcon\Html\Escaper;
use Phalcon\Html\Exception;
use Phalcon\Html\Helper\Img;
use Phalcon\Html\TagFactory;
use UnitTester;

/**
 * Class UnderscoreInvokeCest
 *
 * @package Phalcon\Tests\Unit\Html\Helper\Img
 */
class UnderscoreInvokeCest
{
    /**
     * Tests Phalcon\Html\Helper\Img :: __invoke()
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
    public function htmlHelperImgUnderscoreInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Html\Helper\Img - __invoke()');
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

    /**
     * @return array
     */
    private function getExamples(): array
    {
        return [
            [
                '<img src="/my-url" />',
                [],
            ],
            [
                '<img src="/my-url" id="my-id" name="my-name" />',
                [
                    'id'   => 'my-id',
                    'name' => 'my-name',
                ],
            ],
            [
                '<img src="/my-url" id="my-id" name="my-name" class="my-class" />',
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
