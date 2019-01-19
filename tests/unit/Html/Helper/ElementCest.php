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

namespace Phalcon\Test\Unit\Html\Helper\Element;

use Codeception\Example;
use Phalcon\Html\Helper\Element;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

/**
 * Class ElementCest
 */
class ElementCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Html\Helper\Element :: __construct()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2019-01-19
     */
    public function htmlHelperElementConstruct(UnitTester $I, Example $example)
    {
        $I->wantToTest('Html\Helper\Element - __construct()');
        $escaper = $this->newEscaper();
        $helper  = new Element($escaper);

        $expected = $example[0];
        $actual   = $helper($example[1], $example[2], $example[3]);
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
            ],
            [
                '<canvas>Jack &amp; Jill</canvas>',
                'canvas',
                'Jack & Jill',
                [],
            ],
            [
                '<canvas>&lt;script&gt;alert(&quot;hello&quot;);&lt;/script&gt;test tag</canvas>',
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
