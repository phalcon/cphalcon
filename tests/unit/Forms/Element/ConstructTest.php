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

namespace Phalcon\Tests\Unit\Forms\Element;

use InvalidArgumentException;
use Phalcon\Forms\Element\Text;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Forms\Fake\FormsTrait;

use function uniqid;

final class ConstructTest extends AbstractUnitTestCase
{
    use FormsTrait;

    /**
     * @dataProvider getExamplesWithoutSelect
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2021-12-05
     */
    public function testFormsElementTextareaConstruct(
        string $class
    ): void {
        $name   = uniqid();
        $object = new $class($name);

        $expected = $name;
        $actual   = $object->getName();
        $this->assertSame($expected, $actual);

        $name       = uniqid();
        $attributes = ["one" => "two"];
        $object     = new $class($name, $attributes);

        $expected = $name;
        $actual   = $object->getName();
        $this->assertSame($expected, $actual);

        $expected = $attributes;
        $actual   = $object->getAttributes();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testFormsElementConstructEmptyNameThrows(): void
    {
        $this->expectException(InvalidArgumentException::class);
        $this->expectExceptionMessage('Form element name is required');

        new Text('');
    }
}
