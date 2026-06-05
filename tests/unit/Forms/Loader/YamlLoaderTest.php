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
use Phalcon\Forms\Loader\YamlLoader;
use Phalcon\Tests\AbstractUnitTestCase;

/**
 * Tests for YamlLoader.
 *
 * All tests are guarded with a check for the ext-yaml extension.
 */
final class YamlLoaderTest extends AbstractUnitTestCase
{
    protected function setUp(): void
    {
        parent::setUp();

        if (!extension_loaded('yaml')) {
            $this->markTestSkipped('The "yaml" PHP extension is not loaded.');
        }
    }

    // -----------------------------------------------------------------------
    // Missing extension path (tested without guard - we test the exception)
    // -----------------------------------------------------------------------

    public function testLoadThrowsWhenExtensionNotLoaded(): void
    {
        if (extension_loaded('yaml')) {
            $this->markTestSkipped('yaml extension is loaded; cannot test missing-extension error.');
        }

        $schema = new YamlLoader('- type: text' . PHP_EOL . '  name: field');

        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches('/yaml.*extension/i');

        $schema->load();
    }

    // -----------------------------------------------------------------------
    // Valid YAML string
    // -----------------------------------------------------------------------

    public function testLoadFromValidYamlString(): void
    {
        $yaml = implode(PHP_EOL, [
            '- type: text',
            '  name: first_name',
            '- type: email',
            '  name: email',
        ]);

        $schema = new YamlLoader($yaml);
        $result = $schema->load();

        $this->assertCount(2, $result);
        $this->assertSame('text', $result[0]['type']);
        $this->assertSame('first_name', $result[0]['name']);
        $this->assertSame('email', $result[1]['type']);
        $this->assertSame('email', $result[1]['name']);
    }

    public function testLoadPassesThroughExtraKeysFromString(): void
    {
        $yaml = implode(PHP_EOL, [
            '- type: text',
            '  name: city',
            '  label: City',
            '  default: London',
        ]);

        $schema = new YamlLoader($yaml);
        $result = $schema->load();

        $this->assertSame('City', $result[0]['label']);
        $this->assertSame('London', $result[0]['default']);
    }

    // -----------------------------------------------------------------------
    // Valid YAML file path
    // -----------------------------------------------------------------------

    public function testLoadFromValidYamlFile(): void
    {
        $yaml = implode(PHP_EOL, [
            '- type: text',
            '  name: title',
            '- type: textarea',
            '  name: body',
        ]);

        $path = $this->writeYamlFile($yaml);

        $schema = new YamlLoader($path);
        $result = $schema->load();

        $this->assertCount(2, $result);
        $this->assertSame('title', $result[0]['name']);
        $this->assertSame('body', $result[1]['name']);

        unlink($path);
    }

    // -----------------------------------------------------------------------
    // Validation delegated to ArrayLoader
    // -----------------------------------------------------------------------

    public function testLoadThrowsWhenEntryMissingType(): void
    {
        $yaml = implode(PHP_EOL, [
            '- name: username',
        ]);

        $schema = new YamlLoader($yaml);

        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches('/missing required key "type"/i');

        $schema->load();
    }

    public function testLoadThrowsWhenEntryMissingName(): void
    {
        $yaml = implode(PHP_EOL, [
            '- type: text',
        ]);

        $schema = new YamlLoader($yaml);

        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches('/missing required key "name"/i');

        $schema->load();
    }

    // -----------------------------------------------------------------------
    // Invalid YAML
    // -----------------------------------------------------------------------

    public function testLoadThrowsWhenYamlParsesToNonArray(): void
    {
        // A scalar YAML string parses to a string, not an array.
        $schema = new YamlLoader('"just a string"');

        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches('/YAML form schema must parse to an array/i');

        $schema->load();
    }

    // -----------------------------------------------------------------------
    // Helpers
    // -----------------------------------------------------------------------

    private function writeYamlFile(string $yaml): string
    {
        $dir  = outputDir('tests/forms/');
        if (!is_dir($dir)) {
            mkdir($dir, 0777, true);
        }
        $path = $dir . 'phalcon_forms_test_' . uniqid() . '.yaml';
        file_put_contents($path, $yaml);

        return $path;
    }
}
