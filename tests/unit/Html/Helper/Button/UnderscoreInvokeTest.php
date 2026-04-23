<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper\Button;

use Phalcon\Html\Escaper;
use Phalcon\Html\Exception;
use Phalcon\Html\Helper\Button;
use Phalcon\Html\TagFactory;
use Phalcon\Tests\AbstractUnitTestCase;

final class UnderscoreInvokeTest extends AbstractUnitTestCase
{
    /**
     * @return array
     */
    public static function getExamples(): array
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

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function testHtmlHelperButtonUnderscoreInvoke(
        string $expected,
        string $text,
        array $attributes,
        bool $raw
    ): void {
        $escaper = new Escaper();
        $helper  = new Button($escaper);

        $actual = $helper($text, $attributes, $raw);
        $this->assertSame($expected, $actual);

        $factory = new TagFactory($escaper);
        $locator = $factory->newInstance('button');
        $actual  = $locator($text, $attributes, $raw);
        $this->assertSame($expected, $actual);

        $factory = new TagFactory($escaper);
        $actual  = $factory->button($text, $attributes, $raw);
        $this->assertSame($expected, $actual);
    }
}
