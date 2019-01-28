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

namespace Phalcon\Test\Unit\Html\Helper\Button;

use Codeception\Example;
use Phalcon\Html\Helper\Button;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

/**
 * Class ButtonCest
 */
class ButtonCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Html\Helper\Button :: __construct()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2019-01-19
     */
    public function htmlHelperTextareaConstruct(UnitTester $I, Example $example)
    {
        $I->wantToTest('Html\Helper\Button - __construct()');
        $escaper = $this->newEscaper();
        $helper  = new Button($escaper);

        $expected = $example[0];
        $actual   = $helper($example[1], $example[2]);
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return array
     */
    private function getExamples(): array
    {
        return [
            [
                '<button>Phalcon Framework</button>',
                'Phalcon Framework',
                [],
            ],
            [
                '<button>Jack &amp; Jill</button>',
                'Jack & Jill',
                [],
            ],
            [
                '<button>&lt;script&gt;alert(&quot;hello&quot;);&lt;/script&gt;test tag</button>',
                '<script>alert("hello");</script>test tag',
                [],
            ],
            [
                '<button id="my-id" name="my-name">test tag</button>',
                'test tag',
                [
                    'id'   => 'my-id',
                    'name' => 'my-name',
                ],
            ],
            [
                '<button id="my-id" name="my-name" class="my-class">test tag</button>',
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
