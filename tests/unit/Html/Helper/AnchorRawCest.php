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
use Phalcon\Html\Helper\AnchorRaw;
use Phalcon\Html\TagFactory;
use UnitTester;

class AnchorRawCest
{
    /**
     * Tests Phalcon\Html\Helper\AnchorRaw :: __construct()
     *
     * @dataProvider getExamples
     *
     * @throws Exception
     */
    public function htmlHelperAnchorRawConstruct(UnitTester $I, Example $example)
    {
        $I->wantToTest('Html\Helper\Anchor - __construct()');
        $escaper = new Escaper();
        $anchor  = new AnchorRaw($escaper);

        $expected = $example[0];
        $actual   = $anchor('/myurl', 'click<>me', $example[1]);
        $I->assertEquals($expected, $actual);

        $factory  = new TagFactory($escaper);
        $locator  = $factory->newInstance('aRaw');
        $expected = $example[0];
        $actual   = $locator('/myurl', 'click<>me', $example[1]);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\Helper\Anchor :: __construct() - exception
     *
     * @throws Exception
     */
    public function htmlHelperAnchorConstructException(UnitTester $I)
    {
        $I->wantToTest('Html\Helper\Anchor - __construct()');
        $I->expectThrowable(
            new Exception(
                'Value at index: "other" type: "array" cannot be rendered'
            ),
            function () {
                $escaper    = new Escaper();
                $anchor     = new AnchorRaw($escaper);
                $attributes = [
                    'id'    => 'my-id',
                    'name'  => 'my-name',
                    'other' => [
                        'a',
                        'b',
                        'c',
                    ],
                ];

                $output = $anchor('/myurl', 'click me', $attributes);
            }
        );
    }

    private function getExamples(): array
    {
        return [
            [
                '<a href="/myurl">click<>me</a>',
                [],
            ],
            [
                '<a href="/myurl">click<>me</a>',
                [
                    'href' => '/somethingelse',
                ],
            ],
            [
                '<a href="/myurl" id="my-id" name="my-name">click<>me</a>',
                [
                    'id'   => 'my-id',
                    'name' => 'my-name',
                ],
            ],
            [
                '<a href="/myurl" id="my-id" name="my-name" class="my-class">click<>me</a>',
                [
                    'class' => 'my-class',
                    'name'  => 'my-name',
                    'id'    => 'my-id',
                ],
            ],
        ];
    }
}
