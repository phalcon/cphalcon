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

namespace Phalcon\Test\Unit\Html\Helper\Button;

use Codeception\Example;
use Phalcon\Escaper;
use Phalcon\Html\Exception;
use Phalcon\Html\Helper\Button;
use Phalcon\Html\TagFactory;
use UnitTester;

class ButtonCest
{
    /**
     * Tests Phalcon\Html\Helper\Button :: __construct()
     *
     * @dataProvider getExamples
     *
     * @throws Exception
     */
    public function htmlHelperTextareaConstruct(UnitTester $I, Example $example)
    {
        $I->wantToTest('Html\Helper\Button - __construct()');
        $escaper = new Escaper();
        $helper  = new Button($escaper);

        $expected = $example[0];
        $actual   = $helper($example[1], $example[2]);
        $I->assertEquals($expected, $actual);

        $factory  = new TagFactory($escaper);
        $locator  = $factory->newInstance('button');
        $expected = $example[0];
        $actual   = $locator($example[1], $example[2]);
        $I->assertEquals($expected, $actual);
    }

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
