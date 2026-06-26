<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Forms\Loader;

use Phalcon\Forms\Exception;
use Phalcon\Forms\Loader\ArrayLoader;
use Phalcon\Tests\AbstractUnitTestCase;

final class ArrayLoaderTest extends AbstractUnitTestCase
{
    public function testLoadPassesThroughExtraKeys(): void
    {
        $definition = [
            'type'       => 'text',
            'name'       => 'color',
            'label'      => 'Favorite Color',
            'default'    => 'red',
            'attributes' => ['class' => 'input'],
            'filters'    => ['trim'],
        ];

        $schema = new ArrayLoader([$definition]);
        $result = $schema->load();

        $this->assertSame($definition, $result[0]);
    }

    // -----------------------------------------------------------------------
    // Error index is reported correctly
    // -----------------------------------------------------------------------

    public function testLoadReportsCorrectIndexInError(): void
    {
        $schema = new ArrayLoader([
            ['type' => 'text',  'name' => 'ok'],
            ['type' => 'email', 'name' => 'ok2'],
            ['name' => 'missing-type'],
        ]);

        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches('/index 2/i');

        $schema->load();
    }

    public function testLoadReturnsEmptyArrayForEmptyInput(): void
    {
        $schema = new ArrayLoader([]);

        $result = $schema->load();

        $this->assertSame([], $result);
    }

    public function testLoadReturnsMultipleDefinitions(): void
    {
        $schema = new ArrayLoader([
            ['type' => 'text',     'name' => 'first_name'],
            ['type' => 'email',    'name' => 'email'],
            ['type' => 'password', 'name' => 'password'],
        ]);

        $result = $schema->load();

        $this->assertCount(3, $result);
    }
    // -----------------------------------------------------------------------
    // Happy path
    // -----------------------------------------------------------------------

    public function testLoadReturnsSingleDefinition(): void
    {
        $schema = new ArrayLoader([
            ['type' => 'text', 'name' => 'username'],
        ]);

        $result = $schema->load();

        $this->assertCount(1, $result);
        $this->assertSame('text', $result[0]['type']);
        $this->assertSame('username', $result[0]['name']);
    }

    // -----------------------------------------------------------------------
    // Validation: non-array entry
    // -----------------------------------------------------------------------

    public function testLoadThrowsWhenEntryIsNotArray(): void
    {
        $schema = new ArrayLoader([
            'not-an-array',
        ]);

        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches('/index 0.*must be an array/i');

        $schema->load();
    }

    public function testLoadThrowsWhenNameIsEmpty(): void
    {
        $schema = new ArrayLoader([
            ['type' => 'text', 'name' => ''],
        ]);

        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches('/missing required key "name"/i');

        $schema->load();
    }

    // -----------------------------------------------------------------------
    // Validation: missing name
    // -----------------------------------------------------------------------

    public function testLoadThrowsWhenNameIsMissing(): void
    {
        $schema = new ArrayLoader([
            ['type' => 'text'],
        ]);

        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches('/missing required key "name"/i');

        $schema->load();
    }

    public function testLoadThrowsWhenTypeIsEmpty(): void
    {
        $schema = new ArrayLoader([
            ['type' => '', 'name' => 'username'],
        ]);

        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches('/missing required key "type"/i');

        $schema->load();
    }

    // -----------------------------------------------------------------------
    // Validation: missing type
    // -----------------------------------------------------------------------

    public function testLoadThrowsWhenTypeIsMissing(): void
    {
        $schema = new ArrayLoader([
            ['name' => 'username'],
        ]);

        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches('/missing required key "type"/i');

        $schema->load();
    }
}
