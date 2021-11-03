<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper\Button;

use Codeception\Example;
use Phalcon\Html\Escaper;
use Phalcon\Factory\Exception as ExceptionAlias;
use Phalcon\Html\Exception;
use Phalcon\Html\Helper\Button;
use Phalcon\Html\TagFactory;
use UnitTester;

class UnderscoreInvokeCest
{
    /**
     * Tests Phalcon\Html\Helper\Button :: __invoke()
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @throws Exception
     * @throws ExceptionAlias
     * @dataProvider getExamples
     * @since        2020-01-05
     *
     */
    public function htmlHelperButtonUnderscoreInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Html\Helper\Button - __invoke()');
        $escaper = new Escaper();
        $helper  = new Button($escaper);

        $expected = $example[0];
        $actual   = $helper($example[1], $example[2], $example[3]);
        $I->assertEquals($expected, $actual);

        $factory  = new TagFactory($escaper);
        $locator  = $factory->newInstance('button');
        $expected = $example[0];
        $actual   = $locator($example[1], $example[2], $example[3]);
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
                false,
            ],
            [
                '<button>Jack &amp; Jill</button>',
                'Jack & Jill',
                [],
                false,
            ],
            [
                '<button>&lt;script&gt;alert(&quot;hello&quot;);&lt;/script&gt;test tag</button>',
                '<script>alert("hello");</script>test tag',
                [],
                false,
            ],
            [
                '<button id="my-id" name="my-name">test tag</button>',
                'test tag',
                [
                    'id'   => 'my-id',
                    'name' => 'my-name',
                ],
                false,
            ],
            [
                '<button id="my-id" name="my-name" class="my-class">test tag</button>',
                'test tag',
                [
                    'class' => 'my-class',
                    'name'  => 'my-name',
                    'id'    => 'my-id',
                ],
                false,
            ],
            [
                '<button>Phalcon Framework</button>',
                'Phalcon Framework',
                [],
                true,
            ],
            [
                '<button>Jack & Jill</button>',
                'Jack & Jill',
                [],
                true,
            ],
            [
                '<button><script>alert("hello");</script>test tag</button>',
                '<script>alert("hello");</script>test tag',
                [],
                true,
            ],
            [
                '<button id="my-id" name="my-name">test tag</button>',
                'test tag',
                [
                    'id'   => 'my-id',
                    'name' => 'my-name',
                ],
                true,
            ],
            [
                '<button id="my-id" name="my-name" class="my-class">test tag</button>',
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
