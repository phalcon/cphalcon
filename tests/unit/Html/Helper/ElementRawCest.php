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

namespace Phalcon\Test\Unit\Html\Helper\Element;

use Codeception\Example;
use Phalcon\Escaper;
use Phalcon\Html\Exception;
use Phalcon\Html\Helper\ElementRaw;
use Phalcon\Html\TagFactory;
use UnitTester;

class ElementRawCest
{
    /**
     * Tests Phalcon\Html\Helper\Element :: __construct()
     *
     * @dataProvider getExamples
     *
     * @throws Exception
     */
    public function htmlHelperElementRawConstruct(UnitTester $I, Example $example)
    {
        $I->wantToTest('Html\Helper\ElementRaw - __construct()');
        $escaper = new Escaper();
        $helper  = new ElementRaw($escaper);

        $expected = $example[0];
        $actual   = $helper($example[1], $example[2], $example[3]);
        $I->assertEquals($expected, $actual);

        $factory  = new TagFactory($escaper);
        $locator  = $factory->newInstance('elementRaw');
        $expected = $example[0];
        $actual   = $locator($example[1], $example[2], $example[3]);
        $I->assertEquals($expected, $actual);
    }

    private function getExamples(): array
    {
        return [
            [
                '<canvas>test tag</canvas>',
                'canvas',
                'test tag',
                [],
            ],
            [
                '<canvas>Jack & Jill</canvas>',
                'canvas',
                'Jack & Jill',
                [],
            ],
            [
                '<canvas><script>alert("hello");</script>test tag</canvas>',
                'canvas',
                '<script>alert("hello");</script>test tag',
                [],
            ],
            [
                '<section id="my-id" name="my-name">test tag</section>',
                'section',
                'test tag',
                [
                    'id'   => 'my-id',
                    'name' => 'my-name',
                ],
            ],
            [
                '<address id="my-id" name="my-name" class="my-class">test tag</address>',
                'address',
                'test tag',
                [
                    'class' => 'my-class',
                    'name'  => 'my-name',
                    'id'    => 'my-id',
                ],
            ],
        ];
    }
}
