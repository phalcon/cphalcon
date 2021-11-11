<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper\Element;

use Codeception\Example;
use Phalcon\Html\Escaper;
use Phalcon\Html\Exception;
use Phalcon\Html\Helper\Element;
use Phalcon\Html\TagFactory;
use UnitTester;

/**
 * Class UnderscoreInvokeCest
 *
 * @package Phalcon\Tests\Unit\Html\Helper\Element
 */
class UnderscoreInvokeCest
{
    /**
     * Tests Phalcon\Html\Helper\Element :: __invoke()
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
    public function htmlHelperElementUnderscoreInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Html\Helper\Element - __invoke()');
        $escaper = new Escaper();
        $helper  = new Element($escaper);

        $expected = $example[0];
        $actual   = $helper($example[1], $example[2], $example[3], $example[4]);
        $I->assertEquals($expected, $actual);

        $factory  = new TagFactory($escaper);
        $locator  = $factory->newInstance('element');
        $expected = $example[0];
        $actual   = $locator($example[1], $example[2], $example[3], $example[4]);
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return array
     */
    private function getExamples(): array
    {
        return [
            [
                '<canvas>test tag</canvas>',
                'canvas',
                'test tag',
                [],
                false,
            ],
            [
                '<canvas>Jack &amp; Jill</canvas>',
                'canvas',
                'Jack & Jill',
                [],
                false,
            ],
            [
                '<canvas>&lt;script&gt;alert(&quot;hello&quot;);&lt;/script&gt;test tag</canvas>',
                'canvas',
                '<script>alert("hello");</script>test tag',
                [],
                false,
            ],
            [
                '<section id="my-id" name="my-name">test tag</section>',
                'section',
                'test tag',
                [
                    'id'   => 'my-id',
                    'name' => 'my-name',
                ],
                false,
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
                false,
            ],
            [
                '<canvas>test tag</canvas>',
                'canvas',
                'test tag',
                [],
                true,
            ],
            [
                '<canvas>Jack & Jill</canvas>',
                'canvas',
                'Jack & Jill',
                [],
                true,
            ],
            [
                '<canvas><script>alert("hello");</script>test tag</canvas>',
                'canvas',
                '<script>alert("hello");</script>test tag',
                [],
                true,
            ],
            [
                '<section id="my-id" name="my-name">test tag</section>',
                'section',
                'test tag',
                [
                    'id'   => 'my-id',
                    'name' => 'my-name',
                ],
                true,
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
                true,
            ],
        ];
    }
}
