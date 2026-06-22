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

namespace Phalcon\Tests\Unit\Tag;

use Phalcon\Di\Di;
use Phalcon\Html\Escaper;
use Phalcon\Tag;
use Phalcon\Tag\Select;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Html\Helper\Input\Select\Fake\FakeResultset;
use ReflectionProperty;

/**
 * Covers the resultset + Closure `using` branch of Tag\Select::selectField
 * (the `call_user_func_array` path), which renders each option through a
 * developer-supplied closure.
 */
final class SelectResultsetUsingClosureTest extends AbstractUnitTestCase
{
    public function setUp(): void
    {
        $container = new Di();
        $container->setShared('escaper', new Escaper());

        Tag::setDI($container);
        Tag::setAutoescape(false);
    }

    public function tearDown(): void
    {
        Tag::setAutoescape(true);

        (new ReflectionProperty(Tag::class, 'container'))->setValue(null, null);
    }

    public function testRendersOptionsFromResultsetUsingClosure(): void
    {
        $resultset = new FakeResultset(
            [
                ['id' => 1, 'name' => 'One'],
                ['id' => 2, 'name' => 'Two'],
            ]
        );

        $html = Select::selectField(
            [
                'choices',
                $resultset,
                'value' => '',
                'using' => static function (array $row): string {
                    return '<option value="' . $row['id'] . '">'
                        . $row['name'] . '</option>';
                },
            ]
        );

        $this->assertStringContainsString('<select', $html);
        $this->assertStringContainsString('id="choices"', $html);
        $this->assertStringContainsString('<option value="1">One</option>', $html);
        $this->assertStringContainsString('<option value="2">Two</option>', $html);
        $this->assertStringContainsString('</select>', $html);
    }
}
