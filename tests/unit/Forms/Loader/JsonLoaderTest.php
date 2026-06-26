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
use Phalcon\Forms\Loader\JsonLoader;
use Phalcon\Tests\AbstractUnitTestCase;

final class JsonLoaderTest extends AbstractUnitTestCase
{
    public function testLoadEmptyArray(): void
    {
        $schema = new JsonLoader('[]');
        $result = $schema->load();

        $this->assertSame([], $result);
    }

    // -----------------------------------------------------------------------
    // Valid JSON file path
    // -----------------------------------------------------------------------

    public function testLoadFromValidJsonFile(): void
    {
        $definitions = [
            ['type' => 'text',     'name' => 'title'],
            ['type' => 'textarea', 'name' => 'body'],
        ];

        $path = $this->writeJsonFile($definitions);

        $schema = new JsonLoader($path);
        $result = $schema->load();

        $this->assertCount(2, $result);
        $this->assertSame('title', $result[0]['name']);
        $this->assertSame('body', $result[1]['name']);

        unlink($path);
    }
    // -----------------------------------------------------------------------
    // Valid JSON string
    // -----------------------------------------------------------------------

    public function testLoadFromValidJsonString(): void
    {
        $json = json_encode([
            ['type' => 'text',  'name' => 'first_name'],
            ['type' => 'email', 'name' => 'email'],
        ]);

        $schema = new JsonLoader($json);
        $result = $schema->load();

        $this->assertCount(2, $result);
        $this->assertSame('first_name', $result[0]['name']);
        $this->assertSame('email', $result[1]['name']);
    }

    public function testLoadPassesThroughExtraKeys(): void
    {
        $json = json_encode([
            [
                'type'       => 'text',
                'name'       => 'city',
                'label'      => 'City',
                'default'    => 'London',
                'attributes' => ['class' => 'field'],
            ],
        ]);

        $schema = new JsonLoader($json);
        $result = $schema->load();

        $this->assertSame('City', $result[0]['label']);
        $this->assertSame('London', $result[0]['default']);
    }

    // -----------------------------------------------------------------------
    // Error: invalid JSON
    // -----------------------------------------------------------------------

    public function testLoadThrowsOnInvalidJson(): void
    {
        $schema = new JsonLoader('{bad json');

        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches('/json form schema is invalid/i');

        $schema->load();
    }

    public function testLoadThrowsWhenEntryMissingName(): void
    {
        $schema = new JsonLoader(json_encode([
            ['type' => 'text'],
        ]));

        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches('/missing required key "name"/i');

        $schema->load();
    }

    // -----------------------------------------------------------------------
    // Validation delegated to ArrayLoader
    // -----------------------------------------------------------------------

    public function testLoadThrowsWhenEntryMissingType(): void
    {
        $schema = new JsonLoader(json_encode([
            ['name' => 'username'],
        ]));

        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches('/missing required key "type"/i');

        $schema->load();
    }

    // -----------------------------------------------------------------------
    // Error: JSON is valid but not an array
    // -----------------------------------------------------------------------

    public function testLoadThrowsWhenJsonIsObject(): void
    {
        $schema = new JsonLoader('{"type":"text","name":"field"}');

        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches('/must decode to an array/i');

        $schema->load();
    }

    public function testLoadThrowsWhenJsonIsString(): void
    {
        $schema = new JsonLoader('"just a string"');

        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches('/must decode to an array/i');

        $schema->load();
    }

    // -----------------------------------------------------------------------
    // Helpers
    // -----------------------------------------------------------------------

    /**
     * Write an array to a temporary JSON file and return its path.
     *
     * @param array<int, array<string, mixed>> $data
     */
    private function writeJsonFile(array $data): string
    {
        $dir  = sys_get_temp_dir();
        $path = $dir . '/phalcon_forms_test_' . uniqid() . '.json';
        file_put_contents($path, json_encode($data));

        return $path;
    }
}
